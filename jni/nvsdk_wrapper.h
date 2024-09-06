/**
 * @file nvsdk_wrapper.h
 * @author your name (you@domain.com)
 * @brief nvsdk wrapper header file.
 * @version 0.1
 * @date 2024-09-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef JNI_NVSDK_WRAPPER_H_
#define JNI_NVSDK_WRAPPER_H_

#include <DecCtrlClientTypes.h>
#include "CLS_NVDSDKHelper.h"

#include <jni.h>
#include <cstring>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace nvsdk {

class NVSDKWrapper {
 public:
  NVSDKWrapper();
  NVSDKWrapper(NVSDKWrapper const&) = delete;
  void operator=(NVSDKWrapper const&) = delete;
  ~NVSDKWrapper();

 public:
  bool LoadNativeLibrary(JNIEnv* env);
  void UnloadNativeLibrary(JNIEnv* env);

  int ClientStartup(JNIEnv* env, uint32_t message, void* wndContext);
  int ClientCleanup(JNIEnv* env);
  int ClientSetComRecvNotify(JNIEnv* env,
                             DEC_COMRECV_NOTIFY callback,
                             void* context);
  int ClientSetComMsgCallback(JNIEnv* env,
                              pTDPostMessage callback,
                              void* context);
  int ClientLogin(JNIEnv* env,
                  const char* ip,
                  int port,
                  const char* user,
                  const char* pwd,
                  void* context = nullptr);
  int ClientLogout(JNIEnv* env, int iID, void* context = nullptr);

  int GetDevConfig(JNIEnv* env,
                   int iID,
                   int iChannel,
                   int iPos,
                   int icmd,
                   char* pBuf,
                   int iBufLen);
  int SetDevConfig(JNIEnv* env,
                   int iID,
                   int iChannel,
                   int iPos,
                   int icmd,
                   char* pBuf,
                   int iBufLen);
  int ClientStartPushStream(JNIEnv* env,
                            int iID,
                            int iChannel,
                            int iPos,
                            int iEncodeMode,
                            int iVideoSize);
  int ClientStreamControl(JNIEnv* env, int iPushID, int iCmd, int iCmdValue);
  int ClientConfigStreamInfo(JNIEnv* env,
                             int iID,
                             int iChannel,
                             int iPos,
                             int iCmd,
                             uint8_t* iCmdValue,
                             int iCmdValueLen);
  int ClientSendStream(JNIEnv* env, int iPushID, int iLen, char* cStreamBuf);
  int ClientStopPushStream(JNIEnv* env, int iPushID);
  int ClientSendNonstandardRawFrame(JNIEnv* env,
                                    int iPushID,
                                    char* cStreamBuf,
                                    int iLen);
  int ClientGetStreamBufferState(JNIEnv* env, int iPushID, int* iBufState);

  int ClientGetDecoderParam(JNIEnv* env, int iID, TDECPARAM* tp);

  int ClientStartView(JNIEnv* env,
                      int iID,
                      TNVSITEM* pItem,
                      int iChannel,
                      int iPos);
  int ClientStopView(JNIEnv* env,
                     int iID,
                     int iChannel,
                     int iPos,
                     int iShowLastPic);
  int ClientStartViewEx(JNIEnv* env,
                        int iID,
                        TNVSITEMEX* pItem,
                        int iChannel,
                        int iPos);

  int ClientGetLoopItemCount(JNIEnv* env, int iID, int iChannel, int iPos);
  int ClientGetLoopItem(JNIEnv* env,
                        int iID,
                        int iIndex,
                        int iChannel,
                        int iPos,
                        TNVSITEM* tnvs_item);
  int ClientGetLoopItemEx(JNIEnv* env,
                          int iID,
                          int iIndex,
                          int iChannel,
                          int iPos,
                          TNVSITEMEX* pItem);

  int ClientStartLoop(JNIEnv* env, int iID, int iChannel, int iPos);
  int ClientStopLoop(JNIEnv* env, int iID, int iChannel, int iPos);
  int ClientGetLoopStatus(JNIEnv* env, int iID, int iChannel, int iPos);

 private:
  CLS_NVDSDKHelper* pClsNVD_ = nullptr;
  void* handle_nvsdk_ = nullptr;
};
}  // namespace nvsdk

#endif  // JNI_NVSDK_WRAPPER_H_
