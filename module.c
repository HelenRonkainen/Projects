/******************************************************************************************

	WinAVR module example by Atomia Ltd (c)
	You may use this as a project template.
	Visit http://www.atomia.net/ for tools, help files and code snippets.

******************************************************************************************/

#include <avr/io.h> //Declare this for register definitions of the MCU
#include <avr/signal.h> //Declare to support SIGNAL-keyword
#include <avr/interrupt.h> //Declare this for sei()-function and other interrupt related stuff
#include "module.h"

/* Example initialization function */
void ModuleInit(void) 
{
   
}

/* Example start function */
void ModuleStart(void)
{
	
}


/* Example interrupt ************************************************
Signal handler for Timer 0 over flow. For other signal definitions 
see c:\winavr2005\avr\include\avr\ioXXX.h , where XXX is your MCU
(for example iom32.h)
*********************************************************************/
SIGNAL(SIG_INPUT_CAPTURE1 )  
{

/* Code... */

}

