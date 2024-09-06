/**
 * @file nvsdk_struct_utils.cc
 * @author hhool (hhool@outlook.com
 * @brief  jni nvsdk struct utils source file.
 * @version 0.1
 * @date 2024-09-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "nvsdk_struct_utils.h"

#include "common/logger.h"
namespace nvsdk {

std::string JniString2Native(JNIEnv* env, jstring jstr) {
  if (jstr == nullptr) {
    return "";
  }

  const char* cstr = env->GetStringUTFChars(jstr, nullptr);
  if (cstr == nullptr) {
    return "";
  }

  std::string str(cstr);
  env->ReleaseStringUTFChars(jstr, cstr);
  return str;
}

int JniTCom4852Native(JNIEnv* env, jobject jitem, TCOM485* item) {
  if (jitem == nullptr || item == nullptr) {
    return -1;
  }
  // covert java TCom485 to C++ TCOM485
  jclass cls = env->FindClass("com/gshx/camera/tiandi/TCom485");
  if (cls == nullptr) {
    return -1;
  }
  bool success = false;
  do {
    // type is int type, GetFieldID return jfieldID
    jfieldID fid = env->GetFieldID(cls, "type", "I");
    if (fid == nullptr) {
      break;
    }
    jint type = env->GetIntField(jitem, fid);
    item->m_type = type;
    // address is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "address", "I");
    if (fid == nullptr) {
      break;
    }
    jint address = env->GetIntField(jitem, fid);
    item->m_address = address;
    // baudrate is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "baudrate", "I");
    if (fid == nullptr) {
      break;
    }
    jint baud_rate = env->GetIntField(jitem, fid);
    item->m_baudrate = baud_rate;
    // databits is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "databits", "I");
    if (fid == nullptr) {
      break;
    }
    jint data_bits = env->GetIntField(jitem, fid);
    item->m_databit = data_bits;
    // stopbits is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "stopbits", "I");
    if (fid == nullptr) {
      break;
    }
    jint stop_bits = env->GetIntField(jitem, fid);
    item->m_stopbit = stop_bits;
    // checkbits is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "checkbits", "I");
    if (fid == nullptr) {
      break;
    }
    jint checkbits = env->GetIntField(jitem, fid);
    item->m_checkbit = checkbits;
    // flowcontrol is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "flowcontrol", "I");
    if (fid == nullptr) {
      break;
    }
    jint flow_control = env->GetIntField(jitem, fid);
    item->m_flowcontrol = flow_control;
    success = true;
  } while (0);
  if (cls != nullptr) {
    env->DeleteLocalRef(cls);
    cls = nullptr;
  }
  return success ? 0 : -1;
}

jobject NativeTCom4852Jni(JNIEnv* env, const TCOM485& item) {
  jclass jcls = nullptr;
  jobject jitem = nullptr;
  bool success = false;
  do {
    if (env == nullptr) {
      LOG_F(LG_ERROR) << "env is nullptr";
      break;
    }
    jcls = env->FindClass("com/gshx/camera/tiandi/TCom485");
    if (jcls == nullptr) {
      LOG_F(LG_ERROR) << "FindClass failed";
      break;
    }
    jmethodID mid = env->GetMethodID(jcls, "<init>", "()V");
    if (mid == nullptr) {
      LOG_F(LG_ERROR) << "GetMethodID <init> failed";
      break;
    }
    jitem = env->NewObject(jcls, mid);
    if (jitem == nullptr) {
      LOG_F(LG_ERROR) << "NewObject failed";
      break;
    }
    // type is int type, GetFieldID return jfieldID
    jfieldID fid = env->GetFieldID(jcls, "type", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "GetFieldID type failed";
      break;
    }
    jint type = item.m_type;
    env->SetIntField(jitem, fid, type);
    // address is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "address", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "GetFieldID address failed";
      break;
    }
    jint address = item.m_address;
    env->SetIntField(jitem, fid, address);
    // baudrate is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "baudrate", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "GetFieldID baudrate failed";
      break;
    }
    jint baud_rate = item.m_baudrate;
    env->SetIntField(jitem, fid, baud_rate);
    // databits is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "databits", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "GetFieldID databits failed";
      break;
    }
    jint data_bits = item.m_databit;
    env->SetIntField(jitem, fid, data_bits);
    // stopbits is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "stopbits", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "GetFieldID stopbits failed";
      break;
    }
    jint stop_bits = item.m_stopbit;
    env->SetIntField(jitem, fid, stop_bits);
    // checkbits is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "checkbits", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "GetFieldID checkbits failed";
      break;
    }
    jint check_bits = item.m_checkbit;
    env->SetIntField(jitem, fid, check_bits);
    // flowcontrol is int type, GetFieldID return jfield
    fid = env->GetFieldID(jcls, "flowcontrol", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "GetFieldID flowcontrol failed";
      break;
    }
    jint flow_control = item.m_flowcontrol;
    env->SetIntField(jitem, fid, flow_control);
    success = true;
  } while (0);
  if (jcls != nullptr) {
    env->DeleteLocalRef(jcls);
    jcls = nullptr;
  }
  return success ? jitem : nullptr;
}

int JniTNVSItem2Native(JNIEnv* env, jobject jitem, TNVSITEM* item) {
  if (jitem == nullptr || item == nullptr) {
    return -1;
  }
  // covert java TNVSItem to C++ TNVSITEM
  jclass cls = env->FindClass("com/gshx/camera/tiandi/TNVSItem");
  if (cls == nullptr) {
    return -1;
  }

  jstring jstr = nullptr;
  do {
    // rtspUrl is String type, GetFieldID return jfieldID
    jfieldID fid = env->GetFieldID(cls, "rtspUrl", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string rtsp_url = JniString2Native(env, jstr);
    strncpy(item->m_cRTSPUrl, rtsp_url.c_str(), sizeof(item->m_cRTSPUrl));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // serverName is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "serverName", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string server_name = JniString2Native(env, jstr);
    strncpy(item->m_serName, server_name.c_str(), sizeof(item->m_serName));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // serverIP is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "serverIP", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string server_ip = JniString2Native(env, jstr);
    strncpy(item->m_serIP, server_ip.c_str(), sizeof(item->m_serIP));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // serverProxy is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "serverProxy", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string server_proxy = JniString2Native(env, jstr);
    strncpy(item->m_serProxy, server_proxy.c_str(), sizeof(item->m_serProxy));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // serverChan is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "serverChan", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_chan = env->GetIntField(jitem, fid);
    item->m_serChan = server_chan;
    // serverStream is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "serverStream", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_stream = env->GetIntField(jitem, fid);
    item->m_serStream = server_stream;
    // serverNetmode is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "serverNetmode", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_net_mode = env->GetIntField(jitem, fid);
    item->m_serNetmode = server_net_mode;
    // useddns is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "useddns", "I");
    if (fid == nullptr) {
      break;
    }
    jint used_dns = env->GetIntField(jitem, fid);
    item->m_bUseddns = used_dns;
    // serverPort is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "serverPort", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_port = env->GetIntField(jitem, fid);
    item->m_serPort = server_port;
    // isView is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "isView", "I");
    if (fid == nullptr) {
      break;
    }
    jint is_view = env->GetIntField(jitem, fid);
    item->m_bisView = is_view;
    // username is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "username", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string user_name = JniString2Native(env, jstr);
    strncpy(item->m_username, user_name.c_str(), sizeof(item->m_username));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // password is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "password", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string password = JniString2Native(env, jstr);
    strncpy(item->m_password, password.c_str(), sizeof(item->m_password));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // holdtime is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "holdtime", "I");
    if (fid == nullptr) {
      break;
    }
    jint hold_time = env->GetIntField(jitem, fid);
    item->m_holdtime = hold_time;
    // deviceType is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "deviceType", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string device_type = JniString2Native(env, jstr);
    strncpy(item->m_deviceType, device_type.c_str(),
            sizeof(item->m_deviceType));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // iAddress is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "iAddress", "I");
    if (fid == nullptr) {
      break;
    }
    jint i_address = env->GetIntField(jitem, fid);
    item->m_iAddress = i_address;
    LOG_F(LG_INFO) << "item->m_iAddress:" << item->m_iAddress;
  } while (0);
  if (cls != nullptr) {
    env->DeleteLocalRef(cls);
    cls = nullptr;
  }
  return 0;
}

jobject NativeTNVSItem2Jni(JNIEnv* env, const TNVSITEM& item) {
  jclass jcls = nullptr;
  jobject jitem = nullptr;
  jstring jstr = nullptr;
  bool success = false;
  do {
    if (env == nullptr) {
      break;
    }
    jcls = env->FindClass("com/gshx/camera/tiandi/TNVSItem");
    if (jcls == nullptr) {
      break;
    }
    jmethodID mid = env->GetMethodID(jcls, "<init>", "()V");
    if (mid == nullptr) {
      break;
    }
    jitem = env->NewObject(jcls, mid);
    if (jitem == nullptr) {
      break;
    }
    // check if rtspUrl is empty
    if (strlen(item.m_cRTSPUrl) != 0) {
      // rtspUrl is String type, GetFieldID return jfieldID
      jfieldID fid = env->GetFieldID(jcls, "rtspUrl", "Ljava/lang/String;");
      if (fid == nullptr) {
        break;
      }
      jstr = env->NewStringUTF(item.m_cRTSPUrl);
      if (jstr == nullptr) {
        break;
      }
      env->SetObjectField(jitem, fid, jstr);
      if (jstr != nullptr) {
        env->DeleteLocalRef(jstr);
        jstr = nullptr;
      }
    } else {
      // serverName is String type, GetFieldID return jfieldID
      jfieldID fid = env->GetFieldID(jcls, "serverName", "Ljava/lang/String;");
      if (fid == nullptr) {
        break;
      }
      jstr = env->NewStringUTF(item.m_serName);
      if (jstr == nullptr) {
        break;
      }
      env->SetObjectField(jitem, fid, jstr);
      if (jstr != nullptr) {
        env->DeleteLocalRef(jstr);
        jstr = nullptr;
      }
      // serverIP is String type, GetFieldID return jfieldID
      fid = env->GetFieldID(jcls, "serverIP", "Ljava/lang/String;");
      if (fid == nullptr) {
        break;
      }
      jstr = env->NewStringUTF(item.m_serIP);
      if (jstr == nullptr) {
        break;
      }
      env->SetObjectField(jitem, fid, jstr);
      if (jstr != nullptr) {
        env->DeleteLocalRef(jstr);
        jstr = nullptr;
      }
      // serverProxy is String type, GetFieldID return jfieldID
      fid = env->GetFieldID(jcls, "serverProxy", "Ljava/lang/String;");
      if (fid == nullptr) {
        break;
      }
      jstr = env->NewStringUTF(item.m_serProxy);
      if (jstr == nullptr) {
        break;
      }
      env->SetObjectField(jitem, fid, jstr);
      if (jstr != nullptr) {
        env->DeleteLocalRef(jstr);
        jstr = nullptr;
      }
    }
    // serverChan is int type, GetFieldID return jfieldID
    jfieldID fid = env->GetFieldID(jcls, "serverChan", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_chan = item.m_serChan;
    env->SetIntField(jitem, fid, server_chan);
    // serverStream is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "serverStream", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_stream = item.m_serStream;
    env->SetIntField(jitem, fid, server_stream);
    // serverNetmode is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "serverNetmode", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_net_mode = item.m_serNetmode;
    env->SetIntField(jitem, fid, server_net_mode);
    // useddns is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "useddns", "I");
    if (fid == nullptr) {
      break;
    }
    jint used_dns = item.m_bUseddns;
    env->SetIntField(jitem, fid, used_dns);
    // serverPort is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "serverPort", "I");
    if (fid == nullptr) {
      break;
    }
    jint server_port = item.m_serPort;
    env->SetIntField(jitem, fid, server_port);
    // isView is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "isView", "I");
    if (fid == nullptr) {
      break;
    }
    jint is_view = item.m_bisView;
    env->SetIntField(jitem, fid, is_view);
    // username is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "username", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = env->NewStringUTF(item.m_username);
    if (jstr == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // password is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "password", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = env->NewStringUTF(item.m_password);
    if (jstr == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // holdtime is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "holdtime", "I");
    if (fid == nullptr) {
      break;
    }
    jint hold_time = item.m_holdtime;
    env->SetIntField(jitem, fid, hold_time);
    // deviceType is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "deviceType", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = env->NewStringUTF(item.m_deviceType);
    if (jstr == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // iAddress is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "iAddress", "I");
    if (fid == nullptr) {
      break;
    }
    jint i_address = item.m_iAddress;
    env->SetIntField(jitem, fid, i_address);
    success = true;
  } while (0);
  if (jstr != nullptr) {
    env->DeleteLocalRef(jstr);
    jstr = nullptr;
  }
  if (jcls != nullptr) {
    env->DeleteLocalRef(jcls);
    jcls = nullptr;
  }

  if (!success) {
    return nullptr;
  }
  return jitem;
}

int JniTNVSItemEx2Native(JNIEnv* env, jobject jitem, TNVSITEMEX* item) {
  if (jitem == nullptr || item == nullptr) {
    return -1;
  }
  // covert java TNVSItemEx to C++ TNVSITEMEX
  jclass cls = env->FindClass("com/gshx/camera/tiandi/TNVSItemEx");
  if (cls == nullptr) {
    return -1;
  }
  // stOldItem is object com.gshx.camera.tiandi.TNVSItem type, GetFieldID return
  // jfieldID
  jstring jstr;
  do {
    jfieldID fid =
        env->GetFieldID(cls, "stOldItem", "Lcom/gshx/camera/tiandi/TNVSItem;");
    if (fid == nullptr) {
      break;
    }
    jobject jold_item = env->GetObjectField(jitem, fid);
    if (jold_item == nullptr) {
      break;
    }
    TNVSITEM old_item;
    JniTNVSItem2Native(env, jold_item, &old_item);
    memcpy(&item->m_stOldItem, &old_item, sizeof(TNVSITEM));
    // cEncyptPWD is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "cEncyptPWD", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string encypt_pwd = JniString2Native(env, jstr);
    strncpy(item->m_cEncyptPWD, encypt_pwd.c_str(), sizeof(item->m_cEncyptPWD));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // iDevPlatType is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "iDevPlatType", "I");
    if (fid == nullptr) {
      break;
    }
    jint dev_plat_type = env->GetIntField(jitem, fid);
    item->m_iDevPlatType = dev_plat_type;
    // cMultIP is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "cMultIP", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string mult_ip = JniString2Native(env, jstr);
    strncpy(item->m_cMultIP, mult_ip.c_str(), sizeof(item->m_cMultIP));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // iMultPort is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "iMultPort", "I");
    if (fid == nullptr) {
      break;
    }
    jint mult_port = env->GetIntField(jitem, fid);
    item->m_iMultPort = mult_port;
    // isavecfg is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "isavecfg", "I");
    if (fid == nullptr) {
      break;
    }
    jint save_cfg = env->GetIntField(jitem, fid);
    item->m_isavecfg = save_cfg;
  } while (0);
  if (cls != nullptr) {
    env->DeleteLocalRef(cls);
    cls = nullptr;
  }
  return 0;
}

jobject NativeTNVSItemEx2Jni(JNIEnv* env, const TNVSITEMEX& item) {
  jclass jcls = nullptr;
  jobject jitem = nullptr;
  jstring jstr = nullptr;
  bool success = false;
  do {
    if (env == nullptr) {
      break;
    }
    jcls = env->FindClass("com/gshx/camera/tiandi/TNVSItemEx");
    if (jcls == nullptr) {
      break;
    }
    jmethodID mid = env->GetMethodID(jcls, "<init>", "()V");
    if (mid == nullptr) {
      break;
    }
    jitem = env->NewObject(jcls, mid);
    if (jitem == nullptr) {
      break;
    }
    // stOldItem is object com.gshx.camera.tiandi.TNVSItem type, GetFieldID
    // return jfieldID
    jfieldID fid =
        env->GetFieldID(jcls, "stOldItem", "Lcom/gshx/camera/tiandi/TNVSItem;");
    if (fid == nullptr) {
      break;
    }
    jobject jold_item = NativeTNVSItem2Jni(env, item.m_stOldItem);
    if (jold_item == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jold_item);
    if (jold_item != nullptr) {
      env->DeleteLocalRef(jold_item);
      jold_item = nullptr;
    }
    // cEncyptPWD is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "cEncyptPWD", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = env->NewStringUTF(item.m_cEncyptPWD);
    if (jstr == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // iDevPlatType is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "iDevPlatType", "I");
    if (fid == nullptr) {
      break;
    }
    jint dev_plat_type = item.m_iDevPlatType;
    env->SetIntField(jitem, fid, dev_plat_type);
    // cMultIP is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "cMultIP", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = env->NewStringUTF(item.m_cMultIP);
    if (jstr == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // iMultPort is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "iMultPort", "I");
    if (fid == nullptr) {
      break;
    }
    jint mult_port = item.m_iMultPort;
    env->SetIntField(jitem, fid, mult_port);
    // isavecfg is int type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "isavecfg", "I");
    if (fid == nullptr) {
      break;
    }
    jint save_cfg = item.m_isavecfg;
    env->SetIntField(jitem, fid, save_cfg);
    success = true;
  } while (0);
  if (jstr != nullptr) {
    env->DeleteLocalRef(jstr);
    jstr = nullptr;
  }
  if (jcls != nullptr) {
    env->DeleteLocalRef(jcls);
    jcls = nullptr;
  }
  if (!success) {
    return nullptr;
  }
  return jitem;
}
int JniTDecParam2Native(JNIEnv* env, jobject jitem, TDECPARAM* item) {
  if (jitem == nullptr || item == nullptr) {
    return -1;
  }
  // covert java TDDecParam to C++ TDECPARAM
  jclass cls = env->FindClass("com/gshx/camera/tiandi/TDDecParam");
  if (cls == nullptr) {
    return -1;
  }

  bool success = false;
  jstring jstr = nullptr;
  do {
    jfieldID fid = env->GetFieldID(cls, "ip", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string ip = JniString2Native(env, jstr);
    strncpy(item->m_ip, ip.c_str(), sizeof(item->m_ip));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // submask is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "submask", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string submask = JniString2Native(env, jstr);
    strncpy(item->m_submask, submask.c_str(), sizeof(item->m_submask));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // gateway is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "gateway", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string gateway = JniString2Native(env, jstr);
    strncpy(item->m_gateway, gateway.c_str(), sizeof(item->m_gateway));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // dns is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "dns", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string dns = JniString2Native(env, jstr);
    strncpy(item->m_dns, dns.c_str(), sizeof(item->m_dns));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // mac_address is List<String> type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "mac_address", "Ljava/util/List;");
    if (fid == nullptr) {
      break;
    }
    jobject list = (jobject)env->GetObjectField(jitem, fid);
    if (list == nullptr) {
      break;
    }
    jclass list_cls = env->GetObjectClass(list);
    if (list_cls == nullptr) {
      break;
    }
    jmethodID mid = env->GetMethodID(list_cls, "size", "()I");
    if (mid == nullptr) {
      break;
    }
    jint size = env->CallIntMethod(list, mid);
    if (size != DEC_MAX_LAN_NUM) {
      break;
    }
    mid = env->GetMethodID(list_cls, "get", "(I)Ljava/lang/Object;");
    if (mid == nullptr) {
      break;
    }
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      jstr = (jstring)env->CallObjectMethod(list, mid, i);
      if (jstr == nullptr) {
        break;
      }
      std::string mac_address = JniString2Native(env, jstr);
      strncpy(item->m_tMacAddress[i].cMac, mac_address.c_str(),
              sizeof(item->m_tMacAddress[i].cMac));
      if (jstr != nullptr) {
        env->DeleteLocalRef(jstr);
        jstr = nullptr;
      }
    }
    if (list_cls != nullptr) {
      env->DeleteLocalRef(list_cls);
      list_cls = nullptr;
    }
    if (list != nullptr) {
      env->DeleteLocalRef(list);
      list = nullptr;
    }
    // ddnsIP is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "ddnsIP", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string ddns_ip = JniString2Native(env, jstr);
    strncpy(item->m_ddnsIP, ddns_ip.c_str(), sizeof(item->m_ddnsIP));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // ddnsUser is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "ddnsUser", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string ddns_user = JniString2Native(env, jstr);
    strncpy(item->m_ddnsUser, ddns_user.c_str(), sizeof(item->m_ddnsUser));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // ddnsPassword is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "ddnsPassword", "Ljava/lang/String;");
    if (fid == nullptr) {
      break;
    }
    jstr = (jstring)env->GetObjectField(jitem, fid);
    if (jstr == nullptr) {
      break;
    }
    std::string ddns_password = JniString2Native(env, jstr);
    strncpy(item->m_ddnsPass, ddns_password.c_str(), sizeof(item->m_ddnsPass));
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // ddnsPort is Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "ddnsPort", "I");
    if (fid == nullptr) {
      break;
    }
    jint ddns_port = env->GetIntField(jitem, fid);
    item->m_ddnsPort = ddns_port;
    // ispal is Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "ispal", "I");
    if (fid == nullptr) {
      break;
    }
    jint is_pal = env->GetIntField(jitem, fid);
    item->m_ispal = is_pal;
    // language is Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "language", "I");
    if (fid == nullptr) {
      break;
    }
    jint language = env->GetIntField(jitem, fid);
    item->m_language = language;
    // List<TCom485> is List<TCom485> type, GetFieldID return jfieldID
    // TODO(hhool): implement this
    // alarm_out is Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "alarm_out", "I");
    if (fid == nullptr) {
      break;
    }
    jint alarm_out = env->GetIntField(jitem, fid);
    item->m_Alarmout = alarm_out;
    // alarm_mode is Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "alarm_mode", "I");
    if (fid == nullptr) {
      break;
    }
    jint alarm_mode = env->GetIntField(jitem, fid);
    item->m_AlarmMode = alarm_mode;
    // channel is Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "channel", "I");
    if (fid == nullptr) {
      break;
    }
    jint channel = env->GetIntField(jitem, fid);
    item->m_iChannel = channel;
    // com_num is Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "com_num", "I");
    if (fid == nullptr) {
      break;
    }
    jint com_num = env->GetIntField(jitem, fid);
    item->m_iComNumber = com_num;
    // chan_mode is array of Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "chan_mode", "[I");
    if (fid == nullptr) {
      break;
    }
    jintArray chan_mode = (jintArray)env->GetObjectField(jitem, fid);
    if (chan_mode == nullptr) {
      break;
    }
    jint* chan_mode_array = env->GetIntArrayElements(chan_mode, nullptr);
    if (chan_mode_array == nullptr) {
      if (chan_mode != nullptr) {
        env->DeleteLocalRef(chan_mode);
        chan_mode = nullptr;
      }
      break;
    }
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      item->m_nChanMode[i] = chan_mode_array[i];
    }
    env->ReleaseIntArrayElements(chan_mode, chan_mode_array, 0);
    // vga_size is array of Int type, GetFieldID return jfieldID
    fid = env->GetFieldID(cls, "vga_size", "[I");
    if (fid == nullptr) {
      break;
    }
    jintArray vga_size = (jintArray)env->GetObjectField(jitem, fid);
    if (vga_size == nullptr) {
      break;
    }
    jint* vga_size_array = env->GetIntArrayElements(vga_size, nullptr);
    if (vga_size_array == nullptr) {
      if (vga_size != nullptr) {
        env->DeleteLocalRef(vga_size);
        vga_size = nullptr;
      }
      break;
    }
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      item->m_iVGASize[i] = vga_size_array[i];
    }
    env->ReleaseIntArrayElements(vga_size, vga_size_array, 0);
  } while (0);
  if (jstr != nullptr) {
    env->DeleteLocalRef(jstr);
    jstr = nullptr;
  }
  if (cls != nullptr) {
    env->DeleteLocalRef(cls);
    cls = nullptr;
  }

  if (!success) {
    return -1;
  }
  return 0;
}

jobject NativeTDecParam2Jni(JNIEnv* env, const TDECPARAM& item) {
  jclass jcls = nullptr;
  jobject jitem = nullptr;
  jobject list = nullptr;
  jstring jstr = nullptr;
  bool success = false;
  do {
    if (env == nullptr) {
      LOG_F(LG_ERROR) << "env is nullptr";
      break;
    }
    jcls = env->FindClass("com/gshx/camera/tiandi/TDecParam");
    if (jcls == nullptr) {
      LOG_F(LG_ERROR) << "jcls is nullptr";
      break;
    }
    // TDecParam(int iChannel) constructor jmethodId is <init>(I)V
    // then call NewObject to create a new object of TDecParam class
    // like this: TDecParam jitem = new TDecParam(item.m_iChannel);
    // jni like this: jitem = env->NewObject(jcls, mid, item.m_iChannel);
    // jitem is TDecParam object,
    // 1 for windows platform, 2 for linux platform
    int type = 2;
#if defined(_WIN32) || defined(_WIN64)
    type = 1;
#endif
    jmethodID mid = env->GetMethodID(jcls, "<init>", "(I)V");
    jitem = env->NewObject(jcls, mid, type);
    if (jitem == nullptr) {
      LOG_F(LG_ERROR) << "jitem is nullptr";
      break;
    }
    // ip is String type, GetFieldID return jfieldID
    jfieldID fid = env->GetFieldID(jcls, "ip", "Ljava/lang/String;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid is nullptr";
      break;
    }
    jstr = env->NewStringUTF(item.m_ip);
    if (jstr == nullptr) {
      LOG_F(LG_ERROR) << "jstr is nullptr";
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // submask is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "submask", "Ljava/lang/String;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid is nullptr";
      break;
    }
    jstr = env->NewStringUTF(item.m_submask);
    if (jstr == nullptr) {
      LOG_F(LG_ERROR) << "jstr is nullptr";
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // gateway is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "gateway", "Ljava/lang/String;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid is nullptr";
      break;
    }
    jstr = env->NewStringUTF(item.m_gateway);
    if (jstr == nullptr) {
      LOG_F(LG_ERROR) << "jstr is nullptr";
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // dns is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "dns", "Ljava/lang/String;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid dns is nullptr";
      break;
    }
    jstr = env->NewStringUTF(item.m_dns);
    if (jstr == nullptr) {
      LOG_F(LG_ERROR) << "jstr is nullptr";
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // mac_address is List<String> type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "mac_address", "Ljava/util/List;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid mac_address is nullptr";
      break;
    }
    jclass list_cls = env->FindClass("java/util/ArrayList");
    if (list_cls == nullptr) {
      LOG_F(LG_ERROR) << "list_cls is nullptr";
      break;
    }
    mid = env->GetMethodID(list_cls, "<init>", "()V");
    if (mid == nullptr) {
      LOG_F(LG_ERROR) << "mid is nullptr";
      break;
    }
    list = env->NewObject(list_cls, mid);
    if (list == nullptr) {
      LOG_F(LG_ERROR) << "list is nullptr";
      break;
    }
    mid = env->GetMethodID(list_cls, "add", "(Ljava/lang/Object;)Z");
    if (mid == nullptr) {
      LOG_F(LG_ERROR) << "mid is nullptr";
      env->DeleteLocalRef(list_cls);
      env->DeleteLocalRef(list);
      break;
    }
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      jstr = env->NewStringUTF(item.m_tMacAddress[i].cMac);
      if (jstr == nullptr) {
        env->DeleteLocalRef(list_cls);
        env->DeleteLocalRef(list);
        break;
      }
      env->CallBooleanMethod(list, mid, jstr);
      env->DeleteLocalRef(jstr);
    }
    fid = env->GetFieldID(jcls, "mac_address", "Ljava/util/List;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid mac_address is nullptr";
      break;
    }
    env->SetObjectField(jitem, fid, list);
    if (list_cls != nullptr) {
      env->DeleteLocalRef(list_cls);
      list_cls = nullptr;
    }
    if (list != nullptr) {
      env->DeleteLocalRef(list);
      list = nullptr;
    }
    // ddnsIP is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "ddnsIP", "Ljava/lang/String;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid ddnsIP is nullptr";
      break;
    }
    jstr = env->NewStringUTF(item.m_ddnsIP);
    if (jstr == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // ddnsUser is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "ddnsUser", "Ljava/lang/String;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid ddnsUser is nullptr";
      break;
    }
    jstr = env->NewStringUTF(item.m_ddnsUser);
    if (jstr == nullptr) {
      LOG_F(LG_ERROR) << "jstr is nullptr";
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // ddnsPassword is String type, GetFieldID return jfieldID
    fid = env->GetFieldID(jcls, "ddnsPassword", "Ljava/lang/String;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid ddnsPassword is nullptr";
      break;
    }
    jstr = env->NewStringUTF(item.m_ddnsPass);
    if (jstr == nullptr) {
      break;
    }
    env->SetObjectField(jitem, fid, jstr);
    if (jstr != nullptr) {
      env->DeleteLocalRef(jstr);
      jstr = nullptr;
    }
    // ddnsPort is int type, GetFieldID return jfieldID
    jint ddnsPort = item.m_ddnsPort;
    fid = env->GetFieldID(jcls, "ddnsPort", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid ddnsPort is nullptr";
      break;
    }
    env->SetIntField(jitem, fid, ddnsPort);
    // ispal is int type, GetFieldID return jfieldID
    jint isPal = item.m_ispal;
    fid = env->GetFieldID(jcls, "ispal", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid ispal is nullptr";
      break;
    }
    env->SetIntField(jitem, fid, isPal);
    // language is int type, GetFieldID return jfieldID
    jint language = item.m_language;
    fid = env->GetFieldID(jcls, "language", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid language is nullptr";
      break;
    }
    env->SetIntField(jitem, fid, language);
    // com485 is array type, GetFieldID return jfieldID
    jobjectArray com485 = env->NewObjectArray(
        DEC_MAX_LAN_NUM, env->FindClass("com/gshx/camera/tiandi/TCom485"),
        nullptr);
    if (com485 == nullptr) {
      LOG_F(LG_ERROR) << "com485 is nullptr";
      break;
    }
    fid = env->GetFieldID(jcls, "com485", "[Lcom/gshx/camera/tiandi/TCom485;");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid com485 is nullptr";
      break;
    }
    env->SetObjectField(jitem, fid, com485);
    // trans TDECPARAM 485 member to TCom485
    TCOM485 tcom485[DEC_MAX_LAN_NUM];
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      tcom485[i].m_type = item.m_rs485type[i];
      tcom485[i].m_address = item.m_rs485address[i];
      tcom485[i].m_baudrate = item.m_rs485baudrate[i];
      tcom485[i].m_databit = item.m_rs485databit[i];
      tcom485[i].m_stopbit = item.m_rs485stopbit[i];
      tcom485[i].m_checkbit = item.m_rs485checkbit[i];
      tcom485[i].m_flowcontrol = item.m_rs485flowcontrol[i];
    }
    // fill com485 array
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      jobject jcom485 = NativeTCom4852Jni(env, tcom485[i]);
      if (jcom485 == nullptr) {
        LOG_F(LG_ERROR) << "jcom485 is nullptr";
        break;
      }
      env->SetObjectArrayElement(com485, i, jcom485);
      if (jcom485 != nullptr) {
        env->DeleteLocalRef(jcom485);
        jcom485 = nullptr;
      }
    }
    // alarm_out is int type, GetFieldID return jfieldID
    jint alarm_out = item.m_Alarmout;
    fid = env->GetFieldID(jcls, "alarm_out", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid alarm_out is nullptr";
      break;
    }
    env->SetIntField(jitem, fid, alarm_out);
    // alarm_mode is int type, GetFieldID return jfieldID
    jint alarm_mode = item.m_AlarmMode;
    fid = env->GetFieldID(jcls, "alarm_mode", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid alarm_mode is nullptr";
      break;
    }
    env->SetIntField(jitem, fid, alarm_mode);
    // channel is int type, GetFieldID return jfieldID
    jint channel = item.m_iChannel;
    fid = env->GetFieldID(jcls, "channel", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid channel is nullptr";
      break;
    }
    env->SetIntField(jitem, fid, channel);
    // com_num is int type, GetFieldID return jfieldID
    jint com_num = item.m_iComNumber;
    fid = env->GetFieldID(jcls, "com_num", "I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid com_num is nullptr";
      break;
    }
    env->SetIntField(jitem, fid, com_num);
    // chan_mode is int array type, GetFieldID return jfieldID
    jintArray chan_mode = env->NewIntArray(DEC_MAX_LAN_NUM);
    if (chan_mode == nullptr) {
      break;
    }
    fid = env->GetFieldID(jcls, "chan_mode", "[I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid chan_mode is nullptr";
      break;
    }
    jint buf[DEC_MAX_LAN_NUM];
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      buf[i] = item.m_nChanMode[i];
    }
    env->SetIntArrayRegion(chan_mode, 0, DEC_MAX_LAN_NUM, buf);
    env->SetObjectField(jitem, fid, chan_mode);
    if (chan_mode != nullptr) {
      env->DeleteLocalRef(chan_mode);
      chan_mode = nullptr;
    }
    // vga_size is int array type, GetFieldID return jfieldID
    jintArray vga_size = env->NewIntArray(DEC_MAX_LAN_NUM);
    if (vga_size == nullptr) {
      break;
    }
    fid = env->GetFieldID(jcls, "vga_size", "[I");
    if (fid == nullptr) {
      LOG_F(LG_ERROR) << "fid vga_size is nullptr";
      break;
    }
    jint jint_buf[DEC_MAX_LAN_NUM];
    for (int i = 0; i < DEC_MAX_LAN_NUM; i++) {
      jint_buf[i] = item.m_iVGASize[i];
    }
    env->SetIntArrayRegion(vga_size, 0, DEC_MAX_LAN_NUM, jint_buf);
    env->SetObjectField(jitem, fid, vga_size);
    if (vga_size != nullptr) {
      env->DeleteLocalRef(vga_size);
      vga_size = nullptr;
    }
    success = true;
  } while (0);
  if (jstr != nullptr) {
    env->DeleteLocalRef(jstr);
    jstr = nullptr;
  }
  if (list != nullptr) {
    env->DeleteLocalRef(list);
    list = nullptr;
  }
  if (jcls != nullptr) {
    env->DeleteLocalRef(jcls);
    jcls = nullptr;
  }

  if (!success) {
    return nullptr;
  }
  return jitem;
}
}  // namespace nvsdk
