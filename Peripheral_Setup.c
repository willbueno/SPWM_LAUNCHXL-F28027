/*
 * Peripheral_Setup.c
 *
 *  Created on: 22 de out de 2022
 *      Author: William
 */

#include "Peripheral_Setup.h"

void Setup_GPIO(void)
{
    EALLOW;

    // LED 1
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;                 // GPIO2 - LED 1
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;                  // I/O DIR - Output = 1

    // LED 2
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;                 // GPIO2 - LED 2
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;                  // I/O DIR - Output = 1

    // LED 3
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;                 // GPIO2 - LED 3
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;                  // I/O DIR - Output = 1

    // LED 4
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;                 // GPIO2 - LED 4
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;                  // I/O DIR - Output = 1

    // PWM 6
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;                 // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;                  // Disable pull-up on GPIO6

    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;                 // Configure GPIO6 as EPWM4B
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;                  // Disable pull-up on GPIO6

    EDIS;
}

void Setup_ePWM(void)
{
    EALLOW;

    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;

    EPwm1Regs.TBPRD = 600;                              // Set period 25 kHz - uC_clock / (2*2*fs) for UP-DOWN
    EPwm1Regs.TBPHS.half.TBPHS = 0;                     // Phase is 0
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;
    EPwm1Regs.TBCTR = 0;                                // Clear counter
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;      // Count UP-DOWN
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;             // Disable phase loading
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;            // Clock ratio to SYSCLKOUT
    EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;         // Load register every ZERO and PRD
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD;
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD;   // Load register every ZERO and PRD

    EPwm1Regs.AQCTLA.bit.PRD = AQ_NO_ACTION;
    EPwm1Regs.AQCTLA.bit.ZRO = AQ_NO_ACTION;
    EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;                // Set actions for EPWM1A
    EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;

    EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;           // Active Hi complementary
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;      // Enable Dead-band module
    EPwm1Regs.DBFED = 80;                               // Dead-Band Generator Falling Edge Delay (FED) = 20 TBCLKs
    EPwm1Regs.DBRED = 80;                               // Dead-Band Generator Rising Edge Delay (RED) = 20 TBCLKs

    EPwm1Regs.CMPA.half.CMPA = 300;                     // Duty Cicle in 50% of PRD

    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;              // Enable TBCLK within the EPWM

    EDIS;
}



