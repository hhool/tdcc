#ifndef _CLS_NVDSDKHELPER_H
#define _CLS_NVDSDKHELPER_H

#include "DecCtrlClientTypes.h"
#include <dlfcn.h>

typedef int (*pDEC_ClientStartup)(unsigned int _uiMessage, void *_hWnd);
typedef int (*pDEC_ClientCleanup)(void);

typedef int (*pDEC_ClientLogon) (char * _cIP, char * _cUserName, char * _cPassword, unsigned short _nPort);
typedef int (*pDEC_ClientLogout)(int _iID);

typedef int (*pDEC_ClientGetDecoderPara)(int _iID, TDECPARAM *_pPara);

typedef int (*pDEC_ClientSetIP)         (int _iID, char* _cNewIP, char* _cMask, char* _cGateway, char* _cDNS);
typedef int (*pDEC_ClientSetDDNS)       (int _iID, char* _cSvrIP, char* _cUserName, char* _cPassword, int _iPort);
typedef int (*pDEC_ClientSetCom)        (int _iID, int _iType, int _iAddress, int _iBaudrate, int _iDatabit, int _iStopbit, int _iCheckbit, int _iFlowCtrl, int _iCom);
typedef int (*pDEC_ClientSetAlarmOut)   (int _iID, int _iAlarmOut, int _iAlarmMode);
typedef int (*pDEC_ClientSetTVInfo)     (int _iID, int _iIsPAL, int _iLanguage);
typedef int (*pDEC_ClientSetChannelMode)(int _iID, int _iChannel, int _iMode);

typedef int (*pDEC_ClientSetLogo)(int _iID, TLOGOPARAM* _logoParam);
typedef int (*pDEC_ClientGetLogo)(int _iID, TLOGOPARAM* _logoParam);

typedef int (*pDEC_ClientGetLoopItemCount)(int _iID, int _iChannel, int _iPos);
typedef int (*pDEC_ClientGetLoopItem)     (int _iID, int _iIndex, TNVSITEM *_pPara, int _iChannel, int _iPos);
typedef int (*pDEC_ClientSetLoopItem)     (int _iID, int _iIndex, TNVSITEM *_pPara, int _iChannel, int _iPos);
typedef int (*pDEC_ClientDelLoopItem)     (int _iID, int _iIndex, int _iChannel, int _iPos);
typedef int (*pDEC_ClientStartLoop)       (int _iID, int _iChanne, int _iPos);
typedef int (*pDEC_ClientStopLoop)        (int _iID, int _iChannel, int _iPos);
typedef int (*pDEC_ClientGetLoopStatus)   (int _iID, int _iChannel, int _iPos);

typedef int (*pDEC_ClientStartView)    (int _iID, TNVSITEM *_pPara, int _iChannel, int _iPos);
typedef int (*pDEC_ClientStopView)     (int _iID, int _iChannel, int _iPos, int _iShowLastPic);
typedef int (*pDEC_ClientGetViewItem)  (int _iID, TNVSITEM *_pPara, int _iChannel, int _iPos);

typedef int (*pDEC_ClientSendKeyCode)     (int _iID,int _keycode);
typedef int (*pDEC_ClientPTZCtrl)         (int _iID,int _iCtrlCode,int _iVal, int _iChannel, int _iPos);
typedef int (*pDEC_Client485Send)         (int _iID,const unsigned char *_pData, int _iSize, int _iChannel, int _iPos);
typedef int (*pDEC_ClientGetPTZprotocols) (int _iID, TDECPROTOCOL * _pProtocol);

typedef int (*pDEC_ClientSoundCtrl)      (int _iID, int _bOn, int _iChannel, int _iPos);
typedef int (*pDEC_ClientTalkServer)     (int _iID, int _bOn, int _iChannel, int _iPos);
typedef int (*pDEC_ClientGetAudioStatus) (int _iID, int _iChannel, int _iPos);
typedef int (*pDEC_ClientGetTalkStatus)  (int _iID, int _iChannel, int _iPos);

typedef int (*pDEC_ClientRebootDecoder)(int _iID);
typedef int (*pDEC_ClientResetDefault) (int _iID);

typedef int (*pDEC_ClientUpgrade)        (int _iID, char *_cFileName);
typedef int (*pDEC_ClientUpgradeLogo)    (int _iID, char *_cFileName);
typedef int (*pDEC_ClientUpgradeProtocol)(int _iID, char *_cFilePath, char *_cFileName);
typedef int (*pDEC_ClientDeleteProtocol) (int _iID, char *_cProtocol);
typedef int (*pDEC_ClientUpgradeWeb)(int _iID, char *_cFileName);

typedef int (*pDEC_ClientGetVersion)   (int _iID, char* _cVer);
typedef int (*pDEC_ClientGetSDKVersion)(NVDSDK_VERSION *_ver);

typedef int (*pDEC_ClientSetComRecvNotify)(DEC_COMRECV_NOTIFY _comRecvNotify);
//注册消息回调函数
typedef	int (*pDEC_ClientSetMsgCallback)(pTDPostMessage _TDPostMsg);

