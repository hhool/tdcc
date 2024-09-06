
#include <errno.h>
#include <iostream>
#include "CLS_NVDSDKHelper.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
//库导出帮助类构造函数,主要为引出函数地址赋初值
CLS_NVDSDKHelper::CLS_NVDSDKHelper()
{
	m_dllhandle = NULL;
	m_error = NULL;

	//库接口初始化
	DEC_ClientStartup = NULL;
	DEC_ClientCleanup = NULL;

	DEC_ClientLogon = NULL;
	DEC_ClientLogout = NULL;

	DEC_ClientGetDecoderPara = NULL;

	DEC_ClientSetIP = NULL;
	DEC_ClientSetDDNS = NULL;
	DEC_ClientSetCom = NULL;
	DEC_ClientSetAlarmOut = NULL;
	DEC_ClientSetTVInfo = NULL;
	DEC_ClientSetChannelMode = NULL;

	DEC_ClientSetLogo = NULL;
	DEC_ClientGetLogo = NULL;

	DEC_ClientGetLoopItemCount = NULL;
	DEC_ClientGetLoopItem = NULL;
	DEC_ClientGetLoopItemEx = NULL;
	DEC_ClientSetLoopItem = NULL;
	DEC_ClientSetLoopItemEx = NULL;
	DEC_ClientDelLoopItem = NULL;
	DEC_ClientStartLoop = NULL;
	DEC_ClientStopLoop = NULL;
	DEC_ClientGetLoopStatus = NULL;

	DEC_ClientStartView = NULL;
	DEC_ClientStartViewEx = NULL;
	DEC_ClientStopView = NULL;
	DEC_ClientGetViewItem = NULL;
	DEC_ClientGetViewItemEx = NULL;

	DEC_ClientSendKeyCode = NULL;
	DEC_ClientPTZCtrl = NULL;
	DEC_Client485Send = NULL;
	DEC_ClientGetPTZprotocols = NULL;

	DEC_ClientSoundCtrl = NULL;
	DEC_ClientTalkServer = NULL;
	DEC_ClientGetAudioStatus = NULL;
	DEC_ClientGetTalkStatus = NULL;

	DEC_ClientRebootDecoder = NULL;
	DEC_ClientResetDefault = NULL;

	DEC_ClientUpgrade = NULL;
	DEC_ClientUpgradeLogo = NULL;
	DEC_ClientUpgradeProtocol = NULL;
	DEC_ClientDeleteProtocol = NULL;
	DEC_ClientUpgradeWeb = NULL; 

	DEC_ClientGetVersion = NULL;
	DEC_ClientGetSDKVersion = NULL;

	DEC_ClientGetCapability = NULL;

	DEC_ClientSetComRecvNotify = NULL;
	DEC_ClientSetMsgCallback = NULL;

	DEC_ClientStartPushStream = NULL;
	DEC_ClientSendStream = NULL;
	DEC_ClientStopPushStream = NULL;
	DEC_ClientSetVGASize = NULL;

	////////////////////////////////////////////////
	//procDEC_ClientPushStreamToDecoder = NULL;
	procDEC_ClientGetStreamBufferState = NULL;
	procDEC_ClientStreamControl = NULL;
	procDEC_ClientLogonEx = NULL;
	procDEC_ClientSendRawFrame = NULL;
	procDEC_ClientStartPushStreamEx = NULL;
	procDEC_ClientSendNonstandardRawFrame = NULL;
	procDEC_SetVolume = NULL;
	procDEC_GetVolume = NULL;
	procDEC_ClientSetCommonEnable = NULL;
	procDEC_ClientGetCommonEnable = NULL;
	procDEC_ClientStopPushStreamEx = NULL;
	procDEC_ClientStartPushStream_V1 = NULL;
	procDEC_ClientConfigStreamInfo = NULL;
	procDEC_ClientSetDevConfig = NULL;
	procDEC_ClientGetDevConfig = NULL;
	procDEC_SetSelectPicture = NULL;
}

