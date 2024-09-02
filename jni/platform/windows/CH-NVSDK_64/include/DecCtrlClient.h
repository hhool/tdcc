#ifndef __DECCTRLCLIENT_H__
#define __DECCTRLCLIENT_H__

#include "DecCtrlClientTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
    @brief ��ʼ�� 
    @param nPort �˿ں�
    @retval TRUE �ɹ� 
    @retval FALSE ʧ��
 */

X_API int STDCALL 
DEC_ClientStartup(unsigned int _uiMessage, void *_hWnd);

/**
    @brief ����ʼ��
    @param nPort �˿ں�
    @retval TRUE �ɹ� 
    @retval FALSE ʧ��
 */
X_API int STDCALL
DEC_ClientCleanup();

X_API int STDCALL
DEC_ClientLogon(char* _cIP, char* _cUserName, char* _cPassword, unsigned short _nPort/* = 3000*/);

X_API int STDCALL 
DEC_ClientLogonEx(char* _cIP, char* _cUserName, char* _cPassword, unsigned short _nPort/* = 3000*/, void* _pvUserData/* = NULL*/);

X_API int STDCALL
DEC_ClientLogout(long _ulID);

X_API int STDCALL
DEC_ClientStartPushStream(long _ulID, int _iChannel/* = 0*/, int _iPos/* = 0*/, int _iEncodeMode/* = 0*/, int _iVideoSize/* = 4*/);

X_API int STDCALL
DEC_ClientStartPushStreamEx(long _ulID, int _iChannel, int _iPos, int _iEncodeMode, int _iVideoSize, char* _pcEncryptKey);

X_API int STDCALL
DEC_ClientStartPushStream_V1(long _ulID, int _iChannel, int _iPos, START_PUSH_PARAM *_pStartPushParam);

X_API int STDCALL
DEC_ClientSendStream(long _ulPushID, int _iLen, char* _cStreambuf);

X_API int STDCALL
DEC_ClientStopPushStream(long _ulPushID);

X_API int STDCALL
DEC_ClientStopPushStreamEx(long _ulPushID, int _iShowLastPic/*=0*/);

X_API int STDCALL
DEC_ClientGetStreamBufferState(long _ulPushID, int * _piStreamBufferState);

X_API int STDCALL
DEC_ClientStreamControl(long  _ulPushID, int  _iCmd, void* _pvCmdBuf, int _iCmdLen);
/** ������	_iPushID			DEC_ClientStartPushStream�ķ���ֵ
			_iCmd		    	��ʶ���������Ĳ���ָ�0����ͣ��1����ţ�2������
			*_pvCmdBuf			�洢������ָ��ֵ��Ŀǰ��֧���������ֲ�����
									<1>��ָͣ�1����ͣ��     0���ָ�
                                    <2>���ָ�0������ 1��������  2���ı���  3���˱���  4��ʮ������
                                    <3>����ָ�0������ 1��������  2���ı���  3���˱��� 4��ʮ������
			_iCmdLen			ָ��ֵ�洢���ĳ���
 */

//������֡ԭʼ��������
X_API int STDCALL 
DEC_ClientSendRawFrame(long _ulPushID, int _iLen, char* _cStreambuf);

X_API int STDCALL
DEC_ClientGetDecoderPara(int _iID,TDECPARAM *_pPara);

X_API int STDCALL 
DEC_ClientSetIP(int _iID, char *_cNewIP, char *_cMask, char *_cGeteway, char *_cDNS);

X_API int STDCALL 
DEC_ClientSetDDNS(int _iID, char *_cSvrIP, char *_cUserName, char *_cPassword, int _iPort);

X_API int STDCALL  
DEC_ClientSetCom(int _iID, int _iType, int _iAddress, int _iBaudrate, int _iDatabit, int _iStopbit, int _iCheckbit, int _iFlowCtrl, int _iCom/* = 2*/);

X_API int STDCALL  
DEC_ClientSetAlarmOut(int _iID, int _iAlarmOut, int _iAlarmMode);

X_API int STDCALL  
DEC_ClientSetTVInfo(int _iID, int _iIsPAL, int _iLanguage);

X_API int STDCALL  
DEC_ClientSetChannelMode(int _iID, int _iChannel, int _iMode);

X_API int STDCALL  
DEC_ClientSetLogo(int _iID, TLOGOPARAM *pLogoPara);

X_API int STDCALL  
DEC_ClientGetLogo(int _iID, TLOGOPARAM *pLogoPara);

