#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "APP_FONT.h"

/*******************************��������ʾ*************************************/

//�����ѹ
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//�����¶�
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};

/******************************************************************************/
//���������
__prog__ const unsigned char * DJKZQ[] = {BMP_DJ, BMP_KZQ, 0};
//���ת��
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//�������
__prog__ const unsigned char * DJDL[] = {BMP_DJ, BMP_DL, 0};
//����¶�
__prog__ const unsigned char * DJWD[] = {BMP_DJ, BMP_Wendu, 0};
//���ת��
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//�����ѹ
__prog__ const unsigned char * DJDY[] = {BMP_DJ, BMP_DY, 0};
/********************************�˵�ѡ��**************************************/
//�Ǳ�ϵͳ��Ϣ
__prog__ const unsigned char * IC_SYSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//�����Ϣ
__prog__ const unsigned char * Battery_SYSTEM[] = {BMP_Battery, BMP_Message, 0};
//���ϵͳ��Ϣ
__prog__ const unsigned char * MOTO_SYSTEM[] = {BMP_MOTO, BMP_STSTEM, BMP_Message, 0};
//����ϵͳ��Ϣ
__prog__ const unsigned char * AIR_SYSTEM[] = {BMP_DMQ, BMP_STSTEM, BMP_Message, 0};
//�ͱ�ϵͳ��Ϣ
__prog__ const unsigned char * OIL_SYSTEM[] = {BMP_DMY, BMP_STSTEM, BMP_Message, 0};
//��ع���ϵͳ��Ϣ
__prog__ const unsigned char * BMS_SYSTEM[] = {BMP_Battery, BMP_Manage, BMP_STSTEM, BMP_Message, 0};
//�յ�ϵͳ��Ϣ
//__prog__ const unsigned char * OIL_STSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};
//��ѹϵͳ��Ϣ
__prog__ const unsigned char * HV_SYSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};

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
//�͵�
__prog__ const unsigned char * DD[] = {BMP_Di, BMP_Dang,0};
//�ߵ�
__prog__ const unsigned char * GD[] = {BMP_Gao, BMP_Dang,0};
//ĸ�ߵ�ѹ����
__prog__ const unsigned char * MXDYBJ[] = {BMP_Muxian, BMP_DY, BMP_Baojing, 0};
//��ص�������
__prog__ const unsigned char * DCDLGD[] = {BMP_DC, BMP_Dianliang, BMP_Guodi, 0};
//��ص���������ͣ��
__prog__ const unsigned char * DCDLBZQTC[] = {BMP_DC, BMP_Dianliang, BMP_Buzu, BMP_Qingtingche, 0};
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
//Ԥ��Ӵ���
__prog__ const unsigned char * YCJCQ[] = {BMP_Yuchong, BMP_Jiechuqi,0};
//��˪�Ӵ���
__prog__ const unsigned char * CSJCQ[] = {BMP_Chushuang, BMP_Jiechuqi,0};
//����״̬
__prog__ const unsigned char * BXZT[] = {BMP_Baoxian, BMP_Zhuangtai,0};
/******************************************************************************/
/*******************************�������ɼ�*************************************/
//���ȿ���
__prog__ const unsigned char * LBKG[] = {BMP_Laba, BMP_IC_Kaiguan, 0};
//ǰ��ƿ���
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
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
/******************************************************************************/

/******************************ģ�����״̬************************************/
//�űõ�Դ
__prog__ const unsigned char * MBDY[] = {BMP_Men, BMP_Dianyuan, 0};
//�ƶ���Դ
__prog__ const unsigned char * ZDDY[] = {BMP_Zhidong, BMP_Dianyuan, 0};
//�����Դ
__prog__ const unsigned char * MLDY[] = {BMP_Men, BMP_Ling, BMP_Dianyuan, 0};
//���µ�Դ
__prog__ const unsigned char * CWDY[] = {BMP_Cangmen, BMP_Wendu, BMP_Dianyuan, 0};
//���ӵ�Դ
__prog__ const unsigned char * DSDY[] = {BMP_Dianshi, BMP_Dianyuan, 0};
//�յ���Դ
__prog__ const unsigned char * KTDY[] = {BMP_Kongtiao, BMP_Dianyuan, 0};
//ǰ������
__prog__ const unsigned char * QWDSC[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//��ǰ������
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//��ǰ������
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//ǰ�ſ����
__prog__ const unsigned char * QMKSC[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Output, 0};
//���ſ����
__prog__ const unsigned char * ZMKSC[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Output, 0};
//��Զ������
__prog__ const unsigned char * ZYGDSC[] = {BMP_IC_Zuo, BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//��Զ������
__prog__ const unsigned char * YYGDSC[] = {BMP_IC_You, BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//���������
__prog__ const unsigned char * ZJGDSC[] = {BMP_IC_Zuo, BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//�ҽ�������
__prog__ const unsigned char * YJGDSC[] = {BMP_IC_You, BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, 0, 0};
//��������
__prog__ const unsigned char * HWDSC[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, 0};
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
/******************************************************************************/
/******************************************************************************/
//�������
__prog__ const unsigned char * DLDC[] = {BMP_Dongli,BMP_DC,0};
//��ش�������
__prog__ const unsigned char * DCCLSL[] = {BMP_DC,BMP_Chuanlian,BMP_Shuliang,0};
//��ز�������
__prog__ const unsigned char * DCBLSL[] = {BMP_DC,BMP_Binglian,BMP_Shuliang,0};
//��ض����
__prog__ const unsigned char * DCEDRL[] = {BMP_DC,BMP_Eding,BMP_Rongliang,0};
//���ʣ������
__prog__ const unsigned char * DCSYRL[] = {BMP_DC,BMP_Shengyu,BMP_Rongliang,0};
//��ر����ȼ�
__prog__ const unsigned char * DCBJDJ[] = {BMP_DC,BMP_Baojing,BMP_Dengji,0};
//һ�����ϴ���
__prog__ const unsigned char * YJGZDM[] = {BMP_Yiji,BMP_Guzhang,BMP_Code,0};
//�������ϴ���
__prog__ const unsigned char * EJGZDM[] = {BMP_Erji,BMP_Guzhang,BMP_Code,0};
//�������ϴ���
__prog__ const unsigned char * SJGZDM[] = {BMP_Sanji,BMP_Guzhang,BMP_Code,0};
//��Եĸ�ߵ�ѹ
__prog__ const unsigned char * JYMXDY[] = {BMP_Jueyuan,BMP_Muxian,BMP_DY,0};
//��Ե���ϵȼ�
__prog__ const unsigned char * JYGZDJ[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Dengji,0};
//��Ե����״̬
__prog__ const unsigned char * JYGZZT1[] = {BMP_Jueyuan,BMP_Guzhang,BMP_Zhuangtai,0};
//��Ե����״̬
__prog__ const unsigned char * JYGZZT2[] = {BMP_Jueyuan,BMP_Gongzuo,BMP_Zhuangtai,0};
//���ֱ����ȼ�
__prog__ const unsigned char * HZBJDJ[] = {BMP_Huozai,BMP_Baojing,BMP_Dengji,0};
//���ֱ������ϴ���
__prog__ const unsigned char * HZBJGZDM[] = {BMP_Huozai,BMP_Baojing,BMP_Guzhang,BMP_Code,0};
/******************************************************************************/
#endif	/* APP_CHAR_H */

