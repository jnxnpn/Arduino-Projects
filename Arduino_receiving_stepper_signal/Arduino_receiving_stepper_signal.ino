/*

Arduino stepper signals reader. 
by JX Pan

A experiment for my laser-cutting 3d printer project. My plan is to add another
Arduino to the 3d printer that I'm about to get, and to use this extra Arduino
to control a laser according to commands which are sent from 
ramps1.4 (the 3d printer's electronics) as stepper motor signals and 
interpreted by the second Arduino's (I'm using a UNO) firmware. 

It's a work-in-progress. I might finish this project (OR NOT...) in summer. 
If you are planing to do the same thing, don't refer to mine yet. 
You can do that once I have a reliable firmware developed.
That should not be remote. But all the hardware jobs will not be 
started until after my final exam in school. 

Connect the stepper signals to 2-5
Connect the stepper driver you use to create signals to 8-11, or of 
course you can simply ignore these pins and run a stepper driver controlled
elsewhere. 

I have used a pot to control the speed of the stepper signals and 
directions for testing sake. The signal of pot is connected to pin A0. 

ADD RESISTORS maybe if you are reading signals for larger Stepper motors. 
I'm using a driver for tiny little steppers using Arduino's internal power 
inout so I didn't use any resistors. Don't know if it's necessary to do 
that when you use a more powerful stepper driver. A external power source 
may cause a difference too.
*/

#include <Stepper.h>


float motorSpeed;

Stepper myStepper(2048, 8,9,10,11);            




int a;

void setup() {
  pinMode (2,INPUT);
  pinMode (3,INPUT);
  pinMode (4,INPUT);
  pinMode (5,INPUT);
Serial.begin(9600);
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(0);
  int r1 = digitalRead(2);
  int r2 = digitalRead(3);
  int r3 = digitalRead(4);
  int r4 = digitalRead(5);
  
  
  
  if (sensorReading < 512) {
  
     motorSpeed = map(sensorReading, 511, 0, 0, 14);
  
     a = -1;} else {
       a = 1;
       motorSpeed = map(sensorReading, 512, 1023, 0, 14);
      
    }
   
  Serial.print(r1);
  Serial.print(r2);
  Serial.print(r3);
  Serial.println(r4);
  
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(a);
  } 


}
