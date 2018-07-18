#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "FONT.h"

/*******************************主界面显示*************************************/
//单体电压
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//单体温度
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};
//ECAS
__prog__ const unsigned char * ECAS[] = {BMP_e, BMP_c, BMP_a, BMP_s, 0};

/******************************************************************************/

/********************************菜单选项**************************************/
//仪表系统信息
__prog__ const unsigned char * IC_STSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//电池信息
__prog__ const unsigned char * Battery_STSTEM[] = {BMP_Battery, BMP_Message, 0};
//电机系统信息
__prog__ const unsigned char * MOTO_STSTEM[] = {BMP_MOTO, BMP_STSTEM, BMP_Message, 0};
//气泵系统信息
__prog__ const unsigned char * AIR_STSTEM[] = {BMP_DMQ, BMP_STSTEM, BMP_Message, 0};
//油泵系统信息
__prog__ const unsigned char * OIL_STSTEM[] = {BMP_DMY, BMP_STSTEM, BMP_Message, 0};
//电池管理系统信息
__prog__ const unsigned char * BMS_STSTEM[] = {BMP_Battery, BMP_Manage, BMP_STSTEM, BMP_Message, 0};
//空调系统信息
__prog__ const unsigned char * Air_STSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};

/******************************************************************************/

/******************************CAN报警*****************************************/
//电池电压低
__prog__ const unsigned char * DCDYD[] = {BMP_DC, BMP_DY, BMP_Di, 0};
//SOC
__prog__ const unsigned char * SOC[] = {BMP_s, BMP_o, BMP_c, 0};
//CAN
__prog__ const unsigned char * CHAR_CAN[] = {BMP_c, BMP_a, BMP_n, 0};
//充电通讯异常
__prog__ const unsigned char * CDTXYC[] = {BMP_Chongdian, BMP_Tongxun, BMP_Yichang, 0};
//前部模块离线
__prog__ const unsigned char * QBMKLX[] = {BMP_Qianbu, BMP_Mokuai, BMP_Lixian, 0};
//顶部模块离线
__prog__ const unsigned char * DBMKLX[] = {BMP_Dingbu, BMP_Mokuai, BMP_Lixian, 0};
//后部模块离线
__prog__ const unsigned char * HBMKLX[] = {BMP_Houbu, BMP_Mokuai, BMP_Lixian, 0};
//空调系统故障
__prog__ const unsigned char * KTXTGZ[] = {BMP_Kongtiao, BMP_System, BMP_Guzhang, 0};

/******************************************************************************/

