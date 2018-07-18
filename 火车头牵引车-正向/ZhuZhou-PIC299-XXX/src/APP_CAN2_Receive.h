/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APP_CAN2_RECEIVE_H
#define	APP_CAN2_RECEIVE_H

typedef union {

    struct {
        unsigned bit1 : 2;
        unsigned bit2 : 2;
        unsigned bit3 : 2;
        unsigned bit4 : 2;
    };
    unsigned char byte;
} DATA_DOUBLE;

typedef union {

    struct {
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
        unsigned bit8 : 1;
    };
    unsigned char byte;
} DATA_BIT;

/*****************分包处理CAN*****************/

typedef union {

    struct {
        unsigned long SPN1 : 19;
        unsigned FMI : 5;
        unsigned CM : 1;
        unsigned OC : 7;
    }; //这个结构需要验证
    unsigned char bData[4];
} DTC;

typedef union {

    struct {
        unsigned ProtectLampStatus : 2;
        unsigned AmberWarningLampStatus : 2;
        unsigned RedStopLampState : 2;
        unsigned MalfunctionIndicatorLampStatus : 2;
        unsigned FlashProtectLamp : 2;
        unsigned FlashAmberWarningLamp : 2;
        unsigned FlashRedStopLamp : 2;
        unsigned FlashMalfunctionIndicatorLamp : 2;
        DTC DTC1;
        DTC DTC2;
        DTC DTC3;
        DTC DTC4;
        DTC DTC5;
    };
    unsigned char bData[42];
} DM1;

extern DM1 CAN_18FECAEF;
extern unsigned char CAN_18FECAEF_len;
extern DM1 CAN_18FECA03;
extern unsigned char CAN_18FECA03_len;
extern DM1 CAN_18FECAF5;
extern unsigned char CAN_18FECAF5_len;
extern DM1 CAN_18FECA00;
extern unsigned char CAN_18FECA00_len;
extern DM1 CAN_18FECAF3;
extern unsigned char CAN_18FECAF3_len;

typedef struct {
    unsigned char pack; //CAN分几包数据传输
    unsigned char flag; //CAN缓存接收完标记
    unsigned char len; //CAN缓存长度
    unsigned char buf[50]; //CAN缓存数组
} CAN_CACHE;
extern CAN_CACHE m_can; //HCU缓存
extern CAN_CACHE n_can; //TCU缓存
extern CAN_CACHE c_can; //CCU缓存
extern CAN_CACHE b_can; //BMS缓存

extern unsigned long SPN; //从缓存里提取的故障码
extern unsigned char FMI;
/*******************分包处理*****************/
typedef union{
    struct{
        unsigned int VCU_VehSpdV : 1;        
        unsigned int VCU_VehSpd : 15;
        
        unsigned char VCU_EnrgyFdbckVal;
        unsigned char VCU_HVBatSOCRsrvd;
        unsigned char VCU_BrkPdlPosRsrvd;
        
        unsigned VCU_VehRdy : 1;
        unsigned VCU_BrkPdlPosVRsvrd : 1;
        unsigned VCU_ShftLvlPos : 3;
        unsigned VCU_HVMainPosReqCmd : 1;
        unsigned VCU_HVMainNegReqCmd : 1;
        unsigned VCU_Rsvrd1 : 1;
        
        unsigned char VCU_VCUAndMtrCtrlSelfErrCd;
        unsigned char VCU_Checksum;
    };
    unsigned char byte[8];
}_CAN_0x141;

extern _CAN_0x141 CAN_0x141;

typedef union{
    struct{
        unsigned VCU_AccPdlPosV : 1;
        unsigned VCU_BrkPdlSts : 2;
        unsigned VCU_MtrACmdMod : 3;
        unsigned VCU_MtrAInvEnbl : 1;
        unsigned VCU_MtrATrqCtrlReqV : 1;     
        
        unsigned char VCU_AccPdlPos;       
        
        unsigned int VCU_MtrASpdCtrlReqValV : 1;
        unsigned int VCU_MtrASpdCtrlReq : 15;
        
        unsigned int VCU_MtrATqCtrlReq: 10;
        unsigned int VCU_LstComWithMCU : 1;
        unsigned int VCU_DCDCStsWrning : 1;
        unsigned int VCU_VehicleStatus : 2;
        unsigned int VCU_VacuumPresWarn : 2;
               
        unsigned VCU_2_Rollingcounter : 4;
        unsigned VCU_DCDCMod : 3;
        unsigned VCU_DCDCTmpWrning : 1;
        
        unsigned char VCU_2_Checksum;
    };
    unsigned char byte[8];
}_CAN_0x121;

