#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "APP_FONT.h"

/*******************************主界面显示*************************************/

//单体电压
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//单体温度
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};

/******************************************************************************/
//电机控制器
__prog__ const unsigned char * DJKZQ[] = {BMP_DJ, BMP_KZQ, 0};
//电机转速
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//电机电流
__prog__ const unsigned char * DJDL[] = {BMP_DJ, BMP_DL, 0};
//电机温度
__prog__ const unsigned char * DJWD[] = {BMP_DJ, BMP_Wendu, 0};
//电机转矩
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//电机电压
__prog__ const unsigned char * DJDY[] = {BMP_DJ, BMP_DY, 0};
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
__prog__ const unsigned char * HV_SYSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};

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
//ABSXH
__prog__ const unsigned char * ABSXH[] = {BMP_a, BMP_b,BMP_s, BMP_Xinhao,0};
//QMWG
__prog__ const unsigned char * QMWG[] = {BMP_IC_Qian, BMP_Men, BMP_Weiguan, 0};
//ZMWG
__prog__ const unsigned char * ZMWG[] = {BMP_Zhong, BMP_Men, BMP_Weiguan, 0};
//HCMWG
__prog__ const unsigned char * HCMWG[] = {BMP_IC_Hou, BMP_Cangmen, BMP_Men, BMP_Weiguan, 0};
//车辆已锁
__prog__ const unsigned char * CLYS[] = {BMP_Chesu, BMP_Liang, BMP_Yi, BMP_Suo, 0};
//车辆未锁
__prog__ const unsigned char * CLWS[] = {BMP_Chesu, BMP_Liang, BMP_Wei, BMP_Suo, 0};
//锁车状态
__prog__ const unsigned char * SCZT[] = {BMP_Suo, BMP_Chesu, BMP_Zhuangtai, 0};
//已锁
__prog__ const unsigned char * YS[] = {BMP_Yi, BMP_Suo,0};
//未锁
__prog__ const unsigned char * WS[] = {BMP_Wei, BMP_Suo,0};
//低档
__prog__ const unsigned char * DD[] = {BMP_Di, BMP_Dang,0};
//高档
__prog__ const unsigned char * GD[] = {BMP_Gao, BMP_Dang,0};
//母线电压报警
__prog__ const unsigned char * MXDYBJ[] = {BMP_Muxian, BMP_DY, BMP_Baojing, 0};
//电池电量过低
__prog__ const unsigned char * DCDLGD[] = {BMP_DC, BMP_Dianliang, BMP_Guodi, 0};
//电池电量不足请停车
__prog__ const unsigned char * DCDLBZQTC[] = {BMP_DC, BMP_Dianliang, BMP_Buzu, BMP_Qingtingche, 0};
/******************************************************************************/

