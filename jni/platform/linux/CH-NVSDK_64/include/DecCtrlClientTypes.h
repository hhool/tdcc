#ifndef __DECCTRLCLIENT_TYPES_H__
#define __DECCTRLCLIENT_TYPES_H__

#include "GlobalTypes.h"
#include "net_sdk_types.h"

#ifndef X_API
#if !defined(__WIN__)
#define X_API
#define STDCALL
#else
#define X_API __declspec(dllexport)
#define STDCALL __stdcall
#endif
#endif

typedef void (__stdcall *DEC_COMRECV_NOTIFY)(long _ulID, char *_cBuf, int _iLength);
//消息回调函数
typedef int (*pTDPostMessage)(void *_hWnd, unsigned int _uiMsg, unsigned int _wParam, int _lParam);
typedef int (*pTDPostMessageEx)(void *_hWnd, unsigned int _uiMsg, unsigned int _wParam, int _lParam, void* _lpUserData);


#define NVD_HEAVY_MODE			0
#define NVD_LIGHT_MODE			1

#define DEC_LEN_8		8
#define DEC_LEN_16		16
#define DEC_LEN_32		32
#define DEC_LEN_64		64
#define DEC_LEN_128		128
#define DEC_LEN_256		256
#define DEC_LEN_512		512
#define DEC_MAX_CHANNELID_LEN   32             //最大通道ID长度

/**********************************************abandon************************************************/
#define	DEC_MAX_CHANNEL_NUM				8     //每个解码器最多通道数
#define	DEC_MAX_CHANNEL_NUM_NEW			16     //每个解码器最多通道数，多路解码器扩展至16个，属于物理通道
#define	DEC_MAX_VIRTUAL_CHANNEL_NUM		8      //每个解码器最多虚拟通道数，大屏设置使用,虚拟通道号从16开始
#define DEC_MAX_SPLIT_SCREEN_NUM		16		//大屏最大的分屏个数

#define DEC_MAX_FLOAT_WINDOW_NUM 16
#define DEC_MAX_PICTURE_NUM		100             //每个解码通道最多画面数扩展至100个
#define DEC_MAX_WINDOW_TOTAL_NUM        (DEC_MAX_PICTURE_NUM + DEC_MAX_FLOAT_WINDOW_NUM)

#define	DEC_MAX_PHYSICAL_CHANNEL_NUM 	96  //最大物理通道数
#define DEC_MAX_SPLIT_CHANNEL_NUM       48  //最大拼接通道数

#define DEC_MAX_CHANNEL_TOTAL_NUM       (DEC_MAX_PHYSICAL_CHANNEL_NUM + DEC_MAX_SPLIT_CHANNEL_NUM)

#define DEC_MAX_ENCODE_CHANNEL_NUM		48

typedef struct tagGetSipVideoChannel_Ex
{
	int		m_iBuffSize;	
	int     m_iBeginChannelNo;
	int		m_iChannelCount;
	char	m_cChannelID[DEC_MAX_CHANNEL_NUM_NEW][DEC_MAX_CHANNELID_LEN+1];
	int	    m_iLevel[DEC_MAX_CHANNEL_NUM_NEW];
	int 	m_iPtzTime[DEC_MAX_CHANNEL_NUM_NEW];
}GetSipVideoChannel_Ex, *pGetSipVideoChannel_Ex;

//获取通道数和每个通道的画面数
typedef struct tagChnNumAndMode
{
	int			iBufSize;				//结构体大小
	int			iLocalChnNum;			//本地通道数
	int			iVOChnNum;				//拼控通道数
	int			iLocalChnMode[DEC_MAX_CHANNEL_NUM_NEW];
	int			iVOChnMode[DEC_MAX_VIRTUAL_CHANNEL_NUM];
}ChnNumAndMode, *pChnNumAndMode;

typedef struct tagDecTimezone
{
	int iTimezone;
}DecTimezone, *PDecTimezone;

typedef struct tagDecScreenDisplay
{
	int iDisplay;
}DecScreenDisplay, *PDecScreenDisplay;
/*****************************************************************************************************/

#define DEC_MAX_NVSITEM_NUM     256             //每个画面最多NVS数量
#define DEC_MAX_DECODER         128				//最多连接解码器数
#define DEC_MAX_COM_NUM			2				//最大串口数
#define DEC_MAX_COM_NUM_NEW		8				//最大串口数(新)
#define DEC_MAX_USER_NUM		32				//最大用户数量

#define DEC_MAX_ALARM_OUT 7
#define DEC_MAX_ALARMMODE 1
#define DEC_MAX_IS_PAL	  1
#define DEC_MAX_LANGUAGE  1

#define NVS_MAX_CHANNEL_NUM		320				//设备的最大通道数扩展至64，兼容大路数nvr

//消息定义
#define DEC_WCM_DEC_LOGON         1   //登录状态消息
#define DEC_WCM_NVS_STARTVIEW     2   //连接NVS消息
#define DEC_WCM_DEC_TALK          3   //对讲消息

#define DEC_WCM_DEC_UPGRADE       4   //升级解码器消息
#define DEC_WCM_DEC_UPGRADELOGO   5   //升级Logo消息
#define DEC_WCM_DEC_UPGRADEP      6   //升级控制协议消息

#define DEC_WCM_ERR_ORDER         7   //命令层发生错误
#define DEC_WCM_NVS_STOPVIEW      8   //断开NVS消息
#define DEC_WCM_DEC_PARASET       9   //参数改变消息

#define DEC_WCM_DEC_UPGRADEWEB      10  //升级网页消息
#define DEC_WCM_DEC_UPGRADEPROCESS  11  //解码器升级进度
#define DEC_WCM_DEC_AUDIOSTATUS     12  //音频状态消息
#define DEC_WCM_DEC_TALK_FAILED     13  //add by lpy for 对讲失败
#define DEC_WCM_DEC_AUDIO_FAILED    14  //add by lpy for 音频失败[2/5/2010 Administrator]

#define DEC_WCM_DEC_PUSHSTREAM		20	//Push stream 结果
#define DEC_WCM_ERR_PUSHSTREAM		21	//Push stream 连接意外断开
#define DEC_WCM_ERR_DATANET         22  //数据通道发生网络异常

#define DEC_WCM_ERR_USERPASS		25	//修改密码结果
#define DEC_WCM_DETECT_CHANN_STATE	26	//解码器各个通道的状态
#define DEC_WCM_ALARM_NOTIFY		27	//发送上报警情
#define DEC_WCM_PARASET_CREATEVVO	28  //创建拼控输出通道消息

#define DEC_WCM_AUTOTEST_INFO		29  //自动化调试 

#define DEC_WCM_QUERY_LOG_FINISH	30  //日志查询

#define DEC_WCM_NVS_STARTVIEW_FAILED      31   //连接NVS失败消息

#define DEC_WCM_SEARCH_IPC			32   //搜索发现IPC
#define DEC_WCM_SEARCH_NVD			33   //搜索发现解码器

#define DEC_WCM_CLUSTER_STATE 					34  
#define DEC_WCM_CLUSTER_CONTROL_CARD_STATE 		35
#define DEC_WCM_CLUSTER_WORK_CARD_STATE 		36
#define DEC_WCM_EXPORT_CONFIG_FINISH 			37
#define DEC_WCM_ENCODE_CHANNEL_STATE 			38
#define DEC_WCM_LOG_WRITE			 			39
#define DEC_WCM_EXCEPTION			 			40
#define DEC_WCM_DEC_USER_NUM					41
#define DEC_WCM_DEC_USER_INFO					42
#define DEC_WCM_DEC_LAST_ERROR					43
#define DEC_WCM_DEC_PICSNAP						44
#define DEC_WCM_DEC_GETPICFILENAME				45
#define DEC_WCM_DEC_SCREENCTLSET				46
#define DEC_WCM_DEC_REBOOTTRADE					47
#define DEC_WCM_DEC_GETUDISK_VIDEOLISTS			48
#define DEC_WCM_DEC_VIDEO_PLAYSET				49


//encodemode: 编码类型
//0，H.264；1，MJPEG， 23:H265, 31:MPEG4 100：PS流
#define ENCODE_H264			0
#define ENCODE_MJPEG		1
#define ENCODE_H265			23
#define ENCODE_MPEG4		31
#define ENCODE_PS			100

//videosize: 视频大小
enum
{
	VIDEO_QCIF		= 0,			//Quarter Cif 	172*144, 
	VIDEO_HCIF		= 1,			//Half Cif	352*144 
	VIDEO_FCIF		= 2,			//Full Cif	352*288
	VIDEO_HD1		= 3,			//Half D1	704*288
	VIDEO_FD1		= 4,			//Full D1	704*576
	VIDEO_MD1		= 5,
	VIDEO_QVGA      = 6,            //QVGA      320x240
	VIDEO_VGA		= 7,			//VGA       640*480
	VIDEO_HVGA	    = 8,	        //HVGA      640*240
	VIDEO_HD_720P	= 9,			//720p      1280*720
	VIDEO_HD_960P	= 10,			//960P		1280*960
	VIDEO_HD_QXVGA	= 11,			//QXVGA		1600*1200
	VIDEO_HD_1080P	= 12,			//1080P		1920*1080
	VIDEO_HD_QXGA	= 13,			//300W		2048*1536
	VZ_4M           = 0x0210,		//400W		2560*1440
	VZ_4MB			= 0x0220,		//400WB		2592*1520
	VZ_QSXGA		= 0x500,		//500W(3)	2560*2048
	//走廊模式
	F720P_9_16		= 0x100009,		//720x 1280
	F1080P_9_16		= 0x10000C,		//1080x 1920
	F4M_9_16		= 0x100210,		//1440x2560
	F4MB_9_16		= 0x100220,		//1520x2592
	VIDEO_BUTT
};

#define VIDEO_SIZE_DEFAULT 255



#ifndef EMBEDED_USE
//VGA分辨率
enum
{
	VGA_800X600		= 1,	//800*600 60HZ
	VGA_1024X768	= 2,	//1024*768 60HZ
	VGA_1280X1024	= 3,	//1280*1024 60HZ
	VGA_1280X720P_60,
	VGA_1920X1080P_60,
	VGA_1280X720P_50,
	VGA_1920X1080P_50,
	VGA_1920X1080I_60,
	VGA_1920X1080I_50,
	VGA_1366x768_60,
	VGA_1440x900_60,
	VGA_1280x800_60,
	VGA_2560x1600_30,
	VGA_3840x2160_30,
	VGA_3840x2160_60,
	VGA_BUTT,
};
#endif

#ifndef VGA_BUTT
#define VGA_BUTT	13
#endif

//登录状态
enum
{
    DEC_LOGON_RETRY         = 2,
    DEC_LOGON_SUCCESS       = 0,
    DEC_LOGON_ING           = 1,
    DEC_LOGON_FAILED        = -1,
    DEC_LOGON_TIMEOUT       = -2,
    DEC_NOT_LOGON           = -3,
};

//Login failed error code
#define DEC_UNKNOW_ERROR			0
#define DEC_CIPHER_USERNAME_ERROR	1
#define DEC_CIPHER_USERPASS_ERROR	2
#define DEC_NO_SUPPORT_ALGORITHM	3
#define DEC_PSWD_ERR_TIMES_OVERRUN	4
#define DEC_ILLEGAL_PLATFORM        5

/************************************************************************
* SIP协议相关                                                                     
************************************************************************/


typedef struct
{
	int  	m_iChannelNo;
	char 	m_cChannelID[DEC_MAX_CHANNELID_LEN+1];
	int     m_iLevel;
	int     m_iPtzTime;
} TSetSipVideoChannel;

typedef struct 
{
	int     m_iBeginChannelNo;
	int		m_iChannelCount;
	char	m_cChannelID[DEC_MAX_CHANNEL_NUM][DEC_MAX_CHANNELID_LEN+1];
	int	    m_iLevel[DEC_MAX_CHANNEL_NUM];
	int 	m_iPtzTime[DEC_MAX_CHANNEL_NUM];
} TGetSipVideoChannel;

