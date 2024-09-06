package com.gshx.camera.tiandi;

/* 视频通道参数定义====================================== */
public class TNVSItem {
    public TNVSItem() {
        rtspUrl = "";
        serverName = "";
        serverIP = "";
        serverProxy = "";
        username = "";
        password = "";
        deviceType = "";
    }
    // RTSP地址 byte 88
    public String rtspUrl;
    // 服务器名称(暂时保留) byte 33
    public String serverName;
    // 服务器地址，可以是IP地址，也可以是域名 byte 33
    public String serverIP;
    // 服务器上级代理 byte 16
    public String serverProxy;
    // 服务器通道
    public int serverChan;
    // 服务器码流类型
    public int serverStream;
    // 传输协议1：TCP，2：UDP，3：多播；
    public int serverNetmode;
    // 通过解析服务器连接
    public int useddns;
    // 服务器端口
    public int serverPort;
    // 当前是否在连接状态，1：连接状态，0：未连接状态(暂时不使用)
    public int isView;
    // 用户名 byte 20
    public String username;
    // 密码 byte 20
    public String password;
    // 保持时间，取值范围：5――1000秒
    public int holdtime;
    // 设备控制协议（需要翻译到的协议） byte 16
    public String deviceType;
    // NVS设备地址（取值范围：0-255）
    public int iAddress;
}
