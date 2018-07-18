#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "APP_FONT.h"

/*******************************主界面显示*************************************/

//单体电压
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//单体温度
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};
//最高电压
__prog__ const unsigned char * ZGDY[] = {BMP_Zui, BMP_Gao, BMP_DY, 0};
//最低电压
__prog__ const unsigned char * ZDDY[] = {BMP_Zui, BMP_Di, BMP_DY, 0};
//最高温度
__prog__ const unsigned char * ZGWD[] = {BMP_Zui, BMP_Gao, BMP_Wendu, 0};
//平均温度
__prog__ const unsigned char * PJWD[] = {BMP_Pingjun, BMP_Wendu, 0};
//电容电压
__prog__ const unsigned char * DRDY[] = {BMP_DC, BMP_Rongliang,BMP_DY, 0};
//SOE
__prog__ const unsigned char * SOE[] = {BMP_s, BMP_o, BMP_e, 0};
//电机输入电压
__prog__ const unsigned char * DJSRDY[] = {BMP_DJ, BMP_Input, BMP_DY, 0};
//电机输入电流
__prog__ const unsigned char * DJSRDL[] = {BMP_DJ, BMP_Input, BMP_DL, 0};
//电机转速
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//电机转矩
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//电机控制器
__prog__ const unsigned char * DJKZQ[] = {BMP_DJ, BMP_KZQ, 0};
//电机温度
__prog__ const unsigned char * DJWD[] = {BMP_DJ, BMP_Wendu, 0};
//电池电流
__prog__ const unsigned char * DCDL[] = {BMP_DC, BMP_DL, 0};
//输出转速
__prog__ const unsigned char * SCZS[] = {BMP_Output, BMP_Zhuansu, 0};
//EV信号
__prog__ const unsigned char * EV[] = {BMP_e, BMP_v,BMP_Xinhao, 0};
//制动踏板
__prog__ const unsigned char * ZDTB[] = {BMP_Zhidong, BMP_Taban, 0};
//油门踏板
__prog__ const unsigned char * YMTB[] = {BMP_Youmen, BMP_Taban, 0};
//输出电流
__prog__ const unsigned char * SCDY[] = {BMP_Output, BMP_DY, 0};
//输出电压
__prog__ const unsigned char * SCDL[] = {BMP_Output, BMP_DL, 0};
//输入电压
__prog__ const unsigned char * SRDY[] = {BMP_Input, BMP_DY, 0};
//总电压
__prog__ const unsigned char * ZDY[] = {BMP_Zong, BMP_DY, 0};
/******************************************************************************/

