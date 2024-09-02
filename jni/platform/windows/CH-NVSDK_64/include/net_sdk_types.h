
#ifndef _NET_SDK_TYPES_H_
#define _NET_SDK_TYPES_H_

#ifndef LEN_2
#define LEN_2   2
#endif

#ifndef LEN_4
#define LEN_4   4
#endif
#ifndef LEN_6
#define LEN_6   6
#endif

#ifndef LEN_8
#define LEN_8   8
#endif


#ifndef LEN_10
#define LEN_10	10
#endif

#ifndef LEN_15
#define LEN_15	15
#endif

#ifndef LEN_16
#define LEN_16  16
#endif

#ifndef LEN_17
#define LEN_17  17
#endif

#ifndef LEN_20
#define LEN_20  20
#endif

#ifndef LEN_24
#define LEN_24  24
#endif

#ifndef LEN_31
#define LEN_31  31
#endif

#ifndef LEN_32
#define LEN_32  32
#endif

#ifndef LEN_33
#define LEN_33  33
#endif

#ifndef LEN_36
#define LEN_36  36
#endif

#ifndef LEN_64
#define LEN_64  64
#endif

#ifndef LEN_65
#define LEN_65		65
#endif

#ifndef LEN_128
#define LEN_128 128
#endif

#ifndef LEN_250
#define LEN_250	250
#endif

#ifndef LEN_256
#define LEN_256 256
#endif


#ifndef LEN_255
#define LEN_255 255
#endif

#ifndef LEN_300
#define LEN_300 300
#endif

#ifndef LEN_512
#define LEN_512 512
#endif

#ifndef LEN_1024
#define LEN_1024 1024
#endif

#ifndef LEN_UUID
#define LEN_UUID 64
#endif

#ifndef MAX_SCHEDULE
#define MAX_SCHEDULE 8
#endif

#ifndef MAX_AREA_COUNT
#define MAX_AREA_COUNT				16
#endif

#ifndef MAX_WEEK_DAYS
#define MAX_WEEK_DAYS   7
#endif

#define LENGTH_IPV4					16	
#define LENGTH_IPV6					32
#define LENGTH_IPV6_V1				64
#define LENGTH_SUB_MASK				16
#define LENGTH_MAC_ADDR     		18
#define MAX_IPADDRESS_LEN			64

#define MAX_QUERY_PAGE_COUNT					20
#define MAX_QUERY_VCA_CONDITION					32
#define MAX_VCA_FILE_COUNT						5
#define MAX_VCA_ATTR_COUNT						32
#define MAX_QUERY_LIST_COUNT					32

#define MAX_IP_FILTER_NUM				48
#define MAX_IPV6_PACKAGE_FILTER_NUM		16

#ifndef MAIN_STREAM
#define MAIN_STREAM								0
#endif

#ifndef SUB_STREAM
#define SUB_STREAM								1
#endif

#define BOUNDAY_MAIN							10000
#define BOUNDAY_SUB								1000000

#define FACE_MAX_PAGE_COUNT						20
#define FACE_MAX_KEY_COUNT_OLD					33
#define FACE_MAX_KEY_COUNT						300
#define FACE_MAX_FEATURE_COUNT					10
#define FACE_MAX_RECT_POINT_COUNT				10

////1：通道名称（文本） 2：时间日期 3:logo颜色 4：附加字符 5:交通专用 6：交通合成图片 7：人脸叠加OSD
#define COMMON_OSD_TYPE_CHANNEL     1
#define COMMON_OSD_TYPE_DATETIME    2
#define COMMON_OSD_TYPE_LOGOCOLOR   3
#define COMMON_OSD_TYPE_ADDITION    4
#define COMMON_OSD_TYPE_ITS         5
#define COMMON_OSD_TYPE_ITSMIX      6
#define COMMON_OSD_TYPE_FACEOSD     7
#define MAX_COMMON_OSD_TYPE         8

typedef struct
{
	unsigned short 		iYear;   				/* Year */
	unsigned short 		iMonth;  				/* Month */
	unsigned short 		iDay;    				/* Day */
	unsigned short 		iHour;   				/* Hour */
	unsigned short 		iMinute; 				/* Minute */
	unsigned short 		iSecond; 				/* Second */
} NVS_FILE_TIME,*PNVS_FILE_TIME;

typedef struct tagQueryChanNo
{
	int 				iChanNo;
	int 				iStream;
}QueryChanNo, ChannelList,*PChannelList,*PQueryChanNo;


typedef struct tagNetFileQueryVca
{
	int					iSize;				//结构体大小				
	int					iChanCount;         //通道个数
	int					iChanSize;			//结构体QueryChanNo大小
	QueryChanNo*		pChanList;			//通道列表
	int					iVcaCount;			//智能分析算法个数
	int					iVcaList[MAX_QUERY_LIST_COUNT];		//智能分析算法列表
	NVS_FILE_TIME		tBegTime;			//开始时间
	NVS_FILE_TIME		tEndTime;			//结束时间
	int					iPageCount;			//页大小
	int					iPageNo;			//页编号
	int					iFileType;			//文件类型， 0：全部，1：录像，2：图片
	int					iConditionCount;	//查询条件个数, 最大32， 当值为 0 时，表示查询全部
	char				cQueryCondition[MAX_QUERY_VCA_CONDITION][LEN_256];	
/*
   当智能分析类型为9时: 
	cQueryCondition[0]：表示检索类型 0-按特征检索，1-按事件检索，2-按图片检索;
	cQueryCondition[1]：cQueryCondition[0]为0时 表示年龄，1-少年，2-青年，3-中年，4-老年;
	cQueryCondition[0]为1时 1-人脸检测 2-人脸比对 3-陌生人 4-频次 5-时长;
	cQueryCondition[2]：cQueryCondition[0]为0时 表示性别，1-男，2-女，3-未知; cQueryCondition[0]为2时 表示操作 1-查询 2-获取结果;
	cQueryCondition[3]：cQueryCondition[0]为0时 表示民族，1-汉族，2-少数民族; cQueryCondition[0]为2时 表示图片类型 1-指定文件 2-从人脸库中选择文件;
	cQueryCondition[4]：cQueryCondition[0]为0时 表示姓名; cQueryCondition[0]为2, cQueryCondition[2]为1时 cQueryCondition[3]为1时 表示图片名称; cQueryCondition[0]为2, cQueryCondition[2]为1时 cQueryCondition[3]为2时 人脸库图片Id;
	cQueryCondition[5]：cQueryCondition[0]为0时，表示戴眼镜 0-预留，1-佩戴，2-未佩戴 cQueryCondition[0]为2，cQueryCondition[2]为1时 表示相似度
	cQueryCondition[6]：cQueryCondition[0]为0时，表示戴口罩 0-预留，1-佩戴，2-未佩戴 cQueryCondition[0]为2，cQueryCondition[2]为1时 表示排序方式 0-按时间排序 1-按相似度排序
   当iVcaType = 22时
	cQueryCondition[0]:表示目标，0x7FFFFFFF-全部，1-人，2-其它，3-车
	cQueryCondition[1]:表示类型, 0x7FFFFFFF-全部，1-周界-入侵，2-周界-离开,3-绊线
   当iVcaType = 23时
	cQueryCondition[0]:表示车牌号码
   当iVcaType = 30时
	cQueryCondition[0]:表示安全帽颜色 0x7FFFFFFF-全部,1-红色，2-黄色，3-蓝色，4-白色，5-其它
	cQueryCondition[1]:表示安全帽未佩戴，0-预留，1-佩戴，2-未佩戴
  */
}NetFileQueryVca, *pNetFileQueryVca;


typedef struct tagVcaFileAttr
{
	int					iFileIndex;				//序号：多张图时，每个图分配一个序号，从10001开始，可对序号做校验。
	char				cFileName[LEN_256];		//图片名称
	int					iFileSize;				//图片名称
	int					iFileType;				//图片类型：1-小图，2-大图 
	int					iReserve;				//保留字段
	char				cReserve[LEN_64];		//保留字段
}VcaFileAttr, *pVcaFileAttr;

typedef struct __tagVcaTPoint
{
	int iX;
	int	iY;
} vca_TPoint;

typedef struct __tagVca_TLine
{
	vca_TPoint 	stStart;
	vca_TPoint 	stEnd;
} vca_TLine;						//	sizeof = 2*8 = 16

#ifndef VCA_MAX_POLYGON_POINT_NUM
#define VCA_MAX_POLYGON_POINT_NUM				16	//The maximum number of points allowed per polygon
#endif
typedef struct __tagVca_TPolygon
{
	int 		iPointNum;
	vca_TPoint 	stPoints[VCA_MAX_POLYGON_POINT_NUM];   
} vca_TPolygon;						//	sizeof = 16*8+4 = 132 

#ifndef VCA_MAX_POLYGON_POINT_NUMEX
#define VCA_MAX_POLYGON_POINT_NUMEX				32	//Max Tripwire Points Number
#endif
typedef struct __tagVca_TPolygonEx
{
	int 		iPointNum;
	vca_TPoint 	stPoints[VCA_MAX_POLYGON_POINT_NUMEX];   
} vca_TPolygonEx;

typedef struct __tagTPoint
{
	int iX;
	int	iY;
} TPoint;

typedef struct tagNetFileQueryVcaResult
{
	int					iSize;
	int					iChanNo;
	int					iFileAttrCount;
	VcaFileAttr			tFileAttr[MAX_VCA_FILE_COUNT];

	int					iTotal;
	int					iCurPageCount;
	int					iItemIndex;
	int					iFileType;
	int					iVcaType;
	NVS_FILE_TIME		tBegTime;
	NVS_FILE_TIME		tEndTime;
	
	int					iExAttrCount;
	char				cExAttr[MAX_VCA_ATTR_COUNT][LEN_256];
}NetFileQueryVcaResult, *pNetFileQueryVcaResult;

typedef struct tagIpcDevAttr
{
	int					iSize;
	int					iType;
	int					iParam;
}IpcDevAttr, *pIpcDevAttr;


typedef struct tagUniqueAlertAlarmStatClr
{
	int					iSize;
	int					iSceneId;
	int					iTypeEnable[LEN_32];	//Whether the current alert event needs to eliminate the state of the alarm
	int					iEventNo;
}UniqueAlertAlarmStatClr,*pUniqueAlertAlarmStatClr;

typedef struct tagITS_LightStatus
{
	int					iSize;
	int					iLaneNo;
	int					iLightType;
	int					iStatus;
}ITS_LightStatus, *pITS_LightStatus;

typedef struct tagNetBitRate
{
	int					iSize;
	int					iMaxBw;					//NIC maximum capacity bandwidth
	int					iMaxRxBw;				//maximum access bandwidth
	int					iMaxTxBw;				//maximum forwarding bandwidth
} NetBitRate, *pNetBitRate;

typedef struct tagSipLocalServer
{
	int					iSize;
	int					iServerPort;			//local server port,default 5060
	char				cServerID[LEN_64];		//local server ID
	int					iHeartBeatInterval;		//heart beat interval,Unit: s
	int					iHeartBeatTimes;		//heart beat times
} SipLocalServer, *pSipLocalServer;

#define MAX_MACFILTER_COUNT			32
#define MAC_FILTERTYPE_DISAUTH		0			//Disable MAC authentication
#define MAC_FILTERTYPE_DISACCESS	1			//Disable MAC access
#define MAC_FILTERTYPE_ALLOWACCESS	2			//Allow MAC access
typedef struct tagMacAddrFilter
{
	int					iSize;
	int					iFilterType;			//filter type:0-Disable MAC authentication; 1-Disable MAC access; 2-Allow MAC access
	int					iMacCount;				//mac count,supports up to 32 different MAC addresses
	char				cMacAddr[MAX_MACFILTER_COUNT][LEN_64];	//MAC address string
} MacAddrFilter, *pMacAddrFilter;


#define VPN_VIRNETCARD_TUN			0
#define VPN_VIRNETCARD_TAP			1

#define VPN_PROTOCOL_TCP			0
#define VPN_PROTOCOL_UDP			1

#define VPN_COMPRESS_DISABLE		0
#define VPN_COMPRESS_LZO			1
#define VPN_COMPRESS_LZ4V2			2

#define VPN_CERTIFICATE_AUTH		0
#define VPN_USERNAMEPWD_AUTH		1
#define VPN_CERT_NAMEPWD_AUTH		2

#define CERT_USAGE_DEFAULT			0
#define CERT_USAGE_CUSTOME			1
typedef struct tagVpnParam
{
	int					iSize;
	int					iEnable;				//Enable switch:0-disable openvpn, 1-enable openvpn
	char				cServerIp[LEN_64];		//VPN server address
	int					iServerPort;			//VPN server port
	int					iVirNetCardType;		//Virtual network card type:0-TUN, 1-TAP
	int					iProtoType;				//Transfer Protocol:0-TCP, 1-UDP
	int					iTlsEnable;				//Whether to enable ta.key attack defense:0-disable, 1-enable
	int					iCompress;				//Compression method:0-Not enabled; 1-LZO; 2-LZ4_V2
	int					iCipherType;			//Data encryption method
	int					iIdentifyType;			//verification method:0: Certificate authentication 1: User name password authentication 2: Certificate + username password
	char				cUserName[LEN_128];		//User name, valid when the authentication method is 1 or 2 and the length is <=32
	char				cPassword[LEN_128];		//The password is valid when the authentication method is 1 or 2. The password must be encrypted using the base64 algorithm. Password length <= 64 bytes
	int					iCertUsage;				//Certificate usage:0-factory default, 1-custom imported
} VpnParam, *pVpnParam;

typedef struct tagVpnLan
{
	int					iSize;
	int					iLanNo;					//Network card number
	int					iDhcpEnable;			//0-disable; 1-enable
	char				cIP[LEN_32];			//IPV4 IP address
	char 				cMask[LEN_32];			//IPV4 subnet mask
	char 				cGateway[LEN_32];		//IPV4 default gateway
	int					iMtu;					//Mtu value in the tunnel,range:500-65535
} VpnLan, *pVpnLan;

typedef struct tagVpnState
{
	int					iSize;
	int					iLanNo;
	int					iState;					//0: Not connected, 1:Connected
} VpnState, *pVpnState;

#define CHN_STATE_OFFLINE		0
#define CHN_STATE_ONLINE		1
#define CHNOFFLINE_RSN_USRPWDERR	1
#define CHNOFFLINE_RSN_IPBLOCKED	2			//IP is blocked
#define CHNOFFLINE_RSN_ACCTLOCK		3			//Account lockout
#define CHNOFFLINE_RSN_MAXCON		4			//Maximum number of connections
#define CHNOFFLINE_RSN_NETEXCP		5			//network anomaly
#define CHNOFFLINE_RSN_MAXBD		6			//Reach the NVR maximum bandwidth
#define CHNOFFLINE_RSN_CAPUPPER		7			//Performance cap
typedef struct tagChnOnlineState 
{
	int					iSize;
	int					iState;					//OnlineState :0-offline, 1-online
	int					iOffLineReason;			//the reason when the channel is offline
} ChnOnlineState, *pChnOnlineState;

typedef struct tagRetransInfo 
{
	int					iIndex;
	char				cIp[LEN_64];	
}RetransInfo, *pRetransInfo;

typedef struct tagITS_DevOffLine
{
	int					iSize;
	int					iDevType;
	int					iIOIndex;
}ITS_DevOffLine, *pITS_DevOffLine;
#define MAX_SDI_CUTAREA_POINT 15
typedef struct tagITSSDICUTAREA
{
	int iSize;
	int iSceneId;
	int iAreaType;
	int iEnabled;
	int iCount;
    vca_TPoint pcPoint[MAX_SDI_CUTAREA_POINT];
}ITS_SDICUTAREA,*pITS_SDICUTAREA;

#define MAX_REUPLOAD_COUNT 40
typedef struct tagITSREUPLOAD
{
	int iSize;
	int iPlatetype;
	int iReuploadNum;
	int iOrderID[MAX_REUPLOAD_COUNT];
}ITS_REUPLOAD, *pITS_REUPLOAD;

typedef struct tagITSREUPLOADRESULT
{
	int iSize;
	int iFailNum;
	int iOrderID[MAX_REUPLOAD_COUNT];
}ITS_REUPLOADRESULT, *pITS_REUPLOADRESULT;

typedef struct tagITSWHISTLESNAPSHOTRESULT
{
    int iSize;
    int iChannelNo;
    int iCapFrameNo;        //取值范围：1~10
    int iResult;            //0：预留，1：成功；2：失败
}ITS_WHISTLESNAPSHOTRESULT, *pITS_WHISTLESNAPSHOTRESULT;


typedef struct tagZFCmdResult
{
	int					iSize;
	int					iResult;
}ZFCmdResult,*pZFCmdResult;

typedef struct tagDelMultiFile
{
	int					iSize;
	int					iChanCount;
	int					iChanSize;
	QueryChanNo*		pChanList;
	int					iRecType;
	NVS_FILE_TIME		tBegTime;
	NVS_FILE_TIME		tEndTime;
}DelMultiFile,*pDelMultiFile;

typedef struct tagDelMultiFileProgress
{
	int					iSize;
	int					iProgress;
}DelMultiFileProgress,*pDelMultiFileProgress;

typedef struct tagBurnMount
{
	int					iSize;
	int					iDeviceNum;
	int					iCmd;
}BurnMount,*pBurnMount;

typedef struct tagBurnCheckDisk
{
	int					iSize;
	int					iType;
	int					iMode;
	int					iDvdNo;
}BurnCheckDisk,*pBurnCheckDisk;

typedef struct tagBurnBackupStart
{
	int					iSize;
	int					iMode;
	int					iDvdNo;
	int					iRecordType;
	int					iRecCode;
	int					iRecAccFile;
	int					iChanCount;
	int					iChanSize;
	QueryChanNo*		pChanList;
	int					iRecType;
	NVS_FILE_TIME		tBegTime;
	NVS_FILE_TIME		tEndTime;
	char				cDvdLable[LEN_64];
}BurnBackupStart,*pBurnBackupStart;

typedef struct tagBurnBackupState
{
	int					iSize;
	int					iDeviceNum;
	int					iState;
	int					iProgress;
	int					iTotalProgress;
}BurnBackupState,*pBurnBackupState;

typedef struct tagBurnBackupStop
{
	int					iSize;
}BurnBackupStop,*pBurnBackupStop;

typedef struct tagZFVolumeIn
{
	int					iSize;
	int					iChanNo;
	int					iType;
}ZFVolumeIn,*pZFVolumeIn;

typedef struct tagZFCameraType
{
	int					iSize;
	int					iType;
}ZFCameraType,*pZFCameraType;

typedef struct tagBurnBackupStateQuery
{
	int					iSize;
	int					iDvdNo;
}BurnBackupStateQuery,*pBurnBackupStateQuery;

typedef struct tagBurnBackupStateResult
{
	int					iSize;
	int					iResult;
	int					iBackupStat;
	int					iBurnProcess;
	int					iTotalBurnProcess;
	int					iBurnMode;
	int 				iDvdNum;
	int					iRecordType;
	int					iRecCode;
	int					iRecAccFile;
	int					iChanCount;
	QueryChanNo			tChannelList[LEN_32];
	int					iRecType;
	NVS_FILE_TIME		tBegTime;
	NVS_FILE_TIME		tEndTime;
	char				cDvdLable[LEN_64];
}BurnBackupStateResult, *pBurnBackupStateResult;

typedef struct tagSmdEncodeEnable
{
	int 				iEnable;
}SmdEncodeEnable, *pSmdEncodeEnable;

typedef struct tagSmdImageEnable
{
	int 				iEnable;
}SmdImageEnable, *pSmdImageEnable;

typedef struct tagSmdSceneEnable
{
	int 				iEnable;
}SmdSceneEnable, *pSmdSceneEnable;

typedef struct tagSmdAlarmArea
{
	int					iLeftMargin;
	int					iTopMargin;
	int					iRightMargin;
	int					iBottomMargin;
}SmdAlarmArea, *pSmdAlarmArea;

typedef struct tagVerificationCode
{
	char cVerificionCode[LEN_32];
}VerificationCode,*pVerificationCode;

#define MAX_VERSION_COUNT   3
typedef struct tagSnmpPara
{
	int                 iSize;
	int                 iEnable[MAX_VERSION_COUNT];
	int                 iPort;
	char                cReCommunity[LEN_33];
	char                cWrCommunity[LEN_33];
	char                cTrapAddr[LEN_16];
	int                 iTrapPort;
	char                cTrapCommunity[LEN_33];
	char                cReUser[LEN_33];
	int                 iReSecurity;
	int                 iReAuthAlg;
	char                cReAuthPwd[LEN_17];
	int                 iRePrivAlg;
	char                cRePrivPwd[LEN_17];
	char                cWrUser[LEN_33];
	int                 iWrSecurity;
	int                 iWrAuthAlg;
	char                cWrAuthPwd[LEN_17];
	int                 iWrPrivAlg;
	char                cWrPrivPwd[LEN_17];
}SnmpPara, *pSnmpPara;

//server type
#define SERVERTYPE_PRIVATE		(0)
#define SERVERTYPE_ONVIF		(1)
#define SERVERTYPE_PUSH			(2)
#define SERVERTYPE_RTSP			(3)
#define SERVERTYPE_28181GB		(4)
#define SERVERTYPE_LG			(1001)

typedef struct tagVCARule
{
	int					iSceneID;				//scene ID(0~15)
	int					iRuleID;				//rule ID(0~7)
	int					iValid;					//event valid, 0:invalid,1:valid
}VCARule,*pVCARule;

typedef struct __tagVca_TDisplayParam
{
	int					iDisplayRule;			//display Rule,0-display 1-Not display	
	int					iDisplayStat;			//alarm count display,0-display 1-Not display
	int					iColor;					//zone color,1-red 2-green 3-yellow 4-blue 5-Purple 6-cyan-blue 7-black 8-White,(defalit green)
	int					iAlarmColor;			//alarm zone color
}vca_TDisplayParam;	

typedef struct tagVCAColorTrack
{
	int					iSize;
	VCARule				tRule;
	vca_TDisplayParam	tDisplayParam;
	int					iDisplayTarget;
	int					iMaxSize;
	int					iMinSize;
	int					iCalibrationSize;
	int					iSensitiv;
	int					iTargetColor;
	int					iHue;
	int					iSaturation;
	int					iLightness;
	int					iZoomRate;
	int					iSearchTime;
	int					iSearchLoop;
}VCAColorTrack, *pVCAColorTrack;

#define MAX_DETECT_AREA_NUM			 8

typedef struct tagVCACommonPara
{
	int					iDevType;								//0-IPC，1-NVR
	VCARule				tRule;
	vca_TDisplayParam	tDisplayParam;
	int					iDisplayTarget;
	int					iMaxSize;
	int					iMinSize;
	int					iSensitivity;
	int					iRegionNum;
	vca_TPolygonEx		stPoints[MAX_DETECT_AREA_NUM];			//The number of vertices of the polygon area and coordinate
}VCACommonPara, *pVCACommonPara;

typedef struct tagVCAParaProcratorateDuty
{
	VCACommonPara		tVcaCommPara;
	int					iLeaveTime;
	int					iInvalidRegionNum;
	vca_TPolygonEx		stInvalidPoints[MAX_DETECT_AREA_NUM];
	vca_TPolygonEx		stPrisonerRegion;					//Prisoner Region
}VCAParaProcratorateDuty, *pVCAParaProcratorateDuty;

typedef struct tagVCAParaHeightLimit
{
	VCACommonPara		tVcaCommPara;
	int					iLimitTime;
}VCAParaHeightLimit, *pVCAParaHeightLimit;

typedef struct tagVCANewDuty
{
	VCACommonPara		tVcaCommPara;
	int					iLeaveTime;
	int					iDutyNum;
}VCAParaNewDuty, *pVCAParaNewDuty;

typedef struct tagVCAAbnormalNum
{
	VCACommonPara       tCommonInfo;
	int                 iReferNum;
	int                 iMode;
	int                 iLeaveTime;
	int			        iInvalidRegionNum;
	vca_TPolygonEx		stInvalidPoints[MAX_DETECT_AREA_NUM];	
}VCAAbnormalNum, *pVCAAbnormalNum;

typedef struct tagVcaArmTouch
{
	VCACommonPara       tCommonInfo;
	int                 iTimeMin;
	int			        iInvalidRegionNum;
	vca_TPolygonEx		stInvalidPoints[MAX_DETECT_AREA_NUM];	
}VcaArmTouch, *pVcaArmTouch;

typedef struct tagVcaNewFight
{
	VCACommonPara       tCommonInfo;
	int                 iTimeMin;
	int			        iInvalidRegionNum;
	vca_TPolygonEx		stInvalidPoints[MAX_DETECT_AREA_NUM];	
}VcaNewFight, *pVcaNewFight;

typedef struct tagVcaStillDect
{
	VCACommonPara       tCommonInfo;
	int                 iStillTime;
	int			        iInvalidRegionNum;
	vca_TPolygonEx		stInvalidPoints[MAX_DETECT_AREA_NUM];	
}VcaStillDect, *pVcaStillDect;

typedef struct tagVCAParaGetUp
{
	VCACommonPara		tCommonPara;
	vca_TLine			tLinePoins;
}VCAParaGetUp, *pVCAParaGetUp;

typedef struct tagVCAParaSlipUp
{
	VCACommonPara		tCommonPara;//The Slip Up algorithm has only one region.The default value iRegionNum=1.
	int     			iHeightMax;	
}VCAParaSlipUp, *pVCAParaSlipUp;

typedef struct tagVCAParaLeaveBed
{
	VCACommonPara		tCommonPara;
	int     			iLeaveTime;	
}VCAParaLeaveBed, *pVCAParaLeaveBed;

typedef struct tagVCAParaSleep
{
	VCACommonPara		tCommonPara;
	int     			iSleepTime;	
	int					iInvalidRegionNum;
	vca_TPolygonEx		stInvalidPoints[MAX_DETECT_AREA_NUM];
}VCAParaSleep, *pVCAParaSleep;

#define		MAX_LOCAL_NVR_TARGET_NUM   4			//每区域目标最多4个
#define		MAX_LOCAL_NVR_REGION_NUM   8			//区域最大8个
typedef struct tagTargetResult
{
	int				iAlarmState;
	int				iTargetID;
	int				iTargetType;
	int				iLeft; 
	int				iTop; 
	int				iRight; 
	int				iBottom; 	
}TargetResult, *pTargetResult;

typedef struct tagRegionInfo
{
	int				iTargetNum;
	TargetResult	tTargetResult[MAX_LOCAL_NVR_TARGET_NUM];
}RegionInfo, *pRegionInfo;

typedef struct _tagDayScheduleTime
{
	int  				iStartHour;
	int  				iStartMin;
	int  				iStopHour;
	int  				iStopMin;
	int  				iEnable;			
}DayScheduleTime,*PDayScheduleTime;

#define MAX_DAYS								7
#define MAX_EXTRA_SCHEDULE_TIME_SEGMENT			16
typedef struct _tagExtraAlarmSchedule
{
	int					iSize;
	int					iSceneID;
	int					iAlarmType;
	int					iWeekday;						
	int					iParam1;
	int					iParam2;
	int					iSegmentNum;
	DayScheduleTime		tTimeSegment[MAX_EXTRA_SCHEDULE_TIME_SEGMENT];		
}ExtraAlarmSchedule, *PExtraAlarmSchedule;


