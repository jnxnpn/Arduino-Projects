
void setup() {
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  
}


void loop() {
  
 digitalWrite(7,HIGH) ;
 Serial.println("xxx");
 delay(300);
 digitalWrite(7,LOW) ;
 Serial.println("o");
 delay(1000);
}
