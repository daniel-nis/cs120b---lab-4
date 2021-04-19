#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Init, Lock, PressPnd, ReleasePnd, PressY, Unlock } State;

void Tick() {
    unsigned char pa = PINA;
    //unsigned char pa1 = PINA & 0x02;
    //unsigned char r = PINA & 0x03;

    switch(State) {

         case Init:
            State = Lock;
            break;

        case Lock:
            if (pa == 0x04){
                State = PressPnd;
            }
            else {
                State = Lock;
            }
            break;

        case PressPnd:
            if (pa == 0x04){
                State = PressPnd;
            }
            else if (pa == 0x00) {
                State = ReleasePnd;
            }
            else {
                State = Lock;
            }
            break;

        case ReleasePnd:
            if (pa == 0x00){
                State = ReleasePnd;
            }
            else if (pa == 0x02){
                State = PressY;
            }
            else {
                State = Lock;
            }
            break;

        case PressY:
            if (pa == 0x02){
                State = PressY;
            }
            else if (pa == 0x00) {
                State = Unlock;
            }
            break;


        case Unlock:
            if (pa == 0x00){
                State = Unlock;
            }
            else if (pa == 0x80){
                State = Lock;
            }
            break;

    }
    switch(State) {

        case Init:
            PORTB = 0x00;
            break;

        case Lock:
            PORTB = 0x00;
            break;

        case PressPnd:
            break;

        case ReleasePnd:
            break;

        case PressY:
            break;

        case Unlock:
            PORTB = 0x01;
            break;

        default:
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
        //DDRC = 0xFF; PORTC = 0x00;
        //DDRD = ; PORTD = ;

        /* Insert your solution below */
        while (1) {
            Tick();
        }
        return 1;
}
                       