/********************************菜单选项**************************************/
//仪表系统信息
__prog__ const unsigned char * IC_SYSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//电池信息
__prog__ const unsigned char * Battery_SYSTEM[] = {BMP_Battery, BMP_Message, 0};
//电机系统信息
__prog__ const unsigned char * MOTO_SYSTEM[] = {BMP_MOTO, BMP_STSTEM, BMP_Message, 0};
//电池管理系统信息
__prog__ const unsigned char * BMS_SYSTEM[] = {BMP_Battery, BMP_Manage, BMP_STSTEM, BMP_Message, 0};
//空调系统信息
__prog__ const unsigned char * AC_SYSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//DCDC系统信息
__prog__ const unsigned char * DCDC_SYSTEM[] = {BMP_DCDC,BMP_STSTEM, BMP_Message, 0};
//气泵系统信息
__prog__ const unsigned char * AIR_SYSTEM[] = {BMP_QIBENG, BMP_STSTEM, BMP_Message, 0};
//油泵系统信息
__prog__ const unsigned char * OIL_SYSTEM[] = {BMP_YOUBENG, BMP_STSTEM, BMP_Message, 0};
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
//高压电池
__prog__ const unsigned char * GYDC[] = {BMP_Gao, BMP_Yali, BMP_DC, 0};
//电机系统故障
__prog__ const unsigned char * DJXTGZ[] = {BMP_DJ, BMP_System, BMP_Guzhang, 0};
//整车系统x级故障
__prog__ const unsigned char * ZCXTGZ[] = {BMP_Zhengche, BMP_System, BMP_Dengji,BMP_Guzhang, 0};
//电池系统x级故障
__prog__ const unsigned char * DCXTGZ[] = {BMP_DC, BMP_System, BMP_Dengji,BMP_Guzhang, 0};
//电池离线
__prog__ const unsigned char * DCLX[] = {BMP_DC, BMP_Lixian, 0};
//电机离线
__prog__ const unsigned char * DJLX[] = {BMP_DJ, BMP_Lixian, 0};
//电容离线
__prog__ const unsigned char * DRLX[] = {BMP_DC, BMP_Rongliang, BMP_Lixian, 0};
//HCU故障
__prog__ const unsigned char * HCUGZ[] = {BMP_h,BMP_c,BMP_u, BMP_Guzhang, 0};
//助力转向故障
__prog__ const unsigned char * ZLZXGZ[] = {BMP_Zhuli,BMP_IC_Zhuanxiang, BMP_Guzhang, 0};
//电机故障
__prog__ const unsigned char * DJGZ[] = {BMP_DJ, BMP_Guzhang, 0};
//电池故障
__prog__ const unsigned char * DCGZ[] = {BMP_DC, BMP_Guzhang, 0};
//电池状态
__prog__ const unsigned char * DCZT[] = {BMP_DC, BMP_Zhuangtai, 0};
//空调工作模式
__prog__ const unsigned char * KTGZMS[] = {BMP_Kongtiao, BMP_Gongzuo,BMP_Mode, 0};
//油泵过热报警
__prog__ const unsigned char * YBGRBJ[] = {BMP_Youbeng, BMP_Guore,BMP_Baojing, 0};
//气泵过热报警
__prog__ const unsigned char * QBGRBJ[] = {BMP_Qibeng, BMP_Guore,BMP_Baojing, 0};

//单体电压过高
__prog__ const unsigned char * DTDYGG[] = {BMP_Dan, BMP_Ti, BMP_DY, BMP_Yali, BMP_Guo, BMP_Gao, 0};
//单体电压过低
__prog__ const unsigned char * DTDYGD[] = {BMP_Dan, BMP_Ti, BMP_DY, BMP_Yali, BMP_Guo, BMP_Di, 0};
//SOC过高
__prog__ const unsigned char * SOCGG[] = {BMP_s, BMP_o, BMP_c, BMP_Guo, BMP_Gao, 0};
//SOC过低
__prog__ const unsigned char * SOCGD[] = {BMP_s, BMP_o, BMP_c, BMP_Guo, BMP_Di, 0};
//电池通讯故障
__prog__ const unsigned char * DCTXGZ[] = {BMP_DC, BMP_Tongxin, BMP_Guzhang, 0};
//总电压欠压
__prog__ const unsigned char * ZDYQY[] = {BMP_Zong, BMP_DY, BMP_Yali, BMP_Qian, BMP_Yali,0};
//总电压过压
__prog__ const unsigned char * ZDYGY[] = {BMP_Zong, BMP_DY, BMP_Yali, BMP_Guo, BMP_Yali,0};
//均衡故障
__prog__ const unsigned char * JHGZ[] = {BMP_Junheng, BMP_Guzhang,0};

//升温过高
__prog__ const unsigned char * SWGG[] = {BMP_Sheng,BMP_Wendu,BMP_Guo,BMP_Gao,0};
//烟雾报警
__prog__ const unsigned char * YWBJ[] = {BMP_Yanwu,BMP_Baojing,0};
//绝缘报警
__prog__ const unsigned char * JYBJ[] = {BMP_Jueyuan,BMP_Baojing,0};
//充电电流
__prog__ const unsigned char * CDDL[] = {BMP_Chong,BMP_DC,BMP_DL,0};
//放电电流
__prog__ const unsigned char * FDDL[] = {BMP_Fang,BMP_DC,BMP_DL,0};
//过大
__prog__ const unsigned char * GD[] = {BMP_Guo, BMP_Da, 0};
//过高
__prog__ const unsigned char * GG[] = {BMP_Guo, BMP_Gao, 0};
//温差过大
__prog__ const unsigned char * WCGD[] = {BMP_Wendu, BMP_Cha, BMP_Guo, BMP_Da, 0};
//电池温度
__prog__ const unsigned char * DCWD[] = {BMP_DC, BMP_Wendu, 0};

