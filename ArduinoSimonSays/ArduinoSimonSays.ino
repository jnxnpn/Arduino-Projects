/*ArduinoSimonSays v1.03
by JX Pan June 2014
email 736107120@qq.com
contact me before spreading thecode for any purpose
see DEMO here: http://v.youku.com/v_show/id_XNzIwOTE4NzI4.html
      or here: https://www.youtube.com/watch?v=dylmt4iHhME
      
havr fun
*/


//-----------------
//SETTINGS:
const int inPutWaitTime= 10000; //in ms, how long to wait for your input until ruled losing
const int PinLED1=4; //led1 has to be lower than led2
const int PinLED2=5;
const int PinBUT1=12; //button 1 works for led1
const int PinBUT2=13;
const int difficulty= 600; //the smaller the harder, but not lower than 63, cuz your eyes could not recognize the blinks then
const int buttonReactTime= 400; // the smaller, the faster you can input your answer. 

//-----------------
//CODE:
int arrange [100];
int i;

void setup() {
  pinMode(PinLED1,OUTPUT);
  pinMode(PinLED2,OUTPUT);
  pinMode(PinBUT1,INPUT);
  pinMode(PinBUT2,INPUT);
}

void loop() {

  randomSeed(analogRead(3)*millis()/analogRead(5));
  arrange[i] = random(1,3);


  for(int n=0;arrange[n]>0;n++){
    digitalWrite(PinLED1-1+arrange[n],HIGH);
    digitalWrite(PinLED1+2-arrange[n],LOW);
    delay(difficulty);
    digitalWrite(3+arrange[n],LOW);
    delay(difficulty*0.75);
  }
  int answerN = 0;
  for (int n = 0; n<inPutWaitTime;n++){

    if(digitalRead(PinBUT1)==HIGH){
      if(arrange[answerN] ==1){
        flash(PinLED1,PinLED2,buttonReactTime);
        answerN ++;
        n=0;
      }
      else{
        loseRoutine();
        break;
      }
    }
    if(digitalRead(PinBUT2)==HIGH){
      if(arrange[answerN] ==2){
        flash(PinLED2,PinLED1,buttonReactTime);
        answerN ++;
        n=0;
      }
      else{
        loseRoutine();
        break;
      }
    }
    if (arrange[answerN]==0){
      delay(400);
      break;
    }
    if(n==inPutWaitTime-1){
      loseRoutine();
      break;
    }

    delay(1);
  }



  i++;
  if(i == 100){
    digitalWrite(PinLED1,HIGH);
    digitalWrite(PinLED2,HIGH);
    delay(1000);
    digitalWrite(PinLED1,LOW);
    digitalWrite(PinLED2,LOW);
    delay(1000);
    digitalWrite(PinLED1,HIGH);
    digitalWrite(PinLED2,HIGH);
    delay(1000);
    digitalWrite(PinLED1,LOW);
    digitalWrite(PinLED2,LOW);
    delay(1000);
    digitalWrite(PinLED1,HIGH);
    digitalWrite(PinLED2,HIGH);
    delay(5000);
    digitalWrite(PinLED1,LOW);
    digitalWrite(PinLED2,LOW);
    delay(2000);
  }
}


void flash(int pin, int pinToClose, int time){
  digitalWrite(pinToClose,LOW);
  digitalWrite(pin,HIGH);
  delay(time);
  digitalWrite(pin,LOW);
}

void loseRoutine(){
  digitalWrite(PinLED1,HIGH);
  digitalWrite(PinLED2,HIGH);
  delay(500);
  digitalWrite(PinLED1,LOW);
  digitalWrite(PinLED2,LOW);
  delay(500);
  digitalWrite(PinLED2,HIGH);
  digitalWrite(PinLED1,HIGH);
  delay(1000);
  digitalWrite(PinLED1,LOW);
  digitalWrite(PinLED2,LOW);
  delay(1500);
  i = -1;
  for(int times= 0; times<100;times++){
    arrange [times]=0;
  }
}





