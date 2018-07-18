#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "FONT.h"

/*******************************��������ʾ*************************************/
//�����ѹ
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//�����¶�
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};
//ECAS
__prog__ const unsigned char * ECAS[] = {BMP_e, BMP_c, BMP_a, BMP_s, 0};

/******************************************************************************/

/********************************�˵�ѡ��**************************************/
//�Ǳ�ϵͳ��Ϣ
__prog__ const unsigned char * IC_STSTEM[] = {BMP_IC, BMP_STSTEM, BMP_Message, 0};
//�����Ϣ
__prog__ const unsigned char * Battery_STSTEM[] = {BMP_Battery, BMP_Message, 0};
//���ϵͳ��Ϣ
__prog__ const unsigned char * MOTO_STSTEM[] = {BMP_MOTO, BMP_STSTEM, BMP_Message, 0};
//����ϵͳ��Ϣ
__prog__ const unsigned char * AIR_STSTEM[] = {BMP_DMQ, BMP_STSTEM, BMP_Message, 0};
//�ͱ�ϵͳ��Ϣ
__prog__ const unsigned char * OIL_STSTEM[] = {BMP_DMY, BMP_STSTEM, BMP_Message, 0};
//��ع���ϵͳ��Ϣ
__prog__ const unsigned char * BMS_STSTEM[] = {BMP_Battery, BMP_Manage, BMP_STSTEM, BMP_Message, 0};
//�յ�ϵͳ��Ϣ
__prog__ const unsigned char * Air_STSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};

/******************************************************************************/

/******************************CAN����*****************************************/
//��ص�ѹ��
__prog__ const unsigned char * DCDYD[] = {BMP_DC, BMP_DY, BMP_Di, 0};
//SOC
__prog__ const unsigned char * SOC[] = {BMP_s, BMP_o, BMP_c, 0};
//CAN
__prog__ const unsigned char * CHAR_CAN[] = {BMP_c, BMP_a, BMP_n, 0};
//���ͨѶ�쳣
__prog__ const unsigned char * CDTXYC[] = {BMP_Chongdian, BMP_Tongxun, BMP_Yichang, 0};
//ǰ��ģ������
__prog__ const unsigned char * QBMKLX[] = {BMP_Qianbu, BMP_Mokuai, BMP_Lixian, 0};
//����ģ������
__prog__ const unsigned char * DBMKLX[] = {BMP_Dingbu, BMP_Mokuai, BMP_Lixian, 0};
//��ģ������
__prog__ const unsigned char * HBMKLX[] = {BMP_Houbu, BMP_Mokuai, BMP_Lixian, 0};
//�յ�ϵͳ����
__prog__ const unsigned char * KTXTGZ[] = {BMP_Kongtiao, BMP_System, BMP_Guzhang, 0};

/******************************************************************************/