typedef struct tagSipVideoChannel
{
	int		iSize;
	char 	cChannelID[DEC_MAX_CHANNELID_LEN+1];
	int     iLevel;
	int     iPtzTime;
}SipVideoChannel, *PSipVideoChannel;

#define DEC_MAX_LAN_NUM 2   //最大网卡数量
typedef struct tagIPAddress
{
	char			ip[16];			//解码器IP地址
	char			submask[16];		//解码器子网掩码
	char			gateway[16];		//解码器的网关地址
	char			dns[16];			//DNS地址
}IPAddress, *pIPAddress;

typedef struct tagMacAddress
{
	char			cMac[18];			//物理地址
}MacAddress, *pMacAddress;

/*解码器参数定义=======================================*/
typedef struct
{
	char			m_ip[16];			//解码器IP地址
	char			m_submask[16];		//解码器子网掩码
	char			m_gateway[16];		//解码器的网关地址
	char			m_dns[16];			//DNS地址

	MacAddress		m_tMacAddress[DEC_MAX_LAN_NUM];			//物理地址

	char			m_ddnsIP[16];		//解析服务器IP地址
	char			m_ddnsUser[16];		//解析服务器用户名
	char			m_ddnsPass[16];		//解析服务器密码
	unsigned short	m_ddnsPort;			//解析服务器端口
	unsigned char	m_ispal;			//0:PAL；1:NTSC
	unsigned char	m_language;			//0:中文；1:英文

	unsigned char	m_rs485type[DEC_MAX_COM_NUM];			//485协议ID，0：透明通道，1:Pelco-P，...
	unsigned char	m_rs485address[DEC_MAX_COM_NUM];		//485地址（取值范围：0-255）
	int				m_rs485baudrate[DEC_MAX_COM_NUM];		//485波特率2400，4800，9600
	unsigned char	m_rs485databit[DEC_MAX_COM_NUM];   		//485数据位，默认为8
	unsigned char	m_rs485stopbit[DEC_MAX_COM_NUM];		//485停止位，默认为1
	unsigned char	m_rs485checkbit[DEC_MAX_COM_NUM]; 		//485校验位，四种可选，0：无校验；1：奇校验；2：偶校验；3：固定为1；4：固定为0
	unsigned char	m_rs485flowcontrol[DEC_MAX_COM_NUM];	//485流控，默认为无流控，设置无效

	int				m_Alarmout;								//报警输出联动关系，&0x01:端口报警，&0x02:丢失报警，&0x04:移动报警，1表示联动输出，0表示不联动输出。
    int			    m_AlarmMode;							//报警输出模式：0：低电平触发；1：高电平触发
	int				m_iChannel;								//解码通道数，0-8
	int				m_iComNumber;							//串口数，0-1
	unsigned char	m_nChanMode[DEC_MAX_CHANNEL_NUM];		//每个通道的工作模式（1：单画面；4：四画面）

	int             m_iVGASize[DEC_MAX_CHANNEL_NUM];		//每个通道的VGA分辨率，1（800*600 60Hz）、2（1024*768 60Hz）、3（1280*1024 60Hz），若为BNC通道，则该参数无效
#ifdef __WIN__
	char			m_cRegSvrIP[32];
	int				m_iRegSvrPort;
	int				m_iRegSvrEnable;

	char			m_cPUID[21];							//	
	char			m_cPUName[DEC_LEN_32+1];



	int				m_iVolume;				//	音量

	int				m_iSelPic[2];			//	画面选择                           
//.................SIP.....@cmz..110223
	DZ_INFO_PARAM	m_dzInfoParam;
	TGetSipVideoChannel m_SipVideoChannel;
	//................视频参数设置.....
	STR_VideoParam  m_VideoParam[DEC_MAX_CHANNEL_NUM];
	int				m_iRegChannelNum[2];
	char			m_cRegChannelPUID[2][DEC_LEN_32+1];
#endif
}TDECPARAM;

#define RTSP_URL_LEN	81
/*视频通道参数定义======================================*/
typedef struct
{
	union
	{
		char				m_cRTSPUrl[RTSP_URL_LEN+1];		//RTSP地址
		struct  
		{
			char 			m_serName[33];		//服务器名称(暂时保留)
			char 			m_serIP[33];		//服务器地址，可以是IP地址，也可以是域名；       zyp modified 0506
			char			m_serProxy[16];		//服务器上级代理
		};		
	};
	
	unsigned char	m_serChan;			//服务器通道
	unsigned char	m_serStream;		//服务器码流类型
	unsigned char	m_serNetmode;		//传输协议1：TCP，2：UDP，3：多播；
	unsigned char	m_bUseddns;			//通过解析服务器连接
	unsigned short	m_serPort;			//服务器端口
	int				m_bisView;			//当前是否在连接状态，1：连接状态，0：未连接状态(暂时不使用)
	char		   	m_username[20];		//用户名
	char	       	m_password[20];		//密码
	int         	m_holdtime;			//保持时间，取值范围：5――1000秒
    char            m_deviceType[16];   //设备控制协议（需要翻译到的协议）
    unsigned char   m_iAddress;         //NVS设备地址（取值范围：0-255）
} TNVSITEM;

//视频通道参数扩展定义
#define MAX_ENCYPTPWD_LEN	16
typedef struct __tagTNVSITEMEX
{
	int				m_iStructLen;							//如果以后要扩展，可以根据这个长度来判断扩展字段的内容
	TNVSITEM		m_stOldItem;
	char			m_cEncyptPWD[MAX_ENCYPTPWD_LEN + 1];	//加密密码
	int				m_iDevPlatType;							//设备平台类型，0-普通，1-Onvif 2-push流 3-RTSP流
	void*			m_pvReserved;							//为了便于扩展
	char			m_cMultIP[33];							//组播地址协议
	int				m_iMultPort;							//组播端口号
	int             m_isavecfg;                             //保存配置标志
}TNVSITEMEX, *LPTNVSITEMEX;

/*服务器支持的协议列表定义===============================*/
typedef struct
{
	int		m_iCount;					//服务器支持的协议类型数
	char 	m_cProtocol[LEN_128][LEN_16];		//各协议名称，最多支持128个协议，每条协议名称最长15字节；
} TDECPROTOCOL;

/*SDK版本号定义==========================================*/
typedef struct
{
	unsigned short	m_ulMajorVersion;
	unsigned short	m_ulMinorVersion;
	unsigned short  m_ulBuilder;
	char*			m_cVerInfo;
}NVDSDK_VERSION;

/*OSD叠加Logo属性定义====================================*/
typedef struct
{
    unsigned char m_enable;           //是否叠加Logo
    int           m_iPosX;            //叠加Logo横坐标
    int           m_iPosY;            //叠加Logo纵坐标
    unsigned char m_iAlpha;           //透明度(0~100)，100为完全不透明
    int           m_iTransparentColor;//背景色，RGB格式(0x00000000~0x00ffffff)
}TLOGOPARAM;


/*设备支持平台信息定义====================================*/
typedef struct  
{
	int     m_iCount;                 //支持的平台数目
	char    m_cPlatformName[10][32];  //各个平台的名称       
}TPLATFORMINFO;

/*错误码定义=============================================*/
#define ERR_SUCCESS					0		//成功
#define ERR_ISVIEW					1       //存在正在连接的NVS
#define ERR_INVALIDID				-1		//指定的解码器不存在
#define ERR_UNINIT					-2		//开发包尚未初始化/初始化失败
#define ERR_INVALIDPARA				-3		//传入非法参数
#define ERR_INVALIDFILE				-7		//文件格式非法
#define ERR_NOTLOGON				-8      //没有登录
#define ERR_MAXDEC					-10     //达到最大连接数
#define ERR_FORBID					-12     //不允许操作
#define ERR_RELOOPITEM				-13     //向循环列表中添加重复的连接
#define ERR_NOCONNECTED				-16		//还没有建立连接
#define ERR_POS_X_Y					-17		//坐标非法
#define ERR_NULL_PTR				-18		// null pointer
#define ERR_UNDEFINED_BEHAVIOR		-19		// undefined behavior
#define ERR_INVALID_BUFF_SIZE		-20		//不合法的缓冲区大小
#define ERR_INVALID_ARRAY_INDEX		-21		//不合法的数组下标
#define ERROR_INVALID_PARAM			-22		//参数不合法
#define ERR_REPEAT_SET				-23		//重复设置
#define ERR_BUILD_PROTOCOL			-24		//build protocol error
#define ERR_SEND_PROTOCOL			-25		//send protocol error
#define ERR_NO_IDLE_ITEM			-26		//no idle item
#define ERR_INVALID_FILEHEADER		-27		//invalid file header
#define ERR_LIGHTMODE_NOTSUPPORT	-28		//sdk light mode not support
#define ERR_OUT_OF_MEMERY			-29		//sdk out of memery

/*键盘码定义=============================================*/
#define DECKEYCODE_NUM1     0X01
#define DECKEYCODE_NUM2		0X02
#define DECKEYCODE_NUM3		0X03
#define DECKEYCODE_NUM4		0X04
#define DECKEYCODE_NUM5		0X05
#define DECKEYCODE_NUM6		0X06
#define DECKEYCODE_NUM7		0X07
#define DECKEYCODE_NUM8		0X08
#define DECKEYCODE_NUM9		0X09
#define DECKEYCODE_NUM0		0X0A

#define DECKEYCODE_UP		0X0D    //上
#define DECKEYCODE_DOWN		0X0E    //下
#define DECKEYCODE_LEFT		0X0F    //左
#define DECKEYCODE_RIGHT	0X10    //右
#define DECKEYCODE_PAGEUP	0X11    //上翻页
#define DECKEYCODE_PAGEDOWN	0X12    //下翻页
#define DECKEYCODE_EDIT		0X13    //编辑
#define DECKEYCODE_ESC		0X14    //取消
#define DECKEYCODE_RETURN	0X15    //确定
#define DECKEYCODE_ABC		0X16    //输入法切换
#define DECKEYCODE_DEV		0X17    //DEV
#define DECKEYCODE_F1		0X18    //F1  
#define DECKEYCODE_F2		0X19    //F2

#define DECKEYCODE_MENU		0X20    //菜单

#define DECKEYCODE_STOP		0X52	//停止(按键方开时发送)

#ifndef EMBEDED_USE
/*云台控制码定义===========================================*/
#define PTZ_LEFT			0	//left
#define PTZ_RIGHT			1
#define PTZ_UP				2
#define PTZ_DOWN			3
#define PTZ_IRISADD			4
#define PTZ_IRISDEC			5
#define PTZ_FOCUSADD		6
#define PTZ_FOCUSDEC		7
#define PTZ_ZOOMADD			8
#define PTZ_ZOOMDEC			9
#define PTZ_GOTOPOINT		10
#define PTZ_SETPOINT		11
#define PTZ_AUTO			12
#define PTZ_STOP			13
#define PTZ_LEFTSTOP		14
#define PTZ_RIGHTSTOP		15
#define PTZ_UPSTOP			16
#define PTZ_DOWNSTOP		17
#define PTZ_IRISADDSTOP		18
#define PTZ_IRISDECSTOP		19
#define PTZ_FOCUSADDSTOP	20
#define PTZ_FOCUSDECSTOP	21
#define PTZ_ZOOMADDSTOP		22
#define PTZ_ZOOMDECSTOP		23
#define PTZ_LIGHT			24
#define PTZ_LIGHTSTOP		25
#define PTZ_RAIN			26
#define PTZ_RAINSTOP		27
#define PTZ_TRACK			28
#define PTZ_TRACKSTOP		29
#define PTZ_DEVOPEN			30
#define PTZ_DEVCLOSE		31
#define PTZ_AUTOSTOP		32
#define PTZ_CLEARPOINT		33
#endif

