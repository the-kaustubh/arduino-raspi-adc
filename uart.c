#include "uart.h"

void uart_init(int ubrr)  {
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)(ubrr >> 0);
  UCSR0B = (1 << RXEN0) | (1 << TXEN0); // enable pins
  UCSR0C = (3 << UCSZ00);  // 8 data bit, 0 parity bit. 1 stop bit
}

void uart_send_byte(char bite) {
  while(!(UCSR0A & (1 << UDRE0)));
  UDR0 = bite;
}

void uart_send_str(char * str) {
  int i = 0;
  while(str[i] != 0) uart_send_byte(str[i++]);
}

unsigned char uart_recieve_byte(void) {
    while(!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void uart_recieve_str(char * str, int len) {
  char i=0;
  char c;

  do
  {
      c = uart_recieve_byte();
      str[i++] = c;
  }  while((i < len) && (c != '\r'));
  str[i++] = '\n';
  str[i] = 0;
}
