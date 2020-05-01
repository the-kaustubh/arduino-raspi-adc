#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "adc.h"

#define F_CPU (16000000UL)
#define BAUD_RATE (9600)
#define UBRR (103)
#define DELAY_MS (1000)

void send_int(int val);
int rev_int(int val);

void main() {
  char c[50];
  c[49] = 0;
  int val = 0;

  uart_init(BAUD(BAUD_RATE, F_CPU));
  DDRB |= (1 << 5);
  PORTB &= (1 << 5);

  // ADC init
  adc_init();

  while(1) {
    val = adc_start(0);
    send_int(val);
    PORTB |= (1 << 5);
    _delay_ms(DELAY_MS);
    PORTB &= ~(1 << 5);
    _delay_ms(DELAY_MS);
    val = 0;
  }
}

void send_int(int val) {
  val = rev_int(val); //3201
  while(val) {
    uart_send_byte((val % 10) + '0');
    val /= 10;
  }
  uart_send_byte('\n');
  uart_send_byte('\r');
}

int rev_int(int val) {
  int rval = 0;
  while(val) {
    rval *= 10;
    rval += val%10;
    val  /= 10;
  }
  return rval;
}
