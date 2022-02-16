/* 
 * File:   newdmain.c
 * Author: francis and Linda assisted by gerry
 *
 * Created on december 3, 2021, 1:09 PM
 */

// PIC32MM0064GPL028 Configuration Bit Settings

// 'C' source line config statements

// FDEVOPT
//#define SYSTEM_FREQUENCY  72000000L
#pragma config SOSCHP = OFF             // Secondary Oscillator High Power Enable bit (SOSC oprerates in normal power mode.)
#pragma config USERID = 0xFFFF          // User ID bits (Enter Hexadecimal value)

// FICD
#pragma config JTAGEN = ON              // JTAG Enable bit (JTAG is enabled)
#pragma config ICS = PGx1               // ICE/ICD Communication Channel Selection bits (Communicate on PGEC1/PGED1)

// FPOR
#pragma config BOREN = BOR3             // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware; SBOREN bit disabled)
#pragma config RETVR = OFF              // Retention Voltage Regulator Enable bit (Retention regulator is disabled)
#pragma config LPBOREN = ON             // Low Power Brown-out Enable bit (Low power BOR is enabled, when main BOR is disabled)

// FWDT
#pragma config SWDTPS = PS1048576       // Sleep Mode Watchdog Timer Postscale Selection bits (1:1048576)
#pragma config FWDTWINSZ = PS25_0       // Watchdog Timer Window Size bits (Watchdog timer window size is 25%)
#pragma config WINDIS = OFF             // Windowed Watchdog Timer Disable bit (Watchdog timer is in non-window mode)
#pragma config RWDTPS = PS1048576       // Run Mode Watchdog Timer Postscale Selection bits (1:1048576)
#pragma config RCLKSEL = LPRC           // Run Mode Watchdog Timer Clock Source Selection bits (Clock source is LPRC (same as for sleep mode))
#pragma config FWDTEN = OFF              // Watchdog Timer Enable bit (WDT is enabled)

// FOSCSEL
#pragma config FNOSC = LPRC             // Oscillator Selection bits (Low power RC oscillator (LPRC))
#pragma config PLLSRC = FRC             // System PLL Input Clock Selection bit (FRC oscillator is selected as PLL reference input on device reset)
#pragma config SOSCEN = ON              // Secondary Oscillator Enable bit (Secondary oscillator is enabled)
#pragma config IESO = ON                // Two Speed Startup Enable bit (Two speed startup is enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Selection bit (Primary oscillator is disabled)
#pragma config OSCIOFNC = OFF           // System Clock on CLKO Pin Enable bit (OSCO pin operates as a normal I/O)
#pragma config SOSCSEL = OFF            // Secondary Oscillator External Clock Enable bit (SOSC pins configured for Crystal mode)
#pragma config FCKSM = CSECME           // Clock Switching and Fail-Safe Clock Monitor Enable bits (Clock switching is enabled; Fail-safe clock monitor is enabled)

// FSEC
#pragma config CP = OFF                 // Code Protection Enable bit (Code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <p32xxxx.h>

/*
 * 
 */

void right_feed_valve_off() {
    LATBbits.LATB3 = 0;
}

void right_feed_valve_on() {
    LATBbits.LATB3 = 1;
}

void right_waste_valve_off() {
    LATBbits.LATB2 = 0;
}

void right_waste_valve_on() {
    LATBbits.LATB2 = 1;
}

void equalizer_valve_off() {
    LATBbits.LATB13 = 0;
}

void equalizer_valve_on() {
    LATBbits.LATB13 = 1;
}

void left_feed_valve_off() {
    LATBbits.LATB14 = 0;
}

void left_feed_valve_on() {
    LATBbits.LATB14 = 1;
}

void left_waste_valve_off() {
    LATBbits.LATB15 = 0;
}

void left_waste_valve_on() {
    LATBbits.LATB15 = 1;
}

void set_output_pins(){
    ANSELBbits.ANSB3 = 0;// RB2 is digital
    TRISBbits.TRISB3 = 0;// RB2 is output 
    ANSELBbits.ANSB2 = 0;// RB3 is digital
    TRISBbits.TRISB2 = 0;// RB3 is output 
    ANSELBbits.ANSB15 = 0;// RB15 is digital
    TRISBbits.TRISB15 = 0;// RB15 is output 
    ANSELBbits.ANSB13 = 0;// RB13 is digital
    TRISBbits.TRISB13 = 0;// RB13 is output
    ANSELBbits.ANSB14 = 0;// RB14 is digital
    TRISBbits.TRISB14 = 0;// RB14 is output 
}

void initializing_state(){
    equalizer_valve_off();
    left_feed_valve_on();
    left_waste_valve_on();
    right_feed_valve_on();
    right_waste_valve_on();
    delay(4000);
    
}

void running_state(){
        //Case One
        equalizer_valve_off();
        left_feed_valve_on();
        left_waste_valve_off();
        right_feed_valve_off();
        right_waste_valve_on();
        delay(6000);
        
        //Case Two
        equalizer_valve_on();
        left_feed_valve_on();
        left_waste_valve_off();
        right_feed_valve_off();
        right_waste_valve_off();
        delay(1400);
        
        //Case Three
        equalizer_valve_on();
        left_feed_valve_off();
        left_waste_valve_off();
        right_feed_valve_on();
        right_waste_valve_off();
        delay(1400);
        
        //Case Four
        equalizer_valve_off();
        left_feed_valve_off();
        left_waste_valve_on();
        right_feed_valve_on();
        right_waste_valve_off();
        delay(6000);
        
        //Case Five
        equalizer_valve_on();
        left_feed_valve_off();
        left_waste_valve_off();
        right_feed_valve_on();
        right_waste_valve_off();
        delay(1400);
        
        //Case Six
        equalizer_valve_on();
        left_feed_valve_on();
        left_waste_valve_off();
        right_feed_valve_off();
        right_waste_valve_off();
        delay(1400);
}

void delay(long ms_Delay) {
    long i , j, k;
    for (j = 0; j < ms_Delay; j++)
        for (i = 0; i < 1; i++);
            for (k = 0; k < 2000; k++);
}

/*
#define USHORT unsigned short  
  
void delay (USHORT milisec) {  
    USHORT newtime;
    newtime = milisec *2;
    T1CON = 0x8010;  
    TMR1 = 0x00;  
    USHORT i = 0;  
    PR1 = 0x40;  
    while(i != newtime) {  
        while(TMR1) {  
        }  
        i++;  
        TMR1 = 0x00;  
    }  
    T1CON = 0x00;  
    return;  
}*/


int main() {
    
    set_output_pins();
       
    int run_once = 0;
    if (run_once == 0 );{
        initializing_state();
        } 
    run_once = 1;
    
    while (1) {
        running_state();
    }
    
    return 0;
}