package com.gshx.camera.tiandi;

public class NVSDKClient {
    private long nativePtr = 0;

    static {
        try {
            if (NativeLoader.load()) {
                System.out.println("Successfully loaded Tiandi_jni.");
            }
        } catch (Exception e) {
            // TODO(hhool): Auto-generated catch block
            e.printStackTrace();
        }
    }

    public NVSDKClient() {
        nativePtr = nativeCreateInstance();
    }

    public void Dispose() {
        nativeDestroyInstance(nativePtr);
    }


    private native long nativeCreateInstance();

    private native void nativeDestroyInstance(long ptr);

    private native int nativeClientStartup(long port, long ptr);

    private native int nativeClientCleanup();

    private native int nativeClientLogin(String ip, int port, String user, String password);

    private native int nativeClientLogin(String ip, int port, String user, String password,
            long context);

    private native int nativeClientLogout(long uID);

    private native int nativeClientLogout(long uID, long context);

    private native int nativeClientStartPushStream(long uID, int iChannel, int iPos, int iEncodeMode,
            int iVideoSize);

    private native int nativeClientStartPushStreamEx(long uID, int iChannel, int iPos,
            int iEncodeMode, int iVideoSize, String sEncrytKey);

    private native int nativeClientStartPushStream_V1(long uID, int iChannel, int iPos,
            String sEncrytKey, String sFileHeader, int iSize);

    private native int nativeClientSendStream(long uPushID, byte[] streamBuf, int iLen);

    private native int nativeClientStopPushStream(long uPushID);

    private native int nativeClientStopPushStreamEx(long uPushID, boolean bShowLastPic);

    private native int nativeClientGetStreamBufferState(long uPushID);

    private native int nativeClientStreamControl(long uPushID, int iCmd, byte[] pCmdBuf, int iLen);

    private native int nativeClientSendRawFrame(long uPushID, byte[] pStreamBuf, int iLen);

    private TDDecParam tdDecParam = new TDDecParam();

    private native int nativeClientGetDecoderPara(int iId, TDDecParam pDecParam);

    private native int nativeClientSetDDNS(int iId, String svrIP, String userName, String passWord,
            int port);

    private native int nativeClientSetAlarmOut(int iId, int ialarmOUt, int ialarmMode);

    private native int nativeClientSetTVInfo(int iId, int iIsPAL, int iLanguage);

    private native int nativeClientSetChannelMode(int iId, int iChannel, int iMode);

    private native int nativeClientSetLogo(int iId, TLogoParam pLogoParam);

    private TLogoParam tdLogoParam = new TLogoParam();

    private native int nativeClientGetLog(int iId);

    private native int nativeClientGetLoopItemCount(int iId, int iChannel, int iPos);

    private TNVSItem tnvsItem = new TNVSItem();

    private native int nativeClientGetLoopItem(int iId, int iIndex, TNVSItem pNVSItem, int iChannel,
            int iPos);

    private TNVSItemEx tnvsItemEx = new TNVSItemEx();

    private native int nativeClientGetLoopItemEx(int iId, int iIndex, TNVSItemEx pNVSItemEx,
            int iChannel, int iPos);

    private native int nativeClientSetLoopItem_V1(int iId, int iChannel, int iPos, int iIndex,
            int iServerType, TServerCommonInfo serverInfo);

    private TServerCommonInfo tServerCommonInfo = new TServerCommonInfo();

    private native int nativeClientStartLoop(int iId, int iChannel, int iPos);

    private native int nativeClientStopLoop(int iId, int iChannel, int iPos);

    private native int nativeClientGetLoopStatus(int iId, int iChannel, int iPos);

    private native int nativeClientStopView(int iId, int iChannel, int iPos, boolean bShowLastPic);

    // TODO(hhool): make sure args with nativeClientStopView_V1 are correct.
    // nativeClientStopView_V1(int _iID, void* _pvPara , int _iBufSize);
    private native int nativeClientStopView_V1(int iId, int iChannel, int iPos, boolean bShowLastPic);

