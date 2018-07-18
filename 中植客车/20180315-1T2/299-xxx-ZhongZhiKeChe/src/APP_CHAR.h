#ifndef APP_CHAR_H
#define	APP_CHAR_H

#include "APP_FONT.h"

/*******************************��������ʾ*************************************/

//�����ѹ
__prog__ const unsigned char * DTDY[] = {BMP_Dan, BMP_Ti, BMP_DY, 0};
//�����¶�
__prog__ const unsigned char * DTWD[] = {BMP_Dan, BMP_Ti, BMP_Wendu, 0};

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
__prog__ const unsigned char * HV_SYSTEM[] = {BMP_Air, BMP_STSTEM, BMP_Message, 0};

/******************************************************************************/
//���߼��ָ��
__prog__ const unsigned char * XXJCZL[] = {BMP_Xia, BMP_Xian1, BMP_Jiance, BMP_Zhiling, 0};
/******************************CAN����*****************************************/
//��ص�ѹ��
__prog__ const unsigned char * DCDYD[] = {BMP_DC, BMP_DY, BMP_Di, 0};
//���ٱ���
__prog__ const unsigned char * CSBJ[] = {BMP_Chaosu, BMP_Baojing, 0};
//SOC
__prog__ const unsigned char * SOC[] = {BMP_s, BMP_o, BMP_c, 0};
//CAN
__prog__ const unsigned char * CHAR_CAN[] = {BMP_c, BMP_a, BMP_n, 0};
//SPN
__prog__ const unsigned char * CHAR_SPN[] = {BMP_s, BMP_p, BMP_n, 0};
//FMI
__prog__ const unsigned char * CHAR_FMI[] = {BMP_f, BMP_m, BMP_i, 0};
//VCU
__prog__ const unsigned char * VCU[] = {BMP_v, BMP_c, BMP_u, 0};
//VCUXTGZDM
__prog__ const unsigned char * VCUXTGZDM[] = {BMP_v, BMP_c, BMP_u, BMP_System, BMP_Guzhang, BMP_Code, 0};
//VCUXTGZ
__prog__ const unsigned char * VCUXTGZ[] = {BMP_v, BMP_c, BMP_u,BMP_System, BMP_Guzhang, 0};
//TCU
__prog__ const unsigned char * TCU[] = {BMP_t, BMP_c, BMP_u, 0};
//���ͨѶ�쳣
//__prog__ const unsigned char * CDTXYC[] = {BMP_Chongdian, BMP_Tongxun, BMP_Yichang, 0};
//ǰ��ģ������
__prog__ const unsigned char * QBMKLX[] = {BMP_Qianbu, BMP_Mokuai, BMP_Lixian, 0};
//����ģ������
__prog__ const unsigned char * DBMKLX[] = {BMP_Dingbu, BMP_Mokuai, BMP_Lixian, 0};
//��ģ������
__prog__ const unsigned char * HBMKLX[] = {BMP_Houbu, BMP_Mokuai, BMP_Lixian, 0};
//BMS
__prog__ const unsigned char * BMS[] = {BMP_b, BMP_m, BMP_s, 0};
//MCU
__prog__ const unsigned char * MCU[] = {BMP_m, BMP_c, BMP_u, 0};
//NM
__prog__ const unsigned char * NM[] = {BMP_n, BMP_m, 0};
//���ڳ���ֹ�г�
__prog__ const unsigned char * CHAGRE[] = {BMP_Charging,BMP_Che, 0};
//���ص�ѹ��
__prog__ const unsigned char * XDCDYD[] = {BMP_Xu, BMP_DC, BMP_DY, BMP_Di, 0};
//ABSXH
__prog__ const unsigned char * ABSXH[] = {BMP_a, BMP_b, BMP_s, BMP_Xinhao, 0};
//QMWG
__prog__ const unsigned char * QMWG[] = {BMP_IC_Qian, BMP_Men, BMP_Weiguan, 0};
//ZMWG
__prog__ const unsigned char * ZMWG[] = {BMP_Zhong, BMP_Men, BMP_Weiguan, 0};
//HCMWG
__prog__ const unsigned char * HCMWG[] = {BMP_IC_Hou, BMP_Cangmen, BMP_Men, BMP_Weiguan, 0};
//������ع���
__prog__ const unsigned char * DLDCGZ[] = {BMP_Dongli, BMP_DC, BMP_Guzhang, 0};
//���ֱ�������
__prog__ const unsigned char * HZBJGZ[] = {BMP_Huozai, BMP_Baojing, BMP_Guzhang, 0};
//��Ե����
__prog__ const unsigned char * JYGZ[] = {BMP_Jueyuan, BMP_Guzhang, 0};
//�������
__prog__ const unsigned char * DJGZ[] = {BMP_DJ, BMP_Guzhang, 0};
//���������
__prog__ const unsigned char * BSXGZ[] = {BMP_Biansuxiang, BMP_Guzhang, 0};
//DCDC����
__prog__ const unsigned char * DCDCGZ[] = {BMP_d, BMP_c,BMP_d, BMP_c, BMP_Guzhang, 0};
//�յ�����
__prog__ const unsigned char * KTGZ[] = {BMP_Kongtiao, BMP_Guzhang, 0};
//����̤�����
__prog__ const unsigned char * YMTBGZ[] = {BMP_Youmen, BMP_Taban, BMP_Guzhang, 0};
//�ƶ�̤�����
__prog__ const unsigned char * ZDTBGZ[] = {BMP_Zhidong, BMP_Taban, BMP_Guzhang, 0};
//ת��DCAC����
__prog__ const unsigned char * ZXDCACGZ[] = {BMP_IC_Zhuanxiang, BMP_d, BMP_c,BMP_a, BMP_c, BMP_Guzhang, 0};
//�ƶ�DCAC����
__prog__ const unsigned char * ZDDCACGZ[] = {BMP_Zhidong, BMP_d, BMP_c,BMP_a, BMP_c, BMP_Guzhang, 0};
//ABS����
__prog__ const unsigned char * ABSGZ[] = {BMP_a, BMP_b,BMP_s, BMP_Guzhang, 0};
//��������
__prog__ const unsigned char * HDGZ[] = {BMP_Huan, BMP_Dang, BMP_Guzhang, 0};
//Ԥ�����
__prog__ const unsigned char * YCGZ[] = {BMP_Yuchong, BMP_Guzhang, 0};
//VCU����
__prog__ const unsigned char * VCUJDQGZ[] = {BMP_v,BMP_c,BMP_u,BMP_Ji4,BMP_Dian,BMP_Qi, BMP_Guzhang, 0};
//DC-DC �¶ȱ���
__prog__ const unsigned char * DCDCWDGZ[] = {BMP_d, BMP_c, BMP_d, BMP_c, BMP_Wendu, BMP_Guzhang, 0};
//��ȴˮ�¹���
__prog__ const unsigned char * SWGZ[] = {BMP_Shuiwei,BMP_Wendu, BMP_Guzhang, 0};
//�¶Ȳ��챨��
__prog__ const unsigned char * WDCYBJ[] = {BMP_Wendu,BMP_Chayi, BMP_Baojing, 0};
//��ظ��±���
__prog__ const unsigned char * DCWDGBJ[] = {BMP_DC, BMP_Wendu, BMP_Gao, BMP_Baojing, 0};
//��ع�ѹ����
__prog__ const unsigned char * DCGYBJ[] = {BMP_DC, BMP_Guo, BMP_Ya, BMP_Baojing, 0};
//���Ƿѹ����
__prog__ const unsigned char * DCQYBJ[] = {BMP_DC, BMP_Qian, BMP_Ya, BMP_Baojing, 0};
//SOC �ͱ���
__prog__ const unsigned char * SOCDBJ[] = {BMP_s,BMP_o,BMP_c, BMP_Di, BMP_Baojing, 0};
//�����ع�ѹ����
__prog__ const unsigned char * DTDCGYBJ[] = {BMP_Dan,BMP_Ti,BMP_DC, BMP_Guo, BMP_Ya, BMP_Baojing, 0};
//������Ƿѹ����
__prog__ const unsigned char * DTDCQYBJ[] = {BMP_Dan,BMP_Ti,BMP_DC, BMP_Qian, BMP_Ya, BMP_Baojing, 0};
//SOC ���߱���
__prog__ const unsigned char * SOCGGBJ[] = {BMP_s,BMP_o,BMP_c, BMP_Guo,BMP_Gao, BMP_Baojing, 0};
//SOC ���䱨��
__prog__ const unsigned char * SOCTBBJ[] = {BMP_s,BMP_o,BMP_c, BMP_Tiaobian, BMP_Baojing, 0};
//��索��ϵͳ����
__prog__ const unsigned char * CDXTCNBJ[] = {BMP_Chong,BMP_Dian,BMP_System, BMP_Chuneng, BMP_Baojing, 0};
//��ص�����챨��
__prog__ const unsigned char * DCDTCYBJ[] = {BMP_Dan,BMP_Ti,BMP_DC, BMP_Chayi, BMP_Baojing, 0};
//��ع���
__prog__ const unsigned char * DCGC[] = {BMP_DC,BMP_Guo,BMP_Chong,0};
//��ѹ����״̬����
__prog__ const unsigned char * GYHSZTBJ[] = {BMP_Gao,BMP_Ya,BMP_Husuo,BMP_Zhuangtai,BMP_Baojing,0};
//����������
__prog__ const unsigned char * YWBJGZ[] = {BMP_Yanwu, BMP_Baojing, BMP_Guzhang, 0};
//���������ͨѶ����
__prog__ const unsigned char * DJKZQTXGZ[] = {BMP_DJ, BMP_Kongzhi,BMP_Qi,BMP_Tongxin, BMP_Guzhang, 0};
//���ͨѶ����
__prog__ const unsigned char * DCTXGZ[] = {BMP_DC,BMP_Tongxin, BMP_Guzhang, 0};
//�Ǳ�ͨѶ����
//__prog__ const unsigned char * YBTXGZ[] = {BMP_Yibiao,BMP_Tongxin, BMP_Guzhang, 0};
//DCDC ͨѶ����
__prog__ const unsigned char * DCDCTXGZ[] = {BMP_d,BMP_c,BMP_d,BMP_c,BMP_Tongxin, BMP_Guzhang, 0};
//�ƶ� DCAC ͨѶ����
__prog__ const unsigned char * ZDDCACTXGZ[] = {BMP_Zhidong,BMP_d,BMP_c,BMP_a,BMP_c,BMP_Tongxin, BMP_Guzhang, 0};
//��ѹת�� DCAC ͨѶ���� 
__prog__ const unsigned char * GYDCACTXGZ[] = {BMP_Gao,BMP_Ya,BMP_d,BMP_c,BMP_a,BMP_c,BMP_Tongxin, BMP_Guzhang, 0};
//��ѹת�� DCAC ͨѶ����
__prog__ const unsigned char * DYDCACTXGZ[] = {BMP_Di,BMP_Ya,BMP_d,BMP_c,BMP_a,BMP_c,BMP_Tongxin, BMP_Guzhang, 0};
//��ѹ����ͨѶ����
__prog__ const unsigned char * GYGTXGZ[] = {BMP_Gao,BMP_Ya,BMP_Gui,BMP_Tongxin, BMP_Guzhang, 0};
//ѡ�����ͨѶ����
__prog__ const unsigned char * HDTXGZ[] = {BMP_Huan,BMP_Dang,BMP_Tongxin, BMP_Guzhang, 0};
//��Ե�����ͨѶ����
__prog__ const unsigned char * JYTXGZ[] = {BMP_Jueyuan,BMP_Tongxin, BMP_Guzhang, 0};
//ABS/EBS ͨѶ����
__prog__ const unsigned char * ABSTXGZ[] = {BMP_a, BMP_b,BMP_s,BMP_Tongxin, BMP_Guzhang, 0};
//�յ�ͨѶ����
__prog__ const unsigned char * KTTXGZ[] = {BMP_Kongtiao,BMP_Tongxin, BMP_Guzhang, 0};
//̥ѹͨѶ����
__prog__ const unsigned char * TYTXGZ[] = {BMP_Tai, BMP_Ya, BMP_Tongxin, BMP_Guzhang, 0};
//Զ�̿����豸ͨѶ���� 
__prog__ const unsigned char * YCTXGZ[] = {BMP_Yuancheng, BMP_Tongxin, BMP_Guzhang, 0};
//�����ź���Ч
__prog__ const unsigned char * CSXHWX[] = {BMP_Chesu, BMP_Xinhao, BMP_Wuxiao, 0};
//����û���ź�
__prog__ const unsigned char * CSWXXH[] = {BMP_Chesu,BMP_Wuxiao, BMP_Xinhao, 0};
//ѡ���������쳣
__prog__ const unsigned char * HDXTGZ[] = {BMP_Huan, BMP_Dang,BMP_System, BMP_Guzhang, 0};
//�����������쳣
//ѡ��ִ�л�������
//������/����ź��쳣
//1��2 ��������ʧ��
//��������¶ȱ���
__prog__ const unsigned char * DJWDBJ[] = {BMP_DJ, BMP_Wendu, BMP_Baojing, 0};
//��������������¶ȱ���
__prog__ const unsigned char * DJKZQWDBJ[] = {BMP_DJ,  BMP_Kongzhi, BMP_Qi,BMP_Wendu, BMP_Baojing, 0};
//���ĸ�߹�ѹ
__prog__ const unsigned char * DJMXGY[] = {BMP_DJ, BMP_Muxian, BMP_Guo, BMP_Ya, 0};
//���ĸ��Ƿѹ
__prog__ const unsigned char * DJMXQY[] = {BMP_DJ, BMP_Muxian, BMP_Qian, BMP_Ya, 0};
//�������
__prog__ const unsigned char * DJGDL[] = {BMP_DJ, BMP_Guo, BMP_DL, 0};
//�������
__prog__ const unsigned char * DJCS[] = {BMP_DJ, BMP_Chaosu, 0};
//�����ת
__prog__ const unsigned char * DJDZ[] = {BMP_DJ, BMP_Du,BMP_Zhuansu, 0};
//�����߶���
__prog__ const unsigned char * XBXDX[] = {BMP_Xuan, BMP_Bian, BMP_Xian4, BMP_Duan, BMP_Xian4, 0};
//����ֵ�������
__prog__ const unsigned char * XBXGZ[] = {BMP_Xuan, BMP_Bian, BMP_Xian4, BMP_Guzhang, 0};
//IGBT ����
__prog__ const unsigned char * IGBTGZ[] = {BMP_i, BMP_g, BMP_b,BMP_t, BMP_Guzhang, 0};
//����ϵͳ����
__prog__ const unsigned char * QBXTGZ[] = {BMP_Qibeng, BMP_System,BMP_Guzhang, 0};
//�ͱ�ϵͳ����
__prog__ const unsigned char * YBXTGZ[] = {BMP_Youbeng, BMP_System,BMP_Guzhang, 0};
/******************************************************************************/
/******************************���ϵͳ��Ϣ*****************************************/
//������ǰ״̬
__prog__ const unsigned char * ZCZT[] = {BMP_Zhengche, BMP_Zhuangtai, 0};
//���ϵͳ״̬
__prog__ const unsigned char * DJXTZT[] = {BMP_DJ, BMP_System, BMP_Zhuangtai, 0};
//ϵͳ����״̬
__prog__ const unsigned char * XTHSZT[] = {BMP_System, BMP_Husuo, BMP_Zhuangtai, 0};
//�����Ӵ���
__prog__ const unsigned char * ZZJCQ[] = {BMP_Zhu, BMP_Zheng, BMP_Jiechuqi, 0};
//���ת���ź�
__prog__ const unsigned char * DJZSXH[] = {BMP_DJ, BMP_Zhuansu, BMP_Xinhao, 0};
//���ת��
__prog__ const unsigned char * DJZS[] = {BMP_DJ, BMP_Zhuansu, 0};
//���ת��
__prog__ const unsigned char * DJZJ[] = {BMP_DJ, BMP_Zhuanju, 0};
//����¶�
__prog__ const unsigned char * DJWD[] = {BMP_DJ, BMP_Wendu, 0};
//�������¶�
__prog__ const unsigned char * KZQWD[] = {BMP_KZQ, BMP_Wendu, 0};
//���ת���ź�
__prog__ const unsigned char * DJZZXH[] = {BMP_DJ, BMP_Zhuanju, BMP_Xinhao, 0};
//���ĸ�ߵ�ѹ�ź�״̬
__prog__ const unsigned char * DJMXDYXHZT[] = {BMP_DJ, BMP_Muxian, BMP_DY, BMP_Xinhao, BMP_Zhuangtai, 0};
//���ĸ�ߵ����ź�״̬
__prog__ const unsigned char * DJMXDLXHZT[] = {BMP_DJ, BMP_Muxian, BMP_DL, BMP_Xinhao, BMP_Zhuangtai, 0};
//��ؽӴ���
__prog__ const unsigned char * DCJCQ[] = {BMP_DC, BMP_Jiechuqi, 0};
//�ƶ�̤��״̬
__prog__ const unsigned char * ZDTBZT[] = {BMP_Zhidong, BMP_Taban, BMP_Zhuangtai, 0};
//����̤��״̬
__prog__ const unsigned char * JSTBZT[] = {BMP_Youmen, BMP_Taban, BMP_Zhuangtai, 0};
//����¶��ź�״̬
__prog__ const unsigned char * DJWDXHZT[] = {BMP_DJ, BMP_Wendu, BMP_Xinhao, BMP_Zhuangtai, 0};
//����������¶��ź�
__prog__ const unsigned char * DJKZQWDXHZT[] = {BMP_DJ, BMP_KZQ, BMP_Wendu, BMP_Xinhao, 0};
//Ԥ��Ӵ���
__prog__ const unsigned char * YCJCQ[] = {BMP_Yuchong, BMP_Jiechuqi, 0};
//��˪�Ӵ���
__prog__ const unsigned char * CSJCQ[] = {BMP_Chushuang, BMP_Jiechuqi, 0};
//����״̬
__prog__ const unsigned char * BXZT[] = {BMP_Baoxian, BMP_Zhuangtai, 0};
//��������ѹ
__prog__ const unsigned char * DJSRDY[] = {BMP_DJ, BMP_Input, BMP_DY, 0};
//����������
__prog__ const unsigned char * DJSRDL[] = {BMP_DJ, BMP_Input, BMP_DL, 0};
//��λģʽ
__prog__ const unsigned char * DWMS[] = {BMP_Dang, BMP_Wei,BMP_Mode, 0};
//��λ��Ϣ
__prog__ const unsigned char * DWXX[] = {BMP_Dang, BMP_Wei,BMP_Xinxi, 0};
//kwh/100km
//__prog__ const unsigned char * KWH[] = {BMP_k, BMP_w, BMP_h, BMP_I, BMP_SZ_2[1], BMP_SZ_2[0], BMP_SZ_2[0], BMP_k, BMP_m, 0};
//kwh
__prog__ const unsigned char * KWH[] = {BMP_k, BMP_w, BMP_h, 0};
//kw
__prog__ const unsigned char * KW[] = {BMP_k, BMP_w,0};
//����̤��
__prog__ const unsigned char * YMTB[] = {BMP_Youmen, BMP_Taban, 0};
//�ƶ�̤��
__prog__ const unsigned char * ZDTB[] = {BMP_Zhidong, BMP_Taban, 0};
//�����Ӵ���״̬
__prog__ const unsigned char * ZFJCQZT[] = {BMP_Zhu, BMP_Fu, BMP_Ji4,BMP_Dian,BMP_Qi, BMP_Zhuangtai, 0};
//�����Ӵ���״̬
__prog__ const unsigned char * ZZJCQZT[] = {BMP_Zhu, BMP_Zheng, BMP_Ji4,BMP_Dian,BMP_Qi, BMP_Zhuangtai, 0};
//�����Ӵ���״̬
__prog__ const unsigned char * ZJJCQZT[] = {BMP_Fu, BMP_Jizhu, BMP_Ji4,BMP_Dian,BMP_Qi, BMP_Zhuangtai, 0};
//���Ӵ���״̬
__prog__ const unsigned char * CDJCQZT[] = {BMP_Chong, BMP_DC, BMP_Ji4,BMP_Dian,BMP_Qi, BMP_Zhuangtai, 0};
//�յ��Ӵ���״̬
__prog__ const unsigned char * KTJCQZT[] = {BMP_Kongtiao, BMP_Ji4,BMP_Dian,BMP_Qi, BMP_Zhuangtai, 0};
//ů��Ӵ���״̬
__prog__ const unsigned char * NFJCQZT[] = {BMP_Nuanfeng, BMP_Ji4,BMP_Dian,BMP_Qi, BMP_Zhuangtai, 0};
//ѩ�ؿ��ƿ���
__prog__ const unsigned char * XDKZKG[] = {BMP_Xuedi, BMP_KZQ, BMP_IC_Kaiguan, 0};
//ˮ�ÿ���ָ��
__prog__ const unsigned char * SBKZZL[] = {BMP_Shuibeng, BMP_Kongzhi, BMP_Zhiling, 0};
//���ȿ���ָ��
__prog__ const unsigned char * FSKZZL[] = {BMP_Fengshan, BMP_Kongzhi, BMP_Zhiling, 0};
//BMS����ָ��
__prog__ const unsigned char * BMSKZZL[] = {BMP_b, BMP_m, BMP_s, BMP_Kongzhi, BMP_Zhiling, 0};
//MCU����ָ��
__prog__ const unsigned char * MCUKZZL[] = {BMP_m, BMP_c, BMP_u, BMP_Kongzhi, BMP_Zhiling, 0};
//�ͱÿ���ָ��
__prog__ const unsigned char * YBKZZL[] = {BMP_Youbeng, BMP_Kongzhi, BMP_Zhiling, 0};
//���ÿ���ָ��
__prog__ const unsigned char * QBKZZL[] = {BMP_Qibeng, BMP_Kongzhi, BMP_Zhiling, 0};
//�յ�����ָ��
__prog__ const unsigned char * KTKZZL[] = {BMP_Kongtiao, BMP_Kongzhi, BMP_Zhiling, 0};
//ů�����ָ��
__prog__ const unsigned char * NFKZZL[] = {BMP_Nuanfeng, BMP_Kongzhi, BMP_Zhiling, 0};
//DCDC����ָ��
__prog__ const unsigned char * DCDCKZZL[] = {BMP_d, BMP_c, BMP_d, BMP_c, BMP_Kongzhi, BMP_Zhiling, 0};
//�ĺ�һ����ָ��
__prog__ const unsigned char * SHYKZZL[] = {BMP_Siheyi, BMP_Kongzhi, BMP_Zhiling, 0};
//��������ָ��
__prog__ const unsigned char * ZZKZZL[] = {BMP_Zhu, BMP_Zheng, BMP_Kongzhi, BMP_Zhiling, 0};
//Ԥ�����ָ��
__prog__ const unsigned char * YCKZZL[] = {BMP_Yuchong, BMP_Kongzhi, BMP_Zhiling, 0};
//��������ָ��
__prog__ const unsigned char * ZFKZZL[] = {BMP_Zhu, BMP_Fu, BMP_Kongzhi, BMP_Zhiling, 0};
//��������ָ��
__prog__ const unsigned char * FJKZZL[] = {BMP_Fu, BMP_Ji, BMP_Kongzhi, BMP_Zhiling, 0};
//��ѹ�Ӵ���״̬
__prog__ const unsigned char * GYJCQZT[] = {BMP_Gao, BMP_Yali, BMP_Ji4, BMP_Dian, BMP_Qi, BMP_Zhuangtai, 0};
//����״̬
__prog__ const unsigned char * SRZT[] = {BMP_Input, BMP_Zhuangtai, 0};
//���ת��
__prog__ const unsigned char * SCZS[] = {BMP_Output, BMP_Zhuansu, 0};
/******************************************************************************/
//���ŵ繦������
__prog__ const unsigned char * ZDFDXZGL[] = {BMP_Zui,BMP_Da,BMP_Fang,BMP_DC,BMP_Xian,BMP_Zhidong,BMP_Gonglv,0};
//����繦������
__prog__ const unsigned char * ZDCDXZGL[] = {BMP_Zui,BMP_Da,BMP_Chong,BMP_DC,BMP_Xian,BMP_Zhidong,BMP_Gonglv,0};
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
__prog__ const unsigned char * YJFBJ[] = {BMP_Yingjifa, BMP_Baojing, 0};
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
__prog__ const unsigned char * SERVICE[] = {BMP_s, BMP_e, BMP_r, BMP_v, BMP_i, BMP_c, BMP_e, BMP_Qingqiu, 0};
//����������
__prog__ const unsigned char * YWBJKG[] = {BMP_Yanwu, BMP_Baojing, BMP_IC_Kaiguan, 0};
//��ȫ������
__prog__ const unsigned char * AQDBJ[] = {BMP_Anquandai, BMP_Baojing, 0};
//���ƿ���1
__prog__ const unsigned char * GGKG1[] = {BMP_Guanggao, BMP_IC_Kaiguan, BMP_SZ_2[1], 0};
//���ƿ���2
__prog__ const unsigned char * GGKG2[] = {BMP_Guanggao, BMP_IC_Kaiguan, BMP_SZ_2[2], 0};
//��������
__prog__ const unsigned char * ZLBJ[] = {BMP_Zhongli, BMP_Baojing, 0};
//������
__prog__ const unsigned char * JZRH[] = {BMP_Jizhong, BMP_Runhua, 0};
//·�ƿ���
__prog__ const unsigned char * LPKG[] = {BMP_Lupai, BMP_IC_Kaiguan, 0};
//ǰ�ſ�����
__prog__ const unsigned char * QMKKG[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//ǰ�ſ�����
__prog__ const unsigned char * QMGKG[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//���ſ�����
__prog__ const unsigned char * ZMKKG[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_IC_Kaiguan, 0};
//���ſ�����
__prog__ const unsigned char * ZMGKG[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_IC_Kaiguan, 0};
//���ȿ���
__prog__ const unsigned char * FSKG[] = {BMP_Fengshan, BMP_IC_Kaiguan, 0};
//˫������
__prog__ const unsigned char * WXBJHXKG[] = {BMP_Weixian, BMP_Baojing, BMP_Huanxing, BMP_IC_Kaiguan, 0};
//ȼ��ˮλ����
__prog__ const unsigned char * RYSWBJ[] = {BMP_Ranyou, BMP_Shuiwei, BMP_Baojing, 0};
//���ˮλ����
__prog__ const unsigned char * DJSWBJ[] = {BMP_DJ, BMP_Shuiwei, BMP_Baojing, 0};
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
//������1
__prog__ const unsigned char * GGSC1[] = {BMP_Guanggao, BMP_Output, BMP_SZ_2[1], 0};
//������2
__prog__ const unsigned char * GGSC2[] = {BMP_Guanggao, BMP_Output, BMP_SZ_2[2], 0};
//ǰ�ŵ����
__prog__ const unsigned char * QMDSC[] = {BMP_IC_Qian, BMP_Men, BMP_IC_Deng, BMP_Output, 0};
//���ŵ����
__prog__ const unsigned char * ZMDSC[] = {BMP_Zhong, BMP_Men, BMP_IC_Deng, BMP_Output, 0};
//�������
__prog__ const unsigned char * LBSC[] = {BMP_Laba, BMP_Output, 0};
//�ƶ������
__prog__ const unsigned char * ZDDSC[] = {BMP_Zhidong, BMP_Output, 0};
//���ȵ�Դ
__prog__ const unsigned char * FSDY[] = {BMP_Fengshan, BMP_Dianyuan, 0};
//��ѹ��Դ
__prog__ const unsigned char * QYDY[] = {BMP_Qiya, BMP_Dianyuan, 0};
//ǰ�ſ����
__prog__ const unsigned char * QMKSC[] = {BMP_IC_Qian, BMP_Men, BMP_Kai, BMP_Output, 0};
//ǰ�Ź����
__prog__ const unsigned char * QMGSC[] = {BMP_IC_Qian, BMP_Men, BMP_Guan, BMP_Output, 0};
//���ſ����
__prog__ const unsigned char * ZMKSC[] = {BMP_Zhong, BMP_Men, BMP_Kai, BMP_Output, 0};
//���Ź����
__prog__ const unsigned char * ZMGSC[] = {BMP_Zhong, BMP_Men, BMP_Guan, BMP_Output, 0};
//ǰ·��
__prog__ const unsigned char * QLP[] = {BMP_IC_Qian, BMP_Lupai, 0};
//��·��
__prog__ const unsigned char * HLP[] = {BMP_IC_Hou, BMP_Lupai, 0};
//������
__prog__ const unsigned char * DCD[] = {BMP_Daoche, BMP_IC_Deng, 0};
//��Դ����
__prog__ const unsigned char * DYKG[] = {BMP_Dianyuan, BMP_IC_Kaiguan, BMP_Output, 0};
//������
__prog__ const unsigned char * GZQ[] = {BMP_Ganzaoqi, BMP_Output, 0};
//�������
__prog__ const unsigned char * FSSC[] = {BMP_Fengshan, BMP_Output, 0};
/******************************************************************************/
/******************************************************************************/
//�������
__prog__ const unsigned char * DLDC[] = {BMP_Dongli, BMP_DC, 0};
//��ش�������
__prog__ const unsigned char * DCCLSL[] = {BMP_DC, BMP_Chuanlian, BMP_Shuliang, 0};
//��ز�������
__prog__ const unsigned char * DCBLSL[] = {BMP_DC, BMP_Binglian, BMP_Shuliang, 0};
//��ض����
__prog__ const unsigned char * DCEDRL[] = {BMP_DC, BMP_Eding, BMP_Rongliang, 0};
//���ʣ�����
__prog__ const unsigned char * DCSYDL[] = {BMP_DC, BMP_Shengyu, BMP_Dianliang, 0};
//��ر����ȼ�
__prog__ const unsigned char * DCBJDJ[] = {BMP_DC, BMP_Baojing, BMP_Dengji, 0};
//һ�����ϴ���
__prog__ const unsigned char * YJGZDM[] = {BMP_Yiji, BMP_Guzhang, BMP_Code, 0};
//�������ϴ���
__prog__ const unsigned char * EJGZDM[] = {BMP_Erji, BMP_Guzhang, BMP_Code, 0};
//�������ϴ���
__prog__ const unsigned char * SJGZDM[] = {BMP_Sanji, BMP_Guzhang, BMP_Code, 0};
//��Եĸ�ߵ�ѹ
__prog__ const unsigned char * JYMXDY[] = {BMP_Jueyuan, BMP_Muxian, BMP_DY, 0};
//��Ե���ϵȼ�
__prog__ const unsigned char * JYGZDJ[] = {BMP_Jueyuan, BMP_Guzhang, BMP_Dengji, 0};
//��Ե����״̬
__prog__ const unsigned char * JYGZZT1[] = {BMP_Jueyuan, BMP_Guzhang, BMP_Zhuangtai, 0};
//��Ե����״̬
__prog__ const unsigned char * JYGZZT2[] = {BMP_Jueyuan, BMP_Gongzuo, BMP_Zhuangtai, 0};
//���ֱ����ȼ�
__prog__ const unsigned char * HZBJDJ[] = {BMP_Huozai, BMP_Baojing, BMP_Dengji, 0};
//���ֱ������ϴ���
__prog__ const unsigned char * HZBJGZDM[] = {BMP_Huozai, BMP_Baojing, BMP_Guzhang, BMP_Code, 0};
/******************************************************************************/
#endif	/* APP_CHAR_H */

