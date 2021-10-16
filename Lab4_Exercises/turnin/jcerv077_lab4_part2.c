/*	Author: jcerv077
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

enum States{start_point,wait, PA0_press, PA1_press,reset_press, reset_wait ,PA0_wait,PA1_wait} state;
unsigned char TOTAL; 
unsigned char button;

void tick(){
    button = 0x00;
    button = PINA & 0x03;
    
    switch(state){
        case start_point: 
            state = wait;
            break;

        case wait:
            if(button == 0x01){
                state = PA0_press; //Go to the press PA0 state in the next switch and add 1.
            }
            else if(button == 0x02){
                state = PA1_press; //Go to the press PA1 state in the next switch and add 1.
            }
            else if(button == 0x03){
                state = reset_press;//Go to the reset_press state and reset TOTAL to zero
            }else{
                state = wait; //if unkown value stay in wait until valid value is entered.
            }
            break;

        case PA0_press:
            if(button == 0x01){
                state = PA0_wait; //Go to PA0_wait because in order to increment again PINA has  
                                  //to be a new value
            }else{
                state = wait;
            }
            break;

        case PA0_wait:
            if(button == 0x01){
                state = PA0_wait; //Continue in this state until a new value is entered.
            }else{
                if(button == 0x01){
                    state = PA0_press; //Go to the press PA0 state in the next switch and add 1.
                }
                else if(button == 0x02){
                    state = PA1_press; //Go to the press PA1 state in the next switch and add 1.
                }
                else if(button == 0x03){
                    state = reset_press;//Go to the reset_press state and reset TOTAL to zero
                }else{
                    state = wait; //if unkown value stay in wait until valid value is entered.
                }
            }
            break;
        
        case PA1_press:
            if(button == 0x02){
                state = PA1_wait; //Go to PA0_wait because in order to increment again PINA has  
                                  //to be a new value
            }else{
                state = wait;
            }
            break;

        case PA1_wait:
            if(button == 0x02){
                state = PA1_wait; //Continue in this state until a new value is entered.
            }else{
                if(button == 0x01){
                    state = PA0_press; //Go to the press PA0 state in the next switch and add 1.
                }
                else if(button == 0x02){
                    state = PA1_press; //Go to the press PA1 state in the next switch and add 1.
                }
                else if(button == 0x03){
                    state = reset_press;//Go to the reset_press state and reset TOTAL to zero
                }else{
                    state = wait; //if unkown value stay in wait until valid value is entered.
                }
            }
            break;

        case reset_press:
            if(button == 0x03){
                state = reset_wait;
            }else{
                state = wait;
            }
            break;
        
        case reset_wait:
            if(button == 0x03){
                state = reset_wait;
            }else{
                if(button == 0x01){
                    state = PA0_press; //Go to the press PA0 state in the next switch and add 1.
                }
                else if(button == 0x02){
                    state = PA1_press; //Go to the press PA1 state in the next switch and add 1.
                }
                else if(button == 0x03){
                    state = reset_press;//Go to the reset_press state and reset TOTAL to zero
                }else{
                    state = wait; //if unkown value stay in wait until valid value is entered.
                }
            }

        
        default:
            //error
            //PORTC=0xFF;
            break; 


    } 


    switch(state){
        case PA0_press:
            if(TOTAL == 0x09){
                //Do nothing
              //  state = wait;
            //    button = 0x00;
            }
            else{
                TOTAL++;
              //  state = wait;
                //button = 0x00;
            }
        break;

        

        case PA1_press:
            if(TOTAL == 0x00){
                //Do nothing
             //   state = wait;
               // button = 0x00;
            }
            else{
                TOTAL--;
             //   state = wait;
               // button = 0x00;
            }
            break;
        
        case reset_press:
            TOTAL = 0x00;
           // state = wait;
            break;
        
        default:
            //error
            //PORTC=0xFF;
            break;
    }

    PORTC = TOTAL;

}

int main(void) {
    	//Set the proper inputs and outputs
    DDRA = 0x00; PORTA = 0xFF; //Configure port A's pins as inputs
   // DDRB = 0xFF; PORTB = 0x00; //Configure port A's pins as inputs
    DDRC = 0xFF; PORTC = 0x00; //Configure port C's pins as outputs
    //DDRD = 0xFF; PORTD = 0x00; //Configure port A's pins as outputs 
    
    //Initialize the starting point
    state = start_point;
    TOTAL = 0x07; //initialize to 0x07
    PORTC = 0x07; //Starting point is 7

    /* Insert your solution below */
    while (1) {
        tick();
        

    }
}