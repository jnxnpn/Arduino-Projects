
#include <Servo.h>;

//hook up servo-yellow to pin 9
//hook up servo-red to +V5
//hook up servo-brown to GND
//serial read optional
//POT-midle to A0, left to +5v right to GND...or whatever

Servo servo;

void setup() {

  Serial.begin(9600);
  servo.attach(9);
}
  
void loop ()
{
  // read the input on analog pin 0:
  int ana = analogRead(A0);
  int degree = ana * 0.175 ;
  servo.write(degree);
  Serial.print("it is at "); 
  Serial.print(degree);
  Serial.println(" degrees now");  
  delay(100);     
}