//faceParam
#define FACE_CMD_MIN								0	
#define FACE_CMD_EDIT								(FACE_CMD_MIN + 0x00)
#define FACE_CMD_DELETE								(FACE_CMD_MIN + 0x01)
#define FACE_CMD_QUERY								(FACE_CMD_MIN + 0x02)
#define FACE_CMD_MODEL								(FACE_CMD_MIN + 0x03)
#define FACE_CMD_LIB_EDIT							(FACE_CMD_MIN + 0x04)
#define FACE_CMD_LIB_DELETE							(FACE_CMD_MIN + 0x05)
#define FACE_CMD_LIB_QUERY							(FACE_CMD_MIN + 0x06)
#define FACE_CMD_FEATURE_QUERY						(FACE_CMD_MIN + 0x07)
#define FACE_CMD_FEATURE_CALC						(FACE_CMD_MIN + 0x08)
#define FACE_CMD_CUT								(FACE_CMD_MIN + 0x09)
#define FACE_CMD_CUT_QUERY							(FACE_CMD_MIN + 0x0A)
#define FACE_CMD_TASK_CREATE						(FACE_CMD_MIN + 0x0B)
#define FACE_CMD_TASK_FREE							(FACE_CMD_MIN + 0x0C)
#define FACE_CMD_LIB_IMPORT							(FACE_CMD_MIN + 0x0D)
#define FACE_CMD_SEARCH								(FACE_CMD_MIN + 0x0E)
#define FACE_CMD_LIB_SYNC_START						(FACE_CMD_MIN + 0x0F)
#define FACE_CMD_LIB_SYNC_STATUS					(FACE_CMD_MIN + 0x10)
#define FACE_CMD_CUT_EX								(FACE_CMD_MIN + 0x11)
#define FACE_CMD_SEARCH_SNAP						(FACE_CMD_MIN + 0x12)
#define FACE_CMD_SEARCH_SNAP_PROCESS				(FACE_CMD_MIN + 0x13)
#define FACE_CMD_SEARCH_SNAP_RESULT 				(FACE_CMD_MIN + 0x14)
#define FACE_CMD_ALARM_PARAM						(FACE_CMD_MIN + 0x15)
#define FACE_CMD_MAX								(FACE_CMD_MIN + 0x16)	

typedef struct tagFaceReply
{
	int					iSize;					//结构体大小
	int					iLibKey;				//人脸库key值，iLibKey>0	  
	int 				iFaceKey;				//图片key值，iFaceKey>0 
	int					iOptType;				//0-添加人脸 1-编辑人脸 2-删除人脸 3-添加人脸库 4-编辑人脸库 5-删除人脸库 6-人脸建模 7-查询人脸库
												//8-查询人脸 9-人脸属性查询 10-人脸属性提取 11-扣人脸 12-以图搜底图 13-同步人脸库 14-查询同步人脸库状态
												//15-以图搜抓拍图 16-人脸库拷贝迁移 17-人脸库解锁密码校验 18-人脸特征值比对
	int					iResult;				//0-成功，1-系统准备好 2-失败 3-超出最大范围 4-系统正在删除 5-系统正在扣人脸 
												//6-系统正在执行以图搜抓拍图操作 7-密码错误
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID
	char				cFaceUUID[LEN_UUID];	//图片在平台对应ID
	int					iDelLibProgress;		//当iResult=4时有效，表示人脸库删除进度，取值范围0-100
												//当iResult=6时有效，表示以图搜抓拍图搜索进度，取值范围0-100
												/*当iOptType=0 && iResult=2时有效, 返回结果如下
													1：人脸底库不存在
													2：暂停智能分析失败
													3: 设备正在升级和对讲
													4: 添加数据库失败
													5：生成图片错误
													6：建模错误---建模图片不符合要求
													7：建模错误---建模图片算法没有检出人脸
													8：建模错误---建模图片人脸检出扩张之后超过1280*736
													9：建模错误---图片的格式和内容不匹配
													10：建模错误---建模图片插入到算法数据库失败
													11：建模错误---建模图片从算法数据库删除失败
													12：建模错误---从jpeg头部信息找图片宽高错误
													13: JPG 转 YUV 失败
													14: JPG 转 ARGB 失败
													15：无效的feature data
													16：算法返回错误
													17：VGS缩放失败                                                     
													18: 建模错误---获取视频帧失败  
													19: VGS局部缩放或者原图缩放失败  
												*/
}FaceReply,*pFaceReply;

typedef struct tagFaceInfo
{
	int					iSize;					//结构体大小
	int					iLibKey;				//人脸库key值，iLibKey>0（iLibKey为0，cLibUUID为空时表示查询所有库） 
	int 				iFaceKey;				//图片key值， iFaceKey>0
	int					iCheckCode;				//文件校验码，iFaceKey=0时有效，用来校验人脸图片
	int					iFileType;				//文件扩展类型，iFaceKey=0时有效，0-jpg，1-png  
	int					iModeling;				//是否建模：0-不建模，1-建模；单张导入时发1，批量导入时发0
	char				cName[LEN_64];			//姓名
	int					iSex;					//性别：0-未知，1-男，2-女
	char				cBirthTime[LEN_16];		//出生日期，格式为：2017-04-04，最大16个字节
	int					iNation;				//民族，按国家标准代码 （见民族代码表）
	int					iPlace;					//籍贯，高16位表示省，低16位表示市；（见省份城市代码表）分别按国家行政区划代码赋值，0表示未知
	int					iCertType;				//证件类型，0-未知，1-身份证，2-军官证，3-护照，4-员工编号
	char				cCertNum[LEN_64];		//证件号
	int					iOptType;				//操作类型：1=添加，2=修改，3=复制，4=迁移
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID，不为空以本字段为准
	char				cFaceUUID[LEN_UUID];	//图片在平台对应ID，不为空以本字段为准
	char				cLibVersion[LEN_64];	//人脸库版本号
	char				cVerifyCode[LEN_64];	//图片校验码，图片文件MD5
	int					iTaskId;				//事务ID，以图搜底图有效
	char				cFileName[LEN_256];		//图片名称，底库图片名
	int					iSimilar;				//相似度，0-100（以图搜底图中的相似度）
	int					iCountry;				//国家，按国家和地区ISO 3166-1代码表（见数字）
	char				cAddress[LEN_64];		//地址
	char				cCompany[LEN_64];		//公司
}FaceInfo,*pFaceInfo;

typedef struct tagFaceEdit
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	char				cFacePic[LEN_256];		//输入要编辑的图片名称	
	FaceInfo			tFace;					//图片信息
}FaceEdit,*pFaceEdit;

typedef struct tagFaceDelete
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号从0开始
	int					iLibKey;				//人脸库key值，iLibKey>0	  
	int 				iFaceKey;				//图片key值， iFaceKey>0
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID，不为空以本字段为准
	char				cFaceUUID[LEN_UUID];	//图片在平台对应ID，不为空以本字段为准
}FaceDelete,*pFaceDelete;

typedef struct tagFaceQuery
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iPageNo;				//页码，iPageNo>=0
	int					iPageCount;				//当前页条数，iPageSize>=0
	int					iLibKey;				//人脸库key值，iLibKey>0（iLibKey为0，cLibUUID为空时表示查询所有库）
	int 				iModeling;				//建模状态， 0-建模成功，1-建模失败，2-未建模 
	char				cName[LEN_64];			//姓名
	int					iSex;					//性别，0-未知，1-男，2-女
	char				cBirthStart[LEN_16];	//出生日期查询开始时间，格式为：2017-04-04
	char				cBirthEnd[LEN_16];		//出生日期查询结束时间，格式为：2017-04-04
	int					iNation;				//民族，按国家标准代码 
	int					iPlace;					//籍贯，高16位表示省，低16位表示市；
												//分别按国家行政区划代码赋值，0表示未知  （见省份城市代码表）
	int					iCertType;				//证件类型，0-未知，1-身份证，2-军官证，3-护照，4-员工编号
	char				cCertNum[LEN_64];		//证件号
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID
	char				cLibPwd[LEN_64];		//library password
	int					iCountry;				//country
	char				cAddress[LEN_64];		//address
	char				cCompany[LEN_64];		//company
}FaceQuery,*pFaceQuery;

typedef struct tagFaceQueryResult
{
	int					iSize;					//结构体大小					
	int					iChanNo;				//通道号，从0开始
	int					iTotal;					//总条数
	int					iPageNo;				//页码，从0开始
	int					iPageCount;				//当前页条数
	int					iIndex;					//页码内序号，从0开始
	FaceInfo			tFace;					//人脸信息结构体
}FaceQueryResult,*pFaceQueryResult;

typedef struct tagFaceLibInfo
{
	int					iSize;					//结构体大小
	int					iLibKey;				//人脸库key值，iLibKey=0表示添加人脸库，>0表示修改人脸库  
	char				cName[LEN_64];			//人脸库名称
	int					iThreshold;				//人脸库阈值
	char				cExtrInfo[LEN_64];		//附加信息
	int					iAlarmType;				//是否上传识别信息，0-不上传，1-上传
	int					iOptType;				//操作类型，1--添加人脸库，2--修改人脸库，3--锁定密码校验，4--通过NVR修改前端相似度
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID，不为空以本字段为准
	char				cLibVersion[LEN_64];	//人脸库版本号
}FaceLibInfo,*pFaceLibInfo;

typedef struct tagFaceLibEdit
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	FaceLibInfo			tFaceLib;				//人脸库信息结构体，不为空以本字段为准
}FaceLibEdit,*pFaceLibEdit;

typedef struct tagFaceLibDelete
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iLibKey;				//人脸库key值，iLibKey>0
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID
}FaceLibDelete,*pFaceLibDelete;

typedef struct tagFaceLibQuery
{
	int					iSize;			//结构体大小
	int					iChanNo;		//通道号，从0开始
	int					iPageNo;		//当前页编号，从0开始
	int					iPageCount;		//当前页大小
}FaceLibQuery,*pFaceLibQuery;

typedef struct tagFaceLibQueryResult
{
	int					iSize;			//结构体大小
	int					iChanNo;		//通道号，从0开始
	int					iTotal;			//总个数
	int					iPageNo;		//当前页编号，从0开始
	int					iIndex;			//页码内序号，从0开始
	int					iPageCount;		//当前页大小
	FaceLibInfo			tFaceLib;		//人脸库信息结构体	
}FaceLibQueryResult,*pFaceLibQueryResult;


typedef struct tagFaceModeling
{
	int					iSize;			//结构体大小
	int					iChanNo;		//通道号，从0开始
	int					iType;			//建模类型，0-单张建模，1-批量建模（未建模人脸），2-批量建模（全部人脸），3-取消建模
	int					iLibKey;		//人脸库key值，iLibKey>0
	int					iFaceNum;		//建模进度
	int					iFaceKey[FACE_MAX_PAGE_COUNT];	//图片key值
}FaceModeling,*pFaceModeling;

typedef struct tagFaceModeResult
{
	int					iSize;			//结构体大小
	int					iChanNo;		//通道号，从0开始
	int					iType;			//建模类型，0-单张建模，1-批量建模（未建模人脸），2-批量建模（全部人脸），3-取消建模
	int					iLibKey;		//人脸库key值，iLibKey>0
	int					iFaceKey;		//图片key值
	char				cName[LEN_64];	//姓名
	int					iRetsult;		//建模结果：0-成功，1-系统忙，2-图片格式错误，3-无人脸，4-多个人脸 5-质量低
	int					iTotal;			//建模总数：iTotal>=0
	int					iIndex;			//建模进度，尝试建模个数
}FaceModeResult,*pFaceModeResult;


typedef struct tagFaceFeatureQuery
{	
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iLibKey;				//人脸库key值，iLibKey>0
	int					iFaceKey;				//图片key值
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID，不为空以本字段为准
	char				cFaceUUID[LEN_UUID];	//图片在平台对应ID，不为空以本字段为准
}FaceFeatureQuery,*pFaceFeatureQuery;

typedef struct tagFaceFeatureCalc
{	
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iCheckCode;				//文件校验码，用来校验人脸图片，0表示不校验
	int					iPicType;				//文件扩展类型：0-jpg，1-png
	char				cPicPath[LEN_256];		//需要提取人脸属性的图片路径
	char				cPicUUID[LEN_UUID];		//图片序列号
}FaceFeatureCalc,*pFaceFeatureCalc;

//扣人脸
typedef struct tagFaceCut
{	
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	char				cCheckCode[LEN_64];		//文件校验码，用来校验人脸图片MD5 
	int					iTaskId;				//事务ID
	int					iPicType;				//文件扩展类型：0-jpg，1-png
	char				cPicPath[LEN_256];		//需要抠图的图片路径
}FaceCut,*pFaceCut;

typedef struct tagFaceCutQuery
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iTaskId;				//事务ID
	int					iPageNo;				//页编号
	int					iPageCount;				//页大小
}FaceCutQuery,*pFaceCutQuery;


typedef struct tagFaceCutEx
{	
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	char				cCheckCode[LEN_64];		//文件校验码，用来校验人脸图片MD5 
	int					iPicType;				//文件扩展类型：0-jpg，1-png
	char				cPicPath[LEN_256];		//需要抠图的图片路径
	int					iPageNo;				//页编号
	int					iPageCount;				//页大小
}FaceCutEx,*pFaceCutEx;

typedef struct tagFaceCutQueryResult
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iTaskId;				//事务ID
	int					iTotal;					//抠图总数
	int					iPageNo;				//页编号
	int					iIndex;					//当前第几条，最大值20
	int					iPageCount;				//当前页条数
	char				cFileName[LEN_256];		//图片名称，图片下载走之前的图片下载协议
}FaceCutQueryResult,*pFaceCutQueryResult;

//以图搜底图（回复查询人脸信息）
typedef struct tagFaceSearch
{
	int					iSize;				//结构体大小
	int					iChanNo;			//通道号，从0开始
	int					iTaskId;			//事务ID
	char				cLibKey[LEN_64];	//人脸库在平台的ID，不为空以本字段为准
	char				cPicName[LEN_256];	//图片名称
	int					iSimilar;			//相似度，0-100
	int					iPageNo;			//当前页码，从0开始
	int					iPageCount;			//每页个数，最大20
	int					iLibKey;			//库id，iLibKey>0(iLibKey为0，cLibUUID为空时表示查询所有库)
}FaceSearch,*pFaceSearch;

typedef struct tagFaceTaskFree
{
	int					iSize;				//结构体大小
	int					iTaskId;			//事务ID
}FaceTaskFree,*pFaceTaskFree;

#define MAX_FEATURE_DATA_LEN		(32*1024)

typedef struct tagFaceFeatureResult
{		
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iType;					//提取类型：1：提取单张图片的feature，2：查询图片的feature
	int					iLibKey;				//人脸库key值：提取单张图片feature时，该值为0
	int					iFaceKey;				//图片key值：提取单张图片feature时，该值为0
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID：提取单张图片feature时，该值为0
	char				cFaceUUID[LEN_UUID];	//图片在平台对应ID，或图片序列号
	int					iFaceNum;				//人脸数目
	int					iFaceRectCount[FACE_MAX_FEATURE_COUNT];		//当前人脸区域个数
	TPoint				tFaceRectPoint[FACE_MAX_FEATURE_COUNT][FACE_MAX_RECT_POINT_COUNT];	//当前人脸区域坐标
	int					iFaceDataLen[FACE_MAX_FEATURE_COUNT];	//当前人脸feature数据的总长度
	char				cFaceData[FACE_MAX_FEATURE_COUNT][MAX_FEATURE_DATA_LEN];	//feature二进制数据
}FaceFeatureResult,*pFaceFeatureResult;

#define FACE_ALARM_DETECTION				0		//Face detection
#define FACE_ALARM_RECOGNITON_DISCERN		1		//Face recognition-Comparison alarm
#define FACE_ALARM_RECOGNITON_STRANGER		2		//Face recognition-Stranger alarm
#define FACE_ALARM_RECOGNITON_RATEN			3		//Face recognition-Frequency alarm
#define FACE_ALARM_RECOGNITON_DETENTION		4		//Face recognition-Stay alarm

typedef struct tagFaceAlarmParam
{
	int					iSize;					//结构体大小
	int					iChanNo;				//通道号，从0开始
	int					iAlarmType;				//报警类型列表			
	int					iParam1;				//iType=21，NVR的智能分析列表							
	int					iParam2;				//当iType=21， iParam1=3,4时代表时间
	int					iParam3;				//iType =21，iParam2=3时，代表频次
	char				cLibkey[LEN_64];		//人脸库key值	
	int					iRecognition;			//是否上传识别信息：0-不支持，1-不上传，2-上传
	int					iSimilar;				//相似度：0--100
	int					iDevType;				//设备类型：0-IPC，1-NVR	
	int					iEnable;				//使能：0-不使能  1-使能
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID列表：UUID列表，最大10个，逗号分隔
	int					iLibEnable;				//人脸库使能列表：0-不使能  1-使能，个数同cLibUUIDList，逗号分隔  例：1,0,1
}FaceAlarmParam, *pFaceAlarmParam;

typedef struct tagFaceAlarmParamIn
{
	int					iSize;			//结构体大小
	int					iType;			//人脸报警类型：0--人脸检测，1--比对报警，2--陌生人报警，3--频次报警，4--滞留报警
	int					iRetCount;		//输入需要获取的报警信息单元的个数
}FaceAlarmParamIn, *pFaceAlarmParamIn;

#define  MAX_DETECTAREA_NUM 128
#define  MIN_POINT_NUM  3
typedef struct _tagDetectArea
{
	int				 	iSize;
	int              	iChannelNO;
	int              	iSceneID;
	int              	iStatus;//1-开始上报检测区域 2-停止上报检测区域
	int                 iType; //0-人脸检测 1-流速检测 2-水位水尺检测
}DetectArea, *pDetectArea;

typedef struct _tagDetectAreaResult
{
	int				  	iSize;
	int               	iChannelNO;
	int               	iSceneID;//0-127
	int               	iAreaNum;//3～32
	int               	iState;   //0-未设置 1-已设置
	vca_TPolygonEx    	tPoint;
	int                 iAreaType;//0-人脸检测 1-流速检测 2-水位水尺检测
}DetectAreaResult, *pDetectAreaResult;

typedef struct _tagDetectAreaFinish
{
	int				  	iSize;
	int               	iChannelNO;
	int               	iSceneID;
	int               	iAreaNum; 
	int               	iAreaList[MAX_DETECTAREA_NUM];
	int                 iAreaType;//0-人脸检测 1-流速检测 2-水位水尺检测
}DetectAreaFinish, *pDetectAreaFinish; 

#define MAX_PACK_AREA_LIST      16
#define MAX_PACK_NUM            8
typedef struct _tagDetectAreaListInfo
{
	int                 iPackNo;
	int                 iAreaList[MAX_PACK_AREA_LIST];
}DetectAreaListInfo, *pDetectAreaListInfo;

typedef struct _tagDetectAreaFinishEx
{
	int				  	iSize;
	int               	iChannelNO;
	int               	iSceneID;
	int               	iAreaNum; 
    DetectAreaListInfo  tInfo[MAX_PACK_NUM];
	int                 iAreaType;//0-人脸检测 1-流速检测 2-水位水尺检测
}DetectAreaFinishEx, *pDetectAreaFinishEx;

typedef struct _tagDetectPara
{
	int 				iSize;						//size of struct
	int 				iChannelNo;
	int 				iSceneID;
	int 				iDetectLoop;
	int 				iDetectTime;
} DetectPara, *pDetectPara;


typedef struct _tagSetDetectArea
{
	int            		iSize;						//size of struct
	int            		iChannelNO;
	int            		iSceneID;
	int            		iAreaNum;
	int            		iOperationType; 
	vca_TPolygonEx 		tPoints;
} SetDetectArea, *pSetDetectArea; 

#define  PICTURE_TYPE_CUSTOMIZE			0
#define  PICTURE_TYPE_HEAD_PHOTO		1
#define  PICTURE_TYPE_HALFBODY_PHOTO	2
#define  PICTURE_TYPE_FULLBODY_PHOTO	3
typedef struct _tagVcaTargetPicture
{
	int					iSize;				//size of struct
	int 				iTargetPictureType; //Target image type  0-customize 1-Head Photo 2-Half-body Photo 3-Full-body Photo
	int					iPictureWidth;		//Picture Width(1~5) When iTargetPictureType=0,This param is available.
	int					iFaceHeight;		//Face Height(1~3)	 When iTargetPictureType=0,This param is available.
	int					iBodyHeight;		//Body Height(0~10)	 When iTargetPictureType=0,This param is available.
}VcaTargetPicture,*pVcaTargetPicture;

typedef struct _tagRainFallAlarmInfo
{
	int                 iSize;							//size of struct
	int                 iRainfallValue;     			//80,120,160(mm)
	int                 iAlarmTime;         			//Alarm Time 1-600s
	int                 iRainTimeInter;     			//The Interval Of Rain Times
	int                 iUploadTime;        			//Default Upload Check Time (min)  
	int                 iModerateRainUploadTime;        //Moderate Rain Upload Check Time (min)
	int                 iHeavyRainUploadTime;           //Heavy Rain Upload Check Time(min)
	int                 iTorrentialRainUploadTime;      //Torrential Rain Upload Check Time (min)
	int                 iModerateRainThershold;         //Moderate Rain Thershold (mm/min) 
	int                 iHeavyRainThershold;            //Heavy Rain Thershold mm/min
	int                 iTorrentialRainThershold;       //Torrential Rain Thershold mm/min
	int	                iUploadType;					//上报方式	0-保留 1-场次上报 2-定时上报					
	int                	iInterval;						//统计时长间隔	范围:0-当前变化的雨量、60-86400，默认:3600，单位:秒					
}RainFallAlarmInfo, *pRainFallAlarmInfo;

#define DEFAULT_CHECKSTAND								1
#define DEFAULT_ALERTWATER								0
#define DEFAULT_ALARMLINKTIME							120
#define DEFAULT_UPLOADTIME								360
#define DEFAULT_FIRSTWATERLEVELUPLOADTIME				240
#define DEFAULT_SECWATERLEVELUPLOADTIME					120
#define DEFAULT_THIRDWATERLEVELUPLOADTIME				60
#define DEFAULT_FIRSTWATERLEVELTHERSHOLD				1
#define DEFAULT_SECWATERLEVELTHERSHOLD					5
#define DEFAULT_THIRDWATERLEVELTHERSHOLD				10
#define MAX_WATER_THERSHOLD_NUM							5

typedef struct _tagAlertWaterAlarmInfo
{
	int                 iSize;							//size of struct
	int                 iAlertWaterValue;			    //Alert Water Level Alarm Thershold
	int                 iAlarmLinkTime;					//Alarm Time 1-600s
	int					iSenceID;						//The ID Of Sence
	int                 iRuleID;					    //The ID Of Rule
	int                 iIsMainChannel;					//Whether Main Channel Or Not(0:NO; 1:Yes)
	int					iCheckStand;					//The Source Of Water Level Alarm Data
	int                 iDefaultUploadTime;             //Default Upload Check Time
	int                 iFirstWaterLevelUploadTime;     //The Upload Check Time Of First Water Level Change(min)
	int                 iSecondWaterLevelUploadTime;    //The Upload Check Time Of Second Water Level Change(min)
	int                 iThirdWaterLevelUploadTime;     //The Upload Check Time Of Third Water Level Change(min)
	int                 iFirstWaterLevelThershold;      //First Water Level Thershold(cm/h)
	int                 iSecondWaterLevelThershold;		//Second Water Level Thershold(cm/h)
	int                 iThirdWaterLevelThershold;		//Third Water Level Thershold(cm/h)
	int					iAlgorithmType;					//Algorithm Type
	int                 iWaterNum;                      //Alert Water Level Alarm Thershold num；
	int                 iWaterAlarm[MAX_WATER_THERSHOLD_NUM]; //Alert Water Data;
	int                 iWaterLowValue;                 //
	int                 iWarnHighValue;                 //decline of the water level(superior limit)
	int                 iWarnLowValue;                  //decline of the water level(lower limit)
}AlertWaterAlarmInfo, *pAlertWaterAlarmInfo;

#define MAX_PERIPHREAL_NUM       100
typedef struct tagIrrigationOverInfo
{
	int					iSize;							//Size Of Struct
	int					iType;							//Type Of Reporting Irrigation Info
	int					iLedEnable;						//Whether Overlying Led Or Not
	int 				iOsdEnable;						//Whether Overlying Video Or Not
    int               iSetFlag;                       //User Define Flag,0:Use Default name,1:Define
	char               cTypeName[LEN_32];              //User Define Content
	int               iPeripheralIndex;              //Peripheral No(1-100)
	int               iPeripheralType;               //periphreal type
}IrrigationOverInfo,*pIrrigationOverInfo;

#define   MAX_PERIPHERAL_PARA_COUNTER       4
typedef struct tagPeripheralPara
{
	int					iSize;							//Size Of Struct
	int					iComNo;							//Com Number
	int 				iPeripheralType;				//Peripheral Type
	int 				iPeripheralAddr;				//address code
	int					iParaCounter;					//Parameter Counter
	char 	         	cPeripheralPara[MAX_PERIPHERAL_PARA_COUNTER][LEN_256]; //Peripheral Parameter
}PeripheralPara,*pPeripheralPara;

#define IRRIGATION_TYPE_RAINFALL					1		//rainfall
#define IRRIGATION_TYPE_RAINDURATION				2		//rain duration
#define IRRIGATION_TYPE_WATERLEVEL					3		//water level
#define IRRIGATION_TYPE_SEDIMENT					4		//depth of water
#define IRRIGATION_TYPE_ALERTWATERLEVEL				5		//alert water level
#define IRRIGATION_TYPE_FLOWRATEVALUE				6		//Flow rate value
#define IRRIGATION_TYPE_BATTERYVOLTAGE				7		//Battery voltage value
#define IRRIGATION_TYPE_AIRPRESSURE 				8		//Air pressure
#define IRRIGATION_TYPE_WINDSPEED					9		//Wind speed
#define IRRIGATION_TYPE_WINDDIRECTION				10		//wind direction
#define IRRIGATION_TYPE_TEMPERATURE					11		//Temperature
#define IRRIGATION_TYPE_HUMIDITY					12		//Humidity
#define IRRIGATION_TYPE_ACIDITYANDALKAL				13     //AcidityAndalkal
#define IRRIGATION_TYPE_DISSOLVEOXYGEN				14     //Dissolve Oxygen
#define IRRIGATION_TYPE_OXYREDUCTION				15     //Oxygen Reduction
#define IRRIGATION_TYPE_GPS							16		//GPS
#define IRRIGATION_TYPE_RTX							17		//RTX
#define IRRIGATION_TYPE_TURBIDITY					18		//turbidity
#define IRRIGATION_TYPE_AMMONICA					19		//Ammonica
#define IRRIGATION_TYPE_WATERTEMP					20		//Water temp
#define IRRIGATION_TYPE_CONDUCTIVITY				21		//Conductivity
#define IRRIGATION_TYPE_OXYDEMAND					22		//Oxydemand
#define IRRIGATION_TYPE_NITROGEN					23		//Nitrogen
#define IRRIGATION_TYPE_PHOSPHORUS					24		//Phosphorus
#define IRRIGATION_TYPE_PRESSURE_WATERLEVEL			25     //Pressure water level gauge
#define IRRIGATION_TYPE_WATER_SPEED_FIELD			26     //Velocity field
#define IRRIGATION_TYPE_WATER_LEVELANDFLOW			27    //Flow
#define IRRIGATION_TYPE_CUMULATIVE_FLOW				28    //Cumulative flow
#define IRRIGATION_TYPE_COMBUSTIBLE_GAS				29    //Combustible gas
#define IRRIGATION_TYPE_OXYGEN						30    //Oxygen
#define IRRIGATION_TYPE_CARBON_MONOXIDE				31    //Carbon monoxide
#define IRRIGATION_TYPE_HYDROGEN_SULFIDE			32    //hydrogen sulfide
#define IRRIGATION_TYPE_VOLTAGE						33    //Voltage
#define IRRIGATION_TYPE_UNDER_VOLTAGE				34    //Under Voltage alarm status
#define IRRIGATION_TYPE_FLOAT_GAUGE_LEVEL			35    //Float level gauge
//36.甲醛；37.氨气；38.液位变送器；
#define IRRIGATION_TYPE_FORMALDEHYDE				36		//Formaldehyde
#define IRRIGATION_TYPE_AMMONIA						37		//ammonia
#define IRRIGATION_TYPE_LIQUID_LEVEL_TRANSMITER		38		//liquid level transmitter
#define IRRIGATION_TYPE_RAINFALL_BYTIME				39
#define IRRIGATION_TYPE_GENERATING_POWER			40
#define IRRIGATION_TYPE_LOAD_POWER					41
#define MAX_IRRIGATION_TYPE							42

