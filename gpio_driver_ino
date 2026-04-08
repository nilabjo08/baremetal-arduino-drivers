#include <avr/io.h>
#include <util/delay.h>

void setup()
{
    // Set PB5 (Arduino pin 13) as output
    DDRB |= (1 << DDB5);
}

void loop()
{
    // Toggle PB5
    PORTB ^= (1 << PORTB5);

    // 500 ms delay
    _delay_ms(500);
}
