/**
 * main.c
 *
 *  Created on: 21 de out de 2022
 *      Author: William
 */

#include "Peripheral_Setup.h"

uint32_t count = 0;

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

    EINT;                                               // Enable Global interrupt INTM
    ERTM;                                               // Enable Global real time interrupt DBGM

    // Configuring LEDs
    GpioDataRegs.GPASET.bit.GPIO0 = 1;
    GpioDataRegs.GPASET.bit.GPIO1 = 1;
    GpioDataRegs.GPASET.bit.GPIO2 = 1;
    GpioDataRegs.GPASET.bit.GPIO3 = 1;

    while (1)
    {
        for (count = 0; count < 0x0007FFFF; count++)
        {
        }

        GpioDataRegs.GPATOGGLE.bit.GPIO3 = 1;
    }

    return 0;
}

__interrupt void isr_cpu_timer0(void)
{
    GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
