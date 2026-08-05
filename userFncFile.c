#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_Led1.h"
#include "inc/led_Led2.h"
#include "inc/timer_api1.h"
#include "inc/Ohmmeter_Temp.h"
#include "inc/conversionFunctions.h"
#include "inc/EMICBus.h"

void onReset()
{
    LEDs_Led1_blink(100, 400, 6);
    setTime1(2000, 'A');
}


void etOut1()
{
    LEDs_Led2_blink(60, 240, 1);
    pI2C("TEMP\t%.2f", Ohmmeter_Temp_getResistance());
}