//高压互锁
__prog__ const unsigned char * GYHS[] = {BMP_Gao, BMP_Yali, BMP_Husuo,0};
//SOC跳变
__prog__ const unsigned char * SOCTB[] = {BMP_s, BMP_o, BMP_c,BMP_Tiaobian,0};
//储能系统报警
__prog__ const unsigned char * CNXTBJ[] = {BMP_Chuneng, BMP_System, BMP_Baojing,0};
//单体压差报警
__prog__ const unsigned char * DTYCBJ[] = {BMP_Dan, BMP_Ti, BMP_Yali,BMP_Cha,BMP_Baojing,0};


//DCDC短路
__prog__ const unsigned char * DCDCDL[] = {BMP_d, BMP_c, BMP_d,BMP_c,BMP_Duanlu,0};
//DCDC过热
__prog__ const unsigned char * DCDCGR[] = {BMP_d, BMP_c, BMP_d,BMP_c,BMP_Guore,0};
//DCDC输入
__prog__ const unsigned char * DCDCSR[] = {BMP_d, BMP_c, BMP_d,BMP_c,BMP_Input,0};
//DCDC输出
__prog__ const unsigned char * DCDCSC[] = {BMP_d, BMP_c, BMP_d,BMP_c,BMP_Output,0};

//气泵输入
__prog__ const unsigned char * QBSR[] = {BMP_Qibeng, BMP_Input,0};
//气泵瞬时过流
__prog__ const unsigned char * QBSSGL[] = {BMP_Qibeng, BMP_Shunshi,BMP_Guoliu,0};
//气泵过热
__prog__ const unsigned char * QBGR[] = {BMP_Qibeng,BMP_Guore,0};
//气泵短路
__prog__ const unsigned char * QBDL[] = {BMP_Qibeng,BMP_Duanlu,0};
//气泵过载
__prog__ const unsigned char * QBGY[] = {BMP_Qibeng,BMP_Guozai,0};
//气泵缺相
__prog__ const unsigned char * QBQX[] = {BMP_Qibeng,BMP_Quexiang,0};
//气泵温度报警
__prog__ const unsigned char * QBWDBJ[] = {BMP_Qibeng,BMP_Wendu,BMP_Baojing,0};

//气泵输入
__prog__ const unsigned char * YBSR[] = {BMP_Youbeng, BMP_Input,0};
//气泵瞬时过流
__prog__ const unsigned char * YBSSGL[] = {BMP_Youbeng, BMP_Shunshi,BMP_Guoliu,0};
//气泵过热
__prog__ const unsigned char * YBGR[] = {BMP_Youbeng,BMP_Guore,0};
//气泵短路
__prog__ const unsigned char * YBDL[] = {BMP_Youbeng,BMP_Duanlu,0};
//气泵过载
__prog__ const unsigned char * YBGY[] = {BMP_Youbeng,BMP_Guozai,0};
//气泵缺相
__prog__ const unsigned char * YBQX[] = {BMP_Youbeng,BMP_Quexiang,0};
//油泵温度报警
__prog__ const unsigned char * YBWDBJ[] = {BMP_Youbeng,BMP_Wendu,BMP_Baojing,0};

//过压
__prog__ const unsigned char * GY[] = {BMP_Guo, BMP_Yali, 0};
//欠压
__prog__ const unsigned char * QY[] = {BMP_Qian, BMP_Yali, 0};

