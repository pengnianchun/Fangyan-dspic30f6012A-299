#include "SYSTEM.h"
#include "font.h"
#include "LOGO.h"

unsigned char frmID = 0;
unsigned char f_index = 0;
unsigned char menuid = 0;
unsigned char AV_CH = 0;

void print_SZ(unsigned int x, unsigned int y, //显示坐标位置
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 8, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPP(x + i * 8, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    }
}

void print_SZ_4(unsigned int x, unsigned int y, //显示坐标位置
        unsigned long dat, //显示的数据 
        unsigned char sum, //显示数据的几位
        unsigned char dot, //显示小数点的位数
        unsigned char color1) { //显示数据的颜色
    unsigned char color, f = 1, i = 0;
    unsigned char bcd[8];
    for (i = 0; i < sum; i++) {
        bcd[sum - i - 1] = dat % 10;
        dat = dat / 10;
    }
    for (i = 0; i < dot; i++) {
        bcd[sum - i] = bcd[sum - 1 - i];
    }
    bcd[sum - dot] = 16; //加入小数点  
    if (dot > 0) {
        for (i = 0; i <= sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1 - dot)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPPZOOM_4(x + i * 16, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    } else {
        for (i = 0; i < sum; i++) {
            if (f && (bcd[i] == 0)&&(i < sum - 1)) { //不显示前面0
                f = 1;
                color = BLACK;
            } else {
                f = 0;
                color = color1;
            }
            LCD_DrawImage1BPPZOOM_4(x + i * 16, y, BMP_SZ[bcd[i]], color, BLACK);
        }
    }
}


//主界面

/*********************************************************
//函数名: void mainFrame(void)
//功能: 显示主界面不需要更新的内容,界面格式
//参数: 无
 *********************************************************/
void mainFrame(void) {

    unsigned int i;

    LCD_Clear();
    LCD_DrawRect(0, 0, 800, 1, GRAY);
    LCD_DrawRect(0, 64, 800, 1, GRAY);
    for (i = 1; i < 12; i++) {
        LCD_DrawRect(4 + 66 * i, 0, 1, 64, GRAY);
    }

    //LCD_DrawRect(0,70,800,3,YELLOW); //顶部横线
    LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标

    //气压柱1外观
    //方框
    LCD_DrawRect(33, 100, 50, 3, WHITE); //
    LCD_DrawRect(33, 100, 3, 135, WHITE);
    LCD_DrawRect(83, 100, 3, 135, WHITE);

    LCD_DrawRect(33, 235, 3, 135, RED);
    LCD_DrawRect(83, 235, 3, 135, RED);
    LCD_DrawRect(33, 370, 50, 3, RED); //

    //标尺
    LCD_DrawImage1BPP(13, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(21, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(21, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(21, 360, BMP_SZ[0], RED, BLACK); //0


    LCD_DrawImage1BPP(33 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa


    //气压柱2外观
    LCD_DrawRect(712, 100, 50, 3, WHITE);
    LCD_DrawRect(712, 100, 3, 135, WHITE);
    LCD_DrawRect(712 + 50, 100, 3, 135, WHITE);
    LCD_DrawRect(712, 235, 3, 135, RED);
    LCD_DrawRect(712 + 50, 235, 3, 135, RED);
    LCD_DrawRect(712, 370, 50, 3, RED); //



    LCD_DrawImage1BPP(770, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360, BMP_SZ[0], RED, BLACK); //0 

    LCD_DrawImage1BPP(712 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km   TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPPZOOM_4(2, 440, Bmp_ODO, BLUE, GRAY); //累计里程 ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    LCD_DrawImage1BPPZOOM_4(200, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPPZOOM_4(240, 440, Bmp_TRIP, BLUE, GRAY); //累计里程 ODO 
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    LCD_DrawImage1BPPZOOM_4(404, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km

}

void disp_miles(void) {//显示里程
    print_SZ_4(2 + 64 + 4, 440, e_total_miles, 7, 1, WHITE);
    print_SZ_4(240 + 80 + 4, 440, e_single_miles, 4, 1, WHITE);
}

void updata_QY(void) {

    unsigned char color = RED;
    unsigned int press1 = 50; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    unsigned int press2 = 90; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/

    if (press1 > 60) color = GREEN;
    else color = RED;
    print_SZ(33 - 7, 410, press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380, Bmp_QY1, color, BLACK); //气压1图标

    if (press1 > 100) press1 = 100;
    LCD_DrawRect(38, 102, 44, (260 - press1 * 2.6), BLACK); //260/100  
    LCD_DrawRect(38, (368 - press1 * 2.6), 44, (press1 * 2.6), color);

    if (press2 > 60) color = GREEN;
    else color = RED;
    LCD_DrawImage1BPP(712 + 9, 380, Bmp_QY2, color, BLACK); //气压2图标
    print_SZ(712 - 7, 410, press2, 3, 2, color);

    if (press2 > 100) press2 = 100;
    LCD_DrawRect(712 + 5, 102, 44, (260 - press2 * 2.6), BLACK); //260/100  
    LCD_DrawRect(712 + 5, (368 - press2 * 2.6), 44, (press2 * 2.6), color);

    //LCD_DrawImage1BPP(24,328,Bmp_QY1,color,BLACK);//气压1图标

    //print_SZ(2,190,press_1,3,2,color);
    // LCD_DrawImage1BPP(38,380,Bmp_Mpa,color,BLACK);//Mpa

}

void disp_baojing(void) {
    unsigned char color = GRAY;

    if (IN28) color = YELLOW;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6, 10, Bmp_baojing[0], color, BLACK);

    if (IN26) color = YELLOW;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66, 10, Bmp_baojing[1], color, BLACK);


    if (IN8) color = GREEN;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 2, 10, Bmp_baojing[2], color, BLACK);

    if (IN9) color = GREEN;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 3, 10, Bmp_baojing[3], color, BLACK);


    if (IN20) color = YELLOW;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 4, 10, Bmp_baojing[4], color, BLACK);


    if (IN19) color = RED;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 5, 10, Bmp_baojing[5], color, BLACK);


    if (IN18) color = YELLOW;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 6, 10, Bmp_baojing[6], color, BLACK);


    if (IN2) color = GREEN;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 7, 10, Bmp_baojing[7], color, BLACK);


    if (!IN24) color = RED;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 8, 10, Bmp_baojing[8], color, BLACK);

    if (IN37) color = RED;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 9, 10, Bmp_baojing[9], color, BLACK);

    if (IN14 == 0 || IN15 == 0) color = RED;
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 10, 10, Bmp_baojing[10], color, BLACK);

    if (IN25) color = GREEN; //20120809原为IN28错了 实为IN25
    else color = GRAY;
    LCD_DrawImage1BPPZOOM_4(6 + 66 * 11, 10, Bmp_baojing[11], color, BLACK);

}

