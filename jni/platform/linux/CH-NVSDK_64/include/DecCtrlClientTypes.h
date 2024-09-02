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
//��Ϣ�ص�����
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
#define DEC_MAX_CHANNELID_LEN   32             //���ͨ��ID����

/**********************************************abandon************************************************/
#define	DEC_MAX_CHANNEL_NUM				8     //ÿ�����������ͨ����
#define	DEC_MAX_CHANNEL_NUM_NEW			16     //ÿ�����������ͨ��������·��������չ��16������������ͨ��
#define	DEC_MAX_VIRTUAL_CHANNEL_NUM		8      //ÿ���������������ͨ��������������ʹ��,����ͨ���Ŵ�16��ʼ
#define DEC_MAX_SPLIT_SCREEN_NUM		16		//�������ķ�������

#define DEC_MAX_FLOAT_WINDOW_NUM 16
#define DEC_MAX_PICTURE_NUM		100             //ÿ������ͨ����໭������չ��100��
#define DEC_MAX_WINDOW_TOTAL_NUM        (DEC_MAX_PICTURE_NUM + DEC_MAX_FLOAT_WINDOW_NUM)

#define	DEC_MAX_PHYSICAL_CHANNEL_NUM 	96  //�������ͨ����
#define DEC_MAX_SPLIT_CHANNEL_NUM       48  //���ƴ��ͨ����

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

//��ȡͨ������ÿ��ͨ���Ļ�����
typedef struct tagChnNumAndMode
{
	int			iBufSize;				//�ṹ���С
	int			iLocalChnNum;			//����ͨ����
	int			iVOChnNum;				//ƴ��ͨ����
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

#define DEC_MAX_NVSITEM_NUM     256             //ÿ���������NVS����
#define DEC_MAX_DECODER         128				//������ӽ�������
#define DEC_MAX_COM_NUM			2				//��󴮿���
#define DEC_MAX_COM_NUM_NEW		8				//��󴮿���(��)
#define DEC_MAX_USER_NUM		32				//����û�����

#define DEC_MAX_ALARM_OUT 7
#define DEC_MAX_ALARMMODE 1
#define DEC_MAX_IS_PAL	  1
#define DEC_MAX_LANGUAGE  1

#define NVS_MAX_CHANNEL_NUM		320				//�豸�����ͨ������չ��64�����ݴ�·��nvr

//��Ϣ����
#define DEC_WCM_DEC_LOGON         1   //��¼״̬��Ϣ
#define DEC_WCM_NVS_STARTVIEW     2   //����NVS��Ϣ
#define DEC_WCM_DEC_TALK          3   //�Խ���Ϣ

#define DEC_WCM_DEC_UPGRADE       4   //������������Ϣ
#define DEC_WCM_DEC_UPGRADELOGO   5   //����Logo��Ϣ
#define DEC_WCM_DEC_UPGRADEP      6   //��������Э����Ϣ

#define DEC_WCM_ERR_ORDER         7   //����㷢������
#define DEC_WCM_NVS_STOPVIEW      8   //�Ͽ�NVS��Ϣ
#define DEC_WCM_DEC_PARASET       9   //�����ı���Ϣ

#define DEC_WCM_DEC_UPGRADEWEB      10  //������ҳ��Ϣ
#define DEC_WCM_DEC_UPGRADEPROCESS  11  //��������������
#define DEC_WCM_DEC_AUDIOSTATUS     12  //��Ƶ״̬��Ϣ
#define DEC_WCM_DEC_TALK_FAILED     13  //add by lpy for �Խ�ʧ��
#define DEC_WCM_DEC_AUDIO_FAILED    14  //add by lpy for ��Ƶʧ��[2/5/2010 Administrator]

#define DEC_WCM_DEC_PUSHSTREAM		20	//Push stream ���
#define DEC_WCM_ERR_PUSHSTREAM		21	//Push stream ��������Ͽ�
#define DEC_WCM_ERR_DATANET         22  //����ͨ�����������쳣

#define DEC_WCM_ERR_USERPASS		25	//�޸�������
#define DEC_WCM_DETECT_CHANN_STATE	26	//����������ͨ����״̬
#define DEC_WCM_ALARM_NOTIFY		27	//�����ϱ�����
#define DEC_WCM_PARASET_CREATEVVO	28  //����ƴ�����ͨ����Ϣ

#define DEC_WCM_AUTOTEST_INFO		29  //�Զ������� 

#define DEC_WCM_QUERY_LOG_FINISH	30  //��־��ѯ

#define DEC_WCM_NVS_STARTVIEW_FAILED      31   //����NVSʧ����Ϣ

#define DEC_WCM_SEARCH_IPC			32   //��������IPC
#define DEC_WCM_SEARCH_NVD			33   //�������ֽ�����

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


//encodemode: ��������
//0��H.264��1��MJPEG�� 23:H265, 31:MPEG4 100��PS��
#define ENCODE_H264			0
#define ENCODE_MJPEG		1
#define ENCODE_H265			23
#define ENCODE_MPEG4		31
#define ENCODE_PS			100

//videosize: ��Ƶ��С
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
	//����ģʽ
	F720P_9_16		= 0x100009,		//720x 1280
	F1080P_9_16		= 0x10000C,		//1080x 1920
	F4M_9_16		= 0x100210,		//1440x2560
	F4MB_9_16		= 0x100220,		//1520x2592
	VIDEO_BUTT
};

#define VIDEO_SIZE_DEFAULT 255



#ifndef EMBEDED_USE
//VGA�ֱ���
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

//��¼״̬
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
* SIPЭ�����                                                                     
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

#define DEC_MAX_LAN_NUM 2   //�����������
typedef struct tagIPAddress
{
	char			ip[16];			//������IP��ַ
	char			submask[16];		//��������������
	char			gateway[16];		//�����������ص�ַ
	char			dns[16];			//DNS��ַ
}IPAddress, *pIPAddress;

typedef struct tagMacAddress
{
	char			cMac[18];			//�����ַ
}MacAddress, *pMacAddress;

