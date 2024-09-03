package com.gshx.camera.tiandi;

public interface IDecNotify {
    /***************************************************************
    Prameter(in) ：	_lID：登录ID
                    _uiMsg：消息号
                    _iChannel：通道号
                    _iPos：窗口号
                    _pvParam：参数
                    _iParamSize：参数大小（字节）
                    _pvUserData：用户数据 DEC_ClientLogonEx传入
    ***************************************************************/
    void onMainNotify(long lID, int uiMsg, int iChannel, int iPos, Object pvParam, int iParamSize, Object pvUserData);
    void onParamChangeNotify(long lID, int uiMsg, int iChannel, int iPos, Object pParam, int iParamSize, Object lpUserData);
}
