
#ifndef OHMMETER_Temp_H_
#define OHMMETER_Temp_H_

/*==================[inclusions]=============================================*/

#include <stdint.h>
#include "gpio.h"

/*==================[macros]=================================================*/

// Calibration constants (injected from module)
#define OHM_Temp_VIN    ((float)3.03248)
#define OHM_Temp_R1     ((float)559.2)
#define OHM_Temp_ADJ    ((float)0.02)
#define OHM_Temp_ADC_RES  ((float)1023.0)

/*==================[init/poll]==============================================*/

void Ohmmeter_Temp_init(void);

void Ohmmeter_Temp_poll(void);

/*==================[functions]=============================================*/

float Ohmmeter_Temp_getResistance(void);


/*==================[end of file]============================================*/
#endif