/*��������������=======================================*/
typedef struct
{
	char			m_ip[16];			//������IP��ַ
	char			m_submask[16];		//��������������
	char			m_gateway[16];		//�����������ص�ַ
	char			m_dns[16];			//DNS��ַ

	MacAddress		m_tMacAddress[DEC_MAX_LAN_NUM];			//�����ַ

	char			m_ddnsIP[16];		//����������IP��ַ
	char			m_ddnsUser[16];		//�����������û���
	char			m_ddnsPass[16];		//��������������
	unsigned short	m_ddnsPort;			//�����������˿�
	unsigned char	m_ispal;			//0:PAL��1:NTSC
	unsigned char	m_language;			//0:���ģ�1:Ӣ��

	unsigned char	m_rs485type[DEC_MAX_COM_NUM];			//485Э��ID��0��͸��ͨ����1:Pelco-P��...
	unsigned char	m_rs485address[DEC_MAX_COM_NUM];		//485��ַ��ȡֵ��Χ��0-255��
	int				m_rs485baudrate[DEC_MAX_COM_NUM];		//485������2400��4800��9600
	unsigned char	m_rs485databit[DEC_MAX_COM_NUM];   		//485����λ��Ĭ��Ϊ8
	unsigned char	m_rs485stopbit[DEC_MAX_COM_NUM];		//485ֹͣλ��Ĭ��Ϊ1
	unsigned char	m_rs485checkbit[DEC_MAX_COM_NUM]; 		//485У��λ�����ֿ�ѡ��0����У�飻1����У�飻2��żУ�飻3���̶�Ϊ1��4���̶�Ϊ0
	unsigned char	m_rs485flowcontrol[DEC_MAX_COM_NUM];	//485���أ�Ĭ��Ϊ�����أ�������Ч

	int				m_Alarmout;								//�������������ϵ��&0x01:�˿ڱ�����&0x02:��ʧ������&0x04:�ƶ�������1��ʾ���������0��ʾ�����������
    int			    m_AlarmMode;							//�������ģʽ��0���͵�ƽ������1���ߵ�ƽ����
	int				m_iChannel;								//����ͨ������0-8
	int				m_iComNumber;							//��������0-1
	unsigned char	m_nChanMode[DEC_MAX_CHANNEL_NUM];		//ÿ��ͨ���Ĺ���ģʽ��1�������棻4���Ļ��棩

	int             m_iVGASize[DEC_MAX_CHANNEL_NUM];		//ÿ��ͨ����VGA�ֱ��ʣ�1��800*600 60Hz����2��1024*768 60Hz����3��1280*1024 60Hz������ΪBNCͨ������ò�����Ч
#ifdef __WIN__
	char			m_cRegSvrIP[32];
	int				m_iRegSvrPort;
	int				m_iRegSvrEnable;

	char			m_cPUID[21];							//	
	char			m_cPUName[DEC_LEN_32+1];



	int				m_iVolume;				//	����

	int				m_iSelPic[2];			//	����ѡ��                           
//.................SIP.....@cmz..110223
	DZ_INFO_PARAM	m_dzInfoParam;
	TGetSipVideoChannel m_SipVideoChannel;
	//................��Ƶ��������.....
	STR_VideoParam  m_VideoParam[DEC_MAX_CHANNEL_NUM];
	int				m_iRegChannelNum[2];
	char			m_cRegChannelPUID[2][DEC_LEN_32+1];
#endif
}TDECPARAM;

#define RTSP_URL_LEN	81
/*��Ƶͨ����������======================================*/
typedef struct
{
	union
	{
		char				m_cRTSPUrl[RTSP_URL_LEN+1];		//RTSP��ַ
		struct  
		{
			char 			m_serName[33];		//����������(��ʱ����)
			char 			m_serIP[33];		//��������ַ��������IP��ַ��Ҳ������������       zyp modified 0506
			char			m_serProxy[16];		//�������ϼ�����
		};		
	};
	
	unsigned char	m_serChan;			//������ͨ��
	unsigned char	m_serStream;		//��������������
	unsigned char	m_serNetmode;		//����Э��1��TCP��2��UDP��3���ಥ��
	unsigned char	m_bUseddns;			//ͨ����������������
	unsigned short	m_serPort;			//�������˿�
	int				m_bisView;			//��ǰ�Ƿ�������״̬��1������״̬��0��δ����״̬(��ʱ��ʹ��)
	char		   	m_username[20];		//�û���
	char	       	m_password[20];		//����
	int         	m_holdtime;			//����ʱ�䣬ȡֵ��Χ��5�D�D1000��
    char            m_deviceType[16];   //�豸����Э�飨��Ҫ���뵽��Э�飩
    unsigned char   m_iAddress;         //NVS�豸��ַ��ȡֵ��Χ��0-255��
} TNVSITEM;

//��Ƶͨ��������չ����
#define MAX_ENCYPTPWD_LEN	16
typedef struct __tagTNVSITEMEX
{
	int				m_iStructLen;							//����Ժ�Ҫ��չ�����Ը�������������ж���չ�ֶε�����
	TNVSITEM		m_stOldItem;
	char			m_cEncyptPWD[MAX_ENCYPTPWD_LEN + 1];	//��������
	int				m_iDevPlatType;							//�豸ƽ̨���ͣ�0-��ͨ��1-Onvif 2-push�� 3-RTSP��
	void*			m_pvReserved;							//Ϊ�˱�����չ
	char			m_cMultIP[33];							//�鲥��ַЭ��
	int				m_iMultPort;							//�鲥�˿ں�
	int             m_isavecfg;                             //�������ñ�־
}TNVSITEMEX, *LPTNVSITEMEX;

/*������֧�ֵ�Э���б���===============================*/
typedef struct
{
	int		m_iCount;					//������֧�ֵ�Э��������
	char 	m_cProtocol[LEN_128][LEN_16];		//��Э�����ƣ����֧��128��Э�飬ÿ��Э�������15�ֽڣ�
} TDECPROTOCOL;

/*SDK�汾�Ŷ���==========================================*/
typedef struct
{
	unsigned short	m_ulMajorVersion;
	unsigned short	m_ulMinorVersion;
	unsigned short  m_ulBuilder;
	char*			m_cVerInfo;
}NVDSDK_VERSION;

/*OSD����Logo���Զ���====================================*/
typedef struct
{
    unsigned char m_enable;           //�Ƿ����Logo
    int           m_iPosX;            //����Logo������
    int           m_iPosY;            //����Logo������
    unsigned char m_iAlpha;           //͸����(0~100)��100Ϊ��ȫ��͸��
    int           m_iTransparentColor;//����ɫ��RGB��ʽ(0x00000000~0x00ffffff)
}TLOGOPARAM;


/*�豸֧��ƽ̨��Ϣ����====================================*/
typedef struct  
{
	int     m_iCount;                 //֧�ֵ�ƽ̨��Ŀ
	char    m_cPlatformName[10][32];  //����ƽ̨������       
}TPLATFORMINFO;

/*�����붨��=============================================*/
#define ERR_SUCCESS					0		//�ɹ�
#define ERR_ISVIEW					1       //�����������ӵ�NVS
#define ERR_INVALIDID				-1		//ָ���Ľ�����������
#define ERR_UNINIT					-2		//��������δ��ʼ��/��ʼ��ʧ��
#define ERR_INVALIDPARA				-3		//����Ƿ�����
#define ERR_INVALIDFILE				-7		//�ļ���ʽ�Ƿ�
#define ERR_NOTLOGON				-8      //û�е�¼
#define ERR_MAXDEC					-10     //�ﵽ���������
#define ERR_FORBID					-12     //���������
#define ERR_RELOOPITEM				-13     //��ѭ���б�������ظ�������
#define ERR_NOCONNECTED				-16		//��û�н�������
#define ERR_POS_X_Y					-17		//����Ƿ�
#define ERR_NULL_PTR				-18		// null pointer
#define ERR_UNDEFINED_BEHAVIOR		-19		// undefined behavior
#define ERR_INVALID_BUFF_SIZE		-20		//���Ϸ��Ļ�������С
#define ERR_INVALID_ARRAY_INDEX		-21		//���Ϸ��������±�
#define ERROR_INVALID_PARAM			-22		//�������Ϸ�
#define ERR_REPEAT_SET				-23		//�ظ�����
#define ERR_BUILD_PROTOCOL			-24		//build protocol error
#define ERR_SEND_PROTOCOL			-25		//send protocol error
#define ERR_NO_IDLE_ITEM			-26		//no idle item
#define ERR_INVALID_FILEHEADER		-27		//invalid file header
#define ERR_LIGHTMODE_NOTSUPPORT	-28		//sdk light mode not support
#define ERR_OUT_OF_MEMERY			-29		//sdk out of memery

/*�����붨��=============================================*/
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

#define DECKEYCODE_UP		0X0D    //��
#define DECKEYCODE_DOWN		0X0E    //��
#define DECKEYCODE_LEFT		0X0F    //��
#define DECKEYCODE_RIGHT	0X10    //��
#define DECKEYCODE_PAGEUP	0X11    //�Ϸ�ҳ
#define DECKEYCODE_PAGEDOWN	0X12    //�·�ҳ
#define DECKEYCODE_EDIT		0X13    //�༭
#define DECKEYCODE_ESC		0X14    //ȡ��
#define DECKEYCODE_RETURN	0X15    //ȷ��
#define DECKEYCODE_ABC		0X16    //���뷨�л�
#define DECKEYCODE_DEV		0X17    //DEV
#define DECKEYCODE_F1		0X18    //F1  
#define DECKEYCODE_F2		0X19    //F2

