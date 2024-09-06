package com.gshx.camera.tiandi;

public class NVSDKClient {
        private long nativePtr = 0;

        // 登录状态
        public enum LoginState {
                DEC_LOGON_RETRY(2),
                DEC_LOGON_SUCCESS(0),
                DEC_LOGON_ING(1),
                DEC_LOGON_FAILED(-1),
                DEC_LOGON_TIMEOUT(-2),
                DEC_NOT_LOGON(-3);

                private final int value;

                LoginState(int value) {
                        this.value = value;
                }

                public int getValue() {
                        return value;
                }
        }

        // 流控类型
        public enum StreamControlType {
                PUSH_STREAM_CMD_TYPE(0),
                PUSH_STREAM_CMD_PAUSE(0),
                PUSH_STREAM_CMD_FAST(1),
                PUSH_STREAM_CMD_SLOW(2);

                private final int value;

                StreamControlType(int value) {
                        this.value = value;
                }

                public int getValue() {
                        return value;
                }
        }

        // push流控制暂停状态
        public enum StreamPushState {
                PUSH_REAL_TIME_STREAM_STATE(0x100),
                PUSH_PLAYBACK_STREAM_PLAY(0),
                PUSH_PLAYBACK_STREAM_PAUSE(1);

                private final int value;

                StreamPushState(int value) {
                        this.value = value;
                }

                public int getValue() {
                        return value;
                }
        }

        // 配置码流信息
        public enum ConfCmd {
                MIN_CONF_CMD(0),
                CONF_CMD_VIDEOHEAD(1),
                CONF_CMD_AUDIOVIDEO(2),
                MAX_CONF_CMD(2);

                private final int value;

                ConfCmd(int value) {
                        this.value = value;
                }

                public int getValue() {
                        return value;
                }
        }

        // 消息定义
        public enum MsgType {
                DEC_WCM_DEC_NONE(0),
                // 登录状态消息
                DEC_WCM_DEC_LOGON(1),
                // 连接NVS消息
                DEC_WCM_NVS_STARTVIEW(2),
                // 对讲消息
                DEC_WCM_DEC_TALK(3),
                // 升级解码器消息
                DEC_WCM_DEC_UPGRADE(4),
                // 升级LOGO消息
                DEC_WCM_DEC_UPGRADELOGO(5),
                // 升级控制协议消息
                DEC_WCM_DEC_UPGRADEP(6),
                // 命令层发生错误
                DEC_WCM_ERR_ORDER(7),
                // 断开NVS消息
                DEC_WCM_NVS_STOPVIEW(8),
                // 参数改变消息
                DEC_WCM_DEC_PARASET(9),
                // 升级WEB消息
                DEC_WCM_DEC_UPGRADEWEB(10),
                // 升级解码器进度消息
                DEC_WCM_DEC_UPGRADEPROCESS(11),
                // 音频状态消息
                DEC_WCM_DEC_AUDIOSTATUS(12),
                // 对讲失败消息
                DEC_WCM_DEC_TALK_FAILED(13),
                // 音频解码失败消息
                DEC_WCM_DEC_AUDIO_FAILED(14),
                // Push stream 结果
                DEC_WCM_DEC_PUSHSTREAM(20),
                // Push stream 错误
                DEC_WCM_ERR_PUSHSTREAM(21),
                // 数据通道发生网络异常
                DEC_WCM_ERR_DATANET(22),
                // 修改密码结果
                DEC_WCM_ERR_USERPASS(25),
                // 解码器各个通道的状态
                DEC_WCM_DETECT_CHANN_STATE(26),
                // 发送上报警情
                DEC_WCM_ALARM_NOTIFY(27),
                // 创建拼控输出通道消息
                DEC_WCM_PARASET_CREATEVVO(28),
                // 自动化调试
                DEC_WCM_AUTOTEST_INFO(29),
                // 日志查询
                DEC_WCM_QUERY_LOG_FINISH(30),
                // 连接NVS失败消息
                DEC_WCM_NVS_STARTVIEW_FAILED(31),
                // 搜索发现IPC
                DEC_WCM_SEARCH_IPC(32),
                // 搜索发现解码器
                DEC_WCM_SEARCH_NVD(33),
                DEC_WCM_CLUSTER_STATE(34),
                DEC_WCM_CLUSTER_CONTROL_CARD_STATE(35),
                DEC_WCM_CLUSTER_WORK_CARD_STATE(36),
                DEC_WCM_EXPORT_CONFIG_FINISH(37),
                DEC_WCM_ENCODE_CHANNEL_STATE(38),
                DEC_WCM_LOG_WRITE(39),
                DEC_WCM_EXCEPTION(40),
                DEC_WCM_DEC_USER_NUM(41),
                DEC_WCM_DEC_USER_INFO(42),
                DEC_WCM_DEC_LAST_ERROR(43),
                DEC_WCM_DEC_PICSNAP(44),
                DEC_WCM_DEC_GETPICFILENAME(45),

