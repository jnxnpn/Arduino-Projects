//to determine voltage of something
//connect the negative end to GND
//and the positive end to A0
//number should be accurate when powered by a Macbook Air

//WIRING: (work as a voltmeter)
// (A0)              (GND)
//  |                  |
//  |---10K RESISTOR---|
//  |                  |
// (+)---BATTERY(S)---(-)


//WIRING: (work as a temperature reader for LM35)
// (V5)     (A0)    (GND)
//  |        |        |
//  |        |        |
//  |        ^        |
// (+)----(SIGNAL)---(-)
//        --------   



//don't input anything higher than 4.65v/5v

void setup() {

   Serial.begin(9600);

}

void loop() {
  
  int num= analogRead(A0);
  float volts = 4.65*num/1023;
  float temp = (100*volts);
  
  Serial.print ("Raw number: ");
  Serial.print (num);
  Serial.print ("     Temperature: "); //uncomment these two lines
  Serial.println (temp);               //to read a LM35 sensor
  Serial.print ("     Volts: ");
  Serial.println (volts);
  

  delay(500);
}