//	新增设备平台类型
#define	DEVTYPE_NORMAL			0
#define	DEVTYPE_ONVIF			1
#define	DEVTYPE_PUSH			2
#define	DEVTYPE_RTSP			3
#define DEVTYPE_ENCODE			4
#define DEVTYPE_LOCAL           5
#define DEVTYPE_LG				1001
#define DEVTYPE_PANASONIC		1002

//	新增通用业务类型
#define COMMONID_NETCUT_HOLD_LASTFRAME	0x13001
#define COMMONID_PREVIEW_PREFERENCE		0x13002
#define COMMONID_HD_DISPLAY				0x13003
#define COMMONID_TELNET					0x13004 //使能telnet

//流控类型
#define PUSH_STREAM_CMD_TYPE	0
#define PUSH_STREAM_CMD_PAUSE	0
#define PUSH_STREAM_CMD_FAST	1
#define PUSH_STREAM_CMD_SLOW	2

//push流控制暂停状态
#define PUSH_REAL_TIME_STREAM_STATE		0x100	//实时流
#define PUSH_PLAYBACK_STREAM_PLAY		0		//回放流播放
#define PUSH_PLAYBACK_STREAM_PAUSE		1		//回放流暂停

//缓冲区状态
#define		RET_BUFFER_IS_ALREADY_FULL		(-10)		//	缓冲区已经满了，数据没有放入缓冲区，数据需要重新发送
#define		RET_BUFFER_IS_EMPTY				(-21)		//	缓冲区空
#define		RET_PAUSE_STATE					(-30)		//	暂停状态

//push流速度类型
#define		PUSH_SLOW_SPEED		0
#define		PUSH_NORMAL_SPEED	1
#define		PUSH_FAST_SPEED		2

//push流添加StartPush结构体
#define 	MAX_ENCRYPT_KEY			16
#define		VIDEO_HEADER_SIZE		88
typedef struct
{
	int		m_iSize;							//结构体大小
	char 	m_cFileHeader[VIDEO_HEADER_SIZE];	//视频头
	char	m_cEncryptKey[MAX_ENCRYPT_KEY + 4];	//前端设备视频解密密码，为空则表示不加密，
												//至多16个字符且保证四字节
}START_PUSH_PARAM;

//配置码流信息
#define		MIN_CONF_CMD					0
#define		CONF_CMD_VIDEOHEAD				MIN_CONF_CMD + 1
#define		CONF_CMD_AUDIOVIDEO				MIN_CONF_CMD + 2
#define		MAX_CONF_CMD					MIN_CONF_CMD + 2

//升级文件结果状态
#define  RET_UPGRADE_FINISH		0
#define  RET_UPGRADE_FAILED		-1
#define  RET_UPGRADE_ERROR		2

//置顶置底
#define SET_TOP		1
#define SET_DOWN	0

//设备参数命令码
#define CMD_MIN_DEV_CONFIG	0
#define CMD_DEC_CFG_PROTOCOL						CMD_MIN_DEV_CONFIG + 0		//PTZ控制协议
#define CMD_DEC_CFG_ALARM_LINK_SWITCH				CMD_MIN_DEV_CONFIG + 1		//报警联动切换
#define CMD_DEC_CFG_CREATE_VVO						CMD_MIN_DEV_CONFIG + 2		//创建拼控输出通道VVO
#define CMD_DEC_CFG_SPLIT_SCREEN					CMD_MIN_DEV_CONFIG + 3		//自定义画面分割方式
#define CMD_DEC_CFG_CHANN_STATE						CMD_MIN_DEV_CONFIG + 4		//获取解码器各个通道的状态
#define CMD_DEC_CFG_DISP_VONUM						CMD_MIN_DEV_CONFIG + 5		//控制输出设备显示物理编号
#define CMD_DEC_CFG_CHANN_NUM						CMD_MIN_DEV_CONFIG + 6		//获取解码器本地通道数和虚拟通道数
#define CMD_DEC_CFG_ALARM_SCHEDULE					CMD_MIN_DEV_CONFIG + 7		//设置智能分析报警布防模板
#define CMD_DEC_CFG_ALARM_LINK						CMD_MIN_DEV_CONFIG + 8		//设置智能分析联动
#define CMD_DEC_CFG_ALARM_NOTIFY					CMD_MIN_DEV_CONFIG + 9		//发送警情
#define CMD_DEC_CFG_ALARM_IN_OUT					CMD_MIN_DEV_CONFIG + 10		//设置报警输入输出
#define CMD_DEC_CFG_SCHEDULE_ENABLE					CMD_MIN_DEV_CONFIG + 11		//设置智能分析布防使能
#define CMD_DEC_CFG_VGA_SIZE						CMD_MIN_DEV_CONFIG + 12		//获取VGA大小
#define CMD_DEC_CFG_SIP_VIDEO_CHANNEL				CMD_MIN_DEV_CONFIG + 13		//获取SIP相关参数
#define CMD_DEC_CFG_VIDEO_PARAM						CMD_MIN_DEV_CONFIG + 14		//获取视频参数
#define CMD_DEC_CFG_SYSTEM_TIME						CMD_MIN_DEV_CONFIG + 15		//设置系统时间
#define CMD_DEC_CFG_DEV_INFO						CMD_MIN_DEV_CONFIG + 16		//获取设备信息	
#define CMD_DEC_CFG_TIMEZONE						CMD_MIN_DEV_CONFIG + 17		//时区
#define CMD_DEC_CFG_CHANNEL_REGINFO					CMD_MIN_DEV_CONFIG + 18		//通道注册信息
#define CMD_DEC_CFG_SCREEN_DISPLAY					CMD_MIN_DEV_CONFIG + 19		//画面显示/隐藏
#define CMD_DEC_CFG_SCREEN_CHANGEAREA				CMD_MIN_DEV_CONFIG + 20		//画面自定义大小/区域
#define CMD_DEC_CFG_GET_ABILITY_LEVEL				CMD_MIN_DEV_CONFIG + 21		//get function ability level
#define CMD_DEC_CFG_FLOAT_WINDOW					CMD_MIN_DEV_CONFIG + 22		//开窗
#define CMD_DEC_CFG_SAVE_PLAN						CMD_MIN_DEV_CONFIG + 23		//设置预案
#define CMD_DEC_CFG_APPLY_PLAN						CMD_MIN_DEV_CONFIG + 24		//应用预案
#define CMD_DEC_CFG_PLANALIAS						CMD_MIN_DEV_CONFIG + 25		//预案别名
#define CMD_DEC_CFG_BASE_OFFSET						CMD_MIN_DEV_CONFIG + 26		//起始编号
#define CMD_DEC_CFG_LOGOPARAM						CMD_MIN_DEV_CONFIG + 27		//logo
#define CMD_DEC_CFG_DECOSD							CMD_MIN_DEV_CONFIG + 28		//OSD叠加操作
#define CMD_DEC_CFG_PICNUM							CMD_MIN_DEV_CONFIG + 29		//画面数量
#define CMD_DEC_CFG_WINDOW_SEQUENCE					CMD_MIN_DEV_CONFIG + 30		//窗口次序
#define CMD_DEC_CFG_REGSERVER						CMD_MIN_DEV_CONFIG + 31		//
#define CMD_DEC_CFG_PUPARAM							CMD_MIN_DEV_CONFIG + 32		//
#define CMD_DEC_CFG_DZ_INFO							CMD_MIN_DEV_CONFIG + 33		//
#define CMD_DEC_CFG_SELECT_PIC						CMD_MIN_DEV_CONFIG + 34		//
#define CMD_DEC_CFG_CHANNEL_REGINFO_EX				CMD_MIN_DEV_CONFIG + 35		//
#define CMD_DEC_CFG_SIP_VIDEO_CHANNEL_EX			CMD_MIN_DEV_CONFIG + 36		//
#define CMD_DEC_CFG_DEVCOMMONNAME					CMD_MIN_DEV_CONFIG + 37		//通道别名
#define CMD_DEC_CFG_EXPORT_CONFIG					CMD_MIN_DEV_CONFIG + 38	    // export config
#define CMD_DEC_CFG_SHOW_OFFLINE_CHAN				CMD_MIN_DEV_CONFIG + 39	    // 是否显示不在线通道
#define CMD_DEC_CFG_PLATFORM_LIST					CMD_MIN_DEV_CONFIG + 40		//平台列表
#define CMD_DEC_CFG_COM_PARAM						CMD_MIN_DEV_CONFIG + 41	
#define CMD_DEC_CFG_SINGLEPIC						CMD_MIN_DEV_CONFIG + 42		//双击放大/缩小控制
#define CMD_DEC_CFG_AUTOTEST_SYSTEMTYPE				CMD_MIN_DEV_CONFIG + 43
#define CMD_DEC_CFG_AUTOTEST_DEVICEPRODUCTER		CMD_MIN_DEV_CONFIG + 44
#define CMD_DEC_CFG_SCREEN_REGION					CMD_MIN_DEV_CONFIG + 45
#define CMD_DEC_CFG_SCREEN_BASICPARA				CMD_MIN_DEV_CONFIG + 46
#define CMD_DEC_CFG_SCREEN_OUTPUT_MODE				CMD_MIN_DEV_CONFIG + 47
#define CMD_DEC_CFG_PICLEVEL_RELATION				CMD_MIN_DEV_CONFIG + 48
#define CMD_DEC_CFG_SYNCLOOPCTRL					CMD_MIN_DEV_CONFIG + 49
#define CMD_DEC_CFG_SYNCLOOPTIME					CMD_MIN_DEV_CONFIG + 50
#define CMD_DEC_CFG_ENCODERPAPA						CMD_MIN_DEV_CONFIG + 51
#define CMD_DEC_CFG_HTTPPORT						CMD_MIN_DEV_CONFIG + 52
#define CMD_DEC_CFG_SHOWICON						CMD_MIN_DEV_CONFIG + 53
#define CMD_DEC_CFG_ALARM_EFFECT_LIGHT				CMD_MIN_DEV_CONFIG + 54
#define CMD_DEC_CFG_ALARM_EFFECT_REGION				CMD_MIN_DEV_CONFIG + 55
#define CMD_DEC_CFG_ALARM_EFFECT_TEXT				CMD_MIN_DEV_CONFIG + 56
#define CMD_DEC_CFG_PLANLOOPITEM					CMD_MIN_DEV_CONFIG + 57
#define CMD_DEC_CFG_PLANLOOP						CMD_MIN_DEV_CONFIG + 58
#define CMD_DEC_CFG_PLANLOOPITEMDEL					CMD_MIN_DEV_CONFIG + 59
#define CMD_DEC_CFG_LANPARAM_WORKMODE				CMD_MIN_DEV_CONFIG + 60
#define CMD_DEC_CFG_SIP_VIDEO_CHANNEL_EX_V2			CMD_MIN_DEV_CONFIG + 61
#define CMD_DEC_CFG_CHANNEL_MAX_WIN					CMD_MIN_DEV_CONFIG + 62	
#define CMD_DEC_CFG_CHANNEL_LAYOUTLIST				CMD_MIN_DEV_CONFIG + 63	
#define CMD_DEC_CFG_CHANNEL_RESOLUTIONLIST			CMD_MIN_DEV_CONFIG + 64	
#define CMD_DEC_CFG_GETSCREENCTLPROTOCOLS			CMD_MIN_DEV_CONFIG + 65	
#define CMD_DEC_CFG_SCREENCRL_PROTOCOL				CMD_MIN_DEV_CONFIG + 66	
#define CMD_DEC_CFG_SET_CHANNEL_VIDEO				CMD_MIN_DEV_CONFIG + 67	
#define CMD_DEC_CFG_CURVIDEO						CMD_MIN_DEV_CONFIG + 68	
#define CMD_DEC_CFG_VIDEO_PLAYMODE					CMD_MIN_DEV_CONFIG + 69	
#define CMD_DEC_CFG_GETPLANLOOPSTATUS				CMD_MIN_DEV_CONFIG + 70	
#define CMD_DEC_CFG_START_LOOP						CMD_MIN_DEV_CONFIG + 71	
#define CMD_DEC_CFG_STOP_LOOP					    CMD_MIN_DEV_CONFIG + 72	
#define CMD_DEC_CFG_ALL_CHANNEL_VIDEO				CMD_MIN_DEV_CONFIG + 73	
#define CMD_DEC_CFG_SMOOTH_MODE					    CMD_MIN_DEV_CONFIG + 74	
#define CMD_DEC_CFG_HDMODE_OUTCHANNEL				CMD_MIN_DEV_CONFIG + 75	
#define CMD_MAX_DEV_CONFIG							CMD_MIN_DEV_CONFIG + 76	


