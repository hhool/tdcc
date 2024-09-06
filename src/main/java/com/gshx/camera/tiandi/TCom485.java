package com.gshx.camera.tiandi;
/*com485通信定义=======================================*/

public class TCom485 {
    // 485协议ID，0：透明通道，1:Pelco-P，
    public int type;
    // 485地址（取值范围：0-255）
    public int address;
    // 485波特率2400，4800，9600
    public int baudrate;
    // 485数据位，默认为8
    public int databits;
    // 485停止位，默认为1
    public int stopbits;
    // 485校验位，四种可选，0：无校验；1：奇校验；2：偶校验；3：固定为1；4：固定为0
    public int checkbits;
    // 485流控，默认为无流控，设置无效
    public int flowcontrol;
}
