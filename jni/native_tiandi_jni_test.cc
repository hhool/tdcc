/**
 * @file native_tiandi_jni_test.cc
 * @author hhool (hhool@outlook.com)
 * @brief  native tiandi jni test file.
 * @version 0.1
 * @date 2024-09-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "native_tiandi_jni.h"

#include <DecCtrlClientTypes.h>
#include "CLS_NVDSDKHelper.h"

#include <jni.h>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "common.h"
#include "common/logger.h"
#include "nvsdk_struct_utils.h"

JNIEXPORT jobject JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeTNVSItemExFromJNI(JNIEnv* env,
                                                                jobject,
                                                                jlong ptr) {
  TNVSITEMEX item;
  memset(&item, 0, sizeof(TNVSITEMEX));
  item.m_iStructLen = sizeof(TNVSITEMEX);
  strncpy(item.m_cEncyptPWD, "123456", sizeof(item.m_cEncyptPWD));
  jobject j_tvs_itemex = nvsdk::NativeTNVSItemEx2Jni(env, item);
  if (j_tvs_itemex == nullptr) {
    LOG_F(LG_ERROR) << "NativeTNVSItemEx2Jni failed";
    return nullptr;
  }
  return j_tvs_itemex;
}

JNIEXPORT jobject JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeTNVSItemFromJNI(JNIEnv* env,
                                                              jobject,
                                                              jlong ptr) {
  TNVSITEM item;
  memset(&item, 0, sizeof(TNVSITEM));
  strncpy(item.m_cRTSPUrl, "rtsp://domain.com", sizeof(item.m_cRTSPUrl));
  jobject j_tvs_item = nvsdk::NativeTNVSItem2Jni(env, item);
  if (j_tvs_item == nullptr) {
    LOG_F(LG_ERROR) << "NativeTNVSItem2Jni failed";
    return nullptr;
  }
  return j_tvs_item;
}

JNIEXPORT jobject JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeTCom485FromJNI(JNIEnv* env,
                                                             jobject,
                                                             jlong ptr) {
  nvsdk::TCOM485 item;
  memset(&item, 0, sizeof(nvsdk::TCOM485));
  item.m_type = 1;
  item.m_address = 1;
  item.m_baudrate = 9600;
  item.m_databit = 8;
  item.m_stopbit = 1;
  item.m_checkbit = 0;
  item.m_flowcontrol = 0;

  jobject j_tcom485 = nullptr;
  j_tcom485 = nvsdk::NativeTCom4852Jni(env, item);
  if (j_tcom485 == nullptr) {
    LOG_F(LG_ERROR) << "NativeTCom4852Jni failed";
    return nullptr;
  }

  return j_tcom485;
}

JNIEXPORT jobject JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeTDecParamFromJNI(JNIEnv* env,
                                                               jobject,
                                                               jlong ptr) {
  TDECPARAM item;
  memset(&item, 0, sizeof(TDECPARAM));
  strncpy(item.m_ip, "127.0.0.1", sizeof(item.m_ip));
  jobject j_tdec_param = nvsdk::NativeTDecParam2Jni(env, item);
  if (j_tdec_param == nullptr) {
    LOG_F(LG_ERROR) << "NativeTDecParam2Jni failed";
    return nullptr;
  }

  return j_tdec_param;
}