#define IRRIGATION_PARA_SRC_ALGO				0		//algorithm acquisition
#define IRRIGATION_PARA_SRC_EXDEV				1		//peripheral acquisition

typedef union tagIrrigationPara8
{
	int        iWaterLevel;  //water level
	int        iRtxData;     //RTX Height
	int        iCommonData;
}IrrigationPara8, *pIrrigationPara8;

typedef union tagIrrigationPara9
{
	int        iValid;       //0:invalid; 1:valid
	int        iCruiseNum;   
	int        iCommonData;
}IrrigationPara9, *pIrrigationPara9;
typedef struct tagIrrigationPara
{
	int					iSize;
	int					iType;				//Irrigation type 1:雨量;2:降雨时长;3:水位;4:积水深度;5:超警戒水位值;6:流速;7:电瓶剩余电量;8:气压;9:风速;10:风向;11:温度;12:湿度;13:酸碱度;14:溶解氧;15:氧化还原;16:GPS;17:高程;18:浊度;19:氨氮;20:水温;21:电导率;22:化学需氧量;23:总氮;24:总磷;25:流速场;
	int					iValue;				//Param2 iType(1,3,4,5)-->Unit:mm;  iType(2)-->Unit:minute ;iType(6)-->Unit:mm/s;iType(7,12)-->Unit:%;
											//		 iType(8)-->Unit:hpa; iType(9)-->Unit:m/s; iType(10)-->Unit:angle°;iType(11)-->Unit:degree centigrade ℃;	
	int					iSrc;				//Param3  0:algorithm acquisition; 1:peripheral acquisition;iType = 26,this means waterLevel
	int					iSceneID;			//Param4  Scene ID
	int					iRuleID;			//Param5  Rule ID
	NVS_FILE_TIME		tUploadTime;		//the time of data uploading
	int					iStationNum;		//Param7  the station No.(when the type is flowSpeed or WaterLevel)
	IrrigationPara8		tIrriParam8;		//Param8  when the type is flowspeed,this para represents cruise times;when the type is WaterLevel, it represents if data is valid
	IrrigationPara9		tIrriParam9;		//Param9  when the type is flowspeed,this para represents cruise times;when the type is WaterLevel, it represents if data is valid
	int					iTotalPointNum;		//Param10 (the total detect numbers)
	int					iCurrentPointNum;	//Param11 (the Current detect Number)
	int					iBaseNum;			//Param12 the distance of baseLine(when the type is flowSpeed)
	NVS_FILE_TIME		tRecordTime;		//start time of Record file(when the type is flowSpeed),other type use param13
	char				cFactoryID[LEN_64];	//Param14 Device ID, no more than 64 bytes
	int					iIrriParam6;		//Param6  when iType=26,means 检测区域编号
	int					iIrriParam13;		//Param13 when iType=26,means 像素点终止横坐标
	int					iIrriParam15;		//Param15 when iType=26,means 像素点终止纵坐标
	int					iIrriParam16;		//Param16 when iType=26,means 空间点起始横坐标
	int					iIrriParam17;		//Param17 when iType=26,means 空间点起始纵坐标
	int					iIrriParam18;		//Param18 when iType=26,means 空间点终止横坐标
	int					iIrriParam19;		//Param19 when iType=26,means 空间点终止纵坐标
	unsigned long long	ulLastTimeStamp;	//Param20 when iType=26,means Last frame timestamp
	unsigned long long	ulCurTimeStamp;		//Param21 when iType=26,means Current frame timestamp
	unsigned long long	ulIrriParam22;		//serial number
	int					iIrriParam23;
	int					iIrriParam24;
} IrrigationPara, *pIrrigationPara; 



#define MAX_PERIPHREALTYPE_NUM   8
typedef struct tagPeriphrealParam
{
	int       iSize;             //PeriphrealNum结构体大小
	int       iPeriphrealType;    //外设类型
	int       iPeriphrealIndex;   //外设序号
}PeriphrealParam, *pPeriphrealParam;

typedef struct tagIrriFuncAssemble
{
	int							iSize;            //IrriFuncAssemble 结构体大小
	int							iOsdType;         //水利字符叠加类型 IRRIGATION_TYPE_RAINFALL--IRRIGATION_TYPE_UNDER_VOLTAGE
	int							iPeripheralCount;  //外设个数，范围【1-255】,目前一个字符叠加类型最多支持8个
	PeriphrealParam				tPeriphrealNum[MAX_PERIPHREALTYPE_NUM];
}IrriFuncAssemble, *pIrriFuncAssemble;




#define  MAX_MANCAR_DETECT_AREA_COUNT  32
#define  MAX_MANCAR_DETECT_TRIPAREA_COUNT  12

#define ARI_PUSHMODE_SPEED_FIRST	1  //iPushMode Speed first
#define ARI_PUSHMODE_QUALITY_FIRST	2  //iPushMode Quality first
#define ARI_PUSHMODE_CUSTOM			3  //iPushMode custom
#define ARI_PUSHMODE_TIMING			4  //iPushMode Timing
#define ARI_PUSHMODE_TOUCHLINE		5  //iPushMode Touch line

#define ARI_SNAPMODE_ALL			1  //iSnapMode 1:snap all
#define ARI_SNAPMODE_QUALITY		2  //iSnapMode 2:snap high quality 
#define ARI_SNAPMODE_CUSTOM			3  //iSnapMode 3:custom
typedef struct tagVcaManCarDetectArithmetic
{
 	int				iSize;				//structure size
 	int				iSceneID;			//Scene id(0~15)
	int				iType;				//Structured algorithm model bit：0-Face，1-pedestrian，2-plate，3-motor vehicles，4-Non-motor vehicle
 	int				iSensitiv;			//Sensitivity(0~5)
 	int				iDisplayTarget;		//display target box, 0-not dispaly, 1-dispaly
 	int				iExposureBright;	//exposure light strength (0~255)
 	int				iDisplayRule;		//0-not display 1-display
 	int				iPushMode;			//push mode 0:reserved 1:Speed first 2:Quality first  3:custom 4:timing 5:Touch line	
 	int				iPushLevel;			//push level effect when iPushMode == 3;(0:reserved,1:fast 2:normal 3:slow)   effect when iPushMode == 4;(value is timing time. range 1~255)
 	int				iSnapMode;			//snap mode (0:reserved 1:snap all 2:snap high quality 3:custom)
 	int				iSnapTimes;			//Snap times(1~10)
 	int				iMinFaceSize;		//minimum face size(1~10000 percentage of image width，10000 indicates the width of entire screen)(This field is 0 and will not be processed.)
	int				iMinPlateSize;		//minimum plate size(1~10000 percentage of image width，10000 indicates the width of entire screen)(This field is 0 and will not be processed.)
 	int				iFaceQuality;		//Facial quality [0-100]
	int				iHumanQuality;		//Pedestrian quality  [0-100]
	int				iPlateQuality;		//Plate quality[0-100]
	int				iVehicleQuality;	//Motor vehicles quality[0-100]
	int				iCycleQuality;		//Non-motor vehicle quality[0-100]
	int				iBigbkimgQuality;	//Background image quality[0-100]
	int				iSmallimgQuality;	//Small image quality[0-100]
	int				iPointNum;			//polygon area vertex number(3～32)
 	TPoint			ptArea[MAX_MANCAR_DETECT_AREA_COUNT]; //x:y percentage of image width
 	int				iTripPointNum;		//Number of vertices of the strike line  effect when iPushMode == 5(0 or 2~12)
 	TPoint			ptTripArea[MAX_MANCAR_DETECT_TRIPAREA_COUNT]; //x:y percentage of image width
    int             iExposureType;      //曝光类型	0-保留, 1-长帧, 2-短帧
    int             iExposureEnable;    //曝光使能	0-不使能, 1-使能
	int             iPlateAlarmType;    //车牌告警类型	0-保留, 1-车牌黑名单报警
	int             iDelayPushSpan;    //首张推图延迟时间	单位：毫秒，支持的数值：500,1000,2000
	int             iTimeSpace;    //时间间隔	单位：毫秒，支持的数值：100,200,300，500,1000,2000
}VcaManCarDetectArithmetic, *pVcaManCarDetectArithmetic;

typedef struct tagItsIpdWarningMsg
{
	int		iSize;
	int		iSceneId;
	int		iAreaId;
	char	cRoadName[LEN_64];
	char	cPlate[LEN_32];
	int		iPlateType;
	int		iCarType;
	int		iCapTime;
} ItsIpdWarningMsg, *pItsIpdWarningMsg;

typedef struct tagSelfTest
{
	int				iSize;			//structure size
	int				iType;			//Selftest type 1:complete self-test; 2:hardware self-test; 3:software self-test.
	int				iTestResult;	//Test result 1:success 2:failed
}SelfTest, *pSelfTest;

typedef struct tagNetTestPara
{
	int     		iTestType;		//NetWork Test Type 1:ping
	int				iCardNum;		//Card Number 0，Lan1；1，Lan2 ….7，Lan8; 10000~10000+n:bond0~bondn
	char			cIp[LEN_16];	//Device Ip
	int             iPort;			//Port
	char            cReserve[LEN_64];
}NetTestPara, *pNetTestPara;

typedef struct tagNetTestResult
{
	int     		iTestType;	
	int				iCardNum;
	int   			iReachable;		//0:Reachable   1:unReachable
	int             iDelayTime;		//NetWork Delay Time(ms)
	int 			iLostRate;		//Lose Packet Rate[0, 100]
}NetTestResult, *pNetTestResult;

typedef struct tagLogNum
{
	int				iSize;			//structure size	
	int				iPara1;			//Maximum number of supported logs;
	int             iPara2;			//The current number of logs;
}LogNum, *pLogNum;


#define USERLOGONLOCK_TYPE_MIN			1
#define USERLOGONLOCK_TYPE_MAX			2
typedef struct tagUserLogonLockPara
{
	int				iSize;			//structure size	
	int				iEnable;		//0:reserved; 1:enabled; 2:not enabled
	int             iType;			//1:logon lock-time setting; 2, logon lock-Limit the number of logon
	int				iPara;			//iType=1,lock time;iType=2,Limit the number of logon
}UserLogonLockPara, *pUserLogonLockPara;

#define FACE_LIBSYNC_CHANLIST_COUNT			64

#define FACE_LIBSYNC_STATUS_START			20
#define FACE_LIBSYNC_STATUS_STOP			21
#define FACE_LIBSYNC_STATUS_DELETE			22	//delete sync task
#define FACE_LIBSYNC_STATUS_DELETE_IPCLIB	23	//delete ipc lib

//设置同步前端人脸库
typedef struct tagFaceLibSyncStart
{
	int					iSize;					//structure size
	int					iChanListArraySize;		//需要同步的通道列表个数
	int 				iChanList[FACE_LIBSYNC_CHANLIST_COUNT];	//通道列表
	int					iLibKey;				//人脸库key值
	char				cLibUUID[LEN_UUID];		//人脸库在平台的ID，不为空以本字段为准
	int					iStatus;				//开始状态：20开始，21停止，22删除任务，23 删除前端人脸库
	int					iSame;					//相似度	0-100
}FaceLibSyncStart,*pFaceLibSyncStart;

//获取同步前端人脸库状态
typedef struct tagFaceLibSyncQuery
{
	int					iSize;				//structure size
	int					iChanNo;			//通道号，取值范围据设备类型而定,0x7FFFFFFF代表所有通道
	int					iQueryResultSize;	//when iChanNo=0x7FFFFFFF,iQueryResultSize=1;else iQueryResultSize is NVR's all channel number.
	int					iLibKey;			//人脸库key值
	char				cLibUUID[LEN_UUID];	//人脸库在平台的ID，不为空以本字段为准
}FaceLibSyncQuery,*pFaceLibSyncQuery;

//获取同步前端人脸库状态结果
typedef struct tagFaceLibSyncQueryResult
{
	int					iSize;						//structure size
	int					iChanNo;					//通道号，取值范围据设备类型而定,0x7FFFFFFF代表所有通道
	int					iLibKey;					//人脸库key值
	char				cLibUUID[LEN_UUID];			//人脸库在平台的ID，不为空以本字段为准
	int					iState;						//sync status:0-unsync, 1-synching, 2-sync success, 3-sync failure, 4-to be sync
	int					iProcess;					//Percentage of progress: range:0-100
	int					iSuccNum;					//sync success num		
	int					iFailNum;					//sync failed num
}FaceLibSyncQueryResult,*pFaceLibSyncQueryResult;

#define SINGLE_PRTOCOL_SYNC_RESULT_MAX_NUM 10
//获取同步前端人脸库每个底图的详细结果(同步失败的结果)
typedef struct tagFaceLibSyncResult
{
	int					iSize;						//structure size
	int					iChanNo;					//通道号，取值范围据设备类型而定,0x7FFFFFFF代表所有通道
	int					iLibKey;					//人脸库key值
	char				cLibUUID[LEN_UUID];			//人脸库在平台的ID，不为空以本字段为准
	int 				iFaceKey;					//图片key值， iFaceKey>0
	char				cFaceUUID[LEN_UUID];		//图片在平台对应ID，不为空以本字段为准
	int					iSyncResult;				//Sync result:0预留，1同步成功，2同步失败，
}FaceLibSyncResult,*pFaceLibSyncResult;

typedef struct tagAlarmOutPortPara
{
	int					iSize;
	int					iMode;		//0:normally open, 1:normally close
	int				    iPulseWidth;
	int					iChanNo;	//0x7fffffff Local param
	int					iPortNo;
} AlarmOutPortPara, *pAlarmOutPortPara;

typedef struct tagAlarmInPortEnable
{
	int    iSize;
	int    iChannelNo;
	int    iPortNo;
	int    iEnable;//0-disenable;1-enable
}AlarmInPortEnable, *pAlarmInPortEnable;

typedef struct tagAlarmOutPortEnable
{
	int    iSize;
	int    iChannelNo;
	int    iPortNo;
	int    iEnable; //0-disenable;1-enable
}AlarmOutPortEnable, *pAlarmOutPortEnable;

typedef struct tagpAlarmInPortState
{
	int    iSize;
	int    iChannelNo;
	int    iPortNo;
	int    iState;//1-Alarm ;0-clear alarm    
	char   cAlarmTime[LEN_32]; //alarm time
}AlarmInPortState, *pAlarmInPortState;

typedef struct tagAlarmOutPortState
{
	int    iSize;
	int    iChannelNo;
	int    iPortNo;
	int    iState;//1-Alarm ;0-clear alarm       
}AlarmOutPortState, *pAlarmOutPortState;

typedef struct tagAlarmOutPortDelayTime
{
	int    iSize;
	int    iChannelNo;
	int	   iPortNo;
	int    iClearType;  //0-Manual cancellation;1-Delay cancellation
	int    iDelayTime ;
}AlarmOutPortDelayTime, *pAlarmOutPortDelayTime;

typedef struct tagAlarmInPortPara
{
	int					iSize;
	int					iMode;		//0:normally open, 1:normally close
	int					iType;		//0:normal port alarm, 1:button alarm
	float               fParam;    //Accuracy of tipping bucket rain gauge	
	int					iChanNo;	//0x7fffffff Local param
	int					iPortNo;
} AlarmInPortPara, *pAlarmInPortPara;

#define INVALID_FLAG	0x7fffffff

//以图搜抓拍图
typedef struct tagFaceSearchSnap
{
	int  			    iSize;			//structure size
	int					iChanCount;		//需要搜索的通道个数
	int					iChanSize;		//结构体QueryChanNo的大小，sizeof(QueryChanNo)
	QueryChanNo*		pChanList;		//通道列表，结构体QueryChanNo数组变量
	NVS_FILE_TIME	    tBegTime;		//搜索起始时间
	NVS_FILE_TIME	    tEndTime;		//搜索结束时间
	char			    cPicturePath[LEN_256];	//以图搜抓拍图需要传入的图片名称。（确保本地该图片存在，并且能正常打开）
	int 				iSimilarity;	//以图搜抓拍图相似度
	int 			    iSortMode;		//排序方式：0-按时间排序，1-按相似度排序(0-sort by time 1-sort by similarity)
	int                 iTaskId;		//抠图建模的事务ID，该值由抠图结果返回
}FaceSearchSnap, *pFaceSearchSnap;

//获取搜索进度传入参数结构体
typedef struct tagFaceSearchSnapProcess
{
	int    iSize;						//structure size
	int	   iTaskId;						//抠图建模的事务ID，该值由抠图结果返回
} FaceSearchSnapProcess, *pFaceSearchSnapProcess;

typedef struct tagFaceSearchSnapQuery
{
	int    iSize;			//structure size
	int    iTaskId;			//抠图建模的事务ID，该值由抠图结果返回
	int    iPageSize;		//以图搜抓拍图每次查询的页大小，建议每次20条记录
	int    iPageNo;			//查询的页编号：0，1，2,3……
}FaceSearchSnapQuery, *pFaceSearchSnapQuery;

typedef struct tagFaceSearchSnapResult{
	int					iSize;				//structure size
	int					iChanNo;			//通道号，取值范围据设备类型而定,0x7FFFFFFF代表所有通道
	int					iTotal;				//搜索到的记录的总个数
	int					iCurPageCount;		//本次获取的个数，页大小
	int					iItemIndex;			//当前页编号，根据页大小传入页编号。比如总共100条记录，每次取20条，页编号依次为0,1,2,3,4
	NVS_FILE_TIME		tBegTime;			//记录开始时间
	NVS_FILE_TIME		tEndTime;			//记录结束时间
	int  				iAge;				//记录年龄值
	int                 iSex;				//记录性别：1-男，2-女，3-未知
	int					iNation;			//记录民族：1-汉族，2-少数民族
	int					iWearGlasses;		//表示戴眼镜：0-预留，1-佩戴，2-未佩戴
	int					iWearMask;			//表示戴口罩：0-预留，1-佩戴，2-未佩戴
	int					iSimilarity;		//表示相似度，范围0-100
	VcaFileAttr			tPicSnap;			//抓拍图属性
	VcaFileAttr			tPicNeg;			//人脸底图属性
	char				cLibUUID[LEN_UUID];	//人脸库在平台的ID
	char				cFaceUUID[LEN_UUID];//图片在平台对应ID
	char				cName[LEN_64];		//姓名
}FaceSearchSnapResult, *pFaceSearchSnapResult;

#define TYPE_SNAP_AGRIBANK    20000
typedef struct tagSnapInfo
{
	int         iSize;
	int         iQValue;
	char        cLocalFileName[LEN_256];
}SnapInfo, *pSnapInfo;

typedef struct tagSnapInfoOut
{
	int         iSize;
	int         iQValue;
	char        cRemoteFileName[LEN_64];
}SnapInfoOut, *pSnapInfoOut;

#define MAX_PIC_TYPE_NUM   2
typedef struct tagPicStreamUploadParam
{
	int         iSize;			
	int         iSceneId;		//range:0~15
	int         iRuleNo;		//range:0～7
	int         iPicType;		//Picture type: 0-Background big picture, 1-Small picture
	int         iSnapEnable;	//Send enable:0-not upload, 1-upload
	int         iIsOsd;			//Overlay information: 0-not stack, 1-stack.When iPicType=1,this parameter is invalid.
	int         iQpvalue;		//Snap picture quality range:1-100
	int			iFaceFrameEnable;//Overlay face frame: 0-not stack, 1-stack.When iPicType=1,this parameter is invalid.
}PicStreamUploadParam, *pPicStreamUploadParam;

typedef struct tagITSLatestBkPlate
{
	long long lLicenseID;
	char      cLicense[LEN_32];
}ITSLatestBkPlate, *pITSLatestBkPlate;

typedef struct tagITSAlarmInfo
{
	NVS_FILE_TIME tTime;
	char          cLicense[LEN_32];
	char          cAddressName[LEN_128];
	char          cAreaName[LEN_128];
	char          cAlarmName[LEN_128];
}ITSAlarmInfo, *pITSAlarmInfo;

typedef struct tagHumanDetectArithmetic
{
	int				iSize;			
	int				iSceneID;			//Scene id(0~15)
	int				iRuleNo;			//0-7
	int				iSnapEnable;		//0-disenable,1-enabele
	int				iDisplayTarget;		//display target box, 0-not dispaly, 1-dispaly
	int				iMinSizeEx;			//minimum face size(0~10000 percentage of image width，10000 indicates the width of entire screen)
	int				iMaxSizeEx;			//maximum face size(0~10000 percentage of image width,10000 indicates the width of entire screen)
}HumanDetectArithmetic, *pHumanDetectArithmetic;

typedef struct tagSIPEncrypt
{
	int     iMode;
}SIPEncrypt,*pSIPEncrypt;

typedef struct tagSIPPublicKey
{
	char sPublicKey[LEN_256];
}SIPPublicKey,*pSIPPublicKey;

typedef struct __tagDormancyWork
{
	int iSize;
	int iBeginHour;
	int iBeginMinute;
	int iEndHour;
	int iEndMinute;
	int iWorkType;  //In bits,1-dormancy, 0-non-dormancy:Bit 0-white light, Bit 1-infrared light, Bit 2-laser, Bit 3-fan, Bit 4-speaker, Bit 5-wiper, Bit 6-motor H, Bit 7-motor V
    int iEnable;   //Whether Timing Sleep is Enabled: 0 Enabled, 1 Not Enabled
}TDormancyWork, *pTDormancyWork;

typedef struct __tagDormancySchedule
{	
	int iSize;
	int iWeekDay;  //Sunday - Saturday : 0-6
	TDormancyWork tWork[MAX_SCHEDULE];
}TDormancySchedule, *pTDormancySchedule;

typedef struct __tagDormancyState
{
	int iSize;
	int iEnable;  //whether the device is in Dormancy state:In bits,1-dormancy, 0-non-dormancy:Bit 0-white light, Bit 1-infrared light, Bit 2-laser, Bit 3-fan, Bit 4-speaker, Bit 5-wiper, Bit 6-motor H, Bit 7-motor V
}TDormancyState, *pTDormancyState;

typedef struct __tagNetReduceFlowCtrl
{
	int iSize;
	int iEnable;//Bit 0 - Information report, Bit1 - picture return; 0 - enabled, 1 - no enabled
}TNetReduceFlowCtrl, *pNetReduceFlowCtrl;

typedef struct __tagDormancySet
{
	int iSize;
	int iEnable;//whether the device is in Dormancy state:In bits,1-dormancy, 0-non-dormancy:Bit 0-white light, Bit 1-infrared light, Bit 2-laser, Bit 3-fan, Bit 4-speaker, Bit 5-wiper, Bit 6-motor H, Bit 7-motor V
	int iResult;//0-succ,1-failed,2-over times
}DormancySet, *pDormancySet;

#define FILTER_CONDITION_MAX_NUM    64		//max number of filter conditions
#define FILTER_CONDITION_LEN		16		//Length of a filter condition
typedef struct tagITSIllegalParkFilterPlate
{
	int  iSize;		
	int  iSceneId;		//Scene ID,0-15
	int  iAreaNo;		//Area No,0-7
	int  iEnable;		//License plate filtering enabled,0: not enable,1:enable
	int  iFilterNum;	//number of filter conditions
	char cFilterCondition[FILTER_CONDITION_MAX_NUM][FILTER_CONDITION_LEN]; //Filter field
}ITSIllegalParkFilterPlate, *pITSIllegalParkFilterPlate;

#define PARKCARNUM_MAX_LEN          32
typedef struct tagITSParkCarNum
{
	int  iSize;
	int  iChannel;
	char cCarNum[PARKCARNUM_MAX_LEN];
	int  iParkStatus;   //0:no changes; 1:start(first report); 2:end(car leaves or record finished).
}ITSParkCarNum, *pITSParkCarNum;

typedef struct __tagVirtualGaugeCalib
{
	int iSize;       
	int iChannel;		 
	int	iScene;	       //scene num:0-15
	int	iType;	       //0:base water point, 1:Ordinary point
	int	iNum;	       //iType=0,iNum=0;iType=1,iNum=0-30
	int	iPosX;	       //per ten thousand (0-10000)
	int	iPosY;	       //per ten thousand (0-10000)
	int iMarkPosX;     //range:0-10000
	int iMarkPosY;     //range:0-10000
}VirtualGaugeCalib, *pVirtualGaugeCalib;

#define MAX_VCA_PEPT_POINT_NUM			 8
typedef struct tagVCAPEPT
{
	VCARule				tRule;					//Rules General Parameters
	vca_TDisplayParam	tDisplayParam;			//Display The Parameter Settings
	int					iDisplayTarget;			//Display Target, 0-Not Dispaly, 1-Dispaly
	int					iMaxSize;				//Max Target Size(Reserved:Percentage of image width)
	int					iMinSize;				//Min Target Size(Reserved:Percentage of image width)
	int					iSensitivity;			//Sensitivity
	int					iModelType;				//bit0: Zone Invasion bit1: Exception residency
	int					iTargetType;			//Target Type,bit1:Car bit2:SUV bit3:Pickup truck bit4:Tanker bit5:Van van bit6:Big truck bit7:Forklift bit8:Excavator bit9:Engineering bit10:Two-wheeler bit11:Tricycle bit31:Other types
	int 				iTimeThreshold;			//Resident Alarm Time
	int					iPointNum;				//Polygon Area Vertex Number
	vca_TPoint     		stPoints[MAX_VCA_PEPT_POINT_NUM];	//Vertex Coordinates		
}VCAPEPT, *pVCAPEPT;

