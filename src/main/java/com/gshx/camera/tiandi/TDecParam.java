package com.gshx.camera.tiandi;

import java.util.List;

/*解码器参数定义=======================================*/

public class TDecParam  extends TDecParamBase{
    TDecParam(int type) {
     super(type);
    }
    ////////////////////////////////////////////////
    // for linux platform
    // 解码器IP地址
    public String ip;
    // 解码器子网掩码
    public String submask;
    // 解码器的网关地址
    public String gateway;
    // DNS地址
    public String dns;
    // 物理地址
    public List<String> mac_address;

    // 解析服务器IP地址
    public String ddnsIP;
    // 解析服务器用户名
    public String ddnsUser;
    // 解析服务器密码
    public String ddnsPassword;
    // 解析服务器端口
    public int ddnsPort;
    // 0:PAL；1:NTSC
    public int ispal;
    // 0:中文；1:英文
    public int language;
    // 485串口参数
    public TCom485[] com485;

    // 报警输出联动关系，&0x01:端口报警，&0x02:丢失报警，&0x04:移动报警，1表示联动输出，0表示不联动输出。
    public int alarm_out;
    // 报警输出模式：0：低电平触发；1：高电平触发
    public int alarm_mode;
    // 解码通道数，0-8
    public int channel;
    // 串口数，0-1
    public int com_num;
    // 每个通道的工作模式（1：单画面；4：四画面）
    public int[] chan_mode;
    // 每个通道的VGA分辨率，1（800*600 60Hz）、2（1024*768 60Hz）、3（1280*1024 60Hz），若为BNC通道，则该参数无效
    public int[] vga_size;
    ////////////////////////////////////////////////
    // for windows platform
    // TODO(hhool): Add windows platform fields here.
    
}
