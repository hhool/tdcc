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

#ifndef D__PROJECT_TIANDI_TIANDI_JAVA_JNI_COMMON_H_
#define D__PROJECT_TIANDI_TIANDI_JAVA_JNI_COMMON_H_

#include <jni.h>
#include <string>
#include <vector>

#define LOG_TAG "JNI"

// jni for windows and linux, not for android ios
#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <tchar.h>
#include <strsafe.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <wininet.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#elif __linux__
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#endif

#endif  // D__PROJECT_TIANDI_TIANDI_JAVA_JNI_COMMON_H_