#define MAX_CHEFHATDETECT_POINT_NUM			8
typedef struct tagVCAChefHatDetect
{
	int					iSceneID;				//scene ID(0~31)
	int					iRuleID;				//rule ID(0~15)
	int					iSensitivity;			//Sensitivity 0~100
	int					iPushMode;				//0: Reserved, 1: fastest, 2: best
	int					iPointNum;				//Polygon Area Vertex Number
	vca_TPoint     	stPoints[MAX_CHEFHATDETECT_POINT_NUM]; //Vertex Coordinates		
}VCAChefHatDetect, *pVCAChefHatDetect;

#define MAX_CHEFMASKDETECT_POINT_NUM		8
typedef struct tagVCAChefMaskDetect
{
	int					iSceneID;				//scene ID(0~31)
	int					iRuleID;				//rule ID(0~15)
	int					iSensitivity;			//Sensitivity 0~100
	int					iPushMode;				//0: Reserved, 1: fastest, 2: best
	int					iPointNum;				//Polygon Area point Number
	vca_TPoint     	stPoints[MAX_CHEFMASKDETECT_POINT_NUM]; //Vertex Coordinates		
}VCAChefMaskDetect, *pVCAChefMaskDetect;

#define CHEFDETECT_TYPE_CLOTHES			0	//chef's clothes
#define MAX_CHEFDETECT_TYPE				1	//max chef detect type
#define CHEFDETECT_PUSHPICMODE_RESERVE	0	//push graph strategy reserve
#define CHEFDETECT_PUSHPICMODE_FAST		1	//push graph strategy fast
#define CHEFDETECT_PUSHPICMODE_BEST		2	//push graph strategy best
#define MAX_CHEFDETECT_POINT_COUNT		8	//max number of vertices in polygon area 
typedef struct tagVCAChefDetect
{
	int					iType;					//input para:0: to detect chef's clothes
	int					iSceneID;				//input para:scene ID(0~31)
	int					iRuleID;				//input para:rule ID(0~15)
	int					iSensitivity;			//Sensitivity 0~100
	int					iPushMode;				//0: Reserved, 1: fastest, 2: best
	int					iPointCount;			//Polygon Area point count
	vca_TPoint     		tPoints[MAX_CHEFDETECT_POINT_COUNT]; //Vertex Coordinates		
} VCAChefDetect, *pVCAChefDetect;

typedef struct tagVCASenceSnap
{
	int		iSnapEnable;						//Scene Snap,  1-enable 0-not enable
}VCASenceSnap, *pVCASenceSnap;

typedef struct __tagVirtualGaugeCalibResult
{
	int iSize;
	int iChannel;		
	int	iScene;	       //scene num:0-15
	int	iType;	       //0:base water point, 1:Ordinary point
	int	iNum;	       //iType=0,iNum=0;iType=1,iNum=0-30
	int	iPosX;	       //per ten thousand (0-10000)
	int	iPosY;	       //per ten thousand (0-10000)
	int iMarkPosX;     //range: 0-10000
	int iMarkPosY;     //range: 0-10000
	int iDistance;
	int iAltitude;     //RTK data
	int iTiltAngle;    //Angle
	int iWaterLevel;   //Water Level,iType = 0  valid
	int iRiverWidth;   //the River of Width iType = 0  valid
	int iResult;       //Calib Result,0:success, -1:failed
}VirtualGaugeCalibResult, *pVirtualGaugeCalibResult;


typedef struct __tagVirtualGaugeParam
{
	int  iSize;
	int  iScene;            //scene num:0-15
	int  iType;             //0:base water point, 1:Ordinary point
	int  iSum;              //total num
	int  iNum;              
	int  iPosX;             //per ten thousand (0-10000)
	int  iPosY;             //per ten thousand (0-10000)
	int  iMarkPosX;         //range:0-10000
	int  iMarkPosY;         //range:0-10000
	int  iDistance;
	int  iAltitude;         //RTK data
	int  iTitleAngle;        //Angle
	int  iWaterLevel;       //Water Level,iType = 0  valid
}VirtualGaugeParam, *pVirtualGaugeParam;


typedef struct __tagUploadStateInfo
{
	int      iSize;
	int      iStation;
}UploadStateInfo, *pUploadStateInfo;

typedef struct __tagSetQueryFlow
{
	int               iSize;
	int               iChn;
	int               iPageNo;        //page num
	int               iPageSize;      //info num in every page
    NVS_FILE_TIME     tStartTime;     //query from time
	NVS_FILE_TIME     tEndTime;       //query end time
}SetQueryFlow, *pSetQueryFlow;

typedef struct __tagSetQueryFlowEmbed
{
	int               iSize;
	int               iChn;
	int               iPageNo;
	int               iPageSize;
	int               iStartTime;
	int               iEndTime;
}SetQueryFlowEmbed, *pSetQueryFlowEmbed;

typedef struct __tagQueryFlowInfo
{
	int                iSize;
	int                iTotal;	       //total info num
	int  	           iPageNo;	       //current page no
	int                iPageSize;	       //current info num in current page
	int    	           iIndex;           //info index
	int                iPlace;           //Station number
	int                iScene;           //Scene num
	unsigned int       iGroup;           
	NVS_FILE_TIME      tRecordTime;     //Record time
	int                iWaterSpeed;	   //Water Speed
	int                iWaterLevel;	   //Water Level
	int                iDistance;	
	int                iSource;			//0 Algorithm Get; 1 Peripheral Get
	int                iRuleID;			//0~7
	int		           iDetectNum;        //Detection points  1~30
	int                iCurrentNum;		//Current nod number
	NVS_FILE_TIME      tStartTime;     //Video start time
}QueryFlowInfo, *pQueryFlowInfo;

typedef struct __tagQueryFlowInfoEmbed
{
	int                iSize;
	int                iTotal;	       //total info num
	int  	           iPageNo;	       //current page no
	int                iPageSize;	       //current info num in current page
	int    	           iIndex;           //info index
	int                iPlace;           //Station number
	int                iScene;           //Scene num
	unsigned int       iGroup;           
	int                iRecordTime;     //Record time
	int                iWaterSpeed;	   //Water Speed
	int                iWaterLevel;	   //Water Level
	int                iDistance;	
	int                iSource;			//0 Algorithm Get; 1 Peripheral Get
	int                iRuleID;			//0~7
	int		           iDetectNum;        //Detection points  1~30
	int                iCurrentNum;		//Current nod number
	int                iStartTime;     //Video start time
}QueryFlowInfoEmbed, *pQueryFlowInfoEmbed;

typedef struct __tagAutoJust
{
	int					iSize;
	int					iChanNo; //channel no
	int                 iFieldOfVision;	//0-保留 1-大 2-小
}AutoJust, *pAutoJust;

typedef struct __tagSceneHeight
{
	int                 iSize;
	int                 iChannel;
}SceneHeight, *pSceneHeight;

typedef struct __tagSceneHeightResult
{
	int                 iSize;
	int                 iChannel;
	int                 iResult;
}SceneHeightResult, *pSceneHeightResult;

typedef struct _tagSinglePic
{
	int                 iSize;
	int                 iVoDevId; //1-VGA/HDMI0, 17-HDMI1(bt1120), 33-CVBS,49-VC,50-VC1（H264） ,Default:VC
	int                 iAct;     //1:Entry SinglePic 2:Exit SinglePic
}SinglePic, *pSinglePic;



typedef struct tagGpsCoordinate
{
	int				iDirection;
	int				iDegree;
	int				iMinute;
	int				iSecond;
}GpsCoordinate, *pGpsCoordinate;

typedef struct tagGpsPointInfo
{
	GpsCoordinate		tLongitudeInfo;	//Longitude iDirection:(0-e, 1-w), degrees (0-180), minutes (0-59), seconds (0-59.99*100)
	GpsCoordinate		tLatitudeInfo;	//Latitude iDirection:(0-s, 1-n), degrees (0-180), minutes (0-59), seconds (0-59.99*100)
}GpsPointInfo, *pGpsPointInfo;

#define MAX_GPS_AREA_NUM			 128
#define MAX_GPS_POINT_NUM			 8
typedef struct tagGpsDangerArea
{
	int					iSize;
	int					iChanNo;	//channel no
	int					iAreaId;	//Area Id,range:0-127
	int					iPointNum;	//Number of vertices in the region,0 indicates the removal of the area.
	GpsPointInfo		tPointInfo[MAX_GPS_POINT_NUM];	//Point coordinates
}GpsDangerArea, *pGpsDangerArea;

#define MAX_POLYGON_POINT_NUM		 16
typedef struct tagNavigationShipDetection
{
	int					iSize;
	int					iChanNo;		//channel no
	int					iSceneId;		//range:0~31
	int					iRuleNo;		//range:0～15
	int					iSensitiv;		//sensitive:range:0~100
	int					iPointNum;		//Number of vertices in a polygon area,rang:3～8
	TPoint				tPoint[MAX_POLYGON_POINT_NUM];	//Point coordinates
}NavigationShipDetection, *pNavigationShipDetection;

typedef struct tagLocate3DPrediction
{
	int					iSize;
	int					iChanNo;		//channel no
	int					iTime;			//Prediction time: unit/s 1-30s
	int					iMultiple;		//Area magnification 1-5
}Locate3DPrediction, *pLocate3DPrediction;



#define MAX_CRUISE_ADD_COUNT  2
#define MAX_AREA_TYPE    2
#define SET_AREA         1
#define CALL_AREA        2
#define DELETE_AREA      3
typedef struct __tagDetectAreaPoseX
{
	int                 iSize;
	int                 iSceneId;  //Scene Num:0-15
	int                 iCruiseAddMode; // 0:Auto;1:Manual
	int                 iAreaNum;  //0-127
	int                 iOperationType;//1-Set Area 2-Call Area 3-Detect Area
	int                 iAreaType;//0-流速 1-水位水尺
}DetectAreaPoseX, *pDetectAreaPoseX;

typedef struct __tagDetectAreaPoseXResult
{
	int                 iSize;
	int                 iResult;  //0:success, 1:fail
	int                 iSceneID;
	int                 iCruiseAddMode; //0:Auto;1:Manual
	int                 iOperationType;////1-Set Area 2-Call Area 3-Detect Area
	int                 iAreaNum;//0-127
    int                 iPtzP;
	int                 iPtzT;
	int                 iPtzZ;
	int                 iResultInfo;	//If the iresult field is not 0, it is valid to indicate the error information of the corresponding error code; if iresult = 3, it is the current diagonal distance in meters
    int                 iAreaType;//0-流速 1-水位水尺 2-零点预置位
	int                 iAngleValue;//倾角仪角度x10000，单位是°，范围0—360
}DetectAreaPoseXResult, *pDetectAreaPoseXResult;

typedef struct __tagDetectAreaParaX
{
	int                 iSize;
	int                 iSceneId;  //Scene Num:0-15
	int                 iCruiseAddMode; //0:Auto;1:Manual
	int                 iAreaNum;  //0-127
	int                 iState;//0:unset, 1;set
	int                 iPtzP;
	int                 iPtzT;
	int                 iPtzZ;
	int                 iAreaType;//0-流速 1-水位水尺 2-零点预置位
	int                 iAngleValue;//倾角仪角度x10000，单位是°，范围0—360
}DetectAreaParaX, *pDetectAreaParaX;

typedef struct tagCallParamResult
{
	int		iBufSize;					//Call gengeral parameters structure size
	int		iType;						//0-Call Scene ID；1-Call privacy shelter location 2- call vca scene 3 - enable intelligent scene quickly 4-quickly start warning scene, 5-fire detection shielding area, 6-smoke detection shielding area, 7-temperature difference detection shielding area
	int		iValue;						//Scene ID range：0~15； privacy shelter location range：0~23
	int		iSceneType;					//0-vca 1-alert
	int     iResult;                    //0:success;other:failed
}CallParamResult, *pCallParamResult;

typedef struct tagHolidayScheTime
{
	int     iSize;
	int     iStartHour;
	int     iStartMin;
	int     iEndHour;
	int     iEndMin;
}HolidayScheTime, *pHolidayScheTime;

#define MAX_HOLIDAY_PLAN_ID   8
#define MAX_HOLIDAY_PARAM_ID  32
typedef struct tagHolidaySche
{
	int               iSize;
	int               iPlanID; //planid:0-7
	int               iEnable; //0:not set Sche, 1:SetSchedule
	char              pcPlanName[LEN_32];
	HolidayScheTime   tScheDule;
}HolidaySche, *pHolidaySche;

typedef struct tagSetPlanByDate
{
	int              iYear;
	int              iMonth;
	int              iDay;
}SetPlanByDate, *pSetPlanByDate;

typedef struct tagSetPlanByWeek
{
	int              iMonthofYear;
	int              iWeekofMonth;
	int              iDayofWeek;
}SetPlanByWeek, *pSetPlanByWeek;

typedef struct tagSetPlanByMonth
{
	int            iMonth;
	int            iDay;
}SetPlanByMonth, *pSetPlanByMonth;

typedef union tagPlanTime
{
	SetPlanByDate   tSetByDate;
	SetPlanByWeek   tSetByWeek;
    SetPlanByMonth  tSetByMonth;
	int             iCommonInt[LEN_4];
}PlanTime, *pPlanTime;

#define SET_HOLIDAY_BYDATE    0
#define SET_HOLIDAY_BYWEEK    1
#define SET_HOLIDAY_BYMONTH   2
#define SET_MAX_HOLIDAY_MODE  3
typedef struct tagHolidayPlan
{
	int               iSize;
	int               iHolidayID;
	int               iEnable;
	int               iPlanID;
	int               iSetMode;   ////Time format,0:By date (year month day) 1:By week(month  week) 2:By month(Month day)
	char              pcHolidayName[LEN_32];
	PlanTime          tStartTime;
	PlanTime          tStopTime;
}HolidayPlan, *pHolidayPlan;

typedef struct tagChannelSrc
{
	 int			iChnDst;
	 int			iSrcDst;
	 int			iEnable;
}ChannelSrc, *pChannelSrc;

typedef struct tagTrafficFlowQuery
{
	int            iSize;
	int            iChn;
	int            iPageNo;
	int            iPageSize;
	NVS_FILE_TIME  tStartTime;
	NVS_FILE_TIME  tEndTime;
}TrafficFlowQuery, *pTrafficFlowQuery;

typedef struct tagCarTypeNum
{
	int            iSize;
	int            iCarType;
	int            iCarNum;
}CarTypeNum, *pCarTypeNum;

typedef struct tagTrafficFlowInfo
{
	int            iSize;
	int            iChn;           //chn Number
	int            iTotalNum;      //total info numbers
	int            iPageNo;        //current page No
	int            iPageSize;      //info numbers in this pageNo
	int            iIndex;         //info No
	int            iLaneNo;        //0-5
	char           pcRoadName[LEN_64]; 
	NVS_FILE_TIME  tStartTime;
	NVS_FILE_TIME  tEndTime;
	int            iFlow;
	int            iHoldRate;      //percent
	int            iSpeed;         //Km/h
	int            iDistance;      //Second
	int            iCarTypeTotal;  
	CarTypeNum     tCarTypeNum[LEN_32];//carType1:num1,......carTypen:numN
	int            iCarQueueLength;         //mm
	int            iHeadDistance;           //mm
	int            iRoomRate;               //Spacing percent
	int            iRunState;               //state:0:Unknown 1:stop 2:slow 3:No car 4:fluent
	int            iSceneID;       //0~31
}TrafficFlowInfo, *pTrafficFlowInfo;

typedef struct tagTencentInfo
{
	int   iSize;
	char  pcURL[LEN_64];         //url address
	char  pcID[LEN_64];          //ID
	char  pcKey[LEN_64];
}TencentInfo, *pTencentInfo;

#define MAX_POLYGON_AREA_POINT_NUM		 8
typedef struct tagGranaryVehicleDetect
{
	int					iSize;
	int					iChanNo;		//channel no
	int					iSceneId;		//range:0~31
	int					iRuleNo;		//range:0～15
	int					iSensitiv;		//sensitive:range:0~100
	int					iPointNum;		//Number of vertices in a polygon area,rang:3～8
	TPoint				tPoint[MAX_POLYGON_AREA_POINT_NUM];	//Point coordinates
}GranaryVehicleDetect, *pGranaryVehicleDetect;

typedef struct tagGranaryVehicleDelay
{
	int					iSize;
	int					iChanNo;		//channel no
	int					iTime;			//unit:s 3D positioning operation is carried out after the vehicle's stationary time reaches the set time
	int					iPreset;		//Preset num
}GranaryVehicleDelay, *pGranaryVehicleDelay;

typedef struct tagModifyFrontPsd
{
	int           iSize;
	char          pcUserName[LEN_16];
	char          pcOldPassword[LEN_16];
	char          pcNewPassword[LEN_16];
}ModifyFrontPsd, *pModifyFrontPsd;

#define MAX_VCA_STRANDED_POINT_NUM			 10
typedef struct tagVCAStranded
{
	int					iDevType;				//0-IPC，1-NVR
	VCARule				tRule;					//Rules General Parameters
	vca_TDisplayParam	tDisplayParam;			//Display The Parameter Settings
	int					iDisplayTarget;			//Display Target, 0-Not Dispaly, 1-Dispaly
	int					iMaxSize;				//Max Target Size(Reserved:Percentage of image width)
	int					iMinSize;				//Min Target Size(Reserved:Percentage of image width)
	int					iSensitivity;			//Sensitivity
	int					iAlarmTime;				//Alarm Time
	int					iPointNum;				//Polygon Area Vertex Number
	vca_TPoint     		stPoints[MAX_VCA_STRANDED_POINT_NUM];	//Vertex Coordinates		
}VCAStranded, *pVCAStranded;

typedef struct tagVCAAlone
{
	VCACommonPara		tVCACommonPara;
	int					iAlarmTime;				//Alarm Time	
}VCAAlone, *pVCAAlone;

#define MAX_VCA_DELIVERGOODS_POINT_NUM			 10
typedef struct tagVCADeliverGoods
{
	int					iDevType;				//0-IPC，1-NVR
	VCARule				tRule;					//Rules General Parameters
	vca_TDisplayParam	tDisplayParam;			//Display The Parameter Settings
	int					iDisplayTarget;			//Display Target, 0-Not Dispaly, 1-Dispaly
	int					iMaxSize;				//Max Target Size(Reserved:Percentage of image width)
	int					iMinSize;				//Min Target Size(Reserved:Percentage of image width)
	int					iSensitivity;			//Sensitivity
	int					iPointNum;				//Polygon Area Vertex Number
	vca_TPoint     		stPoints[MAX_VCA_DELIVERGOODS_POINT_NUM];	//Vertex Coordinates		
}VCADeliverGoods, *pVCADeliverGoods;

typedef struct tagVCATops
{
	int					iChanNo;
	int					iDevType;				//0-IPC，1-NVR
	int					iSceneID;				//
	int					iVcaType;
	int					iTops;					//Reference value of calculation force occupied by this algorithm, range 1-100
	int					iMaxCnt;				//The maximum number of this algorithm to open, range 1-100
	int					iUsedCnt;				//The number of this algorithm has been opened, range 0-100
}VCATops, *pVCATops;


typedef struct tagShdbRunState
{
	int					iSize;
	int					iRunState;				//Running state, 0: not running; 1: running 
}ShdbRunState, *pShdbRunState;


#define MAX_SHDB_CHAN_NUM   1024 
typedef struct tagShdbAlarmPic
{
	int					iSize;
	int					iEnable;				//Alarm linkage enable, 0: not enable; 1: Enable 
	int					iPreTm;					//Pre shooting time, settable: 0, 1, 2, 3, 4, 5, 10, 20, 30, 40, 50, 60s 
	int					iDelayTm;				//Delay time, settable: 0, 1, 2, 3, 4, 5, 10, 20, 30, 40, 50, 60s 
	int					iIntervalTm;			//Time interval, settable: 3,4,5,10,20,30,40,50,60s 
	int					iChanCount;				//channel number
	int					iChanList[MAX_SHDB_CHAN_NUM];
}ShdbAlarmPic, *pShdbAlarmPic;


#define MAX_SHDB_TIMESNAPGROUPS_NUM   4
#define CUR_SHDB_TIMESNAPGROUP_NUM    2
typedef struct tagShdbTimeSnapGroups
{
	int					iTmEnable;				//Point in time enable, 0: not enable, 1: Enable 
	int					iPicCnt;				//Capture times, temporarily fixed to 1 
	int					iBeginTm;				//Start time unit s 
	int					iEndTm;					//End time in seconds 
	int					iChanCount;				//channel number
	int					iChanList[MAX_SHDB_CHAN_NUM];
}ShdbTimeSnapGroups, *pShdbTimeSnapGroups;

typedef struct tagShdbTimeSnap
{
	int					iSize;
	int					iEnable;								//Daily Photo enabled, 0: not enabled; 1: enabled 
	int					iTmSnapGrpNum;							//Number of time point capture groups, maximum 4 groups, currently only 2 groups are open 
	ShdbTimeSnapGroups  tParam[MAX_SHDB_TIMESNAPGROUPS_NUM];	//Time point capture group number structure 
}ShdbTimeSnap, *pShdbTimeSnap;



typedef struct tagQueryShdbApprepairSys
{
	int					iSize;
	int					iRepairName;		    //Name of repair reporting system, 0: building intercom; 1: perimeter alarm; 2: networking alarm; 3: local alarm; 4: video security; 5: access control; 6: electronic patrol system; 7: other security systems; 
	int					iRepairType;		    //Repair type: 0: front end; 1: terminal; 2: system;
}QueryShdbApprepairSys, *pQueryShdbApprepairSys;

typedef struct tagShdbApprepairSysResult
{
	int					iSize;
	int					iRepairName;		   //Name of repair reporting system, 0: building intercom; 1: perimeter alarm; 2: networking alarm; 3: local alarm; 4: video security; 5: access control; 6: electronic patrol system; 7: other security systems; 
	int					iRepairType;           //Repair type: 0: front end; 1: terminal; 2: system;
	int					iResult;               //Execution result, 0: success; - 1: failure 
}ShdbApprepairSysResult, *pShdbApprepairSysResult;



typedef struct tagQueryShdbServiceType 
{
	int					iSize;
	int					iMaintainType;		  //Maintenance type, 0: normal; 1: exception repaired; 2: exception not repaired; 3: not selected 
	int					iRepairType;          //Repair type, 0: normal; 1: abnormal repaired; 2: abnormal not repaired; 3: not selected 
}QueryShdbServiceType, *pQueryShdbServiceType;

typedef struct tagShdbServiceTypeResult
{
	int					iSize;
	int					iMaintainType;		 //Maintenance type, 0: normal; 1: exception repaired; 2: exception not repaired; 3: not selected 
	int					iRepairType;		 //Repair type, 0: normal; 1: abnormal repaired; 2: abnormal not repaired; 3: not selected 
	int					iResult;			 //Execution result, 0: success; - 1: failure 
}ShdbServiceTypeResult, *pShdbServiceTypeResult;



typedef struct tagQueryShdbTestMainTain
{
	int					iSize;
	int					iOperType;			 //Operation type: 0: upload test picture; 1: upload maintenance picture
	int					iChanCount;			 //channel number
	int					iChanSize;			 //struct ChannelList size
	ChannelList*		pChanList;			 //channel list
}QueryShdbTestMainTain, *pQueryShdbTestMainTain;

typedef struct tagShdbTestMainTainResult
{
	int					iSize;
	int					iOperType;			 //Operation type: 0: upload test picture; 1: upload maintenance picture
	int					iChanCount;          //channel number
	int					iChanSize;			 //struct QueryChanNo size
	ChannelList*		pChanList;			 //channel list
	int					iResult;			 //Execution result, 0: success; - 1: failure
}ShdbTestMainTainResult, *pShdbTestMainTainResult;


#define  MAX_SHDB_POLICELD_NUM    32
#define  MAX_SHDB_PASSWD_NUM      32


typedef struct tagQueryShdbCheckManage
{
	int					iSize;
	char				cPoliceId[MAX_SHDB_POLICELD_NUM];	//Officer, 32 Max 
	char				cPasswd[MAX_SHDB_PASSWD_NUM];		//Password, up to 32 bits 
	int					iChanCount;							//channel number
	int					iChanSize;							//struct ChannelList size
	ChannelList*		pChanList;							//channel list
}QueryShdbCheckManage, *pQueryShdbCheckManage;

typedef struct tagShdbCheckManageResult
{
	int					iSize;
	char				cPoliceId[MAX_SHDB_POLICELD_NUM];   //Officer, 32 Max 
	char				cPasswd[MAX_SHDB_PASSWD_NUM];		//Password, up to 32 bits 
	int					iChanCount;							//channel number
	int					iChanSize;							//struct ChannelList size
	ChannelList*		pChanList;							//channel list
	int					iResult;							//Execution result, 0: success; - 1: failure
}ShdbCheckManageResult, *pShdbCheckManageResult;

typedef struct tagHsjjFocusstate
{
	int						iSize;
	int						iRunState;							//0：未聚焦完成；1：聚焦完成
}HsjjFocusstate, *pHsjjFocusstate;

typedef struct tagAlmLoopDetec
{
	int                 iSize;        
	int                 iChannelNo;                   //channel number，0~N-1：ipc parameters of corresponding IPC channel； 
	                                                  //0x7fffffff：NVR local parameters
	int                 iPortNo;                      //port number
	int                 iEnable;                      //whether to open：0, close；1, open
} AlmLoopDetec, *pAlmLoopDetec;

typedef struct tagIdentificationType
{
	int                 iSize;
	int                 iChannelNo;                    //channel number，0~N-1：ipc parameters of corresponding IPC channel；
	                                                   //0x7fffffff：NVR local parameters
	int                 iProtocol;		               //protocol type, 0：rtsp，1：http
	int                 ibasicConfig;	               //basic auth config, 0：forbid ，1：allow
	int                 iDigestlConfig;                //digest认证配置,  0：forbid ，1：allow
}IdentificationType, *pIdentificationType;

typedef struct tagDevAutoTimingParam
{
	int					iSize;
	int					iType;				//Timing type, 0-never, 1-year cycle, 2-month cycle, 3-week, 4-day 
	int					iWeekDay;			//Starting time: 1-7 from Monday to Sunday, valid when itype is 3 
	int					iMonth;				//Month, value range is 1-12, valid when itype = 1 
	int					iDay;				//Day, value range is 1-31, valid when itype = 1,2
	int					iHour; 				//Hour,value range is 0-23,valid When itype = 1,2,3,4
	int					iMinute;			//Minute,value range is 0-23,valid When itype = 1,2,3,4
	int					iSecond;			//Second,value range is 0-23,valid When itype = 1,2,3,4
}DevAutoTimingParam, *pDevAutoTimingParam;

typedef struct __tagIpFilter
{
	int iSize;
	char cIp[LENGTH_IPV4];
	char cSubMask[LENGTH_SUB_MASK];
	int iFilterType;								//Filter typr:0,Disable IP permission qualification;1,IP access is disabled;2,Allow IP access
	int iIpNum;										//Filter IP number,the maximum support 16 different IP addresses
	char cFilterIp[MAX_IP_FILTER_NUM][LENGTH_IPV4];	//Network address string, such as：pcFilterIp[0]=“192.168.1.10”
}TIpFilter, * pTIpFilter;

typedef struct __tagIpv6Filter
{
	int iSize;
	int iIpNum;												//Filter IP number,the maximum support 16 different IP addresses
	int iFilterType;										//Filter typr:0,Disable IP permission qualification;1,IP access is disabled;2,Allow IP access
	char pcFilterIp[MAX_IP_FILTER_NUM][LENGTH_IPV6_V1];		//Network address string, such as：pcFilterIp[0]=“1234:5678:9abc:def::1”
}TIpv6Filter, * pTIpv6Filter;