/******************************电机系统信息*****************************************/
//车辆当前状态
__prog__ const unsigned char * ZCZT[] = {BMP_Zhengche, BMP_Zhuangtai,0};
//电机系统状态
__prog__ const unsigned char * DJXTZT[] = {BMP_DJ,BMP_System, BMP_Zhuangtai,0};
//系统互锁状态
__prog__ const unsigned char * XTHSZT[] = {BMP_System,BMP_Husuo, BMP_Zhuangtai,0};
//主正接触器
__prog__ const unsigned char * ZZJCQ[] = {BMP_Zhu,BMP_Zheng, BMP_Jiechuqi,0};
//电机转速信号
__prog__ const unsigned char * DJZSXH[] = {BMP_DJ, BMP_Zhuansu, BMP_Xinhao,0};
//电机转矩信号
__prog__ const unsigned char * DJZZXH[] = {BMP_DJ, BMP_Zhuanju, BMP_Xinhao,0};
//电机母线电压信号状态
__prog__ const unsigned char * DJMXDYXHZT[] = {BMP_DJ, BMP_Muxian, BMP_DY,BMP_Xinhao, BMP_Zhuangtai,0};
//电机母线电流信号状态
__prog__ const unsigned char * DJMXDLXHZT[] = {BMP_DJ, BMP_Muxian, BMP_DL,BMP_Xinhao, BMP_Zhuangtai,0};
//电池接触器
__prog__ const unsigned char * DCJCQ[] = {BMP_DC, BMP_Jiechuqi,0};
//制动踏板状态
__prog__ const unsigned char * ZDTBZT[] = {BMP_Zhidong, BMP_Taban, BMP_Zhuangtai,0};
//加速踏板状态
__prog__ const unsigned char * JSTBZT[] = {BMP_Youmen, BMP_Taban, BMP_Zhuangtai,0};
//电机温度信号状态
__prog__ const unsigned char * DJWDXHZT[] = {BMP_DJ, BMP_Wendu, BMP_Xinhao,BMP_Zhuangtai,0};
//电机控制器温度信号
__prog__ const unsigned char * DJKZQWDXHZT[] = {BMP_DJ,BMP_KZQ, BMP_Wendu, BMP_Xinhao,0};
//预充接触器
__prog__ const unsigned char * YCJCQ[] = {BMP_Yuchong, BMP_Jiechuqi,0};
//除霜接触器
__prog__ const unsigned char * CSJCQ[] = {BMP_Chushuang, BMP_Jiechuqi,0};
//保险状态
__prog__ const unsigned char * BXZT[] = {BMP_Baoxian, BMP_Zhuangtai,0};
/******************************************************************************/
/*******************************开关量采集*************************************/
//喇叭开关
__prog__ const unsigned char * LBKG[] = {BMP_Laba, BMP_IC_Kaiguan, 0};
//前雾灯开关
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//后雾灯开关
__prog__ const unsigned char * HWDKG[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//小灯开关
__prog__ const unsigned char * XDKG[] = {BMP_Xiao, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//前门开信号
__prog__ const unsigned char * QMKXH[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Xinhao, 0};
//中门开信号
__prog__ const unsigned char * ZMKXH[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Xinhao, 0};
//应急阀报警
__prog__ const unsigned char * YJFBJ[] = {BMP_Yingjifa, BMP_Baojing,0};
//远光灯开关
__prog__ const unsigned char * YGDKG[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//近光灯开关
__prog__ const unsigned char * JGDKG[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ASR
__prog__ const unsigned char * ASR[] = {BMP_a, BMP_s, BMP_r, BMP_Guzhang, 0};
//ABS
__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s, BMP_Guzhang, 0};
//START档
__prog__ const unsigned char * START[] = {BMP_s, BMP_t, BMP_a, BMP_r, BMP_t, BMP_Dang, 0};
//危险报警信号
__prog__ const unsigned char * WXBJKG[] = {BMP_Weixian, BMP_Baojing, BMP_IC_Kaiguan, 0};
//驻车制动开关
__prog__ const unsigned char * ZCZDKG[] = {BMP_Zhuche, BMP_Zhidong, BMP_IC_Kaiguan, 0};
//门铃开关
__prog__ const unsigned char * MLKG[] = {BMP_Men, BMP_Ling, BMP_IC_Kaiguan, 0};
//SERVICE
__prog__ const unsigned char * SERVICE[] = {BMP_s, BMP_e, BMP_r,BMP_v, BMP_i, BMP_c,BMP_e, BMP_Qingqiu, 0};
//烟雾报警开关
__prog__ const unsigned char * YWBJKG[] = {BMP_Yanwu, BMP_Baojing, BMP_IC_Kaiguan, 0};
//安全带报警
__prog__ const unsigned char * AQDBJ[] = {BMP_Anquandai, BMP_Baojing,0};
//广告灯开关
__prog__ const unsigned char * GGKG[] = {BMP_Guanggao, BMP_IC_Kaiguan,0};
//重力报警
__prog__ const unsigned char * ZLBJ[] = {BMP_Zhongli, BMP_Baojing,0};
//集中润滑
__prog__ const unsigned char * JZRH[] = {BMP_Jizhong, BMP_Runhua, 0};
/******************************************************************************/

/******************************模块输出状态************************************/
//门泵电源
__prog__ const unsigned char * MBDY[] = {BMP_Men, BMP_Dianyuan, 0};
//制动电源
__prog__ const unsigned char * ZDDY[] = {BMP_Zhidong, BMP_Dianyuan, 0};
//门铃电源
__prog__ const unsigned char * MLDY[] = {BMP_Men, BMP_Ling, BMP_Dianyuan, 0};
//仓温电源
__prog__ const unsigned char * CWDY[] = {BMP_Cangmen, BMP_Wendu, BMP_Dianyuan, 0};
//电视电源
__prog__ const unsigned char * DSDY[] = {BMP_Dianshi, BMP_Dianyuan, 0};
//空调电源
__prog__ const unsigned char * KTDY[] = {BMP_Kongtiao, BMP_Dianyuan, 0};
//前雾灯输出
__prog__ const unsigned char * QWDSC[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//左前雾灯输出
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//右前雾灯输出
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
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
//倒车输出
__prog__ const unsigned char * DCSC[] = {BMP_Daoche, BMP_Output, 0};
//广告输出
__prog__ const unsigned char * GGSC[] = {BMP_Guanggao, BMP_Output,0};
//前门灯输出
__prog__ const unsigned char * QMDSC[] = {BMP_IC_Qian, BMP_Men, BMP_IC_Deng, BMP_Output, 0};
//中门灯输出
__prog__ const unsigned char * ZMDSC[] = {BMP_Zhong, BMP_Men, BMP_IC_Deng, BMP_Output, 0};
//喇叭输出
__prog__ const unsigned char * LBSC[] = {BMP_Laba,  BMP_Output, 0};
//制动灯输出
__prog__ const unsigned char * ZDDSC[] = {BMP_Zhidong,  BMP_Output, 0};
//风扇电源
__prog__ const unsigned char * FSDY[] = {BMP_Fengshan,  BMP_Dianyuan, 0};
//气压电源
__prog__ const unsigned char * QYDY[] = {BMP_Qiya,  BMP_Dianyuan, 0};
/******************************************************************************/
/******************************************************************************/
//动力电池
__prog__ const unsigned char * DLDC[] = {BMP_Dongli,BMP_DC,0};
//电池串联数量
__prog__ const unsigned char * DCCLSL[] = {BMP_DC,BMP_Chuanlian,BMP_Shuliang,0};
//电池并联数量
__prog__ const unsigned char * DCBLSL[] = {BMP_DC,BMP_Binglian,BMP_Shuliang,0};
//电池额定容量
__prog__ const unsigned char * DCEDRL[] = {BMP_DC,BMP_Eding,BMP_Rongliang,0};
//电池剩余容量
__prog__ const unsigned char * DCSYRL[] = {BMP_DC,BMP_Shengyu,BMP_Rongliang,0};
//电池报警等级
__prog__ const unsigned char * DCBJDJ[] = {BMP_DC,BMP_Baojing,BMP_Dengji,0};
//一级故障代码
__prog__ const unsigned char * YJGZDM[] = {BMP_Yiji,BMP_Guzhang,BMP_Code,0};
//二级故障代码
__prog__ const unsigned char * EJGZDM[] = {BMP_Erji,BMP_Guzhang,BMP_Code,0};
//三级故障代码
__prog__ const unsigned char * SJGZDM[] = {BMP_Sanji,BMP_Guzhang,BMP_Code,0};
//绝缘母线电压
__prog__ const unsigned char * JYMXDY[] = {BMP_Jueyuan,BMP_Muxian,BMP_DY,0};
//绝缘故障等级
__prog__ const unsigned char * JYGZDJ[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Dengji,0};
//绝缘故障状态
__prog__ const unsigned char * JYGZZT1[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Zhuangtai,0};
//绝缘工作状态
__prog__ const unsigned char * JYGZZT2[] = {BMP_Jueyuan,BMP_Gongzuo,BMP_Zhuangtai,0};
//火灾报警等级
__prog__ const unsigned char * HZBJDJ[] = {BMP_Huozai,BMP_Baojing,BMP_Dengji,0};
//火灾报警故障代码
__prog__ const unsigned char * HZBJGZDM[] = {BMP_Huozai,BMP_Baojing,BMP_Guzhang,BMP_Code,0};
/******************************************************************************/
#endif	/* APP_CHAR_H */

