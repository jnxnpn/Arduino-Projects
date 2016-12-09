
//ohmmeter
//by JX Pan
//see forst pic in http://en.wikipedia.org/wiki/Voltage_divider
// Vin ==> +5v
// Vout ==> A0
// Z1 ==> resistor to be measured
// Z2 ==> 10k resistor
//Should work with 4.65v output (measured data from my Arduino)


void setup() {                

  Serial.begin(9600);
  
  

}


void loop() {
  
  int raw = analogRead(A0);
  float volts = 4.65*raw/1023;
  float ohms = 4.65/volts*10000-10000;
  
  Serial.print ("Raw number: ");
  Serial.print (raw);
  Serial.print ("     Resistance: ");
  Serial.print (ohms);
  Serial.println (" ohms");
  delay(500);
  
}
