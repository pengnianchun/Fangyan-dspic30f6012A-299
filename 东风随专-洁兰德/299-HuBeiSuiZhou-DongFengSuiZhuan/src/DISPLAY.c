#include "SYSTEM.h"
#include "font.h"
#include "LOGO.h"

unsigned char frmID = 0;
unsigned char f_index = 0;
unsigned char menuid = 0;
unsigned char AV_CH = 0;
unsigned char color_old[24] = {};

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

void print_SZ_1(unsigned int x, unsigned int y, //显示坐标位置//高清数字
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
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
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
            LCD_DrawImage1BPP(x + i * 16, y, BMP_SZ_1[bcd[i]], color, BLACK);
        }
    }
}

void print_SZ_4(unsigned int x, unsigned int y, //显示坐标位置 //放大4倍数字
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
    //新增加的符号片框架2016/11/1
    LCD_DrawRect(136, 128, 528, 1, GRAY);
    for (i = 1; i < 10; i++) {
        if (i == 5)
            continue;
        LCD_DrawRect(70 + 66 * i, 64, 1, 64, GRAY);
    }
    //每次进入主界面，符号片颜色都是灰色，若不处理，只会第一次上电显示灰色，翻页后就不显示灰色
    for (i = 0; i < 24; i++) {
        color_old[i] = 0;
    }
    LCD_DrawRect(0, 430, 800, 1, WHITE); //底部横线
    //LCD_DrawRect(0,70,800,3,YELLOW); //顶部横线
    // LCD_DrawImage1BPPZOOM_4(336, 150, BMP_LOGO, BLUE, BLACK); //客车车标
    //动力电池电流 电压 SOC 外观
    LCD_DrawImage1BPP(150, 155, BMP_SOC, WHITE, BLACK); //SOC
    LCD_DrawRect(225, 150 + 5, 336, 3, WHITE);
    LCD_DrawRect(225, 150 + 40, 336, 3, WHITE);
    LCD_DrawRect(225, 145, 3, 10 + 38, WHITE);
    LCD_DrawRect(225 + 83, 145, 3, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83, 145, 3, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83, 145, 3, 10, WHITE);
    LCD_DrawRect(225 + 83 + 83 + 83 + 84, 145, 3, 10 + 38, WHITE);
    LCD_DrawImage1BPP(660, 160, BMP_BAIFENHAO, WHITE, BLACK);

    //报警区域
    LCD_DrawRect(180, 365, 350 + 85, 2, WHITE);
    LCD_DrawRect(180, 365, 2, 65, WHITE);
    LCD_DrawRect(615, 365, 2, 65, WHITE);

    LCD_DrawImage1BPPZOOM_4(100 + 36, 150 + 60, BMP_DCDY, WHITE, BLACK); //电池电压
    LCD_DrawImage1BPP(320 + 36, 150 + 60 - 5, BMP_V, WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(135 + 180 + 50 + 36, 150 + 60, BMP_DCDL, WHITE, BLACK); //电池电流
    LCD_DrawImage1BPP(335 + 180 + 50 + 30 + 36, 150 + 60 - 5, BMP_A, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(100 + 36, 150 + 60 + 50, BMP_DCT, WHITE, BLACK); //电池温度
    LCD_DrawImage1BPP(320 - 10 + 36, 150 + 110 - 5, BMP_T, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(135 + 180 + 50 + 36, 150 + 70 + 40, BMP_DJT, WHITE, BLACK); //电机温度
    LCD_DrawImage1BPP(335 + 180 + 50 + 30 - 10 + 36, 150 + 110 - 5, BMP_T, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(100 + 36, 250 + 60, BMP_DJDY, WHITE, BLACK); //电机电压
    LCD_DrawImage1BPP(320 + 36, 150 + 60 + 50 + 50 - 5, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(135 + 180 + 50 + 36, 250 + 60, BMP_DJZS, WHITE, BLACK); //电机转速
    LCD_DrawImage1BPPZOOM_4(335 + 180 + 50 + 30 + 36, 150 + 60 + 50 + 50, BMP_RMP, WHITE, BLACK);

    //LCD_DrawImage1BPPZOOM_4(100, 150 + 70 + 60 + 45 + 50, BMP_DW, WHITE, BLACK); //档位

    //气压柱1外观
    //方框
    LCD_DrawRect(33, 100, 50, 3, WHITE); //
    LCD_DrawRect(33, 100, 3, 135, WHITE);
    LCD_DrawRect(83, 100, 3, 135, WHITE);

    LCD_DrawRect(33, 235, 3, 135, RED);
    LCD_DrawRect(83, 235, 3, 138, RED);
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
    LCD_DrawRect(712 + 50, 235, 3, 138, RED);
    LCD_DrawRect(712, 370, 50, 3, RED); //

    LCD_DrawImage1BPP(770, 95, BMP_SZ[1], RED, BLACK); //1
    LCD_DrawImage1BPP(770 + 8, 95, BMP_SZ[0], RED, BLACK); //0
    LCD_DrawImage1BPP(770, 225, BMP_SZ[5], RED, BLACK); //5
    LCD_DrawImage1BPP(770, 360, BMP_SZ[0], RED, BLACK); //0 

    LCD_DrawImage1BPP(712 - 7 + 32, 410, Bmp_Mpa, WHITE, BLACK); //Mpa

    /*--------------------------------------------
    以下显示的格式为:(ODO 000.0Km       00:00          TRIP0000000Km)
    ---------------------------------------------*/
    LCD_DrawImage1BPP(2, 440+3, Bmp_ODO, YELLOW, BLACK); //累计里程 ODO  
    //print_SZ_4(2+64+4,440,9999999,7,1,WHITE);

    LCD_DrawImage1BPPZOOM_4(210, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km

    LCD_DrawImage1BPP(240 + 300 + 30, 440+3, Bmp_TRIP, YELLOW , BLACK); //单次里程 TRIF
    //print_SZ_4(240+80+4,440,9999,4,1,WHITE);
    LCD_DrawImage1BPPZOOM_4(404 + 336 + 30, 440, BMP_HZ_KM, WHITE, BLACK); //单位 Km

}

void disp_miles(void) {//显示里程
    print_SZ_1(2 + 64 + 4+10, 440 - 2, total_miles, 7, 1, WHITE);
    print_SZ_1(240 + 80 + 4 + 330 + 30, 440 - 2, single_miles, 4, 1, WHITE);
}

void disp_time(unsigned int x, unsigned int y, DATE dtimer) {
    unsigned char color = 0;
    //    if(Did==0) color=RED;
    //    else       color=WHITE;

    LCD_DrawImage1BPP(x, y, BMP_SMSZ[(dtimer.hour >> 4)&0x0f], WHITE, BLACK);
    LCD_DrawImage1BPP(x + 28, y, BMP_SMSZ[dtimer.hour & 0x0f], WHITE, BLACK);

    if (F500ms_LCD) color = WHITE;
    else color = BLACK;
    LCD_DrawImage1BPP(x + 28 * 2, y + 3, BMP_SMSZ[10], color, BLACK); //冒号 

    //    if(Did==1) color=RED;
    //    else       color=WHITE;
    LCD_DrawImage1BPP(x + 28 * 3, y, BMP_SMSZ[(dtimer.minute >> 4)&0x0f], WHITE, BLACK);
    LCD_DrawImage1BPP(x + 28 * 4, y, BMP_SMSZ[dtimer.minute & 0x0f], WHITE, BLACK);

    /*****************年月日不显示**********************/
    /*
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
     */
}

void updata_QY(void) {
    unsigned char color = RED;
    unsigned int press1 = 50; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    unsigned int press2 = 90; /*气压传感器量程是0-1.2Mpa ,对应为0-120 进度条0-100*/
    press1 = ADR[4] / 27; //电压型采样   0-5V
    press2 = ADR[5] / 27;

    if (press1 > 60) color = GREEN;
    else color = RED;
    if (press1 > 100) press1 = 100;
    print_SZ(33 - 7, 410, press1, 3, 2, color);
    LCD_DrawImage1BPP(33 + 9, 380, Bmp_QY1, color, BLACK); //气压1图标
    LCD_DrawRect(38, 102, 44, (260 - press1 * 2.6), BLACK); //260/100  
    LCD_DrawRect(38, (368 - press1 * 2.6), 44, (press1 * 2.6), color);

    if (press2 > 60) color = GREEN;
    else color = RED;
    if (press2 > 100) press2 = 100;
    LCD_DrawImage1BPP(712 + 9, 380, Bmp_QY2, color, BLACK); //气压2图标
    print_SZ(712 - 7, 410, press2, 3, 2, color);
    LCD_DrawRect(712 + 5, 102, 44, (260 - press2 * 2.6), BLACK); //260/100  
    LCD_DrawRect(712 + 5, (368 - press2 * 2.6), 44, (press2 * 2.6), color);


    //LCD_DrawImage1BPP(24,328,Bmp_QY1,color,BLACK);//气压1图标

    //print_SZ(2,190,press_1,3,2,color);
    // LCD_DrawImage1BPP(38,380,Bmp_Mpa,color,BLACK);//Mpa

}

void updata_Dangwei(void) {
    unsigned char gear = 1;
    if (Current_Gear == 124) gear = 0;
    else if (Current_Gear == 125) gear = 1;
    else if (Current_Gear == 126) gear = 2;
    else if (Current_Gear == 127) gear = 3;
    else if (Current_Gear == 128) gear = 4;
    else if (Current_Gear == 129) gear = 5;
    else if (Current_Gear == 130) gear = 6;
    else if (Current_Gear == 131) gear = 7;
    LCD_DrawImage1BPPZOOM_4(100, 150 + 65 + 65 + 45 + 35 + 10, BMP_DANGWEI[gear], GREEN, BLACK); //档位更新   
}

void updata_SOC(void) {
    unsigned char color = WHITE;
    unsigned char soc = 10;
    soc = BMS_SOC / 2;
    if (soc >= 100) soc = 100;
    if (soc > 25) color = GREEN;
    else if (soc > 0 && soc <= 25) color = RED;
    else color = BLACK;
    print_SZ_1(585, 162, soc, 3, 0, WHITE); //SOC数值
    LCD_DrawRect(228, 158, (soc * 3.3), 32, color); // 330/100  
    if (soc < 100)//当soc为100时会出错
        LCD_DrawRect((228 + soc * 3.3), 158, (330 - soc * 3.3), 32, BLACK);
}

void updata_DCDY(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int DCDY = 50;
    DCDY = BMS_V * 4;
    if (DCDY < 1) color = RED;
    print_SZ_1(x, y, DCDY, 3, 0, color); //电池电压数值 x=120+72+30   y=150+60-2
}

void updata_DJDY(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int DJDY = 500;
    DJDY = moto_voltage * 4;
    if (DJDY < 1) color = RED;
    print_SZ_1(x, y, DJDY, 3, 0, color); //电机电压数值 x=120+72+35   y=250+60-2
}

void updata_DCDL(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int DCDL = 100;
    DCDL = BMS_A * 8;

    if (DCDL < 1000) {
        print_SZ_1(x, y, 1000 - DCDL, 4, 0, color);
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 4, BMP_FU, color, BLACK);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 4, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, DCDL - 1000, 4, 0, color); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
    }
}

void updata_DJDL(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int DJDL = 100;
    DJDL = moto_current * 4;

    if (DJDL < 500) {
        print_SZ_1(x, y, 500 - DJDL, 3, 0, color);
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_FU, color, BLACK);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 40, y + 4, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, DJDL - 500, 3, 0, color); //电池电流数值 x=135+180+50+100+20+20   y=150+60-2
    }
}

void updata_DCT(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int t = 80;
    t = battle_t;
    if (t < 40) {
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 5, BMP_FU, color, BLACK);
        print_SZ_1(x, y, 40 - t, 3, 0, color); //电池温度
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 20, y + 5, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, t - 40, 3, 0, color); //电池温度  x=120+75+40   y=150+70+40-7
    }
}

