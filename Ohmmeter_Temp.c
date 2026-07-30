
/*==================[inclusions]=============================================*/

#include "inc/Ohmmeter_Temp.h"
#include "inc/adc.h"
#include <stdio.h>
#include <string.h>

/*==================[internal data]=========================================*/

static uint16_t adcVal1 = 0;
static uint16_t adcVal2 = 0;
static float    resistance = 0.0f;
static char     formattedVal[8] = "0.00";
static uint8_t  state = 0;

/*==================[external functions]====================================*/

void Ohmmeter_Temp_init(void)
{
    // Configure switching pins
    HAL_GPIO_PinCfg(IN1, GPIO_OUTPUT);
    HAL_GPIO_PinCfg(Res1, GPIO_OUTPUT);

    // Initial state: IN high, RES low
    HAL_GPIO_PinSet(IN1, GPIO_HIGH);
    HAL_GPIO_PinSet(Res1, GPIO_LOW);

    // Configure ADC pin
    HAL_SetAnalog_ADC1();

    state = 0;
    resistance = 0.0f;
}

void Ohmmeter_Temp_poll(void)
{
    float vout1, vout2;
    float rx1, rx2;

    switch (state)
    {
        case 0:
            // Read ADC with IN=HIGH, RES=LOW
            HAL_GPIO_PinSet(IN1, GPIO_HIGH);
            HAL_GPIO_PinSet(Res1, GPIO_LOW);
            adcVal1 = ADC_value_ADC1;
            state = 1;
            break;

        case 1:
            // Read ADC with IN=LOW, RES=HIGH
            HAL_GPIO_PinSet(IN1, GPIO_LOW);
            HAL_GPIO_PinSet(Res1, GPIO_HIGH);
            adcVal2 = ADC_value_ADC1;

            // Calculate resistance from two readings
            vout1 = ((float)adcVal1 * OHM_Temp_VIN / OHM_Temp_ADC_RES) + OHM_Temp_ADJ;
            vout2 = ((float)adcVal2 * OHM_Temp_VIN / OHM_Temp_ADC_RES) + OHM_Temp_ADJ;

            float vTotal = vout1 + vout2;
            if (vout1 > 0.001f && vout2 > 0.001f)
            {
                rx1 = ((OHM_Temp_R1 * vTotal) / vout1) - OHM_Temp_R1;
                rx2 = OHM_Temp_R1 / ((vTotal / vout2) - 1.0f);
                resistance = (rx1 + rx2) / 2.0f;
            }

            // Format as string
            int intPart = (int)resistance;
            int decPart = (int)((resistance - intPart) * 100);
            if (decPart < 0) decPart = -decPart;
            sprintf(formattedVal, "%d.%02d", intPart, decPart);

            state = 0;
            break;
    }
}

float Ohmmeter_Temp_getResistance(void)
{
    return resistance;
}

void Ohmmeter_Temp_getFormattedValue(char* buffer)
{
    strcpy(buffer, formattedVal);
}