                DEC_WCM_DEC_SCREENCTLSET(46),
                DEC_WCM_DEC_REBOOTTRADE(47),
                DEC_WCM_DEC_GETUDISK_VIDEOLISTS(48),
                DEC_WCM_DEC_VIDEO_PLAYSET(49);

                private final int value;

                MsgType(int value) {
                        this.value = value;
                }

                public int getValue() {
                        return value;
                }
        }

        private IDecComRecvNotify mDecComRecvNotify = null;
        private ITDPostMessageNotify mTDPostMessageNotify = null;

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

        private static void OnNativeDecComRecvNotify(Object thiz_ref, long uId, byte[] pBuf) {
                System.out.println("OnNativeDecComRecvNotify");
                NVSDKClient thiz = (NVSDKClient) thiz_ref;
                if (thiz.mDecComRecvNotify != null) {
                        thiz.mDecComRecvNotify.OnDecComRecvNotify(uId, pBuf);
                }
        }

        private static void OnNativeTDPostMessageNotify(Object thiz_ref, long hwndContext, int iMsg, int iWParamLo,
                        int iWParamHi,
                        int iLParam) {
                System.out.println("OnNativeTDPostMessageNotify");
                NVSDKClient thiz = (NVSDKClient) thiz_ref;
                if (thiz.mTDPostMessageNotify != null) {
                        thiz.mTDPostMessageNotify.OnTDPostMessageNotify(hwndContext, iMsg, iWParamLo, iWParamHi,
                                        iLParam);
                }
        }

        public NVSDKClient() {
                nativePtr = nativeCreateInstance();
        }

        public void Dispose() {
                nativeDestroyInstance(nativePtr);
        }

        public int ClientStartup(int imessage) {
                return nativeClientStartup(nativePtr, imessage);
        }

        public int ClientCleanup() {
                return nativeClientCleanup(nativePtr);
        }

        public int ClientSetComRecvNotify(IDecComRecvNotify comRecvNotify) {
                mDecComRecvNotify = comRecvNotify;
                return 0;
        }

        public int ClientSetMsgCallback(ITDPostMessageNotify tDPostMsg) {
                mTDPostMessageNotify = tDPostMsg;
                return 0;
        }

        public int ClientSetMsgCallbackEx(ITDPostMessageNotify tDPostMsg) {
                return nativeClientSetMsgCallbackEx(nativePtr, tDPostMsg);
        }

        public int ClientLogin(String ip, int port, String user, String password) {
                return nativeClientLogin(nativePtr, ip, port, user, password);
        }

        public int ClientLogin(String ip, int port, String user, String password, long context) {
                return nativeClientLogin(nativePtr, ip, port, user, password, context);
        }

        public int ClientLogout(long uID) {
                return nativeClientLogout(nativePtr, uID);
        }

        public int ClientLogout(long uID, long context) {
                return nativeClientLogout(nativePtr, uID, context);
        }

        public int ClientGetDevConfig(long _ulID, int _iChannel, int _iPos, int _iCmd, byte[] _pvCmdBuf) {
                return nativeClientGetDevConfig(nativePtr, _ulID, _iChannel, _iPos, _iCmd, _pvCmdBuf);
        }

        public int ClientSetDevConfig(long _ulID, int _iChannel, int _iPos, int _iCmd, byte[] _pvCmdBuf) {
                return nativeClientSetDevConfig(nativePtr, _ulID, _iChannel, _iPos, _iCmd, _pvCmdBuf);
        }

        public int ClientGetStreamBufferState(long uPushID) {
                return nativeClientGetStreamBufferState(nativePtr, uPushID);
        }

        /// <summary>
        /// 推流前的准备工作,
        /// 返回值：>=0:成功(pushID)，<0:失败
        public int ClientStartPushStream(long uID, int iChannel, int iPos, int iEncodeMode,
                        int iVideoSize) {
                return nativeClientStartPushStream(nativePtr, uID, iChannel, iPos, iEncodeMode, iVideoSize);
        }

