/**
 * main.c
 *
 *  Created on: 21 de out de 2022
 *      Author: William
 */

#include "Peripheral_Setup.h"

uint32_t index = 0;
uint16_t sine_table[125];

__interrupt void isr_cpu_timer0(void);

int main(void)
{
    InitSysCtrl();                                      // Initialize System Control
    DINT;                                               // Disable CPU interrupts
    InitPieCtrl();                                      // Initialize the PIE control registers to their default state

    IER = 0x0000;                                       // Disable CPU interrupts
    IFR = 0x0000;                                       // Clear all CPU interrupt flags

    InitPieVectTable();                                 // Initialize the PIE vector table

    Setup_GPIO();
    Setup_ePWM();

    EALLOW;
    PieVectTable.TINT0 = &isr_cpu_timer0;               // Pointer to interruption function
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;                  // Enable Timer 0 - Line 1 - Column 7
    IER |= M_INT1;                                      // Enable interruption line 1
    EDIS;

    InitCpuTimers();
    ConfigCpuTimer(&CpuTimer0, 60, 50000);              // Frequency clock: 60 MHz
    StartCpuTimer0();                                   // Enable Timer 0 interruption

    for (index = 0; index < 125; index++)
    {
//        sine_table[index] = (uint16_t) (1000.0 * (1.0 + sin(6.28318531 / 125.0 * ((float) index))));
        sine_table[index] = 0;
    }
    index = 0;

    EINT;                                               // Enable Global interrupt INTM
    ERTM;                                               // Enable Global real time interrupt DBGM

    // Configuring LEDs
    GpioDataRegs.GPASET.bit.GPIO0 = 1;
    GpioDataRegs.GPASET.bit.GPIO1 = 1;
    GpioDataRegs.GPASET.bit.GPIO2 = 1;
    GpioDataRegs.GPASET.bit.GPIO3 = 1;

    while (1)
    {
        DELAY_US(100000);
        GpioDataRegs.GPATOGGLE.bit.GPIO3 = 1;
    }

    return 0;
}

__interrupt void isr_cpu_timer0(void)
{
    GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
