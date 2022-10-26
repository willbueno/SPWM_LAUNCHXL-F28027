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

    // PWM 3
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;                 // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;                  // Disable pull-up on GPIO4

    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;                 // Configure GPIO5 as EPWM3B
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;                  // Disable pull-up on GPIO5

    // PWM 4
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;                 // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;                  // Disable pull-up on GPIO6

    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;                 // Configure GPIO7 as EPWM4B
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;                  // Disable pull-up on GPIO7

    EDIS;
}

void Setup_ePWM(void)
{
    EALLOW;

    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;

    // PWM 3A
    EPwm3Regs.TBPRD = 1500;                             // Set period 20 kHz - uC_clock / (2*fs) for UP/DOWN

    EPwm3Regs.CMPA.half.CMPA = 750;                     // Duty Cicle in 50% of PRD

    EPwm3Regs.TBPHS.half.TBPHS = 0;                     // Phase is 0
    EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
    EPwm3Regs.TBCTR = 0x0000;                           // Clear counter
    EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;      // Count UP/DOWN
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;             // Disable phase loading
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;            // Clock ratio to SYSCLKOUT
    EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;         // Load register every ZERO and PRD
    EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD;
    EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD;   // Load register every ZERO and PRD

    EPwm3Regs.AQCTLA.bit.PRD = AQ_NO_ACTION;
    EPwm3Regs.AQCTLA.bit.ZRO = AQ_NO_ACTION;
    EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;                // Set actions for EPWM3A
    EPwm3Regs.AQCTLA.bit.CAD = AQ_SET;                  // Set actions for EPWM3A

    EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;           // Active Hi complementary
    EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;      // Enable Dead-band module
    EPwm3Regs.DBFED = 80;                               // Dead-Band Generator Falling Edge Delay (FED)
    EPwm3Regs.DBRED = 80;                               // Dead-Band Generator Rising Edge Delay (RED)

    // PWM 4A
    EPwm4Regs.TBPRD = 1500;                             // Set period 20 kHz - uC_clock / (2*fs) for UP-DOWN

    EPwm4Regs.CMPA.half.CMPA = 750;

    EPwm4Regs.TBPHS.half.TBPHS = 600;                   // Phase is 180 degree
    EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
    EPwm4Regs.TBCTR = 0x0000;                           // Clear counter
    EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;      // Count UP-DOWN
    EPwm4Regs.TBCTL.bit.PHSEN = TB_ENABLE;              // Enable phase loading
    EPwm4Regs.TBCTL.bit.PHSDIR = TB_DOWN;               // Phase Up/Down
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;            // Clock ratio to SYSCLKOUT
    EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;

    EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;         // Load register every ZERO and PRD
    EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO_PRD;
    EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO_PRD;   // Load register every ZERO and PRD

    EPwm4Regs.AQCTLA.bit.PRD = AQ_NO_ACTION;
    EPwm4Regs.AQCTLA.bit.ZRO = AQ_NO_ACTION;
    EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;                // Set actions for EPWM4A
    EPwm4Regs.AQCTLA.bit.CAD = AQ_SET;                  // Set actions for EPWM4A

    EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;           // Active Hi complementary
    EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;      // Enable Dead-band module
    EPwm4Regs.DBFED = 80;                               // Dead-Band Generator Falling Edge Delay (FED)
    EPwm4Regs.DBRED = 80;                               // Dead-Band Generator Rising Edge Delay (RED)

    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;              // Enable TBCLK within the EPWM

    EDIS;
}
