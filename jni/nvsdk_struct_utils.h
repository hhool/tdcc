/**
 * @file nvsdk_struct_utils.h
 * @author hhool (hhool@outlook.com)
 * @brief jni nvsdk struct utils header file.
 * @version 0.1
 * @date 2024-09-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef JNI_NVSDK_STRUCT_UTILS_H_
#define JNI_NVSDK_STRUCT_UTILS_H_

#include <DecCtrlClientTypes.h>
#include "CLS_NVDSDKHelper.h"

#include <jni.h>

#include <cstring>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace nvsdk {

std::string JniString2Native(JNIEnv* env, jstring jstr);

typedef struct TCOM485 {
  uint8_t m_type;
  uint8_t m_address;
  int m_baudrate;         // 波特率
  uint8_t m_databit;      // 数据位
  uint8_t m_stopbit;      // 停止位
  uint8_t m_checkbit;     // 校验位
  uint8_t m_flowcontrol;  // 流控
}TCOM485;

int JniTCom4852Native(JNIEnv* env, jobject jitem, TCOM485* item);
jobject NativeTCom4852Jni(JNIEnv* env, const TCOM485& item);

int JniTNVSItem2Native(JNIEnv* env, jobject jitem, TNVSITEM* item);
jobject NativeTNVSItem2Jni(JNIEnv* env, const TNVSITEM& item);

int JniTNVSItemEx2Native(JNIEnv* env, jobject jitem, TNVSITEMEX* item);
jobject NativeTNVSItemEx2Jni(JNIEnv* env, const TNVSITEMEX& item);

int JniTDecParam2Native(JNIEnv* env, jobject jitem, TDECPARAM* item);
jobject NativeTDecParam2Jni(JNIEnv* env, const TDECPARAM& item);
}  // namespace nvsdk

#endif  // JNI_NVSDK_STRUCT_UTILS_H_