#define MAX_PROTOCOL_NUM				128		//DEC最多支持128个协议
#define MAX_PROTOCOL_NAME_LEN32			32		//设备支持的协议名称的最大长度
typedef struct
{
	int		m_iCount;					//协议个数
	char 	m_cProtocol[MAX_PROTOCOL_NUM][MAX_PROTOCOL_NAME_LEN32];		
							//各协议名称，最多支持128个协议，每条协议名称最长31字节；
} TDECPROTOCOL_EX;

#define DEC_ALARM_TYPE_BASE			128
#define DEC_ALARMTYPE_VIDEOLOST		128 + 0
#define DEC_ALARMTYPE_NET_PORT		128 + 1
#define DEC_ALARMTYPE_MOVE			128 + 2
#define DEC_ALARMTYPE_LOCAL_PORT	128 + 7
#define DEC_ALARMTYPE_POWER         128 + 8
#define DEC_MAX_ALARM_TYPE			128 + 9

#define ALARM_LINK_SWITCH_ENBALE		1
#define ALARM_LINK_SWITCH_DISENBALE		0
//报警联动切换
typedef struct tagAlarmLinkSwitch
{
	int  iBufSize;		//结构体大小
	int  iAlarmType;	//报警类型	"0，视频丢失；1，端口报警；2，移动侦测；3，视频遮挡；4，智能分析；5，音频丢失；6,温湿度报警；
						//128之后解码器使用，模式=128 + iType（上一行表示的数值）
						//128，视频丢失；
						//129，网络端口报警；
						//130，移动侦测；
						//131～159，预留
						//160，本地端口报警；"					
	int  iPortNo;					//端口号	仅当报警类型为本地端口报警时，该字段有效					
	int  iChannelNo;				//通道号						
	int  iPos;						//画面号						
	char cSerName[DEC_LEN_32];		//前端设备名称						
	char cSerIP[DEC_LEN_16];		//前端设备IP地址						
	char cSerProxy[DEC_LEN_16];		//前端设备代理IP						
	int  iSerChan;					//前端设备通道号	serType为4时，serChan为编码通道号serType为5时，serChan为本地输入通道号					
	int  iSerStreamNo;				//主副码流	0,主码流；1，副码流					
	int  iSerNetmode;				//服务器网络模式	1，TCP；2，UDP；3，多播					
	int	 iUseddns;					//是否使用ddns	0，IP；1，域名；3，主动模式					
	int  iSerPort;					//服务器端口号						
	char cUserName[DEC_LEN_32];		//前端设备登录用户名						
	char cPassword[DEC_LEN_32];		//前端设备登录密码						
	int  iHoldTime;					//停留时间	10-999					
	char cEncrypt[DEC_LEN_32];		//前端设备视频解密密码						
	int  iSerType;					//前端设备类型	0，Tiandy；1，Onvif；2，push流	3，rtsp；4，解码器内部编码通道；5，本地输入通道1000开始是厂家对接特殊类型  1001，LG； 1002，松下
	char cRtspUrl[DEC_LEN_256];
	int  iLinkSwitchEnable;
}AlarmLinkSwitch, *pAlarmLinkSwitch;

//画面分割参数，使用万分比表示
typedef struct tagScreenPara
{
	int iBufSize;		//结构体大小
	int iX;				//起始点横坐标
	int	iY;				//起始点纵坐标
	int	iWidth;			//画面宽
	int	iHeight;		//画面高
}ScreenPara, *pScreenPara;

//创建拼控输出通道VVO
typedef struct tagInputChannelParam
{
	int		   iMode;
	ScreenPara tSplitScreenPara;
}InputChannelParam;

typedef struct tagCreateVVOInfo
{
	int					iBufSize;									//结构体大小
	int					iVVOChannelNo;								//拼控通道号
	int					iRows;										//拼控屏行数
	int					iCols;										//拼控屏列数
	int					iInputChannel[DEC_MAX_PHYSICAL_CHANNEL_NUM];	//各分屏绑定的输出通道号，没绑定则用0x7fffffff表示
	InputChannelParam	tInputChannelParam[DEC_MAX_PHYSICAL_CHANNEL_NUM];//通道参数
	int					iScreenType;
	ScreenPara          tEffectiveArea;
}CreateVVOInfo, *pCreateVVOInfo;


//自定义画面分割方式
typedef struct tagSplitScreen
{
	int			iBufSize;										//结构体大小
	int			iVVOChannelNo;									//拼控通道号
	int			iPicNum;										//画面数，16个
	ScreenPara	tSplitScreenPara[DEC_MAX_PICTURE_NUM];			//画面参数
}SplitScreen, *pSplitScreen;

//解码器各个通道的状态
#define CHANEEL_ON_LINE		1
#define CHANNEL_OFF_LINE	0

#define DECODE_CHANNEL		0
#define ENCODE_CHANNEL		1
typedef struct tagLocalChannelState
{
	int			iBufSize;				//输入参数：结构体大小
	int			iChannelNo;				//输入参数：通道号
	int			iState;					//输出参数：在线状态, 0-不在线  1-在线  2-不可用
	int			iType;					//输入参数：通道类型, 0-解码通道 1-编码通道
}LocalChannelState, *pLocalChannelState;

#define DEC_MAX_DAYS	7
#define DEC_MAX_TIMESEGMENT		4
//Schedle time
typedef struct tagDEC_SCHEDTIME
{
	int      iStartHour;
	int      iStartMin;
	int      iStopHour;
	int      iStopMin;
	int      iEnable;
}DEC_SCHEDTIME, *PDEC_SCHEDTIME;

//时间段
typedef struct tagAlarmScheduleParam
{
	int				iBuffSize;
	int				iChannelNo;	//标识进行智能分析的通道
	int				iAlarmType;	//128，视频丢失；129，网络端口报警；130，移动侦测；131～134，预留；135，本地端口报警；
	int				iWeekday;	//星期日到星期六（0-6）
	int				iParam1;	//iType=4时表示规则ID
	int				iParam2;	//iType= 4时表示事件类型（0：单绊线 1：双绊线 2：周界检测 3：徘徊 4：停车 5：奔跑
								//6：区域内人员密度 7：被盗物 8：遗弃物 9：人脸识别 10：视频诊断
								//11:智能跟踪 12：流量统计 13：人群聚集 14：离岗检测）
	DEC_SCHEDTIME	timeSeg[DEC_MAX_DAYS][DEC_MAX_TIMESEGMENT];		//	时间段
	void*			pvReserved;									
}AlarmScheduleParam, *PAlarmScheduleParam;

typedef struct tagAlarmLink
{
	int	iBuffSize;
	int iChannelNo;			//取值范围据设备类型而定
	int	iAlarmType;			//128，视频丢失；129，网络端口报警；130，移动侦测；131～134，预留；135，本地端口报警；136，电源报警
	int	iAlarmTypeParam;	//取值由iAlarmType而定，假如iAlarmType为智能分析，则iAlarmTypeParam表示iRuleID
	char cReserved[DEC_LEN_32];
	int	iLinkType;			//联动类型,0，联动声音提示；1，联动屏幕显示；2，联动输出端口；3，联动录像；4，联动PTZ；5，联动抓拍；
	int	iLinkParam1;	//联动参数,取值由iLinkType而定：iLinkType=0,1时，iParam1表示使能iEnable。0，不使能；1，使能。
	//iLinkType=2,3,5,6时，iParam1表示按位使能iEnableByBits，从最低位至最高位每一位表示一个音视频通道/输出端口的使能。
	//iLinkType=4时，iParam1表示待联动的通道号iLinkChannel,取值范围据设备类型而定；
	//iParam2表示待联动的类型iLinkType：0，不联动该通道PTZ，1预置位，2轨迹，3路径；iParam3表示PTZ号iNo，
	//根据iParam2的类型分别表示预置位号，轨迹号和路径号
	int	iLinkParam2;	//联动参数
	int	iLinkParam3;	//联动参数
}AlarmLink, *PAlarmLink;

#define DEC_MAX_PORT_NUM        64
#define MAX_ALARM_IN_OUT_TYPE	4

//设置报警输入是高电平触发还是低电平触发
#define DEC_ALARM_IN_LHP	0
//设置报警输出是高电平触发还是低电平触发
#define DEC_ALARM_OUT_LHP	1
//设置报警输入端口使能
#define DEC_ALARM_IN_PORT	2
//设置报警输出端口使能
#define DEC_ALARM_OUT_PORT	3

typedef struct tagAlarmInAndOut
{
	int	iBuffSize;
	int	iType;		//0：报警输入高低电平设置；1：报警输出高低电平设置；2：报警输入端口使能；3：报警输出端口使能
	int	iPortNo;	//输入输出端口号
	int	iPara1;		//与iType取值有关
	int	iPara2;		//保留
}AlarmInAndOut, *PAlarmInAndOut;

typedef struct tagAlarmNotify
{
	int	iBuffSize;
	int	iAlarmType;	//128，视频丢失；129，网络端口报警；130，移动侦测；131～134，预留；135，本地端口报警；
	int	iChannelNo;	//通道号,iType = 160，表示解码器本地端口号
	int	iState;		//1，报警；0，消警
}AlarmNotify, *pAlarmNotify;

typedef struct tagScheduleEnable
{
	int	iBuffSize;
	int iChannelNo;
	int	iAlarmType;		//128，视频丢失；129，网络端口报警；130，移动侦测；131～134，预留；135，本地端口报警；136 电源告警
	int	iEnable;		//是否使能,0：不使能 1：使能
	int	iParam1;		//参数1
	int	iParam2;		//参数2
	int	iParam3;		//参数3
}ScheduleEnable, *pScheduleEnable;

typedef struct tagVGASize
{
	int	iBuffSize;
	int iChannelNo;
	int iVGASize;
}VGASize, *pVGASize;