void disp_time(unsigned int x, unsigned int y, DATE dtimer) {
    unsigned char color = 0;
    //    if(Did==0) color=RED;
    //    else       color=WHITE;

    LCD_DrawImage1BPPZOOM_4(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(x + 48, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, BLACK);

    if (F500ms_LCD) color = WHITE;
    else color = BLACK;
    LCD_DrawImage1BPPZOOM_4(x + 48 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //冒号 

    //    if(Did==1) color=RED;
    //    else       color=WHITE;
    LCD_DrawImage1BPPZOOM_4(x + 48 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(x + 48 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(610, 440, BMP_SZ[2], WHITE, BLACK); //2
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 1, 440, BMP_SZ[0], WHITE, BLACK); //0
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 2, 440, BMP_SZ[(dtimer.year >> 4)&0x0f], WHITE, BLACK); //年
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 3, 440, BMP_SZ[dtimer.year & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 4, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 5, 440, BMP_SZ[(dtimer.month >> 4)&0x0f], WHITE, BLACK); //月
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 6, 440, BMP_SZ[dtimer.month & 0x0f], WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 7, 440, BMP_SZ[17], WHITE, BLACK); //-
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 8, 440, BMP_SZ[(dtimer.day >> 4)&0x0f], WHITE, BLACK); //日
    LCD_DrawImage1BPPZOOM_4(610 + 18 * 9, 440, BMP_SZ[dtimer.day & 0x0f], WHITE, BLACK);



}

