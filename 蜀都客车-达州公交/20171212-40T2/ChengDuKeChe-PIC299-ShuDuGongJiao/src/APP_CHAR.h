#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "APP_FONT.h"

/*******************************��������ʾ*************************************/

//�����ѹ
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//�����¶�
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};
//��ߵ�ѹ
__prog__ const unsigned char * ZGDY[] = {BMP_Zui, BMP_Gao, BMP_DY, 0};
//��͵�ѹ
__prog__ const unsigned char * ZDDY[] = {BMP_Zui, BMP_Di, BMP_DY, 0};
//����¶�
__prog__ const unsigned char * ZGWD[] = {BMP_Zui, BMP_Gao, BMP_Wendu, 0};
//ƽ���¶�
__prog__ const unsigned char * PJWD[] = {BMP_Pingjun, BMP_Wendu, 0};
//���ݵ�ѹ
__prog__ const unsigned char * DRDY[] = {BMP_DC, BMP_Rongliang,BMP_DY, 0};
//SOE
__prog__ const unsigned char * SOE[] = {BMP_s, BMP_o, BMP_e, 0};
//���ĸ�ߵ�ѹ
__prog__ const unsigned char * DJMXDY[] = {BMP_DJ, BMP_Muxian, BMP_DY, 0};
//���ĸ�ߵ���
__prog__ const unsigned char * DJMXDL[] = {BMP_DJ, BMP_Muxian, BMP_DL, 0};
//���ת��
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//��ص���
__prog__ const unsigned char * DCDL[] = {BMP_DC, BMP_DL, 0};
//���ת��
__prog__ const unsigned char * SCZS[] = {BMP_Output, BMP_Zhuansu, 0};
//EV�ź�
__prog__ const unsigned char * EV[] = {BMP_e, BMP_v,BMP_Xinhao, 0};
//ͣ��״̬
__prog__ const unsigned char * TJZT[] = {BMP_Tingzhi, BMP_Jiyou,BMP_Zhuangtai, 0};
//�ƶ�̤��
__prog__ const unsigned char * ZDTB[] = {BMP_Zhidong, BMP_Taban, 0};
//����̤��
__prog__ const unsigned char * YMTB[] = {BMP_Youmen, BMP_Taban, 0};
/******************************************************************************/

/********************************�˵�ѡ��**************************************/
//�Ǳ�ϵͳ��Ϣ
__prog__ const unsigned char * IC_SYSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//�����Ϣ
__prog__ const unsigned char * Battery_SYSTEM[] = {BMP_Battery, BMP_Message, 0};
//���ϵͳ��Ϣ
__prog__ const unsigned char * MOTO_SYSTEM[] = {BMP_MOTO, BMP_STSTEM, BMP_Message, 0};
//��ع���ϵͳ��Ϣ
__prog__ const unsigned char * BMS_SYSTEM[] = {BMP_Battery, BMP_Manage, BMP_STSTEM, BMP_Message, 0};
//�յ�ϵͳ��Ϣ
//__prog__ const unsigned char * OIL_STSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//��ѹϵͳ��Ϣ
__prog__ const unsigned char * HV_SYSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//������Ϣ
__prog__ const unsigned char * PDH_SYSTEM[] = {BMP_PEIDIANHE, BMP_Message, 0};
//��������Ϣ
__prog__ const unsigned char * ENG_SYSTEM[] = {BMP_Engine, BMP_Message, 0};

/******************************************************************************/