//前门外阀盖开报警
__prog__ const unsigned char * QMWGFKBJ[] = {BMP_IC_Qian, BMP_Men, BMP_Wai, BMP_Fa, BMP_Gai, BMP_Kai, BMP_Baojing, 0};
//前门应急阀报警
__prog__ const unsigned char * QMYJFBJ[] = {BMP_IC_Qian, BMP_Men, BMP_Yingjifa, BMP_Ji, BMP_Fa, BMP_Baojing, 0};
//内应急阀盖开报警
__prog__ const unsigned char * NYJFGKBJ[] = {BMP_Nei, BMP_Yingjifa, BMP_Ji, BMP_Fa, BMP_Gai, BMP_Kai, BMP_Baojing, 0};
//前门车内应急阀报警
__prog__ const unsigned char * QMCNYJFBJ[] = {BMP_IC_Qian, BMP_Men, BMP_Chesu, BMP_Nei, BMP_Yingjifa, BMP_Ji, BMP_Fa, BMP_Baojing, 0};
//中门车内应急阀报警
__prog__ const unsigned char * HMCNYJFBJ[] = {BMP_IC_Hou, BMP_Men, BMP_Chesu, BMP_Nei, BMP_Yingjifa, BMP_Ji, BMP_Fa, BMP_Baojing, 0};
//中门外应急阀盖开报警
__prog__ const unsigned char * HMWYJFGKBJ[] = {BMP_IC_Hou, BMP_Men, BMP_Wai, BMP_Yingjifa, BMP_Ji, BMP_Fa, BMP_Gai, BMP_Kai, BMP_Baojing, 0};
//中门外应急阀报警
__prog__ const unsigned char * HMWYJFBJ[] = {BMP_IC_Hou, BMP_Men, BMP_Wai, BMP_Yingjifa, BMP_Ji, BMP_Fa,BMP_Baojing, 0};
/******************************************************************************/