#define DECKEYCODE_MENU		0X20    //�˵�

#define DECKEYCODE_STOP		0X52	//ֹͣ(��������ʱ����)

#ifndef EMBEDED_USE
/*��̨�����붨��===========================================*/
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

//	�����豸ƽ̨����
#define	DEVTYPE_NORMAL			0
#define	DEVTYPE_ONVIF			1
#define	DEVTYPE_PUSH			2
#define	DEVTYPE_RTSP			3
#define DEVTYPE_ENCODE			4
#define DEVTYPE_LOCAL           5
#define DEVTYPE_LG				1001
#define DEVTYPE_PANASONIC		1002

//	����ͨ��ҵ������
#define COMMONID_NETCUT_HOLD_LASTFRAME	0x13001
#define COMMONID_PREVIEW_PREFERENCE		0x13002
#define COMMONID_HD_DISPLAY				0x13003
#define COMMONID_TELNET					0x13004 //ʹ��telnet

//��������
#define PUSH_STREAM_CMD_TYPE	0
#define PUSH_STREAM_CMD_PAUSE	0
#define PUSH_STREAM_CMD_FAST	1
#define PUSH_STREAM_CMD_SLOW	2

//push��������ͣ״̬
#define PUSH_REAL_TIME_STREAM_STATE		0x100	//ʵʱ��
#define PUSH_PLAYBACK_STREAM_PLAY		0		//�ط�������
#define PUSH_PLAYBACK_STREAM_PAUSE		1		//�ط�����ͣ

//������״̬
#define		RET_BUFFER_IS_ALREADY_FULL		(-10)		//	�������Ѿ����ˣ�����û�з��뻺������������Ҫ���·���
#define		RET_BUFFER_IS_EMPTY				(-21)		//	��������
#define		RET_PAUSE_STATE					(-30)		//	��ͣ״̬

//push���ٶ�����
#define		PUSH_SLOW_SPEED		0
#define		PUSH_NORMAL_SPEED	1
#define		PUSH_FAST_SPEED		2

//push�����StartPush�ṹ��
#define 	MAX_ENCRYPT_KEY			16
#define		VIDEO_HEADER_SIZE		88
typedef struct
{
	int		m_iSize;							//�ṹ���С
	char 	m_cFileHeader[VIDEO_HEADER_SIZE];	//��Ƶͷ
	char	m_cEncryptKey[MAX_ENCRYPT_KEY + 4];	//ǰ���豸��Ƶ�������룬Ϊ�����ʾ�����ܣ�
												//����16���ַ��ұ�֤���ֽ�
}START_PUSH_PARAM;

//����������Ϣ
#define		MIN_CONF_CMD					0
#define		CONF_CMD_VIDEOHEAD				MIN_CONF_CMD + 1
#define		CONF_CMD_AUDIOVIDEO				MIN_CONF_CMD + 2
#define		MAX_CONF_CMD					MIN_CONF_CMD + 2

//�����ļ����״̬
#define  RET_UPGRADE_FINISH		0
#define  RET_UPGRADE_FAILED		-1
#define  RET_UPGRADE_ERROR		2

//�ö��õ�
#define SET_TOP		1
#define SET_DOWN	0

//�豸����������
#define CMD_MIN_DEV_CONFIG	0
#define CMD_DEC_CFG_PROTOCOL						CMD_MIN_DEV_CONFIG + 0		//PTZ����Э��
#define CMD_DEC_CFG_ALARM_LINK_SWITCH				CMD_MIN_DEV_CONFIG + 1		//���������л�
#define CMD_DEC_CFG_CREATE_VVO						CMD_MIN_DEV_CONFIG + 2		//����ƴ�����ͨ��VVO
#define CMD_DEC_CFG_SPLIT_SCREEN					CMD_MIN_DEV_CONFIG + 3		//�Զ��廭��ָʽ
#define CMD_DEC_CFG_CHANN_STATE						CMD_MIN_DEV_CONFIG + 4		//��ȡ����������ͨ����״̬
#define CMD_DEC_CFG_DISP_VONUM						CMD_MIN_DEV_CONFIG + 5		//��������豸��ʾ������
#define CMD_DEC_CFG_CHANN_NUM						CMD_MIN_DEV_CONFIG + 6		//��ȡ����������ͨ����������ͨ����
#define CMD_DEC_CFG_ALARM_SCHEDULE					CMD_MIN_DEV_CONFIG + 7		//�������ܷ�����������ģ��
#define CMD_DEC_CFG_ALARM_LINK						CMD_MIN_DEV_CONFIG + 8		//�������ܷ�������
#define CMD_DEC_CFG_ALARM_NOTIFY					CMD_MIN_DEV_CONFIG + 9		//���;���
#define CMD_DEC_CFG_ALARM_IN_OUT					CMD_MIN_DEV_CONFIG + 10		//���ñ����������
#define CMD_DEC_CFG_SCHEDULE_ENABLE					CMD_MIN_DEV_CONFIG + 11		//�������ܷ�������ʹ��
#define CMD_DEC_CFG_VGA_SIZE						CMD_MIN_DEV_CONFIG + 12		//��ȡVGA��С
#define CMD_DEC_CFG_SIP_VIDEO_CHANNEL				CMD_MIN_DEV_CONFIG + 13		//��ȡSIP��ز���
#define CMD_DEC_CFG_VIDEO_PARAM						CMD_MIN_DEV_CONFIG + 14		//��ȡ��Ƶ����
#define CMD_DEC_CFG_SYSTEM_TIME						CMD_MIN_DEV_CONFIG + 15		//����ϵͳʱ��
#define CMD_DEC_CFG_DEV_INFO						CMD_MIN_DEV_CONFIG + 16		//��ȡ�豸��Ϣ	
#define CMD_DEC_CFG_TIMEZONE						CMD_MIN_DEV_CONFIG + 17		//ʱ��
#define CMD_DEC_CFG_CHANNEL_REGINFO					CMD_MIN_DEV_CONFIG + 18		//ͨ��ע����Ϣ
#define CMD_DEC_CFG_SCREEN_DISPLAY					CMD_MIN_DEV_CONFIG + 19		//������ʾ/����
#define CMD_DEC_CFG_SCREEN_CHANGEAREA				CMD_MIN_DEV_CONFIG + 20		//�����Զ����С/����
#define CMD_DEC_CFG_GET_ABILITY_LEVEL				CMD_MIN_DEV_CONFIG + 21		//get function ability level
#define CMD_DEC_CFG_FLOAT_WINDOW					CMD_MIN_DEV_CONFIG + 22		//����
#define CMD_DEC_CFG_SAVE_PLAN						CMD_MIN_DEV_CONFIG + 23		//����Ԥ��
#define CMD_DEC_CFG_APPLY_PLAN						CMD_MIN_DEV_CONFIG + 24		//Ӧ��Ԥ��
#define CMD_DEC_CFG_PLANALIAS						CMD_MIN_DEV_CONFIG + 25		//Ԥ������
#define CMD_DEC_CFG_BASE_OFFSET						CMD_MIN_DEV_CONFIG + 26		//��ʼ���
#define CMD_DEC_CFG_LOGOPARAM						CMD_MIN_DEV_CONFIG + 27		//logo
#define CMD_DEC_CFG_DECOSD							CMD_MIN_DEV_CONFIG + 28		//OSD���Ӳ���
#define CMD_DEC_CFG_PICNUM							CMD_MIN_DEV_CONFIG + 29		//��������
#define CMD_DEC_CFG_WINDOW_SEQUENCE					CMD_MIN_DEV_CONFIG + 30		//���ڴ���
#define CMD_DEC_CFG_REGSERVER						CMD_MIN_DEV_CONFIG + 31		//
#define CMD_DEC_CFG_PUPARAM							CMD_MIN_DEV_CONFIG + 32		//
#define CMD_DEC_CFG_DZ_INFO							CMD_MIN_DEV_CONFIG + 33		//
#define CMD_DEC_CFG_SELECT_PIC						CMD_MIN_DEV_CONFIG + 34		//
#define CMD_DEC_CFG_CHANNEL_REGINFO_EX				CMD_MIN_DEV_CONFIG + 35		//
#define CMD_DEC_CFG_SIP_VIDEO_CHANNEL_EX			CMD_MIN_DEV_CONFIG + 36		//
#define CMD_DEC_CFG_DEVCOMMONNAME					CMD_MIN_DEV_CONFIG + 37		//ͨ������
#define CMD_DEC_CFG_EXPORT_CONFIG					CMD_MIN_DEV_CONFIG + 38	    // export config
#define CMD_DEC_CFG_SHOW_OFFLINE_CHAN				CMD_MIN_DEV_CONFIG + 39	    // �Ƿ���ʾ������ͨ��
#define CMD_DEC_CFG_PLATFORM_LIST					CMD_MIN_DEV_CONFIG + 40		//ƽ̨�б�
#define CMD_DEC_CFG_COM_PARAM						CMD_MIN_DEV_CONFIG + 41	
#define CMD_DEC_CFG_SINGLEPIC						CMD_MIN_DEV_CONFIG + 42		//˫���Ŵ�/��С����
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