typedef struct tagIpv6FilterParam
{
	int					iSize;				
	int					iFilterType;														//过滤类型(0-禁用IP权限设定,1-禁止IP访问,2-允许IP访问)
	int					iIpNum;																//过滤ip数量(iIpNum 最大支持48个不同的IP地址)
	int					iPackageNum;														//总包数
	int					iListIndex;															//列表序号(从1开始)
	int					iParamNum;															//参数列表长度(每次发送的列表数目)
	char				pcFilterIp[MAX_IPV6_PACKAGE_FILTER_NUM][LENGTH_IPV6_V1];			//IPv6地址(网络地址字符串。如：pcFilterIp1=“1234:5678:9abc:def::1”或“192.168.1.10”（最大长度为64字节）)
}Ipv6FilterParam, * pIpv6FilterParam;

typedef struct tagCloudAutoDetect
{
	int					iSize;
	int					iChannelNo;				//Channel number, 1-NVR when upgrading ipc channel number starts from 0, 2-NVR cloud upgrade channel number is 0x7FFFFFFF
	int					iNewVerStat;			//is there a new version, 0-no new version, 1-new version
	char				cNewVer[LEN_64];		//new version, 64 bytes
	char				cReleaseData[LEN_32];	//Release time, 32 bytes, YYYY-MM-DD
}CloudAutoDetect, *pCloudAutoDetect;

typedef struct tagDeviceName
{
	int                 iSize;
	int                 iChannelNo;              //channel number，0~N-1：ipc parameters of corresponding IPC channel；
	                                             //0x7fffffff：NVR local parameters
	char                pcDeviceName[LEN_32];    //device name
}DeviceName, *pDeviceName;

typedef struct tagChnDevInfo
{
	int					iSize;
	int					iChannelNo;					// output para,Channel number, iChannelNo according to the actual situation to determine iChannelNo= 0~n-1
	char				cMac[LEN_64];				// output para,Mac address, no more than 64 bytes
	char				cFactoryID[LEN_64];			// output para,Factory ID, no more than 64 bytes
	char				cBarCode[LEN_64];			// output para,Bar code, no more than 64 bytes
}ChnDevInfo, *pChnDevInfo;

typedef struct tagDomainParsePara
{
	int				iSize;
	char			cUserID[LEN_16];							//username
	char			cPassWord[LEN_16];							//password
	char			cHostName[LEN_32];							//device name
	int				iInterval;									//Registration interval
	char			cDomain1[LEN_32];							//Server 1 domain name
	char			cDomain2[LEN_32];							//Server 2 domain name
	int				iPort1;										//Server port 1
	int				iPort2;										//Server port 2
	char			cDomain1v6[LENGTH_IPV6_V1];					//Server 1 domain name
	char			cDomain2v6[LENGTH_IPV6_V1];					//Server 2 domain name
}DomainParsePara, *pDomainParsePara;

typedef struct	tagNVS_NFS_DEVEx
{
	int		iSize;
	char	cDeviceIP[LEN_16];					//NFS IP
	char	cStorePath[LEN_250];				//NFS Path
	char	cUsername[LEN_16];					//User Name
	char	cPassword[LEN_16];					//Password
	int		iState;								
	char	cDeviceIPv6[LENGTH_IPV6_V1];		//IPv6
}NVS_NFS_DEVEx,*pNVS_NFS_DEVEx;

typedef struct tagWaterLevelSource
{
	int				iSize;				//input para: Structure waterlevelsource size 
	int				iChannelNo;			//input para: Channel number 
	int				iType;				//input para: Water level data source type, 0-reserved; 1-manual setting; 2-network access; 3-peripheral access,4-water level algorithm acquisition
	int				iValue;				//input para: Water level in mm, valid when itype = 1 	
}WaterLevelSource, *pWaterLevelSource;

typedef struct tagWaterLevelSourceID
{
	int				iSize;				//input para: Structure waterlevelsourceid size 
	int				iChannelNo;			//input para: Channel number 
	char			cFactoryID[LEN_64];	//input para: Factory id, no more than 64 bytes 
}WaterLevelSourceID, *pWaterLevelSourceID;


#define IPV6_ADDRLIST_NUM_MAX				16

#define IPV6_ADDRESS_MANUAL_MODE				1	//MANUAL
#define IPV6_ADDRESS_DHCP_MODE					2	//DHCP
#define IPV6_ADDRESS_ANNOUNCEMENT_MODE			3	//Routing announcement mode
#define IPV6_ADDRESS_MODE_MAX					4	//Mode max num

typedef struct tagIPV6AddrAndPrefix
{
	char			cIP[LENGTH_IPV6_V1];	
	int				iPrefixLen;			
}IPV6AddrAndPrefix, *pIPV6AddrAndPrefix;

typedef struct tagIPV6AddrList
{
	int					iSize;									//input para: Structure waterlevelsourceid size 
	int					iChannelNo;								//input para: Channel number 
	int					iLanNo;									//input para: Lan number 0-MAX_LAN_NUM
	int					iIPMode;								//input para: 1-MANUAL mode 2-DHCP mode ,3-Routing announcement mode
	int					iIPListNum;								//output para: IP num
	IPV6AddrAndPrefix	tIPInfo[IPV6_ADDRLIST_NUM_MAX];			//ooutput para: IP address list
}IPV6AddrList, *pIPV6AddrList;


#define MAX_SMOKEDETECT_POINT_NUM			8
typedef struct tagVCASmokeDetect
{
	int					iSceneID;						     //scene ID(0~31)
	int					iRuleID;						     //rule ID(0~15)
	int                 iValid;					             //0;invalid; 1:valid(default:0)
	int					iSensitivity;					     //Sensitivity 0~100
	int					iPointNum;						     //Polygon Area point Number
	vca_TPoint     	    stPoints[MAX_SMOKEDETECT_POINT_NUM]; //Vertex Coordinates		
}VCASmokeDetect, *pVCASmokeDetect;

#define MAX_PHONEDETECT_POINT_NUM		8
typedef struct tagVCAPhoneDetect
{
	int					iSceneID;						     //scene ID(0~31)
	int					iRuleID;						     //rule ID(0~15)
	int                 iValid;					             //0;invalid; 1:valid(default:0)
	int					iSensitivity;					     //Sensitivity 0~100
	int					iPointNum;						     //Polygon Area point Number
	vca_TPoint     	    stPoints[MAX_PHONEDETECT_POINT_NUM]; //Vertex Coordinates		
}VCAPhoneDetect, *pVCAPhoneDetect;

#define MAX_SLUICEGATE_CEIL_COUNT	10	//MAX_VCA_SLUICEGATE_COUNT*2

typedef struct tagCeilLineInfo
{	
	vca_TPoint			tPointStart;			
	vca_TPoint			tPointEnd;	
}CeilLineInfo, *pCeilLineInfo;

typedef struct tagVcaSluiceGateCeil
{
	int					iSize;										//input para:Structure size
	VCARule				tRule;										//input para
	int					iCeilLineCount;								//input para:Ceil line count
	CeilLineInfo		tCeilLineInfo[MAX_SLUICEGATE_CEIL_COUNT];	//output para:Ceil line point info
}VcaSluiceGateCeil, *pVcaSluiceGateCeil;

typedef struct tagOsdClarity
{
	int				iSize;								// input para Structure size
	int				iOsdType;							// input para Character type, 0: channel name 1: Date Time 2: additional character 1 3: additional character 2 4: additional character 3 5: additional character 4 6: additional character 5 
	int				iBClarity;							// input para Background transparency, 0-100, smaller, more transparent 
	int				iFClarity;							// input para Foreground transparency, 0-100, smaller, more transparent 
}OsdClarity, *pOsdClarity;

typedef struct tagLedPowerLimit
{
	int				iSize;							// output para Structure size
	int				iNearLEDPower;					// output para The power consumption per unit brightness of the approach lamp is increased by 1000 times. For example, when the power consumption is 0.05W, the value of this field is 50, the same below 
	int				iFarLEDPower;					// output para The power consumption per unit brightness of the far lamp is increased by 1000 times 
	int				iBasePower;						// output para The basic power consumption of the system is increased by 1000 times 
	int				iBasePowerRatio;				// output para Basic power consumption coefficient of the system 
	int				iOtherPower;					// output para Other power consumption, actual power consumption increased by 1000 times 
	int				iOtherRatio;					// output para Other coefficient, multiple of other power consumption when calculating power consumption 
	int				iLimitPower;					// output para Limit the power consumption value, and increase the actual power consumption value by 1000 times 
}LedPowerLimit, *pLedPowerLimit;

typedef struct tagFaceOsdTimeFormat
{
	int             iSize;  // input para Structure size
	int             iCapType;  
	char            cYearText[LEN_8];  //Format symbol after year
	char            cMonthText[LEN_8]; //Format symbol after month
	char            cDayText[LEN_8];   //Format symbol after day
	char            cHourText[LEN_8];  //Format symbol after hour
	char            cMinText[LEN_8];   //Format symbol after min
	char            cSecText[LEN_8];   //Format symbol after sec
	char            cMilsecText1[LEN_8];//Format symbol after milsec1
	char            cMilsecText2[LEN_8];//Format symbol after milsec2
}FaceOsdTimeFormat, *pFaceOsdTimeFormat;

typedef struct tagFaceOsdWordOverlay
{
	int             iSize;        //input para Structure size
	int             iOsdDisplayIndex;   //
	int             iEnable;            //control context show
	char            pcOsdName[LEN_32];  //osd name
	int             iPosX;              //PosX
	int             iPosY;              //PosY
	int             iZoomScale;         //[0-500].100 represents no change
	int             iLineCharNum;       //Maximum characters per line
	int             iBlankCharNum;      //Number of starting spaces after line brea
	int             iOsdPosNo;          //osd Postion Number
	int             iCapType;           //capture type
	int             iFacePicType;       //small picture size:0,default;1.small;2.middle;3,big
}FaceOsdWordOverlay, *pFaceOsdWordOverlay;

typedef struct tagFaceOsdCommonDev
{
	int             iSize;  //input para Structure size
	int             iOsdType;//0-reserved, 1-mechanism code, 2-mechanism name, 3-capture image character overlay bit, 6-composite image character overlay bit, 7-face overlay OSD
	char            cCommonInfo[LEN_64];//ods content
	int             iCapType;//capture type
}FaceOsdCommonDev, *pFaceOsdCommonDev;

typedef struct tagImageLocation
{
        int            iSize; //input para Structure size
        int            iLocation; //0-normal，1-turnover，2-h_mirror，3-v_mirror
}ImageLocation, *pImageLocation;

typedef struct tagPtzResult
{
	int iSize;
	int iPtzP; //0~3600000 [0-360]，accurancy：0.0001
	int iPtzT; //100000~1900000 [-90 - 90]accurancy：0.0001
	int iPtzZ; //0~100000 [0-1000]，accurancy:0.01
}PtzResult, *pPtzResult;

typedef struct
{
	int         m_iStructSize;        //Structure size
	char        m_cVersion[LEN_32];       //Server version number
	char		m_cUIVersion[LEN_32];	  //UI Server version number
	char		m_cSlaveVersion[LEN_32];  //From film version number
	char        m_cPlugInVersion[LEN_32]; //Plug-in version number 
	char		m_cSCMVersion[LEN_32];	  //Single chip version number
	char 		m_cSCGuiVersion[LEN_32];  //UI version number
	char		m_cMediaVersion[LEN_32];  //T2 Camera Media Version
	char		m_cMethodVersion[LEN_64];		//Method Version
	char		m_cCpldVersion[LEN_64];			//Cpld Version
	char		m_cDomeDriveVersion[LEN_64];	//DomeDrive Version
	char		m_cDigitalMovementVersion[LEN_64];  //Digital Movement Version
	char		m_cTradeP2PVersion[LEN_64];			//p2p Version
	char		m_cTradeOnvifVersion[LEN_64];		//Onvif Version
	char		m_cTradeItsVersion[LEN_64];			//Its Version
	char		m_cTrade28181Version[LEN_64];		//28181 Version
	char		m_cTradeZFZJVersion[LEN_64];		
	char		m_cTradeH323Version[LEN_64];		
	char		m_cTradeRTSPVersion[LEN_64];		
	char		m_cTradeRTMPVersion[LEN_64];
	char		m_cHpdVersion[LEN_64];
	char		m_cFrontPanelVersion[LEN_64];
	char		m_cAlgoModelVersion[LEN_64];
	char		m_cIntelligentModuleVersion[LEN_64];	//Intelligent module Version
	char		m_cLandmarkVersion[LEN_64];				//Landmark Version
	char        m_cNetSdkVersion[LEN_32];
	char        m_cNetOcxVersion[LEN_32];
	char		m_cSecondDomeDriverVersion[LEN_64];				//2nd M3  Driver
	char		m_cEncrypChipSupportFirmwareVersion[LEN_64];
	char        m_cIspVersion[LEN_64];
    char        m_cFacePadM3Version[LEN_64];    // face pad m3

}SERVER_VERSION;

#define BURN_BACKUP_FILE_ALL         0
#define BURN_BACKUP_FILE_ONLYPEN     1
typedef struct tagBurnBackupFile
{
    int 	  iSize;  			//[IN]结构体大小
    int	      iBurnFile;	    //[IN] BURN_BACKUP_FILE_ALL：正常备份所有文件  BURN_BACKUP_FILE_ONLYPEN：只备份笔录文件
}BurnBackupFile, *pBurnBackupFile;

#define RET_BURN_SUCCESS       0 //设置成功
#define RET_BURN_FAILED        1 //设置失败
#define RET_BURN_RUNING        2 //当前正在刻录，不允许修改配置


#define EASYDDNS_LINK_OFFLINE	0
#define	EASYDDNS_LINK_ONLINE	1
typedef struct tagEasyDDNSLinkState
{
	int iSize;
	int iLinkState;	//0:offline, 1:online
} EasyDDNSLinkState, *pEasyDDNSLinkState;

typedef struct tagModulePowerLimit
{
	int				iSize;				// output para 结构体大小
	int				iLimitPower;		// output para 限制总功耗值, 实际功耗值扩大1000倍
	int				iModuleType;		// output para 模块类型，0：红外灯，1：白光灯，2：激光灯，3-9：预留
	int				iPowerRatio1;		// output para 模块功耗系数1, 模块为红外或白光灯时表示近光组每单位亮度变化的功耗值，模块为激光灯时表示激光灯每单位亮度变化的功耗值，实际扩大1000倍，不支持则为0，其他模块则根据需求定义
	int				iPowerRatio2;		// output para 模块功耗系数2, 模块为红外或白光灯时表示远光组每单位亮度变化的功耗值，实际扩大1000倍，不支持则为0，其他模块则根据需求定义
	int				iPowerRatio3;		// output para 模块功耗系数3, 模块为红外灯时表示中光组每单位亮度变化的功耗值，实际扩大1000倍，不支持则为0，其他模块则根据需求定义
	int				iPowerRatio4;		// output para 模块功耗系数4, 预留，不支持则为0
	int				iLightID;			// output para 灯组编号, 0表示灯组1；1表示灯组2
}ModulePowerLimit, *pModulePowerLimit;

typedef struct tagManualPortMap
{
    int  iSize;
    int  iHttpWanPort;			// http协议外网映射端口号
    int  iRtspWanPort;			//rtsp协议外网映射端口号
    int  iServerWanPort;		//私有协议外网映射端口号
    int  iHttpsWanPort;			// https协议外网映射端口号
    int  iRtmpWanPort;		    // rtmp协议外网映射端口号
} ManualPortMap, *pManualPortMap, ManualPortMapResult, *pManualPortMapResult;

#define OSDTYPE_TIME						0x01
#define OSDTYPE_TITLE						0x02
#define OSDTYPE_LOGO						0x04
#define OSDTYPE_ITS							0x05

typedef struct tagNorthAngle
{
	int iSize;
	int iAngle; //0~3600000 [0-360]，accurancy：0.0001
	int iStatus;//校正状态:0：预留，1：校正，2，未校正
}NorthAngle, *pNorthAngle;

typedef struct tagCommonRECT 
{ 
	int left; 
	int top; 
	int right; 
	int bottom; 
}CommonRECT, *pCommonRECT;

typedef struct tagIEEE8021X
{
	int iSize;
	int iLanNo; //0：lan1  1:lan2….
	int iEnable;	//0:not enable   1:enable
	int iConnectType;	//0:automic  1:manual
	int iEapType;		//0，EAP-MD5
	int iEapolVersion;	//1，IEEEStd 802.1X-2001  2，IEEEStd 802.1X-2004
	char cUserName[LEN_64];	//user name
	char cPassWord[LEN_64];	//password

}IEEE8021X, *pIEEE8021X;

#define    MAX_ADDRESS_TYPE			2
typedef struct tagCommonRtmp
{
	int iSize;
	int iStreamType;	//0:main 1:sub  2:three
	int iAddressType; //1Custom 2Non-custom 
	int iEnable; //	0:not enable  1:enable
	int iPort; //0~65535
	char cIpAddress[LEN_256]; //Ip Address
	char cUserName[LEN_64];	//user name
	char cPassWord[LEN_64];	//password
	char cKey[LEN_64];	//key
}CommonRtmp, *pCommonRtmp;

typedef struct tagIEEE8021XState
{
	int iSize;
	int iLanNo;			 //0：lan1  1:lan2….
	int iConnectState;	//0:not connect 1:connected  2:connecting 3:connect failed
}IEEE8021XState, *pIEEE8021XState;


typedef struct tagWaterSpeedFieldInfo
{
	int					iSize;			
	int					iChanNo;		//channel no
	int					iEnable;		//0-close;1-open
	int					iResult;		//output para:0-success;1-failed
}WaterSpeedFieldInfo, *pWaterSpeedFieldInfo;

#define MAX_AUTOTESTMULT_PARAM_NUM    16
typedef struct tagAutotestMultQuery
{
	int                 iSize;
	int					iChannelNo;			
	int					iTestItem;		//Debugging items:1-Calibration of PTG pot cover;
					                    //2-Calibration of PTG temperature; 3-Calibration of PTG distance;
	int					iParamNum;		                                
	char			    pcParam[MAX_AUTOTESTMULT_PARAM_NUM][LEN_65]; 
}AutotestMultQuery, *pAutotestMultQuery;

typedef struct tagAutotestMultResult
{
	int                 iSize;
	int					iChannelNo;			
	int					iTestItem;		//Debugging items:1-Calibration of PTG pot cover;
										//2-Calibration of PTG temperature; 3-Calibration of PTG distance;
	int					iTestResult;
	char                cTestInfo[LEN_65];
	int					iParamNum;		                                
	char			    pcParam[MAX_AUTOTESTMULT_PARAM_NUM][LEN_65]; 
}AutotestMultResult, *pAutotestMultResult;

#define MAX_TEMP_MODEL_TYPE 3
typedef struct tagVCATemDetect
{
	int                 iSize;
	int					iSceneID;						     //scene ID(0~31)
	int					iRuleID;						     //rule ID(0~15)
	int                 iValid;					             //0:invalid; 1:valid(default:0)
	int					iDisplayTemScaleEnable;			     //0:not display 1:display (default:0)
	int					iHighTemColor;						 //1:red 2:green 3:yellow 4:blue 5:purple 6:cyan 7:black 8:white (default:1）
	int					iLowTemColor;						 //1:red 2:green 3:yellow 4:blue 5:purple 6:cyan 7:black 8:white (default:1）		
	int					iModelType;						     //1:Ambient temperature difference alarm 2:Environmental high temperature alarm 3:human high temperature alarm	
	int					iTemUnit;						     //0:centigrade 1:Fahrenheit; 		
	int  				iTemThreshold;	                     //The threshold value of temperature alarm is determined according to the imodeltype, and the value is the actual temperature * 100 
	int					iWaitTime;                           //Unit: Second	
	int                 iTempLoseEnable;                     //Temperature abnormal alarm enable, 0-disable, 1-enable.(default:0)
}VCATemDetect, *pVCATemDetect;

typedef struct tagVcaScanList
{
	int                iSize;
	int                iVcaType;
	int                iSupport;                             //0-not support 1-support scan list
}VcaScanList, *pVcaScanList;

typedef struct tagVcaFireWork
{
	int               iSize;
	int               iSceneId;//range:[0-31],default:[0-15]
	int               iRuleID; //range:[0-15],default:0
	int               iValid;  //0:unvalid,1:valid
	int               iDisplayRule;//0:not display,1:display
	int               iDisplayStat;//0:not display,1:display
	int               iDisplayTarget;//0:not display,1:display
	int               iColor;      //1：red 2：green 3：yellow 4：blue 5：purple 6：Cyan 7：black 8：white  （default:2）
	int               iAlarmColor; //1：red 2：green 3：yellow 4：blue 5：purple 6：Cyan 7：black 8：white  （default:1）
	int               iFireSensitiv;//fire sensitive,range:[0-100],default:50
	int               iSmogSensitiv;//smoke sensitive,range:[0-100],default:50
	int               iModelType;//fire work test model:0:default，1:fire point detection，2:Smoke detection，3:fire point detection or Smoke detection，4:fire point detection and Smoke detection
	int               iWaitTime;//find alarm waiting time,range[0-600]s,default:0
}VcaFireWork, *pVcaFireWork;


#define  MAX_MASKAREA_TYPE  4
#define  MAX_MASKAREA_NO    48
typedef struct _tagMaskAreaEnable
{
	int             iSize;						//size of struct
    int             iMaskType;                  //0-reserved, 1-pyrotechnic detection - fire point shielding area, 2-pyrotechnic detection - Smoke shielding area, 3-temperature detection shielding area
	int             iEnable;                    //0：unenable  1：enable  (default:0)
}MaskAreaEnable, *pMaskAreaEnable;

#define SDK_MAX_MASKAREA_NUM   12
typedef struct _tagMaskAreaPara
{
	int             iSize;
    int             iMaskType; //0-reserved, 1-pyrotechnic detection - fire point shielding area, 2-pyrotechnic detection - Smoke shielding area, 3-temperature detection shielding area
    int             iAreaNo;//AreaNo:1-48
	vca_TPolygonEx  tPoint;
}MaskAreaPara, *pMaskAreaPara;


typedef struct tagSingleScreenCalParam
{
	int                 iChanNo;
	TPoint              tPoint;               
}SingleScreenCalParam, *pSingleScreenCalParam;

#define MAX_CALIBRATION_SCREEN_COUNT    32
typedef struct tagCalibrationInfo
{
	int                     iSize;           
	int                     iCalPtCount;	   //Calibration points count, max value 16.
	int                     iCalPtNo;          //Current calibration point number, 1~16.
	int                     iCalScreenCount;   //Screens count of calibration channel, max value 32.
	SingleScreenCalParam    tParam[MAX_CALIBRATION_SCREEN_COUNT]; //Every screen parameter, including channel number & points information corresponding to the each screen.
}CalibrationInfo, *pCalibrationInfo;

typedef struct tagVisualRange
{
	int iSize;
	int iRange;				//visual range
	int iHview;				//hortional view angle, 0~36000
	int	iVview;				//vertical view angle, 0~36000
	int iChannel;
}VisualRange, *pVisualRange;

#define VIDEO_CONVOER_AREA			8	//视频遮挡区域数

typedef struct tagVideoCover
{
	int			iSize;
	int			iStreamNo;
	CommonRECT tRect[VIDEO_CONVOER_AREA];
}VideoCover, *pVideoCover;

typedef struct tagRadarStatusInfo
{
	int		iSize;			
	int		iType;						//radar type 0-reserve  1-川速雷达
	char	cRadarVersion[LEN_64];		//Version
	int		iRadarStatus;				//Status 1-online, 0-offline
}RadarStatusInfo, *pRadarStatusInfo;

typedef struct tagTemperatureScaleType
{
	int			iSize;
	int         iChanNo;
	int         iTempStandard;          //temperature scale type, 0-reserved, 1-celsius, 2-fahrenheit, 3-kelvin 
}TemperatureScaleType, *pTemperatureScaleType;

typedef struct tagSingleBlackbodyParam
{
	int         iBlackBodyId;           //black body ID
	int         iBlackBodyTemp;         //temperature value * 100
	int         iBlackBodyTempUnit;     //temperature unit: 0-reserved, 1-celsius, 2-fahrenheit, 3-kelvin
	int         iBlackBodyDistance;     //unit: cm
	CommonRECT  tRect;
}SingleBlackbodyParam, *pSingleBlackbodyParam;

#define MAX_BLACKBODY_COUNT         2
typedef struct tagBlackbodyCorrection
{
	int			iSize;
	int         iChanNo;
	int         iBlackBodyCorrectEnable;//black body correct enable: 0-disable, 1-enable   
	int         iBlackBodyCorrectType;  //0-reserved, 1-single correction, 2-continuous correction 
	int         iBlackBodyNum;          //black body number: 1 or 2
	SingleBlackbodyParam tParam[MAX_BLACKBODY_COUNT];
}BlackbodyCorrection, *pBlackbodyCorrection;

typedef struct tagBodyTempCorrect
{
	int			iSize;
	int         iChanNo;
	int         iBodyTempCorrectEnable;          //body temperature correction enable:  0-disable, 1-enable 
	int         iBodyTempCorrectSensitivity;     //body temperature correction sensitivity: 0-100
}BodyTempCorrect, *pBodyTempCorrect;

typedef struct tagIntelligentCorretct
{
	int			iSize;
	int         iChanNo;
	int         iIntelligentCorrectEnable;		 //intelligent correction enable: 0-disable, 1-enable
	int         iIntelligentCorrectSensitivity;  //intelligent correction correction sensitivity: 0-100
}IntelligentCorretct, *pIntelligentCorretct;

typedef struct tagVcaScanArea
{
	int			iSize;
	int			iSceneId;		//scene id 0-15
	int			iOrderTyp;		//0:top area, 1:bottom area, 2:left area, 3:right area
	int			iCmdType;		//commond type, 0:set, 1:call
}VcaScanArea, *pVcaScanArea;

typedef struct tagVcaScanPara
{
	int			iSize;
	int			iSceneId;		//scene id 0-15
	int			iMode;			//scan type,0:manual, 1:auto
	int			iWaitTime;		//wait time (s)
	int			iPanStep;		//Pan Step [0,36000],Corresponding floating point range [0,360], unit: degree,(software use divide by 100), accuracy: 0.01
	int			iTiltStep;		//Tilt Step [0--9000],Corresponding floating point range [0,90], unit: degree,(software use divide by 100), accuracy: 0.01
}VcaScanPara, *pVcaScanPara;

typedef struct tagRtmpClientLinkState
{
    int				iSize;							// 结构体大小
    int				iStateValue;					// 连接状态值
} RtmpClientLinkState, *pRtmpClientLinkState;

#define RADAR_EVENT_TYPE_PARK			1
#define RADAR_EVENT_TYPE_CONGESTION		2
#define RADAR_EVENT_TYPE_MAX			3
typedef struct tagRadarEventPara
{
	int					iSize;
	int					iChanNo;		//channel no
	int					iEventType;		//0- reservation 1- parking event 2- congestion event
	int					iTime;			//iEventType=1 range [1,43200], Unit s
										//iEventType=2 range [1,3600], Unit s
}RadarEventPara, *pRadarEventPara;