//////////////////////////////////////////////////////////////////////////
//库导出帮助类析构函数
CLS_NVDSDKHelper::~CLS_NVDSDKHelper()
{
	if(m_dllhandle) 
	{
		FreeLibrary();
	}
	m_error = NULL;

	DEC_ClientStartup = NULL;
	DEC_ClientCleanup = NULL;

	DEC_ClientLogon = NULL;
	DEC_ClientLogout = NULL;

	DEC_ClientGetDecoderPara = NULL;

	DEC_ClientSetIP = NULL;
	DEC_ClientSetDDNS = NULL;
	DEC_ClientSetCom = NULL;
	DEC_ClientSetAlarmOut = NULL;
	DEC_ClientSetTVInfo = NULL;
	DEC_ClientSetChannelMode = NULL;

	DEC_ClientSetLogo = NULL;
	DEC_ClientGetLogo = NULL;

	DEC_ClientGetLoopItemCount = NULL;
	DEC_ClientGetLoopItem = NULL;
	DEC_ClientGetLoopItemEx = NULL;
	DEC_ClientSetLoopItem = NULL;
	DEC_ClientSetLoopItemEx = NULL;
	DEC_ClientDelLoopItem = NULL;
	DEC_ClientStartLoop = NULL;
	DEC_ClientStopLoop = NULL;
	DEC_ClientGetLoopStatus = NULL;

	DEC_ClientStartView = NULL;
	DEC_ClientStartViewEx = NULL;
	DEC_ClientStopView = NULL;
	DEC_ClientGetViewItem = NULL;
	DEC_ClientGetViewItemEx = NULL;

	DEC_ClientSendKeyCode = NULL;
	DEC_ClientPTZCtrl = NULL;
	DEC_Client485Send = NULL;
	DEC_ClientGetPTZprotocols = NULL;

	DEC_ClientSoundCtrl = NULL;
	DEC_ClientTalkServer = NULL;
	DEC_ClientGetAudioStatus = NULL;
	DEC_ClientGetTalkStatus = NULL;

	DEC_ClientRebootDecoder = NULL;
	DEC_ClientResetDefault = NULL;

	DEC_ClientUpgrade = NULL;
	DEC_ClientUpgradeLogo = NULL;
	DEC_ClientUpgradeProtocol = NULL;
	DEC_ClientDeleteProtocol = NULL;
	DEC_ClientUpgradeWeb = NULL; 

	DEC_ClientGetVersion = NULL;
	DEC_ClientGetSDKVersion = NULL;

	DEC_ClientGetCapability = NULL;

	DEC_ClientSetComRecvNotify = NULL;
	DEC_ClientSetMsgCallback = NULL;

	DEC_ClientStartPushStream = NULL;
	DEC_ClientSendStream = NULL;
	DEC_ClientStopPushStream = NULL;
	DEC_ClientSetVGASize = NULL;

	////////////////////////////////////////////////
	//procDEC_ClientPushStreamToDecoder = NULL;
	procDEC_ClientGetStreamBufferState = NULL;
	procDEC_ClientStreamControl = NULL;
	procDEC_ClientLogonEx = NULL;
	procDEC_ClientSendRawFrame = NULL;
	procDEC_ClientStartPushStreamEx = NULL;
	procDEC_ClientSendNonstandardRawFrame = NULL;
	procDEC_SetVolume = NULL;
	procDEC_GetVolume = NULL;
	procDEC_ClientSetCommonEnable = NULL;
	procDEC_ClientGetCommonEnable = NULL;
	procDEC_ClientStopPushStreamEx = NULL;
	procDEC_ClientStartPushStream_V1 = NULL;
	procDEC_ClientConfigStreamInfo = NULL;
	procDEC_ClientSetDevConfig = NULL;
	procDEC_ClientGetDevConfig = NULL;
	procDEC_SetSelectPicture = NULL;
}