/******************************CAN����*****************************************/
//��ص�ѹ��
__prog__ const unsigned char * DCDYD[] = {BMP_DC, BMP_DY, BMP_Di, 0};
//SOC
__prog__ const unsigned char * SOC[] = {BMP_s, BMP_o, BMP_c, 0};
//CAN
__prog__ const unsigned char * CHAR_CAN[] = {BMP_c, BMP_a, BMP_n, 0};
//���ͨѶ�쳣
//__prog__ const unsigned char * CDTXYC[] = {BMP_Chongdian, BMP_Tongxun, BMP_Yichang, 0};
//ǰ��ģ������
__prog__ const unsigned char * QBMKLX[] = {BMP_Qianbu, BMP_Mokuai, BMP_Lixian, 0};
//����ģ������
__prog__ const unsigned char * DBMKLX[] = {BMP_Dingbu, BMP_Mokuai, BMP_Lixian, 0};
//��ģ������
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
//��������
__prog__ const unsigned char * CLYS[] = {BMP_Chesu, BMP_Liang, BMP_Yi, BMP_Suo, 0};
//����δ��
__prog__ const unsigned char * CLWS[] = {BMP_Chesu, BMP_Liang, BMP_Wei, BMP_Suo, 0};
//����״̬
__prog__ const unsigned char * SCZT[] = {BMP_Suo, BMP_Chesu, BMP_Zhuangtai, 0};
//����
__prog__ const unsigned char * YS[] = {BMP_Yi, BMP_Suo,0};
//δ��
__prog__ const unsigned char * WS[] = {BMP_Wei, BMP_Suo,0};
//��ѹ���
__prog__ const unsigned char * GYDC[] = {BMP_Gao, BMP_Yali, BMP_DC, 0};
//���ϵͳ����
__prog__ const unsigned char * DJXTGZ[] = {BMP_DJ, BMP_System, BMP_Guzhang, 0};
//�������
__prog__ const unsigned char * DCLX[] = {BMP_DC, BMP_Lixian, 0};
//�������
__prog__ const unsigned char * DJLX[] = {BMP_DJ, BMP_Lixian, 0};
//����������
__prog__ const unsigned char * BSXLX[] = {BMP_Biansuxiang, BMP_Lixian, 0};
//����������
__prog__ const unsigned char * FDJLX[] = {BMP_Fadongji, BMP_Lixian, 0};
//��������
__prog__ const unsigned char * DRLX[] = {BMP_DC, BMP_Rongliang, BMP_Lixian, 0};
//����ϵͳ����
__prog__ const unsigned char * CDXTGZ[] = {BMP_Chuandong, BMP_System, BMP_Guzhang, 0};
//��϶�������
__prog__ const unsigned char * HHDLGZ[] = {BMP_Hunhe, BMP_Dongli, BMP_Guzhang, 0};
//���������
__prog__ const unsigned char * BSXGZ[] = {BMP_Biansuxiang, BMP_Guzhang, 0};
//HCU����
__prog__ const unsigned char * HCUGZ[] = {BMP_h,BMP_c,BMP_u, BMP_Guzhang, 0};
//����ת�����
__prog__ const unsigned char * ZLZXGZ[] = {BMP_Zhuli,BMP_IC_Zhuanxiang, BMP_Guzhang, 0};
//�������
__prog__ const unsigned char * DJGZ[] = {BMP_DJ, BMP_Guzhang, 0};
//��ع���
__prog__ const unsigned char * DCGZ[] = {BMP_DC, BMP_Guzhang, 0};
/******************************************************************************/