#define RADAR_ROAD_MAXNUM		24
#define RADAR_CROSS_SECTION		 8

typedef struct tagRadarRoadDir
{
	int				iId;		//[0,11]
	int				iDir;		//0–来向车道, 1–去向车道
}RadarRoadDir, *pRadarRoadDir;

typedef struct tagRadarCrossSection
{
	int				iId;		//断面Id,	范围 [0,3]
	int				iPos;		//断面位置, 范围 [0,250], 默认值0表示未配置断面，单位m
}RadarCrossSection, *pRadarCrossSection;

typedef struct tagRadarDevicePara
{
	int					iSize;
	int					iChanNo;							//channel no
	int					iRadarType;							//1-川速雷达
	int					iRoadNum;							//车道数量 [1,12]
	int					iRadarRoadWidth;					//车道宽度 [100,400]	单位 cm
	RadarRoadDir		tRoadDir[RADAR_ROAD_MAXNUM];		//车道方向
	int					iRadarMeasureMax;					//测距上限 范围 [100,28000], 默认值 25000； 单位cm
	int					iRadarMeasureMin;					//测距下限 范围 [100,25600], 默认值 3000；单位cm
	int					iCrossSectionNum;					//断面个数
	RadarCrossSection	tCrossSection[RADAR_CROSS_SECTION];	//断面信息
	int					iRadarHeight;						//雷达安装高度 范围 [100,1000]默认值 700 单位cm 
	int					iRadarAngleDelta;					//雷达角度修正 范围 [0,20000] 默认值 10000 单位(度*100) (实际对应范围[-100度,100度])
	int					iRadarCoordDelta;					//雷达坐标修正 范围 [0,2000], 默认值 1000 单位cm (实际对应范围[-1000,1000])
	int					iTrafficJamStartLine;				//拥堵判断起始位置 范围 [0,250], 默认值0，单位m
	int					iTrafficJamTerminationLine;			//拥堵判断终止位置 范围 [0,250], 默认值0，单位m
	int					iQueueLengthThreshold;				//排队长度阈值 范围 [0,8], 默认值0
	int					iTrafficJamCarNumber;				//拥堵车辆阈值 范围 [0,128], 默认值0
	int					iLsolationBeltDriveway;				//隔离带所在车道 范围 [0,12], 默认值0
	int					iLeftToTheLane;						//左侧来向车道数目 范围 [0,8], 默认值0 代表全部为来向
	int					iNonmotorValue;						//路口非机动车过滤阈值 范围 [0,20], 默认值 0；对应范围[-10,10] ，-10不过滤，值越大过滤效果越强
	int					iMotorValue;						//行车道非机动车过滤阈值 整数, 范围 [0,20], 默认值 0；对应范围[-10,10] ，-10不过滤，值越大过滤效果越强
	int					iShieldDistance;					//反射屏蔽距离 [0,250],单位m， 默认值80，0表示此功能无效
}RadarDevicePara, *pRadarDevicePara;	

#define MAX_CROP_NUM 2
typedef struct _tagCropCoding
{
	int                iSize;
	int                iEnable;                             //0：不使能；1：使能
	TPoint             tPoint[MAX_CROP_NUM];                //使用万分比表示，取值范围0～10000。矩形框实际分辨率最小为352*288,区域顶点坐标
}CropCoding, *pCropCoding;

#define MAX_VAR_GAUGE_POINT_NUM		8

typedef struct tagVirGaugedIs
{
	int					iSize;
	int					iEnable;		//0, off; 1, on 
	int					iResult;		//0, setting succeeded; 1, setting failed
}VirGaugedIs, *pVirGaugedIs;

#define  MAX_VIDEO_COVER_EX     4
typedef struct tagVideoCoverEx
{
	int					iSize;
	int					iStreamNo;
	int					iAreaCnt;		//effictive area count
	CommonRECT			tCommonRECT[MAX_VIDEO_COVER_EX];		//area point
}VideoCoverEx, *pVideoCoverEx;

typedef struct __tagInterestedArea
{
	int iSize;
	int iIndex;
	int iEnable;
	int iAbsQp;
	int iQp;
	int iLeft;
	int iTop;
	int iRight;
	int iBottom;
	int iDstFrameRate;	//destination frame rate，1-current framerate
}TInterestedArea, *pTInterestedArea;

typedef struct __tagVcaFlowSpeedParam
{
	int					iSize;
	int					iChanNo;
	VCARule			    tRule;
	int		            iDisplayRule;	
	int                 iColor;
	int                 iSensitive;
	int                 iLinkRecord;
	int              	iCruiseAddMode;
	int              	iCruiseNum;
	int                 iInterval;
	vca_TPolygonEx      tPonit;
	int                 iApplyScene;	//0: large scene 1: small scene
	int                 iDetectStep;	//0 ~ 100000 unit mm, valid when icruiseaddmode is automatic
	int                 iMiddleWidth;	//0-20000 unit mm
	int                 iDetectAltitude;//The elevation unit of the initial detection area is mm, and the actual value range is [- 10000000 ~ 10000000]. If it is sent on the network, add 10000000, and then subtract 10000000 after the software value
	vca_TLine			tLinePonit;
	int                 iHorizontalWidth;	//Horizontal  Width
	int                 iVerticalWidth;		//Vertical  Width
	int                 iHypotenuseWidth;	//Hypotenuse  Width
	int                 iAngelInputMode;	//0: enter slope angle 1: enter right angle slope
	int                 iNightFocusMode;	//0: off 1: on
	int                 iWaterSpeedDirEnable;	//0: Not Enable 1: Enable
	vca_TLine			tWaterSpeedDirPoint;
	int                 iWaterSpeedRatio;	//Water Speed Ratio,（0,1000]
	int                 iFilterSensitivity;	//int	过滤灵敏度	0～100 
	int              	iLinkAreaType;	//int	水位联动检测区域类型	0-不联动 1-流速方向左边联动 2-流速方向右边联动 3-双边联动
	int              	iMinSpeed;	//int	最小流速限制	-300000～300000，单位：毫米/秒(mm/s)
	int              	iMaxSpeed;	//int	最大流速限制	-300000～300000，单位：毫米/秒(mm/s)
	int             	iDisplayType;	//int	流速显示类型	0-瞬时流速 1-平均流速
	int                 iWaterLevelThreshold;//int 范围:-10000000～10000000，单位:毫米(mm)
	int                 iDetectMode;          //流速检测模式	0-保留 1-自动 2-低速 3-高速
	int                 iTrackFrameNum;       //检测跟踪帧数	范围：2-10  iDetectMode=1自动模式下有效
	int                 iFieldOfVision;       //流速检测视野大小	0-保留 1-大 2-小
	int                 iCorrlevel;           //流速曲线校正级别	0-保留 范围:1-100
	int					iStartDir;            //流速检测起点方向	0-保留 1-同向(面向起点方向检测) 2-反向(背向起点方向检测)
}VcaFlowSpeedParam, *pVcaFlowSpeedParam;

#define MAX_PRESET_NUM_EX			32

// (water level detection) RULEEVENT15
#define MAX_REFERPOINT_NUM			10
#define	EVENT_BUF_RESERVED			2048			//reserve size
#define MAX_WATER_SAMPLE_POINT		16


typedef struct tagWaterRange // level range
{
	int iStart;			// start range
	int iEnd;			// End range
} WaterRange;

typedef struct tagReferPoint // The water level reference
{
	int iPointX;		// abscissa
	int iPointY;		// ordinate
	int iValue;			// The reading on the ruler
}ReferPoint;

typedef struct tagWaterPresetInfo
{
	int                 iSize;
	int iPresetId;					// Preset ID
	WaterRange stGaugeRange;		// Water level range iStart: iEnd
	CommonRECT rcGaugeRect;			// Diagonal coordinate of the scale area
	CommonRECT rcAssistRect;		// auxiliary area diagonal coordinates
	CommonRECT rcGaugeLine;			// Coordinate of the ruler reference line
	int iReferNum;					// number of reference points
	ReferPoint stReferPoint [MAX_REFERPOINT_NUM]; // reference points 1, 2, 3
}WaterPresetInfo;

#define  MAX_RULE_REGION_NUM	4
typedef struct vca_tLeaveDetect
{
	int iValid;						// Whether this event detection is valid, 0: invalid 1: valid
	int iLeaveAlarmTime;			// off-duty alarm time, 60 ~ 3600, in seconds, the default: 120S
	int iRuturnClearAlarmTime;		// back to the police alarm time, 10 to 300, in seconds Default: 15S
	int iAreaNum;					// Total number of rule fields, 1 ~ 4
	vca_TPolygonEx		stRegion[MAX_RULE_REGION_NUM];			//	 Range	
}vca_tLeaveDetect, *LPvca_tLeaveDetect;

typedef  struct WaterSamplePoint
{
	int iSize;
	VCARule	stRule;
	vca_TDisplayParam	stDisplayParam;		//Parameter dispaly
	int iSamplePointId;
	int iSnapInterval;
	int iBaseValue;			//base water level value
	int iCurrentPresetId;	//current preset id
	int	iGaugeType;			//Gauge type:0-Reserved, 1-Wide gauge,New gauge, 2-Narrow gauge,Old gauge, 3-Special water ruler, self-calibration 4-gauge-type-squad 5-gauge-type-pile
	int iPresetCount;
	WaterPresetInfo stPresetInfo[MAX_PRESET_NUM_EX];
	int	iGaugeLength;
	int iGaugeCount;        //this param is valid when the gauge type is pile gauge
	int iDirection;         //0：left 1：right
	int iVirGaugeMode;		//Virtual Gauge Detect Mode 0-algorithm detection mode 1-manual calibration mode
	int iVirGaugePointNum;  //2--8,Effective in manual calibration mode 
	vca_TPoint tVirGaugePoint[MAX_VAR_GAUGE_POINT_NUM];
	int iCurGaugeNo;        //0：invalid  >0 is Gauge Num
	int iSnapPresetEnable; //Snap interval enable
	int iSnapPresetNo;     //Snap interval No
	int iGaugeMinScale;    //the minize Scale(Unit:cm，range:0-20，0:auto)
	int iGaugeCalibIntervel; //5-1440（unit:min）
	int iDetDisturbFlag; //0-default，1--close 2--detect human default：1
}WaterSamplePoint, *LPWaterSamplePoint;

#define BANDWIDTH_ADAPTING         0    // 20M/40M 自适应
#define BANDWIDTH_FIX              1    //固定20M 频宽
#define MAX_WIFI_AP_CLIENT        16


//查询/回复AP client设备列表
typedef struct tagWIFIAPClientResult
{
    int     iSize;              // 结构体大小
    int	    iCount;             // 总条数
    int     iNo;                // 当前序号从开始
    char    cDevName[LEN_64]; // 设备名称
    char    cIp[LEN_64];      // ip地址
    char    cMac[LEN_64];     // mac地址
    int     iSpeed;            // 速度Mbps
    int     iBandWidth;        // 带宽BANDWIDTH_ADAPTING/BANDWIDTH_FIX
    int     iConnectTime;       // 连接时间 s

} WIFIAPClientResult, *pWIFIAPClientResult;


typedef struct tagWifiAPClientList
{
    int				    iSize; // 结构体大小
    WIFIAPClientResult	tResult[MAX_WIFI_AP_CLIENT];      
}WifiAPClientList, *pWifiAPClientList;

#define SPEED_ADAPTING         0    // 20M/40M 自适应
#define SPEED_FIX              1    //固定20M 频宽
#define MAX_WIFI_SEARCH_AP     32

typedef struct tagWIFISearchAPResult
{
    int     iSize;               // 结构体大小
    int     iCount;              // 总条数
    int     iNo;                 // 当前序号从开始
    char    cESSID[LEN_33];      //ESSID  LEN_33
    char    cEncryption[LEN_16]; //wifi encrypttion flag; NULL no encryption，"WEP" encryption
    int     iChannel;            // 0，Auto，～，信道～信道。
    int     iRSSL;               // Mbps
    int     iSpeed;              // 速度Mbps SPEED_ADAPTING/SPEED_FIX

} WIFISearchAPResult, *pWIFISearchAPResult;

typedef struct tagWIFISearchAPResultList
{
    int		            iSize;   // 结构体大小
    WIFISearchAPResult  tResult[MAX_WIFI_SEARCH_AP];
} WIFISearchAPResultList,*pWIFISearchAPResultList;

#define LOCATION_NEM						1	//路口编号/地点名称
#define LANE_NUMBER							2	//车道编号/监区名称
#define DEVICE_NUMBER						3	//设备编号/设备名称
#define DRIVE_DIRECTION_TYPE				4	//行驶方向类型；
#define DICTIONARY_VEHICLE_TYPE				5	//车辆类型；
#define SNAP_TYPE							6	//抓拍类型；
#define VEHICLE_BRAND						7	//车辆品牌；
#define VEHICLE_PLATE						8	//车牌；
#define VEHICLE_COLOR						9	//车身颜色
#define PIC_NAME_FORMATE					10	//图片名称格式；
#define PLATFORM_VERSION					11	//平台版本；
#define VEHICLE_SUB_BRAND					12	//车辆子品牌；
#define EXPORT_PIC_ROUTE_FORMATE			13	//导出图片路径格式；
#define PLATFORM_TYPE						14	//平台类型；
#define DEVICE_MODE							15	//设备型号；
#define LED_INSERT_LABEL_ITEM				16	//Led字符叠加快速插入标签项；
#define LED_DEV_MODE						17	//Led设备类型；
#define LED_HINT_MODE						18	//Led提示模式；
#define SCH_ALRAM_MODE						19	//布控报警类型 C
#define SEPARATOR_TYPE						20	//分隔符类型；
#define FTP_UPLOAD_TYPE						21	//FTP上传文件类型；
#define VEHICLE_FORM						22	//车辆外形；
#define OSD_COLOR							23	//OSD字体颜色；
#define LANE_TYPE							24	//车道类型；
#define PLATE_COLOR							25	//车牌颜色；
#define ITS_LOG_LEVEL						26	//交通日志等级；
#define CAM_NAME							27	//相机名称；
#define LOCATION_NAME						28	//路口名称；
#define OSD_OVERLAY_TYPE					29	//Osd叠加信息类型；
#define MD_CARD_VERSION						30	//Mq卡口版本；
#define MD_ILLEGAL_VERSION					31	//Mq违法版本；
#define COMPOSTION_VIDESIZE_TYPE 			32	//合成分辨率类型

#define MAX_DATA_PIC_ITEM  10

typedef struct tagDataDicionaryItem
{
	int		            iSize;   // 结构体大小
	int					iFuncType;		//功能类型，如上
	int		            iTotal;   // 查询总数
	int		            iIndexNo;   // 字段索引0~(N-1)
	int		            iFuncTypeValueNo;   // 当前编号
	char				cParam[LEN_128];   // 字符串描述，内容格式根据具体iFuncType以及iFuncTypeValueNo自己定义
}DataDicionaryItem,*pDataDicionaryItem;


#define			MAX_HINT_INFO_TYPE_NUM   2
typedef struct tagHintInfo
{
	int		            iSize;   // 结构体大小
	int					iHintType;//提示类型 0：有车 1：无车
	char				cDisplayInfo[LEN_128];
	int					iHintTime;		//提示时间,单位：秒
} HintInfo,*pHintInfo;


typedef struct tagLedDevOsdInfo
{
	int     iSize;               // 结构体大小
	int     iIdNum;              // 不显示，内核赋值，添加时默认0，编辑和删除时根据获取值透传即可（从1开始）（后端使用）
	int     iActionType;         // 0：添加，1：编辑，2：删除 
	int		iLedTypeId;			//LED屏的应用类型编号(对应DATADICTIONARYITEM查询类型17的序号iFuncTypeValueNo)，从1开始，如：1-道路预警屏，2-拥堵屏，3-超速屏，也可以1-超速屏，2-道路预警屏，具体数值依据DATADICTIONARYITEM查询上报而定
	char    cLedDevNo[LEN_64];  //提示屏编号
	char    cledDevName[LEN_128];  //提示屏名称
	int     iAlarmTypeId;            // 提示模式,提示模式(对应DATADICTIONARYITEM查询类型18的序号iFuncTypeValueNo)，从1开始，如：1-道路预警
	int     iFontWidth;               // 字体宽度  16,24,26,28，30，32,48,64
	int     iFontHeight;              // 字体高度  16,24,26,28，30，32,48,64
	int     iFontColor;				//字体颜色LED屏的字体颜色(对应DATADICTIONARYITEM查询类型23的序号iFuncTypeValueNo)，从1开始，如：1-红色
	char    cLedSize[LEN_64];		//屏幕尺寸   比如：800*600  （Led设备外键关联）
	HintInfo tHintInfo[MAX_HINT_INFO_TYPE_NUM];//默认tHintInfo[0]有车 tHintInfo[1]无车
	int		iActionResult;		//操作返回状态  0：成功 ，-1 ：失败
} LedDevOsdInfo, *pLedDevOsdInfo;

typedef struct tagLedDevOsdParamList
{
	int		            iSize;   // 结构体大小
	int					iTotal;
	int					iIndexNo;		//提示时间,单位：秒
	LedDevOsdInfo       tLedDevOsdInfo;
} LedDevOsdParamList,*pLedDevOsdParamList;

#define RADAR_PARAMID_MAXNUM 256
typedef struct tagRadarAdvancedPara
{
	int		iSize;			
	int		iChanNo;
	int		iParamID;			//radar paramID 0-255
	char	cValue[LEN_64];		//paramID Value
}RadarAdvancedPara, *pRadarAdvancedPara;

#define LED_DEVICE_MAX_NUM		10

#define LED_ACTION_TYPE_ADD		0
#define LED_ACTION_TYPE_EDIT	1
#define LED_ACTION_TYPE_DEL		2
#define LED_ACTION_TYPE_TEST	3
#define LED_ACTION_TYPE_QUERY	4
#define LED_ACTION_TYPE_MAX		5

typedef struct tagLedDevInfo
{
	int     iSize;               
	int		iChanNo;
	int     iIdNo;					//reserved
	char    cLedDevNo[LEN_64];		//提示屏编号
	char    cLedDevName[LEN_128];   //提示屏名称
	int		iLedDevType;			//提示屏的应用类型
	int     iLedDevWidth;           //屏幕宽度  单位：像素(1-10000)
	int     iLedDevHeight;          //屏幕高度  单位：像素(1-10000)
	int     iLedDevModel;			//提示屏型号
	char    cIpAddr[LEN_64];		//IP地址
	int		iPort;					//端口号
}LedDevInfo, *pLedDevInfo;

typedef struct tagLedDevReply
{
	int		            iSize;
	int					iChanNo;
	int					iActionType;		//opt type 0：添加，1：编辑，2：删除，3：测试
	char				cLedDevNo[LEN_64];			//提示屏编号
	int					iActionResult;		//操作返回状态 0：成功，1:失败
}LedDevReply,*pLedDevReply;

typedef struct tagLedDevParamResult
{
	int		            iSize;   
	int					iTotal;
	int					iIndexNo;
	LedDevInfo			tLedDevInfo;
}LedDevParamResult,*pLedDevParamResult;

typedef struct tagLedDevParamOpt
{
	int		            iSize;   
	int					iActionType;		//opt type 0：添加，1：编辑，2：删除，3：测试， 4,查询
	LedDevInfo			tLedDevInfo;
}LedDevParamOpt,*pLedDevParamOpt;

#define MAX_RADAR_CALIBRATE_POINT_NUM		16

typedef struct tagRadarPointInfo
{	
	vca_TPoint			tVideoPosition;	//万分比坐标
	vca_TPoint			tRealPosition;	//数值[0~100000]对应[-50000cm~50000cm] 数值50000对应0cm
}RadarPointInfo, *pRadarPointInfo;

typedef struct tagItsRadarCalibrate
{
	int		            iSize;   
	int					iChanNo;
	int					iPointNum;								  //point Number
	RadarPointInfo     	tPoints[MAX_RADAR_CALIBRATE_POINT_NUM];   //point info
}ItsRadarCalibrate, *pItsRadarCalibrate;

typedef struct tagBlackBodyDetect
{
	int		iSize;   
	int		iChanNo;
	int		iEnable;		//0-disenable 1-enable
	int		iThreshold;		//[0-100]
	int		iSharkTime;		//[0-100s] unit:s
}BlackBodyDetect, *pBlackBodyDetect;

typedef struct tagDefaultDevParam
{
	int		iSize;   
	int		iChanNo;
	int		iType;			//input para 1-热成像模组恢复默认  2-4G小基站FDD模块恢复出厂 3-4G小基站TDD模块恢复出厂 4-4G小基站FDD模块重启 5-4G小基站TDD模块重启
	int		iResult;		//output para 0-success，1-failed
}DefaultDevParam, *pDefaultDevParam;


typedef struct tagWaterSpeedDeteUpdate
{
	int		iSize;   
	int		iSceneId;		//0~31 
	int		iDetectStep;	//0~100000,mm		
}WaterSpeedDeteUpdate, *pWaterSpeedDeteUpdate;

typedef struct tagWaterSpeedDeteUpdateResult
{
	int		iSize;   
	int		iSceneId;		//0~31 
	int		iDetectStep;	//0~100000,mm		
	int		iResult;	//0-succ 1-failed		
}WaterSpeedDeteUpdateResult, *pWaterSpeedDeteUpdateResult;

	
typedef struct tagSmallCellInfo
{
	int     iSize;
	int     iTerminalType;     //Module type in 4G small base station,0-FDD 1-TDD	
	int     iIsDspHearbeatRecv;//if Receive Dsp heart beat,0:no,1:yes
	int     iRfEnable;         //RF status 0 indicates RF off, 1 indicates RF on
}SmallCellInfo, *pSmallCellInfo;

typedef struct tagSmallCellImsi_Notify
{
	int      iSize;
	int      iDeviceId;       //Device ID
	int      iMsgId;          //Msg ID,prevent overlap
	int      iTime;           //timestamp
	char     pcImsiNo[LEN_32];
	int      iOwnerProvince;  //Provice Code
	int      iOwnerCity;      //City Code
	int      iOwnerOperator;  //0-Unknown 1-Mobile 2-Unicom 3-Telecom
	int      iAccessType;     //1-EpsAtt 2-EPSImsiAtt 6-EpsEmerAtt 16-Tau 17-TaLau 18-TaLauImsi 19-PeriU 24-TaUBr 25-TaLaUBr 26-TaLaImsiBr 27-PeriUBr
	int      iBaseStationType;//1-FDD 2-TDD
	char     pcImeiNo[LEN_32];
	char     pcStmsiNo[LEN_32];
	int      iLibCheck;       //0-under list 1-black list 2-white list
	int      iIsRealTime;     //1-upload ontime 2-upload storage
	int      iIsOwnerWarn;    //1- Place of attribution warning 2- Not place of attribution warning
}SmallCellImsi_Notify, *pSmallCellImsi_Notify;

typedef struct tagVcaHDSchedule
{
    int     iSize;
    int     iSceneId;               // 高16位为0时，低16位表示智能分析，范围0~31;高16位为1时，低16位表示警戒，范围0~3
    int     iType;			        //模板类型 0=保留, 1=通用, 2=短帧, 3=长帧
    int     iEnable;		        //0=不使能, 1=使能
    int     iDayId;			        // 日模板ID '-1=无效, 范围[0,31]
    int     iNightId;			    // 夜模板ID '-1=无效, 范围[0,31]
	int     iColor2Gray;			//联动彩转黑	0-保留 1-黑白 2-普通
} VcaHDSchedule, *pVcaHDSchedule, VcaHDScheduleResult, *pVcaHDScheduleResult;

#define MAX_VCA_FOCUS_AREA 17
typedef struct tagVcaFocusArea
{
    int                 iSize;
    int                 iSceneId;                   // 高16位为0时，低16位表示智能分析，范围0~31,高16位为1时，低16位表示警戒，范围0~3
    int                 iAlgType;                   // 0-保留 1-人脸 2-结构化
    int                 iEnable;                    // 0-不使能 1-使能
    int	                iAreaNum;                   //区域个数 取值范围[0-16]
    vca_TPolygonEx		stAreas[MAX_VCA_FOCUS_AREA];	
} VcaFocusArea, *pVcaFocusArea, VcaFocusAreaResult, *pVcaFocusAreaResult;

#define MAX_PLATE_FILTER_TYPE_NUM		2
#define MAX_PLATE_FILTER_NUM			32
typedef struct tagItsPlateFilterParam
{
	int		iSize;
	int		iChanNo;
	int		iFilterType;									//Filter type: 0-white list, 1:-blacklist
	int		iPlateFilterNum;								//Filter num, max 32
	char	cPlateFilterInfo[MAX_PLATE_FILTER_NUM][LEN_32];	//Plate Filter Info
}ItsPlateFilterParam, *pItsPlateFilterParam;

typedef struct tagTemperaturePosition
{
	int		iSize;
	int		iTempPosition;									//0-reserved, 1-face, 2-eye socket
}TemperaturePosition, *pTemperaturePosition;

typedef struct tagCalibrateCheck
{
    int					iSize;			
    int					iSceneId;		    // 0-32
    int					iStartPointX;		//万分比坐标0-10000
    int					iStartPointY;		//万分比坐标0-10000
    int					iEndPointX;			//万分比坐标0-10000
    int					iEndPointY;			//万分比坐标0-10000

}CalibrateCheck,*pCalibrateCheck;

typedef struct tagCalibrateCheckResult
{
    int					iSize;			
    int					iSceneId;		    // 0-32
    int					iStartPointX;		//万分比坐标0-10000
    int					iStartPointY;		//万分比坐标0-10000
    int					iEndPointX;			//万分比坐标0-10000
    int					iEndPointY;			//万分比坐标0-10000
    int                 iResult;			// 0-SUCCESS，1-FAILED
} CalibrateCheckResult, *pCalibrateCheckResult;

typedef struct tagWirelessSilent
{
	int						iSize;
	int						iRestartTime;						//重启时间
	int                     iResult;			                // 0-SUCCESS，1-FAILED
}WirelessSilent, *pWirelessSilent;
#define WATER_FLOW_CONTROL_TYPE_DEFAULT		0
#define WATER_FLOW_CONTROL_TYPE_ADD	        1
#define WATER_FLOW_CONTROL_TYPE_EDIT		2
#define WATER_FLOW_CONTROL_TYPE_DEL		    3
#define WATER_FLOW_CONTROL_TYPE_MAX		    4
typedef struct tagWaterFlowRef
{
	int  iSize;
	int  iControl; //0保留、1添加、2编辑、3删除、
	int  iNum;     //编号	1~1000
	int  iWaterLevel;//水位值	-10000000~10000000，单位毫米(mm)
	int  iWaterFlow;//水流量值	0~100000000，单位立方分米/秒(dm3/s)
	int  iWaterSpeed;//水流速	0~30000，单位：毫米/秒(mm/s)
}WaterFlowRef, *pWaterFlowRef;

