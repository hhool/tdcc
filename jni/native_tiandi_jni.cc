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

JNIEXPORT jlong JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeCreateInstance(JNIEnv *,
                                                              jobject)
{
  return 0;
}

JNIEXPORT void JNICALL
Java_com_gshx_camera_tiandi_NVSDKClient_nativeDestroyInstance(JNIEnv *,
                                                               jobject,
                                                               jlong)
{
}
