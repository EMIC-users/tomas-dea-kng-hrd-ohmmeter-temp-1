#include "inc/adc.h"

uint16_t Buffer_entradas[16];
uint8_t canales[16] = {0};
uint8_t numCanales = 0;
uint8_t indices[16];  // Para saber el orden en que escaneamos
uint8_t entrada = 0;

void adc_init(void)
{
    if (AD1CON1bits.ADON == 0)
    {
        AD1CHS = 9;  // Selecciona AN0 como canal inicial (aunque no se use)

        AD1CON1bits.ASAM = 1;       // Auto-sample
        AD1CON1bits.SSRC = 7;       // Auto-convert
        AD1CON2bits.CSCNA = 1;      // Escaneo automático
        AD1CON2bits.BUFM = 0;       // Buffer único
        AD1CON2bits.SMPI = numCanales - 1;  // # de conversiones por interrupción - 1
        AD1CON3bits.SAMC = 10;       // Tiempo de muestreo
        AD1CON3bits.ADCS = 20;    // Divisor de reloj
        AD1CON1bits.ADON = 1;       // Encender ADC
    }
    AD1CON1bits.SAMP = 1;           // Iniciar muestreo
}

void adc_addAnalogChannel(uint8_t channel)
{
    if (channel >= 16) return;

    canales[channel] = 1;
    indices[numCanales++] = channel;
    int j = 0;
    for (int i = 0; i < 16 ; i++)
    {
        if (canales[i] == 1)
        {
            indices[j++] = i; 
        }
    }

    AD1PCFG &= ~(1 << channel);     // Habilitar modo analÃ³gico
    AD1CSSL |= 1 << channel;        // AÃ±adir a lista de escaneo

    if (AD1CON1bits.ADON)
        AD1CON1bits.ADON = 0;

    adc_init();
}


void poll_adc(void)
{
        if(IFS0bits.AD1IF)
    {
        IFS0bits.AD1IF = 0;  // Limpiar flag

        for (uint8_t i = 0; i < numCanales; i++)
        {
            uint8_t canal = indices[i];
            Buffer_entradas[canal] = *(&ADC1BUF0 + i) & 0x03FF;  // Lee BUF0, BUF1, BUF2...
        }
    }
}

