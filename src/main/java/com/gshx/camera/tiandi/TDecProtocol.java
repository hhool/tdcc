package com.gshx.camera.tiandi;

import java.util.List;

public class TDecProtocol {
    // 服务器支持的协议类型数
    public int iCount;
    // 各协议名称，最多支持128个协议，每条协议名称最长15字节；
    public List<String> cProtocol;
}
