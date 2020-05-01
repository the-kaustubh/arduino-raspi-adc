#include "adc.h"

void adc_init() {
  ADMUX = 0;
  ADMUX |= (1 << REFS0) ;
  ADCSRA |= (1 << ADEN);
  ADCSRA |= ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
  DIDR0 = 0x3F;
}

int adc_start(int adchannel) {
  ADMUX |= (adchannel & 0xf);
  ADCSRA |= (1 << ADSC);
  while(ADCSRA & (1 << ADSC));
  return ADC;
}
