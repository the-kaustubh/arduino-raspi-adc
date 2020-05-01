#ifndef UART_H
#define UART_H

#include <avr/io.h>

#define BAUD(x, fosc) (((fosc) / (16UL * x)) - 1)

void uart_init(int);
void uart_send_byte(char);
void uart_send_str(char *);
unsigned char uart_recieve_byte(void);
void uart_recieve_str(char *, int);

#endif