void updata_DJT(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int t = 80;
    t = Motor_Temperature;
    if (t < 40) {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
        print_SZ_1(x, y, 40 - t, 3, 0, color);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, t - 40, 3, 0, color); //电机温度  x=135+180+50+100+20+20   y=150+70+35
    }
}

void updata_NBQT(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int t = 80;
    t = Inverter_t;
    if (t < 40) {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
        print_SZ_1(x, y, 40 - t, 3, 0, color);
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, t - 40, 3, 0, color);
    }
}

void updata_RMP(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int rmp = 80;
    rmp = moto_speed * 20;
    if (rmp < 2000) {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_FU, color, BLACK);
        print_SZ_1(x, y, 2000 - rmp, 4, 0, color); //电流数值
    } else {
        LCD_DrawImage1BPPZOOM_4(x - 25, y + 5, BMP_ZHENG, color, BLACK);
        print_SZ_1(x, y, rmp - 2000, 4, 0, color); //电流数值 x=135+180+50+100+20+20   y=250+55
    }

}

void updata_Accelerator(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int ymtb = 80;
    ymtb = Accelerator * 4;
    if (ymtb > 1000) ymtb = 1000;
    print_SZ_1(x, y, ymtb, 4, 1, color); //电流数值 x=135+180+50+100+20+20   y=250+55


}

