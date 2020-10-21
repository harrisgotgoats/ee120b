/*	Author: hshep002
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

int main(void) {
    /* Insert DDR and PORT initializations */

	//idk this might be initializatino?
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0x00;
	PORTB = 0xFF;


	DDRC = 0xFF;
	PORTC = 0x00;

	unsigned char fuelLevel = 0x00;
//	unsigned char pA1 = 0x00;
//	unsigned char pB0 = 0x00;
    /* Insert your solution below */
   while (1) {
//	pA0 = PINA & 0x01;
//	pA1 = PINA & 0x02;
//	lab3 counting 1's in ports
	fuelLevel = 0x00;
	switch(PORTA) {
	case 1:
	case 2:
		//pc5 lights
		fuelLevel = 0x20;
		break;
	case 3:
	case 4:
		//pc4 and 5
		fuelLevel = 0x30;
		break;
	case 5:
	case 6:
		//pc 5,4 3 ,
		fuelLevel = 0x38;
		break;
	case 7:
	case 8:
	case 9:
		//pc 5 4 3 2
		fuelLevel = 0x3C;
		break;
	case 10:
	case 11:
	case 12:
		//pc 5 4 3 2 1
		fuelLevel = 0x3E;
		break;
	case 13:
	case 14:
	case 15:
		fuelLevel = 0x3F;
		break;
	default:
		fuelLevel = 0x00;
		break;
	}
	//low fuel warning
	if(PORTA < 5)//if 4 or less
	{
		fuelLevel = fuelLevel | 0x40;//pc6
	}	

	PORTC = fuelLevel;

    }
    return 1;
}