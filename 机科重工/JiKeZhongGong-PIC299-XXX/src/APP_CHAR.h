#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "APP_FONT.h"

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
//三合一温度
__prog__ const unsigned char * SHYWD[] = {BMP_Sanheyi, BMP_Wendu, 0};
/******************************************************************************/

/********************************菜单选项**************************************/
//仪表系统信息
__prog__ const unsigned char * IC_SYSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//电池信息
__prog__ const unsigned char * Battery_SYSTEM[] = {BMP_Battery, BMP_Message, 0};
//车辆系统信息
__prog__ const unsigned char * MOTO_SYSTEM[] = {Bmp_Car, BMP_STSTEM, BMP_Message, 0};
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
//吊具系统信息
__prog__ const unsigned char * DJu_SYSTEM[] = {Bmp_DJu, BMP_STSTEM, BMP_Message, 0};


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

/*******************************开关量采集*************************************/
__prog__ const unsigned char * KIN1[] = {BMP_Diao, BMP_Ju, BMP_Kai, BMP_Suo, BMP_IC_Kaiguan, 0};//吊具开锁开关
__prog__ const unsigned char * KIN2[] = {BMP_Diao, BMP_Ju, BMP_Bi, BMP_Suo, BMP_IC_Kaiguan, 0};//吊具闭锁开关
__prog__ const unsigned char * KIN3[] = {BMP_Diao, BMP_Ju, BMP_IC_Zuo, BMP_Yi, BMP_IC_Kaiguan, 0};//吊具左移开关
__prog__ const unsigned char * KIN4[] = {BMP_Diao, BMP_Ju, BMP_IC_You, BMP_Yi, BMP_IC_Kaiguan, 0};//吊具右移开关
__prog__ const unsigned char * KIN5[] = {BMP_Diao, BMP_Ju, BMP_IC_Zuo, BMP_Xuan, BMP_IC_Kaiguan, 0};//吊具左旋开关
__prog__ const unsigned char * KIN6[] = {BMP_Diao, BMP_Ju, BMP_IC_You, BMP_Xuan, BMP_IC_Kaiguan, 0};//吊具右旋开关

__prog__ const unsigned char * KIN7[] = {Bmp_FYang, Bmp_XJiang, BMP_IC_Kaiguan, 0};//俯仰下降开关
__prog__ const unsigned char * KIN8[] = {Bmp_FYang, Bmp_SSheng, BMP_IC_Kaiguan, 0};//俯仰上升开关
__prog__ const unsigned char * KIN9[]  = {Bmp_DBi, Bmp_SChu, BMP_IC_Kaiguan, 0};//大臂伸出开关
__prog__ const unsigned char * KIN10[] = {Bmp_DBi, Bmp_SJing, BMP_IC_Kaiguan, 0};//大臂缩进开关

__prog__ const unsigned char * KIN11[] = {Bmp_SBSNeng, BMP_IC_Kaiguan, 0};//手柄使能开关
__prog__ const unsigned char * KIN12[] = {BMP_IC_Qian, Bmp_Jin, Bmp_Dang, BMP_IC_Kaiguan, 0};//前进档开关
__prog__ const unsigned char * KIN13[] = {BMP_IC_Hou, Bmp_Tui, Bmp_Dang, BMP_IC_Kaiguan, 0};//后退档开关
__prog__ const unsigned char * KIN14[] = {Bmp_Kong, Bmp_Dang, BMP_IC_Kaiguan, 0};//空挡开关

__prog__ const unsigned char * KIN15[] = {Bmp_Dang, Bmp_Wei, BMP_Xinxi, BMP_SZ_2[1], 0};//挡位信息1
__prog__ const unsigned char * KIN16[] = {Bmp_Dang, Bmp_Wei, BMP_Xinxi, BMP_SZ_2[2], 0};//挡位信息2
__prog__ const unsigned char * KIN17[] = {Bmp_Dang, Bmp_Wei, BMP_Xinxi, BMP_SZ_2[3], 0};//挡位信息3

