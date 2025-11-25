#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

ISR(TIMER0_COMPA_vect){
  PORTD ^= (1<<PORTD6);
}

int main()
{
  TCCR0A |= (1<<WGM01); //clear timer on compare
  TCCR0B |= (1<<CS01);  //prescaler 8
  OCR0A = 55;
  TCNT0 = 0;
  TIMSK0 |= (1<<OCIE0A);
  sei();
  DDRD |= (1<<DDD6);
  DDRB |= (1<<DDB3) | (1<<DDB4);

  while(1)
  {
    if (~(PINB | ~(1<<PINB3)))
    {
      DDRD |= (1<<DDD6);
    }
    else
    {
      DDRD &= ~(1<<DDD6);
    }

    if (~(PIND | ~(1<<PIND2)))
    {
      PORTB &= ~(1<<PORTB4);
    }
    else
    {
      PORTB |= (1<<PORTB4);
    }
  }

  return 0;
}