    private native int nativeClientStartView(int iId, TNVSItem pPara, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClientStartViewEx(int iId, TNVSItemEx pPara, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClientStartView_V1(int iId, int iChannel, int iPos, int iServerType,
            TServerCommonInfo puItem);

    private native int nativeClientGetViewItem(int iId, TNVSItem pPara, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClientGetViewItemEx(int iId, TNVSItemEx pPara, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClientGetViewItem_V1(int iId, int iChannel, int iPos, int piServerType,
            TServerCommonInfo puItem);

    private native int nativeClientSendKey(int iId, int iKeyCode);

    private native int nativeClientPTZCtrl(int iId, int iCtrlCode, int iVal, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClient485Send(int iId, byte[] pData, int iSize, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClientGetPTZprotocols(int iId, TDecProtocol pProtocol);

    private TDecProtocol tDecProtocol = new TDecProtocol();

    private native int nativeClientSoundCtrl(int iId, int bOn, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClientTalkServer(int iId, int bOn, int iChannel /* =0 */,
            int iPos /* =0 */);

    private native int nativeClientGetAudioStatus(int iId, int iChannel /* =0 */, int iPos /* =0 */);

    private native int nativeClientGetTalkStatus(int iId, int iChannel /* =0 */, int iPos /* =0 */);

    private native int nativeClientRebootDecoder(int iId);

    private native int nativeClientResetDefault(int iId);

    private native int nativeClientUpgrade(int iId, String pcFileName);

    private native int nativeClientUpgradeLogo(int iId, String pcFileName);

    private native int nativeClientUpgradeProtocol(int iId, String pcFilePath, String pcFileName);

    private native int nativeClientDeleteProtocol(int iId, String pcProtocol);

    private native int nativeClientGetVersion(int iId, String pcVer);

    private native int nativeClientGetSDKVersion(TNVDSdkVersion pVer);

    private TNVDSdkVersion tNVDSdkVersion = new TNVDSdkVersion();

    private native int nativeClientSetComRecvNotify(IDecComRecvNotify comRecvNotify);

    private native int nativeClientSetMsgCallback(ITDPostMessageNotify tDPostMsg);

    private native int nativeClientSetMsgCallbackEx(ITDPostMessageNotify tDPostMsg);

    private native int nativeClientUpgradeWeb(int iId, String pcFileName);

    private native int nativeClientGetCapability(int iId, String pcCap);

    private native int nativeClientSetVGASize(int iId, int iChannel, int iSize);

    // 发送整帧原始NV裸流，定制接口
    private native int nativeClientSendNonstandardRawFrame(long uPushID, int iLen, byte[] cStreambuf);

    private native int nativeClientSetVolume(int iId, int iVolume);

    private native int nativeClientGetVolume(int iId);

    private int iVolume = 0;

    private native int nativeClientSetCommonEnable(int iId, int iEnableID, int iChannelNo,
            int iEnableValue);

    /*
     * _iEnableID: 0x13001:断网保留最后一帧; _iEnableValue：0--->不使能;1--->使能。 0x13002:预览偏好设置;
     * _iEnableValue：0--->低延时;1--->高流畅。
     */
    private native int nativeClientGetCommonEnable(int iId, int iEnableID);

    private boolean piEnableLastFrame = false;
    private boolean piEnablePreference = false;

    private native int nativeClientSetCommonEnableEx(int iId, int iEnableID, int iChannelNo,
            int iEnableValue);

    // 扩展接口，增加push流保留最后一帧需求
    // 扩展接口，增加音频采样率
    private native int nativeClientConfigStreamInfo(int _iID, int _iChannel, int _iPos, int _iCmd, byte[] _pvCmdBuf,
            int _iBuffSize);

    /***************************************************************
     * Function ： nativeClientSetDevConfig Description ： 设置解码器的某个参数，根据_iCmd不同，执行不同的操作 Prameter(in) ：
     * _ulID：登录ID _iChannel：通道号 _iPos: 画面号 _iCmd：操作码 _iBuffSize：传入缓冲区的大小 Prameter(in, out)：
     * _pvCmdBuf ： 传入缓冲区指针 return ： 0：成功 -1：缓冲区不足 other：失败 others ： 2013-08-14
     ***************************************************************/
    private native int nativeClientSetDevConfig(long _ulID, int _iChannel, int _iPos, int _iCmd,
            byte[] _pvCmdBuf, int _iBuffSize);


    /***************************************************************
     * Function ： nativeClientGetDevConfig Description ： 获取解码器的某个参数，根据_iCmd不同，执行不同的操作 Prameter(in) ：
     * _ulID：登录ID _iChannel：通道号 _iPos: 画面号 _iCmd：操作码 _iBuffSize：传入缓冲区的大小 Prameter(in, out)：
     * _pvCmdBuf ： 传入缓冲区指针 return ： 0：成功 -1：缓冲区不足 other：失败 others ： 2013-08-14
     ***************************************************************/
    private native int nativeClientGetDevConfig(long _ulID, int _iChannel, int _iPos, int _iCmd,
            byte[] _pvCmdBuf, int _iBuffSize);

    /***************************************************************
     * Function ： nativeClientSetAutoTest Description ： 自动化调试设置接口 Prameter(in) ： _ulID：登录ID _iCmd：操作码
     * _iBuffSize：传入缓冲区的大小 _pvCmdBuf： 传入缓冲区指针 return ： 0：成功 -1：缓冲区不足 other：失败 others ： 2014-06-11
     ***************************************************************/
    private native int nativeClientSetAutoTest(long _ulID, int _iCmd, byte[] _pvCmdBuf,
            int _iBuffSize);

    private native int nativeClientSetSelectPicture(long _lID, int _iChannel, int _iPicture);

    private native int nativeClientSetNotify(IDecNotify _pNotify);


    private native int nativeClientSetNetLog(long _lID, int _iEnable, int _iLogType,
            int _iLogSize);

    private native int nativeClientNetLogGetLogfile(long _ulID, int _iLogIndex, TDecLogData _pLogInfo,
            int _iSize);

    private native int nativeClientNetLogGetLogCount(long _ulID, int _iTotalCount,
            int _iCurrentCount);


    private native int nativeClientUserChangePassword(long _ulID, String _cUser, String _cOldPassword,
            String _cNewPassword);

    private native int nativeSetRegServer(long _lID, String _pcRegSvrIP, int _iRegSvrPort,
            int _iEnable);

    private native int nativeSetRegDevice(long _lID, String _pcPUID, String _pcPUName);

    private native int nativeSetRegChannel(long _lID, int _iChannelNum, String _pcPUID);

    private native int nativeSetDZInfo(long _lID, TDZInfoParam dzInfoParam);

    private native int nativeSetChannelSipConfig(long _lID, int _iCmd,
            TSetSipVideoChannel sipVideoChannel);

    private native int nativeSetPlatformStart(long _lID, TPlatforminfo platformInfo);

    private native int nativeGetPlatformInfo(long _lID);

    private TPlatforminfo platformInfo = new TPlatforminfo();

    private native int nativeGetRunningPlatformInfo(long _lID);

    private TPlatforminfo platformInfo_running = new TPlatforminfo();

    private native int nativeSetPlatformConfig(long _lID, int _iCmd, byte[] _lpInBuffer,
            int _iInBufferSize);

    private native int nativeClientGetClusterConfig(long _lID, int _iCmd, byte[] _lpOutBuffer);

    private native int nativeClientSendCommand(long _iID, int _iChannel, int _iPos, int _iCommand,
            byte[] _pBuffer);

    private native int nativeClientRecvCommand(long _iID, int _iChannel, int _iPos, int _iCommand,
            byte[] _pBuffer);

    private native int nativeClientGetLogonState(long _iID);

    private native int nativeClientSetSDKWorkMode(int _iWorkMode);

    private native int nativeClientSetExternDevLogonInfo(int _uiAllowDevType);

}
