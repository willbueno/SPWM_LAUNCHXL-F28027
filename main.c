/**
 * main.c
 *
 *  Created on: 21 de out de 2022
 *      Author: William
 */

#include "Peripheral_Setup.h"

uint32_t index = 0;
uint16_t sine_table[125] = { 300, 315, 330, 345, 360, 375, 389, 403, 417, 431,
                             445, 458, 470, 482, 494, 505, 516, 526, 536, 545,
                             553, 561, 568, 575, 580, 585, 590, 593, 596, 598,
                             599, 600, 600, 599, 597, 595, 591, 588, 583, 578,
                             571, 565, 557, 549, 540, 531, 521, 511, 500, 488,
                             476, 464, 451, 438, 424, 410, 396, 382, 367, 353,
                             338, 323, 308, 292, 277, 262, 247, 233, 218, 204,
                             190, 176, 162, 149, 136, 124, 112, 100, 89, 79, 69,
                             60, 51, 43, 35, 29, 22, 17, 12, 9, 5, 3, 1, 0, 0,
                             1, 2, 4, 7, 10, 15, 20, 25, 32, 39, 47, 55, 64, 74,
                             84, 95, 106, 118, 130, 142, 155, 169, 183, 197,
                             211, 225, 240, 255, 270, 285 };

uint16_t pwm[100];
int g = 0;

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
    ConfigCpuTimer(&CpuTimer0, 60, 160);                // Frequency clock: 60 MHz, 160 us interruption
    StartCpuTimer0();                                   // Enable Timer 0 interruption

    // No memory for float compute
    /*
    for (index = 0; index < 125; index++)
    {
        sine_table[index] = (uint16_t) (1500.0 * (1.0 + sin(6.28318531 / 125.0 * ((float) index))));
    }
     */
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

    index = (index == 124) ? 0 : (index + 1);

    EPwm3Regs.CMPA.half.CMPA = sine_table[index];
    EPwm4Regs.CMPA.half.CMPA = sine_table[index];

    pwm[g] = sine_table[index];
    if (++g == 100)
    {
        g = 0;
    }

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
