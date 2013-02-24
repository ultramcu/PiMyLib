
/*
NOTE

HARDWARE : Raspberry PI
IO_LIB : BCM2835 (http://www.open.com.au/mikem/bcm2835/)
AUTHER : MaIII Themd
EMAIL : maiii.themd@gmail.com
COMPILER : gcc version 4.6.3 (Debian 4.6.3-12+rpi1)
SINCE : 19/02/2013

Copyright MaIII Themd 
WEB : http://www.pishared.com/
FB : https://www.facebook.com/pages/Pi-Shared/350972691684305

main.c for test PiMyLCD

*/

#include <stdio.h>
#include "PiMyLCD.h"


st_lcd LCD;


void use_lcd16x2()
{


    int i = 0;
    int cnt_show = 0;
    char loading[20];
    double percen = 0;

    memset(loading,' ',sizeof(loading));

    LCD.lcd_type = _LCD_TYPE_16x2_;
    LCD.lcd_16x2.data_mode = _LCD_TYPE_16x2_MODE_8_BIT;
    LCD.lcd_16x2.rs = RPI_GPIO_P1_11;
    LCD.lcd_16x2.en = RPI_GPIO_P1_15;

    LCD.lcd_16x2.data[0] = RPI_GPIO_P1_16;
    LCD.lcd_16x2.data[1] = RPI_GPIO_P1_18;
    LCD.lcd_16x2.data[2] = RPI_GPIO_P1_19;
    LCD.lcd_16x2.data[3] = RPI_GPIO_P1_21;
    LCD.lcd_16x2.data[4] = RPI_GPIO_P1_22;
    LCD.lcd_16x2.data[5] = RPI_GPIO_P1_23;
    LCD.lcd_16x2.data[6] = RPI_GPIO_P1_24;
    LCD.lcd_16x2.data[7] = RPI_GPIO_P1_26;

 

    
    if(init_gpio(&LCD) != 0)
    {
        printf("Initial GPIO Failed\r\n");
        return;
    }
    lcd_init(&LCD);
    lcd_clear(&LCD);



    sleep(2);

  

    lcd_clear(&LCD);
    sleep(1);
    printl(&LCD,0,2,0,"Raspberry Pi");
    sleep(2);
    lcd_clear(&LCD);
    sleep(1);
    printl(&LCD,0,2,1,"Raspberry Pi");
    sleep(2);

    for(i = 0; i < 16; i++)
    {
        loading[i] = '|';
        printl(&LCD,0,0,0,"%s",loading);
        percen = (float)(100.0/16.0) * (i + 1);
        printl(&LCD,0,0,1," Loading %4.2f%%",percen);
        usleep(30000);
    }
    sleep(2);

    
    printl(&LCD,0,0,0,"  comming soon  ");
    printl(&LCD,0,0,1,"Free D/L PiMyLib");
    sleep(3);
    printl(&LCD,0,0,0,"www.PiShared.com");
    sleep(1);
    printl(&LCD,0,0,1,"   io[^+^]>/    ");

    sleep(3);
    printl(&LCD,0,0,1,"www.PiShared.com");

}

void use_lcd5110()
{



    LCD.lcd_type = _LCD_TYPE_PCD8544_;
    LCD.lcd_pcd_8544.sec = RPI_GPIO_P1_11;
    LCD.lcd_pcd_8544.rst = RPI_GPIO_P1_15;
    LCD.lcd_pcd_8544.dc = RPI_GPIO_P1_16;
    LCD.lcd_pcd_8544.sdin = RPI_GPIO_P1_18;
    LCD.lcd_pcd_8544.sclk = RPI_GPIO_P1_22;
    LCD.lcd_pcd_8544.show_inverse = 0;


    if(init_gpio(&LCD) != 0)
    {
        printf("Initial GPIO Failed\r\n");
        return;
    }
    lcd_init(&LCD);
    lcd_clear(&LCD);

    printl(&LCD,1,0,1,"Free Lib For \n Raspberry Pi ");
    printl(&LCD,1,0,4," PiMyLib V%1.1f ",1);
    printl(&LCD,1,0,5," %s ","PiShared.com");

    sleep(5);
    glcd_test(&LCD);

}



int main()
{


         
    use_lcd16x2();
    //use_lcd5110();   


    return 0;
    

}


