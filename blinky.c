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

// ******** PARA ESTE EXPERIMENTO LA SALIDA ES EN PF3

volatile int32_t a; // ***** SE PUEDE CAMBIAR EL VALOR DE ESTA VARIABLE 
int
main(void)
{
    volatile uint32_t ui32Loop;
    // LA VARIABLE a CMABIA LA VELOCIDAD DEL PARPADEO
    // PARA EL TIEMPO DE UNA SOLA CUENTA SE PONE a = 1, SE VE LA SALIDA EN EL OSCILOSCOPIO 
    // EN EL OSCILOSCOPIO CON LOS CURSORES SE VE QUE EL TIEMPO ES DE 1.50 us
    a = 66667; 

    // PARA LOS 100 ms, USANDO UNA REGLA DE 3 -> a = 66667
    // LOS 100 ms SON PARA TODO EL CICLO 


    // PARA HABILITAR EL PUERTO DE GPIO, EN ESTE CASO PUERTO F
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    ui32Loop = SYSCTL_RCGC2_R;

    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //GPIO_PORTF_DIR_R = 0x08;
    //GPIO_PORTF_DEN_R = 0x08;
    // PARA EL CAMBIO DE LED 
    GPIO_PORTF_DIR_R = 0x02;
    GPIO_PORTF_DEN_R = 0x02;
    /* AZUL -> PF2 -> (0x04)
       ROJO -> PF1 -> (0x02)
       VERDE -> PF3 -> (0x08)
    */

    //
    // Loop forever.
    //
    while(1)
    {
        // ENCENDER EL LED .
        GPIO_PORTF_DATA_R |= 0x02;

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < a; ui32Loop++) //evalua esas operaciones
        {
        }

        // APAGA EL LED
        GPIO_PORTF_DATA_R &= ~(0x02);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < a; ui32Loop++)
        {
        }
    }
}