#define MAX_PROTOCOL_NUM				128		//DEC���֧��128��Э��
#define MAX_PROTOCOL_NAME_LEN32			32		//�豸֧�ֵ�Э�����Ƶ���󳤶�
typedef struct
{
	int		m_iCount;					//Э�����
	char 	m_cProtocol[MAX_PROTOCOL_NUM][MAX_PROTOCOL_NAME_LEN32];		
							//��Э�����ƣ����֧��128��Э�飬ÿ��Э�������31�ֽڣ�
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
//���������л�
typedef struct tagAlarmLinkSwitch
{
	int  iBufSize;		//�ṹ���С
	int  iAlarmType;	//��������	"0����Ƶ��ʧ��1���˿ڱ�����2���ƶ���⣻3����Ƶ�ڵ���4�����ܷ�����5����Ƶ��ʧ��6,��ʪ�ȱ�����
						//128֮�������ʹ�ã�ģʽ=128 + iType����һ�б�ʾ����ֵ��
						//128����Ƶ��ʧ��
						//129������˿ڱ�����
						//130���ƶ���⣻
						//131��159��Ԥ��
						//160�����ض˿ڱ�����"					
	int  iPortNo;					//�˿ں�	������������Ϊ���ض˿ڱ���ʱ�����ֶ���Ч					
	int  iChannelNo;				//ͨ����						
	int  iPos;						//�����						
	char cSerName[DEC_LEN_32];		//ǰ���豸����						
	char cSerIP[DEC_LEN_16];		//ǰ���豸IP��ַ						
	char cSerProxy[DEC_LEN_16];		//ǰ���豸����IP						
	int  iSerChan;					//ǰ���豸ͨ����	serTypeΪ4ʱ��serChanΪ����ͨ����serTypeΪ5ʱ��serChanΪ��������ͨ����					
	int  iSerStreamNo;				//��������	0,��������1��������					
	int  iSerNetmode;				//����������ģʽ	1��TCP��2��UDP��3���ಥ					
	int	 iUseddns;					//�Ƿ�ʹ��ddns	0��IP��1��������3������ģʽ					
	int  iSerPort;					//�������˿ں�						
	char cUserName[DEC_LEN_32];		//ǰ���豸��¼�û���						
	char cPassword[DEC_LEN_32];		//ǰ���豸��¼����						
	int  iHoldTime;					//ͣ��ʱ��	10-999					
	char cEncrypt[DEC_LEN_32];		//ǰ���豸��Ƶ��������						
	int  iSerType;					//ǰ���豸����	0��Tiandy��1��Onvif��2��push��	3��rtsp��4���������ڲ�����ͨ����5����������ͨ��1000��ʼ�ǳ��ҶԽ���������  1001��LG�� 1002������
	char cRtspUrl[DEC_LEN_256];
	int  iLinkSwitchEnable;
}AlarmLinkSwitch, *pAlarmLinkSwitch;

//����ָ������ʹ����ֱȱ�ʾ
typedef struct tagScreenPara
{
	int iBufSize;		//�ṹ���С
	int iX;				//��ʼ�������
	int	iY;				//��ʼ��������
	int	iWidth;			//�����
	int	iHeight;		//�����
}ScreenPara, *pScreenPara;

//����ƴ�����ͨ��VVO
typedef struct tagInputChannelParam
{
	int		   iMode;
	ScreenPara tSplitScreenPara;
}InputChannelParam;

typedef struct tagCreateVVOInfo
{
	int					iBufSize;									//�ṹ���С
	int					iVVOChannelNo;								//ƴ��ͨ����
	int					iRows;										//ƴ��������
	int					iCols;										//ƴ��������
	int					iInputChannel[DEC_MAX_PHYSICAL_CHANNEL_NUM];	//�������󶨵����ͨ���ţ�û������0x7fffffff��ʾ
	InputChannelParam	tInputChannelParam[DEC_MAX_PHYSICAL_CHANNEL_NUM];//ͨ������
	int					iScreenType;
	ScreenPara          tEffectiveArea;
}CreateVVOInfo, *pCreateVVOInfo;


//�Զ��廭��ָʽ
typedef struct tagSplitScreen
{
	int			iBufSize;										//�ṹ���С
	int			iVVOChannelNo;									//ƴ��ͨ����
	int			iPicNum;										//��������16��
	ScreenPara	tSplitScreenPara[DEC_MAX_PICTURE_NUM];			//�������
}SplitScreen, *pSplitScreen;

//����������ͨ����״̬
#define CHANEEL_ON_LINE		1
#define CHANNEL_OFF_LINE	0

#define DECODE_CHANNEL		0
#define ENCODE_CHANNEL		1
typedef struct tagLocalChannelState
{
	int			iBufSize;				//����������ṹ���С
	int			iChannelNo;				//���������ͨ����
	int			iState;					//�������������״̬, 0-������  1-����  2-������
	int			iType;					//���������ͨ������, 0-����ͨ�� 1-����ͨ��
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

//ʱ���
typedef struct tagAlarmScheduleParam
{
	int				iBuffSize;
	int				iChannelNo;	//��ʶ�������ܷ�����ͨ��
	int				iAlarmType;	//128����Ƶ��ʧ��129������˿ڱ�����130���ƶ���⣻131��134��Ԥ����135�����ض˿ڱ�����
	int				iWeekday;	//�����յ���������0-6��
	int				iParam1;	//iType=4ʱ��ʾ����ID
	int				iParam2;	//iType= 4ʱ��ʾ�¼����ͣ�0�������� 1��˫���� 2���ܽ��� 3���ǻ� 4��ͣ�� 5������
								//6����������Ա�ܶ� 7�������� 8�������� 9������ʶ�� 10����Ƶ���
								//11:���ܸ��� 12������ͳ�� 13����Ⱥ�ۼ� 14����ڼ�⣩
	DEC_SCHEDTIME	timeSeg[DEC_MAX_DAYS][DEC_MAX_TIMESEGMENT];		//	ʱ���
	void*			pvReserved;									
}AlarmScheduleParam, *PAlarmScheduleParam;

typedef struct tagAlarmLink
{
	int	iBuffSize;
	int iChannelNo;			//ȡֵ��Χ���豸���Ͷ���
	int	iAlarmType;			//128����Ƶ��ʧ��129������˿ڱ�����130���ƶ���⣻131��134��Ԥ����135�����ض˿ڱ�����136����Դ����
	int	iAlarmTypeParam;	//ȡֵ��iAlarmType����������iAlarmTypeΪ���ܷ�������iAlarmTypeParam��ʾiRuleID
	char cReserved[DEC_LEN_32];
	int	iLinkType;			//��������,0������������ʾ��1��������Ļ��ʾ��2����������˿ڣ�3������¼��4������PTZ��5������ץ�ģ�
	int	iLinkParam1;	//��������,ȡֵ��iLinkType������iLinkType=0,1ʱ��iParam1��ʾʹ��iEnable��0����ʹ�ܣ�1��ʹ�ܡ�
	//iLinkType=2,3,5,6ʱ��iParam1��ʾ��λʹ��iEnableByBits�������λ�����λÿһλ��ʾһ������Ƶͨ��/����˿ڵ�ʹ�ܡ�
	//iLinkType=4ʱ��iParam1��ʾ��������ͨ����iLinkChannel,ȡֵ��Χ���豸���Ͷ�����
	//iParam2��ʾ������������iLinkType��0����������ͨ��PTZ��1Ԥ��λ��2�켣��3·����iParam3��ʾPTZ��iNo��
	//����iParam2�����ͷֱ��ʾԤ��λ�ţ��켣�ź�·����
	int	iLinkParam2;	//��������
	int	iLinkParam3;	//��������
}AlarmLink, *PAlarmLink;

#define DEC_MAX_PORT_NUM        64
#define MAX_ALARM_IN_OUT_TYPE	4

//���ñ��������Ǹߵ�ƽ�������ǵ͵�ƽ����
#define DEC_ALARM_IN_LHP	0
//���ñ�������Ǹߵ�ƽ�������ǵ͵�ƽ����
#define DEC_ALARM_OUT_LHP	1
//���ñ�������˿�ʹ��
#define DEC_ALARM_IN_PORT	2
//���ñ�������˿�ʹ��
#define DEC_ALARM_OUT_PORT	3

typedef struct tagAlarmInAndOut
{
	int	iBuffSize;
	int	iType;		//0����������ߵ͵�ƽ���ã�1����������ߵ͵�ƽ���ã�2����������˿�ʹ�ܣ�3����������˿�ʹ��
	int	iPortNo;	//��������˿ں�
	int	iPara1;		//��iTypeȡֵ�й�
	int	iPara2;		//����
}AlarmInAndOut, *PAlarmInAndOut;

typedef struct tagAlarmNotify
{
	int	iBuffSize;
	int	iAlarmType;	//128����Ƶ��ʧ��129������˿ڱ�����130���ƶ���⣻131��134��Ԥ����135�����ض˿ڱ�����
	int	iChannelNo;	//ͨ����,iType = 160����ʾ���������ض˿ں�
	int	iState;		//1��������0������
}AlarmNotify, *pAlarmNotify;

typedef struct tagScheduleEnable
{
	int	iBuffSize;
	int iChannelNo;
	int	iAlarmType;		//128����Ƶ��ʧ��129������˿ڱ�����130���ƶ���⣻131��134��Ԥ����135�����ض˿ڱ�����136 ��Դ�澯
	int	iEnable;		//�Ƿ�ʹ��,0����ʹ�� 1��ʹ��
	int	iParam1;		//����1
	int	iParam2;		//����2
	int	iParam3;		//����3
}ScheduleEnable, *pScheduleEnable;

typedef struct tagVGASize
{
	int	iBuffSize;
	int iChannelNo;
	int iVGASize;
}VGASize, *pVGASize;

//�������Զ�������
#define CMD_AUTOTEST_MIN                    0
#define	CMD_AUTOTEST_SETMACADDR				(CMD_AUTOTEST_MIN+1)	  //����MAC��ַ��
#define	CMD_AUTOTEST_LAN					(CMD_AUTOTEST_MIN+2)	  //��������
#define	CMD_AUTOTEST_USB					(CMD_AUTOTEST_MIN+10)     //����USB�ڣ�
#define	CMD_AUTOTEST_ALARMIN				(CMD_AUTOTEST_MIN+12)	  //���Ա�������˿ڣ�
#define	CMD_AUTOTEST_ALARMOUT				(CMD_AUTOTEST_MIN+13)	  //���Ա�������˿ڣ�
#define	CMD_AUTOTEST_RTC			   		(CMD_AUTOTEST_MIN+15)	  //����ʱ��оƬ��
#define	CMD_AUTOTEST_BACKUPSYSTEM			(CMD_AUTOTEST_MIN+20)	  //����ϵͳ��
#define CMD_AUTOTEST_VERIFYTIME				(CMD_AUTOTEST_MIN+26)	  //ʱ��У����
#define AUTOTEST_SWITCHLAN					(CMD_AUTOTEST_MIN+38)     //�л�UI���ԣ�
#define CMD_AUTOTEST_FPGASTATUS             (CMD_AUTOTEST_MIN+39)	  //����FPGA�Ĺ���״̬
#define CMD_AUTOTEST_DOUBLEPOWER_ALARM      (CMD_AUTOTEST_MIN+40)	  //����˫��Դ����
#define CMD_AUTOTEST_UPDATEVOCHIP	        (CMD_AUTOTEST_MIN+41)	  //������Ƶ���оƬ����
#define CMD_AUTOTEST_POWERDOWNDETECTIVE     (CMD_AUTOTEST_MIN+42)	  //�ػ������ź����
#define CMD_AUTOTEST_CLUSTER				(CMD_AUTOTEST_MIN+99)	  //S5��������Ⱥ������ɼ�Ⱥ��
#define	CMD_AUTOTEST_END					(CMD_AUTOTEST_MIN+100)	  //���Խ�����
#define	CMD_AUTOTEST_MAX					(CMD_AUTOTEST_MIN+101)
//������
#define PRODUC_TIANDY                        0
#define PRODUC_OEM                           1
//UI����
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
#define DEC_SUB_FUNC_REBOOTDOCKING	22 //�����Խӳ���
#define DEC_SUB_FUNC_REMOTESWICHNET	23 //Զ�̿����������
#define DEC_SUB_FUNC_ENCODECHN_PROOFADJUST	   24 //����ͨ��ƫɫƫ������
#define DEC_SUB_FUNC_LOCALINPUTCHN_PROOFADJUST 25 //��������ͨ��ƫɫƫ������
#define	DEC_SUB_FUNC_LED_SMALLPITCH			   26 //�Ƿ�֧��LEDС���	0��������1��֧�֣� 2����֧��
#define	DEC_SUB_FUNC_SMOOTH_MODE			   27 //0����֧�֣�����������ģʽ��֧�ֱ�������ͨ����������
#define DEC_MAX_SUB_FUNC_TYPE				   28 
typedef struct _tagDecAbilityLevel
{
	int		iSize;
	int		iMainFuncType;			//main function type
	int		iSubFuncType;			//sub function type
	char	cParam[DEC_LEN_256];	//Capability Description
} DecAbilityLevel, *pDecAbilityLevel;

#define DEC_INVALID_CHANNEL 0x7FFFFFFF

#define DEC_NO_CHANNEL_PARAM -1  //ͨ���޹�
#define DEC_NO_PIC_PARAM     -1	//�����޹�

/***************************************************************

Prameter(in) ��	_lID����¼ID
				_uiMsg����Ϣ��
				_iChannel��ͨ����
				_iPos�����ں�
				_pvParam������
				_iParamSize��������С���ֽڣ�
				_pvUserData���û����� DEC_ClientLogonEx����
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
	int			iChannelNo;		//	ͨ����
	int			iLogType;		//	��־����
	int			iLanguage;		//	��������
	NVS_FILE_TIME	struStartTime;		//	��ʼʱ��
	NVS_FILE_TIME	struStopTime;		//	����ʱ��
	int			iPageSize;		//	ҳ��С
	int			iPageNo;		//	ҳ���
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
	int    iEncChnNo;	//����ͨ��ͨ���ţ����뿨ʹ��
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
	int iSeekDevice; // SEEK_DEVICE_IPC��SEEK_DEVICE_NVD
	int iSeekType; //SEEK_TYPE_IP��SEEK_TYPE_DNS��SEEK_TYPE_DMS
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
	int iSeekType;//SEEK_TYPE_IP��SEEK_TYPE_DNS��SEEK_TYPE_DMS
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
	int iSequence; // WINDOW_SEQUENCE_TOP ��WINDOW_SEQUENCE_BOTTOM
}WindowSequence, *PWindowSequence;

typedef struct tagChannelLogoParam
{
	int    iSize;
	TLOGOPARAM tLogoParam;
}ChannelLogoParam, *pChannelLogoParam;

#define ALIGN_ABOUT_BWLOW_MIDDLE  0		//���¾���
#define ALIGN_ABOUT				  1		//�϶���
#define ALIGN_BWLOW				  2		//�¶���

#define ALIGN_LEFT_RIGHT_MIDDLE	  0		//���Ҷ���
#define ALIGN_LEFT				  1		//�����
#define ALIGN_RIGHT				  2		//�Ҷ���

#define SHOW_STATIC               0		//��̬��ʾ
#define SHOW_DYNAMIC_LEFT_RIGHT   1		//�����ƶ���̬��ʾ
#define SHOW_DYNAMIC_ABOUT_BWLOW  2		//�����ƶ���̬��ʾ
#define SHOW_STATIC_LINE_DISPLAY  3     //��̬������ʾ

typedef struct tagDecOsd
{
	int   iSize;
	char  cOsd[LEN_256];
	int   iColor;
	int   iBackColor;
	int   iDiaphaneity;//0-100
	int   iFontSize; // 1-5
	ScreenPara tArea;
	int   iAboutBelowAlign;//ALIGN_ABOUT_BWLOW_MIDDLE��ALIGN_ABOUT��ALIGN_BWLOW
	int   iLeftRightAlign;//ALIGN_LEFT_RIGHT_MIDDLE��ALIGN_LEFT��ALIGN_RIGHT
	int	  iDynamic;//SHOW_STATIC��SHOW_DYNAMIC_LEFT_RIGHT��SHOW_DYNAMIC_ABOUT_BWLOW��SHOW_STATIC_LINE_DISPLAY
	int	  iEnbale;
	int   iSwitchTime;//��ʾ�л�ʱ��
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
	int  iSaveCfg;         //�������ñ�־��0���棬 1������
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

#define MAX_DEC_CHANNEL_TYPE	4 //0-��Ƶ���ͨ�� 1-��������ͨ�� 2-�������ͨ�� 3-��������ͨ��
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
	int	 iEnable; //1----��ʾ  0:----����ʾ
} ShowOfflineChan, *pShowOfflineChan;

typedef struct tagComParam
{
	int				iSize;
	int				iCom;
	unsigned char	ucType;			    //485Э��ID��0��͸��ͨ����1:Pelco-P��...
	unsigned char	ucAddress;			//485��ַ��ȡֵ��Χ��0-255��
	int				iBaudrate;		    //485������2400��4800��9600
	unsigned char	ucDatabit;   		//485����λ��Ĭ��Ϊ8
	unsigned char	ucStopbit;			//485ֹͣλ��Ĭ��Ϊ1
	unsigned char	ucCheckbit; 		//485У��λ�����ֿ�ѡ��0����У�飻1����У�飻2��żУ�飻
	unsigned char	ucFlowcontrol;		//485���أ�Ĭ��Ϊ�����أ�������Ч
	int				iComType;			//0��RS485��1��RS232�̶��ӣ�2��RS232����
} ComParam, *PComParam;

typedef struct tagStopViewPara
{
	int        iSize;
	int        iChannel;
	int        iPos;
	int        iSaveLastFrame;	//�Ƿ������һ֡��0-������(Ĭ��ֵ)��1-����
	int        iSaveCfg;		//�Ƿ񱣴����ã�0-���棻1=�����棻�������ֶ�Ĭ�ϱ���
}StopViewPara, *pStopViewPara;

//CMD
#define DEC_COMMAND_MIN							0
#define DEC_COMMAND_PTZ_CONTROL			(DEC_COMMAND_MIN + 1)		//�豸����Э��
#define DEC_COMMAND_PROOF_ADJUST		(DEC_COMMAND_MIN + 2)		//У�����뿨ƫ��ƫɫ
#define DEC_COMMAND_LOGWRITE			(DEC_COMMAND_MIN + 3)		//cgi report log
#define DEC_COMMAND_USERNUM				(DEC_COMMAND_MIN + 4)		//��ȡ�û���Ŀ
#define DEC_COMMAND_USERINFO			(DEC_COMMAND_MIN + 5)		//��ȡ�û���Ϣ
#define DEC_COMMAND_GETUSERNUM			(DEC_COMMAND_MIN + 6)		//��ȡ�û�����
#define DEC_COMMAND_GETUSERINFO			(DEC_COMMAND_MIN + 7)		//��ȡ�û���������
#define DEC_COMMAND_GETLASTERROR		(DEC_COMMAND_MIN + 8)		//��ȡ�豸������Ϣ
#define DEC_COMMAND_PICSNAP				(DEC_COMMAND_MIN + 9)		//�·�ץ������
#define DEC_COMMAND_GETPICFILENAME		(DEC_COMMAND_MIN + 10)		//��ȡץ��ͼƬ���ļ���
#define DEC_COMMAND_SCREENCTLSET		(DEC_COMMAND_MIN + 11)      //���ؿ��������·�
#define DEC_COMMAND_REBOOTTRADE			(DEC_COMMAND_MIN + 12)      //�����������
#define DEC_COMMAND_GETUDISK_VIDEOLISTS	(DEC_COMMAND_MIN + 13)      //��ȡU����Ƶ����
#define DEC_COMMAND_VIDEO_PLAYSET		(DEC_COMMAND_MIN + 14)      //�����·�ͨ������Ĳ��ź�ֹͣ
#define DEC_COMMAND_DEL_PICSNAP			(DEC_COMMAND_MIN + 15)		//ɾ��ץ������
#define DEC_COMMAND_SOUNDCTRL_RESULT	(DEC_COMMAND_MIN + 16)		//��ȡ����״̬
#define DEC_COMMAND_TALKSERVER_RESULT	(DEC_COMMAND_MIN + 17)		//��ȡ�Խ�״̬
#define DEC_COMMAND_MAX					(DEC_COMMAND_MIN + 18)

typedef struct tagPtzControlPara
{
	int  iSize;
	int	 iActionType;	//�ϡ��¡����ҡ��䱶��Ԥ��λ��
	int  iControlType;	//0����ͨ��̨���ƣ�1��������̨e-PTZ.ȱʡΪ0
	int  iParam1;		//�����������������������ĺ���Ҳ��һ����ˮƽ�ٶȻ�Ԥ��λ�š�
	int  iParam2;		//��ֱ�ٶȡ�
} PtzControlPara, *pPtzControlPara;


#define		PROOFADJUST_OPERTYPE_MANU		1		//1-manu�� 2-auto 
#define		PROOFADJUST_OPERTYPE_AUTO		2		
#define		PROOFADJUST_OUT_DEV_HDMI		1		//out dev 1-HDMI�� 2-VGA
#define		PROOFADJUST_OUT_DEV_VGA		    2		
#define    	PROOFADJUST_TYPE_RESO			1       //Type��1-Video Resolution  2-Video Color
#define    	PROOFADJUST_TYPE_COLOR			2
#define    	PROOFADJUST_CHANNELTYPE_ENCODE     0       //Channel Type��0-Encode  1-LocalInput
#define    	PROOFADJUST_CHANNELTYPE_LOCALINPUT 1
typedef struct tagProofAdjust
{
	int  iSize;
	int	 iOperateMethod;	//1-�ֶ��� 2-�Զ�
	int  iVoId;				//1-HDMI�� 2-VGA
	int  iType;				//1-��Ƶ�ֱ���  2-��Ƶ��ɫ
	int  iChannelType;      //ͨ�������޸��ֶΣ�ͨ������Ϊ����ͨ��,0-����ͨ��1-��������ͨ��
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
	int iNetId;			//�������
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
#define DEC_LASTERROR_ALARMLINK		0x13000		//��������������ǰ�����������������޸�����
#define DEC_LASTERROR_MODIFY_IP		0x13100		//ip��ַ�޸�ʧ��

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
	int		iState;	//������״̬:0-�ǵ�����ģʽ, 1-������
} DecSinglePic, *pDecSinglePic;

typedef struct tagDecScreenRegion
{
	int		iSize;
	int		iEnable;		//ʹ��
	int		iXPos;			//��ʼ������
	int		iYPos;			//��ʼ������
	int		iPixelWidth;	//���ؿ��
	int		iPixelHeight;	//���ظ߶�
} DecScreenRegion, *pDecScreenRegion;

typedef struct tagDecScreenBasicPara
{
	int		iSize;	
	int		iBrightness;	//���ȣ�0��100
	int		iContrast;		//�Աȶȣ�0��100
	int		iSaturation;	//���Ͷȣ�0��100
	int		iHue;			//ɫ�ȣ�0��100
} DecScreenBasicPara, *pDecScreenBasicPara;

#define SCREEN_OUTPUT_MODE_HDMI				0
#define SCREEN_OUTPUT_MODE_DVI				1
#define SCREEN_OUTPUT_MODE_ADAPTATION		2
typedef struct tagDecScreenOutputMode
{
	int		iSize;	
	int		iMode;		//0:HDMI 1:DVI 2:����Ӧ
} DecScreenOutputMode, *pDecScreenOutputMode;

typedef struct tagDecPicLevelRelation
{
	int		iSize;
	int		iPicCount;
	int		iLevelArray[DEC_MAX_WINDOW_TOTAL_NUM];	//�㼶��ϵ:�±�Ϊ����ţ��㼶��ϵ����ײ㿪ʼΪ0���������μ�1��
			//����iLevelArray[0]�ǵ�0����Ĳ㼶��iLevelArray[1]�ǵ�1����Ĳ㼶����iLevelArray[N]�ǵ�N����Ĳ㼶
} DecPicLevelRelation, *pDecPicLevelRelation;

typedef struct tagDecSyncLoopCtrl
{
	int		iSize;	
	int		iLoopEnable;	//0��ֹͣ�л��� 1����ʼ�л�
} DecSyncLoopCtrl, *pDecSyncLoopCtrl;

typedef struct tagDecSyncLoopTime
{
	int		iSize;	
	int		iHoldTime;		//ͣ��ʱ�䣺10-999
} DecSyncLoopTime, *pDecSyncLoopTime;

typedef struct tagDecEncodePara
{
	int		iSize;	
	int		iWidth;			//��Ƶ��
	int		iHeight;		//��Ƶ��
	int		iFrameRate;		//֡�ʣ���Чֵ��1��25��50��60
	int		iBitRate;		//���ʣ���λΪKBytes/s����1024kbps������
} DecEncodePara, *pDecEncodePara;

typedef struct tagDecHttpPort
{
	int		iSize;	
	int		iPort;			//HTTP�˿ں�
	int		iHttpsPort;		//HTTPS�˿ں�
	int		iRtsPort;		//�˿ں� 
	int		iSchedulePort;	//���ڶ˿ں�
} DecHttpPort, *pDecHttpPort;

typedef struct tagDecShowIcon
{
	int     iSize;
	int     iIconType;		//ͼ������,1-655350-Ԥ��,1-����׶˺�ɫ������˸
	int     iDisp;			//�Ƿ���ʾ,0 ����ʾ 1 ��ʾ
} DecShowIcon, *pDecShowIcon;

typedef struct tagDecAlarmEffectLight
{
	int     iSize;
	int     iEnable;				//��Чʹ�ܣ�1--ʹ�ܣ�0--�ر�					
	int		iDuration;				//��Ч����ʱ�� 	��λ����					
	int		iColor;					//��ɫ��32λ��ȡ��24λ��ʾ��ɫrgb, �������ַ�ʽbgr��[((DWORD)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))]				
	int		iFlashtime;				//��˸���,	��λ������					
} DecAlarmEffectLight, *pDecAlarmEffectLight;

#define MAX_EFFECTREGION_POINT_COUNT		8
typedef struct tagDecAlarmEffectRegion
{
	int     iSize;
	int     iEnable;				//��Чʹ�ܣ�1--ʹ�ܣ�0--�ر�					
	int		iDuration;				//��Ч����ʱ�� 	��λ����
	int		iWidth;					//�߿���
	int		iColor;					//��ɫ��32λ��ȡ��24λ��ʾ��ɫrgb, �������ַ�ʽbgr��[((DWORD)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))]					
	int		iPointCount;			//���򶥵��������8����					
	POINT	tPoints[MAX_EFFECTREGION_POINT_COUNT];	//������, �������Ƶ�ֱ��ʵ���ֱ�����			
} DecAlarmEffectRegion, *pDecAlarmEffectRegion;

typedef struct tagDecAlarmEffectText
{
	int     iSize;
	int     iEnable;				//��Чʹ�ܣ�1--ʹ�ܣ�0--�ر�					
	int		iDuration;				//��Ч����ʱ�� 	��λ����
	int		iFontSize;				//�����С����Χ1-5������5������������С
	int		iColor;					//��ɫ��32λ��ȡ��24λ��ʾ��ɫrgb, �������ַ�ʽbgr��[((DWORD)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))]					
	char	cText[LEN_64];			//�ı�����	���64�ֽ�					
	int		iTextAlign;				//���뷽ʽ��0--�û��Զ���, 1--���Ͻ�, 2--���½�, 3--���Ͻ�, 4--���½�, 5����					
	POINT	tPoint;					//�ַ��������Ͻ����꣬�������Ƶ�ֱ��ʵ���ֱ�����					
	int		iTextWidth;				//�ı������ȣ�ʵ�ʷֱ���					
	int		iTextHeight;			//�ı�����߶ȣ�ʵ�ʷֱ���					
	int		iLeft;					//��߾࣬iTextAlignΪ1, 2ʱ��Ч					
	int		iTop;					//�ϱ߾࣬iTextAlignΪ1, 3ʱ��Ч					
	int		iRight;					//�ұ߾࣬iTextAlignΪ3, 4ʱ��Ч					
	int		iBottom;				//�±߾࣬iTextAlignΪ2, 4ʱ��Ч						
} DecAlarmEffectText, *pDecAlarmEffectText;

#define DEC_MAX_PLAN_LOOP_ITEM_NUM MAX_PLAN_COUNT
typedef struct tagPlanLoopItem
{
	int     iIndex;		//�л����к�
	int		iPlanNo;	//Ԥ�����
	int		iHoldTime;	//ͣ��ʱ�� 30-9999
}PlanLoopItem,*pPlanLoopItem;

typedef struct tagPlanLoopList
{
	int     iCount;		//�л��б���Ŀ
	PlanLoopItem tPlanLoopItem[DEC_MAX_PLAN_LOOP_ITEM_NUM];
}PlanLoopList,*pPlanLoopList;

typedef struct tagPlanLoop
{
	int     iEnable;	//ʹ��
	int     iCount;     //��Ŀ
	int		iIndex;	    //��ǰ�л����к�
	int		iPlanNo;	//��ǰԤ�����
}PlanLoop,*pPlanLoop;

typedef struct tagPlanLoopItemDel
{
	int		iIndex;	    //Ҫɾ�����л����к�
}PlanLoopItemDel,*pPlanLoopItemDel;

//�豸���繤��ģʽ
typedef	struct tagLanParamWorkMode
{
	int				iWorkMode;				//����ģʽ0�����ݣ�1����ַ
	int				iMainLanNo;				//���������0��Lan1��1��Lan2
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
	int serType;			//0��Tiandy��1��Onvif��2��push����3��rtsp��4���������ڲ�����ͨ����5����������ͨ��
							//1000��ʼ�ǳ��ҶԽ���������  1001��LG�� 1002�����£�
}PicSnap,*pPicSnap;

typedef struct tagPicSnapResult
{
	int     iRet;				//0���ɹ���1��ʧ�ܣ�
	int     iSnapID;			//ץ��ID
}PicSnapResult, *pPicSnapResult;

typedef struct tagPicSnapID
{
	int     iSnapID;//ץ��ID
}PicSnapID, *pPicSnapID;

typedef struct tagPicSnapFileName
{
	int     iSnapID;
	int     iState;					//0���ɹ���1��ʧ�ܣ�2��ץ����
	char    cPicFileName[LEN_256];	//ץ��ͼƬ�ļ���
}PicSnapFileName, *pPicSnapFileName;

typedef struct tagScreenCtlProtocols
{
	int		iCount;													//Э�����
	char 	cProtocol[MAX_PROTOCOL_NUM][MAX_PROTOCOL_NAME_LEN32+1];	//��Э�����ƣ����֧��128��Э�飬ÿ��Э�������32�ֽڣ�	
}ScreenCtlProtocols, *pScreenCtlProtocols;

typedef struct tagScreenCtlProtocol
{
	int     iScreenNo;		//ƴ�����ı�ţ�ָ������IE����ʾ����Ļ���			
	int     iAddressNo;		//��Ļ��ַ��0x11~0xAA				
	int     iComNo;			//���ڱ��
	char 	cProtocol[MAX_PROTOCOL_NAME_LEN32+1];
}ScreenCtlProtocol, *pScreenCtlProtocol;

typedef struct tagScreenCtl
{
	int     iScreenNo;		//ƴ�����ı�ţ�ָ������IE����ʾ����Ļ���			
	int     iActionType;	//�������1�����ػ���2��ƴ����ѡ��3���Աȶȣ�4�����ȣ�5��ɫ���Ͷȣ�6��������
	int     iParam;			//��������������1�����ػ�����0-�ػ���1-������2��ƴ����ѡ������ʱ0-AV��
							//1-S-VIDEO��2-VGA��3-DVI��4-HDMI��3���Ķȿ��ƣ��Աȶȡ����ȡ�ɫ���Ͷȡ������ȣ�����0-���٣�����1-����
}ScreenCtl, *pScreenCtl;

typedef struct tagScreenCtlResult
{
	int     iScreenNo;					
	int     iActionType;	
	int     iParam; 
	int     iResult;		//0��Ԥ����1���ɹ���2��ʧ��
}ScreenCtlResult, *pScreenCtlResult;

typedef struct tagRebootTradeResult
{
	int       iResult;		//0��Ԥ����1���ɹ���2��ʧ��
}RebootTradeResult,*pRebootTradeResult;

#define DEC_MAX_VIDEOLIST_SIZE			100

typedef struct tagUDiskVideoList
{
	int      iCount;
	char 	 cVideoName[DEC_MAX_VIDEOLIST_SIZE][LEN_128];	//��Ƶ����	
}UDiskVideoList, *pUDiskVideoList;

typedef struct tagUDiskCurVideo
{
	int		iCurVideoState;		//��Ƶ״̬
	char 	cVideoName[LEN_128];	//��Ƶ����	
}UDiskCurVideo, *pUDiskCurVideo;


#define DEC_MAX_UDISK_CHANNEL_VIDEO		20
typedef struct tagUDiskSetChannelVideo
{
	int		iVideoNum; //��Ƶ����
	char 	cVideoName[DEC_MAX_UDISK_CHANNEL_VIDEO][LEN_128];	//��Ƶ����	
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
	int		iPlayMode; //����ģʽ������Ƶ�������ͣ�1��ѭ������ 2��˳�򲥷�  
}VideoPlayMode, *pVideoPlayMode;

typedef struct tagVideoPlayCmd
{
	int		iPlayCmd;  //��������0��ֹͣ���� 1����ʼ����  
}VideoPlayCmd, *pVideoPlayCmd;

typedef struct tagVideoPlayCmdResult
{
	int			 iPlayCmd;
	int			 iResult;      //0��Ԥ����1���ɹ���2��ʧ��
}VideoPlayCmdResult, *pVideoPlayCmdResult;

typedef struct tagPlanLoopStatus
{
	int			 iStatus;//0����ʼ�л� 1��ֹͣ�л�
}PlanLoopStatus, *pPlanLoopStatus;

typedef struct tagLoopParam
{
	int			 iType;	//0,��Ƶ�л��б�1�� Ԥ���л��б�
}LoopParam, *pLoopParam;

typedef struct tagSoundCtrlResult
{
	int iAudioStatus;//0:AUDIO_STATUS_CLOSE	1:AUDIO_STATUS_OPEN	-1: AUDIO_STATUS_FAILD
	int iFailReason;//0��Ԥ����1���Խ��Ѵ򿪣��뱾����ƵԤ�����ڻ���
}SoundCtrlResult;

typedef struct tagTalkServResult
{
	int iTalkStatus;//0:TALK_STATUS_CLOSE	1:TALK_STATUS_OPEN	-1:TALK_STATUS_FAILD      
	int iFailReason;//0��Ԥ����1��������ƵԤ���Ѵ򿪣���Խ����ڻ���
}TalkServResult;

typedef struct tagHDModeOutChannel
{
	int iOutChnNum;							  //����ģʽ�£�֧�����ͨ������
	int iOutChnn[DEC_MAX_CHANNEL_TOTAL_NUM];  //���ͨ����
}HDModeOutChannel;

typedef struct tagSmoothMode
{
	int iEnable;							     //����ģʽʹ��
	int iLocalInNum;							 //����ͨ������
	int iEnableChnn[DEC_MAX_ENCODE_CHANNEL_NUM]; //ʹ�ܱ�������ͨ��
}SmoothMode;

#endif