X_API int STDCALL  
DEC_ClientGetLoopItemCount(int _iID, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetLoopItem(int _iID, int _iIndex, TNVSITEM* _pPara, int _iChannel/* = 0*/,int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetLoopItemEx(int _iID, int _iIndex, TNVSITEMEX* _pPara, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetLoopItem_V1(int _iID, int _iChannel, int _iPos, int _iIndex, int* _piServerType, ServerItem* _puItem);

X_API int STDCALL 
DEC_ClientDelLoopItem(int _iID, int _iIndex, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientSetLoopItem(int _iID, int _iIndex, TNVSITEM *_pPara, int _iChannel/* = 0*/,int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientSetLoopItemEx(int _iID, int _iIndex, TNVSITEMEX *_pPara, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientSetLoopItem_V1(int _iID, int _iChannel, int _iPos, int _iIndex, int _iServerType, ServerItem* _puItem);

X_API int STDCALL  
DEC_ClientStartLoop(int _iID, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientStopLoop(int _iID, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetLoopStatus(int _iID, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientStopView(int _iID, int _iChannel/* = 0*/, int _iPos/* = 0*/, int _iShowLastPic/* = 0*/);

X_API int STDCALL
DEC_ClientStopView_V1(int _iID,  void* _pvPara , int _iBufSize);

X_API int STDCALL  
DEC_ClientStartView(int _iID, TNVSITEM *_pPara, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientStartViewEx(int _iID, TNVSITEMEX *_pPara, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientStartView_V1(int _iID, int _iChannel, int _iPos, int _iServerType, ServerItem* _puItem);

X_API int STDCALL  
DEC_ClientGetViewItem(int _iID, TNVSITEM *_pPara, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetViewItemEx(int _iID, TNVSITEMEX *_pPara, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetViewItem_V1(int _iID, int _iChannel, int _iPos, int* _piServerType, ServerItem* _puItem);

X_API int STDCALL  
DEC_ClientSendKeyCode(int _iID,int _iKeyCode);

X_API int STDCALL  
DEC_ClientPTZCtrl(int _iID, int _iCtrlCode, int _iVal, int _iChannel/* = 0*/, int _Pos/* = 0*/);

X_API int STDCALL  
DEC_Client485Send(int _iID, const unsigned char *pData, int _iSize, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetPTZprotocols(int _iID, TDECPROTOCOL *_pProtocol);

X_API int STDCALL  
DEC_ClientSoundCtrl(int _iID, int _bOn, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientTalkServer(int _iID, int _bOn, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetAudioStatus(int _iID, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientGetTalkStatus(int _iID, int _iChannel/* = 0*/, int _iPos/* = 0*/);

X_API int STDCALL  
DEC_ClientRebootDecoder(int _iID);

X_API int STDCALL  
DEC_ClientResetDefault(int _iID);

X_API int STDCALL  
DEC_ClientUpgrade(int _iID, char *_pcFileName);

X_API int STDCALL  
DEC_ClientUpgradeLogo(int _iID, char *_pcFileName);

X_API int STDCALL  
DEC_ClientUpgradeProtocol(int _iID, char *_pcFilePath, char *_pcFileName);

X_API int STDCALL  
DEC_ClientDeleteProtocol(int _lID, char *_pcProtocol);

X_API int STDCALL  
DEC_ClientGetVersion(int _iID, char *_pcVer);

X_API int STDCALL  
DEC_ClientGetSDKVersion(NVDSDK_VERSION *_pVer);

X_API int STDCALL  
DEC_ClientSetComRecvNotify(DEC_COMRECV_NOTIFY _comRecvNotify);

X_API int STDCALL  
DEC_ClientSetMsgCallback(pTDPostMessage _TDPostMsg);

X_API int STDCALL  
DEC_ClientUpgradeWeb(int _iID, char *_pcFileName);

X_API int STDCALL  
DEC_ClientGetCapability(int _iID, char *_pcCap);

X_API int STDCALL  
DEC_ClientSetVGASize(int _iID, int _iChannel, int _iSize);

//ע����Ϣ�ص���չ
X_API int STDCALL 
DEC_ClientSetMsgCallbackEx(pTDPostMessageEx _TDPostMsg);
 
//������֡ԭʼNV���������ƽӿ�
X_API int STDCALL 
DEC_ClientSendNonstandardRawFrame(long _ulPushID, int _iLen, char* _cStreambuf);

X_API int STDCALL 
DEC_SetVolume(int _iID, int _iVolume);

X_API int STDCALL 
DEC_GetVolume(int _iID, int *_piVolume);

X_API int STDCALL 
DEC_ClientSetCommonEnable(int _iID, int _iEnableID, int _iChannelNo, int _iEnableValue);

/*_iEnableID:
0x13001:�����������һ֡; _iEnableValue��0--->��ʹ��;1--->ʹ�ܡ�
0x13002:Ԥ��ƫ������;	  _iEnableValue��0--->����ʱ;1--->��������*/
X_API int STDCALL 
DEC_ClientGetCommonEnable(int _iID, int _iEnableID, int *_piEnableLastFrame, int *_piEnablePreference);

X_API int STDCALL 
DEC_ClientGetCommonEnableEx(int _iID, int _iEnableID, int _iChannelNo, int* _piEnableValue);

//��չ�ӿڣ�����push���������һ֡����
//��չ�ӿڣ�������Ƶ������
X_API int STDCALL 
DEC_ClientConfigStreamInfo(int _iID, int _iChannel, int _iPos, int _iCmd, void* _pvCmdBuf, int _iBuffSize);

 /***************************************************************
 Function     ��		DEC_ClientSetDevConfig
 Description  ��		���ý�������ĳ������������_iCmd��ͬ��ִ�в�ͬ�Ĳ���
 Prameter(in) ��		_ulID����¼ID
 				_iChannel��ͨ����
 				_iPos: �����
 				_iCmd��������
 				_iBuffSize�����뻺�����Ĵ�С
 Prameter(in, out)��	_pvCmdBuf �� ���뻺����ָ��            
 return       ��		0���ɹ�
                 -1������������
                 other��ʧ��
 others       ��		2013-08-14 
 ***************************************************************/
X_API int STDCALL 
DEC_ClientSetDevConfig(long _ulID, int _iChannel, int _iPos, int _iCmd, void* _pvCmdBuf, int _iBuffSize);
 
/***************************************************************
Function     ��		DEC_ClientGetDevConfig
Description  ��		��ȡ��������ĳ������������_iCmd��ͬ��ִ�в�ͬ�Ĳ���
Prameter(in) ��		_ulID����¼ID
				_iChannel��ͨ����
				_iPos: �����
				_iCmd��������
				_iBuffSize�����뻺�����Ĵ�С
Prameter(in, out)��	_pvCmdBuf �� ���뻺����ָ��            
return       ��		0���ɹ�
                -1������������
                other��ʧ��
others       ��		2013-08-14 
***************************************************************/
X_API int STDCALL 
DEC_ClientGetDevConfig(long _ulID, int _iChannel, int _iPos, int _iCmd, void* _pvCmdBuf, int _iBuffSize);

/***************************************************************
Function     ��		DEC_ClientSetAutoTest
Description  ��		�Զ����������ýӿ�
Prameter(in) ��		_ulID����¼ID
				_iCmd��������
				_iBuffSize�����뻺�����Ĵ�С
				_pvCmdBuf�� ���뻺����ָ��            
return       ��		0���ɹ�
                -1������������
                other��ʧ��
others       ��		2014-06-11 
***************************************************************/
X_API int STDCALL 
DEC_ClientSetAutoTest(long _ulID, int _iCmd, void* _pvCmdBuf, int _iBuffSize);

X_API int STDCALL 
DEC_SetSelectPicture(long _lID, int _iChannel, int _iPicture);

X_API int STDCALL 
DEC_ClientSetNotify(DecNotifyFun* _pNotify);


X_API int STDCALL 
DEC_ClientNetLogQuery(long _ulID, PDecLogQuery _logQuery, int _iSize);

X_API int STDCALL 
DEC_ClientNetLogGetLogfile(long _ulID, int _iLogIndex, PDecLogData _pLogInfo, int _iSize);

X_API int STDCALL 
DEC_ClientNetLogGetLogCount(long _ulID, int *_iTotalCount, int *_iCurrentCount); 

X_API int STDCALL 
DEC_ClientUserChangePassword(long _ulID, char *_cUser, char *_cOldPassword, char *_cNewPassword);

X_API int STDCALL
DEC_SetRegServer(long _lID, char* _pcRegSvrIP, int _iRegSvrPort, int _iEnable);

X_API int STDCALL
DEC_SetRegDevice(long _lID, char* _pcPUID, char* _pcPUName);

X_API int STDCALL
DEC_SetRegChannel(long _lID, int _iChannelNum, char* _pcPUID);

X_API int STDCALL
DEC_SetDZInfo(long _lID, DZ_INFO_PARAM* _pDzInfoParam);

X_API int STDCALL
DEC_SetChannelSipConfig(long _lID, int _iCmd, TSetSipVideoChannel* _lpBuf);

X_API int STDCALL
DEC_SetPlatformStart(long _lID, TPLATFORMINFO *_platformInfo);

X_API int STDCALL
DEC_GetPlatformInfo(long _lID, TPLATFORMINFO *_platformInfo);

X_API int STDCALL
DEC_GetRunningPlatformInfo(long _lID, TPLATFORMINFO *_platformInfo);

X_API int STDCALL
DEC_ClientSetClusterConfig(long _iID, int _iCommand, void *_lpInBuffer, int _iInBufferSize);

X_API int STDCALL
DEC_ClientGetClusterConfig (long _iID, int _iCommand, void *_lpOutBuffer, int _iOutBufferSize, int* _iResultSize);

X_API int STDCALL
DEC_ClientSendCommand(long _iID, int _iChannel, int _iPos, int _iCommand, void* _pBuffer, int _iBufferSize);

X_API int STDCALL
DEC_ClientRecvCommand(long _iID, int _iChannel, int _iPos, int _iCommand, void* _pBuffer, int _iBufferSize);

X_API int STDCALL
DEC_ClientGetLogonState(long _iID);

X_API int STDCALL 
DEC_ClientSetSDKWorkMode(int _iWorkMode);

X_API int STDCALL 
DEC_ClientSetExternDevLogonInfo(unsigned int _uiAllowDevType);

#ifdef __cplusplus
};
#endif

#endif