/*******************************开关量采集*************************************/
//安全带
__prog__ const unsigned char * AQD[] = {BMP_Anquan, BMP_Dai, 0};
//前雾灯开关
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//后雾灯开关
__prog__ const unsigned char * HWDKG[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//小灯开关
__prog__ const unsigned char * XDKG[] = {BMP_Xiao, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//前门开状态
__prog__ const unsigned char * QMKZT[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Zhuangtai, 0};
//中门开状态
__prog__ const unsigned char * ZMKZT[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Zhuangtai, 0};
//前门开开关
__prog__ const unsigned char * QMKKG[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//中门开开关
__prog__ const unsigned char * ZMKKG[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//前门关开关
__prog__ const unsigned char * QMGKG[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//中门关开关
__prog__ const unsigned char * ZMGKG[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//前门应急阀报警
//远光灯开关
__prog__ const unsigned char * YGDKG[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//近光灯开关
__prog__ const unsigned char * JGDKG[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ASR
__prog__ const unsigned char * ASR[] = {BMP_a, BMP_s, BMP_r,BMP_Guzhang, 0};
//ABS
__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s,BMP_Guzhang, 0};
//危险报警信号
__prog__ const unsigned char * WXBJKG[] = {BMP_Weixian, BMP_Baojing, BMP_IC_Kaiguan, 0};
//驻车制动开关
__prog__ const unsigned char * ZCZDKG[] = {BMP_Zhuche, BMP_Zhidong, BMP_IC_Kaiguan, 0};
//门铃开关
__prog__ const unsigned char * MLKG[] = {BMP_Men, BMP_Ling, BMP_IC_Kaiguan, 0};
//水位报警
__prog__ const unsigned char * SWBJ[] = {BMP_Shuiwei, BMP_Baojing, 0};
//ECAS提升
__prog__ const unsigned char * ECASTS[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Tisheng, 0};
//ECAS下降
__prog__ const unsigned char * ECASXJ[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Xiajiang, 0};
//ECAS复位
__prog__ const unsigned char * ECASFW[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Fuwei, 0};
//ECAS侧跪
__prog__ const unsigned char * ECASCG[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Cegui, 0};
//重力感应开关
__prog__ const unsigned char * ZLGYKG[] = {BMP_Zhongliganying, BMP_IC_Kaiguan, 0};
//START档
__prog__ const unsigned char * START[] = {BMP_s,BMP_t,BMP_a,BMP_r,BMP_t, BMP_Dang, 0};
//ACC开关
__prog__ const unsigned char * ACCKG[] = {BMP_a,BMP_c,BMP_c,BMP_IC_Kaiguan, 0};
//ON档
__prog__ const unsigned char * ONHX[] = {BMP_o,BMP_n,BMP_Huanxing, 0};
/******************************************************************************/

/******************************模块输出状态************************************/

//左前雾灯输出
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//右前雾灯输出
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//前门开输出
__prog__ const unsigned char * QMKSC[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Output, 0};
//中门开输出
__prog__ const unsigned char * ZMKSC[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Output, 0};
//前门关输出
__prog__ const unsigned char * QMGSC[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_Output, 0};
//中门关输出
__prog__ const unsigned char * ZMGSC[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_Output, 0};
//左远光灯输出
__prog__ const unsigned char * ZYGDSC[] = {BMP_IC_Zuo, BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//右远光灯输出
__prog__ const unsigned char * YYGDSC[] = {BMP_IC_You, BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//左近光灯输出
__prog__ const unsigned char * ZJGDSC[] = {BMP_IC_Zuo, BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//右近光灯输出
__prog__ const unsigned char * YJGDSC[] = {BMP_IC_You, BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//后雾灯输出
__prog__ const unsigned char * HWDSC[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, 0};
//日行灯
__prog__ const unsigned char * RXD[] = {BMP_Rixing, BMP_IC_Deng, 0};
//位置灯
__prog__ const unsigned char * WZD[] = {BMP_Weizhi, BMP_IC_Deng, 0};
//制动灯
__prog__ const unsigned char * ZDD[] = {BMP_Zhidong, BMP_IC_Deng, 0};
//雨刮电机电源
__prog__ const unsigned char * YGDJDY[] = {BMP_IC_Yugua, BMP_DJ, BMP_Dianyuan, 0};
//投币机电源
__prog__ const unsigned char * TBJDY[] = {BMP_Toubiji, BMP_Dianyuan, 0};
//集中润滑电源
__prog__ const unsigned char * JZRHDY[] = {BMP_Jizhongrunhua, BMP_Dianyuan, 0};
//前门踏步
__prog__ const unsigned char * QMTB[] = {BMP_IC_Qian, BMP_Men,BMP_Tabu, 0};
//前门踏步
__prog__ const unsigned char * ZMTB[] = {BMP_Zhong, BMP_Men,BMP_Tabu, 0};
//主继电器
__prog__ const unsigned char * ZJDQ[] = {BMP_Zhu, BMP_Jidianqi, 0};
/******************************************************************************/
/******************************************************************************/
//电机转矩
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//电机转速
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//母线电压
__prog__ const unsigned char * MXDY[] = {BMP_Muxian, BMP_DY, 0};
//母线电流
__prog__ const unsigned char * MXDL[] = {BMP_Muxian, BMP_DL, 0};
//电机当前转矩
__prog__ const unsigned char * DJDQZJ[] = {BMP_DJ,BMP_Dangqian, BMP_Zhuanju, 0};
//电机当前转速
__prog__ const unsigned char * DJDQZS[] = {BMP_DJ,BMP_Dangqian, BMP_Zhuansu, 0};
//电机温度
__prog__ const unsigned char * DJWD[] = {BMP_DJ,BMP_Wendu, 0};
//控制器温度
__prog__ const unsigned char * KZQWD[] = {BMP_KZQ,BMP_Wendu, 0};
//油门踏板开度
__prog__ const unsigned char * YMTBKD[] = {BMP_Youmen,BMP_Taban,BMP_Kaidu, 0};
//制动踏板开度
__prog__ const unsigned char * ZDTBKD[] = {BMP_Zhidong,BMP_Taban,BMP_Kaidu, 0};
//故障代码
__prog__ const unsigned char * GZDM[] = {BMP_Guzhang, BMP_Code, 0};
//故障等级
__prog__ const unsigned char * GZDJ[] = {BMP_Guzhang, BMP_Dengji, 0};
//充放电状态
__prog__ const unsigned char * CFDZT[] = {BMP_Chong, BMP_Fangdian, BMP_DC, BMP_Zhuangtai, 0};
//空调故障代码
__prog__ const unsigned char * KTGZDM[] = {BMP_Kongtiao, BMP_Guzhang, BMP_Code, 0};
//空调电机状态
__prog__ const unsigned char * KTDJZT[] = {BMP_Kongtiao, BMP_DJ, BMP_Zhuangtai, 0};
//空调工作状态
__prog__ const unsigned char * KTGZZT[] = {BMP_Kongtiao, BMP_Gongzuo, BMP_Zhuangtai, 0};
//车外实际
__prog__ const unsigned char * CWSJ[] = {BMP_Chesu, BMP_Wai, BMP_Shiji, 0};
//车内实际
__prog__ const unsigned char * CNSJ[] = {BMP_Chesu, BMP_Nei, BMP_Shiji, 0};
//设定温度
__prog__ const unsigned char * SDWD[] = {BMP_Sheding, BMP_Wendu,0};
//实际功率
__prog__ const unsigned char * SJGL[] = {BMP_Shiji, BMP_Gonglv,0};
/******************************************************************************/
#endif	/* APP_CHAR_H */