void frmMain(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_QY();
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
    } else if (f_index == 4) {
        f_index = 1;
        disp_time(280, 300, timer);
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if(IN2==1){//背光开启
               if (e_backlight >= 1000) e_backlight = 100;
               else e_backlight += 100;
               EEROM_WriteBackLight();
            }
        }
        if (key_set) {
            key_set = 0;
            key_long_set = 0;
            key_up = 0;
            key_AV = 0;
            key_duble = 0;
            frmID=1;
            f_index=0;
        }
        if (key_long_set) {
            key_long_set = 0;
            key_set = 0;
            key_up = 0;
            key_AV = 0;
            frmID = 5; 
            f_index = 0;
        }
    }
    
    if (IN35 == 0) {//倒车视屏选择使能按键
        if (IN17 && R_flag == 0) {//倒挡
            key_AV = 1; //模拟AV开关按一次
            AV_CH = 3; //3+1=4  倒车
            R_flag = 1;
        }
        if (IN17 == 0 && R_flag == 1) {  
            key_AV = 1;
            AV_CH = 4; //返回MCU界面
            R_flag = 0;
        }
    }

    if (key_AV) {
        key_AV = 0;
        key_long_set = 0;
        key_up = 0;
        key_set = 0;
        unsigned char mode = 2;//2,MCU
        
        if (AV_CH < 4) AV_CH++;
        else AV_CH = 0;
        
        switch (AV_CH) {
            case 0: // DAV
                CS_E = 0; //关闭 
                mode = 2;//2,MCU
                break;
            case 1: //AV2  SP2  CJ2
                CS_E = 1; //打开 
                CS_A = 1;
                CS_B = 1;
                CS_C = 1;
                mode = 1;//AV2
                break;
            case 2: //AV2  SP3  CJ3
                CS_E = 1; //打开 
                CS_A = 0;
                CS_B = 1;
                CS_C = 1;
                mode = 1;//AV2
                break;
            case 3: //AV2  SP4  CJ4
                CS_E = 1; //打开 
                CS_A = 1;
                CS_B = 0;
                CS_C = 1;
                mode = 1;//AV2
                break;
            case 4:  //AV1
                CS_E = 0; //倒车
                mode = 4;//4,AV1 
                break;
            default:
                CS_E = 0; //关闭 
                mode = 2;//2,MCU
                AV_CH = 0;
                break;
        }
        LCD_CHS(mode);
    }
}



