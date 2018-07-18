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
//电机母线电压
__prog__ const unsigned char * DJMXDY[] = {BMP_DJ, BMP_Muxian, BMP_DY, 0};
//电机母线电流
__prog__ const unsigned char * DJMXDL[] = {BMP_DJ, BMP_Muxian, BMP_DL, 0};
//电机转速
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//电池电流
__prog__ const unsigned char * DCDL[] = {BMP_DC, BMP_DL, 0};
//输出转速
__prog__ const unsigned char * SCZS[] = {BMP_Output, BMP_Zhuansu, 0};
//EV信号
__prog__ const unsigned char * EV[] = {BMP_e, BMP_v,BMP_Xinhao, 0};
//停机状态
__prog__ const unsigned char * TJZT[] = {BMP_Tingzhi, BMP_Jiyou,BMP_Zhuangtai, 0};
//制动踏板
__prog__ const unsigned char * ZDTB[] = {BMP_Zhidong, BMP_Taban, 0};
//油门踏板
__prog__ const unsigned char * YMTB[] = {BMP_Youmen, BMP_Taban, 0};
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
//__prog__ const unsigned char * OIL_STSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//高压系统信息
__prog__ const unsigned char * HV_SYSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//配电盒信息
__prog__ const unsigned char * PDH_SYSTEM[] = {BMP_PEIDIANHE, BMP_Message, 0};
//发动机信息
__prog__ const unsigned char * ENG_SYSTEM[] = {BMP_Engine, BMP_Message, 0};

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
//电池离线
__prog__ const unsigned char * DCLX[] = {BMP_DC, BMP_Lixian, 0};
//电机离线
__prog__ const unsigned char * DJLX[] = {BMP_DJ, BMP_Lixian, 0};
//变速箱离线
__prog__ const unsigned char * BSXLX[] = {BMP_Biansuxiang, BMP_Lixian, 0};
//发动机离线
__prog__ const unsigned char * FDJLX[] = {BMP_Fadongji, BMP_Lixian, 0};
//电容离线
__prog__ const unsigned char * DRLX[] = {BMP_DC, BMP_Rongliang, BMP_Lixian, 0};
//传动系统故障
__prog__ const unsigned char * CDXTGZ[] = {BMP_Chuandong, BMP_System, BMP_Guzhang, 0};
//混合动力故障
__prog__ const unsigned char * HHDLGZ[] = {BMP_Hunhe, BMP_Dongli, BMP_Guzhang, 0};
//变速箱故障
__prog__ const unsigned char * BSXGZ[] = {BMP_Biansuxiang, BMP_Guzhang, 0};
//HCU故障
__prog__ const unsigned char * HCUGZ[] = {BMP_h,BMP_c,BMP_u, BMP_Guzhang, 0};
//助力转向故障
__prog__ const unsigned char * ZLZXGZ[] = {BMP_Zhuli,BMP_IC_Zhuanxiang, BMP_Guzhang, 0};
//电机故障
__prog__ const unsigned char * DJGZ[] = {BMP_DJ, BMP_Guzhang, 0};
//电池故障
__prog__ const unsigned char * DCGZ[] = {BMP_DC, BMP_Guzhang, 0};
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
//除霜接触器
__prog__ const unsigned char * CSJCQ[] = {BMP_Chushuang, BMP_Jiechuqi,0};
//发动机转速
__prog__ const unsigned char * FDJZS[] = {BMP_Fadongji, BMP_Zhuansu,0};
//发动机气耗
__prog__ const unsigned char * FDJQH[] = {BMP_Fadongji, BMP_Qihao,0};
//发动机水温
__prog__ const unsigned char * FDJSW[] = {BMP_Fadongji, BMP_Shuiwen,0};
//发动机油门
__prog__ const unsigned char * FDJYM[] = {BMP_Fadongji, BMP_Youmen,0};
//机油压力
__prog__ const unsigned char * JYYL[] = {BMP_Jiyou,BMP_Yali,0};
//进气温度
__prog__ const unsigned char * JQWD[] = {BMP_Jinqi,BMP_Wendu,0};
//进气压力
__prog__ const unsigned char * JQYL[] = {BMP_Jinqi,BMP_Yali,0};
//增压压力
__prog__ const unsigned char * ZYYL[] = {BMP_Zengya,BMP_Yali,0};
//RPM
__prog__ const unsigned char * CHAR_RPM[] = {BMP_r,BMP_p,BMP_m,0};
//L/H
__prog__ const unsigned char * CHAR_LH[] = {BMP_l,BMP_I,BMP_h,0};
//MPA
__prog__ const unsigned char * CHAR_MPA[] = {BMP_m,BMP_p,BMP_a,0};
//MPA
__prog__ const unsigned char * CHAR_KPA[] = {BMP_k,BMP_p,BMP_a,0};
//SPN
__prog__ const unsigned char * CHAR_SPN[] = {BMP_s,BMP_p,BMP_n,0};
//FMI
__prog__ const unsigned char * CHAR_FMI[] = {BMP_f,BMP_m,BMP_i,0};
//配电盒温度
__prog__ const unsigned char * PDHWD[] = {BMP_Peidianhe,BMP_Wendu,0};
//配电盒电流
__prog__ const unsigned char * PDHDL[] = {BMP_Peidianhe,BMP_DL,0};
//电源状态
__prog__ const unsigned char * DYZT[] = {BMP_Dianyuan,BMP_Zhuangtai,0};
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
//空滤报警
__prog__ const unsigned char * KLBJ[] = {BMP_Konglv, BMP_Baojing, 0};
//后启动
__prog__ const unsigned char * HQD[] = {BMP_IC_Hou, BMP_Qidong, 0};
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
//启动请求
__prog__ const unsigned char * QDQQ[] = {BMP_Qidong, BMP_Qingqiu,0};
//电源输出
__prog__ const unsigned char * DYSC[] = {BMP_Dianyuan, BMP_Output,0};
//前路牌
__prog__ const unsigned char * QLP[] = {BMP_IC_Qian, BMP_Lupai,0};
//后路牌
__prog__ const unsigned char * HLP[] = {BMP_IC_Hou,BMP_Lupai,0};
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
//启动接触器
__prog__ const unsigned char * QDJCQ[] = {BMP_Qidong, BMP_Jiechuqi, 0};
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
//门开信号
__prog__ const unsigned char * MKXH[] = {BMP_Men, BMP_Kai,BMP_Xinhao, 0};
//发动机输出
__prog__ const unsigned char * FDJSC[] = {BMP_Fadongji, BMP_Output, 0};
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