//解码器自动化调试
#define CMD_AUTOTEST_MIN                    0
#define	CMD_AUTOTEST_SETMACADDR				(CMD_AUTOTEST_MIN+1)	  //设置MAC地址；
#define	CMD_AUTOTEST_LAN					(CMD_AUTOTEST_MIN+2)	  //调试网卡
#define	CMD_AUTOTEST_USB					(CMD_AUTOTEST_MIN+10)     //调试USB口；
#define	CMD_AUTOTEST_ALARMIN				(CMD_AUTOTEST_MIN+12)	  //调试报警输入端口；
#define	CMD_AUTOTEST_ALARMOUT				(CMD_AUTOTEST_MIN+13)	  //调试报警输出端口；
#define	CMD_AUTOTEST_RTC			   		(CMD_AUTOTEST_MIN+15)	  //调试时钟芯片；
#define	CMD_AUTOTEST_BACKUPSYSTEM			(CMD_AUTOTEST_MIN+20)	  //备份系统；
#define CMD_AUTOTEST_VERIFYTIME				(CMD_AUTOTEST_MIN+26)	  //时间校正；
#define AUTOTEST_SWITCHLAN					(CMD_AUTOTEST_MIN+38)     //切换UI语言；
#define CMD_AUTOTEST_FPGASTATUS             (CMD_AUTOTEST_MIN+39)	  //调试FPGA的工作状态
#define CMD_AUTOTEST_DOUBLEPOWER_ALARM      (CMD_AUTOTEST_MIN+40)	  //调试双电源报警
#define CMD_AUTOTEST_UPDATEVOCHIP	        (CMD_AUTOTEST_MIN+41)	  //下载视频输出芯片程序
#define CMD_AUTOTEST_POWERDOWNDETECTIVE     (CMD_AUTOTEST_MIN+42)	  //关机按键信号侦测
#define CMD_AUTOTEST_CLUSTER				(CMD_AUTOTEST_MIN+99)	  //S5解码器集群调试组成集群；
#define	CMD_AUTOTEST_END					(CMD_AUTOTEST_MIN+100)	  //调试结束；
#define	CMD_AUTOTEST_MAX					(CMD_AUTOTEST_MIN+101)
//制造商
#define PRODUC_TIANDY                        0
#define PRODUC_OEM                           1
//UI语言
#define LANGUAGE_ENGLISH                     0
#define LANGUAGE_CHINESE                     1

typedef struct tagSystemTime
{
	int iBuffsize;
	int iYear;
	int iMonth;
	int iDay;
	int iHour;
	int iMin;
	int iSec;
}SystemTime, *pSystemTime;

typedef struct  
{
	int iSize;
	int iChanNum;
	int iAlarmInNum;
	int iAlarmOutNum;
	int iComNum;
	int iSplitChanNum;
	int iEncChanNum;
	int iUsbInterfaceNum;
	int iNetCardNum;
	int	iLocalInChnNum;
}tDevInfo, *ptDevInfo;

#define TOTAL_CHANNEL_NUM	24
typedef struct tagChannelRegInfo
{
	int		iBuffsize;
	int		m_iRegChannelNum[TOTAL_CHANNEL_NUM];
	char	m_cRegChannelPUID[TOTAL_CHANNEL_NUM][DEC_LEN_32+1];
}ChannelRegInfo, *pChannelRegInfo;

typedef struct tagChannelRegInfoEx
{
	int		iBuffsize;
	char	cRegChannelPUID[DEC_LEN_32+1];
}ChannelRegInfoEx, *pChannelRegInfoEx;


#define DEC_MAIN_FUNC_DECODER		0x6
#define DEC_SUB_FUNC_MPIC			0
#define DEC_SUB_FUNC_ALARMIN		1
#define DEC_SUB_FUNC_ALARMOUT		2
#define DEC_SUB_FUNC_VVO_SPLIT		3
#define DEC_SUB_FUNC_DEFINEPIC		4
#define DEC_SUB_FUNC_PICHIDE		5
#define DEC_SUB_FUNC_COM			6
#define DEC_SUB_FUNC_TALK			7
#define DEC_SUB_FUNC_CLUSTER		8
#define DEC_SUB_FUNC_EASYX_WINDOW	9
#define DEC_SUB_FUNC_LEVELRELATION	10
#define DEC_SUB_FUNC_ENCODECFG		11
#define DEC_SUB_FUNC_MULTIAUDIO		12
#define DEC_SUB_FUNC_LOCALINPUT		13
#define DEC_SUB_FUNC_PREVIEW		14
#define DEC_SUB_FUNC_SCREENCTRL		15
#define DEC_SUB_FUNC_UDISKFILEPLAY	16
#define DEC_SUB_FUNC_PLANLOOP		17
#define DEC_SUB_FUNC_STRIPEDSCREEN	18
#define DEC_SUB_FUNC_4KMODE			19
#define DEC_SUB_FUNC_POWERALARM		20
#define DEC_SUB_FUNC_28181PARAM		21
#define DEC_SUB_FUNC_REBOOTDOCKING	22 //重启对接程序
#define DEC_SUB_FUNC_REMOTESWICHNET	23 //远程开关网络服务
#define DEC_SUB_FUNC_ENCODECHN_PROOFADJUST	   24 //编码通道偏色偏屏调节
#define DEC_SUB_FUNC_LOCALINPUTCHN_PROOFADJUST 25 //本地输入通道偏色偏屏调节
#define	DEC_SUB_FUNC_LED_SMALLPITCH			   26 //是否支持LED小间距	0，保留；1，支持； 2，不支持
#define	DEC_SUB_FUNC_SMOOTH_MODE			   27 //0，不支持；其他，畅显模式下支持本地输入通道最大个数；
#define DEC_MAX_SUB_FUNC_TYPE				   28 
typedef struct _tagDecAbilityLevel
{
	int		iSize;
	int		iMainFuncType;			//main function type
	int		iSubFuncType;			//sub function type
	char	cParam[DEC_LEN_256];	//Capability Description
} DecAbilityLevel, *pDecAbilityLevel;

#define DEC_INVALID_CHANNEL 0x7FFFFFFF

#define DEC_NO_CHANNEL_PARAM -1  //通道无关
#define DEC_NO_PIC_PARAM     -1	//画面无关

/***************************************************************

Prameter(in) ：	_lID：登录ID
				_uiMsg：消息号
				_iChannel：通道号
				_iPos：窗口号
				_pvParam：参数
				_iParamSize：参数大小（字节）
				_pvUserData：用户数据 DEC_ClientLogonEx传入
***************************************************************/
typedef int (*MainNotify)(unsigned long _lID, unsigned int _uiMsg, unsigned int _iChannel, int _iPos, void* _pvParam, int _iParamSize, void* _pvUserData);

typedef int (*ParamChangeNotify)(unsigned long _lID, unsigned int _uiMsg, unsigned int _iChannel, int _iPos, void* _pParam, int _iParamSize, void* _lpUserData);
#define  DEC_PARACHANGE_DNSABSTRACT					1
#define  DEC_PARACHANGE_TVINFO						2
#define  DEC_PARACHANGE_RS485TYPE					3
#define  DEC_PARACHANGE_ALARMOUT					4
#define  DEC_PARACHANGE_CHANNELINFO					5
#define  DEC_PARACHANGE_SETLOOPITEM					6
#define  DEC_PARACHANGE_DELLOOPITEM					7
#define  DEC_PARACHANGE_STARTLOOP					8
#define  DEC_PARACHANGE_STOPTLOOP					9
#define  DEC_PARACHANGE_GETPTZPROTOCOLS				10
#define  DEC_PARACHANGE_PLATFORMRUN					11
#define  DEC_PARACHANGE_VGA							12
#define  DEC_PARACHANGE_MANAGERINFO					13
#define  DEC_PARACHANGE_COMMONINFO					14
#define  DEC_PARACHANGE_COMMONINFO_CHANNEL			15
#define  DEC_PARACHANGE_DZCOMMON					16
#define  DEC_PARACHANGE_SIP_VIDEOCHANNEL			17
#define  DEC_PARACHANGE_VIDEOPARAM					18
#define  DEC_PARACHANGE_VOLUME						19
#define  DEC_PARACHANGE_ALARM_LINKSWITCH			20
#define  DEC_PARACHANGE_CREATEFREEVO				21
#define  DEC_PARACHANGE_ALARM_SCHEDULE				22
#define  DEC_PARACHANGE_ALARMLINK					23
#define  DEC_PARACHANGE_ALM_IN_LHP					24
#define  DEC_PARACHANGE_ALM_OUT_LHP					25
#define  DEC_PARACHANGE_ALARM_INPORT				26
#define  DEC_PARACHANGE_ALARM_OUTPORT				27
#define  DEC_PARACHANGE_SCHEDULE_ENABLE				28
#define  DEC_PARACHANGE_TIMEZONE					29
#define  DEC_PARACHANGE_DISPLAY						30
#define  DEC_PARACHANGE_CHANGEAREA					31
#define  DEC_PARACHANGE_CREATEVVO					32
#define  DEC_PARACHANGE_SELECT_PIC					33
#define  DEC_PARACHANGE_PREFERENCE					34
#define  DEC_PARACHANGE_RESEVELASTFRAME				35
#define  DEC_PARACHANGE_LOGOPARAM					36
#define  DEC_PARACHANGE_DEVICEABSTRACT				37
#define  DEC_PARACHANGE_CLUSTER_ALIAS				38
#define  DEC_PARACHANGE_CLUSTER_CLUSTERINFO			39
#define  DEC_PARACHANGE_CLUSTER_DEVINFO				40
#define  DEC_PARACHANGE_CLUSTER_CONTRAL_CARD_INFO 	41
#define  DEC_PARACHANGE_CLUSTER_WORK_CARD_INFO	  	42
#define  DEC_PARACHANGE_MERAGE_CLUSTER				43
#define  DEC_PARACHANGE_DEMERAGE_CLUSTER			44
#define  DEC_PARACHANGE_FLOAT_WINDOW 				45
#define  DEC_PARACHANGE_PLAN 						46
#define  DEC_PARACHANGE_PLAN_ALIAS 					47
#define  DEC_PARACHANGE_OSD 						48
#define  DEC_PARACHANGE_CLUSTER_IP					49
#define  DEC_PARACHANGE_APPLY_PLAN					50
#define  DEC_PARACHANGE_DEVCOMMONNAME				51
#define  DEC_PARACHANGE_DETECT_CHANN_STATE			52
#define  DEC_PARACHANGE_SHOWOFFLINECHN				53
#define  DEC_PARACHANGE_DEVICEMACADDR				54
#define  DEC_PARACHANGE_PLATFORM_LIST				55
#define  DEC_PARACHANGE_CTRL_MAC					56
#define	 DEC_PARACHANGE_SINGLE_PIC					57
#define  DEC_PARACHANGE_AUTOTEST_SYSTEMTYPE			58
#define  DEC_PARACHANGE_AUTOTEST_DEVICEPRODUCTER	59
#define  DEC_PARACHANGE_SCREEN_REGION				60
#define  DEC_PARACHANGE_SCREEN_BASICPARA			61
#define  DEC_PARACHANGE_SCREEN_OUTPUT_MODE			62
#define  DEC_PARACHANGE_PICLEVEL_RELATION			63
#define  DEC_PARACHANGE_SYNCLOOPCTRL				64
#define  DEC_PARACHANGE_SYNCLOOPTIME				65
#define  DEC_PARACHANGE_ENCODERPAPA					66
#define  DEC_PARACHANGE_HTTPPORT					67
#define  DEC_PARACHANGE_SHOWICON					68
#define	 DEC_PARACHANGE_ALARM_EFFECT_LIGHT			69
#define  DEC_PARACHANGE_ALARM_EFFECT_REGION			70
#define  DEC_PARACHANGE_ALARM_EFFECT_TEXT			71
#define  DEC_PARACHANGE_HD_DISPLAY					72
#define  DEC_PARACHANGE_PLAN_LOOP_ITEM              73
#define  DEC_PARACHANGE_PLAN_LOOP		            74
#define  DEC_PARACHANGE_PLAN_LOOP_ITEM_DEL          75 
#define  DEC_PARACHANGE_LANPARAM_WORKMODE           76
#define  DEC_PARACHANGE_SIP_VIDEO_CHANNEL_EX_V2	    77
#define  DEC_PARACHANGE_CHAN_MAX_WIN			    78
#define  DEC_PARACHANGE_CHAN_LAYOUTLIST			    79
#define  DEC_PARACHANGE_CHAN_RESOLUTIONLIST		    80
#define  DEC_PARACHANGE_GETSCREENCTLPROTOCOLS	    81
#define  DEC_PARACHANGE_SCREENCRLPROTOCOL		    82
#define  DEC_PARACHANGE_SET_CHANNEL_VIDEO		    83
#define  DEC_PARACHANGE_CURVIDEO				    84
#define  DEC_PARACHANGE_VIDEO_PLAYMODE			    85
#define  DEC_PARACHANGE_PLAN_LOOP_ITEM_LIST         86
#define  DEC_PARACHANGE_STARTPLANLOOP				87
#define  DEC_PARACHANGE_STOPPLANLOOP				88
#define  DEC_PARACHANGE_TELNET						89
#define  DEC_PARACHANGE_SMOOTH_MODE					90
#define  DEC_PARACHANGE_HDMODE_OUTCHN				91