extern _CAN_0x121 CAN_0x121;

typedef union{
    struct{        
        unsigned int VCU_Flt : 3;
        unsigned int VCU_WorkingSts : 3;
        unsigned int VCU_DCDCStsWrning : 10;
        
        unsigned char VCU_DCDCLVOptVolCmd;
        
        unsigned char VCU_EvaporateTmp;
        
        unsigned char VCU_ErrorNumber;
        
        unsigned char VCU_CntrlSelfErrCodRsvrd;
        
        unsigned VCU_3_Rsrvd3 : 1;
        unsigned VCU_SrplsMilgV : 1;
        unsigned VCU_EvapTmpV: 1;
        unsigned VCU_RadiOutletTmpVRsvrd : 1;
        unsigned VCU_3_RollingCounter : 4; 
        
        unsigned char VCU_3_Checksum;
    };
    unsigned char byte[8];
}_CAN_0x113;

extern _CAN_0x113 CAN_0x113;

typedef union{
    struct{
        unsigned VCU_DCDCModCtrlReq : 4;
        unsigned VCU_DCDCMaxCrntLmtV : 1;
        unsigned VCU_DCDCEnabReqRsvrd : 1;
        unsigned VCU_4_Rsrvd1 : 2;
        
        unsigned char VCU_DCDCMaxCrntLmt;
        
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        unsigned : 8;
        
        unsigned : 4;
        unsigned VCU_4_Rollingcounter : 4;

        unsigned char VCU_4_Checksum;

    };
    unsigned char byte[8];
}_CAN_0x202;

extern _CAN_0x202 CAN_0x202;

typedef union{
    struct{
        unsigned int MCU_MtrSpdV : 1;
        unsigned int MCU_MtrSpd : 15;
        
        unsigned char MCU_MtrCntrlTmp;
        
        unsigned char MCU_MtrTmp;
        
        unsigned int MCU_MtrDirSts : 1;
        unsigned int MCU_MtrModSts : 3;
        unsigned int MCU_MtrCtrlTmpV : 1;
        unsigned int MCU_MtrTmpV : 1;
        unsigned int MCU_MtrDlvrdTrq : 10;        

        unsigned int MCU_MtrOptPwrV : 1;
        unsigned int MCU_MtrDlvrdTrqV : 1;
        unsigned int MCU_MtrAInvrSts : 1;
        unsigned int MCU_MtrSysFltSts : 3;             
        unsigned int MCU_MtrOptPwr : 10;
    };
    unsigned char byte[8];
}_CAN_0x239;

extern _CAN_0x239 CAN_0x239;

typedef union{
    struct{
        unsigned int MCU_RotationElecAngl;
        
        unsigned int MCU_MtrSpdV : 1;
        unsigned int MCU_MtrSpd : 15;
        
        unsigned MCU_RotationElecAnglV : 1;
        unsigned MCU_1_Rsrvd1 : 7;
        
        unsigned : 8;
        
        unsigned MCU_1_Rollingcounter : 4;
        unsigned : 4;
        
        unsigned char MCU_1_Checksum;
    };
    unsigned char byte[8];
}_CAN_0x233;

extern _CAN_0x233 CAN_0x233;

typedef union{
    struct{
        unsigned int MCU_MtrInverRatVol;
        
        unsigned int MCU_MtrCntrlRatCrnt;
        
        unsigned char MCU_MtrCntrlSelfErrCod;
        
        unsigned MCU_MtrInverRatVolV : 1;
        unsigned MCU_MtrCntrlRatCrntV : 1;
        unsigned MCU_LstCommWithMCU : 1;
        unsigned MCU_VehRdy : 1;
        unsigned MCU_MtrCntrlTmpWarn : 1;
        unsigned MCU_MtrTmpWarn : 1;
        unsigned MCU_MtrBlockErr : 2;
        
        unsigned MCU_MtrSelfCheckSts : 2;
        unsigned MCU_PerchrgCmplSts : 2;
        unsigned MCU_Rollingcounter : 4;
        
        unsigned char MCU_Checksum;
    };
    unsigned char byte[8];
}_CAN_0x23D;