//////////////////////////////////////////////////////////////////////////
//类成员，动态加载库并导出函数
int CLS_NVDSDKHelper::LoadLibrary(const char *_pclib)
{
	if(_pclib == NULL) 
	{
		return -1;
	}
	
	m_dllhandle = dlopen(_pclib, RTLD_LAZY);
	if(!m_dllhandle) 
	{
		m_error = dlerror();
		//perror("error is :");
		cout<<"!!!  "<<m_error<<endl;
		m_error = NULL;
		return -2;
	}
	//perror("----");

	DEC_ClientStartup = (pDEC_ClientStartup)dlsym(m_dllhandle, "DEC_ClientStartup");
	DEC_ClientCleanup = (pDEC_ClientCleanup)dlsym(m_dllhandle, "DEC_ClientCleanup");

	DEC_ClientLogon = (pDEC_ClientLogon)dlsym(m_dllhandle, "DEC_ClientLogon");
	DEC_ClientLogout = (pDEC_ClientLogout)dlsym(m_dllhandle, "DEC_ClientLogout");

	DEC_ClientGetDecoderPara = (pDEC_ClientGetDecoderPara)dlsym(m_dllhandle, "DEC_ClientGetDecoderPara");

	DEC_ClientSetIP = (pDEC_ClientSetIP)dlsym(m_dllhandle, "DEC_ClientSetIP");
	DEC_ClientSetDDNS = (pDEC_ClientSetDDNS)dlsym(m_dllhandle, "DEC_ClientSetDDNS");
	DEC_ClientSetCom = (pDEC_ClientSetCom)dlsym(m_dllhandle, "DEC_ClientSetCom");
	DEC_ClientSetAlarmOut = (pDEC_ClientSetAlarmOut)dlsym(m_dllhandle, "DEC_ClientSetAlarmOut");
	DEC_ClientSetTVInfo = (pDEC_ClientSetTVInfo)dlsym(m_dllhandle, "DEC_ClientSetTVInfo");
	DEC_ClientSetChannelMode = (pDEC_ClientSetChannelMode)dlsym(m_dllhandle, "DEC_ClientSetChannelMode");

	DEC_ClientSetLogo = (pDEC_ClientSetLogo)dlsym(m_dllhandle, "DEC_ClientSetLogo");
	DEC_ClientGetLogo = (pDEC_ClientGetLogo)dlsym(m_dllhandle, "DEC_ClientGetLogo");

	DEC_ClientGetLoopItemCount = (pDEC_ClientGetLoopItemCount)dlsym(m_dllhandle, "DEC_ClientGetLoopItemCount");
	DEC_ClientGetLoopItem = (pDEC_ClientGetLoopItem)dlsym(m_dllhandle, "DEC_ClientGetLoopItem");
	DEC_ClientGetLoopItemEx = (pDEC_ClientGetLoopItemEx)dlsym(m_dllhandle, "DEC_ClientGetLoopItemEx");
	DEC_ClientSetLoopItem = (pDEC_ClientSetLoopItem)dlsym(m_dllhandle, "DEC_ClientSetLoopItem");
	DEC_ClientSetLoopItemEx = (pDEC_ClientSetLoopItemEx)dlsym(m_dllhandle, "DEC_ClientSetLoopItemEx");
	DEC_ClientDelLoopItem = (pDEC_ClientDelLoopItem)dlsym(m_dllhandle, "DEC_ClientDelLoopItem");
	DEC_ClientStartLoop = (pDEC_ClientStartLoop)dlsym(m_dllhandle, "DEC_ClientStartLoop");
	DEC_ClientStopLoop = (pDEC_ClientStopLoop)dlsym(m_dllhandle, "DEC_ClientStopLoop");
	DEC_ClientGetLoopStatus = (pDEC_ClientGetLoopStatus)dlsym(m_dllhandle, "DEC_ClientGetLoopStatus");

	DEC_ClientStartView = (pDEC_ClientStartView)dlsym(m_dllhandle, "DEC_ClientStartView");
	DEC_ClientStartViewEx = (pDEC_ClientStartViewEx)dlsym(m_dllhandle, "DEC_ClientStartViewEx");
	DEC_ClientStopView = (pDEC_ClientStopView)dlsym(m_dllhandle, "DEC_ClientStopView");
	DEC_ClientGetViewItem = (pDEC_ClientGetViewItem)dlsym(m_dllhandle, "DEC_ClientGetViewItem");
	DEC_ClientGetViewItemEx = (pDEC_ClientGetViewItemEx)dlsym(m_dllhandle, "DEC_ClientGetViewItemEx");

	DEC_ClientSendKeyCode = (pDEC_ClientSendKeyCode)dlsym(m_dllhandle, "DEC_ClientSendKeyCode");
	DEC_ClientPTZCtrl = (pDEC_ClientPTZCtrl)dlsym(m_dllhandle, "DEC_ClientPTZCtrl");
	DEC_Client485Send = (pDEC_Client485Send)dlsym(m_dllhandle, "DEC_Client485Send");
	DEC_ClientGetPTZprotocols = (pDEC_ClientGetPTZprotocols)dlsym(m_dllhandle, "DEC_ClientGetPTZprotocols");

	DEC_ClientSoundCtrl = (pDEC_ClientSoundCtrl)dlsym(m_dllhandle, "DEC_ClientSoundCtrl");
	DEC_ClientTalkServer = (pDEC_ClientTalkServer)dlsym(m_dllhandle, "DEC_ClientTalkServer");
	DEC_ClientGetAudioStatus = (pDEC_ClientGetAudioStatus)dlsym(m_dllhandle, "DEC_ClientGetAudioStatus");
	DEC_ClientGetTalkStatus = (pDEC_ClientGetTalkStatus)dlsym(m_dllhandle, "DEC_ClientGetTalkStatus");

	DEC_ClientRebootDecoder = (pDEC_ClientRebootDecoder)dlsym(m_dllhandle, "DEC_ClientRebootDecoder");
	DEC_ClientResetDefault = (pDEC_ClientResetDefault)dlsym(m_dllhandle, "DEC_ClientResetDefault");

	DEC_ClientUpgrade = (pDEC_ClientUpgrade)dlsym(m_dllhandle, "DEC_ClientUpgrade");
	DEC_ClientUpgradeLogo = (pDEC_ClientUpgradeLogo)dlsym(m_dllhandle, "DEC_ClientUpgradeLogo");
	DEC_ClientUpgradeProtocol = (pDEC_ClientUpgradeProtocol)dlsym(m_dllhandle, "DEC_ClientUpgradeProtocol");
	DEC_ClientDeleteProtocol = (pDEC_ClientDeleteProtocol)dlsym(m_dllhandle, "DEC_ClientDeleteProtocol");
	DEC_ClientUpgradeWeb = (pDEC_ClientUpgradeWeb)dlsym(m_dllhandle, "DEC_ClientUpgradeWeb"); 

	DEC_ClientGetVersion = (pDEC_ClientGetVersion)dlsym(m_dllhandle, "DEC_ClientGetVersion");
	DEC_ClientGetSDKVersion = (pDEC_ClientGetSDKVersion)dlsym(m_dllhandle, "DEC_ClientGetSDKVersion");

	DEC_ClientGetCapability = (pDEC_ClientGetCapability)dlsym(m_dllhandle, "DEC_ClientGetCapability");

	DEC_ClientSetComRecvNotify = (pDEC_ClientSetComRecvNotify)dlsym(m_dllhandle, "DEC_ClientSetComRecvNotify");
	DEC_ClientSetMsgCallback = (pDEC_ClientSetMsgCallback)dlsym(m_dllhandle, "DEC_ClientSetMsgCallback");

	DEC_ClientStartPushStream = (pDEC_ClientStartPushStream)dlsym(m_dllhandle, "DEC_ClientStartPushStream");
	DEC_ClientSendStream = (pDEC_ClientSendStream)dlsym(m_dllhandle, "DEC_ClientSendStream");
	DEC_ClientStopPushStream = (pDEC_ClientStopPushStream)dlsym(m_dllhandle, "DEC_ClientStopPushStream");
	DEC_ClientSetVGASize = (pDEC_ClientSetVGASize)dlsym(m_dllhandle, "DEC_ClientSetVGASize");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//procDEC_ClientPushStreamToDecoder = (pfDEC_ClientPushStreamToDecoder)dlsym(m_dllhandle, "DEC_ClientPushStreamToDecoder");
	procDEC_ClientGetStreamBufferState = (pfDEC_ClientGetStreamBufferState)dlsym(m_dllhandle, "DEC_ClientGetStreamBufferState");
	procDEC_ClientStreamControl = (pfDEC_ClientStreamControl)dlsym(m_dllhandle,"DEC_ClientStreamControl");
	procDEC_ClientLogonEx = (pfDEC_ClientLogonEx)dlsym(m_dllhandle,"DEC_ClientLogonEx");
	procDEC_ClientSendRawFrame = (pfDEC_ClientSendRawFrame)dlsym(m_dllhandle,"DEC_ClientSendRawFrame");
	procDEC_ClientStartPushStreamEx = (pfDEC_ClientStartPushStreamEx)dlsym(m_dllhandle,"DEC_ClientStartPushStreamEx");
	procDEC_ClientSendNonstandardRawFrame = (pfDEC_ClientSendNonstandardRawFrame)dlsym(m_dllhandle,"DEC_ClientSendNonstandardRawFrame");
	procDEC_SetVolume = (pfDEC_SetVolume)dlsym(m_dllhandle,"DEC_SetVolume");
	procDEC_GetVolume = (pfDEC_GetVolume)dlsym(m_dllhandle,"DEC_GetVolume");
	procDEC_ClientSetCommonEnable = (pfDEC_ClientSetCommonEnable)dlsym(m_dllhandle,"DEC_ClientSetCommonEnable");
	procDEC_ClientGetCommonEnable = (pfDEC_ClientGetCommonEnable)dlsym(m_dllhandle,"DEC_ClientGetCommonEnable");
	procDEC_ClientStopPushStreamEx = (pfDEC_ClientStopPushStreamEx)dlsym(m_dllhandle,"DEC_ClientStopPushStreamEx");
	procDEC_ClientStartPushStream_V1 = (pfDEC_ClientStartPushStream_V1)dlsym(m_dllhandle,"DEC_ClientStartPushStream_V1");
	procDEC_ClientConfigStreamInfo = (pfDEC_ClientConfigStreamInfo)dlsym(m_dllhandle, "DEC_ClientConfigStreamInfo");
	procDEC_ClientSetDevConfig = (pfDEC_ClientGetDevConfig)dlsym(m_dllhandle, "DEC_ClientSetDevConfig");
	procDEC_ClientGetDevConfig = (pfDEC_ClientGetDevConfig)dlsym(m_dllhandle, "DEC_ClientGetDevConfig");
	procDEC_SetSelectPicture = (pfDEC_SetSelectPicture)dlsym(m_dllhandle, "DEC_SetSelectPicture");

	m_error = dlerror();
	if(m_error) 
	{
		cout<<m_error<<endl;
		m_error = NULL;
		return -3;
	}		

	return 1;
}

//////////////////////////////////////////////////////////////////////////
//类成员，释放资源
int CLS_NVDSDKHelper::FreeLibrary()
{
	if(m_dllhandle) 
	{
		dlclose(m_dllhandle);
		m_dllhandle = NULL;
	}
	return 1;
}