typedef struct _tagDecNotifyFun
{
	int iSize;
	ParamChangeNotify pParamChangeNotify;
	MainNotify pMainNotify;
}DecNotifyFun, *pDecNotifyFun;

#define MAX_PAGE_LOG_SIZE	20
typedef struct	_tagDecLogQuery			
{
	int			iChannelNo;		//	通道号
	int			iLogType;		//	日志类型
	int			iLanguage;		//	语言类型
	NVS_FILE_TIME	struStartTime;		//	开始时间
	NVS_FILE_TIME	struStopTime;		//	结束时间
	int			iPageSize;		//	页大小
	int			iPageNo;		//	页编号
}DecLogQuery, *PDecLogQuery;


#define MAX_LOG_LEN   130
typedef struct  _tagDecLogData
{
	int				iChannel;
	int				iLogType;
	NVS_FILE_TIME	struStartTime; 	/* File start time */
	/*NVS_FILE_TIME	struStoptime; 	/ * File end time * /*/
	char			cLogContent[MAX_LOG_LEN];					
}DecLogData,*PDecLogData;

#define MIN_CLUSTER_OP						 0
#define CLUSTER_MERAGE						 MIN_CLUSTER_OP
#define CLUSTER_DEMERAGE					(MIN_CLUSTER_OP+1)
#define CLUSTER_ALIAS						(MIN_CLUSTER_OP+2)
#define CLUSTER_CLUSTERINFO					(MIN_CLUSTER_OP+3)
#define CLUSTER_CONTROL_CARD_VERSIONINFO	(MIN_CLUSTER_OP+4)
#define CLUSTER_WORK_CARD_VERSIONINFO		(MIN_CLUSTER_OP+5)
#define CLUSTER_CONTROL_CARD_STATE			(MIN_CLUSTER_OP+6)
#define CLUSTER_WORK_CARD_STATE				(MIN_CLUSTER_OP+7)
#define CLUSTER_IP							(MIN_CLUSTER_OP+8)
#define CLUSTER_DEVICE_INFO					(MIN_CLUSTER_OP+9)
#define CLUSTER_SEARCH						(MIN_CLUSTER_OP+10)
#define CLUSTER_DEVICE_STATE				(MIN_CLUSTER_OP+11)
#define CLUSTER_CTRL_MAC					(MIN_CLUSTER_OP+12)
#define MAX_CLUSTER_OP						(MIN_CLUSTER_OP+13)

typedef struct tagClusterMerage
{
	int		iSize;
	char	cIP[LEN_64];
	int     iPort;
	char    cUserName[LEN_32];
	char    cPassword [LEN_32];
	char    cClusterId [LEN_64];
}ClusterMerage, *pClusterMerage;

typedef struct tagClusterAlias
{
	int		iSize;
	char	cAlias[LEN_64];
}ClusterAlias, *pClusterAlias;

typedef struct tagClusterInfo
{
	int		iSize;
	char	cClusterId[LEN_64];
	int		iDevNum;
}ClusterInfo, *pClusterInfo;

#define MAX_CLUSTER_DEVICE_COUNT 4
#define MAX_CONTROL_CARD_COUNT	 2
#define MAX_CONTROL_NET_COUNT	 2
#define MAX_WORK_CARD_COUNT      16
#define MAX_NET_CARD_COUNT		8

#define CARD_TYPE_CONTROL	1
#define CARD_TYPE_DECODE	2
#define CARD_TYPE_ENCODE	3

typedef struct tagClusterControlCardInfo
{
	int    iSize;
	int    iDevId;	
	int	   iCardId;
	char   cMasterVersion[LEN_64];
	char   cProxyVersion[LEN_64];
	char   cStreamVersion[LEN_64];    
	int    iProductModel;
	char   cSpecialVersion[LEN_64];    
	char   cDeviceModel[LEN_64];
	char   cOnvifVersion[LEN_64];  
	char   cMcuVersion[LEN_64];  
}ClusterControlCardInfo, *pClusterControlCardInfo;

typedef struct tagClusterWorkCardInfo
{
	int    iSize;
	int    iDevId;	
	int	   iCardId;
	int    iCardType;
	char   cVersion[LEN_64];
	int    iEncChnNo;	//编码通道通道号，编码卡使用
	int    iProductModel;
	char   cFpgaInVersion[LEN_64];    
	char   cFpgaOutVersion[LEN_64];
}ClusterWorkCardInfo, *pClusterWorkCardInfo;

typedef struct tagClusterDeviceInfo
{
	int    iSize;
	int    iDevId;
	int    iCtrlCardNum;
	int    iSlotdNum;
	int    iAlarmInNum;
	int    iAlarmOutNum;
	int    iComNum;    
}ClusterDeviceInfo, *pClusterDeviceInfo;

typedef struct tagClusterCardState
{
	int    iSize;	
	int    iDevId;
	int    iCardId;
	int    iState;
	int    iType;
	int    iMaxCaptility;
	int    iCurrentCaptility;    
	int    iProgress;
}ClusterCardState, *pClusterCardState;


#define SEEK_DEVICE_IPC  1
#define SEEK_DEVICE_NVD  2

#define SEEK_TYPE_IP	0
#define SEEK_TYPE_DNS	1
#define SEEK_TYPE_DMS	2
typedef struct tagClusterSearchParam
{
	int iSize;
	int iSeekDevice; // SEEK_DEVICE_IPC、SEEK_DEVICE_NVD
	int iSeekType; //SEEK_TYPE_IP、SEEK_TYPE_DNS、SEEK_TYPE_DMS
}ClusterSearchParam, *PClusterSearchParam;

typedef struct tagClusterSearchResult
{
	int iSize;
	char cMac[LEN_64];
	char cIP[LEN_64];
	char cMask[LEN_64]; 
	char cGateWay[LEN_64]; 
	char cDNS[LEN_64];
	int iChannelNum;
	int iServerPort;
	int iClientPort;
	int iDeviceType;
	int iHttpPort;
	int iProductModel;
	char cFactoryID[LEN_64];
	char cKernelVersion[LEN_64];
	char cOcxVersion[LEN_64];
	char cClusterId[LEN_64];
	char cClusterAlias[LEN_64];
	int iDevNum;
	int iSeekType;//SEEK_TYPE_IP、SEEK_TYPE_DNS、SEEK_TYPE_DMS
}ClusterSearchResult, *PClusterSearchResult;

#define CHANGEIP_TYPE_SINGLE 0 
#define CHANGEIP_TYPE_ALL	 1 
typedef struct tagClusterChangeIP
{
	int		iSize;
	int		iDevId;
	int		iCardId;
	char	cIP[LEN_16];
	char	cSubMask[LEN_16];
	char	cGateway[LEN_16];
	char	cDns[LEN_16];    
	int		iType; // CHANGEIP_TYPE_SINGLE ,CHANGEIP_TYPE_ALL
	int		iIndex;
}ClusterIP, *PClusterChangeIP;


typedef struct tagFloatWindow
{
	int    iSize;
	int    iEnable;
	ScreenPara tArea;
}FloatWindow, *pFloatWindow;

#define MAX_PLAN_COUNT 16
typedef struct tagDecPlan
{
	int    iSize;
	int	   iPlanId;
	char   cSaveTime[LEN_64];
}DecPlan, *pDecPlan;

typedef struct tagApplyPlan
{
	int    iSize;
	int	   iPlanId;
}ApplyPlan, *pApplyPlan;

typedef struct tagPlanAlias
{
	int    iSize;
	int    iPlanId;
	char   cAlias[LEN_64];
}PlanAlias, *pPlanAlias;

#define WINDOW_SEQUENCE_TOP		 1
#define WINDOW_SEQUENCE_BOTTOM   0

typedef struct tagWindowSequence
{
	int iSize;
	int iSequence; // WINDOW_SEQUENCE_TOP 、WINDOW_SEQUENCE_BOTTOM
}WindowSequence, *PWindowSequence;

typedef struct tagChannelLogoParam
{
	int    iSize;
	TLOGOPARAM tLogoParam;
}ChannelLogoParam, *pChannelLogoParam;

#define ALIGN_ABOUT_BWLOW_MIDDLE  0		//上下居中
#define ALIGN_ABOUT				  1		//上对齐
#define ALIGN_BWLOW				  2		//下对齐

#define ALIGN_LEFT_RIGHT_MIDDLE	  0		//左右对齐
#define ALIGN_LEFT				  1		//左对齐
#define ALIGN_RIGHT				  2		//右对齐

#define SHOW_STATIC               0		//静态显示
#define SHOW_DYNAMIC_LEFT_RIGHT   1		//左右移动动态显示
#define SHOW_DYNAMIC_ABOUT_BWLOW  2		//上下移动动态显示
#define SHOW_STATIC_LINE_DISPLAY  3     //静态分行显示

typedef struct tagDecOsd
{
	int   iSize;
	char  cOsd[LEN_256];
	int   iColor;
	int   iBackColor;
	int   iDiaphaneity;//0-100
	int   iFontSize; // 1-5
	ScreenPara tArea;
	int   iAboutBelowAlign;//ALIGN_ABOUT_BWLOW_MIDDLE、ALIGN_ABOUT、ALIGN_BWLOW
	int   iLeftRightAlign;//ALIGN_LEFT_RIGHT_MIDDLE、ALIGN_LEFT、ALIGN_RIGHT
	int	  iDynamic;//SHOW_STATIC、SHOW_DYNAMIC_LEFT_RIGHT、SHOW_DYNAMIC_ABOUT_BWLOW、SHOW_STATIC_LINE_DISPLAY
	int	  iEnbale;
	int   iSwitchTime;//显示切换时间
}DecOsd, *pDecOsd;

typedef struct tagBaseOffset
{
	int   iSize;
	int   iSplitScreen;
	int   iFloatWindow;
}BaseOffset, *pBaseOffset;

#define MAX_SERVER_ITEM_COUNT	8192
#define DEFAULT_SPLIT_SCREEN_OFFSET		10000
#define DEFAULT_OPEN_WINDOW_OFFSET		10000

typedef struct tagServerCommonInfo
{
	char cServerIp[DEC_LEN_32];
	int	 iServerPort;
	int	 iServerChannelNo;
	int	 iServerStreamNo;
	int  iServerNetmode;	//0:TCP, 1:UDP, 2:MUT
	int  iHoldTime;
	char cServerUserName[DEC_LEN_64];
	char cServerPassword[DEC_LEN_64];
	char cServerPtzProtocol[DEC_LEN_32];
	int  iServerPtzAddress;
	int  iSaveCfg;         //保存配置标志：0保存， 1不保存
} ServerCommonInfo, *pServerCommonInfo;

#define DEC_CON_SER_MODE_IP			0
#define DEC_CON_SER_MODE_DDNS		1
#define DEC_CON_SER_MODE_DSM		2
typedef struct tagNormalServer
{
	int					iSize;		//input para,the size of struct
	ServerCommonInfo	tCommonInfo;
	int					iConnectMode;	//0:ip, 1:DDNS, 3:DSM
	char				cServerName[DEC_LEN_128];
	char				cServerProxy[DEC_LEN_32];
	char				cVideoDecryptPassword[DEC_LEN_32];
} NormalServer, *pNormalServer; 

typedef struct tagOnvifServer
{
	int					iSize;		//input para,the size of struct
	ServerCommonInfo	tCommonInfo;
} OnvifServer,*pOnvifServer;

