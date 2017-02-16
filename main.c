#include <msp430.h>
#include "LED.h"

// Function prototypes
void ConfigureClockModule(void);

void main(void)
{
	// Stop the watchdog timer, and configure the clock module.
	WDTCTL = WDTPW + WDTHOLD;
	ConfigureClockModule();
	    
    InitializeLEDPortPins();

	// Infinite loop
  	while (1)
  	{
  		TURN_ON_LED1;
  		TURN_ON_LED2;
  		
  		// Wait for approximately 1/4 second
  		_delay_cycles(250000);
  		
  		TURN_OFF_LED1;
  		TURN_OFF_LED2;
  		
  		// Wait for approximately 1/4 second
  		_delay_cycles(250000);
  	}
}
void ConfigureClockModule(void)
{
    // Configure Digitally Controlled Oscillator (DCO) for 16 MHz using factory
    // calibrations.
	DCOCTL  = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;
}