//远光灯开关
__prog__ const unsigned char * YGDKG[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//近光灯开关
__prog__ const unsigned char * JGDKG[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};

                     #define   KIN18      JGDKG //近光灯开关
                     #define   KIN19      YGDKG //远光灯开关

__prog__ const unsigned char * KIN20[] = {BMP_Zhidong, BMP_Yali, BMP_Di, BMP_Baojing, BMP_Xinhao, 0};//刹车压力不足报警信号
__prog__ const unsigned char * KIN21[] = {BMP_Zhidong, BMP_IC_Kaiguan, 0};//刹车信号
__prog__ const unsigned char * KIN22[] = {BMP_Zhuche,  BMP_IC_Kaiguan, 0};//驻车开关
__prog__ const unsigned char * KIN23[] = {BMP_IC_Zuo,  BMP_IC_Zhuanxiang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};//左转灯开关
__prog__ const unsigned char * KIN24[] = {BMP_IC_You,  BMP_IC_Zhuanxiang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};//右转灯开关

__prog__ const unsigned char * KIN25[] = {BMP_Diao, BMP_Ju, BMP_Shen, Bmp_ZLing, BMP_IC_Kaiguan, 0};//吊具伸指令
__prog__ const unsigned char * KIN26[] = {Bmp_YShi, BMP_s, BMP_t, BMP_a, BMP_r, BMP_t, BMP_Xinhao, 0};//钥匙START信号
__prog__ const unsigned char * KIN27[] = {Bmp_YShi, BMP_a, BMP_c, BMP_c, BMP_Xinhao, 0};//钥匙ACC信号
__prog__ const unsigned char * KIN28[] = {BMP_Gongzuo, BMP_IC_Deng, BMP_IC_Kaiguan, 0};//工作灯开关
                     #define   KIN29      BMP_Beiyong
                     #define   KIN30      BMP_Beiyong
                     #define   KIN31      BMP_Beiyong
__prog__ const unsigned char * KIN32[] = {BMP_Diao, BMP_Ju, BMP_Suo2, Bmp_ZLing, BMP_IC_Kaiguan, 0};//吊具缩指令
                     #define   KIN33      BMP_Beiyong
                     #define   KIN34      BMP_Beiyong
                     #define   KIN35      BMP_Beiyong
                     #define   KIN36      BMP_Beiyong
                     #define   KIN37      BMP_Beiyong
__prog__ const unsigned char * KIN38[] = {BMP_Weixian,   BMP_Baojing,  BMP_Xinhao, 0};//
__prog__ const unsigned char * KIN39[] = {BMP_Chongdian, BMP_Huanxing, BMP_Xinhao, 0};//
__prog__ const unsigned char * KIN40[] = {Bmp_YShi, BMP_o, BMP_n, BMP_Dang, BMP_IC_Kaiguan, 0};//

__prog__ const unsigned char * Bmp_front_load_1[] = {BMP_IC_Qian, Bmp_Jin, Bmp_Dang, 0};//前进档
__prog__ const unsigned char * Bmp_front_load_2[] = {BMP_IC_Hou, Bmp_Tui, Bmp_Dang, 0};//后退档
__prog__ const unsigned char * Bmp_front_load_3[] = {Bmp_Dang,   BMP_Fa,  BMP_SZ_2[1], 0};//档阀1
__prog__ const unsigned char * Bmp_front_load_4[] = {Bmp_Dang,   BMP_Fa,  BMP_SZ_2[2], 0};//档阀2
__prog__ const unsigned char * Bmp_front_load_5[] = {Bmp_Dang,   BMP_Fa,  BMP_SZ_2[3], 0};//档阀3
__prog__ const unsigned char * Bmp_front_load_6[] = {BMP_Zhuche,   BMP_Fa,   0};//驻车阀
__prog__ const unsigned char * Bmp_front_load_7[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, 0};//近光灯
__prog__ const unsigned char * Bmp_front_load_8[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, 0};//远光灯
__prog__ const unsigned char * Bmp_front_load_9[] = {BMP_IC_Zuo,  BMP_IC_Zhuanxiang, BMP_IC_Deng, 0};//左转灯开关
__prog__ const unsigned char * Bmp_front_load_10[] = {BMP_IC_You,  BMP_IC_Zhuanxiang, BMP_IC_Deng, 0};//右转灯开关
__prog__ const unsigned char * Bmp_front_load_11[] = {BMP_Daoche,    BMP_IC_Deng,   0};//倒车灯
__prog__ const unsigned char * Bmp_front_load_12[] = {BMP_Zhidong,   BMP_IC_Deng,   0};//制动灯
__prog__ const unsigned char * Bmp_front_load_13[] = {BMP_Kai, BMP_Suo,  BMP_IC_Deng, 0};//开锁灯
__prog__ const unsigned char * Bmp_front_load_14[] = {BMP_Bi,  BMP_Suo,  BMP_IC_Deng, 0};//闭锁灯
__prog__ const unsigned char * Bmp_front_load_15[] = {Bmp_Zhuo,   BMP_Xiang_BMS,  BMP_IC_Deng, 0};//着箱灯



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
//前门应急阀报警

//ASR
__prog__ const unsigned char * ASR[] = {BMP_a, BMP_s, BMP_r, BMP_Guzhang, 0};
//ABS
__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s, BMP_Guzhang, 0};
//ACC信号
__prog__ const unsigned char * ACCXH[] = {BMP_a, BMP_c, BMP_c, BMP_Xinhao, 0};
//START档
__prog__ const unsigned char * START[] = {BMP_s, BMP_t, BMP_a, BMP_r, BMP_t, BMP_Dang, 0};
//危险报警信号
__prog__ const unsigned char * WXBJXH[] = {BMP_Weixian, BMP_Baojing, BMP_Xinhao, 0};
//充电唤醒信号
__prog__ const unsigned char * CDHXXH[] = {BMP_Chongdian, BMP_Huanxing, BMP_Xinhao, 0};
//驻车制动开关
__prog__ const unsigned char * ZCZDKG[] = {BMP_Zhuche, BMP_Zhidong, BMP_IC_Kaiguan, 0};
//门铃开关
__prog__ const unsigned char * MLKG[] = {BMP_Men, BMP_Ling, BMP_IC_Kaiguan, 0};
//喇叭开关
__prog__ const unsigned char * LBKG[] = {BMP_Laba,  BMP_IC_Kaiguan, 0};
//空调开关
__prog__ const unsigned char * KTKG[] = {BMP_Kongtiao,  BMP_IC_Kaiguan, 0};
//SERVICE
__prog__ const unsigned char * SERVICE[] = {BMP_s, BMP_e, BMP_r,BMP_v, BMP_i, BMP_c,BMP_e, BMP_Qingqiu, 0};