        public int ClientStartPushStream(long uID, int iChannel, int iPos, int iEncodeMode,
                        int iVideoSize, String sEncrytKey) {
                return nativeClientStartPushStreamEx(nativePtr, uID, iChannel, iPos, iEncodeMode, iVideoSize,
                                sEncrytKey);
        }

        public int ClientStreamControl(long uPushID, int iCmd, int cmdvalue) {
                return nativeClientStreamControl(nativePtr, uPushID, iCmd, cmdvalue);
        }

        public int ClientConfigStreamInfo(int iID, int iChannel, int iPos, int iCmd, byte[] pvCmdBuf) {
                return nativeClientConfigStreamInfo(nativePtr, iID, iChannel, iPos, iCmd, pvCmdBuf);
        }

        public int ClientStopPushStream(long uPushID) {
                return nativeClientStopPushStream(nativePtr, uPushID);
        }

        public int ClientStopPushStreamEx(long uPushID, boolean bShowLastPic) {
                return nativeClientStopPushStreamEx(nativePtr, uPushID, bShowLastPic);
        }

        public int ClientSendNonstandardRawFrame(long uPushID, byte[] cStreambuf) {
                return nativeClientSendNonstandardRawFrame(nativePtr, uPushID, cStreambuf);
        }

        public int ClientSendRawFrame(long uPushID, byte[] pStreamBuf) {
                return nativeClientSendRawFrame(nativePtr, uPushID, pStreamBuf);
        }

        public int ClientStartView(int iId, int iChannel, int iPos, TNVSItem nvs_item) {
                return nativeClientStartView(nativePtr, iId, iChannel, iPos, nvs_item);
        }

        public int ClientStartViewEx(int iId, int iChannel, int iPos, TNVSItemEx itemEx) {
                return nativeClientStartViewEx(nativePtr, iId, iChannel, iPos, itemEx);
        }

        public int ClientStopView(int iId, int iChannel, int iPos,
                        boolean bShowLastPic) {
                return nativeClientStopView(nativePtr, iId, iChannel, iPos, bShowLastPic);
        }

        public int ClientStartLoop(int iId, int iChannel, int iPos) {
                return nativeClientStartLoop(nativePtr, iId, iChannel, iPos);
        }

        public int ClientStopLoop(int iId, int iChannel, int iPos) {
                return nativeClientStopLoop(nativePtr, iId, iChannel, iPos);
        }

        public int ClientGetLoopItemCount(int iId, int iChannel, int iPos) {
                return nativeClientGetLoopItemCount(nativePtr, iId, iChannel, iPos);
        }

        public TNVSItem ClientGetLoopItem(int iId, int iIndex, int iChannel, int iPos) {
                return nativeClientGetLoopItem(nativePtr, iId, iIndex, iChannel, iPos);
        }

        public TNVSItemEx ClientGetLoopItemEx(int iId, int iIndex, int iChannel, int iPos) {
                return nativeClientGetLoopItemEx(nativePtr, iId, iIndex, iChannel, iPos);
        }

        /**
         * 获取解码器循环播放状态
         * 
         * @param iId
         * @param iChannel
         * @param iPos
         * @return >0:正在播放 不可删除
         */
        public int ClientGetLoopStatus(int iId, int iChannel, int iPos) {
                return nativeClientGetLoopStatus(nativePtr, iId, iChannel, iPos);
        }

        public int ClientDelLoopItem(int iId, int iNVSIndex, int iChannel, int iPos) {
                return nativeClientDelLoopItem(nativePtr, iId, iNVSIndex, iChannel, iPos);
        }

        private native long nativeCreateInstance();

        private native void nativeDestroyInstance(long ptr);

        private native int nativeClientStartup(long ptr, int imessage);

        private native int nativeClientCleanup(long ptr);

        private native int nativeClientSetComRecvNotify(long ptr, IDecComRecvNotify comRecvNotify);

        private native int nativeClientSetMsgCallback(long ptr, ITDPostMessageNotify tDPostMsg);

        private native int nativeClientSetMsgCallbackEx(long ptr, ITDPostMessageNotify tDPostMsg);

        private native int nativeClientLogin(long ptr, String ip, int port, String user,
                        String password);

        private native int nativeClientLogin(long ptr, String ip, int port, String user,
                        String password, long context);

        private native int nativeClientLogout(long ptr, long uID);

        private native int nativeClientLogout(long ptr, long uID, long context);

