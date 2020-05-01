#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void adc_init();
int adc_start(int adchannel);


#endif
