void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
int num= analogRead(A0);

float volts = (4.7* num / 1023);
 float ohms = 

Serial.print("raw data: ");
Serial.print(num);
Serial.print("   volts: ");
Serial.print(volts);
Serial.print("   ohms: ");
Serial.println(ohms);



delay(500);

}