        private native int nativeClientStartPushStream(long ptr, long uID, int iChannel, int iPos,
                        int iEncodeMode, int iVideoSize);

        private native int nativeClientStartPushStreamEx(long ptr, long uID, int iChannel, int iPos,
                        int iEncodeMode, int iVideoSize, String sEncrytKey);

        private native int nativeClientStartPushStream_V1(long ptr, long uID, int iChannel,
                        int iPos, String sEncrytKey, String sFileHeader, int iSize);

        private native int nativeClientSendStream(long ptr, long uPushID, byte[] streamBuf,
                        int iLen);

        private native int nativeClientStopPushStream(long ptr, long uPushID);

        private native int nativeClientStopPushStreamEx(long ptr, long uPushID,
                        boolean bShowLastPic);

        private native int nativeClientGetStreamBufferState(long ptr, long uPushID);

        private native int nativeClientStreamControl(long ptr, long uPushID, int iCmd,
                        int cmdvalue);

        private native int nativeClientSendRawFrame(long ptr, long uPushID, byte[] pStreamBuf);

        public TDecParam ClientGetDecoderPara(int iId) {
                return nativeClientGetDecoderPara(nativePtr, iId);
        }

        private native TDecParam nativeClientGetDecoderPara(long ptr, int iId);

        private native int nativeClientSetDDNS(long ptr, int iId, String svrIP, String userName,
                        String passWord, int port);

        private native int nativeClientSetAlarmOut(long ptr, int iId, int ialarmOUt,
                        int ialarmMode);

        private native int nativeClientSetTVInfo(long ptr, int iId, int iIsPAL, int iLanguage);

        private native int nativeClientSetChannelMode(long ptr, int iId, int iChannel, int iMode);

        private native int nativeClientSetLogo(long ptr, int iId, TLogoParam pLogoParam);

        private TLogoParam tdLogoParam = new TLogoParam();

        private native int nativeClientGetLog(long ptr, int iId);

        private native int nativeClientGetLoopItemCount(long ptr, int iId, int iChannel, int iPos);

        private native TNVSItem nativeClientGetLoopItem(long ptr, int iId, int iIndex,
                        int iChannel, int iPos);

        private native TNVSItemEx nativeClientGetLoopItemEx(long ptr, int iId, int iIndex, int iChannel, int iPos);

        private native int nativeClientSetLoopItem_V1(long ptr, int iId, int iChannel, int iPos,
                        int iIndex, int iServerType, TServerCommonInfo serverInfo);

        private native int nativeClientDelLoopItem(long ptr, int iId, int iNVSIndex, int iChannel, int iPos);

        private TServerCommonInfo tServerCommonInfo = new TServerCommonInfo();

        private native int nativeClientStartLoop(long ptr, int iId, int iChannel, int iPos);

        private native int nativeClientStopLoop(long ptr, int iId, int iChannel, int iPos);

        private native int nativeClientGetLoopStatus(long ptr, int iId, int iChannel, int iPos);

        private native int nativeClientStopView(long ptr, int iId, int iChannel, int iPos,
                        boolean bShowLastPic);

        // TODO(hhool): make sure args with nativeClientStopView_V1 are correct.
        // nativeClientStopView_V1(int _iID, void* _pvPara , int _iBufSize);
        private native int nativeClientStopView_V1(long ptr, int iId, int iChannel, int iPos,
                        boolean bShowLastPic);

        private native int nativeClientStartView(long ptr, int iId,
                        int iChannel /* =0 */, int iPos /* =0 */, TNVSItem nvs_item);

        private native int nativeClientStartViewEx(long ptr, int iId,
                        int iChannel /* =0 */, int iPos /* =0 */ , TNVSItemEx nvs_item_ex);

        private native int nativeClientStartView_V1(long ptr, int iId, int iChannel, int iPos,
                        int iServerType, TServerCommonInfo puItem);

        private native int nativeClientGetViewItem(long ptr, int iId, TNVSItem pPara,
                        int iChannel /* =0 */, int iPos /* =0 */);

        private native int nativeClientGetViewItemEx(long ptr, int iId, TNVSItemEx pPara,
                        int iChannel /* =0 */, int iPos /* =0 */);

        private native int nativeClientGetViewItem_V1(long ptr, int iId, int iChannel, int iPos,
                        int piServerType, TServerCommonInfo puItem);

        private native int nativeClientSendKey(long ptr, int iId, int iKeyCode);

        private native int nativeClientPTZCtrl(long ptr, int iId, int iCtrlCode, int iVal,
                        int iChannel /* =0 */, int iPos /* =0 */);