typedef struct tagRtspServer
{
	int					iSize;		//input para,the size of struct
	ServerCommonInfo	tCommonInfo;
	char				cRtspUrl[DEC_LEN_512];
	char				cMultIP[DEC_LEN_32];
	int					iMultPort;
} RtspServer, *pRtspServer;

typedef struct tagEncodeChannel
{
	int					iSize;		//input para,the size of struct
	ServerCommonInfo	tCommonInfo;
} EncodeChannel, *pEncodeChannel;

typedef struct tagLocalInputChannel 
{
	int					iSize;
	ServerCommonInfo	tCommonInfo;
} LocalChannel, *pLocalInputChannel;

typedef union tagServerItem
{
	int				iSize;
	NormalServer	tNormal;
	OnvifServer		tOnvif;
	RtspServer		tRtsp;
	EncodeChannel	tEncode;
	LocalChannel    tLocal;
} ServerItem, *pServerItem;

typedef struct tagDecRegServer
{
	int iSize;
	char cIP[LEN_64];
	int iPort;
	int iEnable;
}DecRegServer, *PDecRegServer;

typedef struct tagDecPuParam
{
	int iSize;
	char cID[LEN_64];
	char cUsername[LEN_64];
}DecPuParam, *PDecPuParam;

typedef struct tagDecDzInfo
{
	int iSize;
	DZ_INFO_PARAM tInfo;
}DecDzInfo, *PDecDzInfo;

typedef struct tagDecSelectPic
{
	int iSize;
	int iPicNo;
}DecSelectPic, *PDecSelectPic;

typedef struct tagPushStreamResponse
{
	int iSize;
	long lPushId;
	int result;
}PushStreamResponse, *PPushStreamResponse;

#define MAX_DEC_CHANNEL_TYPE	4 //0-视频输出通道 1-报警输入通道 2-报警输出通道 3-本地输入通道
typedef struct tagDevCommonName
{
	int  iSize;
	int  iChannelType;
	char cChannelName[DEC_LEN_64];
} DevCommonName, *pDevCommonName;


typedef struct tagChannelPicNum
{
	int  iSize;
	int  iPicNum;
	int	 iMode; // iPicNum == 20  1:20A 2: 20B
} ChannelPicNum, *pChannelPicNum;

typedef struct tagShowOfflineChan
{
	int  iSize;
	int	 iEnable; //1----显示  0:----不显示
} ShowOfflineChan, *pShowOfflineChan;

typedef struct tagComParam
{
	int				iSize;
	int				iCom;
	unsigned char	ucType;			    //485协议ID，0：透明通道，1:Pelco-P，...
	unsigned char	ucAddress;			//485地址（取值范围：0-255）
	int				iBaudrate;		    //485波特率2400，4800，9600
	unsigned char	ucDatabit;   		//485数据位，默认为8
	unsigned char	ucStopbit;			//485停止位，默认为1
	unsigned char	ucCheckbit; 		//485校验位，四种可选，0：无校验；1：奇校验；2：偶校验；
	unsigned char	ucFlowcontrol;		//485流控，默认为无流控，设置无效
	int				iComType;			//0，RS485；1，RS232绿端子；2，RS232网口
} ComParam, *PComParam;

typedef struct tagStopViewPara
{
	int        iSize;
	int        iChannel;
	int        iPos;
	int        iSaveLastFrame;	//是否保留最后一帧，0-不保留(默认值)；1-保留
	int        iSaveCfg;		//是否保存配置，0-保存；1=不保存；不发此字段默认保存
}StopViewPara, *pStopViewPara;

//CMD
#define DEC_COMMAND_MIN							0
#define DEC_COMMAND_PTZ_CONTROL			(DEC_COMMAND_MIN + 1)		//设备控制协议
#define DEC_COMMAND_PROOF_ADJUST		(DEC_COMMAND_MIN + 2)		//校正编码卡偏屏偏色
#define DEC_COMMAND_LOGWRITE			(DEC_COMMAND_MIN + 3)		//cgi report log
#define DEC_COMMAND_USERNUM				(DEC_COMMAND_MIN + 4)		//获取用户数目
#define DEC_COMMAND_USERINFO			(DEC_COMMAND_MIN + 5)		//获取用户信息
#define DEC_COMMAND_GETUSERNUM			(DEC_COMMAND_MIN + 6)		//获取用户数量
#define DEC_COMMAND_GETUSERINFO			(DEC_COMMAND_MIN + 7)		//获取用户名和密码
#define DEC_COMMAND_GETLASTERROR		(DEC_COMMAND_MIN + 8)		//获取设备错误信息
#define DEC_COMMAND_PICSNAP				(DEC_COMMAND_MIN + 9)		//下发抓拍命令
#define DEC_COMMAND_GETPICFILENAME		(DEC_COMMAND_MIN + 10)		//获取抓拍图片的文件名
#define DEC_COMMAND_SCREENCTLSET		(DEC_COMMAND_MIN + 11)      //屏控控制命令下发
#define DEC_COMMAND_REBOOTTRADE			(DEC_COMMAND_MIN + 12)      //重启外挂请求
#define DEC_COMMAND_GETUDISK_VIDEOLISTS	(DEC_COMMAND_MIN + 13)      //获取U盘视频名称
#define DEC_COMMAND_VIDEO_PLAYSET		(DEC_COMMAND_MIN + 14)      //命令下发通道画面的播放和停止
#define DEC_COMMAND_DEL_PICSNAP			(DEC_COMMAND_MIN + 15)		//删除抓拍命令
#define DEC_COMMAND_SOUNDCTRL_RESULT	(DEC_COMMAND_MIN + 16)		//获取声音状态
#define DEC_COMMAND_TALKSERVER_RESULT	(DEC_COMMAND_MIN + 17)		//获取对讲状态
#define DEC_COMMAND_MAX					(DEC_COMMAND_MIN + 18)

typedef struct tagPtzControlPara
{
	int  iSize;
	int	 iActionType;	//上、下、左、右、变倍、预置位等
	int  iControlType;	//0，普通云台控制；1，电子云台e-PTZ.缺省为0
	int  iParam1;		//根据命令类型这两个参数的含义也不一样，水平速度或预置位号…
	int  iParam2;		//垂直速度…
} PtzControlPara, *pPtzControlPara;


#define		PROOFADJUST_OPERTYPE_MANU		1		//1-manu， 2-auto 
#define		PROOFADJUST_OPERTYPE_AUTO		2		
#define		PROOFADJUST_OUT_DEV_HDMI		1		//out dev 1-HDMI， 2-VGA
#define		PROOFADJUST_OUT_DEV_VGA		    2		
#define    	PROOFADJUST_TYPE_RESO			1       //Type，1-Video Resolution  2-Video Color
#define    	PROOFADJUST_TYPE_COLOR			2
#define    	PROOFADJUST_CHANNELTYPE_ENCODE     0       //Channel Type，0-Encode  1-LocalInput
#define    	PROOFADJUST_CHANNELTYPE_LOCALINPUT 1
typedef struct tagProofAdjust
{
	int  iSize;
	int	 iOperateMethod;	//1-手动， 2-自动
	int  iVoId;				//1-HDMI， 2-VGA
	int  iType;				//1-视频分辨率  2-视频颜色
	int  iChannelType;      //通道类型无该字段，通道类型为编码通道,0-编码通道1-本地输入通道
} ProofAdjust, *pProofAdjust;

typedef struct tagAutoTestResult
{
	int iSize;
	int iItem;
	int iTestParam;
	int iResult;
	char cTestParam[LEN_128];
}AutoTestResult, *PAutoTestResult;


typedef struct tagUserInfo
{
	int  iSize;
	int  iUserId;
	char cUserName[LEN_16];
	char cPassword[LEN_16];
}UserInfo, *PUserInfo;

typedef struct tagUserNum
{
	int iSize;
	int iUserNum;
}UserNum, *PUserNum;

#define LOG_WRITE_TYPE_CHANGE_PASSWD_SUCCESS	4001
#define LOG_WRITE_TYPE_CHANGE_PASSWD_FAILED		4002
#define LOG_WRITE_TYPE_LOGON_SUCCESS			4003
#define LOG_WRITE_TYPE_LOGON_FAILED				4004


#define MAX_LOG_WRITE_COUNT 4
typedef struct tagDecLogWrite
{
	int iSize;
	int iLogType;
	int iCount;
	char cParam[MAX_LOG_WRITE_COUNT][LEN_64];
}DecLogWrite, *PDecLogWrite;

typedef struct tagDecCtrlMac
{
	int iSize;
	int iDevId;
	int iCardId;
	int iNetId;			//网卡编号
	char cPcMac[LEN_64];	  
}DecCtrlMac, *PDecCtrlMac;

#define SHOW_LAST_FRAME 1

#define DELETE_LOOOP_ITEM_EXCEPT 0
#define ADD_LOOP_ITEM_EXCEPT	 1

#define AUDIO_STATUS_CLOSE		0
#define AUDIO_STATUS_OPEN		1
#define AUDIO_STATUS_FAILD      -1
#define AUDIO_FAILD_REASON_RESERVE 0
#define AUDIO_FAILD_REASON_MUTEX   1

#define TALK_STATUS_CLOSE		0
#define TALK_STATUS_OPEN		1
#define TALK_STATUS_FAILD      -1
#define TALK_FAILD_REASON_RESERVE 0
#define TALK_FAILD_REASON_MUTEX   1

#define VIEW_STATUS_STOP		0
#define VIEW_STATUS_RUN			1

#define LOOP_STATUS_STOP		0
#define LOOP_STATUS_START		1

#define LOOP_TYPE_VIDEO		0
#define LOOP_TYPE_PLAN		1

#define EX_CHANNEL_FLAG		0x7FFFFFFF

//ErrorID
#define DEC_LASTERROR_ALARMLINK		0x13000		//（报警联动）当前正在联动，不允许修改设置
#define DEC_LASTERROR_MODIFY_IP		0x13100		//ip地址修改失败

typedef struct tagDecLastError
{
	int		iSize;			
	int		iErrorID;
	char	cErrorInfo[DEC_LEN_64]; 
} DecLastError, *pDecLastError;

typedef struct tagDecSinglePic
{
	int		iSize;	
	int		iPicNum;
	int		iState;	//单画面状态:0-非单画面模式, 1-单画面
} DecSinglePic, *pDecSinglePic;

typedef struct tagDecScreenRegion
{
	int		iSize;
	int		iEnable;		//使能
	int		iXPos;			//起始横坐标
	int		iYPos;			//起始纵坐标
	int		iPixelWidth;	//像素宽度
	int		iPixelHeight;	//像素高度
} DecScreenRegion, *pDecScreenRegion;

typedef struct tagDecScreenBasicPara
{
	int		iSize;	
	int		iBrightness;	//亮度，0～100
	int		iContrast;		//对比度，0～100
	int		iSaturation;	//饱和度，0～100
	int		iHue;			//色度，0～100
} DecScreenBasicPara, *pDecScreenBasicPara;

#define SCREEN_OUTPUT_MODE_HDMI				0
#define SCREEN_OUTPUT_MODE_DVI				1
#define SCREEN_OUTPUT_MODE_ADAPTATION		2
typedef struct tagDecScreenOutputMode
{
	int		iSize;	
	int		iMode;		//0:HDMI 1:DVI 2:自适应
} DecScreenOutputMode, *pDecScreenOutputMode;

typedef struct tagDecPicLevelRelation
{
	int		iSize;
	int		iPicCount;
	int		iLevelArray[DEC_MAX_WINDOW_TOTAL_NUM];	//层级关系:下标为画面号，层级关系从最底层开始为0，往上依次加1。
			//其中iLevelArray[0]是第0画面的层级，iLevelArray[1]是第1画面的层级……iLevelArray[N]是第N画面的层级
} DecPicLevelRelation, *pDecPicLevelRelation;

typedef struct tagDecSyncLoopCtrl
{
	int		iSize;	
	int		iLoopEnable;	//0：停止切换， 1：开始切换
} DecSyncLoopCtrl, *pDecSyncLoopCtrl;

