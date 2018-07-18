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