/*******************************�������ɼ�*************************************/
//��ȫ��
__prog__ const unsigned char * AQD[] = {BMP_Anquan, BMP_Dai, 0};
//ǰ��ƿ���
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//����ƿ���
__prog__ const unsigned char * HWDKG[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//С�ƿ���
__prog__ const unsigned char * XDKG[] = {BMP_Xiao, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ǰ�ſ�״̬
__prog__ const unsigned char * QMKZT[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Zhuangtai, 0};
//���ſ�״̬
__prog__ const unsigned char * ZMKZT[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Zhuangtai, 0};
//ǰ�ſ�����
__prog__ const unsigned char * QMKKG[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//���ſ�����
__prog__ const unsigned char * ZMKKG[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//ǰ�Źؿ���
__prog__ const unsigned char * QMGKG[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//���Źؿ���
__prog__ const unsigned char * ZMGKG[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//ǰ��Ӧ��������
//Զ��ƿ���
__prog__ const unsigned char * YGDKG[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//����ƿ���
__prog__ const unsigned char * JGDKG[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ASR
__prog__ const unsigned char * ASR[] = {BMP_a, BMP_s, BMP_r,BMP_Guzhang, 0};
//ABS
__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s,BMP_Guzhang, 0};
//Σ�ձ����ź�
__prog__ const unsigned char * WXBJKG[] = {BMP_Weixian, BMP_Baojing, BMP_IC_Kaiguan, 0};
//פ���ƶ�����
__prog__ const unsigned char * ZCZDKG[] = {BMP_Zhuche, BMP_Zhidong, BMP_IC_Kaiguan, 0};
//���忪��
__prog__ const unsigned char * MLKG[] = {BMP_Men, BMP_Ling, BMP_IC_Kaiguan, 0};
//ˮλ����
__prog__ const unsigned char * SWBJ[] = {BMP_Shuiwei, BMP_Baojing, 0};
//ECAS����
__prog__ const unsigned char * ECASTS[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Tisheng, 0};
//ECAS�½�
__prog__ const unsigned char * ECASXJ[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Xiajiang, 0};
//ECAS��λ
__prog__ const unsigned char * ECASFW[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Fuwei, 0};
//ECAS���
__prog__ const unsigned char * ECASCG[] = {BMP_e, BMP_c, BMP_a, BMP_s, BMP_Cegui, 0};
//������Ӧ����
__prog__ const unsigned char * ZLGYKG[] = {BMP_Zhongliganying, BMP_IC_Kaiguan, 0};
//START��
__prog__ const unsigned char * START[] = {BMP_s,BMP_t,BMP_a,BMP_r,BMP_t, BMP_Dang, 0};
//ACC����
__prog__ const unsigned char * ACCKG[] = {BMP_a,BMP_c,BMP_c,BMP_IC_Kaiguan, 0};
//ON��
__prog__ const unsigned char * ONHX[] = {BMP_o,BMP_n,BMP_Huanxing, 0};
/******************************************************************************/

/******************************ģ�����״̬************************************/

//��ǰ������
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//��ǰ������
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_Output, 0};
//ǰ�ſ����
__prog__ const unsigned char * QMKSC[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Output, 0};
//���ſ����
__prog__ const unsigned char * ZMKSC[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Output, 0};
//ǰ�Ź����
__prog__ const unsigned char * QMGSC[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_Output, 0};
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
//��������
__prog__ const unsigned char * HWDSC[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, 0};
//���е�
__prog__ const unsigned char * RXD[] = {BMP_Rixing, BMP_IC_Deng, 0};
//λ�õ�
__prog__ const unsigned char * WZD[] = {BMP_Weizhi, BMP_IC_Deng, 0};
//�ƶ���
__prog__ const unsigned char * ZDD[] = {BMP_Zhidong, BMP_IC_Deng, 0};
//��ε����Դ
__prog__ const unsigned char * YGDJDY[] = {BMP_IC_Yugua, BMP_DJ, BMP_Dianyuan, 0};
//Ͷ�һ���Դ
__prog__ const unsigned char * TBJDY[] = {BMP_Toubiji, BMP_Dianyuan, 0};
//�����󻬵�Դ
__prog__ const unsigned char * JZRHDY[] = {BMP_Jizhongrunhua, BMP_Dianyuan, 0};
//ǰ��̤��
__prog__ const unsigned char * QMTB[] = {BMP_IC_Qian, BMP_Men,BMP_Tabu, 0};
//ǰ��̤��
__prog__ const unsigned char * ZMTB[] = {BMP_Zhong, BMP_Men,BMP_Tabu, 0};
//���̵���
__prog__ const unsigned char * ZJDQ[] = {BMP_Zhu, BMP_Jidianqi, 0};
/******************************************************************************/
/******************************************************************************/
//���ת��
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//���ת��
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//ĸ�ߵ�ѹ
__prog__ const unsigned char * MXDY[] = {BMP_Muxian, BMP_DY, 0};
//ĸ�ߵ���
__prog__ const unsigned char * MXDL[] = {BMP_Muxian, BMP_DL, 0};
//�����ǰת��
__prog__ const unsigned char * DJDQZJ[] = {BMP_DJ,BMP_Dangqian, BMP_Zhuanju, 0};
//�����ǰת��
__prog__ const unsigned char * DJDQZS[] = {BMP_DJ,BMP_Dangqian, BMP_Zhuansu, 0};
//����¶�
__prog__ const unsigned char * DJWD[] = {BMP_DJ,BMP_Wendu, 0};
//�������¶�
__prog__ const unsigned char * KZQWD[] = {BMP_KZQ,BMP_Wendu, 0};
//����̤�忪��
__prog__ const unsigned char * YMTBKD[] = {BMP_Youmen,BMP_Taban,BMP_Kaidu, 0};
//�ƶ�̤�忪��
__prog__ const unsigned char * ZDTBKD[] = {BMP_Zhidong,BMP_Taban,BMP_Kaidu, 0};
//���ϴ���
__prog__ const unsigned char * GZDM[] = {BMP_Guzhang, BMP_Code, 0};
//���ϵȼ�
__prog__ const unsigned char * GZDJ[] = {BMP_Guzhang, BMP_Dengji, 0};
//��ŵ�״̬
__prog__ const unsigned char * CFDZT[] = {BMP_Chong, BMP_Fangdian, BMP_DC, BMP_Zhuangtai, 0};
//�յ����ϴ���
__prog__ const unsigned char * KTGZDM[] = {BMP_Kongtiao, BMP_Guzhang, BMP_Code, 0};
//�յ����״̬
__prog__ const unsigned char * KTDJZT[] = {BMP_Kongtiao, BMP_DJ, BMP_Zhuangtai, 0};
//�յ�����״̬
__prog__ const unsigned char * KTGZZT[] = {BMP_Kongtiao, BMP_Gongzuo, BMP_Zhuangtai, 0};
//����ʵ��
__prog__ const unsigned char * CWSJ[] = {BMP_Chesu, BMP_Wai, BMP_Shiji, 0};
//����ʵ��
__prog__ const unsigned char * CNSJ[] = {BMP_Chesu, BMP_Nei, BMP_Shiji, 0};
//�趨�¶�
__prog__ const unsigned char * SDWD[] = {BMP_Sheding, BMP_Wendu,0};
//ʵ�ʹ���
__prog__ const unsigned char * SJGL[] = {BMP_Shiji, BMP_Gonglv,0};
/******************************************************************************/
#endif	/* APP_CHAR_H */