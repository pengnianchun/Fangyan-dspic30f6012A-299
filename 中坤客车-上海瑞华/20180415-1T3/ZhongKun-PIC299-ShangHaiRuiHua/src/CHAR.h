#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "FONT.h"

/*******************************主界面显示*************************************/

//单体电压
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//单体温度
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};
//电机转速
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//电机转矩
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//电机温度
__prog__ const unsigned char * DJWD[] = {BMP_DJ, BMP_Wendu, 0};
//电机控制器
__prog__ const unsigned char * DJKZQ[] = {BMP_DJ, BMP_KZQ, 0};

/******************************************************************************/

/********************************菜单选项**************************************/
//仪表系统信息
__prog__ const unsigned char * IC_SYSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//电池信息
__prog__ const unsigned char * Battery_SYSTEM[] = {BMP_Battery, BMP_Message, 0};
//电机系统信息
__prog__ const unsigned char * MOTO_SYSTEM[] = {BMP_MOTO, BMP_STSTEM, BMP_Message, 0};
//气泵系统信息
__prog__ const unsigned char * AIR_SYSTEM[] = {BMP_DMQ, BMP_STSTEM, BMP_Message, 0};
//油泵系统信息
__prog__ const unsigned char * OIL_SYSTEM[] = {BMP_DMY, BMP_STSTEM, BMP_Message, 0};
//电池管理系统信息
__prog__ const unsigned char * BMS_SYSTEM[] = {BMP_Battery, BMP_Manage, BMP_STSTEM, BMP_Message, 0};
//空调系统信息
//__prog__ const unsigned char * OIL_STSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//高压系统信息
__prog__ const unsigned char * HV_SYSTEM[] = {BMP_Gaoya, BMP_STSTEM, BMP_Message, 0};
//轮胎系统信息
__prog__ const unsigned char * Luntai_SYSTEM[] = {BMP_TAIYA, BMP_STSTEM, BMP_Message, 0};

/******************************************************************************/

/*******************************子菜单*****************************************/
__prog__ const unsigned char * GD[] = {BMP_Guo, BMP_Di, 0};

/******************************************************************************/

/******************************CAN报警*****************************************/
//电池电压低
__prog__ const unsigned char * DCDYD[] = {BMP_DC, BMP_DY, BMP_Di, 0};
//SOC
__prog__ const unsigned char * SOC[] = {BMP_s, BMP_o, BMP_c, 0};
//CAN
__prog__ const unsigned char * CHAR_CAN[] = {BMP_c, BMP_a, BMP_n, 0};
//充电通讯异常
//__prog__ const unsigned char * CDTXYC[] = {BMP_Chongdian, BMP_Tongxun, BMP_Yichang, 0};
//前部模块离线
__prog__ const unsigned char * QBMKLX[] = {BMP_Qianbu, BMP_Mokuai, BMP_Lixian, 0};
//顶部模块离线
__prog__ const unsigned char * DBMKLX[] = {BMP_Dingbu, BMP_Mokuai, BMP_Lixian, 0};
//后部模块离线
__prog__ const unsigned char * HBMKLX[] = {BMP_Houbu, BMP_Mokuai, BMP_Lixian, 0};
//BMS
__prog__ const unsigned char * BMS[] = {BMP_b, BMP_m,BMP_s, 0};

/******************************************************************************/

/*******************************仪表开关量采集*********************************/

