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
int main(void) {
	//Set the proper inputs and outputs
    DDRA = 0x00; PORTA = 0xFF; //Configure port A's pins as inputs
    //DDRB = 0x00; PORTB = 0xFF; //Configure port A's pins as inputs
    DDRC = 0xFF; PORTC = 0x00; //Configure port A's pins as inputs
    //DDRD = 0xFF; PORTD = 0x00; //Configure port A's pins as outputs 


    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    unsigned char tempC = 0x00;
    unsigned char fuel_LED = 0x00;





    while(1) {
        tempA= PINA & 0x0F;
        tempB= PINA & 0x30;
        tempC= PINA & 0x70;

        fuel_LED = 0;

        if(tempB == 0x30 && tempC != 0x70){ //This means that the seat belt is not fassend
            if(tempA == 0x00){
                fuel_LED = 0xC0;
            }
            else if(tempA <=0x02 ){//Check if fuel below or equal to 2
                fuel_LED = 0xE0; //1 10 0000
            }
            else if(tempA <=4){//Check if fuel below or equal to 4
                fuel_LED = 0xF0;//1 11 0000
            }
            else if(tempA <=6){//Check if fuel below or equal to 6
                fuel_LED = 0xB8;//0 11 1000
            }
            else if(tempA <=9){//Check if fuel below or equal to 9
                fuel_LED = 0xBC;//0 11 1100
            }
            else if(tempA <=12){//Check if fuel below or equal to 12
                fuel_LED = 0xBE;//0 11 1110
            }
            else if(tempA <=15){//else full tank
                fuel_LED = 0xBF; //0 11 1111
            }
        }else{ //This means that the seat belt is on
            if(tempA == 0x00){
                fuel_LED = 0x40;
            }
            else if(tempA <=0x02 ){//Check if fuel below or equal to 2
                fuel_LED = 0x60; //1 10 0000
            }
            else if(tempA <=4){//Check if fuel below or equal to 4
                fuel_LED = 0x70;//1 11 0000
            }
            else if(tempA <=6){//Check if fuel below or equal to 6
                fuel_LED = 0x38;//0 11 1000
            }
            else if(tempA <=9){//Check if fuel below or equal to 9
                fuel_LED = 0x3C;//0 11 1100
            }
            else if(tempA <=12){//Check if fuel below or equal to 12
                fuel_LED = 0x3E;//0 11 1110
            }
            else if(tempA <=15){//else full tank
                fuel_LED = 0x3F; //0 11 1111
            }
        }

        PORTC = fuel_LED;
    } 

    
	return 0;
}

