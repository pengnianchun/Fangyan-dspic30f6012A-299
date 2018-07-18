#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "FONT.h"

/*******************************��������ʾ*************************************/

//�����ѹ
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//�����¶�
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};
//���ת��
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//���ת��
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//����¶�
__prog__ const unsigned char * DJWD[] = {BMP_DJ, BMP_Wendu, 0};
//���������
__prog__ const unsigned char * DJKZQ[] = {BMP_DJ, BMP_KZQ, 0};

/******************************************************************************/

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
__prog__ const unsigned char * HV_SYSTEM[] = {BMP_Gaoya, BMP_STSTEM, BMP_Message, 0};
//��̥ϵͳ��Ϣ
__prog__ const unsigned char * Luntai_SYSTEM[] = {BMP_TAIYA, BMP_STSTEM, BMP_Message, 0};

/******************************************************************************/

/*******************************�Ӳ˵�*****************************************/
__prog__ const unsigned char * GD[] = {BMP_Guo, BMP_Di, 0};

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

/******************************************************************************/

/*******************************�Ǳ������ɼ�*********************************/

//ǰ��ƿ���
__prog__ const unsigned char * QWDKG[] = {BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//����ƿ���
__prog__ const unsigned char * HWDKG[] = {BMP_IC_Hou, BMP_IC_Wu, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//С�ƿ���
__prog__ const unsigned char * XDKG[] = {BMP_Xiao, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ǰ�ſ�����
__prog__ const unsigned char * QMKKG[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//ǰ�Źؿ���
__prog__ const unsigned char * QMGKG[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//���ſ�����
__prog__ const unsigned char * ZMKKG[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//���Źؿ���
__prog__ const unsigned char * ZMGKG[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//ǰ��Ӧ��������
//Զ��ƿ���
__prog__ const unsigned char * YGDKG[] = {BMP_IC_Yuan, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//����ƿ���
__prog__ const unsigned char * JGDKG[] = {BMP_IC_Jin, BMP_IC_Guang, BMP_IC_Deng, BMP_IC_Kaiguan, 0};
//ASR
//__prog__ const unsigned char * ASR[] = {BMP_a, BMP_s, BMP_r, BMP_Guzhang, 0};
//ABS
//__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s, BMP_Guzhang, 0};
__prog__ const unsigned char * ABS[] = {BMP_a, BMP_b, BMP_s, Bmp_JCe, 0};//ABS���
//START��
//__prog__ const unsigned char * START[] = {BMP_s, BMP_t, BMP_a, BMP_r, BMP_t, BMP_Dang, 0};
//Σ�ձ����ź�
__prog__ const unsigned char * WXBJKG[] = {BMP_Weixian, BMP_Baojing, BMP_IC_Kaiguan, 0};
//פ���ƶ�����
__prog__ const unsigned char * ZCZDKG[] = {BMP_Zhuche, BMP_Zhidong, BMP_IC_Kaiguan, 0};
//���忪��
__prog__ const unsigned char * MLKG[] = {BMP_Men, BMP_Ling, BMP_IC_Kaiguan, 0};
//SERVICE
//__prog__ const unsigned char * SERVICE[] = {BMP_s, BMP_e, BMP_r,BMP_v, BMP_i, BMP_c,BMP_e, BMP_Qingqiu, 0};

/******************************************************************************/


/******************************ǰģ�鿪��״̬**********************************/
//��ַѡ��
__prog__ const unsigned char * DZXZ[] = {BMP_Dizhi, BMP_Xuanze,0};
//�汾��
__prog__ const unsigned char * BBH[] = {BMP_Banben, BMP_Hao,0};

/******************************************************************************/

/******************************ǰģ�����״̬**********************************/
//��ǰ������
__prog__ const unsigned char * ZQWDSC[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
//��ǰ������
__prog__ const unsigned char * YQWDSC[] = {BMP_IC_You, BMP_IC_Qian, BMP_IC_Wu, BMP_IC_Deng, 0};
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

/******************************************************************************/

/******************************��ģ�����״̬**********************************/
//ǰ�ſ���ŷ�
__prog__ const unsigned char * QMKDCF[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Diancifa, 0};
//ǰ�Źص�ŷ�
__prog__ const unsigned char * QMGDCF[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_Diancifa, 0};
//���ſ���ŷ�
__prog__ const unsigned char * ZMKDCF[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Diancifa, 0};
//���Źص�ŷ�
__prog__ const unsigned char * ZMGDCF[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_Diancifa, 0};
//ǰ��Ӧ����
__prog__ const unsigned char * QMYJF[] = {BMP_IC_Qian, BMP_Men, BMP_Yingjifa,0};
//����Ӧ����
__prog__ const unsigned char * ZMYJF[] = {BMP_Zhong, BMP_Men, BMP_Yingjifa,0};
/******************************************************************************/

/******************************��ģ�鿪��״̬**********************************/
//ǰ�ſ��ź�
__prog__ const unsigned char * QMKXH[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Xinhao, 0};
//���ſ��ź�
__prog__ const unsigned char * ZMKXH[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Xinhao, 0};

/******************************************************************************/

/******************************��ģ�����״̬**********************************/


/******************************************************************************/

/******************************��ģ�鿪��״̬**********************************/
//��ǰĦ��Ƭ
__prog__ const unsigned char * ZQMCQ[] = {BMP_IC_Zuo, BMP_IC_Qian, BMP_Mocapian, 0};
//��ǰĦ��Ƭ
__prog__ const unsigned char * YQMCQ[] = {BMP_IC_You, BMP_IC_Qian, BMP_Mocapian,0};


/******************************************************************************/
/*********************************���״̬*************************************/
//���ֱ����ѹ
__prog__ const unsigned char * DJZLDY[] = {BMP_DJ, BMP_Zhiliu, BMP_DY,0};
//���ֱ������
__prog__ const unsigned char * DJZLDL[] = {BMP_DJ, BMP_Zhiliu, BMP_DL,0};
//�������״̬
__prog__ const unsigned char * DJGZZT[] = {BMP_DJ, BMP_Gongzuo, BMP_Zhuangtai,0};
//�������ϴ���
__prog__ const unsigned char * ZCGZDM[] = {BMP_Zhengche, BMP_Guzhang, BMP_Code,0};
/******************************************************************************/

/******************************��ģ�鿪��״̬**********************************/


__prog__ const unsigned char * ZLBJ[] = {BMP_Zhongli, BMP_Baojing,0};//��������
__prog__ const unsigned char * DSBJ[] = {Bmp_DSu, BMP_Baojing,0};//���ٱ���

__prog__ const unsigned char * Bmp_AQDai[] = {Bmp_An, Bmp_Quan, Bmp_Dai, 0};//��ȫ��
__prog__ const unsigned char * Bmp_AQMen[] = {Bmp_An, Bmp_Quan, BMP_Men, 0};//��ȫ��
__prog__ const unsigned char * Bmp_JYDZ[] = {BMP_Jueyuan, Bmp_Dian, BMP_Zu, 0};//��Ե����
__prog__ const unsigned char * Bmp_KR[] = {BMP_k, BMP_Omu, 0};//KR

/******************************��ع��ϱ���*********************************/
__prog__ const unsigned char * Bmp_Display_bj_13[] = {BMP_Yuchong, BMP_Chaoshi,0};//Ԥ�䳬ʱ
__prog__ const unsigned char * Bmp_Display_bj_14[] = {BMP_Xu, BMP_DC,BMP_DY,BMP_Di,0};//���ص�ѹ��
__prog__ const unsigned char * Bmp_Display_bj_15[] = {BMP_s,  BMP_o,BMP_c,BMP_Guzhang,0};//SOC����
__prog__ const unsigned char * Bmp_Display_bj_16[] = {BMP_Dan,BMP_Ti, BMP_DY,BMP_Guzhang,0};//�����ѹ����
__prog__ const unsigned char * Bmp_Display_bj_17[] = {BMP_Zong, BMP_DY,BMP_Guzhang,0};//�ܵ�ѹ����
__prog__ const unsigned char * Bmp_Display_bj_18[] = {BMP_Wendu, BMP_Guzhang,0};//�¶ȹ���
__prog__ const unsigned char * Bmp_Display_bj_19[] = {BMP_s, BMP_o,BMP_c,BMP_Guo,BMP_Di,0};//SOC����
__prog__ const unsigned char * Bmp_Display_bj_20[] = {BMP_Jueyuan, BMP_Guzhang,0};//��Ե����
__prog__ const unsigned char * Bmp_Display_bj_21[] = {BMP_DL, BMP_Guzhang,0};//��������
__prog__ const unsigned char * Bmp_Display_bj_22[] = {BMP_DC, BMP_Junheng,BMP_Guzhang,0};//��ؾ������
__prog__ const unsigned char * Bmp_Display_bj_23[] = {BMP_Husuo, BMP_Baojing,0};//��������
__prog__ const unsigned char * Bmp_Display_bj_24[] = {Bmp_please,Bmp_ZQue,Bmp_TChe,0};//����ȷͣ��
__prog__ const unsigned char * Bmp_Display_bj_25[] = {Bmp_An, Bmp_Quan, Bmp_Dai,Bmp_WXi,0};//��ȫ��δϵ
__prog__ const unsigned char * Bmp_Display_bj_26[] = {Bmp_An, Bmp_Quan, BMP_Men, BMP_Kai, 0};//��ȫ�ſ�

/******************************************************************************/

#endif	/* APP_CHAR_H */