void ICFrame(void){ //仪表框架
    LCD_Clear();
    
    LCD_DrawImage1BPPZOOM_4(320,15,BmpZHYB,WHITE,BLACK);
    LCD_DrawRect(0,70,800,2,YELLOW); //顶部横线
    
    LCD_DrawImage1BPPZOOM_4(35,75,Bmp_IN1,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*1,Bmp_IN2,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*2,Bmp_IN3,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*3,Bmp_IN4,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*4,Bmp_IN5,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*5,Bmp_IN6,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*6,Bmp_IN7,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*7,Bmp_IN8,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*8,Bmp_IN9,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*9,Bmp_IN10,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*10,Bmp_IN11,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*11,Bmp_IN12,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*12,Bmp_IN13,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*13,Bmp_IN14,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*14,Bmp_IN15,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(35,75+25*15,Bmp_IN16,WHITE,BLACK);
    
    
    LCD_DrawImage1BPPZOOM_4(285,75,     Bmp_IN17,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*1,Bmp_IN18,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*2,Bmp_IN19,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*3,Bmp_IN20,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*4,Bmp_IN21,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*5,Bmp_IN22,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*6,Bmp_IN23,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*7,Bmp_IN24,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*8,Bmp_IN25,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*9,Bmp_IN26,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*10,Bmp_IN27,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*11,Bmp_IN28,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*12,Bmp_IN29,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*13,Bmp_IN30,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*14,Bmp_IN31,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*15,Bmp_IN32,WHITE,BLACK);
    
    
    LCD_DrawImage1BPPZOOM_4(535,75,     Bmp_IN33,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(535,75+25*1,Bmp_IN34,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(535,75+25*2,Bmp_IN35,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(535,75+25*3,Bmp_IN36,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(535,75+25*4,Bmp_IN37,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(535,75+25*5,Bmp_IN38,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(535,75+25*6,Bmp_IN39,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(535,75+25*7,Bmp_IN40,WHITE,BLACK);
    
    
    
    
    
}
void ICUpdate(void){
    unsigned int dump;
    unsigned int i;
   
    dump=sw_input[0].byte+((unsigned int)(sw_input[1].byte)<<8);
    for(i=0;i<16;i++){
      if((dump & 0x01)==0x01){
        LCD_DrawImage1BPP(5,75+25*i,Bmpflag[1],GREEN,BLACK);
      }else{
        LCD_DrawImage1BPP(5,75+25*i,Bmpflag[0],WHITE,BLACK);
      }
       dump=dump>>1;
    }
   
    dump=sw_input[2].byte+((unsigned int)(sw_input[3].byte)<<8);
    for(i=0;i<16;i++){
     if((dump & 0x01)==0x01){
        LCD_DrawImage1BPP(255,75+25*i,Bmpflag[1],GREEN,BLACK);
      }else{
        LCD_DrawImage1BPP(255,75+25*i,Bmpflag[0],WHITE,BLACK);
      }
       dump=dump>>1;
    }
        
    dump=sw_input[4].byte;
    for(i=0;i<8;i++){
     if((dump & 0x01)==0x01){
        LCD_DrawImage1BPP(505,75+25*i,Bmpflag[1],GREEN,BLACK);
      }else{
        LCD_DrawImage1BPP(505,75+25*i,Bmpflag[0],WHITE,BLACK);
      }
       dump=dump>>1;
    }
    
    
}
void frmIC(void){
  if (f_index == 0) { //只更新一次
        f_index = 1;
        ICFrame();
    } else if (f_index == 1) {
        f_index = 1;
        ICUpdate();
    }else{
       f_index = 0;
    }
  
  
  if(key_up){
      key_up=0;
      frmID=2;
      f_index=0;
  }

  if(key_AV){
      key_AV=0;
  }
  if(key_set){
      key_set=0;
      frmID=0;
      f_index=0;
  }
  if(key_long_set){
      key_long_set=0;
  }

}

void BCUFrame(unsigned char index){
    LCD_Clear(); 
        
    LCD_DrawRect(0,70,800,2,YELLOW); //顶部横线
    if(index==0){
    LCD_DrawImage1BPPZOOM_4(320,15,BmpQMK,WHITE,BLACK);
    
    LCD_DrawImage1BPPZOOM_4(60,75,BmpBCU_F_OUT1,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*1,BmpBCU_F_OUT2,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*2,BmpBCU_F_OUT3,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*3,BmpBCU_F_OUT4,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*4,BmpBCU_F_OUT5,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*5,BmpBCU_F_OUT6,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*6,BmpBCU_F_OUT7,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*7,BmpBCU_F_OUT8,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*8,BmpBCU_F_OUT9,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*9,BmpBCU_F_OUT10,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*10,BmpBCU_F_OUT11,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*11,BmpBCU_F_OUT12,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*12,BmpBCU_F_OUT13,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*13,BmpBCU_F_OUT14,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*14,BmpBCU_F_OUT15,WHITE,BLACK);
    
    LCD_DrawImage1BPPZOOM_4(285,75,     BmpBCU_F_KL1,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*1,BmpBCU_F_KL2,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*2,BmpBCU_F_KL3,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*3,BmpBCU_F_KL4,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*4,BmpBCU_F_KL5,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*5,BmpBCU_F_KL6,WHITE,BLACK);   
    LCD_DrawImage1BPPZOOM_4(285,75+25*6,BmpBCU_F_KL7,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*7,BmpBCU_F_KL8,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*8,BmpBCU_F_KL9,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*9,BmpBCU_F_KL10,WHITE,BLACK);  
    LCD_DrawImage1BPPZOOM_4(285,75+25*10,BmpBCU_F_KL11,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*11,BmpBCU_F_KL12,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*12,BmpBCU_F_KL13,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*13,BmpBCU_F_KL14,WHITE,BLACK);      
    LCD_DrawImage1BPPZOOM_4(285,75+25*14,BmpBCU_F_KL15,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*15,BmpBCU_F_KH1,WHITE,BLACK);   
    }else if(index==1){
     LCD_DrawImage1BPPZOOM_4(320,15,BmpZMK,WHITE,BLACK);    
        
    LCD_DrawImage1BPPZOOM_4(60,75,BmpBCU_M_OUT1,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*1,BmpBCU_M_OUT2,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*2,BmpBCU_M_OUT3,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*3,BmpBCU_M_OUT4,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*4,BmpBCU_M_OUT5,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*5,BmpBCU_M_OUT6,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*6,BmpBCU_M_OUT7,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*7,BmpBCU_M_OUT8,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*8,BmpBCU_M_OUT9,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*9,BmpBCU_M_OUT10,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*10,BmpBCU_M_OUT11,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*11,BmpBCU_M_OUT12,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*12,BmpBCU_M_OUT13,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*13,BmpBCU_M_OUT14,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*14,BmpBCU_M_OUT15,WHITE,BLACK);
    
    
    LCD_DrawImage1BPPZOOM_4(285,75, BmpBCU_M_KL1,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*1,BmpBCU_M_KL2,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*2,BmpBCU_M_KL3,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*3,BmpBCU_M_KL4,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*4,BmpBCU_M_KL5,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*5,BmpBCU_M_KL6,WHITE,BLACK);   
    LCD_DrawImage1BPPZOOM_4(285,75+25*6,BmpBCU_M_KL7,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*7,BmpBCU_M_KL8,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*8,BmpBCU_M_KL9,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*9,BmpBCU_M_KL10,WHITE,BLACK);  
    LCD_DrawImage1BPPZOOM_4(285,75+25*10,BmpBCU_M_KL11,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*11,BmpBCU_M_KL12,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*12,BmpBCU_M_KL13,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*13,BmpBCU_M_KL14,WHITE,BLACK);      
    LCD_DrawImage1BPPZOOM_4(285,75+25*14,BmpBCU_M_KL15,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*15,BmpBCU_M_KH1,WHITE,BLACK);  
    }else if(index==2){
        
    LCD_DrawImage1BPPZOOM_4(320,15,BmpHMK,WHITE,BLACK);      
        
    LCD_DrawImage1BPPZOOM_4(60,75,BmpBCU_R_OUT1,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*1,BmpBCU_R_OUT2,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*2,BmpBCU_R_OUT3,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*3,BmpBCU_R_OUT4,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*4,BmpBCU_R_OUT5,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*5,BmpBCU_R_OUT6,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*6,BmpBCU_R_OUT7,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*7,BmpBCU_R_OUT8,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*8,BmpBCU_R_OUT9,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*9,BmpBCU_R_OUT10,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*10,BmpBCU_R_OUT11,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*11,BmpBCU_R_OUT12,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*12,BmpBCU_R_OUT13,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*13,BmpBCU_R_OUT14,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(60,75+25*14,BmpBCU_R_OUT15,WHITE,BLACK);
    
    LCD_DrawImage1BPPZOOM_4(285,75, BmpBCU_R_KL1,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*1,BmpBCU_R_KL2,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*2,BmpBCU_R_KL3,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*3,BmpBCU_R_KL4,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*4,BmpBCU_R_KL5,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*5,BmpBCU_R_KL6,WHITE,BLACK);   
    LCD_DrawImage1BPPZOOM_4(285,75+25*6,BmpBCU_R_KL7,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*7,BmpBCU_R_KL8,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*8,BmpBCU_R_KL9,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*9,BmpBCU_R_KL10,WHITE,BLACK);  
    LCD_DrawImage1BPPZOOM_4(285,75+25*10,BmpBCU_R_KL11,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*11,BmpBCU_R_KL12,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*12,BmpBCU_R_KL13,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*13,BmpBCU_R_KL14,WHITE,BLACK);      
    LCD_DrawImage1BPPZOOM_4(285,75+25*14,BmpBCU_R_KL15,WHITE,BLACK);
    LCD_DrawImage1BPPZOOM_4(285,75+25*15,BmpBCU_R_KH1,WHITE,BLACK); 
    
    }
}

void BCUUpdate(void){
unsigned int dump;
    unsigned int i;
   
    dump=fPOUT.WORDS;//POUT0 -POUT15
    for(i=0;i<15;i++){  
      if((dump & 0x01)==0x01){
        LCD_DrawImage1BPP(30,75+25*i,Bmpflag[1],GREEN,BLACK);
      }else{
        LCD_DrawImage1BPP(30,75+25*i,Bmpflag[0],WHITE,BLACK);
      }
       dump=dump>>1;
    }
   
    dump=fKEY.BYTES[0]+((unsigned int)(fKEY.BYTES[1])<<8); //KL0-KL15
    for(i=0;i<15;i++){
     if((dump & 0x01)==0x01){
        LCD_DrawImage1BPP(255,75+25*i,Bmpflag[1],GREEN,BLACK);
      }else{
        LCD_DrawImage1BPP(255,75+25*i,Bmpflag[0],WHITE,BLACK);
      }
       dump=dump>>1;
    }
    
    dump=fKEY.BYTES[2]; //KH1
      if((dump & 0x01)==0x01){
        LCD_DrawImage1BPP(255,75+25*15,Bmpflag[1],GREEN,BLACK);
      }else{
        LCD_DrawImage1BPP(255,75+25*15,Bmpflag[0],WHITE,BLACK);
      }
   
    
}
void frmBCU_f(void){
   if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(0);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate();
    }else{
       f_index = 0;
    }
   if(key_set){
      key_set=0;
      frmID=0;
      f_index=0;
  }
  if(key_up){
      key_up=0;
      frmID=3;
      f_index=0;
  } 
   

}
void frmBCU_m(void){
     if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(1);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate();
    }else{
       f_index = 0;
    }
  if(key_set){
      key_set=0;
      frmID=0;
      f_index=0;
  }
  if(key_up){
      key_up=0;
      frmID=4;
      f_index=0;
  } 

}
void frmBCU_r(void){
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(2);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate();
    }else{
       f_index = 0;
    }
   if(key_set){
      key_set=0;
      frmID=0;
      f_index=0;
  } 
   if(key_up){
      key_up=0;
      frmID=1;
      f_index=0;
  } 
    
}


void frmSET(void){


}

void LCD_Exec(void) {
    switch (frmID) {
        case 0:
            frmMain();
            break;
        case 1:
            frmIC();
            break;
        case 2:
            frmBCU_f();
            break;
        case 3:
            frmBCU_m();
            break;
        case 4:
            frmBCU_r();
            break;  
            
        case 5:
             frmSET(); 
         break;
        default:
            key_up=0;
            key_set=0;
            key_AV=0;
            LCD_Clear();
            break;
    }
    if( key_duble){
        key_duble=0;
    }
}



