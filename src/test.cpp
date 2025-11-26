#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <Wire.h>
#include <HardwareSerial.h>
#include <Nunchuk.h>

#define NUNCHUK_ADDRESS 0x52
#define WAIT		1000
#define BAUDRATE	9600
#define CHUNKSIZE	32

int nunchuk_read(void)
{

	// serial 
	Serial.begin(BAUDRATE);

	// I2C bus als master
	Wire.begin();


	// handshake met de nunchuk
	Serial.print("-------- Connecting to nunchuk at address 0x");
	Serial.println(NUNCHUK_ADDRESS, HEX);
	if (!Nunchuk.begin(NUNCHUK_ADDRESS))
	{
		Serial.println("******** No nunchuk found");
		Serial.flush();
		return(1);
	}

    
    // identificatie
	Serial.print("-------- Nunchuk with Id: ");
	Serial.println(Nunchuk.id);

    while(1)
    {
     	if (!Nunchuk.getState(NUNCHUK_ADDRESS))
	        return (false);
  
        if (Nunchuk.state.joy_x_axis  == 80) 
        {
            Serial.print("midden");
        }

        if (Nunchuk.state.joy_x_axis > 80) 
        {
            Serial.print("rechts");
        }


        if (Nunchuk.state.joy_x_axis < 80)
        {
            Serial.print("links");
        }

        Serial.print(Nunchuk.state.joy_x_axis, HEX);

        _delay_ms(1000);
    }

    return(0);
}