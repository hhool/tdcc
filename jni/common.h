/**
 * @file common.h
 * @author hhool (hhool@outlook.com)
 * @brief  common header file.
 * @version 0.1
 * @date 2024-09-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef JNI_COMMON_H_
#define JNI_COMMON_H_

#include <jni.h>
#include <string>
#include <vector>

#define LOG_TAG "JNI"

// jni for windows and linux, not for android ios
#ifdef _WIN32
#include <direct.h>
#include <io.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <strsafe.h>
#include <tchar.h>
#include <windows.h>
#include <wininet.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#elif __linux__
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

// LOG with tag for printf
#if defined(ENABLE_LOG)
#define LOGI(...)                   \
  {                                 \
    printf("[INFO] %s: ", LOG_TAG); \
    printf(__VA_ARGS__);            \
  }
#define LOGE(...)                    \
  {                                  \
    printf("[ERROR] %s: ", LOG_TAG); \
    printf(__VA_ARGS__);             \
  }
#define LOGD(...)                    \
  {                                  \
    printf("[DEBUG] %s: ", LOG_TAG); \
    printf(__VA_ARGS__);             \
  }
#else
#define LOGI(...)  // do nothing
#define LOGE(...)  // do nothing
#define LOGD(...)  // do nothing
#endif

#define CHECK_PTR_RET_FAIL(ptr) \
  if (ptr == nullptr) {         \
    return -1;                  \
  }
#define CHECK_PTR_RET(ptr, ret) \
  if (ptr == nullptr) {         \
    return ret;                 \
  }
#define CHECK_PTR_RET_VOID(ptr) \
  if (ptr == nullptr) {         \
    return;                     \
  }

#endif  // JNI_COMMON_H_
