// Arduino G-code Interpreter
// v1.0 Carlos guilarte y diego colonnello...
// Modificado para manejar tres ejes en un cnc chimbo... jejeje

#include <HardwareSerial.h>

//our command string
#define COMMAND_SIZE 128
char palabra[COMMAND_SIZE];
byte serial_count;
int no_data = 0;

void setup()
{
	//Do startup stuff here
	Serial.begin(19200);
	Serial.println("start");
	
	//other initialization.
	init_process_string();
	init_steppers();
	
}

void loop()
{
	char c;
	
	//keep it hot!


	//read in characters if we got them.
	if (Serial.available() > 0)
	{
		c = Serial.read();
		no_data = 0;
		
		//newlines are ends of commands.
		if (c != '\n')
		{
			palabra[serial_count] = c;
			serial_count++;
		}
	}
	//mark no data.
	else
	{
		no_data++;
		delayMicroseconds(100);
	}

	//if theres a pause or we got a real command, do it
	if (serial_count && (c == '\n' || no_data > 100))
	{
		//process our command!
		process_string(palabra, serial_count);

		//clear command.
		init_process_string();
	}

	//no data?  turn off steppers
	if (no_data > 1000)
	  disable_steppers();
}
