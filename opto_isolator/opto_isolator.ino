int cmd;

void setup() {
Serial.begin(9600);
pinMode(11,OUTPUT);
}

void loop() {
if(Serial.available()>0){
  
  while(Serial.peek()>47&&Serial.peek()<58){
    byte bt = Serial.read()-48; 
    cmd=cmd*10+bt;
    delay(10);
  }
  while(Serial.available()>0){
    Serial.read();}
  if(cmd<=160){
  Serial.print("writting:");
  Serial.println(cmd); 
  analogWrite(11,cmd);
  cmd=0;
  delay(50);
  }
  
}else{
  float Vout = analogRead(A0)/1023.00*4.60;
  float resis = (10000*Vout)/(4.60-Vout);
  Serial.print("Resistance of the PhoRes:");
  Serial.println(resis); 
  delay(500);
}
}