        private native int nativeClient485Send(long ptr, int iId, byte[] pData, int iSize,
                        int iChannel /* =0 */, int iPos /* =0 */);

        private native int nativeClientGetPTZprotocols(long ptr, int iId, TDecProtocol pProtocol);

        private TDecProtocol tDecProtocol = new TDecProtocol();

        private native int nativeClientSoundCtrl(long ptr, int iId, int bOn, int iChannel /* =0 */,
                        int iPos /* =0 */);

        private native int nativeClientTalkServer(long ptr, int iId, int bOn, int iChannel /* =0 */,
                        int iPos /* =0 */);

        private native int nativeClientGetAudioStatus(long ptr, int iId, int iChannel /* =0 */,
                        int iPos /* =0 */);

        private native int nativeClientGetTalkStatus(long ptr, int iId, int iChannel /* =0 */,
                        int iPos /* =0 */);

        private native int nativeClientRebootDecoder(long ptr, int iId);

        private native int nativeClientResetDefault(long ptr, int iId);

        private native int nativeClientUpgrade(long ptr, int iId, String pcFileName);

        private native int nativeClientUpgradeLogo(long ptr, int iId, String pcFileName);

        private native int nativeClientUpgradeProtocol(long ptr, int iId, String pcFilePath,
                        String pcFileName);

        private native int nativeClientDeleteProtocol(long ptr, int iId, String pcProtocol);

        private native int nativeClientGetVersion(long ptr, int iId, String pcVer);

        private native int nativeClientGetSDKVersion(long ptr, TNVDSdkVersion pVer);

        private TNVDSdkVersion tNVDSdkVersion = new TNVDSdkVersion();

        private native int nativeClientUpgradeWeb(long ptr, int iId, String pcFileName);

        private native int nativeClientGetCapability(long ptr, int iId, String pcCap);

        private native int nativeClientSetVGASize(long ptr, int iId, int iChannel, int iSize);

        // 发送整帧原始NV裸流，定制接口
        private native int nativeClientSendNonstandardRawFrame(long ptr, long uPushID,
                        byte[] cStreambuf);

        private native int nativeClientSetVolume(long ptr, int iId, int iVolume);

        private native int nativeClientGetVolume(long ptr, int iId);

        private int iVolume = 0;

        private native int nativeClientSetCommonEnable(long ptr, int iId, int iEnableID,
                        int iChannelNo, int iEnableValue);

        /*
         * _iEnableID: 0x13001:断网保留最后一帧; _iEnableValue：0--->不使能;1--->使能。 0x13002:预览偏好设置;
         * _iEnableValue：0--->低延时;1--->高流畅。
         */
        private native int nativeClientGetCommonEnable(long ptr, int iId, int iEnableID);

        private boolean piEnableLastFrame = false;
        private boolean piEnablePreference = false;

        private native int nativeClientSetCommonEnableEx(long ptr, int iId, int iEnableID,
                        int iChannelNo, int iEnableValue);

        // 扩展接口，增加push流保留最后一帧需求
        // 扩展接口，增加音频采样率
        private native int nativeClientConfigStreamInfo(long ptr, int iID, int iChannel,
                        int iPos, int iCmd, byte[] pvCmdBuf);

        /***************************************************************
         * Function ： nativeClientSetDevConfig Description ：
         * 设置解码器的某个参数，根据_iCmd不同，执行不同的操作
         * Prameter(in) ： _ulID：登录ID _iChannel：通道号 _iPos: 画面号 _iCmd：操作码
         * _iBuffSize：传入缓冲区的大小
         * Prameter(in, out)： _pvCmdBuf ： 传入缓冲区指针 return ： 0：成功 -1：缓冲区不足 other：失败 others
         * ：
         * 2013-08-14
         ***************************************************************/
        private native int nativeClientSetDevConfig(long ptr, long _ulID, int _iChannel, int _iPos,
                        int _iCmd, byte[] _pvCmdBuf);

        /***************************************************************
         * Function ： nativeClientGetDevConfig Description ：
         * 获取解码器的某个参数，根据_iCmd不同，执行不同的操作
         * Prameter(in) ： _ulID：登录ID _iChannel：通道号 _iPos: 画面号 _iCmd：操作码
         * _iBuffSize：传入缓冲区的大小
         * Prameter(in, out)： _pvCmdBuf ： 传入缓冲区指针 return ： 0：成功 -1：缓冲区不足 other：失败 others
         * ：
         * 2013-08-14
         ***************************************************************/
        private native int nativeClientGetDevConfig(long ptr, long _ulID, int _iChannel, int _iPos,
                        int _iCmd, byte[] _pvCmdBuf);

