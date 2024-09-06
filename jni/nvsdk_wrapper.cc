/**
 * @file nvsdk_wrapper.cc
 * @author hhool (hhool@outlook.com)
 * @brief  nvsdk wrapper source file.
 * @version 0.1
 * @date 2024-09-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "nvsdk_wrapper.h"

#include "common.h"
#include "common/logger.h"

namespace nvsdk {

namespace {

const int MAX_DECNUM = 1024;
const int MAX_NVSNUM = 128;
const unsigned int START_MSG = 90000;
}  // namespace

NVSDKWrapper::NVSDKWrapper() {
  pClsNVD_ = new CLS_NVDSDKHelper();
}

NVSDKWrapper::~NVSDKWrapper() {
  if (pClsNVD_) {
    delete pClsNVD_;
    pClsNVD_ = NULL;
  }
}

bool NVSDKWrapper::LoadNativeLibrary(JNIEnv* env) {
  int ret = -1;
  const char* path = "/tmp/libnvdsdk.so";
  ret = pClsNVD_->LoadLibrary(path);
  if (ret <= 0) {
    return false;
  }
  return true;
}

void NVSDKWrapper::UnloadNativeLibrary(JNIEnv* env) {
  if (pClsNVD_) {
    pClsNVD_->FreeLibrary();
  }
}

int NVSDKWrapper::ClientStartup(JNIEnv* env,
                                uint32_t message,
                                void* wndContext) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStartup(message, wndContext);
  return ret;
}

int NVSDKWrapper::ClientCleanup(JNIEnv* env) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientCleanup();
  return ret;
}

///////////////////////////////////////////////////////////////////////////////
int NVSDKWrapper::ClientSetComRecvNotify(JNIEnv* env,
                                         DEC_COMRECV_NOTIFY callback,
                                         void* context) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientSetComRecvNotify(callback);
  return ret;
}

int NVSDKWrapper::ClientSetComMsgCallback(JNIEnv* env,
                                          pTDPostMessage callback,
                                          void* context) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientSetMsgCallback(callback);
  return ret;
}

int NVSDKWrapper::ClientLogin(JNIEnv* env,
                              const char* ip,
                              int port,
                              const char* user,
                              const char* pwd,
                              void* context) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  std::string ip_str = ip;
  std::string user_str = user;
  std::string pwd_str = pwd;
  ret = pClsNVD_->DEC_ClientLogon(const_cast<char*>(ip_str.c_str()),
                                  const_cast<char*>(user_str.c_str()),
                                  const_cast<char*>(pwd_str.c_str()), port);
  LOG_F(LG_INFO) << "DEC_ClientLogon ret: " << ret << " ip: " << ip_str
                 << " port: " << port << " user: " << user_str
                 << " pwd: " << pwd_str;
  return ret;
}

int NVSDKWrapper::ClientLogout(JNIEnv* env, int iID, void* context) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientLogout(iID);
  LOG_F(LG_INFO) << "DEC_ClientLogout ret: " << ret << " iID: " << iID;
  return ret;
}

int NVSDKWrapper::GetDevConfig(JNIEnv* env,
                               int iID,
                               int iChanel,
                               int ipos,
                               int icmd,
                               char* pBuf,
                               int iBufLen) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->procDEC_ClientGetDevConfig(iID, iChanel, ipos, icmd, pBuf,
                                             iBufLen);
  LOG_F(LG_INFO) << "DEC_ClientGetDevConfig ret: " << ret << " iID: " << iID
                 << " iChanel: " << iChanel << " ipos: " << ipos
                 << " icmd: " << icmd << " pBuf: " << pBuf
                 << " iBufLen: " << iBufLen;
  return ret;
}

int NVSDKWrapper::SetDevConfig(JNIEnv* env,
                               int iID,
                               int iChanel,
                               int ipos,
                               int icmd,
                               char* pBuf,
                               int iBufLen) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->procDEC_ClientSetDevConfig(iID, iChanel, ipos, icmd, pBuf,
                                             iBufLen);
  LOG_F(LG_INFO) << "DEC_ClientSetDevConfig ret: " << ret << " iID: " << iID
                 << " iChanel: " << iChanel << " ipos: " << ipos
                 << " icmd: " << icmd << " pBuf: " << pBuf
                 << " iBufLen: " << iBufLen;

  return ret;
}

int NVSDKWrapper::ClientStartPushStream(JNIEnv* env,
                                        int iID,
                                        int iChannel,
                                        int iPos,
                                        int iEncodeMode,
                                        int iVideoSize) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStartPushStream(iID, iChannel, iPos, iEncodeMode,
                                            iVideoSize);
  LOG_F(LG_INFO) << "DEC_ClientStartPushStream ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " iEncodeMode: " << iEncodeMode
                 << " iVideoSize: " << iVideoSize;
  return ret;
}

int NVSDKWrapper::ClientStreamControl(JNIEnv* env,
                                      int iPushID,
                                      int iCmd,
                                      int iCmdValue) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->procDEC_ClientStreamControl(iPushID, iCmd, &iCmdValue,
                                              sizeof(int));
  LOG_F(LG_INFO) << "DEC_ClientStreamControl ret: " << ret
                 << " iPushID: " << iPushID << " iCmd: " << iCmd
                 << " iCmdValue: " << iCmdValue;
  return ret;
}

int NVSDKWrapper::ClientConfigStreamInfo(JNIEnv* env,
                                         int iID,
                                         int iChannel,
                                         int iPos,
                                         int iCmd,
                                         uint8_t* iCmdValue,
                                         int iCmdValueLen) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->procDEC_ClientConfigStreamInfo(iID, iChannel, iPos, iCmd,
                                                 iCmdValue, iCmdValueLen);
  LOG_F(LG_INFO) << "DEC_ClientConfigStreamInfo ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " iCmd: " << iCmd << " iCmdValue: " << iCmdValue
                 << " iCmdValueLen: " << iCmdValueLen;
  return ret;
}

int NVSDKWrapper::ClientSendStream(JNIEnv* env,
                                   int iPushID,
                                   int iLen,
                                   char* cStreamBuf) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientSendStream(iPushID, iLen, cStreamBuf);
  LOG_F(LG_INFO) << "DEC_ClientSendStream ret: " << ret
                 << " iPushID: " << iPushID << " iLen: " << iLen
                 << " cStreamBuf: " << cStreamBuf;
  return ret;
}

int NVSDKWrapper::ClientStopPushStream(JNIEnv* env, int iPushID) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStopPushStream(iPushID);
  LOG_F(LG_INFO) << "DEC_ClientStopPushStream ret: " << ret
                 << " iPushID: " << iPushID;
  return ret;
}

int NVSDKWrapper::ClientSendNonstandardRawFrame(JNIEnv* env,
                                                int iPushID,
                                                char* cStreamBuf,
                                                int iLen) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->procDEC_ClientSendNonstandardRawFrame(iPushID, iLen,
                                                        cStreamBuf);
  LOG_F(LG_INFO) << "DEC_ClientSendNonstandardRawFrame ret: " << ret
                 << " iPushID: " << iPushID << " iLen: " << iLen
                 << " cStreamBuf: " << cStreamBuf;
  return ret;
}

int NVSDKWrapper::ClientGetStreamBufferState(JNIEnv* env,
                                             int iPushID,
                                             int* iBufState) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->procDEC_ClientGetStreamBufferState(iPushID, iBufState);
  LOG_F(LG_INFO) << "DEC_ClientGetStreamBufferState ret: " << ret
                 << " iPushID: " << iPushID << " iBufState: " << iBufState;
  return ret;
}

int NVSDKWrapper::ClientGetDecoderParam(JNIEnv* env, int iID, TDECPARAM* tp) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  CHECK_PTR_RET_FAIL(tp);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientGetDecoderPara(iID, tp);
  LOG_F(LG_INFO) << "DEC_ClientGetDecoderPara ret: " << ret << " iID: " << iID
                 << " tp: " << tp;
  return ret;
}

int NVSDKWrapper::ClientStartView(JNIEnv* env,
                                  int iID,
                                  TNVSITEM* pItem,
                                  int iChannel,
                                  int iPos) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStartView(iID, pItem, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientStartView ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " pItem: " << pItem;
  return ret;
}

int NVSDKWrapper::ClientStopView(JNIEnv* env,
                                 int iID,
                                 int iChannel,
                                 int iPos,
                                 int iShowLastPic) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStopView(iID, iChannel, iPos, iShowLastPic);
  LOG_F(LG_INFO) << "DEC_ClientStopView ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " iShowLastPic: " << iShowLastPic;
  return ret;
}

int NVSDKWrapper::ClientStartViewEx(JNIEnv* env,
                                    int iID,
                                    TNVSITEMEX* pItem,
                                    int iChannel,
                                    int iPos) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStartViewEx(iID, pItem, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientStartViewEx ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " pItem: " << pItem;
  return ret;
}

int NVSDKWrapper::ClientGetLoopItemCount(JNIEnv* env,
                                         int iID,
                                         int iChannel,
                                         int iPos) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientGetLoopItemCount(iID, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientGetLoopItemCount ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos;
  return ret;
}

int NVSDKWrapper::ClientGetLoopItem(JNIEnv* env,
                                    int iID,
                                    int iIndex,
                                    int iChannel,
                                    int iPos,
                                    TNVSITEM* tnvs_item) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientGetLoopItem(iID, iIndex, tnvs_item, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientGetLoopItem ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " iIndex: " << iIndex;
  return ret;
}

int NVSDKWrapper::ClientGetLoopItemEx(JNIEnv* env,
                                      int iID,
                                      int iIndex,
                                      int iChannel,
                                      int iPos,
                                      TNVSITEMEX* pItem) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientGetLoopItemEx(iID, iIndex, pItem, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientGetLoopItemEx ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos
                 << " iIndex: " << iIndex << " pItem: " << pItem;
  return ret;
}

int NVSDKWrapper::ClientStartLoop(JNIEnv* env,
                                  int iID,
                                  int iChannel,
                                  int iPos) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStartLoop(iID, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientStartLoop ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos;
  return ret;
}

int NVSDKWrapper::ClientStopLoop(JNIEnv* env, int iID, int iChannel, int iPos) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientStopLoop(iID, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientStopLoop ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos;
  return ret;
}

int NVSDKWrapper::ClientGetLoopStatus(JNIEnv* env,
                                      int iID,
                                      int iChannel,
                                      int iPos) {
  CHECK_PTR_RET_FAIL(pClsNVD_);
  int32_t ret = -1;
  ret = pClsNVD_->DEC_ClientGetLoopStatus(iID, iChannel, iPos);
  LOG_F(LG_INFO) << "DEC_ClientGetLoopStatus ret: " << ret << " iID: " << iID
                 << " iChannel: " << iChannel << " iPos: " << iPos;
  return ret;
}

}  // namespace nvsdk