void updata_Brake_percent(unsigned int x, unsigned int y) {
    unsigned char color = WHITE;
    unsigned int zdtb = 80;
    zdtb = Brake_percent;
    if (zdtb > 100) zdtb = 100;
    print_SZ_1(x, y, zdtb, 3, 0, color); //电流数值 x=135+180+50+100+20+20   y=250+55


}

void updata_CAN_MainFrame_baojing(unsigned int x, unsigned int y) {
    //unsigned char color;
    static unsigned char al_index = 0;

    //if (!IN37) color = YELLOW;
    if (alarm_update_flag == 0) { //3S 更新一次 循环  x=270  y=375
        LCD_DrawRect(x, y - 5, 420, 50, BLACK); //清除显示区域
        switch (al_index) {
            case 0:
                al_index = 1;
                if (mil_lamp_request == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_JINGBAO1, YELLOW, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 1:
                al_index = 2;
                if (fail_mode == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_STOP1, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 2:
                al_index = 3;
                if (fail_mode == 2) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_STOP2, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 3:
                al_index = 4;
                if (fail_mode == 3) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_STOP3, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 4:
                al_index = 5;
                if (battle_t_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_DCT_WARN, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }

            case 5:
                al_index = 6;
                if (battle_jueyuan_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_JUEYUAN_WARN, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 6:
                al_index = 7;
                if (battle_higtv1_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_DC1GZ_WARN, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 7:
                al_index = 8;
                if (battle_higtv2_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_DC2GZ_WARN, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 8:
                al_index = 9;
                if (moto_t_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_DJTGG_WARN, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 9:
                al_index = 10;
                if (xudc == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_XDCYC_WARN, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 10:
                al_index = 11;
                if (moto_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_DJGZ, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 11:
                al_index = 12;
                if (BMS_offline_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_DC_offline, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 12:
                al_index = 13;
                if (MCU_offline_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_DJ_offline, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 13:
                al_index = 14;
                if (TCU_offline_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_TCU_offline, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 14:
                al_index = 15;
                if (Engine_offline_warn == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_Engine_offline, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 15:
                al_index = 16;
                if (Lamp_status_YELLOW == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_TCU_note, YELLOW, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 16:
                al_index = 17;
                if (Lamp_status_RED == 1) {
                    LCD_DrawImage1BPPZOOM_4(x, y, BMP_STOP4, RED, BLACK);
                    alarm_update_flag = 1;
                    break;
                }
            case 17:
                al_index = 18;
                if (CAN_18FECA03_len >= 6 || CAN_18FECAF5_len >= 6) {
                    DM_TCU(1);
                    DM_CCU(1);
                    if (tcu_spn > 100 || ccu_spn > 50000) {
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_TCU_warn, RED, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 18:
                al_index = 19;
                if (CAN_18FECAEF_len >= 6) {
                    DM_HCU(1);
                    if (((hcu_spn > 0)&&(hcu_spn <= 1000)) || ((hcu_spn >= 5600)&&(hcu_spn <= 5900)))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_HCU_warn, RED, BLACK);
                    else if ((hcu_spn > 2000)&&(hcu_spn <= 2100))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_zhuanxiangzhuli_warn, RED, BLACK);
                    else if ((hcu_spn > 520200)&&(hcu_spn <= 520280))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_MOTO_warn, RED, BLACK);
                    else if ((hcu_spn > 520280)&&(hcu_spn <= 522000))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_Battle_warn, RED, BLACK);
                    else break;
                    alarm_update_flag = 1;
                    break;
                }

            case 19:
                al_index = 20;
                if (CAN_18FECAEF_len >= 10) {
                    DM_HCU(2);
                    if (((hcu_spn > 0)&&(hcu_spn <= 1000)) || ((hcu_spn >= 5600)&&(hcu_spn <= 5900)))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_HCU_warn, RED, BLACK);
                    else if ((hcu_spn > 2000)&&(hcu_spn <= 2100))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_zhuanxiangzhuli_warn, RED, BLACK);
                    else if ((hcu_spn > 520200)&&(hcu_spn <= 520280))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_MOTO_warn, RED, BLACK);
                    else if ((hcu_spn > 520280)&&(hcu_spn <= 522000))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_Battle_warn, RED, BLACK);
                    else break;
                    alarm_update_flag = 1;
                    break;
                }

            case 20:
                al_index = 21;
                if (CAN_18FECAEF_len >= 14) {
                    DM_HCU(3);
                    if (((hcu_spn > 0)&&(hcu_spn <= 1000)) || ((hcu_spn >= 5600)&&(hcu_spn <= 5900)))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_HCU_warn, RED, BLACK);
                    else if ((hcu_spn > 2000)&&(hcu_spn <= 2100))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_zhuanxiangzhuli_warn, RED, BLACK);
                    else if ((hcu_spn > 520200)&&(hcu_spn <= 520280))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_MOTO_warn, RED, BLACK);
                    else if ((hcu_spn > 520280)&&(hcu_spn <= 522000))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_Battle_warn, RED, BLACK);
                    else break;
                    alarm_update_flag = 1;
                    break;
                }
            case 21:
                al_index = 22;
                if (CAN_18FECAEF_len >= 18) {
                    DM_HCU(4);
                    if (((hcu_spn > 0)&&(hcu_spn <= 1000)) || ((hcu_spn >= 5600)&&(hcu_spn <= 5900)))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_HCU_warn, RED, BLACK);
                    else if ((hcu_spn > 2000)&&(hcu_spn <= 2100))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_zhuanxiangzhuli_warn, RED, BLACK);
                    else if ((hcu_spn > 520200)&&(hcu_spn <= 520280))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_MOTO_warn, RED, BLACK);
                    else if ((hcu_spn > 520280)&&(hcu_spn <= 522000))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_Battle_warn, RED, BLACK);
                    else break;
                    alarm_update_flag = 1;
                    break;
                }

            case 22:
                al_index = 0;
                if (CAN_18FECAEF_len >= 22) {
                    DM_HCU(5);
                    if (((hcu_spn > 0)&&(hcu_spn <= 1000)) || ((hcu_spn >= 5600)&&(hcu_spn <= 5900)))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_HCU_warn, RED, BLACK);
                    else if ((hcu_spn > 2000)&&(hcu_spn <= 2100))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_zhuanxiangzhuli_warn, RED, BLACK);
                    else if ((hcu_spn > 520200)&&(hcu_spn <= 520280))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_MOTO_warn, RED, BLACK);
                    else if ((hcu_spn > 520280)&&(hcu_spn <= 522000))
                        LCD_DrawImage1BPPZOOM_4(x, y, BMP_Battle_warn, RED, BLACK);
                    else break;
                    alarm_update_flag = 1;
                    break;
                }
                /*  //具体显示故障码的SPN和FMI
                case 17:
                    al_index = 18;
                    if (CAN_18FECAEF_len >= 6) {
                        DM_HCU(1);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 5, 0, RED);
                        print_SZ_1(x + 230, y, hcu_fmi, 5, 0, RED);
                        alarm_update_flag = 1;
                        break;
                    }

                case 18:
                    al_index = 19;
                    if (CAN_18FECAEF_len >= 10) {
                        DM_HCU(2);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 19:
                    al_index = 20;
                    if (CAN_18FECAEF_len >= 14) {
                        DM_HCU(3);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 20:
                    al_index = 21;
                    if (CAN_18FECAEF_len >= 18) {
                        DM_HCU(4);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 21:
                    al_index = 22;
                    if (CAN_18FECAEF_len >= 22) {
                        DM_HCU(5);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 22:
                    al_index = 23;
                    if (CAN_18FECAEF_len >= 6) {
                        DM_HCU(1);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }

                case 23:
                    al_index = 24;
                    if (CAN_18FECAEF_len >= 10) {
                        DM_HCU(2);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 24:
                    al_index = 25;
                    if (CAN_18FECAEF_len >= 14) {
                        DM_HCU(3);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 25:
                    al_index = 26;
                    if (CAN_18FECAEF_len >= 18) {
                        DM_HCU(4);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                case 26:
                    al_index = 0;
                    if (CAN_18FECAEF_len >= 22) {
                        DM_HCU(5);
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 5, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 5, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                 */
            default:
                al_index = 0;
                LCD_DrawRect(x, y, 400, 50, BLACK); //清除显示区域
                break;
        }
    }
}