        /***************************************************************
         * Function ： nativeClientSetAutoTest Description ： 自动化调试设置接口 Prameter(in) ：
         * _ulID：登录ID
         * _iCmd：操作码 _iBuffSize：传入缓冲区的大小 _pvCmdBuf： 传入缓冲区指针 return ： 0：成功 -1：缓冲区不足
         * other：失败 others ：
         * 2014-06-11
         ***************************************************************/
        private native int nativeClientSetAutoTest(long ptr, long _ulID, int _iCmd,
                        byte[] _pvCmdBuf, int _iBuffSize);

        private native int nativeClientSetSelectPicture(long ptr, long _lID, int _iChannel,
                        int _iPicture);

        private native int nativeClientSetNotify(long ptr, IDecNotify _pNotify);

        private native int nativeClientSetNetLog(long ptr, long _lID, int _iEnable, int _iLogType,
                        int _iLogSize);

        private native int nativeClientNetLogGetLogfile(long ptr, long _ulID, int _iLogIndex,
                        TDecLogData _pLogInfo, int _iSize);

        private native int nativeClientNetLogGetLogCount(long ptr, long _ulID, int _iTotalCount,
                        int _iCurrentCount);

        private native int nativeClientUserChangePassword(long ptr, long _ulID, String _cUser,
                        String _cOldPassword, String _cNewPassword);

        private native int nativeSetRegServer(long ptr, long _lID, String _pcRegSvrIP,
                        int _iRegSvrPort, int _iEnable);

        private native int nativeSetRegDevice(long ptr, long _lID, String _pcPUID,
                        String _pcPUName);

        private native int nativeSetRegChannel(long ptr, long _lID, int _iChannelNum,
                        String _pcPUID);

        private native int nativeSetDZInfo(long ptr, long _lID, TDZInfoParam dzInfoParam);

        private native int nativeSetChannelSipConfig(long ptr, long _lID, int _iCmd,
                        TSetSipVideoChannel sipVideoChannel);

        private native int nativeSetPlatformStart(long ptr, long _lID, TPlatforminfo platformInfo);

        private native int nativeGetPlatformInfo(long ptr, long _lID);

        private TPlatforminfo platformInfo = new TPlatforminfo();

        private native int nativeGetRunningPlatformInfo(long ptr, long _lID);

        private TPlatforminfo platformInfo_running = new TPlatforminfo();

        private native int nativeSetPlatformConfig(long ptr, long _lID, int _iCmd,
                        byte[] _lpInBuffer, int _iInBufferSize);

        private native int nativeClientGetClusterConfig(long ptr, long _lID, int _iCmd,
                        byte[] _lpOutBuffer);

        private native int nativeClientSendCommand(long ptr, long _iID, int _iChannel, int _iPos,
                        int _iCommand, byte[] _pBuffer);

        private native int nativeClientRecvCommand(long ptr, long _iID, int _iChannel, int _iPos,
                        int _iCommand, byte[] _pBuffer);

        private native int nativeClientGetLogonState(long ptr, long _iID);

        private native int nativeClientSetSDKWorkMode(long ptr, int _iWorkMode);

        private native int nativeClientSetExternDevLogonInfo(long ptr, int _uiAllowDevType);

        /// just for native struct test
        public void TestSDK() {
                TNVSItemEx obj = nativeTNVSItemExFromJNI(this.nativePtr);
                System.out.println("TNVSItemEx.cEncyptPWD: " + obj.cEncyptPWD);

                TNVSItem obj2 = nativeTNVSItemFromJNI(this.nativePtr);
                System.out.println("TNVSItem.rtspUrl: " + obj2.rtspUrl);

                TCom485 obj3 = nativeTCom485FromJNI(this.nativePtr);
                System.out.println("TCom485.type: " + obj3.type);

                TDecParam obj4 = nativeTDecParamFromJNI(this.nativePtr);
                System.out.println("TDecParam.ip: " + obj4.ip);
        }

        private native TNVSItemEx nativeTNVSItemExFromJNI(long ptr);

        private native TNVSItem nativeTNVSItemFromJNI(long ptr);

        private native TCom485 nativeTCom485FromJNI(long ptr);

        private native TDecParam nativeTDecParamFromJNI(long ptr);
        /// just for native struct test end

}
