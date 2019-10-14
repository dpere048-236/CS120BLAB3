/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned char BitManip1(unsigned char a, unsigned char b, unsigned char c){ //sets the bit
	return(c ? a | (0x01 << b):a & ~(0x01 << b));
}
unsigned char BitManip2(unsigned char a, unsigned char b){ //gets the bit
	return((a & (0x01 << b))!=0);
}

int main(void) {
    /* Insert DDR and PORT initializations */ 

	DDRA = 0x00; PORTA = 0xFF; //port A 8 pins = inputs
        DDRB = 0x00; PORTB = 0xFF; //portB 8 pins = INputs, sets to 1s
        DDRC = 0xFF; PORTC = 0x00; //pC 8 pins = outputs, set to 0s
	unsigned char tmpB = 0x00; //temp vriable for B
        unsigned char tmpA = 0x00; //variable for A
        unsigned char  buttonC = 0x00; //temp variable for portA+B
	unsigned char i = 0;
    /* Insert your solution below */
    while (1) {
        tmpA = PINA; //pins on A se
	tmpB = PINB;
	buttonC = 0x00;
	for(i = 0; i < 8; i++){
		if(BitManip2(tmpA, i)){
			buttonC++;
		}
}
	for(i = 0; i < 8; i++){
		if(BitManip2(tmpB, i)){
			buttonC++;
	}
}
PORTC = buttonC; //receives output
}
return 0;
}
