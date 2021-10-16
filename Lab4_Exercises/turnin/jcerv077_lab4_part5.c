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
#include <stdbool.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"

#endif

//# = 0x43
//X = 0x58
//Y = 0x59

enum States{start_point, init , correct_pressed, correct_release, Unlock, Locking, PINA7_press} state;
unsigned char sequence[] = {4, 1,2 , 1}; 
unsigned char button;
unsigned char value = 0x00;
unsigned char reset = 0x00;

//bool hashtag_Set;


void tick(){
    button = PINA & 0x87;
    

        if(button == 0x80){
            PORTB = 0x00; 
            state = init;     
            value = 0x00;       
        }

    switch(state){
        
        case start_point:
            state = init;
            break;  
    
        case init:
            if(button == sequence[value]){
                state = correct_pressed;
            }else if(PORTB == 0x01 && button ==sequence[value]){
                state = correct_pressed;
            }
            else
            {
                state = init;
                
            }
            break;

        case correct_pressed:
        //////////////
            if(value == 0x03 && button == 0x00 ){
                PORTB = 0x01;
                state == init;
                value = 0x00;
                //PORTC = 5;
            }
            else if(button == sequence[value]){
                state = correct_pressed;
            }
            else if(button == 0x00){
                state = correct_release;
                value++;
                //PORTC =5;
                
            }else{
                state = init;
                value = 0x00;
            }
            break;

        case correct_release:
            if(button == sequence[value])
            {
                state = correct_pressed;
                
                //PORTC = value;


                 
            }else if(button == 0x00)
            {
                state = correct_release;
                //PORTC = 5;
                

            }else{
                state = init;
            }
            break;



        case PINA7_press:
            if(button == 0x80)
            {
                state = PINA7_press;
            }else
            {
                state = init;
            }

        default:
            break; 


    } 


    switch(state){
        case Unlock:
            PORTB = 0x01;
            state = init; 
            break;
        case init:
            //PORTB = 0x00;
            break;
        case PINA7_press:
            PORTB = 0x00;
            break;
        case Locking:
            PORTB= 0x00;
            state = init;
            break;
        
        default:
            break;
    }


}

int main(void) {
    	//Set the proper inputs and outputs
    DDRA = 0x00; PORTA = 0xFF; //Configure port A's pins as inputs
    DDRB = 0xFF; PORTB = 0x00; //Configure port A's pins as inputs
    //DDRC = 0xFF; PORTC = 0x00; //Configure port C's pins as outputs
    //DDRD = 0xFF; PORTD = 0x00; //Configure port A's pins as outputs 
    
    //Initialize the starting point
    state = init;

    /* Insert your solution below */
    while (1) {
        tick();
        

    }
}