typedef int (*pDEC_ClientGetCapability)(int _iID,char* _cCap);  //add for guo wei 2010-1-8

typedef int (*pDEC_ClientStartPushStream)(int _iID, int _iChannel, int _iPos, int _iEncodeMode, int _iVideoSize);
typedef int (*pDEC_ClientSendStream)(int _ulPushID, int _iLen, char* _cStreambuf);
typedef int (*pDEC_ClientStopPushStream)(int _ulPushID);
typedef int (*pDEC_ClientSetVGASize)(int _iID, int _iChannel, int _iSize);

typedef int (*pDEC_ClientStartViewEx)(int _iID, TNVSITEMEX *_pPara, int _iChannel, int _iPos);
typedef int (*pDEC_ClientGetViewItemEx)(int _iID, TNVSITEMEX *_pPara, int _iChannel, int _iPos);
	//add by hyq 20111201
typedef int (*pDEC_ClientSetLoopItemEx)(int _iID, int _iIndex, TNVSITEMEX *_pPara, int _iChannel, int _iPos);
typedef int (*pDEC_ClientGetLoopItemEx)(int _iID, int _iIndex, TNVSITEMEX *_pPara, int _iChannel, int _iPos);

/*********************************20121101-->add by wangshaobo****************************************************/
//typedef int (*pfDEC_ClientPushStreamToDecoder)(int _iID, unsigned char* _pucStreamData, int _iSize, int _iFlagVideo,int * _piState);
typedef int (*pfDEC_ClientGetStreamBufferState)(int _ulPushID, int * _piStreamBufferState);
typedef int (*pfDEC_ClientStreamControl)(int  _ulPushID, int  _iCmd, void* _pvCmdBuf, int _iCmdLen);
typedef int (*pfDEC_ClientLogonEx)(char* _cIP, char* _cUserName, char* _cPassword, unsigned short _nPort, void* _pvUserData);
typedef int (*pfDEC_ClientSendRawFrame)(long _ulPushID, int _iLen, char* _cStreambuf );
typedef int (*pfDEC_ClientStartPushStreamEx)(int _ulID, int _iChannel, int _iPos, int _iEncodeMode, int _iVideoSize, char* _pcEncryptKey);
typedef int (*pfDEC_ClientSendNonstandardRawFrame)(int _ulPushID, int _iLen, char* _cStreambuf);
typedef int (*pfDEC_SetVolume)(int _iID, int _iVolume);
typedef	int (*pfDEC_GetVolume)(int _iID, int *_piVolume);
typedef	int (*pfDEC_ClientSetCommonEnable)(int _iID, int _iEnableID, int _iChannelNo, int _iEnableValue);
		/*_iEnableID:
			0x13001:断网保留最后一帧; _iEnableValue：0--->不使能;1--->使能。
			0x13002:预览偏好设置;	  _iEnableValue：0--->低延时;1--->高流畅。*/
typedef	int (*pfDEC_ClientGetCommonEnable)(int _iID, int _iEnableID, int *_piEnableLastFrame, int *_piEnablePreference);
typedef int (*pfDEC_ClientStopPushStreamEx)(int _ulPushID, int _iShowLastPic/*=0*/);
typedef int (*pfDEC_ClientStartPushStream_V1)(int _iID, int _iChannel, int _iPos, START_PUSH_PARAM *_pStartPushParam);
typedef int (*pfDEC_ClientConfigStreamInfo)(int _iID, int _iChannel, int _iPos, int _iCmd, void* _pvCmdBuf, int _iBuffSize);
typedef int (*pfDEC_ClientGetDevConfig)(int _ulID, int _iChannel, int _iPos, int _iCmd, void* _pvCmdBuf, int _iBuffSize);
typedef int (*pfDEC_ClientSetDevConfig)(int _ulID, int _iChannel, int _iPos, int _iCmd, void* _pvCmdBuf, int _iBuffSize);
typedef int (*pfDEC_SetSelectPicture)(long _lID, int _iChannel, int _iPicture);

class CLS_NVDSDKHelper
{
public:
	CLS_NVDSDKHelper();
	~CLS_NVDSDKHelper();
	int LoadLibrary(const char *_pclib);
	int FreeLibrary();

	pDEC_ClientStartup 				DEC_ClientStartup;
	pDEC_ClientCleanup 				DEC_ClientCleanup;

	pDEC_ClientLogon   				DEC_ClientLogon;
	pDEC_ClientLogout  				DEC_ClientLogout;

	pDEC_ClientGetDecoderPara 		DEC_ClientGetDecoderPara;

	pDEC_ClientSetIP           	 	DEC_ClientSetIP;
	pDEC_ClientSetDDNS          	DEC_ClientSetDDNS;
	pDEC_ClientSetCom           	DEC_ClientSetCom;
	pDEC_ClientSetAlarmOut      	DEC_ClientSetAlarmOut;
	pDEC_ClientSetTVInfo        	DEC_ClientSetTVInfo;
	pDEC_ClientSetChannelMode   	DEC_ClientSetChannelMode;

