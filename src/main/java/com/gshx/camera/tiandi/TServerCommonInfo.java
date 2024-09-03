package com.gshx.camera.tiandi;

public class TServerCommonInfo {
    public String cServerIp;
    public int iServerPort;
    public int iServerChannelNo;
    public int iServerStreamNo;
    //0:TCP, 1:UDP, 2:MUT
    public int iServerNetmode;
    public int iHoldTime;
    public String cServerUserName;
    public String cServerPassword;
    public String cServerPtzProtocol;
    public int iServerPtzAddress;
    //保存配置标志：0保存， 1不保存
    public int iSaveCfg;     
}