typedef struct tagDecSyncLoopTime
{
	int		iSize;	
	int		iHoldTime;		//停留时间：10-999
} DecSyncLoopTime, *pDecSyncLoopTime;

typedef struct tagDecEncodePara
{
	int		iSize;	
	int		iWidth;			//视频宽
	int		iHeight;		//视频高
	int		iFrameRate;		//帧率，有效值：1～25，50，60
	int		iBitRate;		//码率，单位为KBytes/s，如1024kbps的码率
} DecEncodePara, *pDecEncodePara;

typedef struct tagDecHttpPort
{
	int		iSize;	
	int		iPort;			//HTTP端口号
	int		iHttpsPort;		//HTTPS端口号
	int		iRtsPort;		//端口号 
	int		iSchedulePort;	//排期端口号
} DecHttpPort, *pDecHttpPort;

typedef struct tagDecShowIcon
{
	int     iSize;
	int     iIconType;		//图标类型,1-655350-预留,1-画面底端红色报警闪烁
	int     iDisp;			//是否显示,0 不显示 1 显示
} DecShowIcon, *pDecShowIcon;

typedef struct tagDecAlarmEffectLight
{
	int     iSize;
	int     iEnable;				//特效使能：1--使能，0--关闭					
	int		iDuration;				//特效持续时间 	单位：秒					
	int		iColor;					//颜色：32位中取低24位表示颜色rgb, 代表数字方式bgr。[((DWORD)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))]				
	int		iFlashtime;				//闪烁间隔,	单位：毫秒					
} DecAlarmEffectLight, *pDecAlarmEffectLight;

#define MAX_EFFECTREGION_POINT_COUNT		8
typedef struct tagDecAlarmEffectRegion
{
	int     iSize;
	int     iEnable;				//特效使能：1--使能，0--关闭					
	int		iDuration;				//特效持续时间 	单位：秒
	int		iWidth;					//边框宽度
	int		iColor;					//颜色：32位中取低24位表示颜色rgb, 代表数字方式bgr。[((DWORD)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))]					
	int		iPointCount;			//区域顶点数，最大8个点					
	POINT	tPoints[MAX_EFFECTREGION_POINT_COUNT];	//点坐标, 相对于视频分辨率的万分比坐标			
} DecAlarmEffectRegion, *pDecAlarmEffectRegion;

typedef struct tagDecAlarmEffectText
{
	int     iSize;
	int     iEnable;				//特效使能：1--使能，0--关闭					
	int		iDuration;				//特效持续时间 	单位：秒
	int		iFontSize;				//字体大小，范围1-5，代表5个级别的字体大小
	int		iColor;					//颜色：32位中取低24位表示颜色rgb, 代表数字方式bgr。[((DWORD)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))]					
	char	cText[LEN_64];			//文本内容	最大64字节					
	int		iTextAlign;				//对齐方式：0--用户自定义, 1--左上角, 2--左下角, 3--右上角, 4--右下角, 5居中					
	POINT	tPoint;					//字符叠加左上角坐标，相对于视频分辨率的万分比坐标					
	int		iTextWidth;				//文本区域宽度，实际分辨率					
	int		iTextHeight;			//文本区域高度，实际分辨率					
	int		iLeft;					//左边距，iTextAlign为1, 2时有效					
	int		iTop;					//上边距，iTextAlign为1, 3时有效					
	int		iRight;					//右边距，iTextAlign为3, 4时有效					
	int		iBottom;				//下边距，iTextAlign为2, 4时有效						
} DecAlarmEffectText, *pDecAlarmEffectText;

#define DEC_MAX_PLAN_LOOP_ITEM_NUM MAX_PLAN_COUNT
typedef struct tagPlanLoopItem
{
	int     iIndex;		//切换序列号
	int		iPlanNo;	//预案编号
	int		iHoldTime;	//停留时间 30-9999
}PlanLoopItem,*pPlanLoopItem;

typedef struct tagPlanLoopList
{
	int     iCount;		//切换列表数目
	PlanLoopItem tPlanLoopItem[DEC_MAX_PLAN_LOOP_ITEM_NUM];
}PlanLoopList,*pPlanLoopList;

typedef struct tagPlanLoop
{
	int     iEnable;	//使能
	int     iCount;     //数目
	int		iIndex;	    //当前切换序列号
	int		iPlanNo;	//当前预案编号
}PlanLoop,*pPlanLoop;

typedef struct tagPlanLoopItemDel
{
	int		iIndex;	    //要删除的切换序列号
}PlanLoopItemDel,*pPlanLoopItemDel;

//设备网络工作模式
typedef	struct tagLanParamWorkMode
{
	int				iWorkMode;				//工作模式0，备份；1，多址
	int				iMainLanNo;				//主网卡编号0，Lan1；1，Lan2
}LanParamWorkMode, *pLanParamWorkMode;

typedef struct tagSipVideoChannelEx
{
	char 	cChannelID[DEC_MAX_CHANNELID_LEN+1];
	int     iLevel;
	int     iPtzTime;
	int		iConnectMode;
	int		iTCPConnectType;
}SipVideoChannelEx, *pSipVideoChannelEx;

typedef struct tagDecChanMaxWin
{
	int     iMaxWin;
}DecChanMaxWin, *pDecChanMaxWin;

#define  DEC_MAX_LAYOUT_NUM 32
typedef struct tagDecChanLayoutList
{
	int     iLayoutNum;
	int		iLayout[DEC_MAX_LAYOUT_NUM];

}DecChanLayoutList, *pDecChanLayoutList;

#define  DEC_MAX_RESOLUTION_NUM 32
typedef struct tagDecChanResolutionList
{
	int     iResolutionNum;
	int		iResolution[DEC_MAX_RESOLUTION_NUM];
}DecChanResolutionList, *pDecChanResolutionList;

typedef struct tagPicSnap
{
	ServerItem uServerItem;
	int serType;			//0，Tiandy；1，Onvif；2，push流；3，rtsp；4，解码器内部编码通道；5，本地输入通道
							//1000开始是厂家对接特殊类型  1001，LG； 1002，松下；
}PicSnap,*pPicSnap;

typedef struct tagPicSnapResult
{
	int     iRet;				//0，成功；1，失败；
	int     iSnapID;			//抓拍ID
}PicSnapResult, *pPicSnapResult;

typedef struct tagPicSnapID
{
	int     iSnapID;//抓拍ID
}PicSnapID, *pPicSnapID;

typedef struct tagPicSnapFileName
{
	int     iSnapID;
	int     iState;					//0，成功；1，失败；2，抓拍中
	char    cPicFileName[LEN_256];	//抓拍图片文件名
}PicSnapFileName, *pPicSnapFileName;

typedef struct tagScreenCtlProtocols
{
	int		iCount;													//协议个数
	char 	cProtocol[MAX_PROTOCOL_NUM][MAX_PROTOCOL_NAME_LEN32+1];	//各协议名称，最多支持128个协议，每条协议名称最长32字节；	
}ScreenCtlProtocols, *pScreenCtlProtocols;

typedef struct tagScreenCtlProtocol
{
	int     iScreenNo;		//拼接屏的编号，指的是在IE上显示的屏幕编号			
	int     iAddressNo;		//屏幕地址码0x11~0xAA				
	int     iComNo;			//串口编号
	char 	cProtocol[MAX_PROTOCOL_NAME_LEN32+1];
}ScreenCtlProtocol, *pScreenCtlProtocol;

typedef struct tagScreenCtl
{
	int     iScreenNo;		//拼接屏的编号，指的是在IE上显示的屏幕编号			
	int     iActionType;	//屏控命令：1：开关机；2：拼接屏选择；3：对比度；4：亮度；5：色饱和度；6：清晰度
	int     iParam;			//命令具体参数：（1）开关机命令0-关机，1-开机（2）拼接屏选择命令时0-AV，
							//1-S-VIDEO，2-VGA，3-DVI，4-HDMI（3）四度控制（对比度、亮度、色饱和度、清晰度）命令0-减少，命令1-增加
}ScreenCtl, *pScreenCtl;

typedef struct tagScreenCtlResult
{
	int     iScreenNo;					
	int     iActionType;	
	int     iParam; 
	int     iResult;		//0：预留，1：成功，2：失败
}ScreenCtlResult, *pScreenCtlResult;

typedef struct tagRebootTradeResult
{
	int       iResult;		//0：预留，1：成功，2：失败
}RebootTradeResult,*pRebootTradeResult;

#define DEC_MAX_VIDEOLIST_SIZE			100

typedef struct tagUDiskVideoList
{
	int      iCount;
	char 	 cVideoName[DEC_MAX_VIDEOLIST_SIZE][LEN_128];	//视频名称	
}UDiskVideoList, *pUDiskVideoList;

typedef struct tagUDiskCurVideo
{
	int		iCurVideoState;		//视频状态
	char 	cVideoName[LEN_128];	//视频名称	
}UDiskCurVideo, *pUDiskCurVideo;


#define DEC_MAX_UDISK_CHANNEL_VIDEO		20
typedef struct tagUDiskSetChannelVideo
{
	int		iVideoNum; //视频个数
	char 	cVideoName[DEC_MAX_UDISK_CHANNEL_VIDEO][LEN_128];	//视频名称	
	int     iChannelNo;
	int     iPos;
}UDiskSetChannelVideo, *pUDiskSetChannelVideo;

#define DEC_MAX_UDISK_ALL_CHANNEL_VIDEO		10
typedef struct tagUDiskAllChannelVideo
{
	int    iCount;
	UDiskSetChannelVideo tUDiskSetChannelVideo[DEC_MAX_UDISK_ALL_CHANNEL_VIDEO];
}UDiskAllChannelVideo, *pUDiskAllChannelVideo;


typedef struct tagVideoPlayMode
{
	int		iPlayMode; //播放模式类型视频播放类型：1：循环播放 2：顺序播放  
}VideoPlayMode, *pVideoPlayMode;

typedef struct tagVideoPlayCmd
{
	int		iPlayCmd;  //播放命令0：停止播放 1：开始播放  
}VideoPlayCmd, *pVideoPlayCmd;

typedef struct tagVideoPlayCmdResult
{
	int			 iPlayCmd;
	int			 iResult;      //0：预留，1：成功，2：失败
}VideoPlayCmdResult, *pVideoPlayCmdResult;

typedef struct tagPlanLoopStatus
{
	int			 iStatus;//0：开始切换 1：停止切换
}PlanLoopStatus, *pPlanLoopStatus;

typedef struct tagLoopParam
{
	int			 iType;	//0,视频切换列表；1， 预案切换列表
}LoopParam, *pLoopParam;

typedef struct tagSoundCtrlResult
{
	int iAudioStatus;//0:AUDIO_STATUS_CLOSE	1:AUDIO_STATUS_OPEN	-1: AUDIO_STATUS_FAILD
	int iFailReason;//0：预留；1：对讲已打开，与本地音频预览存在互斥
}SoundCtrlResult;

typedef struct tagTalkServResult
{
	int iTalkStatus;//0:TALK_STATUS_CLOSE	1:TALK_STATUS_OPEN	-1:TALK_STATUS_FAILD      
	int iFailReason;//0：预留；1：本地音频预览已打开，与对讲存在互斥
}TalkServResult;

typedef struct tagHDModeOutChannel
{
	int iOutChnNum;							  //高清模式下，支持输出通道数量
	int iOutChnn[DEC_MAX_CHANNEL_TOTAL_NUM];  //输出通道号
}HDModeOutChannel;

typedef struct tagSmoothMode
{
	int iEnable;							     //畅显模式使能
	int iLocalInNum;							 //输入通道数量
	int iEnableChnn[DEC_MAX_ENCODE_CHANNEL_NUM]; //使能本地输入通道
}SmoothMode;

#endif
