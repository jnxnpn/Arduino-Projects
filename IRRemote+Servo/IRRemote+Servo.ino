/* IR remote+ Sevo
servo signal --- 10
led +222ohms resistor--- 2
IR signal --- 11
power button = home (0°)
numbers + play button = go degrees
st/rec button = clear */



#include <IRremote.h>
#include <Servo.h>;
const int RECV_PIN = 11;
Servo servo;
IRrecv irrecv(RECV_PIN); //!!!

decode_results results; //!!!

boolean command;

long rec;

int ang; 




void setup()
{servo.attach(10);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  command = false; 
}

void loop() {
  
  rec = 0;
  
  if (irrecv.decode(&results)) {   //!!!
    irrecv.resume();   // Receive the next value
    rec = results.value;
  }

  switch (rec) {
  case 16593103:
    ang = 10*ang;
    led();
    break;
  case 16582903:
    led();
    ang = 10*ang + 1;
    break;

  case 16615543:
    ang = 10 * ang +2;
    led();
    break;
  case 16599223:
    ang = 10*ang + 3;
    led();
    break;
  case 16591063:
    ang = 10*ang + 4;
    led();
    break;
  case 16623703:
    ang = 10*ang + 5;
    led();
    break;
  case 16607383:
    ang = 10*ang + 6;
    led();
    break;
  case 16586983:
    ang = 10*ang + 7;
    led();
    break;


  case 16619623:
    ang = 10*ang + 8;
    led();
    break;
  case 16603303:
    ang = 10*ang + 9;
    led();
    break;
  case 16609423://rept ==>clear
    ang = 0;
    led();
    break;

  case 16580863: // home
    ang = 0;
    led();
    command = true; 
    break;
  case 16621663:
    command = true;
    led();
    break;
  default: 
    // if nothing else matches, do the default
    // default is optional
    break;
  }
  
  
  
  if (command == true) {//servo
    servo.write(ang);
    Serial.print("angle: ");
    Serial.println(ang);
    ang = 0;
    command = false;
  }
delay(10);
} 


void led() {
  pinMode(2,OUTPUT);
  digitalWrite (2,HIGH);
  delay(50);
  digitalWrite (2,LOW);
}



