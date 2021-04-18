#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Init, s0, wait, s1, wait2 } State;

void Tick() {
    unsigned char pa0 = PINA & 0x01;

    switch(State) {

         case Init:
            State = s0;
            break;

	case s0:
            if (pa0 == 0x01){
                State = s0;
            }
            else {
                State = wait;
            }
            break;

         case wait:
            if (pa0 == 0x01){
                State = s1;
            }
            else {
                State = wait;
            }
            break;

        case s1:
            if (pa0 == 0x01) {
                State = s1;
            }
            else {
                State = wait2;
            }
            break;

        case wait2:
            if (pa0 == 0x01) {
                State = s0;
            }
            else {
                State = wait2;
            }

    }
    switch(State) {

        case Init:
            PORTB = 0x01;

        case wait:
            break;

        case s0:
            PORTB = 0x01;
            break;

        case s1:
            PORTB = 0x02;
            break;

        case wait2:
            break;

        default:
            PORTB = 0x01;
            break;
    }
}


int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
        //DDRC = ; PORTC = ;
        //DDRD = ; PORTD = ;

        /* Insert your solution below */
        while (1) {
            Tick();
        }
        return 1;
}
