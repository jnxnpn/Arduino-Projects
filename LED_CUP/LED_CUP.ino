void setup() { 
  for (int i=2; i<=4; i++) pinMode(i,OUTPUT); 

}
void loop() {
  int vol=analogRead(A0)*(5.0/1023.0*100); 

  digitalWrite(4,(vol<=25));                //低温区温度设置
  digitalWrite(3,(vol>25 && vol<28));       //中温区温度设置
  digitalWrite(2,(vol>=28));                //高温区温度设置
}

