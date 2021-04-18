#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Init, Press, Inc, IncWait, Dec, DecWait, Reset } State;

void Tick() {
    unsigned char pa = PINA & 0x0F;
    //unsigned char pa1 = PINA & 0x02;
    //unsigned char r = PINA & 0x03;

    switch(State) {

         case Init:
            State = Press;
            break;

	case Press:
            if (pa == 0x01){
                State = Inc;
            }
            else if (pa == 0x02){
                State = Dec;
            }
	    else if (pa == 0x03){
		State = Reset;
	    }
            break;
	
	case Inc:
            if (pa == 0x03){
                State = Reset;
            }
            else {
                State = IncWait;
            }
            break;

	case IncWait:
            if (pa == 0x01){
                State = IncWait;
            }
            else if (pa == 0x00){
                State = Press;
            }
            else if (pa == 0x03){
                State = Reset;
            }
            break;
	
	case Dec:
            if (pa == 0x03){
                State = Reset;
            }
            else {
                State = DecWait;
            }
            break;


	case DecWait:
            if (pa == 0x02){
                State = DecWait;
            }
            else if (pa == 0x00){
                State = Press;
            }
            else if (pa == 0x03){
                State = Reset;
            }
            break;
	
	case Reset:
            State = Press;
            break;

    }
    switch(State) {

        case Init:
            PORTC = 0x07;
	    break;

        case Press:
            break;

        case Inc:
            if (PORTC < 9) {
		PORTC++;
	    }
            break;

        case Dec:
            if (PORTC > 0) {
		PORTC--;
	    }
            break;

	case IncWait:
            break;

	case DecWait:
            break;

        case Reset:
	    PORTC = 0x00;
            break;

        default:
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        //DDRB = 0xFF; PORTB = 0x00;
        DDRC = 0xFF; PORTC = 0x00;
        //DDRD = ; PORTD = ;

        /* Insert your solution below */
        while (1) {
            Tick();
        }
        return 1;
}