void disp_baojing(void) {
    //static unsigned char color_old[24] = {};
    unsigned char color = GRAY;

    if (IN34 && M_ON) color = YELLOW;
    else color = GRAY;
    if (color_old[0] != color) {
        color_old[0] = color;
        LCD_DrawImage1BPP(6, 10, Bmp_baojing[0], color, BLACK); //ASR
    }


    if ((battle_higtv1_warn == 1) || (battle_higtv2_warn == 1)) color = RED;
    else color = GRAY;
    if (color_old[1] != color) {
        color_old[1] = color;
        LCD_DrawImage1BPP(6 + 66, 10, Bmp_baojing[9], color, BLACK); //动力电池故障
    }

    if (IN19 && M_ON) color = RED;
    else color = GRAY;
    if (color_old[2] != color) {
        color_old[2] = color;
        LCD_DrawImage1BPP(6 + 66 * 2, 10, Bmp_baojing[2], color, BLACK); //门开
    }

    if (Lamp_status_YELLOW == 1 && Lamp_status_RED == 0) color = YELLOW;
    else if (Lamp_status_RED == 1) color = RED;
    else color = GRAY;
    if (color_old[3] != color) {
        color_old[3] = color;
        LCD_DrawImage1BPP(6 + 66 * 3, 10, Bmp_baojing[10], color, BLACK); //变速箱故障
    }

    if (IN26) color = GREEN;
    else color = GRAY;
    if (color_old[4] != color) {
        color_old[4] = color;
        LCD_DrawImage1BPP(6 + 66 * 4, 10, Bmp_baojing[3], color, BLACK); //干燥
    }

    if (fail_mode == 1 || Lamp_status_RED == 1) color = RED;
    else color = GRAY;
    if (color_old[5] != color) {
        color_old[5] = color;
        LCD_DrawImage1BPP(6 + 66 * 5, 10, Bmp_baojing[17], color, BLACK); //红色三角报警
    }

    if (IN17 && M_ON) color = YELLOW;
    else color = GRAY;
    if (color_old[6] != color) {
        color_old[6] = color;
        LCD_DrawImage1BPP(6 + 66 * 6, 10, Bmp_baojing[5], color, BLACK); //空滤
    }

    if (moto_t_warn == 1) color = RED;
    else if (moto_t_warn == 0) color = GRAY;
    if (color_old[7] != color) {
        color_old[7] = color;
        LCD_DrawImage1BPP(6 + 66 * 7, 10, Bmp_baojing[6], color, BLACK); //电机过温
    }

    if (Signal_charge == 1 || Signal_charge == 2 || wake_up2 == 1) color = RED; //新添加随州符号片2016/11/1
    else color = GRAY;
    if (color_old[8] != color) {
        color_old[8] = color;
        LCD_DrawImage1BPP(6 + 66 * 8, 10, Bmp_baojing[11], color, BLACK); //充电指示
    }

    if (water_level <= 20) color = RED;
    else color = GRAY;
    if (color_old[9] != color) {
        color_old[9] = color;
        LCD_DrawImage1BPP(6 + 66 * 9, 10, Bmp_baojing[8], color, BLACK); //水位
    }

    if ((mil_lamp_request == 1 || Lamp_status_YELLOW == 1)/*&&(fail_mode == 0 && Lamp_status_RED == 0)*/) color = YELLOW;
    else color = GRAY;
    if (color_old[10] != color) {
        color_old[10] = color;
        LCD_DrawImage1BPP(6 + 66 * 10, 10, Bmp_baojing[17], color, BLACK); //黄色三角报警
    }

    if (IN20 && M_ON) color = RED;
    else color = GRAY;
    if (color_old[11] != color) {
        color_old[11] = color;
        LCD_DrawImage1BPP(6 + 66 * 11, 10, Bmp_baojing[16], color, BLACK); //安全带
    }

    //if (Signal_charge == 1 || Signal_charge == 2) color = RED; //新添加随州符号片2016/11/1
    //else color = GRAY;
    //LCD_DrawImage1BPPZOOM_4(138, 74, Bmp_baojing[14], color, BLACK); //充电指示

    if (IN10) color = YELLOW;
    else color = GRAY;
    if (color_old[12] != color) {
        color_old[12] = color;
        LCD_DrawImage1BPP(138 + 66 * 1, 74, Bmp_baojing[14], color, BLACK); //燃油预热
    }

    if (IN27 && M_ON) color = RED;
    else color = GRAY;
    if (color_old[13] != color) {
        color_old[13] = color;
        LCD_DrawImage1BPP(138 + 66 * 2, 74, Bmp_baojing[12], color, BLACK); //灯丝
    }

    if (moto_ready == 1) color = GREEN;
    else if (moto_ready == 0) color = GRAY;
    if (color_old[14] != color) {
        color_old[14] = color;
        LCD_DrawImage1BPP(138 + 66 * 3, 74, Bmp_baojing2, color, BLACK); //READY
    }
    //if (IN37) color = GREEN; 
    //else color = GRAY;
    //LCD_DrawImage1BPPZOOM_4(138+66*4, 74, Bmp_baojing[16], color, BLACK);

    if (moto_warn == 1) color = RED;
    else if (moto_warn == 0) color = GRAY;
    if (color_old[15] != color) {
        color_old[15] = color;
        LCD_DrawImage1BPP(138 + 66 * 5, 74, Bmp_baojing[13], color, BLACK); //电机故障
    }

    if (EV == 1) color = GREEN;
    else color = GRAY;
    if (color_old[16] != color) {
        color_old[16] = color;
        LCD_DrawImage1BPP(138 + 66 * 6, 74, Bmp_baojing[15], color, BLACK); //EV
    }
    //if (IN10) color = YELLOW;
    //else color = GRAY;
    //LCD_DrawImage1BPPZOOM_4(138 + 66 * 7, 74, Bmp_baojing[18], color, BLACK); //燃油预热


}