/******************************************************************************/

/******************************模块输出状态************************************/
//左前雾灯输出
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//右前雾灯输出
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//前雾灯输出
__prog__ const unsigned char * QWDSC[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
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
//驻车制动指示
__prog__ const unsigned char * ZCZDSC[] = {BMP_Zhuche, BMP_Zhidong, BMP_Output, 0};
//空调电源
__prog__ const unsigned char * KTDY[] = {BMP_Kongtiao, BMP_Dianyuan, 0};
/******************************************************************************/
//左侧开锁阀
__prog__ const unsigned char * ZCKSF[] = {BMP_IC_Zuo, BMP_Ce, BMP_Kai, BMP_Suo, BMP_Fa, 0};
//左侧闭锁阀
__prog__ const unsigned char * ZCBSF[] = {BMP_IC_Zuo, BMP_Ce, BMP_Bi, BMP_Suo, BMP_Fa, 0};
//右侧开锁阀
__prog__ const unsigned char * YCKSF[] = {BMP_IC_You, BMP_Ce, BMP_Kai, BMP_Suo, BMP_Fa, 0};
//右侧闭锁阀
__prog__ const unsigned char * YCBSF[] = {BMP_IC_You, BMP_Ce, BMP_Bi, BMP_Suo, BMP_Fa, 0};
//左侧吊具伸阀
__prog__ const unsigned char * ZCDJShenF[] = {BMP_IC_Zuo, BMP_Ce, BMP_Diao, BMP_Ju,BMP_Shen, BMP_Fa, 0};
//左侧吊具缩阀
__prog__ const unsigned char * ZCDJSuoF[] = {BMP_IC_Zuo, BMP_Ce, BMP_Diao, BMP_Ju,BMP_Suo2, BMP_Fa, 0};
//右侧吊具伸阀
__prog__ const unsigned char * YCDJShenF[] = {BMP_IC_You, BMP_Ce, BMP_Diao, BMP_Ju,BMP_Shen, BMP_Fa, 0};
//右侧吊具缩阀
__prog__ const unsigned char * YCDJSuoF[] = {BMP_IC_You, BMP_Ce, BMP_Diao, BMP_Ju,BMP_Suo2, BMP_Fa, 0};
//左侧移阀
__prog__ const unsigned char * ZCYF[] = {BMP_IC_Zuo, BMP_Ce, BMP_Yi, BMP_Fa, 0};
//右侧移阀
__prog__ const unsigned char * YCYF[] = {BMP_IC_You, BMP_Ce, BMP_Yi, BMP_Fa, 0};
//左旋阀
__prog__ const unsigned char * ZXF[] = {BMP_IC_Zuo, BMP_Xuan, BMP_Fa, 0};
//右旋阀
__prog__ const unsigned char * YXF[] = {BMP_IC_You, BMP_Xuan, BMP_Fa, 0};
//制动器打开阀
__prog__ const unsigned char * ZDQDKF[] = {BMP_Zhidong, BMP_Qi, BMP_Da2, BMP_Kai, BMP_Fa, 0}; //BMP_Dongli,
//旋转高速阀
__prog__ const unsigned char * XZGSF[] = {BMP_Xuan,  Bmp_Zhuan, BMP_Gao, BMP_Su, BMP_Fa, 0};//BMP_Zhuansu,


//开闭锁次数
__prog__ const unsigned char * KBSCS[] = {BMP_Kai, BMP_Bi, BMP_Suo, Bmp_Ci, Bmp_Shu, 0};
//开锁灯
__prog__ const unsigned char * KSD[] = {BMP_Kai, BMP_Suo,  BMP_IC_Deng,  0};
//闭锁灯
__prog__ const unsigned char * BSD[] = {BMP_Bi, BMP_Suo,  BMP_IC_Deng,  0};
//着箱灯
__prog__ const unsigned char * ZXD[] = {Bmp_Zhuo, BMP_Xiang_BMS,  BMP_IC_Deng,  0};
//着箱旁路指示灯
__prog__ const unsigned char * ZXPLD[] = {Bmp_Zhuo, BMP_Xiang_BMS, Bmp_Pang, Bmp_ROAD, Bmp_Zhi, Bmp_Shi, BMP_IC_Deng,  0};
//垂直起伏模式
__prog__ const unsigned char * CZQFMS[] = {Bmp_CZhi, Bmp_QFu, Bmp_MShi,  0};
//电机控制器就绪
//__prog__ const unsigned char * DJKZQ[] = {BMP_DJ, BMP_KZQ, 0};
//电池管理系统就绪
__prog__ const unsigned char * DCGLXT[] = {BMP_DC, Bmp_GLi, BMP_System, Bmp_JXu, 0};


//吊具界面
__prog__ const unsigned char * DJU_KIN1[] = {BMP_IC_Qian, BMP_IC_Zuo, BMP_DING, Bmp_Xiao, BMP_Xinhao, 0};//前左顶销信号
__prog__ const unsigned char * DJU_KIN2[] = {BMP_IC_Hou,  BMP_IC_Zuo, BMP_DING, Bmp_Xiao, BMP_Xinhao, 0};//后左顶销信号
__prog__ const unsigned char * DJU_KIN3[] = {BMP_IC_Qian, BMP_IC_You, BMP_DING, Bmp_Xiao, BMP_Xinhao, 0};//前右顶销信号
__prog__ const unsigned char * DJU_KIN4[] = {BMP_IC_Hou,  BMP_IC_You, BMP_DING, Bmp_Xiao, BMP_Xinhao, 0};//后右顶销信号
__prog__ const unsigned char * DJU_KIN5[] = {BMP_IC_Zuo,  BMP_Ce,     BMP_Kai,  BMP_Suo,  BMP_Xinhao, 0};//左侧开锁信号
__prog__ const unsigned char * DJU_KIN6[] = {BMP_IC_Zuo,  BMP_Ce,     BMP_Bi,   BMP_Suo,  BMP_Xinhao, 0};//左侧闭锁信号
__prog__ const unsigned char * DJU_KIN7[] = {BMP_IC_You,  BMP_Ce,     BMP_Kai,  BMP_Suo,  BMP_Xinhao, 0};//右侧开锁信号
__prog__ const unsigned char * DJU_KIN8[] = {BMP_IC_You,  BMP_Ce,     BMP_Bi,   BMP_Suo,  BMP_Xinhao, 0};//右侧闭锁信号

__prog__ const unsigned char * DJU_KIN9[]  = {BMP_IC_Zuo,  BMP_Xuan,   Bmp_Ji5,  Bmp_Xian, BMP_Xinhao, 0};//左旋极限信号
__prog__ const unsigned char * DJU_KIN10[] = {BMP_IC_You,  BMP_Xuan,   Bmp_Ji5,  Bmp_Xian, BMP_Xinhao, 0};//右旋极限信号
                      #define  DJU_KIN11      CZQFMS   //垂直起伏模式
                      #define  DJU_KIN12      BMP_Beiyong   //
                      #define  DJU_KIN13      BMP_Beiyong   //
                      #define  DJU_KIN14      BMP_Beiyong   //
                      #define  DJU_KIN15      BMP_Beiyong   //
                      #define  DJU_KIN16      BMP_Beiyong   //

                      #define  DJU_KIN17      ZCKSF   //左侧开锁阀
                      #define  DJU_KIN18      ZCBSF   //左侧闭锁阀
                      #define  DJU_KIN19      YCKSF   //右侧开锁阀
                      #define  DJU_KIN20      YCBSF   //右侧闭锁阀
                      #define  DJU_KIN21      ZCDJShenF  //左侧吊具伸阀
                      #define  DJU_KIN22      ZCDJSuoF   //左侧吊具缩阀
                      #define  DJU_KIN23      YCDJShenF  //右侧吊具伸阀
                      #define  DJU_KIN24      YCDJSuoF   //右侧吊具缩阀

                      #define  DJU_KIN25      ZCYF   //左侧移阀
                      #define  DJU_KIN26      ZCYF   //左侧移阀
                      #define  DJU_KIN27      YCYF   //右侧移阀
                      #define  DJU_KIN28      YCYF   //右侧移阀
                      #define  DJU_KIN29      ZDQDKF   //制动器打开阀
                      #define  DJU_KIN30      ZXF      //左旋阀
                      #define  DJU_KIN31      YXF      //右旋阀
                      #define  DJU_KIN32      XZGSF    //旋转高速阀

                      #define  DJU_KIN33      KSD      //开锁灯
                      #define  DJU_KIN34      BSD      //闭锁灯
                      #define  DJU_KIN35      ZXD      //着箱灯
                      #define  DJU_KIN36      ZXPLD    //着箱旁路指示灯
/******************************************************************************/
#endif	/* APP_CHAR_H */