/******************************电机系统信息*****************************************/
//车辆当前状态
__prog__ const unsigned char * ZCZT[] = {BMP_Zhengche, BMP_Zhuangtai,0};
//车辆输入状态
__prog__ const unsigned char * ZCSRZT[] = {BMP_Zhengche,BMP_Input, BMP_Zhuangtai,0};
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
//制动踏板状态
__prog__ const unsigned char * ZDTBZT[] = {BMP_Zhidong, BMP_Taban, BMP_Zhuangtai,0};
//加速踏板状态
__prog__ const unsigned char * JSTBZT[] = {BMP_Youmen, BMP_Taban, BMP_Zhuangtai,0};
//电机温度信号状态
__prog__ const unsigned char * DJWDXHZT[] = {BMP_DJ, BMP_Wendu, BMP_Xinhao,BMP_Zhuangtai,0};
//电机控制器温度信号
__prog__ const unsigned char * DJKZQWDXHZT[] = {BMP_DJ,BMP_KZQ, BMP_Wendu, BMP_Xinhao,0};
//除霜接触器
__prog__ const unsigned char * CSJCQ[] = {BMP_Chushuang, BMP_Jiechuqi,0};
//增压压力
__prog__ const unsigned char * ZYYL[] = {BMP_Zengya,BMP_Yali,0};
//RPM
__prog__ const unsigned char * CHAR_RPM[] = {BMP_r,BMP_p,BMP_m,0};
//L/H
__prog__ const unsigned char * CHAR_LH[] = {BMP_l,BMP_I,BMP_h,0};
//MPA
__prog__ const unsigned char * CHAR_MPA[] = {BMP_m,BMP_p,BMP_a,0};
//KPA
__prog__ const unsigned char * CHAR_KPA[] = {BMP_k,BMP_p,BMP_a,0};
//KWH
__prog__ const unsigned char * CHAR_KWH[] = {BMP_k,BMP_w,BMP_h,0};
//SPN
__prog__ const unsigned char * CHAR_SPN[] = {BMP_s,BMP_p,BMP_n,0};
//FMI
__prog__ const unsigned char * CHAR_FMI[] = {BMP_f,BMP_m,BMP_i,0};
//电源状态
__prog__ const unsigned char * DYZT[] = {BMP_Dianyuan,BMP_Zhuangtai,0};
//程序版本
__prog__ const unsigned char * CXBB[] = {BMP_Chengxu,BMP_Banben,0};
//故障代码
__prog__ const unsigned char * GZDM[] = {BMP_Guzhang,BMP_Code,0};
//工作状态
__prog__ const unsigned char * GZZT[] = {BMP_Guzhang,BMP_Zhuangtai,0};
//故障等级
__prog__ const unsigned char * GZDJ[] = {BMP_Guzhang,BMP_Dengji,0};
//DCDC
__prog__ const unsigned char * DCDC[] = {BMP_d,BMP_c,BMP_d,BMP_c,0};
//DCAC
__prog__ const unsigned char * DCAC[] = {BMP_d,BMP_c,BMP_a,BMP_c,0};
//散热器温度
__prog__ const unsigned char * SRQWD[] = {BMP_Sanreqi,BMP_Wendu,0};
//控制器温度
__prog__ const unsigned char * KZQWD[] = {BMP_KZQ,BMP_Wendu,0};
//电机状态
__prog__ const unsigned char * DJZT[] = {BMP_DJ,BMP_Zhuangtai,0};
//充电座温度
__prog__ const unsigned char * CDZWD[] = {BMP_Chong, BMP_DC, BMP_Zuo, BMP_Wendu, 0};
//
__prog__ const unsigned char * CFDDL[] = {BMP_Chong, BMP_Fang, BMP_DC, BMP_DL, 0};
/******************************************************************************/
/*******************************开关量采集*************************************/
//喇叭开关
__prog__ const unsigned char * LBKG[] = {BMP_Laba, BMP_IC_Kaiguan, 0};
//前雾灯开关
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ADD
__prog__ const unsigned char * ADD[] = {BMP_a, BMP_d, BMP_d,0};
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
//ACC档
__prog__ const unsigned char * ACCD[] = {BMP_a, BMP_c, BMP_c,BMP_Dang, 0};
//ON档
__prog__ const unsigned char * ON[] = {BMP_o, BMP_n,BMP_Dang, 0};
//危险报警信号
__prog__ const unsigned char * WXBJKG[] = {BMP_Weixian, BMP_Baojing, BMP_IC_Kaiguan, 0};
//电源开关
__prog__ const unsigned char * DYKG[] = {BMP_Dianyuan, BMP_IC_Kaiguan, 0};
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
//厢灯1开关
__prog__ const unsigned char * XD1KG[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[1], BMP_IC_Kaiguan, 0};
//厢灯2开关
__prog__ const unsigned char * XD2KG[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[2], BMP_IC_Kaiguan, 0};
//路牌开关
__prog__ const unsigned char * LPKG[] = {BMP_Lupai, BMP_IC_Kaiguan, 0};
//制动开关
__prog__ const unsigned char * ZDKG[] = {BMP_Zhidong, BMP_IC_Kaiguan, 0};
//顶灯开关
__prog__ const unsigned char * DDKG[] = {BMP_Dingbu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//散热器1开关
__prog__ const unsigned char * SRQ1KG[] = {BMP_Sanreqi, BMP_SZ_2[1], 0};
//散热器2开关
__prog__ const unsigned char * SRQ2KG[] = {BMP_Sanreqi, BMP_SZ_2[2], 0};
//TV开关
__prog__ const unsigned char * TVKG[] = {BMP_t, BMP_v, BMP_IC_Kaiguan, 0};
//风扇开关
__prog__ const unsigned char * FSKG[] = {BMP_Fengshan, BMP_IC_Kaiguan, 0};
//司机灯开关
__prog__ const unsigned char * SJDKG[] = {BMP_Siji, BMP_IC_Kaiguan,0};
//照明开关1
__prog__ const unsigned char * ZMKG1[] = {BMP_Zhaoming,BMP_IC_Kaiguan, BMP_SZ_2[1], 0};
//照明开关2
__prog__ const unsigned char * ZMKG2[] = {BMP_Zhaoming,BMP_IC_Kaiguan, BMP_SZ_2[2], 0};
//TV开关1
__prog__ const unsigned char * TV1KG[] = {BMP_t,BMP_v, BMP_SZ_2[1],BMP_IC_Kaiguan, 0};
//TV开关2
__prog__ const unsigned char * TV2KG[] = {BMP_t,BMP_v, BMP_SZ_2[2],BMP_IC_Kaiguan, 0};
//地址选择1
__prog__ const unsigned char * DZXZ1[] = {BMP_Dizhi,BMP_Xuanze, BMP_SZ_2[1], 0};
//地址选择2
__prog__ const unsigned char * DZXZ2[] = {BMP_Dizhi,BMP_Xuanze, BMP_SZ_2[2], 0};
//水位报警
__prog__ const unsigned char * SWBJ[] = {BMP_Shuiwei,BMP_Baojing, 0};
//左前摩擦片
__prog__ const unsigned char * ZQMCP[] = {BMP_IC_Zuo,BMP_IC_Qian,BMP_Mocapian, 0};
//左前摩擦片
__prog__ const unsigned char * YQMCP[] = {BMP_IC_You,BMP_IC_Qian,BMP_Mocapian, 0};
//左前摩擦片
__prog__ const unsigned char * ZHMCP[] = {BMP_IC_Zuo,BMP_IC_Hou,BMP_Mocapian, 0};
//左前摩擦片
__prog__ const unsigned char * YHMCP[] = {BMP_IC_You,BMP_IC_Hou,BMP_Mocapian, 0};
//气压报警1
__prog__ const unsigned char * QYBJ1[] = {BMP_Qiya, BMP_Baojing,BMP_SZ_2[1], 0};
//气压报警2
__prog__ const unsigned char * QYBJ2[] = {BMP_Qiya, BMP_Baojing,BMP_SZ_2[2], 0};
//后舱门开关
__prog__ const unsigned char * HCMKG[] = {BMP_IC_Hou, BMP_Cangmen,BMP_Men, BMP_IC_Kaiguan, 0};
/******************************************************************************/

/******************************模块输出状态************************************/
//门泵电源
__prog__ const unsigned char * MBDY[] = {BMP_Men, BMP_Dianyuan, 0};
//制动电源
//__prog__ const unsigned char * ZDDY[] = {BMP_Zhidong, BMP_Dianyuan, 0};
//门铃电源
__prog__ const unsigned char * MLDY[] = {BMP_Men, BMP_Ling, BMP_Dianyuan, 0};
//仓温电源
__prog__ const unsigned char * CWDY[] = {BMP_Cangmen, BMP_Wendu, BMP_Dianyuan, 0};
//电视电源
__prog__ const unsigned char * DSDY[] = {BMP_Dianshi, BMP_Dianyuan, 0};
//空调电源
__prog__ const unsigned char * KTDY[] = {BMP_Kongtiao, BMP_Dianyuan, 0};
//前雾灯输出
__prog__ const unsigned char * QWDSC[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//后雾灯输出
__prog__ const unsigned char * HWDSC[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, 0};
//左前雾灯输出
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//右前雾灯输出
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//前门开输出
__prog__ const unsigned char * QMKSC[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Output, 0};
//前门关输出
__prog__ const unsigned char * QMGSC[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_Output, 0};
//中门开输出
__prog__ const unsigned char * ZMKSC[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Output, 0};
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
//前门开开关
__prog__ const unsigned char * QMKKG[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//中门开开关
__prog__ const unsigned char * ZMKKG[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//前门关开关
__prog__ const unsigned char * QMGKG[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//中门关开关
__prog__ const unsigned char * ZMGKG[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//辅助气压报警
__prog__ const unsigned char * FZQYBJ[] = {BMP_Fuzhu, BMP_Qiya, BMP_Baojing, 0};
//小灯
__prog__ const unsigned char * XD[] = {BMP_Xiao, BMP_IC_Deng,0};
//位置灯
__prog__ const unsigned char * WZD[] = {BMP_Weizhi, BMP_IC_Deng,0};
//电源输出
__prog__ const unsigned char * DYSC[] = {BMP_Dianyuan, BMP_Output,0};
//前路牌
__prog__ const unsigned char * QLP[] = {BMP_IC_Qian, BMP_Lupai,0};
//后路牌
__prog__ const unsigned char * HLP[] = {BMP_IC_Hou,BMP_Lupai,0};
//司机灯
__prog__ const unsigned char * SJD[] = {BMP_Siji,BMP_IC_Deng,0};
//TV1电源
__prog__ const unsigned char * TV1DY[] = {BMP_t, BMP_v, BMP_SZ_2[1], BMP_Dianyuan, 0};
//TV2电源
__prog__ const unsigned char * TV2DY[] = {BMP_t, BMP_v, BMP_SZ_2[2], BMP_Dianyuan, 0};
//顶灯输出
__prog__ const unsigned char * DDSC[] = {BMP_Dingbu, BMP_IC_Deng,BMP_Output, 0};
//厢灯1输出
__prog__ const unsigned char * XD1SC[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[1], BMP_Output, 0};
//厢灯2输出
__prog__ const unsigned char * XD2SC[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[2], BMP_Output, 0};
//风扇输出1
__prog__ const unsigned char * FSSC1[] = {BMP_Fengshan, BMP_Output, BMP_SZ_2[1], 0};
//风扇输出2
__prog__ const unsigned char * FSSC2[] = {BMP_Fengshan, BMP_Output, BMP_SZ_2[2], 0};
//风扇输出3
__prog__ const unsigned char * FSSC3[] = {BMP_Fengshan, BMP_Output, BMP_SZ_2[3], 0};
//倒车灯输出
__prog__ const unsigned char * DCDSC[] = {BMP_Daoche, BMP_IC_Deng, 0};
//散热器1
__prog__ const unsigned char * SRQ1[] = {BMP_Sanreqi, BMP_SZ_2[1], 0};
//散热器2
__prog__ const unsigned char * SRQ2[] = {BMP_Sanreqi, BMP_SZ_2[2], 0};
//照明1
__prog__ const unsigned char * ZM1[] = {BMP_Zhaoming, BMP_SZ_2[1], 0};
//照明2
__prog__ const unsigned char * ZM2[] = {BMP_Zhaoming, BMP_SZ_2[2], 0};
//倒车信号
__prog__ const unsigned char * DCXH[] = {BMP_Daoche, BMP_Xinhao,0};
//门开信号
__prog__ const unsigned char * MKXH[] = {BMP_Men, BMP_Kai,BMP_Xinhao, 0};
//接近开关
__prog__ const unsigned char * JJKG[] = {BMP_Jiechuqi, BMP_IC_Jin,BMP_IC_Kaiguan, 0};
//后舱门灯
__prog__ const unsigned char * HCMD[] = {BMP_IC_Hou, BMP_Cangmen,BMP_Men, BMP_IC_Deng, 0};
/******************************************************************************/
/******************************************************************************/
//动力电池
__prog__ const unsigned char * DLDC[] = {BMP_Dongli,BMP_DC,0};
//电池报警等级
__prog__ const unsigned char * DCBJDJ[] = {BMP_DC,BMP_Baojing,BMP_Dengji,0};
//绝缘母线电压
__prog__ const unsigned char * JYMXDY[] = {BMP_Jueyuan,BMP_Muxian,BMP_DY,0};
//绝缘故障等级
__prog__ const unsigned char * JYGZDJ[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Dengji,0};
//绝缘故障状态
__prog__ const unsigned char * JYGZZT1[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Zhuangtai,0};
//绝缘工作状态
__prog__ const unsigned char * JYGZZT2[] = {BMP_Jueyuan,BMP_Gongzuo,BMP_Zhuangtai,0};
/******************************************************************************/
#endif	/* APP_CHAR_H */

