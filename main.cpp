/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"

#define WAIT_TIME_MS 1000 
DigitalOut led1(LED1);
AnalogIn Vout(A0);
Grove_LCD_RGB_Backlight rgbLCD(PB_9,PB_8);
float Rntc ;
float T;
char mensaje[16];


int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    while (true)
    {

        Rntc=((5.0*100.0)/(3.3*Vout))-100.0; // sacamos la resitencia de temperatura
        T = (4250.0/(log(100.0/Rntc)+(4250.0/298.0)))-273; // sacamos la temprestura


        rgbLCD.setRGB(0xff, 0xff, 0xff);                 //set the color azul
        rgbLCD.locate(0,0);
        rgbLCD.print("Temperatura");
        rgbLCD.locate(0,1);
        sprintf(mensaje,"%f",T);
        rgbLCD.print(mensaje);
        thread_sleep_for(WAIT_TIME_MS);
    }
}
