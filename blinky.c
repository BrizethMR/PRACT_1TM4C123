#include <stdint.h>
#include "inc/tm4c123gh6pm.h" // ../../../inc/tm4c123gh6pm.h

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
volatile int32_t a;
int
main(void)
{
    volatile uint32_t ui32Loop;
    a = 32000;

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGC2_R;

    //
    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R = 0x08;
    GPIO_PORTF_DEN_R = 0x08;

    //
    // Loop forever.
    //
    while(1)
    {
        //
        // Turn on the LED.
        //
        GPIO_PORTF_DATA_R |= 0x08;

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < a; ui32Loop++) //evalua esas operaciones
        {
        }

        //
        // Turn off the LED.
        //
        GPIO_PORTF_DATA_R &= ~(0x08);

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < a; ui32Loop++)
        {
        }
    }
}