extern _CAN_0x23D CAN_0x23D;

typedef union{
    struct{
        unsigned char MCU_MtrSerialNmb;
        
        unsigned char MCU_MtrErrCod;
        
        unsigned char MCU_MtrNumb;
        
        unsigned char MCU_MaxOperationCurrent;
        
        unsigned int MCU_RotationElecAngle;
        
        unsigned char MCU_DriveMotorNumber;
        
        unsigned char MCU_DriveMotorErrorNumber;
    };
    unsigned char byte[8];
}_CAN_0x235;

extern _CAN_0x235 CAN_0x235;

typedef union{
    /*struct{
        unsigned int MCU_MotAMaxTrqCapLTV : 1;     
        unsigned int MCU_MotAMinTrqCapLTV : 1;       
        unsigned int MCU_2_Rsrvd1 : 2;       
        unsigned int MCU_MtrAMaxTrqCapLT : 10;              
        unsigned int MCU_MtrAMaxTrqCapSTVRsvrd : 1;      
        unsigned int MCU_MtrAMinTrqCapSTVRsvrd : 1;
        
        unsigned char MCU_2_Rsrvd2;
        
        unsigned int MCU_MtrAMaxTrqCapSTRsvrd;
        
        unsigned char MCU_MtrAMinTrqCapSTRsvrd;
        
        unsigned char MCU_LstCommWithVCU;
        
        unsigned char MCU_2_Rsrvd3;
        
        unsigned char MCU_2_Rollingcounter;
        
        unsigned int MCU_2_Checksum;
    };*/
    unsigned char byte[8];
}_CAN_0x237;

extern _CAN_0x237 CAN_0x237;

typedef union{
    struct{
        unsigned int BMS_HVBatProVol;
        
        unsigned int BMS_BatPckCrnt;
        
        unsigned char BMS_HVBatSOC;           
        
        unsigned BMS_HVBatSts: 3;
        unsigned BMS_HVbatSOCV: 1;
        unsigned BMS_HVBatProVolV: 1;
        unsigned BMS_LstComWithVCU: 1;
        unsigned BMS_PrechrgCompSts: 2;
        
        unsigned BMS_BatCellChrgAct: 1;
        unsigned BMS_BatCellDischAct: 1;
        unsigned BMS_BatTmpHiInd: 1;
        unsigned BMS_BatDischOvCrnt: 1;
        unsigned BMS_SOCLwReqInd: 1;
        unsigned BMS_IsoResisLw: 1;
        unsigned IBMS_IsoResisOvLwReqInd: 1;
        unsigned BMS_LstCommwithMCU: 1;
                
        unsigned BMS_BatPckHVFlt: 1;
        unsigned BMS_BatPckLVFlt: 1;
        unsigned BMS_ChrgOvCrntFlt: 1;
        unsigned BMS_LwTmpFlt: 1;
        unsigned BMS_DltTmpFlt: 1;
        unsigned BMS_DltVolFlt: 1;
        unsigned BMS_TmpIncOvFstFlt: 1;
        unsigned BMS_Shortcircuit_ProtAct: 1;

    };
    unsigned char byte[8];
}_CAN_0x213;

extern _CAN_0x213 CAN_0x213;

typedef union{
    struct{
        unsigned int BMS_BatPckCellMaxVol;
        
        unsigned char BMS_CellMaxVolNum;
        
        unsigned char BMS_BatPckCellMaxVolNum;           
        
        unsigned int BMS_BatPckCellMinVol;
        
        unsigned char BMS_CellMinVolNum;
        
        unsigned char BMS_CellMinVolPckNum;                  
    };
    unsigned char byte[8];
}_CAN_0x215;

extern _CAN_0x215 CAN_0x215;

