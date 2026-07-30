

// ADC input
#define TRIS_ADC1	                _TRISB15
#define PORT_ADC1 	                _RB15
#define LAT_ADC1 	                _LATB15
#define ODC_ADC1	                _ODB15
#define PIN_ADC1 	                _RB15
#define RPOUT_ADC1	                RPOR7bits.RP15R
#define RPIN_ADC1	                15
#define CN_ADC1		                11
#define ADC_value_ADC1              Buffer_entradas[9] 
#define HAL_SetAnalog_ADC1()        {_PCFG9=0;\
                                        adc_addAnalogChannel(9);}

// Switching pins for two-point measurement
#define TRIS_IN1	                _TRISB5
#define PIN_IN1 	                _RB5
#define LAT_IN1 	                _LATB5
#define ODC_IN1	                _ODB5
#define RPOUT_IN1		            RPOR2bits.RP5R
#define RPIN_IN1		            5
#define CN_IN1		                27
#define TRIS_Res1	                _TRISB6
#define PIN_Res1 	                _RB6
#define LAT_Res1 	                _LATB6
#define ODC_Res1	                _ODB6
#define RPOUT_Res1		            RPOR3bits.RP6R
#define RPIN_Res1		            6
#define CN_Res1		                24

// LEDs
#define TRIS_Led1	_TRISA2
#define LAT_Led1 	_LATA2
#define ODC_Led1	_ODA2
#define PIN_Led1 	_RA2
#define CN_Led1		30
#define TRIS_Led2	_TRISA3
#define LAT_Led2 	_LATA3
#define ODC_Led2	_ODA3
#define PIN_Led2 	_RA3
#define CN_Led2		29

// Board name