void frmMain(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        mainFrame();
    } else if (f_index == 1) {
        f_index = 2;
        updata_QY();
        updata_CAN_MainFrame_baojing(190, 375);
    } else if (f_index == 2) {
        f_index = 3;
        disp_baojing();
        updata_RMP(505 + 36, 305);
    } else if (f_index == 3) {
        f_index = 4;
        disp_miles();
        updata_DCDL(505 + 36, 208);
    } else if (f_index == 4) {
        f_index = 5;
        disp_time(330, 440, timer);
    } else if (f_index == 5) {
        f_index = 6;
        updata_SOC();
        updata_Dangwei();
    } else if (f_index == 6) {
        f_index = 7;
        updata_DCDY(222 + 36, 208);
        updata_DJDY(227 + 36, 305);
    } else if (f_index == 7) {
        f_index = 1;
        updata_DCT(235 + 36, 253);
        updata_DJT(505 + 36, 255);
    } else {
        f_index = 0;
    }

    if (AV_CH == 0) { //当在数字界面
        if (key_up) { //调节背光灯
            key_up = 0;
            if (IN12 == 1) {//背光开启
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
            frmID = 1;
            f_index = 0;
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
    /***********随州未用到摄像头切换**************/
    /*
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
        unsigned char mode = 2; //2,MCU

        if (AV_CH < 4) AV_CH++;
        else AV_CH = 0;

        switch (AV_CH) {
            case 0: // DAV
                CS_E = 0; //关闭 
                mode = 1; //2,MCU
                break;
            case 1: //AV2  SP2  CJ2
                CS_E = 1; //打开 
                CS_A = 1;
                CS_B = 1;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 2: //AV2  SP3  CJ3
                CS_E = 1; //打开 
                CS_A = 0;
                CS_B = 1;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 3: //AV2  SP4  CJ4
                CS_E = 1; //打开 
                CS_A = 1;
                CS_B = 0;
                CS_C = 1;
                mode = 6; //AV2
                break;
            case 4: //AV1
                CS_E = 0; //倒车
                mode = 2; //4,AV1 
                break;
            default:
                CS_E = 0; //关闭 
                mode = 1; //2,MCU
                AV_CH = 0;
                break;
        }
        LCD_CHS(mode);
    }*/
}

void ICFrame(void) { //仪表框架
    LCD_Clear();

    LCD_DrawImage1BPPZOOM_4(320, 15, BmpZHYB, WHITE, BLACK);
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线

    LCD_DrawImage1BPPZOOM_4(35, 75, Bmp_IN1, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 1, Bmp_IN33/*备用开关*//*Bmp_IN2*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 2, Bmp_IN7/*Bmp_IN3*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 3, Bmp_IN6/*Bmp_IN4*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 4, Bmp_IN5, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 5, Bmp_IN33/*备用开关*//*Bmp_IN6*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 6, Bmp_IN33/*备用开关*//*Bmp_IN7*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 7, Bmp_IN33/*备用开关*//*Bmp_IN8*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 8, Bmp_IN33/*备用开关*//*Bmp_IN9*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 9, Bmp_ran_you_yu_re/*Bmp_IN10*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 10, Bmp_jin_qi_yu_re/*Bmp_IN11*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 11, Bmp_IN2/*Bmp_IN12*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 12, Bmp_IN33/*备用开关*//*Bmp_IN13*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 13, Bmp_qu_li_kai_guan_gao/*Bmp_IN14*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 14, Bmp_IN33/*备用开关*//*Bmp_IN15*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(35, 75 + 25 * 15, Bmp_pai_qi_zd_gao/*Bmp_IN16*/, WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(285, 75, Bmp_IN18/*Bmp_IN17*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 1, Bmp_IN33/*备用开关*//*Bmp_IN18*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 2, Bmp_IN8/*Bmp_IN19*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 3, Bmp_an_quan_dai/*Bmp_IN20*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 4, Bmp_IN33/*备用开关*//*Bmp_IN21*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 5, Bmp_IN33/*备用开关*//*Bmp_IN22*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 6, Bmp_IN33/*备用开关*//*Bmp_IN23*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 7, Bmp_IN11/*Bmp_IN24*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 8, Bmp_IN33/*备用开关*//*Bmp_IN25*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 9, Bmp_IN20/*Bmp_IN26*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 10, Bmp_deng_si_jian_ce/*Bmp_IN27*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 11, Bmp_IN33/*备用开关*//*Bmp_IN28*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 12, Bmp_pai_qi_zd_di/*Bmp_IN29*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 13, Bmp_IN33/*备用开关*//*Bmp_IN30*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 14, Bmp_qu_li_kai_guan_di/*Bmp_IN31*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 15, Bmp_IN33/*备用开关*//*Bmp_IN32*/, WHITE, BLACK);


    LCD_DrawImage1BPPZOOM_4(535, 75, Bmp_IN34/*Bmp_IN33*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 1, Bmp_IN28/*Bmp_IN34*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 2, Bmp_IN26/*Bmp_IN35*/, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 3, Bmp_IN36, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 4, Bmp_IN37, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 5, Bmp_IN38, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 6, Bmp_IN39, WHITE, BLACK);
    LCD_DrawImage1BPPZOOM_4(535, 75 + 25 * 7, Bmp_IN40, WHITE, BLACK);


}

void ICUpdate(void) {
    unsigned int dump;
    unsigned int i;

    dump = sw_input[0].byte + ((unsigned int) (sw_input[1].byte) << 8);
    for (i = 0; i < 16; i++) {
        if (i == 3 || i == 1 || i == 2 || i == 0 || i == 4 || i == 6 || i == 7 || i == 9 || i == 10 || i == 11
                || i == 13 || i == 15) {//为控火开关
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            } else {
                LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            }
        } else if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(5, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
        }
        dump = dump >> 1;
    }

    dump = sw_input[2].byte + ((unsigned int) (sw_input[3].byte) << 8);
    for (i = 0; i < 16; i++) {
        if (i == 9) {//IN26 为控火开关
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            } else {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            }
        } else if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
        }
        dump = dump >> 1;
    }

    dump = sw_input[4].byte;
    for (i = 0; i < 8; i++) {//WAKE1 WAKE2 WAKE3为控火开关
        if (i == 5 || i == 6 || i == 7) {
            if ((dump & 0x01) == 0x01)
                LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            else
                LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
        } else
            LCD_DrawImage1BPP(505, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
        dump = dump >> 1;
    }

}

void frmIC(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        ICFrame();
    } else if (f_index == 1) {
        f_index = 1;
        ICUpdate();
    } else {
        f_index = 0;
    }


    if (key_up) { //子菜单切换
        key_up = 0;
        frmID = 1;
        f_index = 0;
    }

    if (key_AV) {
        key_AV = 0;
    }
    if (key_set) {//主菜单/子菜单切换
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

void BCUFrame(unsigned char index) {
    LCD_Clear();

    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线
    if (index == 0) {
        LCD_DrawImage1BPPZOOM_4(320, 15, BmpQMK, WHITE, BLACK);

        LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_F_OUT1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 1, BmpBCU_F_OUT2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 2, BmpBCU_F_OUT3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 3, BmpBCU_F_OUT4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 4, BmpBCU_F_OUT5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 5, BmpBCU_F_OUT6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 6, BmpBCU_F_OUT7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 7, BmpBCU_F_OUT8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 8, BmpBCU_F_OUT9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 9, BmpBCU_F_OUT10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 10, BmpBCU_F_OUT11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 11, BmpBCU_F_OUT12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 12, BmpBCU_F_OUT13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 13, BmpBCU_F_OUT14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_F_OUT15, WHITE, BLACK);

        LCD_DrawImage1BPPZOOM_4(285, 75, BmpBCU_F_KL1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 1, BmpBCU_F_KL2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 2, BmpBCU_F_KL3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 3, BmpBCU_F_KL4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 4, BmpBCU_F_KL5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 5, BmpBCU_F_KL6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 6, BmpBCU_F_KL7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 7, BmpBCU_F_KL8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 8, BmpBCU_F_KL9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 9, BmpBCU_F_KL10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 10, BmpBCU_F_KL11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 11, BmpBCU_F_KL12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 12, BmpBCU_F_KL13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 13, BmpBCU_F_KL14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 14, BmpBCU_F_KL15, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 15, BmpBCU_F_KH1, WHITE, BLACK);
    } else if (index == 1) {
        LCD_DrawImage1BPPZOOM_4(320, 15, BmpZMK, WHITE, BLACK);

        LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_M_OUT1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 1, BmpBCU_M_OUT2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 2, BmpBCU_M_OUT3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 3, BmpBCU_M_OUT4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 4, BmpBCU_M_OUT5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 5, BmpBCU_M_OUT6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 6, BmpBCU_M_OUT7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 7, BmpBCU_M_OUT8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 8, BmpBCU_M_OUT9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 9, BmpBCU_M_OUT10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 10, BmpBCU_M_OUT11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 11, BmpBCU_M_OUT12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 12, BmpBCU_M_OUT13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 13, BmpBCU_M_OUT14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_M_OUT15, WHITE, BLACK);


        LCD_DrawImage1BPPZOOM_4(285, 75, BmpBCU_M_KL1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 1, BmpBCU_M_KL2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 2, BmpBCU_M_KL3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 3, BmpBCU_M_KL4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 4, BmpBCU_M_KL5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 5, BmpBCU_M_KL6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 6, BmpBCU_M_KL7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 7, BmpBCU_M_KL8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 8, BmpBCU_M_KL9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 9, BmpBCU_M_KL10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 10, BmpBCU_M_KL11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 11, BmpBCU_M_KL12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 12, BmpBCU_M_KL13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 13, BmpBCU_M_KL14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 14, BmpBCU_M_KL15, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 15, BmpBCU_M_KH1, WHITE, BLACK);
    } else if (index == 2) {

        LCD_DrawImage1BPPZOOM_4(320, 15, BmpHMK, WHITE, BLACK);

        LCD_DrawImage1BPPZOOM_4(60, 75, BmpBCU_R_OUT1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 1, BmpBCU_R_OUT2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 2, BmpBCU_R_OUT3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 3, BmpBCU_R_OUT4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 4, BmpBCU_R_OUT5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 5, BmpBCU_R_OUT6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 6, BmpBCU_R_OUT7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 7, BmpBCU_R_OUT8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 8, BmpBCU_R_OUT9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 9, BmpBCU_R_OUT10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 10, BmpBCU_R_OUT11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 11, BmpBCU_R_OUT12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 12, BmpBCU_R_OUT13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 13, BmpBCU_R_OUT14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(60, 75 + 25 * 14, BmpBCU_R_OUT15, WHITE, BLACK);

        LCD_DrawImage1BPPZOOM_4(285, 75, BmpBCU_R_KL1, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 1, BmpBCU_R_KL2, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 2, BmpBCU_R_KL3, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 3, BmpBCU_R_KL4, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 4, BmpBCU_R_KL5, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 5, BmpBCU_R_KL6, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 6, BmpBCU_R_KL7, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 7, BmpBCU_R_KL8, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 8, BmpBCU_R_KL9, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 9, BmpBCU_R_KL10, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 10, BmpBCU_R_KL11, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 11, BmpBCU_R_KL12, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 12, BmpBCU_R_KL13, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 13, BmpBCU_R_KL14, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 14, BmpBCU_R_KL15, WHITE, BLACK);
        LCD_DrawImage1BPPZOOM_4(285, 75 + 25 * 15, BmpBCU_R_KH1, WHITE, BLACK);

    }
}

void BCUUpdate(unsigned char index) {
    unsigned int dump;
    unsigned int i;

    /*前控模块*/
    if (index == 0) {
        dump = fPOUT.WORDS; //POUT0 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = fKEY.BYTES[0]+((unsigned int) (fKEY.BYTES[1]) << 8); //KL0-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = fKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
    }

    /*中控模块*/
    if (index == 1) {
        dump = mPOUT.WORDS; //POUT0 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = mKEY.BYTES[0]+((unsigned int) (mKEY.BYTES[1]) << 8); //KL0-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = mKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
    }

    /*后控模块*/
    if (index == 2) {
        dump = rPOUT.WORDS; //POUT0 -POUT15   
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(30, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = rKEY.BYTES[0]+((unsigned int) (rKEY.BYTES[1]) << 8); //KL0-KL15
        for (i = 0; i < 15; i++) {
            if ((dump & 0x01) == 0x01) {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[1], GREEN, BLACK);
            } else {
                LCD_DrawImage1BPP(255, 75 + 25 * i, Bmpflag[0], WHITE, BLACK);
            }
            dump = dump >> 1;
        }

        dump = rKEY.BYTES[2]; //KH1
        if ((dump & 0x01) == 0x01) {
            LCD_DrawImage1BPP(255, 75 + 25 * 15, Bmpflag[1], GREEN, BLACK);
        } else {
            LCD_DrawImage1BPP(255, 75 + 25 * 15, Bmpflag[0], WHITE, BLACK);
        }
    }
}

void frmBCU_f(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(0);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate(0);
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        frmID = 3;
        f_index = 0;
    }


}

