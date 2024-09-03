package com.gshx.camera.tiandi;

/* OSD叠加Logo属性定义==================================== */
public class TLogoParam {
    //是否叠加Logo
    public boolean m_enable;  
    //叠加Logo横坐标         
    public int           m_iPosX; 
    //叠加Logo纵坐标           
    public int           m_iPosY;
    //透明度(0~100)，100为完全不透明            
    public byte m_iAlpha;           
    //背景色，RGB格式(0x00000000~0x00ffffff)
    public int           m_iTransparentColor;
}
