/**
 * @file native_tiandi_jni.cc
 * @author hhool (hhool@outlook.com)
 * @brief  native_tiandi_jni source file.
 * @version 0.1
 * @date 2024-09-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "native_tiandi_jni.h"

#include <DecCtrlClientTypes.h>

#include <jni.h>

#include <iostream>
#include <map>
#include <string>

#include "common.h"
#include "common/logger.h"
#include "nvsdk_struct_utils.h"
#include "nvsdk_wrapper.h"

static JavaVM* gJavaVM;

typedef struct JniCallback {
  JNIEnv* env;
  jobject obj;
  jclass clz;
  jmethodID method;
} JniCallback;

static JniCallback gComRecvNotifyCallback;
static JniCallback gMsgNotifyCallback;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
  gJavaVM = vm;
  return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
  gJavaVM = NULL;
}

void OnDecComRecvNotify(long uId, char* cBuf, int iLen) {  // NOLINT
  JNIEnv* env = NULL;
  pthread_t tid = pthread_self();
  if (gJavaVM->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) !=
      JNI_OK) {
    if (gJavaVM->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL) !=
        JNI_OK) {
      LOG_F(LG_ERROR) << "AttachCurrentThread failed";
      return;
    }
  }
  jbyteArray jbuf = env->NewByteArray(iLen);
  env->SetByteArrayRegion(jbuf, 0, iLen, reinterpret_cast<jbyte*>(cBuf));
  env->CallStaticVoidMethod(gComRecvNotifyCallback.clz,
                            gComRecvNotifyCallback.method,
                            gComRecvNotifyCallback.obj, uId, jbuf, iLen);
  env->DeleteLocalRef(jbuf);
  if (env->ExceptionCheck()) {
    env->ExceptionDescribe();
    env->ExceptionClear();
  }
  if (gJavaVM->DetachCurrentThread() != JNI_OK) {
    return;
  }
}

int OnTDPostMessageNotify(void* hWnd,
                          uint32_t uiMsg,
                          uint32_t _wParam,
                          int _lParam) {  // NOLINT
  JNIEnv* env = NULL;
  pthread_t tid = pthread_self();
  if (gJavaVM->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) !=
      JNI_OK) {
    if (gJavaVM->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL) !=
        JNI_OK) {
      return -1;
    }
  }
  int16_t wParamHi = (_wParam >> 16) & 0x0000FFFF;
  int16_t wParamLo = _wParam & 0x0000FFFF;
  LOG_F(LG_INFO) << "OnTDPostMessageNotify clz: " << gMsgNotifyCallback.clz
                 << " method: " << gMsgNotifyCallback.method
                 << " obj: " << gMsgNotifyCallback.obj << " hWnd: " << hWnd
                 << " uiMsg: " << uiMsg << " wParamHi: " << wParamHi
                 << " wParamLo: " << wParamLo << " wParam: " << _wParam
                 << " lParam: " << _lParam;
  bool isLogon = wParamLo == DEC_WCM_DEC_LOGON;
  bool isLogoSuccess = wParamHi == DEC_LOGON_SUCCESS;
  env->CallStaticVoidMethod(gMsgNotifyCallback.clz, gMsgNotifyCallback.method,
                            gMsgNotifyCallback.obj, hWnd, uiMsg, wParamHi,
                            wParamLo, _lParam);
  if (env->ExceptionCheck()) {
    env->ExceptionDescribe();
    env->ExceptionClear();
  }
  /// @note if logon failed, detach current thread, otherwise, keep it
  /// attached. This is because logon failed, the thread will be exit the
  /// thread and the thread will be detached by the base dll. we have no
  /// chance to detach it.
  if (isLogon && !isLogoSuccess) {
    LOG_F(LG_ERROR) << "OnTDPostMessageNotify logon failed";
    if (gJavaVM->DetachCurrentThread() != JNI_OK) {
      return 0;
    }
  }
  return 0;
}

JNIEXPORT jlong JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeCreateInstance(JNIEnv* env,
                                                             jobject thiz) {
  nvsdk::NVSDKWrapper* nv = new nvsdk::NVSDKWrapper();
  if (nv == nullptr) {
    return 0;
  }
  LOG_F(LG_INFO) << "Create NVSDKWrapper instance";
  if (!nv->LoadNativeLibrary(env)) {
    delete nv;
    return 0;
  }
  if (gJavaVM == NULL) {
    env->GetJavaVM(&gJavaVM);
    if (gJavaVM == NULL) {
      LOG_F(LG_ERROR) << "Get JavaVM failed";
      return -1;
    }
  }
  /// Register callback function for JNI call back to Java layer
  /// OnNativeDecComRecvNotify
  jclass cls = env->FindClass("com/gshx/camera/tiandi/NVSDKClient");
  if (cls == NULL) {
    LOG_F(LG_ERROR) << "FindClass failed";
    return -1;
  }
  jmethodID mid = env->GetStaticMethodID(cls, "OnNativeDecComRecvNotify",
                                         "(Ljava/lang/Object;J[B)V");
  if (mid == 0) {
    LOG_F(LG_ERROR) << "GetStaticMethodID failed";
    return -1;
  }
  gComRecvNotifyCallback.env = env;
  gComRecvNotifyCallback.clz = (jclass)env->NewGlobalRef(cls);
  gComRecvNotifyCallback.obj = env->NewGlobalRef(thiz);
  gComRecvNotifyCallback.method = mid;

  /// @note OnNativeTDPostMessageNotify callback function for JNI call back to
  /// Java
  mid = env->GetStaticMethodID(cls, "OnNativeTDPostMessageNotify",
                               "(Ljava/lang/Object;JIIII)V");
  if (mid == 0) {
    LOG_F(LG_ERROR) << "GetStaticMethodID failed";
    return -1;
  }
  gMsgNotifyCallback.env = env;
  gMsgNotifyCallback.clz = (jclass)env->NewGlobalRef(cls);
  gMsgNotifyCallback.obj = env->NewGlobalRef(thiz);
  gMsgNotifyCallback.method = mid;

  nv->ClientSetComRecvNotify(env, OnDecComRecvNotify, nullptr);
  nv->ClientSetComMsgCallback(env, OnTDPostMessageNotify, nullptr);
  return reinterpret_cast<jlong>(nv);
}

JNIEXPORT void JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeDestroyInstance(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_VOID(nv);
  nv->UnloadNativeLibrary(env);

  if (gComRecvNotifyCallback.obj != NULL) {
    env->DeleteGlobalRef(gComRecvNotifyCallback.obj);
    gComRecvNotifyCallback.obj = NULL;
  }
  if (gComRecvNotifyCallback.clz != NULL) {
    env->DeleteGlobalRef(gComRecvNotifyCallback.clz);
    gComRecvNotifyCallback.clz = NULL;
  }
  if (gMsgNotifyCallback.obj != NULL) {
    env->DeleteGlobalRef(gMsgNotifyCallback.obj);
    gMsgNotifyCallback.obj = NULL;
  }
  if (gMsgNotifyCallback.clz != NULL) {
    env->DeleteGlobalRef(gMsgNotifyCallback.clz);
    gMsgNotifyCallback.clz = NULL;
  }

  delete reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartup(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jint msg) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  nv->ClientStartup(env, msg, nullptr);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientCleanup(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return nv->ClientCleanup(env);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetComRecvNotify(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jobject jobject_callback) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return -1;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetMsgCallback(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jobject jobject_callback) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return -1;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetMsgCallbackEx(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientLogin__JLjava_lang_String_2ILjava_lang_String_2Ljava_lang_String_2(  // NOLINT
    JNIEnv* env,
    jobject,
    jlong ptr,
    jstring ip,
    jint port,
    jstring user,
    jstring pwd) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  std::string ip_str = nvsdk::JniString2Native(env, ip);
  std::string user_str = nvsdk::JniString2Native(env, user);
  std::string pwd_str = nvsdk::JniString2Native(env, pwd);
  if (ip_str.empty() || user_str.empty() || pwd_str.empty()) {
    return -1;
  }
  int ret = nv->ClientLogin(env, ip_str.c_str(), port, user_str.c_str(),
                            pwd_str.c_str());
  LOG_F(LG_INFO) << "ClientLogin ret: " << ret << " ip: " << ip_str
                 << " port: " << port << " user: " << user_str
                 << " pwd: " << pwd_str;

  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientLogin__JLjava_lang_String_2ILjava_lang_String_2Ljava_lang_String_2J(  // NOLINT
    JNIEnv* env,
    jobject,
    jlong ptr,
    jstring ip,
    jint port,
    jstring user,
    jstring pwd,
    jlong context) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  std::string ip_str = nvsdk::JniString2Native(env, ip);
  std::string user_str = nvsdk::JniString2Native(env, user);
  std::string pwd_str = nvsdk::JniString2Native(env, pwd);
  void* context_ptr = reinterpret_cast<void*>(context);
  if (ip_str.empty() || user_str.empty() || pwd_str.empty()) {
    return -1;
  }
  int ret = nv->ClientLogin(env, ip_str.c_str(), port, user_str.c_str(),
                            pwd_str.c_str(), context_ptr);
  LOG_F(LG_INFO) << "ClientLogin ret: " << ret << " ip: " << ip_str
                 << " port: " << port << " user: " << user_str
                 << " pwd: " << pwd_str;
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientLogout__JJ(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr,
                                                               jlong userID) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return nv->ClientLogout(env, userID);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientLogout__JJJ(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jlong userID,
                                                                jlong context) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  void* context_ptr = reinterpret_cast<void*>(context);
  return nv->ClientLogout(env, userID, context_ptr);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartPushStream(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong iID,
    jint iChannel,
    jint iPos,
    jint iEncodeMode,
    jint iVideoSize) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  LOG_F(LG_INFO) << "ClientStartPushStream iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " iEncodeMode: " << iEncodeMode
                 << " iVideoSize: " << iVideoSize;
  return nv->ClientStartPushStream(env, iID, iChannel, iPos, iEncodeMode,
                                   iVideoSize);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartPushStreamEx(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong,
    jint,
    jint,
    jint,
    jint,
    jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartPushStream_1V1(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong,
    jint,
    jint,
    jstring,
    jstring,
    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSendStream(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr,
                                                               jlong iPUshID,
                                                               jbyteArray pData,
                                                               jint iLen) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  jbyte* pBuf = env->GetByteArrayElements(pData, 0);
  int ret =
      nv->ClientSendStream(env, iPUshID, iLen, reinterpret_cast<char*>(pBuf));
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStopPushStream(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong iPushID) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return nv->ClientStopPushStream(env, iPushID);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStopPushStreamEx(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong,
    jboolean) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetStreamBufferState(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong iPushID) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int iBufState = 0;
  int ret = -1;
  ret = nv->ClientGetStreamBufferState(env, iPushID, &iBufState);
  if (ret < 0) {
    return ret;
  }
  return iBufState;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStreamControl(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong iPushID,
    jint iCmd,
    jint iCmdValue) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = nv->ClientStreamControl(env, iPushID, iCmd, iCmdValue);
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSendRawFrame(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong iPushID,
    jbyteArray jbuf) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = 0;
  jbyte* buf = env->GetByteArrayElements(jbuf, 0);
  ret = nv->ClientSendNonstandardRawFrame(
      env, iPushID, reinterpret_cast<char*>(buf), env->GetArrayLength(jbuf));
  env->ReleaseByteArrayElements(jbuf, buf, 0);
  return ret;
}

JNIEXPORT jobject JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetDecoderPara(JNIEnv* env,
                                                                   jobject,
                                                                   jlong ptr,
                                                                   jint iID) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET(nv, nullptr);
  TDECPARAM tp;
  int ret = nv->ClientGetDecoderParam(env, iID, &tp);
  if (ret < 0) {
    return nullptr;
  }
  jobject jparam = nvsdk::NativeTDecParam2Jni(env, tp);
  if (jparam == NULL) {
    LOG_F(LG_ERROR) << "NativeTDecParam2Jni failed";
    return nullptr;
  }
  return jparam;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetDDNS(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jint,
                                                            jstring,
                                                            jstring,
                                                            jstring,
                                                            jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetAlarmOut(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jint,
                                                                jint,
                                                                jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetTVInfo(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jint,
                                                              jint,
                                                              jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetChannelMode(JNIEnv* env,
                                                                   jobject,
                                                                   jlong ptr,
                                                                   jint,
                                                                   jint,
                                                                   jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetLogo(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jint,
                                                            jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetLog(JNIEnv* env,
                                                           jobject,
                                                           jlong ptr,
                                                           jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetLoopItemCount(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jint jid,
    jint jchannel,
    jint jpos) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = -1;
  int id = jid;
  int channel = jchannel;
  int pos = jpos;
  ret = nv->ClientGetLoopItemCount(env, id, channel, pos);
  return ret;
}

JNIEXPORT jobject JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetLoopItem(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jint jid,
                                                                jint jindex,
                                                                jint jchannel,
                                                                jint jpos) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET(nv, nullptr);
  TNVSITEM tni;
  memset(&tni, 0, sizeof(TNVSITEM));
  int ret = -1;
  ret = nv->ClientGetLoopItem(env, jid, jindex, jchannel, jpos, &tni);
  if (ret < 0) {
    LOG_F(LG_ERROR) << "ClientGetLoopItem failed";
    return nullptr;
  }
  jobject jtnvs_item = nvsdk::NativeTNVSItem2Jni(env, tni);
  if (jtnvs_item == NULL) {
    LOG_F(LG_ERROR) << "NativeTNVSItem2Jni failed";
    return NULL;
  }
  return jtnvs_item;
}

JNIEXPORT jobject JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetLoopItemEx(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jint jid,
                                                                  jint jindex,
                                                                  jint jchannel,
                                                                  jint jpos) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET(nv, nullptr);
  TNVSITEMEX tni_item_ex;
  memset(&tni_item_ex, 0, sizeof(TNVSITEMEX));
  tni_item_ex.m_iStructLen = sizeof(TNVSITEMEX);
  int ret = -1;
  ret = nv->ClientGetLoopItemEx(env, jid, jindex, jchannel, jpos, &tni_item_ex);
  if (ret < 0) {
    LOG_F(LG_ERROR) << "ClientGetLoopItemEx failed";
    return nullptr;
  }
  jobject jtni_item_ex = nvsdk::NativeTNVSItemEx2Jni(env, tni_item_ex);
  if (jtni_item_ex == NULL) {
    LOG_F(LG_ERROR) << "NativeTNVSItemEx2Jni failed";
    return NULL;
  }
  return jtni_item_ex;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetLoopItem_1V1(JNIEnv* env,
                                                                    jobject,
                                                                    jlong ptr,
                                                                    jint,
                                                                    jint,
                                                                    jint,
                                                                    jint,
                                                                    jint,
                                                                    jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartLoop(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jint jid,
                                                              jint jchannel,
                                                              jint jpos) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = -1;
  ret = nv->ClientStartLoop(env, jid, jchannel, jpos);
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStopLoop(JNIEnv* env,
                                                             jobject,
                                                             jlong ptr,
                                                             jint jid,
                                                             jint jchannel,
                                                             jint jpos) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = -1;
  ret = nv->ClientStopLoop(env, jid, jchannel, jpos);
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetLoopStatus(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jint jid,
                                                                  jint jchannel,
                                                                  jint jpos) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = -1;
  ret = nv->ClientGetLoopStatus(env, jid, jchannel, jpos);
  LOG_F(LG_INFO) << "ClientGetLoopStatus ret: " << ret << " id: " << jid
                 << " channel: " << jchannel << " pos: " << jpos;
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStopView(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jint jid,
    jint ichannel,
    jint ipos,
    jboolean show_last_frame) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = nv->ClientStopView(env, jid, ichannel, ipos, show_last_frame);
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStopView_1V1(JNIEnv* env,
                                                                 jobject,
                                                                 jlong ptr,
                                                                 jint,
                                                                 jint,
                                                                 jint,
                                                                 jboolean) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartView(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jint iID,
                                                              jint ichannel,
                                                              jint ipos,
                                                              jobject jtni) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET(nv, -1);
  TNVSITEM tni;
  memset(&tni, 0, sizeof(TNVSITEM));
  int32_t ret = -1;
  ret = nvsdk::JniTNVSItem2Native(env, jtni, &tni);
  if (ret < 0) {
    LOG_F(LG_ERROR) << "JniTNVSItemEx2Native failed";
    return ret;
  }
  ret = -1;
  ret = nv->ClientStartView(env, iID, &tni, ichannel, ipos);
  if (ret < 0) {
    LOG_F(LG_ERROR) << "ClientStartView failed";
    return ret;
  }

  return ret;
}
namespace {
void InitStruct(TNVSITEMEX& tnvs_item_ex) {
  memset(&tnvs_item_ex, 0, sizeof(TNVSITEMEX));
  memset(&tnvs_item_ex.m_stOldItem, 0, sizeof(TNVSITEM));
  tnvs_item_ex.m_iStructLen = sizeof(TNVSITEMEX);
  strncpy(tnvs_item_ex.m_stOldItem.m_cRTSPUrl, "172.27.100.15",
          sizeof(tnvs_item_ex.m_stOldItem.m_cRTSPUrl));
  strncpy(tnvs_item_ex.m_stOldItem.m_serName, "172.27.100.15",
          sizeof(tnvs_item_ex.m_stOldItem.m_serName));
  strncpy(tnvs_item_ex.m_stOldItem.m_serIP, "172.27.100.15",
          sizeof(tnvs_item_ex.m_stOldItem.m_serIP));
  tnvs_item_ex.m_stOldItem.m_serChan = 1;
  tnvs_item_ex.m_stOldItem.m_serStream = 0;
  tnvs_item_ex.m_stOldItem.m_serNetmode = 1;
  tnvs_item_ex.m_stOldItem.m_bUseddns = 0;
  tnvs_item_ex.m_stOldItem.m_serPort = 3000;
  tnvs_item_ex.m_stOldItem.m_bisView = 0;
  strncpy(tnvs_item_ex.m_stOldItem.m_username, "Admin",
          sizeof(tnvs_item_ex.m_stOldItem.m_username));
  strncpy(tnvs_item_ex.m_stOldItem.m_password, "Gshx1234",
          sizeof(tnvs_item_ex.m_stOldItem.m_password));
  tnvs_item_ex.m_stOldItem.m_holdtime = 20;
  strncpy(tnvs_item_ex.m_stOldItem.m_deviceType, "DOME_PELCO_P",
          sizeof(tnvs_item_ex.m_stOldItem.m_deviceType));
  tnvs_item_ex.m_stOldItem.m_iAddress = 2;
  tnvs_item_ex.m_iDevPlatType = 0;
}
void DumpStruct(TNVSITEMEX& tnvs_item_ex) {
  LOG_F(LG_INFO) << " m_iStructLen:" << tnvs_item_ex.m_iStructLen;
  LOG_F(LG_INFO) << " m_cRTSPUrl:" << tnvs_item_ex.m_stOldItem.m_cRTSPUrl;
  LOG_F(LG_INFO) << " m_serName:"
                 << std::string(tnvs_item_ex.m_stOldItem.m_serName);
  LOG_F(LG_INFO) << " m_serIP:"
                 << std::string(tnvs_item_ex.m_stOldItem.m_serIP);
  LOG_F(LG_INFO) << " m_serProxy:"
                 << std::string(tnvs_item_ex.m_stOldItem.m_serProxy);
  LOG_F(LG_INFO) << " m_serChan:" << tnvs_item_ex.m_stOldItem.m_serChan;
  LOG_F(LG_INFO) << " m_serStream:" << tnvs_item_ex.m_stOldItem.m_serStream;
  LOG_F(LG_INFO) << " m_serNetmode:" << tnvs_item_ex.m_stOldItem.m_serNetmode;
  LOG_F(LG_INFO) << " m_bUseddns:" << tnvs_item_ex.m_stOldItem.m_bUseddns;
  LOG_F(LG_INFO) << " m_serPort:" << tnvs_item_ex.m_stOldItem.m_serPort;
  LOG_F(LG_INFO) << " m_bisView:" << tnvs_item_ex.m_stOldItem.m_bisView;
  LOG_F(LG_INFO) << " m_username:" << tnvs_item_ex.m_stOldItem.m_username;
  LOG_F(LG_INFO) << " m_password:" << tnvs_item_ex.m_stOldItem.m_password;
  LOG_F(LG_INFO) << " m_holdtime:" << tnvs_item_ex.m_stOldItem.m_holdtime;
  LOG_F(LG_INFO) << " m_deviceType:" << tnvs_item_ex.m_stOldItem.m_deviceType;
  LOG_F(LG_INFO) << " m_iAddress:"
                 << static_cast<int>(tnvs_item_ex.m_stOldItem.m_iAddress);
  LOG_F(LG_INFO) << " m_iDevPlatType:" << tnvs_item_ex.m_iDevPlatType;
}

void DumpStruct2(TNVSITEMEX& tnvs_item_ex) {
  std::cout << " m_iStructLen:" << tnvs_item_ex.m_iStructLen << std::endl;
  std::cout << " m_cRTSPUrl:" << tnvs_item_ex.m_stOldItem.m_cRTSPUrl
            << std::endl;
  std::cout << " m_serName:" << tnvs_item_ex.m_stOldItem.m_serName << std::endl;
  std::cout << " m_serIP:" << tnvs_item_ex.m_stOldItem.m_serIP << std::endl;
  std::cout << " m_serProxy:" << tnvs_item_ex.m_stOldItem.m_serProxy
            << std::endl;
  std::cout << " m_serChan:"
            << std::to_string(tnvs_item_ex.m_stOldItem.m_serChan) << std::endl;
  std::cout << " m_serStream:"
            << std::to_string(tnvs_item_ex.m_stOldItem.m_serStream)
            << std::endl;
  std::cout << " m_serNetmode:"
            << std::to_string(tnvs_item_ex.m_stOldItem.m_serNetmode)
            << std::endl;
  std::cout << " m_bUseddns:"
            << std::to_string(tnvs_item_ex.m_stOldItem.m_bUseddns) << std::endl;
  std::cout << " m_serPort:" << tnvs_item_ex.m_stOldItem.m_serPort << std::endl;
  std::cout << " m_bisView:" << tnvs_item_ex.m_stOldItem.m_bisView << std::endl;
  std::cout << " m_username:" << tnvs_item_ex.m_stOldItem.m_username
            << std::endl;
  std::cout << " m_password:" << tnvs_item_ex.m_stOldItem.m_password
            << std::endl;
  std::cout << " m_holdtime:" << tnvs_item_ex.m_stOldItem.m_holdtime
            << std::endl;
  std::cout << " m_deviceType:" << tnvs_item_ex.m_stOldItem.m_deviceType
            << std::endl;
  std::cout << " static_cast m_iAddress:"
            << static_cast<int>(tnvs_item_ex.m_stOldItem.m_iAddress)
            << std::endl;
  std::cout << " m_iAddress:"
            << static_cast<int>(tnvs_item_ex.m_stOldItem.m_iAddress)
            << std::endl;
  std::cout << " m_iDevPlatType:" << tnvs_item_ex.m_iDevPlatType << std::endl;
}
}  // namespace

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartViewEx(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jint jid,
    jint jchannel,
    jint jpos,
    jobject jtni_ex) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET(nv, -1);
  TNVSITEMEX tnvs_item_ex = {0};
  memset(&tnvs_item_ex, 0, sizeof(TNVSITEMEX));
  tnvs_item_ex.m_iStructLen = sizeof(TNVSITEMEX);
  int32_t ret = -1;
  ret = nvsdk::JniTNVSItemEx2Native(env, jtni_ex, &tnvs_item_ex);
  if (ret < 0) {
    LOG_F(LG_ERROR) << "JniTNVSItemEx2Native failed";
    return ret;
  }
  LOG_F(LG_INFO) << "ClientStartViewEx id: " << jid << " channel: " << jchannel
                 << " pos: " << jpos;
  LOG_F(LG_INFO) << "DumpStruct: " << 0;
#if 0
  DumpStruct(tnvs_item_ex);
  LOG_F(LG_INFO) << "InitStruct DumpStruct: " << 1;
  InitStruct(tnvs_item_ex);
  LOG_F(LG_INFO) << "DumpStruct InitStruct DumpStruct: " << 1;
  DumpStruct(tnvs_item_ex);
  LOG_F(LG_INFO) << "DumpStruct2 InitStruct DumpStruct: " << 1;
#endif
  DumpStruct2(tnvs_item_ex);
  ret = -1;
  ret = nv->ClientStartViewEx(env, jid, &tnvs_item_ex, jchannel, jpos);
  if (ret < 0) {
    LOG_F(LG_ERROR) << "ClientStartViewEx failed";
    return -1;
  }
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientStartView_1V1(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jint,
                                                                  jint,
                                                                  jint,
                                                                  jint,
                                                                  jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetViewItem(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jint,
                                                                jobject,
                                                                jint,
                                                                jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetViewItemEx(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jint,
                                                                  jobject,
                                                                  jint,
                                                                  jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetViewItem_1V1(JNIEnv* env,
                                                                    jobject,
                                                                    jlong ptr,
                                                                    jint,
                                                                    jint,
                                                                    jint,
                                                                    jint,
                                                                    jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSendKey(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jint,
                                                            jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientPTZCtrl(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jint,
                                                            jint,
                                                            jint,
                                                            jint,
                                                            jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClient485Send(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jint,
                                                            jbyteArray,
                                                            jint,
                                                            jint,
                                                            jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetPTZprotocols(JNIEnv* env,
                                                                    jobject,
                                                                    jlong ptr,
                                                                    jint,
                                                                    jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSoundCtrl(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jint,
                                                              jint,
                                                              jint,
                                                              jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientTalkServer(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr,
                                                               jint,
                                                               jint,
                                                               jint,
                                                               jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetAudioStatus(JNIEnv* env,
                                                                   jobject,
                                                                   jlong ptr,
                                                                   jint,
                                                                   jint,
                                                                   jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetTalkStatus(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jint,
                                                                  jint,
                                                                  jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientRebootDecoder(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientResetDefault(JNIEnv* env,
                                                                 jobject,
                                                                 jlong ptr,
                                                                 jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientUpgrade(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jint,
                                                            jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientUpgradeLogo(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jint,
                                                                jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientUpgradeProtocol(JNIEnv* env,
                                                                    jobject,
                                                                    jlong ptr,
                                                                    jint,
                                                                    jstring,
                                                                    jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientDeleteProtocol(JNIEnv* env,
                                                                   jobject,
                                                                   jlong ptr,
                                                                   jint,
                                                                   jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetVersion(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr,
                                                               jint,
                                                               jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetSDKVersion(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientUpgradeWeb(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr,
                                                               jint,
                                                               jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetCapability(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jint,
                                                                  jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetVGASize(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr,
                                                               jint,
                                                               jint,
                                                               jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSendNonstandardRawFrame(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong pushID,
    jbyteArray jbufarray) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  int ret = 0;
  jbyte* pBuf = env->GetByteArrayElements(jbufarray, 0);
  int len = env->GetArrayLength(jbufarray);
  ret = nv->ClientSendNonstandardRawFrame(env, pushID,
                                          reinterpret_cast<char*>(pBuf), len);
  env->ReleaseByteArrayElements(jbufarray, pBuf, 0);
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetVolume(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jint,
                                                              jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetVolume(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetCommonEnable(JNIEnv* env,
                                                                    jobject,
                                                                    jlong ptr,
                                                                    jint,
                                                                    jint,
                                                                    jint,
                                                                    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetCommonEnable(JNIEnv* env,
                                                                    jobject,
                                                                    jlong ptr,
                                                                    jint,
                                                                    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetCommonEnableEx(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jint,
    jint,
    jint,
    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientConfigStreamInfo(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jint,
    jint,
    jint,
    jint,
    jbyteArray) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetDevConfig(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong uID,
    jint iChannel,
    jint iPos,
    jint iCmd,
    jbyteArray jbuf) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  jbyte* pBuf = env->GetByteArrayElements(jbuf, 0);
  int ret = nv->SetDevConfig(env, uID, iChannel, iPos, iCmd,
                             reinterpret_cast<char*>(pBuf),
                             env->GetArrayLength(jbuf));
  env->ReleaseByteArrayElements(jbuf, pBuf, 0);
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetDevConfig(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong uID,
    jint iChannel,
    jint iPos,
    jint iCmd,
    jbyteArray jbuf) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  jbyte* pBuf = env->GetByteArrayElements(jbuf, 0);
  int ret = nv->GetDevConfig(env, uID, iChannel, iPos, iCmd,
                             reinterpret_cast<char*>(pBuf),
                             env->GetArrayLength(jbuf));
  env->ReleaseByteArrayElements(jbuf, pBuf, 0);
  return ret;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetAutoTest(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jlong,
                                                                jint,
                                                                jbyteArray,
                                                                jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetSelectPicture(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong,
    jint,
    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetNotify(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetNetLog(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jlong,
                                                              jint,
                                                              jint,
                                                              jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientNetLogGetLogfile(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong,
    jint,
    jobject,
    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientNetLogGetLogCount(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong,
    jint,
    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientUserChangePassword(
    JNIEnv*,
    jobject,
    jlong ptr,
    jlong,
    jstring,
    jstring,
    jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeSetRegServer(JNIEnv* env,
                                                           jobject,
                                                           jlong ptr,
                                                           jlong,
                                                           jstring,
                                                           jint,
                                                           jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeSetRegDevice(JNIEnv* env,
                                                           jobject,
                                                           jlong ptr,
                                                           jlong,
                                                           jstring,
                                                           jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeSetRegChannel(JNIEnv* env,
                                                            jobject,
                                                            jlong ptr,
                                                            jlong,
                                                            jint,
                                                            jstring) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeSetDZInfo(JNIEnv* env,
                                                        jobject,
                                                        jlong ptr,
                                                        jlong,
                                                        jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeSetChannelSipConfig(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jlong,
                                                                  jint,
                                                                  jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeSetPlatformStart(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr,
                                                               jlong,
                                                               jobject) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeGetPlatformInfo(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr,
                                                              jlong) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeGetRunningPlatformInfo(
    JNIEnv* env,
    jobject,
    jlong ptr,
    jlong) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeSetPlatformConfig(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jlong,
                                                                jint,
                                                                jbyteArray,
                                                                jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetClusterConfig(
    JNIEnv*,
    jobject,
    jlong ptr,
    jlong,
    jint,
    jbyteArray) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSendCommand(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jlong,
                                                                jint,
                                                                jint,
                                                                jint,
                                                                jbyteArray) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientRecvCommand(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr,
                                                                jlong,
                                                                jint,
                                                                jint,
                                                                jint,
                                                                jbyteArray) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientGetLogonState(JNIEnv* env,
                                                                  jobject,
                                                                  jlong ptr,
                                                                  jlong) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetSDKWorkMode(JNIEnv* env,
                                                                   jobject,
                                                                   jlong ptr,
                                                                   jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}

JNIEXPORT jint JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeClientSetExternDevLogonInfo(
    JNIEnv*,
    jobject,
    jlong ptr,
    jint) {
  nvsdk::NVSDKWrapper* nv = reinterpret_cast<nvsdk::NVSDKWrapper*>(ptr);
  CHECK_PTR_RET_FAIL(nv);
  return 0;
}