//前雾灯开关
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//后雾灯开关
__prog__ const unsigned char * HWDKG[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//小灯开关
__prog__ const unsigned char * XDKG[] = {BMP_Xiao, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//前门开开关
__prog__ const unsigned char * QMKKG[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//前门关开关
__prog__ const unsigned char * QMGKG[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//中门开开关
__prog__ const unsigned char * ZMKKG[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//中门关开关
__prog__ const unsigned char * ZMGKG[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//前门应急阀报警
//远光灯开关
__prog__ const unsigned char * YGDKG[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//近光灯开关
__prog__ const unsigned char * JGDKG[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ASR
//__prog__ const unsigned char * ASR[] = {BMP_a, BMP_s, BMP_r, BMP_Guzhang, 0};
//ABS
//__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s, BMP_Guzhang, 0};
__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s, Bmp_JCe, 0};//ABS检测
//START档
//__prog__ const unsigned char * START[] = {BMP_s, BMP_t, BMP_a, BMP_r, BMP_t, BMP_Dang, 0};
//危险报警信号
__prog__ const unsigned char * WXBJKG[] = {BMP_Weixian, BMP_Baojing, BMP_IC_Kaiguan, 0};
//驻车制动开关
__prog__ const unsigned char * ZCZDKG[] = {BMP_Zhuche, BMP_Zhidong, BMP_IC_Kaiguan, 0};
//门铃开关
__prog__ const unsigned char * MLKG[] = {BMP_Men, BMP_Ling, BMP_IC_Kaiguan, 0};
//SERVICE
//__prog__ const unsigned char * SERVICE[] = {BMP_s, BMP_e, BMP_r,BMP_v, BMP_i, BMP_c,BMP_e, BMP_Qingqiu, 0};

/******************************************************************************/


/******************************前模块开关状态**********************************/
//地址选择
__prog__ const unsigned char * DZXZ[] = {BMP_Dizhi, BMP_Xuanze,0};
//版本号
__prog__ const unsigned char * BBH[] = {BMP_Banben, BMP_Hao,0};

/******************************************************************************/

/******************************前模块输出状态**********************************/
//左前雾灯输出
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//右前雾灯输出
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//前门开输出
__prog__ const unsigned char * QMKSC[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Output, 0};
//中门开输出
__prog__ const unsigned char * ZMKSC[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Output, 0};
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

/******************************************************************************/

/******************************顶模块输出状态**********************************/
//前门开电磁阀
__prog__ const unsigned char * QMKDCF[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Diancifa, 0};
//前门关电磁阀
__prog__ const unsigned char * QMGDCF[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_Diancifa, 0};
//中门开电磁阀
__prog__ const unsigned char * ZMKDCF[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Diancifa, 0};
//中门关电磁阀
__prog__ const unsigned char * ZMGDCF[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_Diancifa, 0};
//前门应急阀
__prog__ const unsigned char * QMYJF[] = {BMP_IC_Qian, BMP_Men, BMP_Yingjifa,0};
//中门应急阀
__prog__ const unsigned char * ZMYJF[] = {BMP_Zhong, BMP_Men, BMP_Yingjifa,0};
/******************************************************************************/

/******************************顶模块开关状态**********************************/
//前门开信号
__prog__ const unsigned char * QMKXH[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Xinhao, 0};
//中门开信号
__prog__ const unsigned char * ZMKXH[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Xinhao, 0};

/******************************************************************************/

/******************************后模块输出状态**********************************/


/******************************************************************************/

/******************************后模块开关状态**********************************/
//左前摩擦片
__prog__ const unsigned char * ZQMCQ[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_Mocapian, 0};
//右前摩擦片
__prog__ const unsigned char * YQMCQ[] = {BMP_IC_You, BMP_IC_Qian, BMP_Mocapian,0};


/******************************************************************************/
/*********************************电机状态*************************************/
//电机直流电压
__prog__ const unsigned char * DJZLDY[] = {BMP_DJ, BMP_Zhiliu, BMP_DY,0};
//电机直流电流
__prog__ const unsigned char * DJZLDL[] = {BMP_DJ, BMP_Zhiliu, BMP_DL,0};
//电机工作状态
__prog__ const unsigned char * DJGZZT[] = {BMP_DJ, BMP_Gongzuo, BMP_Zhuangtai,0};
//整车故障代码
__prog__ const unsigned char * ZCGZDM[] = {BMP_Zhengche, BMP_Guzhang, BMP_Code,0};
/******************************************************************************/

/******************************后模块开关状态**********************************/


__prog__ const unsigned char * ZLBJ[] = {BMP_Zhongli, BMP_Baojing,0};//重力报警
__prog__ const unsigned char * DSBJ[] = {Bmp_DSu, BMP_Baojing,0};//低速报警

__prog__ const unsigned char * Bmp_AQDai[] = {Bmp_An, Bmp_Quan, Bmp_Dai, 0};//安全带
__prog__ const unsigned char * Bmp_AQMen[] = {Bmp_An, Bmp_Quan, BMP_Men, 0};//安全门
__prog__ const unsigned char * Bmp_JYDZ[] = {BMP_Jueyuan, Bmp_Dian, BMP_Zu, 0};//绝缘电阻
__prog__ const unsigned char * Bmp_KR[] = {BMP_k, BMP_Omu, 0};//KR

/******************************电池故障报警*********************************/
__prog__ const unsigned char * Bmp_Display_bj_13[] = {BMP_Yuchong, BMP_Chaoshi,0};//预充超时
__prog__ const unsigned char * Bmp_Display_bj_14[] = {BMP_Xu, BMP_DC,BMP_DY,BMP_Di,0};//蓄电池电压低
__prog__ const unsigned char * Bmp_Display_bj_15[] = {BMP_s,  BMP_o,BMP_c,BMP_Guzhang,0};//SOC故障
__prog__ const unsigned char * Bmp_Display_bj_16[] = {BMP_Dan,BMP_Ti, BMP_DY,BMP_Guzhang,0};//单体电压故障
__prog__ const unsigned char * Bmp_Display_bj_17[] = {BMP_Zong, BMP_DY,BMP_Guzhang,0};//总电压故障
__prog__ const unsigned char * Bmp_Display_bj_18[] = {BMP_Wendu, BMP_Guzhang,0};//温度故障
__prog__ const unsigned char * Bmp_Display_bj_19[] = {BMP_s, BMP_o,BMP_c,BMP_Guo,BMP_Di,0};//SOC过低
__prog__ const unsigned char * Bmp_Display_bj_20[] = {BMP_Jueyuan, BMP_Guzhang,0};//绝缘故障
__prog__ const unsigned char * Bmp_Display_bj_21[] = {BMP_DL, BMP_Guzhang,0};//电流故障
__prog__ const unsigned char * Bmp_Display_bj_22[] = {BMP_DC, BMP_Junheng,BMP_Guzhang,0};//电池均衡故障
__prog__ const unsigned char * Bmp_Display_bj_23[] = {BMP_Husuo, BMP_Baojing,0};//互锁报警
__prog__ const unsigned char * Bmp_Display_bj_24[] = {Bmp_please,Bmp_ZQue,Bmp_TChe,0};//请正确停车
__prog__ const unsigned char * Bmp_Display_bj_25[] = {Bmp_An, Bmp_Quan, Bmp_Dai,Bmp_WXi,0};//安全带未系
__prog__ const unsigned char * Bmp_Display_bj_26[] = {Bmp_An, Bmp_Quan, BMP_Men, BMP_Kai, 0};//安全门开

/******************************************************************************/

#endif	/* APP_CHAR_H */

