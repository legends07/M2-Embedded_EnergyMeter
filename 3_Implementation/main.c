/**
 * @file Main.c
 * @author Ajish Saji (ajish.saji@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
#include "Engergymeter.h"


#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif


int main(void)
{
    DDRB = 0xFF;
    //DDRA = 0;
    DDRD = 0xFF;
    _delay_ms(50);
    
    ADMUX |=(1<<REFS0)|(1<<REFS1);
    ADCSRA |=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
    
    int16_t COUNTA = 0;
    char SHOWA [3];
     

    send_a_command(0x01); //Clear Screen 0x01 = 00000001
    _delay_ms(50);
    send_a_command(0x38);
    _delay_ms(50);
    send_a_command(0b00001111);
    _delay_ms(50);
    
    ADCSRA |=(1<<ADSC);
    while(1)
    {
        COUNTA = ADC/8.5;
        send_a_string ("Energy Meter");
        send_a_command(0x80 + 0x40 + 0);
        send_a_string ("Power(w)=");
        send_a_command(0x80 + 0x40 + 8);
        itoa(COUNTA,SHOWA,10);
        send_a_string(SHOWA);
        send_a_string ("      ");
        send_a_command(0x80 + 0);
        
    }    
}
