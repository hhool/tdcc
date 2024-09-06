package com.gshx.camera.tiandi;

public class TNVSItemEx {
    public TNVSItemEx() {
        stOldItem = new TNVSItem();
        cEncyptPWD = "";
        iDevPlatType = 0;
        cMultIP = "";
        iMultPort = 0;
        isavecfg = 0;
    }
    public TNVSItem   stOldItem;
    //加密密码 byte 16 + 1
    public String cEncyptPWD;
    //设备平台类型，0-普通，1-Onvif 2-push流 3-RTSP流
    public int iDevPlatType;
    //组播地址协议 byte 32 + 1
    public String cMultIP;
    //组播端口号
    public int iMultPort;
    //保存配置标志
    public int isavecfg;
}
