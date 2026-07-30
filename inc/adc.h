#ifndef __ADC_H__
#define __ADC_H__

#include <xc.h>

extern uint16_t Buffer_entradas[16];
extern uint8_t canales[16];
extern uint8_t entrada;

void adc_init(void);                    //Inicializa el ADC.
void adc_addAnalogChannel(uint8_t);     //Agrega un nuevo canal a la lista de canales activos.
void poll_adc(void);

#endif //__ADC_H__
