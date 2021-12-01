#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
#include "Function.h"



void send_a_command(unsigned char command)
{
    PORTD = command;
    PORTB &= ~ (1<<registerselection);
    PORTB |= 1<<enable;
    _delay_ms(2);
    PORTB &= ~1<<enable;
    PORTD = 0;
}

void send_a_character(unsigned char character)
{
    PORTD = character;
    PORTB |= 1<<registerselection;
    PORTB |= 1<<enable;
    _delay_ms(2);
    PORTB &= ~1<<enable;
    PORTD = 0;
}
void send_a_string(char *string_of_characters)
{
    while(*string_of_characters > 0)
    {
        send_a_character(*string_of_characters++);
    }
}
