

#include <Stepper.h>
Stepper stepmotor(2048, 8,9,10,11);  // (stepsPerRevo,pin1,pin4,pin2,pin3---for my stepper)     
int digCount; 
byte byteRead;
int steps;
boolean xTest;



void setup() {
  Serial.begin(9600);
}



void loop() {
  
  steps = 0; 
  byteRead = Serial.read();
  //digCount = 0;
  xTest = false
  
  if (byteRead == 88 || xTest == true) {
    
    xTest = true;
    delay(10);    // for better communication
    byteRead = Serial.read(); 


    if (byteRead >=48 && byteRead <= 57) {
      //digCount = digCo+1;
      steps = (byteRead -48) + num * 10;






    }

  }

}















