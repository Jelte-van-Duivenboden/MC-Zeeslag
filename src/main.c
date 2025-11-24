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

  while(1)
  {
    
  }

  return 0;
}