typedef union{
    struct{
        unsigned char BMS_BatPckMaxTmp;
        
        unsigned char BMS_CellMaxTmpNum;
        
        unsigned char BMS_CellMaxTmpPckNum;           
        
        unsigned char BMS_BatPckMinTmp;
        
        unsigned char BMS_CellMinTmpNum;
        
        unsigned char BMS_CellMinTmpPckNum;    
        
        unsigned BMS_BatPckMaxTmpV: 1;
        unsigned BMS_BatPckMinTmpV: 1;
        unsigned BMS_4_Rsrvd: 2;
        unsigned BMS_4_Rollingcounter: 4;
        
        unsigned char BMS_4_checksum;
    };
    unsigned char byte[8];
}_CAN_0x21A;

extern _CAN_0x21A CAN_0x21A;

typedef union{
    struct{
        unsigned int BMS_PosIsoRes;
        
        unsigned int BMS_NegIsoRes;
        
        unsigned char BMS_HVBatSOH;
        
        unsigned BMS_NegRlySts : 2;      
        unsigned BMS_PosRlySts : 2; 
        unsigned BMS_FstChrgRlySts : 2; 
        unsigned BMS_SlwChrgRlySts : 2; 
        
        unsigned BMS_PreCharRlySts : 2;      
        unsigned BMS_HeatRlySts : 2; 
        unsigned BMS_HigVolBatIsoSts : 2; 
        unsigned BMS_HVBatPckChrgSts : 2; 
        
        unsigned char BMS_5_Checksum;
    };
    unsigned char byte[8];
}_CAN_0x217;

extern _CAN_0x217 CAN_0x217;

typedef union{
    struct{
        unsigned BMS_6_Rsrvd1 : 2;      
        unsigned BMS_HVInterLockStsWrningRsvrd : 1; 
        unsigned BMS_SysFltLvl : 3; 
        unsigned BMS_6_Rsrvd2 : 2;                
        
        unsigned int BMS_OvDischCnt;   
        
        unsigned char BMS_BatPckSysFltCod;
             
        unsigned int BMS_ChrgCnt;  
        
        unsigned BMS_BatSysSelChkSts : 2;      
        unsigned BMS_6_Rsrvd3 : 2; 
        unsigned BMS_6_Rollingcounter : 4; 
        
        unsigned char BMS_6_Checksum;
    };
    unsigned char byte[8];
}_CAN_0x207;

extern _CAN_0x207 CAN_0x207;

typedef union{
    struct{
        unsigned BMS_ChrgConnIndLmp : 2;
        unsigned BMS_ChrgStsIndLmp : 2;
        unsigned BMS_BatChrgPrcntStsIndLmp : 2;
        unsigned BMS_ChrgLckStsAct : 2;
        
        unsigned BMS_ChrgModCmd : 2;
        unsigned BMS_LstCommWithCCS : 1;
        unsigned BMS_HVBatChrgTmRmn : 5;
        
        unsigned int BMS_ChrgModSts : 2;
        unsigned int BMS_SOCJumpWarning : 1;
        unsigned int BMS_SOCOverHighWarning : 1;
        unsigned int BMS_HVInterLockStsWarning : 1;
        unsigned int BMS_7_Rsrvd1 : 1;
        unsigned int BMS_SurpMilea : 10;
        
        unsigned char BMS_SingleBatteryNumber;
        
        unsigned char BMS_SingleBatteryTmpDetectedNum;
        
        unsigned int BMS_ChrgStsForTbox : 3;
        unsigned int BMS_7_Rsrvd2 : 13;
    };
    unsigned char byte[8];
}_CAN_0x219;

extern _CAN_0x219 CAN_0x219;

typedef union{
    struct{
        unsigned VCU_Gear_D : 1;
        unsigned VCU_Gear_R : 1;
        unsigned VCU_Gear_N : 1;
        unsigned VCU_Gear_LowSpeed : 1;       
        unsigned VCU_Gear_HighSpeed : 1;
        unsigned VCU_Gear_Idle : 1;
        unsigned VCU_BusVoltage_Alarm : 2;
    };
    unsigned char byte[8];
}_CAN_0x7E0;

extern _CAN_0x7E0 CAN_0x7E0;

#endif	/* APP_CAN2_RECEIVE_H */