void frmBCU_m(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(1);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate(1);
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        frmID = 4;
        f_index = 0;
    }

}

void frmBCU_r(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        BCUFrame(2);
    } else if (f_index == 1) {
        f_index = 1;
        BCUUpdate(2);
    } else {
        f_index = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_up) {
        key_up = 0;
        frmID = 5;
        f_index = 0;
    }

}

void DJFrame(void) {

    LCD_Clear();

    LCD_DrawImage1BPPZOOM_4(320, 15, BMP_DJXT, WHITE, BLACK);
    LCD_DrawRect(0, 70, 800, 2, YELLOW); //顶部横线


    LCD_DrawImage1BPPZOOM_4(100 - 24, 150 + 60, BMP_DJDY, WHITE, BLACK); //电机电压
    LCD_DrawImage1BPP(320 - 24, 150 + 60 - 5, BMP_V, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(135 + 180 + 50, 150 + 60, BMP_DJDL, WHITE, BLACK); //电机电流
    LCD_DrawImage1BPP(335 + 180 + 50 + 30, 150 + 60 - 5, BMP_A, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(100 - 24, 150 + 60 + 50, BMP_DCT, WHITE, BLACK); //电池温度
    LCD_DrawImage1BPP(320 - 10 - 24, 150 + 110 - 5, BMP_T, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(135 + 180 + 50, 150 + 70 + 40, BMP_DJT, WHITE, BLACK); //电机温度
    LCD_DrawImage1BPP(335 + 180 + 50 + 30 - 10, 150 + 110 - 5, BMP_T, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(100 - 24, 250 + 60, BMP_DJZS, WHITE, BLACK); //电机转速
    LCD_DrawImage1BPPZOOM_4(320 - 24, 150 + 60 + 50 + 50, BMP_RMP, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(135 + 180 + 50, 250 + 60, BMP_NBQT, WHITE, BLACK); //逆变器温度
    LCD_DrawImage1BPP(335 + 180 + 50 + 30 - 10 + 48, 150 + 60 + 50 + 50, BMP_T, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(100 - 24, 300 + 60, BMP_ZDTB, WHITE, BLACK); //制动踏板开度
    LCD_DrawImage1BPP(135 + 180 + 50 - 24, 300 + 60 - 5, BMP_BAIFENHAO, WHITE, BLACK);

    LCD_DrawImage1BPPZOOM_4(135 + 180 + 50, 300 + 60, BMP_YMTB, WHITE, BLACK); //油门踏板开度
    LCD_DrawImage1BPP(335 + 180 + 50 + 30 + 48 + 24, 300 + 60, BMP_BAIFENHAO, WHITE, BLACK);
}

void DJUpdate(unsigned int x, unsigned int y) {
    static unsigned char al_index = 0;
    if (alarm_update_flag == 0) { //3S 更新一次 循环  x=270  y=375
        // LCD_DrawRect(x, y - 5, 320, 50, BLACK); //清除显示区域
        switch (al_index) {
                //具体显示故障码的SPN和FMI
            case 0:
                al_index = 1;
                if (CAN_18FECAEF_len >= 6) {
                    DM_HCU(1);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 230, y, hcu_fmi, 4, 0, RED);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 1:
                al_index = 2;
                if (CAN_18FECAEF_len >= 10) {
                    DM_HCU(2);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 2:
                al_index = 3;
                if (CAN_18FECAEF_len >= 14) {
                    DM_HCU(3);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 3:
                al_index = 4;
                if (CAN_18FECAEF_len >= 18) {
                    DM_HCU(4);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 4:
                al_index = 5;
                if (CAN_18FECAEF_len >= 22) {
                    DM_HCU(5);
                    if (hcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, hcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, hcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 5:
                al_index = 6;
                if (CAN_18FECA03_len >= 6) {
                    DM_TCU(1);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 6:
                al_index = 7;
                if (CAN_18FECA03_len >= 10) {
                    DM_TCU(2);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 7:
                al_index = 8;
                if (CAN_18FECA03_len >= 14) {
                    DM_TCU(3);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 8:
                al_index = 9;
                if (CAN_18FECA03_len >= 18) {
                    DM_TCU(4);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }
            case 9:
                al_index = 10;
                if (CAN_18FECA03_len >= 22) {
                    DM_TCU(5);
                    if (tcu_spn > 0) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, tcu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, tcu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            case 10:
                al_index = 0;
                if (CAN_18FECAF5_len >= 6) {
                    DM_CCU(1);
                    if (ccu_spn > 50000) {
                        LCD_DrawImage1BPPZOOM_4(x, y + 5, BMP_SPN, WHITE, BLACK);
                        print_SZ_1(x + 50, y, ccu_spn, 6, 0, RED);
                        print_SZ_1(x + 120 + 110, y, ccu_fmi, 4, 0, RED);
                        LCD_DrawImage1BPPZOOM_4(x + 190, y + 5, BMP_FMI, WHITE, BLACK);
                        alarm_update_flag = 1;
                        break;
                    }
                }

            default:
                al_index = 0;
                LCD_DrawRect(x, y, 320, 50, BLACK); //清除显示区域
                break;
        }
    }


    //电机状态
    if (MCU_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(50 + 30, 80, BMP_MCU_online, GREEN, BLACK);
        LCD_DrawRect(50 + 96 + 30, 80, 25, 30, BLACK); //残留覆盖
    } else if (MCU_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(50 + 30, 80, BMP_DJ_offline_1, RED, BLACK);

    //电池状态
    if (BMS_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(200 + 30, 80, BMP_BMS_online, GREEN, BLACK);
        LCD_DrawRect(200 + 96 + 30, 80, 25, 30, BLACK);
    } else if (BMS_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(200 + 30, 80, BMP_DC_offline_1, RED, BLACK);

    //变速箱状态
    if (TCU_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(350 + 30, 80, BMP_TCU_online, GREEN, BLACK);
        LCD_DrawRect(350 + 120 + 30, 80, 25, 30, BLACK);
    } else if (TCU_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(350 + 30, 80, BMP_TCU_offline_1, RED, BLACK);

    //发动机状态
    if (Engine_offline_warn == 0x3) {
        LCD_DrawImage1BPPZOOM_4(500 + 24 + 30, 80, BMP_Engine_online, GREEN, BLACK);
        LCD_DrawRect(500 + 120 + 24 + 30, 80, 25, 30, BLACK);
    } else if (Engine_offline_warn == 1)
        LCD_DrawImage1BPPZOOM_4(500 + 24 + 30, 80, BMP_Engine_offline_1, RED, BLACK);

    updata_DJDY(198, 208); //(120+72+35,250+60-2);
    updata_DJDL(520, 208);
    updata_DCT(211, 253);
    updata_DJT(505, 255);
    updata_RMP(213, 308); //(135+180+50+100+20+20,250+55);
    updata_NBQT(553, 308);
    updata_Accelerator(553, 358);
    updata_Brake_percent(235 + 18, 358);

}

void frmDJ(void) {
    if (f_index == 0) { //只更新一次
        f_index = 1;
        DJFrame();
    } else if (f_index == 1) {
        f_index = 1;
        DJUpdate(270, 450);
    } else {
        f_index = 0;
    }


    if (key_up) {
        key_up = 0;
        frmID = 2;
        f_index = 0;
    }

    if (key_AV) {
        key_AV = 0;
    }
    if (key_set) {
        key_set = 0;
        frmID = 0;
        f_index = 0;
    }
    if (key_long_set) {
        key_long_set = 0;
    }

}

void frmSET(void) {


}

void LCD_Exec(void) {
    switch (frmID) {
        case 0:
            frmMain();
            break;
        case 1:
            frmDJ();
            break;
        case 2:
            frmIC();
            break;
        case 3:
            frmBCU_f();
            break;
        case 34:
            frmBCU_m();
            break;
        case 5:
            frmBCU_r();
            break;
        case 6:
            frmSET();
            break;
        default:
            key_up = 0;
            key_set = 0;
            key_AV = 0;
            LCD_Clear();
            break;
    }
    if (key_duble) {
        key_duble = 0;
    }
}