typedef struct tagWaterFlowRefResult
{
	int  iSize;
	int  iControl; //0保留、1添加、2编辑、3删除、
	int  iNum;     //编号	1~1000
	int  iWaterLevel;//水位值	-10000000~10000000，单位毫米(mm)
	int  iWaterFlow;//水流量值	0~100000000，单位立方分米/秒(dm3/s)
	int  iResult;   //0-成功 1-超出最大个数限制错误 2-设置参数超出范围错误
	int  iWaterSpeed;//'0~30000，单位：毫米/秒(mm/s)
} WaterFlowRefResult, *pWaterFlowRefResult;


typedef struct tagWaterTotalInfo
{
	int iNum;
	int iWaterLevel;
	int iWaterFlow;
	int iWaterSpeed;
}WaterTotalInfo, *pWaterTotalInfo;

#define SDK_MAX_DATA_NUM  64
typedef struct tagWaterFlowRefInfo
{
	int  iSize;
	int  iTotalCount;
	int  iPacketIndex;
	int  iCurPacketNum;
	WaterTotalInfo tInfo[SDK_MAX_DATA_NUM];
}WaterFlowRefInfo, *pWaterFlowRefInfo;

typedef struct tagVCA_GaugeInfoPoint
{
	int  iSize;
	int  iPointx;
	int  iPointy;
	int  iGaugeValue;
}VCA_GaugeInfoPoint, *pVCA_GaugeInfoPoint;

#define   MAX_GAUGEINFO_NUM 10
typedef struct tagGaugeInfo
{
	int    iSize;
	int    iSceneId; //场景编号	0~31  （默认使用0~15）
	int    iRuleID;  //规则ID(预留)	0~15   （默认使用 0）
	int    iGaugeNo; //int	水尺编号	0：无效  大于0为水尺编号
	int    iGaugeAltitude;//水尺高程 -10000000~10000000单位mm
	int    iGaugeID;//0：无效  大于0为水尺序号
	int    iGaugeType; //0-保留 1-宽尺、新尺 2-窄尺、旧尺（注意与算法对应转换）3-特制水尺,支持自标定  4-方块水尺,支持自标定（只用于积水深度算法） 5-桩式水尺，支持自标定 6-无水尺 7-虚拟水尺 8-桩式水尺(纵向接力) 9-无水尺(纵向接力)
	int    iReferNum;  //0~10
	VCA_GaugeInfoPoint  tPoint[MAX_GAUGEINFO_NUM];//坐标参数为万分比
	int    iGaugeValue; //水尺读数	-10000000~10000000单位mm
	int    iGaugeLength;//水尺长度（单位mm）iGaugeType=5桩式水尺横向接力时有效，注意转换，算法单位m iGaugeType=8桩式水尺纵向接力时有效，注意转换，算法单位m 
	int    iBlcEnable;//背光补偿使能	0-保留，1-开启，2-关闭
	CommonRECT tRect;//水尺矩形区域对角线坐标,坐标为万分比
	int	   iGaugeBaseValue; //水尺基准水尺读数	当前水位对应此组水尺的真实读数，范围：-10000000~10000000, 单位：mm（注意转换，算法单位m）
	int    iGaugeCalibNum; //水尺标定预置位个数	支持水尺标定预置位的个数，范围：1～20
	int    iGaugeCalibType; //水尺标定类型	0-保留 1-自标定 2-手动标定 3-倾角或垂直角度标定
}GaugeInfo, *pGaugeInfo;

typedef struct tagVcaGaugeCalib
{
	int						iSceneID;
	int						iRuleID;
	int						iGaugeGroupID;  //水尺组号	1~20 (与VCA*GAUGEINFO协议的iGaugeId对应)
	int						iGaugeCalibID;  //水尺每组标定预置位的序号	1~20
	int						iGaugeValue;    //视频中心点水尺读数	-10000000~10000000单位mm
	int						iReferNum;      //标定点个数	0~10
	VCA_GaugeInfoPoint		tPoint[MAX_GAUGEINFO_NUM];//坐标参数为万分比
}VcaGaugeCalib, *pVcaGaugeCalib;

typedef struct tagGaugeCalibQuery
{
	int				iSceneID;
	int				iRuleID;
	int				iGaugeGroupID; //水尺组号	1~20 (与VCA*GAUGEINFO协议的iGaugeId对应)
	int				iGaugeCalibID; //水尺每组标定预置位的序号	0-可以查询此组水尺所有标定参数 1~20-查询此组水尺当前序号的标定参数
}GaugeCalibQuery, *pGaugeCalibQuery;


typedef struct tagGaugeCalibQueryResult
{
	int						iSize;
	int						iSceneID;
	int						iRuleID;
	int						iGaugeGroupID;
	int						iGaugeCalibID;
	int						iResult;				  //询操作结果	0-无数据 >0为返回查询结果条数
	int						iGaugeValue;			  //视频中心点水尺读数	-10000000~10000000单位mm
	int						iReferNum;
	VCA_GaugeInfoPoint		tPoint[MAX_GAUGEINFO_NUM];//坐标参数为万分比
}GaugeCalibQueryResult,*pGaugeCalibQueryResult;

typedef struct tagVCASmartMove
{
	int					iSize;								
	VCARule				tRule;
	int					iTargetTypeCheck;		//0: do not distinguish 1: distinguish people 2: distinguish cars 3: distinguish people and vehicles
	int					iSensitivity;			//[0, 100]
	int					iRegionNum;
	vca_TPolygonEx		stPoints[MAX_DETECT_AREA_NUM];			//The number of vertices of the polygon area and coordinate
	int					iUserDefult;			//0 - use custom parameter 1 - use default parameter, default value is 1
	int					iAlramTime;				//The default value of [0, 100] seconds is 3, which is valid when the iusedefault value is 0
	int					iMinSize;				//[0, 100] the default value of 5 is valid when the iusedefault value is 0
	int					iMaxSize;				//[0, 100] the default value is 30, which is valid when the iusedefault value is 0
}VCASmartMove, *pVCASmartMove;


typedef struct tagSingleCutPicFeature
{
	int		iSize;
	int		iChanNo;
	int		iSceneId;		//Scene ID 1-16
	int		iCutPicEnable;	//Feature cutout enabled 0-disenable 1-enable						
	int		iCutRange;		//Cutout range 4-1/4   9-1/9  16:-1/16
	int		iSourcePic;		//Cutout choice 0: Excellent 1: First sheet 2: Second sheet
	int		iOsdEnable;		//Character overlay enablement 0-disenable 1-enable
}SingleCutPicFeature, *pSingleCutPicFeature;

typedef struct tagTrafficFillLight
{
	int		iSize;
	int		iChanNo;
	int		iOpenVal;		//0-100 Open  light threshold
	int		iCloseVal;		//0-100 Close light threshold
}TrafficFillLight, *pTrafficFillLight;

#define MAX_DEFAULT_TEMPLATE_LIST_NUM   18  
typedef struct tagDefaultTemplateList
{
    int    iSize;
    int    iType;           //算法类型
    int    iDaytimeDef;     //默认日间模板
    int    iEveningDef;     //默认夜间模板
}DefaultTemplateList, *pDefaultTemplateList;


#define ITS_EBIKE_CITY_MAX_NUM	2
#define PROVINCE_TIANJIN		0xC0000
#define CITY_GUANGXI_YULIN		0x2D0009

typedef struct tagItsEbikePlate
{
	int		iSize;
	int		iChanNo;
	int		iCodeNo;		//City code number Currently only supported 2 city
	int		iEnable;		//0- no enable, 1- enable
}ItsEbikePlate, *pItsEbikePlate;

#define MAX_COFE_NUM 20
typedef struct tagCofeInfo
{
	int     iSize;
	int     iWaterLevel;
	int     iCoef;
}CofeInfo, *pCofeInfo;

typedef struct tagVerTiCallIne
{
	int       iSize;
	int       iSceneId;
	int       iControl;
	int       iVLineId;
	int       iStartDistance;
	int       iBottomAltitude;
	int       iCoefNum;
	CofeInfo  tInfo[MAX_COFE_NUM];
	int       iResult;
}VerTiCallIne, *pVerTiCallIne;

typedef struct tagVerTiCallIneGet
{
	int        iSize;
	int        iSceneId;	//场景ID	0～31 预留
	int        iPageNo;	    //页码	iPageNo>=0
	int        iPageSize;	//int	每页条数	iPageSize>=0 最大20
	int        iVLineIdStart; //int	查询垂线的开始序号	1～101
}VerTiCallIneGet, *pVerTiCallIneGet;

typedef struct tagVerTiCallIneResult
{
	int        iSize;
	int        iSceneId;	//int	场景ID	0～31 预留
	int        iTotal;	//int	总条数	iTotal>=0
	int        iPageNo;	//int	页码	iPageNo>=0
	int        iPageSize;	//int	当前页条数	iPageSize>=0
	int        iIndex;	//int	页码内序号	iIndex>=0
	int        iVLineId;	//int	垂线序号	1~101
	int        iStartDistance;	//int	垂线起点距	范围:0～10000000,单位:mm
	int        iBottomAltitude;	//int	垂线河底高程	范围:-10000000～10000000,单位:mm
	int        iMeasuredTime;	//int	垂线实测时间	时间(utc)
	int        iCoefNum;	//int	垂线区域流速系数个数	1～20
	CofeInfo   tInfo[MAX_COFE_NUM];
}VerTiCallIneResult, *pVerTiCallIneResult;

typedef struct tagVcaWaterFlow
{
	int   iSize;
	int   iSceneId;	//int	场景编号	0～31  （默认使用0～15）
	int   iFlowCoef;	//int	流量系数	范围:0～10000，软件取值后除以1000.0转换成float
	int   iFlowSource;  //流量来源	0-水利前端设备计算(默认) 1-查询人工表数据 2-稳定河道(公式) 3-水堰水量(公式)
	int   iWaterSlope;  //水面比降系数	"iFlowSource=2稳定河道时有效,系数乘以10000
	int   iRoughness;   //河床糙率系数	"iFlowSource=2稳定河道时有效,系数乘以10000
	int   iWeirFlow;    //堰流系数系数	"iFlowSource=3水堰水量时有效,系数乘以10000
}VcaWaterFlow, *pVcaWaterFlow;



typedef struct tagAliSecret
{
	int   iSize;
	char  pcPK[LEN_64]; //设备pk
	char  pcPS[LEN_64];	//设别ps
	char  pcDN[LEN_64];	//设备DN
	char  pcDS[LEN_64];	//设备DS
	int   iChannelNo;
}AliSecret,*pAliSecret;

typedef struct tagAliSecretResult
{
	int   iSize;
	int   iResult;  //设置结果
	int   iChannel;
}AliSecretResult,*pAliSecretResult;

//xml协议设置、获取参数使用以下结构体
typedef struct tagXmlResponseStatus
{
	int iStatusCode; //状态码：0=1-OK, 2-Device Busy, 3-Device Error, 4-Invalid Operation, 5-Invalid XML Format, 6-Invalid XML Content, 7-Reboot Required
	char cStatusString[LEN_64];
	char cSubStatusCode[LEN_64];
} XmlResponseStatus,* pXmlResponseStatus;

typedef struct tagXmlRegistrationCenter
{
	int		iStructSize;
	char	cServerName[LEN_32];
	char	cRegIp1[LEN_128];
	int		iRegPort1;
	char	cRegIp2[LEN_128];
	int		iRegPort2;
	char	cAccount[LEN_32];
	char	cPassword[LEN_32];
} XmlRegistrationCenter, *pXmlRegistrationCenter;

#define TIMING_MODE_RESERVED		0
#define TIMING_MODE_NTP				1		
#define TIMING_MODE_GPS				2
#define TIMING_MODE_MANUAL			3
#define TIMING_MODE_ONVIF			4
typedef struct tagXmlDeviceSystemTime
{
	int						iTimingMode;			//0-保留 1-NTP校时 2-GPS校时 3- 手动 4-ONVIF协议校时
	NVS_FILE_TIME			tLocalTime;
	int						iTimeZoneDiffHour;		//与国际标准时间的时差（小时），-12 ... +13 
	int						iTimeZoneDiffMinute;	//与国际标准时间的时差（分钟），0, 30, 45
	int						iTimeZoneDiffSecond;	//与国际标准时间的时差（秒数），0, 30, 45 
	//Daylight Saving Time parameter
	int						iDstEnable;				//DaylightSavingTime enable, 0-disable, 1-enable
	int						iDstOffsetTime;			//DaylightSavingTime Offset time,0～120（unit：minute）
	int						iDstStartMonth;			//Start daylight saving time: month
	int						iDstStartWeek;			//Start daylight saving time: week of month, (0:last 1:first 2:second 3:third 4:forth)
	int						iDstStartDay;			//Start daylight saving time: day Of week, sunday to saturday is 0-6
	int						iDstStartHour;			//Start daylight saving time: hour of day [0～23]
	int						iDstStopMonth;			//Stop daylight saving time: month
	int						iDstStopWeek;			//Stop daylight saving time: week of month, (0:last 1:first 2:second 3:third 4:forth)
	int						iDstStopDay;			//Stop daylight saving time: day Of week, sunday to saturday is 0-6
	int						iDstStopHour;			//Stop daylight saving time: hour of day [0～23]）

} XmlDeviceSystemTime, *pXmlDeviceSystemTime;

//Ntp Server parameter
typedef struct tagXmlNtpServer
{
	char					cNtpServerIp[MAX_IPADDRESS_LEN];	//NTP Server IP, support ipv6
	int						iNtpServerPort;						//NTP Server Port
	int						iNtpInterval;						//ntp校时间隔时间，以分钟为单位
} XmlNtpServer, *pXmlNtpServer;


#define MAX_WORDOVERLAY_POSNO  7
typedef struct tagWordOverLayPos
{
	int     iSize;
	int     iLayNo;
	int     iAlignFormat;
	int     iDistance;
}WordOverLayPos, *pWordOverLayPos;

typedef struct tagIrriServerInfo
{
	int  iSize;
	char pcIrrigationIP[LEN_32]; //水利平台服务器IP
	int  iIrrigationPort;       //水利平台服务器端口
	char pcStationAddress[LEN_32];//水利平台测站地址
}IrriServerInfo, *pIrriServerInfo;

typedef struct tagIrrigationServerInfo
{
	int  iSize;
	IrriServerInfo tServerInfo[LEN_4];
}IrrigationServerInfo, *pIrrigationServerInfo;

typedef struct tagT4GParam
{
	int      iSize; 
	int      i3GDeviceType;   //设备类型	0,DTM-移动3G; 1,EVDO-电信3G; 2,WCDMA-联通3G，3，未识别；4-TDD移动4G；5-电信4G；6-联通4G；7-移动网络
	int      iStatus;         //在线状态	0,未上线；1，已上线；2，拨号中	
	int      iIntensity;      //信号强度	数字，对应含义待测
	char     pcIP[LEN_16];    //拨号ip	ppp0的IP地址
	char     pcStarttime[LEN_64];//初始拨号时间	开始拨号的时间戳，格式为  "YYYY/MM/DD HH:MM:SS"
	char     pcIMEI[LEN_32];  //GSM模块的IMEI（国际移动设备标识）序列号
	char     pcICCID[LEN_32]; //SIM卡的ICCID标识
}T4GParam, *pT4GParam;	

typedef struct tagPuInfo
{
	int                         iSize;
	char    					cDeviceID[LEN_64];		
	char    					cDeviceName[LEN_64];
	unsigned short    			wVspPort;
	char    					cPassword[LEN_64];
	unsigned short    			wVapPort;
}PuInfo, *pPuInfo;

#define MAX_KFK_SERVER_COUNT  32
#define MAX_KFK_CAMERA_COUNT  8
typedef struct tagCpcAreaDisplay
{
	int                         iSize;
	int    						iDevType;	//设备类型0:IPC,1:NVR
	int    						iDisplay;	//显示方式:1: 显示客流量统计界面 2: 退出客流量统计界面
	int    						iAreaNo ;	//当前显示区域0-19
}CpcAreaDisplay, *pCpcAreaDisplay;

typedef struct tagITSKfkCameraCount
{
	int     iSize;
	char    pcCameraNo[LEN_16];
	char    pcItsHostNo[LEN_16];
	char    pcSectionNo[LEN_16];
}ITS_KfkCameraCount, *pITSKfkCameraCount;

typedef struct tagItsKfkServerInfo
{
	int     iSize;
	char    pcServerIP[LEN_16];
	int     iServerPort;
}Its_KfkServerInfo, *pItsKfkServerInfo;

typedef struct tagITSKafkaCfg
{
	int					iSize;
	int                 iDockingType;
	int					iKfaUploadType;	  
	char                pcKkTopic[LEN_64];
	char                pciLLegalTopic[LEN_64];
	char                pcPointNum[LEN_64];
	int                 iCameraCount;
	ITS_KfkCameraCount  tCameraNum[MAX_KFK_CAMERA_COUNT];
	int                 iKfkServerCount;
	Its_KfkServerInfo   tServerNum[MAX_KFK_SERVER_COUNT];
}ITS_KafkaCfg, *pITSKafkaCfg;
#define  MAX_CPC_AREA_NUM 20
typedef struct tagCpcAreaConfig
{
	int                         iSize;
	int    						iAreaNo ;								 //当前显示区域0-19
	int                         iMask[LEN_32];							 //通道掩码每个bit表示与对应通道关联，0:不关联 1:关联
	int                         iMaskCount;                              //通道掩码有效数量
	int							iEnable;								 //0: 禁能 1: 使能
	char						cName[LEN_64];							 //区域名称
	int                         iCurPeople;							     //当前人数
	int    						iMaxPeople;								 //最大允许人数
	int                         iClearMode;								 //清零方式1: 每天 2: 从不
	int							iHour;									 //清零小时 0-23
	int							iMinute;								 //清零分钟 0-59

}CpcAreaConfig, *pCpcAreaConfig;

typedef struct tagCpcAreaStatus
{
	int        iSize;
	int        iAreaNo;	//区域编号	0～19 
}CpcAreaStatus, *pCpcAreaStatus;

typedef struct tagCpcAreaStatusResult
{
	int							iSize;
	int							iAreaNo;								 //区域编号	0～19 
	char						cName[LEN_64];							 //区域名称
	int                         iCurPeople;							     //当前人数
	int    						iMaxPeople;								 //最大允许人数
	int                         iStartTime;								 //本次统计开始时间,1970年1月1日0点到本次开始统计的秒数

}CpcAreaStatusResult, *pCpcAreaStatusResult;

typedef struct tagCpcAreaManualClear
{
	int			iSize;
	int			iAreaNo;	//区域编号	0～19 
}CpcAreaManualClear, *pCpcAreaManualClear;

typedef struct tagCpcAreaManualClearResult
{
	int			iSize; 
	int			iResult;	//0: 成功 1: 失败
}CpcAreaManualClearResult, *pCpcAreaManualClearResult;

#define MAX_BAN_TIME_COUNT		4
typedef struct tagVcaInquiryTimeout
{
	int					iSize; 
	int					iDevType;											//0-IPC, 1-NVR
	int					iRuleID;											//rule Id, 0～7
	int					iSceneId;											//scene Id,0~15
	int					iValid;
	int					iDisplayRule;
	int					iDisplayStat;
	int					iDisplayTarget;
	int					iMiniSize;
	int					iMaxSize;
	int					iSensitivity;
	int					iInquiryTime;
	int					iLeaveTime;
	int					iBantimeNum;
	DayScheduleTime		tBanTime[MAX_BAN_TIME_COUNT];
	int					iDetectRegionNum;
	vca_TPolygonEx		tDetectRegions[MAX_AREA_COUNT];	
	int					iInvalidRegionNum;
	vca_TPolygonEx		tInvalidRegions[MAX_AREA_COUNT];
}VcaInquiryTimeout, *pVcaInquiryTimeout;

typedef struct tagCommonAlarmNotify
{
	int					iSize;
	int					iChanNo;
	int					iState;
	int					iAddlPara1;
	int					iAddlPara2;
	int					iAddlPara3;
	int					iAddlPara4;
	char                cAlarmTime[LEN_32];
}CommonAlarmNotify,*pCommonAlarmNotify;

typedef struct tagTdServerSysParam
{
	int					iSize;
	char				cSystemUuid[LEN_64];
	char				cBaseboardSerialNumber[LEN_64];
}TdServerSysParam,*pTdServerSysParam;

typedef struct tagTrafficViolationPara
{
	int				iSize;
	int				iChanNo;
	int				iCallSensitivity;
	int				iNoSeatBeltSensitivity;		
}TrafficViolationPara, *pTrafficViolationPara;

typedef struct tagWstAbleUseMode
{
	int        iSize;         //结构体大小
	int        iSceneId;      //int	场景ID	0～31 预留
	int        iUseMode;      //使用时的工作模式	0-自动 1-手动开启 2-手动关闭 3-定时
	int        iStartHour;    //定时使用开始时间	单位:小时 范围:0-23 iMode=3定时模式有效
	int        iStartMin;     //定时使用开始分钟	单位:分钟 范围:0-59 iMode=3定时模式有效
	int        iStopHour;     //定时使用结束时间	单位:小时 范围:0-23 iMode=3定时模式有效
	int        iStopMin;      //定时使用结束分钟	单位:分钟 范围:0-59 iMode=3定时模式有效
	int        iDetectTimeOut;//检测超时时间	单位:秒 范围:1-7200 iMode=0自动模式有效
	int        iTableOption;  //流速表来源选择	0-使用自动流速表 1-使用手动流速表
}WstAbleUseMode, *pWstAbleUseMode;

typedef struct tagWsTableAutoGen
{
	int        iSize;
	int        iSceneId;       //场景ID	0～31 预留
	int        iAutoUpdate;    //自动更新流速表	0-停止更新  1-开启更新
	int        iWaterLevelMax; //水位最大值	范围:-10000000～10000000，单位:毫米(mm)
	int        iWaterLevelMin; //水位最小值	范围:-10000000～10000000，单位:毫米(mm)
	int        iStartHour;    //生成开始时间	单位:小时 范围:0-23
	int        iStartMin;     //生成开始分钟	单位:分钟 范围:0-59 
	int        iStopHour;     //生成结束时间	单位:小时 范围:0-23 
	int        iStopMin;      //生成结束分钟	单位:分钟 范围:0-59
}WsTableAutoGen, *pWsTableAutoGen;

typedef struct tagWsTableQuery
{
	int   iSize;
	int   iSceneId;		//场景ID	0～31 预留
	int   iPageNo;		//页码	iPageNo>=0
	int   iPageSize;	//每页条数	iPageSize>=0 最大20条
	int   iVlineArea;	//垂线区域号	0:代表所有垂线区域  1~100:垂线区域索引 
	int   iWaterLevelStart;	//水位区间起始值	范围:-10000000~10000000，单位:毫米(mm)
	int   iWaterLevelStop;	//水位区间结束值	范围:-10000000~10000000，单位:毫米(mm)
}WsTableQuery, *pWsTableQuery;

typedef struct tagWstableContent
{
	int      iSize;
	int      iPageIndex;	//当前页内数据的序号	iIndex>=0
	int	     iNum;	        //当前页内数据的唯一索引号	1-50000
	int	     iVlineArea;	//当前页内数据的垂线区域号	1~100:垂线区域索引 
	int	     iWaterLevel;	//当前页内数据的水位值	-10000000~10000000，单位毫米(mm)
	int	     iWaterSpeed;	//当前页内数据的水流速值	0~30000，单位：毫米/秒(mm/s)
	int	     iWaterFlow;	//当前页内数据的水流量值	0~100000000，单位立方分米/秒(dm?/s)
}WstableContent, *pWstableContent;

typedef struct tagWsTableQueryResult
{
	int      iSize;
	int      iSceneId;		//场景ID	0～31 预留
	int	     iTotal;		//总条数	iTotal>=0
	int	     iPageNo;		//页码	iPageNo>=0
	int	     iPageSize;		//当前页条数	iPageSize>=0
	int	     iPagePktNum;	//当前页本次包的数据个数	iPagePktNum >= 0
	WstableContent  tWsTableContent[LEN_20];//数据内容 最多20条；
}WsTableQueryResult, *pWsTableQueryResult;


typedef struct tagWsTableOpt
{
	int      iSize;
	int      iSceneId;		//场景ID	0～31 预留
	int  	 iControl;		//操作类型	0保留、1添加、2编辑、3删除
	int  	 iNum;		//唯一索引号	1-50000
	int 	 iVlineArea;		//垂线区域	1~100:垂线区域索引 
	int  	 iWaterLevel;		//水位值	-10000000~10000000，单位毫米(mm)
	int      iWaterSpeed;		//水流速	0~30000，单位：毫米/秒(mm/s)
	int  	 iWaterFlow;		//水流量值	0~100000000，单位立方分米/秒(dm?/s)*/
}WsTableOpt, *pWsTableOpt;


typedef struct tagWsTableOptResult
{
	int      iSize;
	int      iSceneId;		//场景ID	0～31 预留
	int  	 iControl;		//操作类型	0保留、1添加、2编辑、3删除
	int  	 iNum;		//唯一索引号	1-50000
	int 	 iVlineArea;		//垂线区域	1~100:垂线区域索引 
	int  	 iWaterLevel;		//水位值	-10000000~10000000，单位毫米(mm)
	int      iWaterSpeed;		//水流速	0~30000，单位：毫米/秒(mm/s)
	int  	 iWaterFlow;		//水流量值	0~100000000，单位立方分米/秒(dm?/s)
	int      iResult;		//操作结果	0-成功	1-超出最大个数限制错误	2-设置参数超出范围错误"
}WsTableOptResult, *pWsTableOptResult;


typedef struct tagWaterLevelFlowQuery
{
	int      iSize;
	int      iSceneId;		//场景ID	0～31 预留
	int   	 iPageNo;		//页码	iPageNo>=0
	int  	 iPageSize;		//每页条数	iPageSize>=0 最大20条
	int  	 iWaterLevelStart;		//水位区间起始值	范围:-10000000~10000000，单位:毫米(mm)
	int  	 iWaterLevelStop;		//水位区间结束值	范围:-10000000~10000000，单位:毫米(mm)*/
}WaterLevelFlowQuery, *pWaterLevelFlowQuery;

typedef struct tagWaterFlowContent
{
	int      iSize;
	int      iPageIndex;	//当前页内数据的序号	iIndex>=0
	int	     iNum;	        //当前页内数据的唯一索引号	1-1000
	int	     iWaterLevel;	//当前页内数据的水位值 -10000000~10000000，单位毫米(mm)
	int	     iWaterSpeed;	//当前页内数据的流速值 0~30000，单位：毫米/秒(mm/s)
	int	     iWaterFlow;	//当前页内数据的流量值 0~100000000，单位立方分米/秒(dm?/s)
}WaterFlowContent, *pWaterFlowContent;

typedef struct tagWaterLevelFlowQueryResult
{
	int      iSize;
	int      iSceneId;		//场景ID	0～31 预留
	int	     iTotal;		//总条数	iTotal>=0
	int 	 iPageNo;		//页码	iPageNo>=0
	int 	 iPageSize;		//当前页条数	iPageSize>=0
	int 	 iPagePktNum;   //当前页本次包的数据个数(N)	iPagePktNum >= 0
	WaterFlowContent  tContent[LEN_20];
}WaterLevelFlowQueryResult, *pWaterLevelFlowQueryResult;


