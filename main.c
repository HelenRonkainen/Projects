/******************************************************************************************

	WinAVR project example by Atomia Ltd (c)
	You may use this as a project template.
	Visit http://www.atomia.net/ for tools, help files and code snippets.

******************************************************************************************/

#include <avr/io.h> //Declare this for register definitions of the MCU
#include <avr/interrupt.h> //Declare this for sei()-function and other interrupt related stuff
#include "module.h" //Declare this in order to access functions from module.c-file

//Global variables
unsigned char temp;

/******************************************
	MasterInit: Initializes the system
******************************************/
void MasterInit(void)
{
DDRA=0xFF; //PortA to output
DDRB=0x00; //PortB to input
DDRC=0x00; //PortC to input
DDRD=0x00; //PortD to input
temp=0; //Initialize the variable
ModuleInit(); //Call function from module1.c file
sei(); //Enable interrupts
}

/******************************************
	main: the start point of the program
******************************************/
int main(void)
{

    /* Call MasterInit to initialise the system */
	MasterInit();
	
	/* Start example module */
	ModuleStart();
	
	/* Go to eternal loop (MCU code usually should not go to end) */
	while(1)
	{
		temp++;
		if(temp==255) 
			PORTA=~PINA; //toggle port output value
	}
   
return 0;
}
