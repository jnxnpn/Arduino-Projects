//PIN 2-7 HOOK UP TO LEDs' positive
//POt-middle to A0

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {
  int set = analogRead(A0);
  float rang = 1024/6;
  
  while(set<(rang-1))
  { 
    digitalWrite(2,HIGH)     ;
    set = analogRead(A0); 
  } 
  digitalWrite(2,LOW);
  while(set<(2*rang-1) && rang<set )
  {  set = analogRead(A0);
    digitalWrite(3,HIGH)     ;
  
  }  
  digitalWrite(3,LOW);
  while( set<3*rang-1 && 2*rang<set)
  { set = analogRead(A0); 
    digitalWrite(4,HIGH)     ;
    
  } 
  digitalWrite(4,LOW);
  while( set<4*rang-1 && 3*rang<set)
  { set = analogRead(A0); 
    digitalWrite(5,HIGH)     ;
    
  } 
  digitalWrite(5,LOW);
  while( set<5*rang-1 && 4*rang<set)
  {  set = analogRead(A0);
    digitalWrite(6,HIGH)     ;
    
  } 
  digitalWrite(6,LOW);
  while( set<1024 && 5*rang<set)
  {  set = analogRead(A0);
    digitalWrite(7,HIGH)     ;
     
  } 
  digitalWrite(7,LOW);
  

}