/******************************���ϵͳ��Ϣ*****************************************/
//������ǰ״̬
__prog__ const unsigned char * ZCZT[] = {BMP_Zhengche, BMP_Zhuangtai,0};
//���ϵͳ״̬
__prog__ const unsigned char * DJXTZT[] = {BMP_DJ,BMP_System, BMP_Zhuangtai,0};
//ϵͳ����״̬
__prog__ const unsigned char * XTHSZT[] = {BMP_System,BMP_Husuo, BMP_Zhuangtai,0};
//�����Ӵ���
__prog__ const unsigned char * ZZJCQ[] = {BMP_Zhu,BMP_Zheng, BMP_Jiechuqi,0};
//���ת���ź�
__prog__ const unsigned char * DJZSXH[] = {BMP_DJ, BMP_Zhuansu, BMP_Xinhao,0};
//���ת���ź�
__prog__ const unsigned char * DJZZXH[] = {BMP_DJ, BMP_Zhuanju, BMP_Xinhao,0};
//���ĸ�ߵ�ѹ�ź�״̬
__prog__ const unsigned char * DJMXDYXHZT[] = {BMP_DJ, BMP_Muxian, BMP_DY,BMP_Xinhao, BMP_Zhuangtai,0};
//���ĸ�ߵ����ź�״̬
__prog__ const unsigned char * DJMXDLXHZT[] = {BMP_DJ, BMP_Muxian, BMP_DL,BMP_Xinhao, BMP_Zhuangtai,0};
//��ؽӴ���
__prog__ const unsigned char * DCJCQ[] = {BMP_DC, BMP_Jiechuqi,0};
//�ƶ�̤��״̬
__prog__ const unsigned char * ZDTBZT[] = {BMP_Zhidong, BMP_Taban, BMP_Zhuangtai,0};
//����̤��״̬
__prog__ const unsigned char * JSTBZT[] = {BMP_Youmen, BMP_Taban, BMP_Zhuangtai,0};
//����¶��ź�״̬
__prog__ const unsigned char * DJWDXHZT[] = {BMP_DJ, BMP_Wendu, BMP_Xinhao,BMP_Zhuangtai,0};
//����������¶��ź�
__prog__ const unsigned char * DJKZQWDXHZT[] = {BMP_DJ,BMP_KZQ, BMP_Wendu, BMP_Xinhao,0};
//��˪�Ӵ���
__prog__ const unsigned char * CSJCQ[] = {BMP_Chushuang, BMP_Jiechuqi,0};
//������ת��
__prog__ const unsigned char * FDJZS[] = {BMP_Fadongji, BMP_Zhuansu,0};
//����������
__prog__ const unsigned char * FDJQH[] = {BMP_Fadongji, BMP_Qihao,0};
//������ˮ��
__prog__ const unsigned char * FDJSW[] = {BMP_Fadongji, BMP_Shuiwen,0};
//����������
__prog__ const unsigned char * FDJYM[] = {BMP_Fadongji, BMP_Youmen,0};
//����ѹ��
__prog__ const unsigned char * JYYL[] = {BMP_Jiyou,BMP_Yali,0};
//�����¶�
__prog__ const unsigned char * JQWD[] = {BMP_Jinqi,BMP_Wendu,0};
//����ѹ��
__prog__ const unsigned char * JQYL[] = {BMP_Jinqi,BMP_Yali,0};
//��ѹѹ��
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
//�����¶�
__prog__ const unsigned char * PDHWD[] = {BMP_Peidianhe,BMP_Wendu,0};
//���е���
__prog__ const unsigned char * PDHDL[] = {BMP_Peidianhe,BMP_DL,0};
//��Դ״̬
__prog__ const unsigned char * DYZT[] = {BMP_Dianyuan,BMP_Zhuangtai,0};
/******************************************************************************/
/*******************************�������ɼ�*************************************/
//���ȿ���
__prog__ const unsigned char * LBKG[] = {BMP_Laba, BMP_IC_Kaiguan, 0};
//ǰ��ƿ���
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ADD
__prog__ const unsigned char * ADD[] = {BMP_a, BMP_d, BMP_d,0};
//����ƿ���
__prog__ const unsigned char * HWDKG[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//С�ƿ���
__prog__ const unsigned char * XDKG[] = {BMP_Xiao, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ǰ�ſ��ź�
__prog__ const unsigned char * QMKXH[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Xinhao, 0};
//���ſ��ź�
__prog__ const unsigned char * ZMKXH[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Xinhao, 0};
//Ӧ��������
__prog__ const unsigned char * YJFBJ[] = {BMP_Yingjifa, BMP_Baojing,0};
//Զ��ƿ���
__prog__ const unsigned char * YGDKG[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//����ƿ���
__prog__ const unsigned char * JGDKG[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ASR
__prog__ const unsigned char * ASR[] = {BMP_a, BMP_s, BMP_r, BMP_Guzhang, 0};
//ABS
__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s, BMP_Guzhang, 0};
//START��
__prog__ const unsigned char * START[] = {BMP_s, BMP_t, BMP_a, BMP_r, BMP_t, BMP_Dang, 0};
//Σ�ձ����ź�
__prog__ const unsigned char * WXBJKG[] = {BMP_Weixian, BMP_Baojing, BMP_IC_Kaiguan, 0};
//פ���ƶ�����
__prog__ const unsigned char * ZCZDKG[] = {BMP_Zhuche, BMP_Zhidong, BMP_IC_Kaiguan, 0};
//���忪��
__prog__ const unsigned char * MLKG[] = {BMP_Men, BMP_Ling, BMP_IC_Kaiguan, 0};
//SERVICE
__prog__ const unsigned char * SERVICE[] = {BMP_s, BMP_e, BMP_r,BMP_v, BMP_i, BMP_c,BMP_e, BMP_Qingqiu, 0};
//����������
__prog__ const unsigned char * YWBJKG[] = {BMP_Yanwu, BMP_Baojing, BMP_IC_Kaiguan, 0};
//��ȫ������
__prog__ const unsigned char * AQDBJ[] = {BMP_Anquandai, BMP_Baojing,0};
//���ƿ���
__prog__ const unsigned char * GGKG[] = {BMP_Guanggao, BMP_IC_Kaiguan,0};
//��������
__prog__ const unsigned char * ZLBJ[] = {BMP_Zhongli, BMP_Baojing,0};
//������
__prog__ const unsigned char * JZRH[] = {BMP_Jizhong, BMP_Runhua, 0};
//���1����
__prog__ const unsigned char * XD1KG[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[1], BMP_IC_Kaiguan, 0};
//���2����
__prog__ const unsigned char * XD2KG[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[2], BMP_IC_Kaiguan, 0};
//·�ƿ���
__prog__ const unsigned char * LPKG[] = {BMP_Lupai, BMP_IC_Kaiguan, 0};
//�ƶ�����
__prog__ const unsigned char * ZDKG[] = {BMP_Zhidong, BMP_IC_Kaiguan, 0};
//���ƿ���
__prog__ const unsigned char * DDKG[] = {BMP_Dingbu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ɢ����1����
__prog__ const unsigned char * SRQ1KG[] = {BMP_Sanreqi, BMP_SZ_2[1], 0};
//ɢ����2����
__prog__ const unsigned char * SRQ2KG[] = {BMP_Sanreqi, BMP_SZ_2[2], 0};
//TV����
__prog__ const unsigned char * TVKG[] = {BMP_t, BMP_v, BMP_IC_Kaiguan, 0};
//���ȿ���
__prog__ const unsigned char * FSKG[] = {BMP_Fengshan, BMP_IC_Kaiguan, 0};
//���˱���
__prog__ const unsigned char * KLBJ[] = {BMP_Konglv, BMP_Baojing, 0};
//������
__prog__ const unsigned char * HQD[] = {BMP_IC_Hou, BMP_Qidong, 0};
/******************************************************************************/

/******************************ģ�����״̬************************************/
//�űõ�Դ
__prog__ const unsigned char * MBDY[] = {BMP_Men, BMP_Dianyuan, 0};
//�ƶ���Դ
//__prog__ const unsigned char * ZDDY[] = {BMP_Zhidong, BMP_Dianyuan, 0};
//�����Դ
__prog__ const unsigned char * MLDY[] = {BMP_Men, BMP_Ling, BMP_Dianyuan, 0};
//���µ�Դ
__prog__ const unsigned char * CWDY[] = {BMP_Cangmen, BMP_Wendu, BMP_Dianyuan, 0};
//���ӵ�Դ
__prog__ const unsigned char * DSDY[] = {BMP_Dianshi, BMP_Dianyuan, 0};
//�յ���Դ
__prog__ const unsigned char * KTDY[] = {BMP_Kongtiao, BMP_Dianyuan, 0};
//ǰ������
__prog__ const unsigned char * QWDSC[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//��������
__prog__ const unsigned char * HWDSC[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, 0};
//��ǰ������
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//��ǰ������
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//ǰ�ſ����
__prog__ const unsigned char * QMKSC[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Output, 0};
//ǰ�Ź����
__prog__ const unsigned char * QMGSC[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_Output, 0};
//���ſ����
__prog__ const unsigned char * ZMKSC[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Output, 0};
//���Ź����
__prog__ const unsigned char * ZMGSC[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_Output, 0};
//��Զ������
__prog__ const unsigned char * ZYGDSC[] = {BMP_IC_Zuo, BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//��Զ������
__prog__ const unsigned char * YYGDSC[] = {BMP_IC_You, BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//���������
__prog__ const unsigned char * ZJGDSC[] = {BMP_IC_Zuo, BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//�ҽ�������
__prog__ const unsigned char * YJGDSC[] = {BMP_IC_You, BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//�������
__prog__ const unsigned char * DCSC[] = {BMP_Daoche, BMP_Output, 0};
//������
__prog__ const unsigned char * GGSC[] = {BMP_Guanggao, BMP_Output,0};
//ǰ�ŵ����
__prog__ const unsigned char * QMDSC[] = {BMP_IC_Qian, BMP_Men, BMP_IC_Deng, BMP_Output, 0};
//���ŵ����
__prog__ const unsigned char * ZMDSC[] = {BMP_Zhong, BMP_Men, BMP_IC_Deng, BMP_Output, 0};
//�������
__prog__ const unsigned char * LBSC[] = {BMP_Laba,  BMP_Output, 0};
//�ƶ������
__prog__ const unsigned char * ZDDSC[] = {BMP_Zhidong,  BMP_Output, 0};
//���ȵ�Դ
__prog__ const unsigned char * FSDY[] = {BMP_Fengshan,  BMP_Dianyuan, 0};
//��ѹ��Դ
__prog__ const unsigned char * QYDY[] = {BMP_Qiya,  BMP_Dianyuan, 0};
//ǰ�ſ�����
__prog__ const unsigned char * QMKKG[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//���ſ�����
__prog__ const unsigned char * ZMKKG[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//ǰ�Źؿ���
__prog__ const unsigned char * QMGKG[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//���Źؿ���
__prog__ const unsigned char * ZMGKG[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//������ѹ����
__prog__ const unsigned char * FZQYBJ[] = {BMP_Fuzhu, BMP_Qiya, BMP_Baojing, 0};
//С��
__prog__ const unsigned char * XD[] = {BMP_Xiao, BMP_IC_Deng,0};
//λ�õ�
__prog__ const unsigned char * WZD[] = {BMP_Weizhi, BMP_IC_Deng,0};
//��������
__prog__ const unsigned char * QDQQ[] = {BMP_Qidong, BMP_Qingqiu,0};
//��Դ���
__prog__ const unsigned char * DYSC[] = {BMP_Dianyuan, BMP_Output,0};
//ǰ·��
__prog__ const unsigned char * QLP[] = {BMP_IC_Qian, BMP_Lupai,0};
//��·��
__prog__ const unsigned char * HLP[] = {BMP_IC_Hou,BMP_Lupai,0};
//TV1��Դ
__prog__ const unsigned char * TV1DY[] = {BMP_t, BMP_v, BMP_SZ_2[1], BMP_Dianyuan, 0};
//TV2��Դ
__prog__ const unsigned char * TV2DY[] = {BMP_t, BMP_v, BMP_SZ_2[2], BMP_Dianyuan, 0};
//�������
__prog__ const unsigned char * DDSC[] = {BMP_Dingbu, BMP_IC_Deng,BMP_Output, 0};
//���1���
__prog__ const unsigned char * XD1SC[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[1], BMP_Output, 0};
//���2���
__prog__ const unsigned char * XD2SC[] = {BMP_Xiang_BMS, BMP_IC_Deng, BMP_SZ_2[2], BMP_Output, 0};
//�����Ӵ���
__prog__ const unsigned char * QDJCQ[] = {BMP_Qidong, BMP_Jiechuqi, 0};
//�������1
__prog__ const unsigned char * FSSC1[] = {BMP_Fengshan, BMP_Output, BMP_SZ_2[1], 0};
//�������2
__prog__ const unsigned char * FSSC2[] = {BMP_Fengshan, BMP_Output, BMP_SZ_2[2], 0};
//�������3
__prog__ const unsigned char * FSSC3[] = {BMP_Fengshan, BMP_Output, BMP_SZ_2[3], 0};
//���������
__prog__ const unsigned char * DCDSC[] = {BMP_Daoche, BMP_IC_Deng, 0};
//ɢ����1
__prog__ const unsigned char * SRQ1[] = {BMP_Sanreqi, BMP_SZ_2[1], 0};
//ɢ����2
__prog__ const unsigned char * SRQ2[] = {BMP_Sanreqi, BMP_SZ_2[2], 0};
//�ſ��ź�
__prog__ const unsigned char * MKXH[] = {BMP_Men, BMP_Kai,BMP_Xinhao, 0};
//���������
__prog__ const unsigned char * FDJSC[] = {BMP_Fadongji, BMP_Output, 0};
/******************************************************************************/
/******************************************************************************/
//�������
__prog__ const unsigned char * DLDC[] = {BMP_Dongli,BMP_DC,0};
//��ر����ȼ�
__prog__ const unsigned char * DCBJDJ[] = {BMP_DC,BMP_Baojing,BMP_Dengji,0};
//��Եĸ�ߵ�ѹ
__prog__ const unsigned char * JYMXDY[] = {BMP_Jueyuan,BMP_Muxian,BMP_DY,0};
//��Ե���ϵȼ�
__prog__ const unsigned char * JYGZDJ[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Dengji,0};
//��Ե����״̬
__prog__ const unsigned char * JYGZZT1[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Zhuangtai,0};
//��Ե����״̬
__prog__ const unsigned char * JYGZZT2[] = {BMP_Jueyuan,BMP_Gongzuo,BMP_Zhuangtai,0};
/******************************************************************************/
#endif	/* APP_CHAR_H */