	pDEC_ClientSetLogo          	DEC_ClientSetLogo;
	pDEC_ClientGetLogo          	DEC_ClientGetLogo;

	pDEC_ClientGetLoopItemCount 	DEC_ClientGetLoopItemCount;
	pDEC_ClientGetLoopItem      	DEC_ClientGetLoopItem;
	pDEC_ClientGetLoopItemEx      	DEC_ClientGetLoopItemEx;
	pDEC_ClientSetLoopItem      	DEC_ClientSetLoopItem;
	pDEC_ClientSetLoopItemEx      	DEC_ClientSetLoopItemEx;
	pDEC_ClientDelLoopItem      	DEC_ClientDelLoopItem;
	pDEC_ClientStartLoop        	DEC_ClientStartLoop;
	pDEC_ClientStopLoop         	DEC_ClientStopLoop;
	pDEC_ClientGetLoopStatus    	DEC_ClientGetLoopStatus;

	pDEC_ClientStartView        	DEC_ClientStartView;
	pDEC_ClientStartViewEx        	DEC_ClientStartViewEx;
	pDEC_ClientStopView         	DEC_ClientStopView;
	pDEC_ClientGetViewItem      	DEC_ClientGetViewItem;
	pDEC_ClientGetViewItemEx      	DEC_ClientGetViewItemEx;

	pDEC_ClientSendKeyCode      	DEC_ClientSendKeyCode;
	pDEC_ClientPTZCtrl          	DEC_ClientPTZCtrl;
	pDEC_Client485Send          	DEC_Client485Send;
	pDEC_ClientGetPTZprotocols  	DEC_ClientGetPTZprotocols;

	pDEC_ClientSoundCtrl        	DEC_ClientSoundCtrl;
	pDEC_ClientTalkServer       	DEC_ClientTalkServer;
	pDEC_ClientGetAudioStatus   	DEC_ClientGetAudioStatus;
	pDEC_ClientGetTalkStatus    	DEC_ClientGetTalkStatus;

	pDEC_ClientRebootDecoder    	DEC_ClientRebootDecoder;
	pDEC_ClientResetDefault     	DEC_ClientResetDefault;

	pDEC_ClientUpgrade          	DEC_ClientUpgrade;
	pDEC_ClientUpgradeLogo      	DEC_ClientUpgradeLogo;
	pDEC_ClientUpgradeProtocol  	DEC_ClientUpgradeProtocol;
	pDEC_ClientDeleteProtocol   	DEC_ClientDeleteProtocol;
	pDEC_ClientUpgradeWeb       	DEC_ClientUpgradeWeb; 

	pDEC_ClientGetVersion       	DEC_ClientGetVersion;
	pDEC_ClientGetSDKVersion    	DEC_ClientGetSDKVersion;

	pDEC_ClientGetCapability        DEC_ClientGetCapability;

	pDEC_ClientSetComRecvNotify     DEC_ClientSetComRecvNotify;
	pDEC_ClientSetMsgCallback       DEC_ClientSetMsgCallback;

	pDEC_ClientStartPushStream      DEC_ClientStartPushStream;
	pDEC_ClientSendStream           DEC_ClientSendStream;
	pDEC_ClientStopPushStream       DEC_ClientStopPushStream;
	pDEC_ClientSetVGASize           DEC_ClientSetVGASize;

	/*************************add by wangshaobo********************************/
	//pfDEC_ClientPushStreamToDecoder		procDEC_ClientPushStreamToDecoder;
	pfDEC_ClientGetStreamBufferState	procDEC_ClientGetStreamBufferState;
	pfDEC_ClientStreamControl			procDEC_ClientStreamControl;
	pfDEC_ClientLogonEx					procDEC_ClientLogonEx;
	pfDEC_ClientSendRawFrame			procDEC_ClientSendRawFrame;
	pfDEC_ClientStartPushStreamEx		procDEC_ClientStartPushStreamEx;
	pfDEC_ClientSendNonstandardRawFrame	procDEC_ClientSendNonstandardRawFrame;
	pfDEC_SetVolume						procDEC_SetVolume;
	pfDEC_GetVolume						procDEC_GetVolume;
	pfDEC_ClientSetCommonEnable			procDEC_ClientSetCommonEnable;
	pfDEC_ClientGetCommonEnable			procDEC_ClientGetCommonEnable;
	pfDEC_ClientStopPushStreamEx		procDEC_ClientStopPushStreamEx;
	pfDEC_ClientStartPushStream_V1		procDEC_ClientStartPushStream_V1;
	pfDEC_ClientConfigStreamInfo		procDEC_ClientConfigStreamInfo;
	pfDEC_ClientSetDevConfig			procDEC_ClientSetDevConfig;
	pfDEC_ClientGetDevConfig			procDEC_ClientGetDevConfig;
	pfDEC_SetSelectPicture				procDEC_SetSelectPicture;

private:
	void *m_dllhandle;
	char *m_error;
};

#endif
