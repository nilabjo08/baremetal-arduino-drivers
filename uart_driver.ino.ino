#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)

void UART_init(void)
{
    UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
    UBRR0L = (unsigned char)UBRR_VALUE;

    UCSR0B = (1 << TXEN0);              // Enable transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void UART_sendChar(char c)
{
    while (!(UCSR0A & (1 << UDRE0)));   // Wait until buffer empty
    UDR0 = c;
}

void UART_sendString(const char *str)
{
    while (*str)
    {
        UART_sendChar(*str);
        str++;
    }
}

void setup()
{
    UART_init();
}

void loop()
{
    UART_sendString("Hello from UART\r\n");
    _delay_ms(1000);
}

