#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
#include "Function.h"

#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif


int main(void)
{
    DDRD = 0xFF;
    DDRC = 0;
    DDRB= 0xFF;
    
    ADMUX |=(1<<REFS0);
    ADCSRA |=(1<<ADEN)|(1<<ADPS0);
    

    float i =0;
    float CURRENT = 0;
    char CURRENTSHOW [7];
    

    send_a_command(0x01); //Clear Screen 0x01 = 00000001
    _delay_ms(5);
    send_a_command(0x38);
    _delay_ms(5);
    send_a_command(0b00001111);
    _delay_ms(5);
    
    ADCSRA |=(1<<ADSC);
    
    send_a_string ("CIRCUIT DIGEST  ");
    send_a_command(0x80 + 0x40 + 0);
    send_a_string ("CURRENT=");
    send_a_command(0x80 + 0x40 + 8);
    
    while(1)
    {
        i=ADC/204.8;
        CURRENT = (2*i*1000)/2.7;//ADC/18.618;
        dtostrf(CURRENT, 4, 1, CURRENTSHOW);
        send_a_string(CURRENTSHOW);
        send_a_string("mAmp");
        //ADCSRA &=~(1<<ADSC);
        //ADCSRA |=(1<<ADSC);
        _delay_ms(50);
        send_a_command(0x80 + 0x40 + 8);
        
        //dtostr(double precision value, width, precision, string that will store the numbers);
        // Value is either a direct value plugged into this place, or a variable to contains a value.
        //Width that is used with dtostrf is the number of characters in the number that includes the negative sign (-). For instance, if the number is -532.87, the width would be 7 including the negative sign and the decimal point.
        //Precision is how many numbers would be after the decimal point in the dtostrf usage.
        //Base is the maximum number of values per digit. For instance, 2 is for binary representation (2 possible values for each digit - 0 or 1); 10 is for the common human number system (10 possible values for each digit - 0, 1, 2, 3, 4, 5, 6, 7, 8, or 9); 16 is for hexadecimal where there are 16 possible values for each digit - 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, or F. It should be understood that if the base is larger, then the alphabet will just get larger.
        //String is the variable that accepts alphanumeric characters such as a char array. After the function is executed, the string will have the number stored within the array. For instance, if an integer variable contains the number 643, then the string variable will contain "634".

        
    }
}