#define DATA_FROM_RADAR		0
#define DATA_FROM_ALGO		1
#define MAX_DATA_SOURCE		2
typedef struct tagIrriGationRecord
{
	int                  iSize;
	int                  iType;		     //记录分类	参考水利上报信息类型
	unsigned long long   iSeqStart;		//查询开始序号	iSeqStart>0
	unsigned long long 	 iSeqStop;		//查询结束序号	iSeqStop>0
	int 	             iPageNo;		//当前页号	iPageNo>=0
	int 	             iPageSize;		//每页条数	iPageSize>=0 最大20条*/
	int                  iQueryType;    //查询条件类型	0-按序号段查询 1-按时间段查询
	NVS_FILE_TIME        tStartTime;    //开始时间
	NVS_FILE_TIME        tEndTime;		//结束时间
}IrriGationRecord, *pIrriGationRecord;

typedef struct tagIrriGationRecordEx
{
	int                  iSize;
	int                  iType;		     //记录分类	参考水利上报信息类型
	unsigned long long   iSeqStart;		//查询开始序号	iSeqStart>0
	unsigned long long 	 iSeqStop;		//查询结束序号	iSeqStop>0
	int 	             iPageNo;		//当前页号	iPageNo>=0
	int 	             iPageSize;		//每页条数	iPageSize>=0 最大20条*/
	int                  iQueryType;    //查询条件类型	0-按序号段查询 1-按时间段查询
	int                  iStartTime;    //开始时间
	int                  iEndTime;		//结束时间
}IrriGationRecordEx, *pIrriGationRecordEx;

typedef struct tagIrriGationRecordResult
{
	int                  iSize;
	int                  iType;		     //记录分类	参考水利上报信息类型
	unsigned long long   iSeqStart;		//查询开始序号	iSeqStart>0
	unsigned long long 	 iSeqStop;		//查询结束序号	iSeqStop>0
	int 	             iPageNo;		//当前页号	iPageNo>=0
	int 	             iPageSize;		//每页条数	iPageSize>=0 最大20条*/
	unsigned long long   iTotal;	//总条数	iTotal>=0
	int                  iResult;	//查询结果	"0-成功 1-超出最大个数限制错误 2-读写错误	
	int                  iMaxSeqNo;//此类型记录的最大序号
}IrriGationRecordResult, *pIrriGationRecordResult;

//远程执行cmd命令
typedef struct tagRemoteCmdShell
{
	int       iSize;            //结构体大小
	char      cCmdString[LEN_128];  //命令字符串
	int       iRetLimit;        //	执行结果条数限制
}RemoteCmdShell, *pRemoteCmdShellCmdShell;

//远程执行Cmd命令结果
typedef struct tagRemoteCmdShellResult
{
	int      iSize;             //结构体大小
	int      iIndex;            //回执序号；
	char     cResultString[LEN_512];//回执字符串，最大512
}RemoteCmdShellResult, *pRemoteCmdShellResult;

//设置条形码
typedef struct tagBarCode
{
    char			cBarCode[LEN_64];			//条形码
    char            cAliSn[LEN_64];             //阿里云SN
} BarCode, *pBarCode;

//http推图参数/推图测试命令
typedef struct tagHttpPicStream
{
	int				iSize;
	char			cIPAdress[256];
	char			cURL[256];
	char            cUserName[64];
	char			cPassWord[64];
	int				iPort;
}HttpPicStream,*pHttpPicStream;

//http推图参数/推图测试命令
typedef struct HttpPicStreamEx
{
	int				iSize;
	char			cIPAdress[256];
	char			cURL[256];
	char            cUserName[64];
	char			cPassWord[64];
	int				iPort;
	int				iProtocalType; // 0:http,1:https
}HttpPicStreamEx,*pHttpPicStreamEx; //以后推图测试协议扩展的话扩展这个

#define MAX_HTTP_SERVER_NUM 32

typedef struct tagHttpPicStreamParam
{
	int				iServerNum;
	HttpPicStream	tHttpPicStream[MAX_HTTP_SERVER_NUM];
	int				iProtocolType[MAX_HTTP_SERVER_NUM]; //0:http;1:https
}HttpPicStreamParam,*pHttpPicStreamParam;

//推图测试命令回复
typedef struct tagHttpPicTestResult
{
	int      iSize;				     //结构体大小
	int      iResult;                //结果
}HttpPicTestResult, *pHttpPicTestResult;

#define MAX_CHECK_RULE_REGION_NUM 8
//室内电动车检测
typedef struct tagVCAIndoorEBike
{
	int                 iSize;
	int					iDevType;								//0-IPC，1-NVR
	VCARule				tRule;
	int                 iDisplayRule;                           //0-hide 1-show
	int					iDisplayTarget;                         //0-hide 1-show
	int					iMaxSize;								//[0-100] 25
	int					iMinSize;								//[0-100] 8
	int					iSensitivity;							//[0-100] 50
	int					iAlarmTime;								//[2-3600] 2s
	int                 iRegionNum;								//[0-8]
	vca_TPolygon        tPolygon[MAX_CHECK_RULE_REGION_NUM];			//The number of vertices of the polygon area and coordinate 
}VCAIndoorEBike, *pVCAIndoorEBike;

#define RET_GAT1400_STATUS_RESERVED         0
#define RET_GAT1400_STATUS_ONLINE           1

typedef struct tagGat1400StatusResult
{
    int		iSize;  //[IN]结构体大小
    int     iResult; //[OUT] RET_GAT1400_STATUS_RESERVED：预留RET_GAT1400_STATUS_ONLINE：在线 其他 ：其他不在线
}Gat1400StatusResult, *pGat1400StatusResult;

#define MAX_GAT1400_CHANNEL_COUNT 32
typedef struct tagGat1400Para
{
    int        iSize;               //结构大小
    int        iChannelNo;          //通道号	通道号
    int        iEnable;		        //是否使能	0不使能，使能
    char       cIpAddress[LEN_256];//ip地址	不超过字节
    int        iPort;               //服务器端口	1-65535
    char       cDeviceID[LEN_256]; //	设备编号	不超过字节
    char       cUserName[LEN_128]; //	账户名	不超过字节
    char       cPassWord[LEN_128]; //	密码	不超过字节
    int        iHeartBeatInterval;  //		心跳间隔时间	单位秒,范围~255秒
    int        iHeartBeatTimes; 		    //心跳次数	范围~255
    char       cPlaceCode[LEN_64]; //行政代码	不超过字节
    int        iLongitude;  		//经度	范围-36000 对应-180~+180，精确到.01   (-E +W)
    int        iLatitude;           //纬度	范围-18000 对应-90~+90，精确到.01     (-S +N)
    int        iTimingEnable;		//启用校时	0为关闭，为开启
    int        iRetryTimes;         //		重发次数	范围~3
    int        iRetryInterval;      //	重发间隔	单位秒,范围~5秒
    int        iTimingInterval;     //校时时间间隔	单位秒，范围-3600
    int        iConfFileNo;         //		配置文件编号	范围-100
    int        iChannelCount;       //		通道个数	设置支持通道个数n  n不超过32
    int        iChannelNoArr[MAX_GAT1400_CHANNEL_COUNT]; //第一个通道号0   （通道号值0~n-1）
    char 	   cChannelNumberArr[MAX_GAT1400_CHANNEL_COUNT][LEN_64]; //通道编号数组
}Gat1400Para, *pGat1400Para;

typedef struct tagDevRealTimeParam
{
	 int       iChannelNo;          //通道号
	 int	   iVoltageValue;       //电压值网络传送设备电压值*10。实际电压值=iVoltageValue/10，单位是V（伏特）
	 int       iQuantityper;        //电量剩余百分比，实际值除以10
	 int       iDeviceStatus;       //设备功耗状态 0：正常状态，1：低功耗状态
}DevRealTimeParam, *pDevRealTimeParam;

typedef struct tagVCALeaveDetectEx
{
	VCARule				tRule;
	vca_TDisplayParam   tDisplayParam;
	int					iLeaveAlarmTime;			// off-duty alarm time, 60 ~ 3600, in seconds, the default: 120S
	int					iRuturnClearAlarmTime;		// back to the police alarm time, 10 to 300, in seconds Default: 15S
	int					iDutyNum;					// [1,2] 默认1
	int					iMinSize;					// [1, 50] 默认 3
	int					iMaxSize;					// [5, 100] 默认 15
	int					iSensitivity;				// [0, 5] 默认 2	
	int					iDisplayTarget;             // 0-hide 1-show
	int					iAreaNum;					// Total number of rule fields, 1 ~ 4
	vca_TPolygon		tPolygon[MAX_RULE_REGION_NUM];	//	2~8。如果点数等于2是矩形 
	
}VCALeaveDetectEx, *pVCALeaveDetectEx;

typedef struct tagVcaRuleEvent15
{
	int iSize;
	int iChannelNo;
	int iSceneId;
	int iRuleId;
	int iDetDisturbFlag;
}VcaRuleEvent15,*pVcaRuleEvent15;

typedef struct tagCommonProgress
{
	int iSize;
	int iType;/*16-调用水利算法检测预置位*/
}CommonProgress, *pCommonProgress;

typedef struct tagCommonProgressResult
{
	int iSize;
	int iType;/*11-场景切换,16-调用水利算法检测预置位*/
	int iStatus;//进度状态
	int iPro;//进度值
}CommonProgressResult, *pCommonProgressResult;

typedef struct
{
    int iDiskNo;                        // disk No.
    int iFullFlag;                       // 0:not full, 1:full
}NVS_DISKINFOFIELD, *PNVS_DISKINFOFIELD;

#define DISK_NUM_MAX	100
typedef struct
{
    int iSize;
    int iDiskNum;                       // disk count
    int iParamNum;                      // param count
    NVS_DISKINFOFIELD stDiskInfos[DISK_NUM_MAX];    // 
}NVS_DISKINFOEX, *PNVS_DISKINFOEX;


#define PARAM_TYPE_RESERVED 0
#define PARAM_TYPE_INPUT    1
#define PARAM_TYPE_OUTPUT   2

typedef struct tagWIEGAND
{
    int				iSize;
    int             iChannelNo; //通道号
    int				iType;       //参数类型 0-保留，1-输入，2-输出
    int				iParam;     //参数当iType =1时：0-关闭，1-开启   当iType =2时：0-关闭，1- Wiegand26，2-Wiegand34 
    int             iOutData;   //韦根输出数据内容0-保留，1-编号，2-卡号
}WIEGAND, *pWIEGAND;

typedef struct tagEntranceGuardInfo
{
    int             iSize;
    int             iChannelNo;             //通道号
    int             iInfoType;              //上报信息类型:0-预留，1-门牌号，2-业主手机号
    char            cInfoData[LEN_64];      //上报信息内容
    char            cDeviceSN[LEN_64];      //设备SN号

}EntranceGuardInfo, *pEntranceGuardInfo;

typedef struct tagTalkRequest
{
    int             iSize;
    int             iChannelNo;             //通道号
    char            cDeviceSN[LEN_64];      //设备SN号

}TalkRequest, *pTalkRequest, TalkStop, *pTalkStop;

typedef struct tagTalkCoder {
    int iSize;
    int iAudioEncode;       //1 G711A，2 G711U，22 AAC
    int iSampleRate;        //实际采样率的值，如8000,16000,32000
} TalkCoder, *pTalkCoder;

#define MAX_DEVLOWPOWER_DAYSCHEDULE_COUNT		4

typedef struct _tagDayScheduleTimeEx
{
	int  				iStartHour;
	int  				iStartMin;
	int  				iStopHour;
	int  				iStopMin;		
} DayScheduleTimeEx, *PDayScheduleTimeEx;

typedef struct tagDeviceLowPower{
	int					iSize;
	int					iEnable;					//0-未启用，1-启用
	DayScheduleTimeEx	tDevLowPowerSchedule[MAX_WEEK_DAYS][MAX_DEVLOWPOWER_DAYSCHEDULE_COUNT];//0-6：Monday-Sunday
}DeviceLowPower, *pDeviceLowPower;

typedef struct tagLENPARA
{
	int				iSize;
	int             iChannelNo; //通道号
	int				iFocusOffsetValue; //聚焦补偿值 1000~21000
}LENPARA, *pLENPARA;

typedef struct tagItsChnLaneExParam
{
	int             iChannelNo;				//[in]通道号
	int				iSceneID;				//[in]场景ID 0-15
	int				iLaneNumber;			//[in]车道编号0-3
	int             iChannelSnapDirection;	//[out]车道抓拍方向0-双向，1-上行，2-下行
}ItsChnLaneExParam, *pItsChnLaneExParam;


typedef struct tagNasTest
{
	int			iDiskNo;			//磁盘编号
	int			iNasType;			//网络附属存储类型 1：NFS、2：CIFS、3：FTP、4：HTTP
	char		pcIP[LEN_256];		//ip地址
	int			iPort;				//端口
	char		pcMapPath[LEN_256];	//映射路径
	char		pcUserName[LEN_128];//用户名
	char		pcPassWord[LEN_128];//密码
}NasTest, *pNasTest;


typedef struct tagNasTestResult
{
	int			iDiskNo;		//磁盘编号
	int			iNasType;		//网络附属存储类型 1：NFS、2：CIFS、3：FTP、4：HTTP
	int			iResult;		//测试结果 0成功；其他失败
}NasTestResult, *pNasTestResult;

typedef struct tagItsDriveaWayLinkLight
{
	int				iChannelNo;
	int				iSceneId;				//场景ID：0-15
	int				iLinkType;				//联动类型：0：激光,1:白光
	int				iLinkEnable;			//0：使能，1：不使能
	int				iPlayType;				//亮灯方式	0：常亮  1：闪烁
	int				iPlayFrequency;			//亮灯频率 亮灯方式为闪烁时代表闪烁频率 1~5s 可选 其他无意义
	int				iContinuedTime;			//持续时间  10S-300S
}ItsDriWayLinLight,*pItsDriWayLinLight;

typedef struct tagAudioChannel
{
	char pcChannel[LEN_32];
}AudioChannel,*pAudioChannel;

typedef struct tagRtpServerInfo
{
	int		iStreamTyp;			//码流类型 1- 主码流；2- 副码流；3- 三码流					
	int		iEnable;			//是否使能	1-使能 0-不使能；每一路码流类型都对应一个使能控制					
	char	pcVideoAddress[LEN_64];		//视频服务器地址	最大长度为64字节（支持ipv6），不包含\0					
	int		iVideoPort;					//int	视频服务器端口	70-65535					
	int		iVideoTTL;			//int	视频保活时间	取值范围 1--128					
	char	pcAudioAddress[LEN_64];		//音频服务器地址	最大长度为64字节（支持ipv6），不包含\0					
	int		iAudioPort;			//音频服务器端口	70-65535					
	int		iAudioTTL;			//音频保活时间	取值范围 1--128					
	char	pcMetadataAddress[LEN_64];	 //Medatdata服务器地址	最大长度为64字节（支持ipv6），不包含\0					
	int		iMetadataPort;	//Medatdata服务器端口	70-65535					
	int		iMetadataTTL;	//Medatdata保活时间	取值范围 1--128					
}RtpServerInfo, *pRtpServerInfo;


typedef struct tagWaterDetectPos
{
	int			iSceneID;			//场景ID	0~31  （默认使用0~15）
	int			iRuleID;			//规则ID(预留)	0~15  （默认使用 0）
	int			iPosType;			//检测区域类型	0-水位检测
	int			iOperationType;		//操作类型	1-设置检测区域 2-调用检测区域 3-删除检测区域
	int			iGroundID;			//检测区域组号	0-保留 1～20为组号
	int			iPosID;				//检测预置位编号	"范围：0～32
}WaterDetectPos, *pWaterDetectPos;

typedef struct tagWaterDetectPosResult
{
	int			iSceneID;			//场景ID	0~31  （默认使用0~15）
	int			iRuleID;			//规则ID(预留)	0~15  （默认使用 0）
	int			iPosType;			//检测区域类型	0-水位检测
	int			iOperationType;		//操作类型	1-设置检测区域 2-调用检测区域 3-删除检测区域
	int			iGroundID;			//检测区域组号	0-保留 1～20为组号
	int			iPosID;				//检测预置位编号	"范围：0～32
	int			iResult;			//设置结果	"0-成功，非0表示失败 1-PTZ获取失败2-设置检测区域当前角度不合理 3-表示调用检测区域失败 4-表示删除检测区域失败 5-表示获取倾角仪角度失败"
	int			iPtzP;				//球机水平角度	p*1000
	int			iPtzT;				//球机垂直角度	t*1000
	int			iPtzZ;				//镜头变倍倍率	z*1000
	int			iAngleValue;		//倾角仪角度, 倾角仪角度乘以10000，单位是度，实际范围0-360
}WaterDetectPosResult, *pWaterDetectPosResult;


#define IRRIGATION_PLAT_SL206   0 
#define IRRIGATION_PLAT_SL651   1
#define IRRIGATION_PLAT_SCSW    2
#define IRRIGATION_PLAT_MAX     3
#define IRRIGATION_SERVERNUM_MAX 4

typedef struct tagIrriServerInfoEx
{
	int				iSerType;					//对接平台服务器类型	0-保留 1-规约SL651 2-四川水文
	int				iSerNum;					//对接平台服务器总数	支持水利对接平台的数量, 最多4个
	int				iSerIndex;					//对接平台服务器编号	0～3
	char			pcServerIP[LEN_128];		//对接平台服务器的IP	不超过128字节
	int				iServerPort;				//对接平台服务器的端口	范围1-65535
	char			pcStationCode[LEN_16];		//对接平台服务器的遥测站码	小于16字节
	char			pcCenterAddr[LEN_16];		//对接平台服务器的中心站地址	小于16字节,当iSerType=1时有效
	char			pcCenterPassword[LEN_16];	//对接平台服务器的中心站密码	小于16字节,当iSerType=1时有效
}IrriServerInfoEx, *pIrriServerInfoEx;
				
typedef struct tagIrriUpLoadParam
{
	int			iPlatFormType;		//水利对接平台类型	0-规约SZY206 1-规约SL651 2-四川水文
	int			iMajorType;			//水利信息上报主类型
	int			iMinorType;			//水利信息上报子类型
	int			iEnable;			//上报数据使能	0：未使能 1：使能
	int			iInterval;			//上报数据时间间隔	60-86400秒
}IrriUpLoadParam, *pIrriUpLoadParam;

typedef struct tagIrriClientQuery
{		
	int					iType;				//记录分类	参考水利上报信息类型
	int					iQueryType;			//查询条件类型	0-按序号段查询 1-按时间段查询
	unsigned long long	iSeqStart;			//查询开始序号	iSeqStart>0，iQueryType=0时有效
	unsigned long long	iSeqStop;			//查询结束序号	iSeqStop>0，iQueryType=0时有效
	NVS_FILE_TIME		tStartTime;			//查询开始时间	utc时间，iQueryType=1时有效
	NVS_FILE_TIME		tEndTime;			//查询截止时间	utc时间，iQueryType=1时有效
	unsigned long long  iPageNo;			//当前页号	iPageNo>=0
	int					iPage;				//每页条数	iPageSize>=0 最大20条
}IrriClientQuery, *pIrriClientQuery;

typedef struct tagIrriClientQueryEx
{		
	int					iType;				//记录分类	参考水利上报信息类型
	int					iQueryType;			//查询条件类型	0-按序号段查询 1-按时间段查询
	unsigned long long	iSeqStart;			//查询开始序号	iSeqStart>0，iQueryType=0时有效
	unsigned long long	iSeqStop;			//查询结束序号	iSeqStop>0，iQueryType=0时有效
	int					iStartTime;			//查询开始时间	utc时间，iQueryType=1时有效
	int					iEndTime;			//查询截止时间	utc时间，iQueryType=1时有效
	unsigned long long  iPageNo;			//当前页号	iPageNo>=0
	int					iPage;				//每页条数	iPageSize>=0 最大20条
}IrriClientQueryEx, *pIrriClientQueryEx; //该结构体只用于嵌入式使用，时间直接传int

typedef struct tagIrriClientQueryResult
{
	int								iSize;
	int								iType;		//上报信息类型	详见【水利信息上报类型】页面的水利上报信息类型
	int								iQueryType;	//查询条件类型	0-按序号段查询 1-按时间段查询
	unsigned long long				uSeqStart;	//查询开始序号	iSeqStart>0，iQueryType=0时有效
	unsigned long long				uSeqStop;	//查询结束序号	iSeqStop>0，iQueryType=0时有效
	NVS_FILE_TIME					tStartTime;	//查询开始时间	utc时间，iQueryType=1时有效
	NVS_FILE_TIME					tStopTime;	//查询截止时间	utc时间，iQueryType=1时有效
	unsigned long long				uPageNo;	//当前页号	iPageNo>=0
	int								iPageSize;	//每页条数	iPageSize>=0 最大20条
	int								iResult;	//查询结果	"0-成功 1-超出最大个数限制错误 2-读写错误"
	unsigned long long				uMaxSeqNo;	//此类型记录的最大序号	iMaxSeqNo>=0
	unsigned long long				iTotal;		//总条数	iTotal>=0
	int								iPageTotal;	//int	当前页数据总条数	<=20
	int								iPageIndex;	//int	当前页数据序号	0-19
	IrrigationPara					tIrrigationPara; //上报具体内容
}IrriClientQueryResult, *pIrriClientQueryResult;//

typedef struct tagIrriClientQueryResultEx
{
	int								iSize;
	int								iType;		//上报信息类型	详见【水利信息上报类型】页面的水利上报信息类型
	int								iQueryType;	//查询条件类型	0-按序号段查询 1-按时间段查询
	unsigned long long				uSeqStart;	//查询开始序号	iSeqStart>0，iQueryType=0时有效
	unsigned long long				uSeqStop;	//查询结束序号	iSeqStop>0，iQueryType=0时有效
	int								iStartTime;	//查询开始时间	utc时间，iQueryType=1时有效
	int								iStopTime;	//查询截止时间	utc时间，iQueryType=1时有效
	unsigned long long				uPageNo;	//当前页号	iPageNo>=0
	int								iPageSize;	//每页条数	iPageSize>=0 最大20条
	int								iResult;	//查询结果	"0-成功 1-超出最大个数限制错误 2-读写错误"
	unsigned long long				uMaxSeqNo;	//此类型记录的最大序号	iMaxSeqNo>=0
	unsigned long long				iTotal;		//总条数	iTotal>=0
	int								iPageTotal;	//int	当前页数据总条数	<=20
	int								iPageIndex;	//int	当前页数据序号	0-19
	IrrigationPara					tIrrigationPara; //上报具体内容
}IrriClientQueryResultEx, *pIrriClientQueryResultEx;//该结构体只用于嵌入式使用，时间直接传int

typedef struct tagWaterDetectPosParam
{
	int			iSceneID;			//场景ID	0~31  （默认使用0~15）
	int			iRuleID;			//规则ID(预留)	0~15  （默认使用 0）
	int			iPosType;			//检测区域类型	0-水位检测
	int			iOperationType;		//操作类型	1-设置检测区域 2-调用检测区域 3-删除检测区域
	int			iGroundID;			//检测区域组号	0-保留 1～20为组号
	int			iPosID;				//检测预置位编号	"范围：0～32
	int			iStatus;			//0-未设置 1-已设置
	int			iPtzP;				//球机水平角度	p*1000
	int			iPtzT;				//球机垂直角度	t*1000
	int			iPtzZ;				//镜头变倍倍率	z*1000
	int			iAngleValue;		//倾角仪角度, 倾角仪角度乘以10000，单位是度，实际范围0-360
}WaterDetectPosParam, *pWaterDetectPosParam;

typedef struct tagAdjustVersionEx
{
	int				iSceneId;
	int				iRuleID;
	int				iFieldOfVision;
}AdjustVersionEx, *pAdjustVersionEx;

typedef struct tagAdjustVersionResult
{
	int				iSceneId;
	int				iRuleID;
	int				iFieldOfVision;
	int				iResult;
}AdjustVersionResult, *pAdjustVersionResult;

typedef struct tagRtuParam
{
	int				iAddress;
}RtuParam, *pRtuParam;


#define MAX_IRRIGATION_GAUGE_GROUP 50
#define MAX_IRRIGATION_GAUGEPRE_ID	33
typedef struct tagWaterDetectQuery
{
	int			iSize;
	int			iSceneID;		//0~31  （默认使用0~15）
	int			iRuleID;		//0~15  （默认使用 0）
	int			iPosType;		//0-水位检测
	int			iGroupID;		//iPosType为0时，1~20-查询此组水尺当前序号的标定参数
	int			iTotalPosID;	//范围：0～32
	int			iPosID;			//当iPosType=0水位检测时:0-保留 1-水位检测预置位 2-上切预置位 3-下切预置位，10-32为标定预置位
	int			iState;			//0-未设置 1-已设置
	int			iPtzP;			//p*1000
	int			iPtzT;			//t*1000
	int			iPtzZ;			//z*1000
	int			iAngleValue;	//倾角仪角度乘以10000，单位是度，实际范围0-360 软件取值后除以10000.0转换成float
	int			iResult;		//0-查询成功，非0失败 
}WaterDetectQuery, *pWaterDetectQuery;

typedef struct tagWaterDetectCmd
{
	int			iSceneID;		//0~31  （默认使用0~15）
	int			iRuleID;		//0~15  （默认使用 0）
	int			iPosType;		//0-水位检测
	int			iGroupID;		//iPosType为0时，1~20-查询此组水尺当前序号的标定参数
}WaterDetectCmd, *pWaterDetectCmd;

typedef struct tagNewCommonEnable
{
	int		iEnable; //轻量级获取通用使能号
}NewCommonEnable,*pNewCommonEnable;

typedef struct tagNewCommonEnableResult
{
	int		iEnable; //轻量级获取通用使能号
	int		iEnableValue;
}NewCommonEnableResult,*pNewCommonEnableResult;

#define MAX_SERVICE_TYPE		2
typedef struct tagNetServicePara
{
	int			iServiceType;					//1代表HTTPS，2代表SRTP
	char		pcServerCertificateID[LEN_128]; //证书ID	最长128字节
	int			iEncryptionAlgo;				//加密算法	1代表AES128，2代表AES256
	int			iPort;							//端口	70-65535
}NetServicePara, *pNetServicePara;

#define MAX_CERTIFICATE_NUM 16
typedef struct tagCertificate
{
	int			iCount;							//证书总数:1-16
	int			iNum;							//证书序号
	char		pcServerCertificateID[LEN_128];	//证书ID
	char		pcStartTime[LEN_32];			//证书有效期开始时间
	char		pcEndTime[LEN_32];				//证书有效期结束时间
	int			iState;							//加密算法：1-Aes128 2-Aes256
	int			iUser;							//使用者:按位bit0:http  bit1:SRTP
}Certificate, *pCertificate;


typedef struct tagVideoParam
{
	int			iSize;
	int			iVencType;
	int			iVideoSize;
	int			iMinBitrate;
}VideoParam, *pVideoParam;

typedef struct tagVideoLimit
{
	int				iGroup;
	int				iNum;
	VideoParam		tVideoParam[LEN_128];
}VideoLimit, *pVideoLimit;

typedef struct tagCmdDelFile
{
	int			iType;
	char		cFileName[LEN_128];
}CmdDelFile, *pCmdDelFile;

typedef struct tagCmdDelFileResult
{
	int			iType;
	char		cFileName[LEN_128];
	int			iResult;
}CmdDelFileResult, *pCmdDelFileResult;

#endif

