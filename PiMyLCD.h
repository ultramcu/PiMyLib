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

PiMyLib
    + PiMyLCD Version 1.0 Release Date 24/02/2013
        - Support LCD5110 Graphic mode, Text Move 
        - LCD16x2 on 4 & 8 Bit Data Mode

*/



#ifndef _mii_lcd_h
#define _mii_lcd_h

#include <bcm2835.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define _LCD_TYPE_PCD8544_ 1
#define _LCD_TYPE_16x2_ 2


#define _LCD_TYPE_16x2_MODE_4_BIT 1
#define _LCD_TYPE_16x2_MODE_8_BIT 2

typedef struct
{
    RPiGPIOPin sec;
    RPiGPIOPin rst;
    RPiGPIOPin dc;
    RPiGPIOPin sdin;
    RPiGPIOPin sclk;

    uint8_t show_inverse;
    
}st_lcd_pcd8544;


typedef struct
{
    
    //RPiGPIOPin rw;
    RPiGPIOPin rs;
    RPiGPIOPin en;
    RPiGPIOPin data[8];

    uint8_t data_mode;
    
}st_lcd_16x2;


typedef struct
{
    uint8_t lcd_type;
    st_lcd_pcd8544 lcd_pcd_8544;
    st_lcd_16x2 lcd_16x2;
    
    
    //char char_sel;
    uint16_t char_pos;
    uint8_t char_data;
    char lcd_buff[85];

    char pmsg[255];
    
}st_lcd;



int init_gpio(st_lcd *lcd);
void gpio_on(RPiGPIOPin pin);
void gpio_off(RPiGPIOPin pin);


int printl(st_lcd *lcd,uint8_t auto_cut,uint8_t pos_x,uint8_t pos_y, char *fmt, ... );
void draw_image_84x48(st_lcd *lcd,unsigned char display_mode,unsigned char *image);

void lcd_test(st_lcd *lcd);
void glcd_test(st_lcd *lcd);


void delay_us(unsigned long int cnt);
void delay_ms(unsigned long int cnt);

void lcd_init(st_lcd *lcd);
void lcd_clear(st_lcd *lcd);
void lcd_write_data_or_cmd(st_lcd *lcd,uint8_t is_data, uint8_t data_or_cmd);
void i2c_write_to_5110(st_lcd *lcd,char data);
void lcd_goto_xy(st_lcd *lcd,uint8_t x, uint8_t y);
void lcd_print_char(st_lcd *lcd,uint8_t cvar);




#endif
