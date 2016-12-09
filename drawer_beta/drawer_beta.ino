/*2-axis drawer
 by JX Pan*/
//SETTING:
float accuracy= 1.00;
//
#include <Stepper.h>
#include <Servo.h> 
int  xdecidig;
int  ydecidig;
byte readd;
boolean xdone;
boolean ydone;
int stepsCount;
float x;
float y;
float xpositive; //if x is positive
boolean xdecimal;
boolean ydecimal;//if x/y has decimal
boolean G1; //if command is complete received
float num; 

Stepper Sp(2048,8,9,10,11);
Servo Sv;
float xp;
float yp;
boolean xChangeTset;
boolean yChangeTset;
boolean G91;
boolean ok;
int ypositive;

void setup() {

  Sv.attach(5);
  Serial.begin(9600);
  x=0.000;
  y=0.000;
  stepsCount = 0;
  Serial.println("ready");
  xp = -80.00;
  yp = 80.00;
  Sp.setSpeed(12);
  G91 = false;
  accuracy= 1.00;
}



void loop() {
  //setup
  G1 = false; 

  xpositive = 1.00;
  ypositive = 1.00;
  xdone = true;
  boolean xused = false;
  boolean yused = false;
  ydone = true;

  xChangeTset = true;
  yChangeTset = true;


  readSerial();



  //prepare

  if (readd == 71){ //G
    readSerial();
    ok = true;
    //--------------------------------------------------------    
    if (readd == 57){ //9
      readSerial();
      if (readd == 49){//1
        G91 = true;
      }//1
      else if (readd == 48){//0
        G91 = false;
      }//0

    }//eng of 9

    //--------------------------------------------------------

    if (readd == 49){ //1

      readSerial();

      if (readd == 32 ){  //SPACE between g1 and x/y
        readSerial();

        while (readd == 88 || xdone == false){//x


          readSerial();
          xdone = false;
          if (xChangeTset == true){
            x=0.000;
            xChangeTset = false;
          }
          //xbackup = xp;


          if (readd == 45){ //negative sign
            xpositive = -1.00;
          }
          if (readd == 46) {//decimal point
            xdecimal = true;
          }
          if (readd >=48 && readd <=57){//numbers

            x = readd-48.000 + 10.000*x;
            deci(1);

          }
          if (readd == 32||readd == 10){
            xdone = true;
            G1 = true;
            xused = true;
            readSerial();

          }

        }//end of x



        while (readd == 89 || ydone == false){  //y
          // ybackup = yp; //TBD if needed
          readSerial();
          ydone = false;
          if (yChangeTset == true){
            y=0.000;
            yChangeTset = false;
          }

          if (readd == 45){ //negative sign
            ypositive = -1.00;
          }
          if (readd == 46) {//decimal point
            ydecimal = true;
          }
          if (readd >=48 && readd <=57){//numbers

            y = readd-48.000 + 10.000*y;
            deci(2);
          }


          if (readd == 32||readd == 10){
            G1 = true;
            yused = true; 
            ydone = true;

          }
        }//end of y


      }//end of space

    }//end of 1
    //--------------------------------------------------------
    if (readd == 50){ //2

      readSerial();

      if(readd== 56){ //8

        x = 0.000;
        y = 160.000;
        G1 = true; 
      }//8
    }//2
    //--------------------------------------------------------
  }//end of g

  if(readd == 77){//M

    ok = true;
  }

  //-------------------------

  if (G1 == true){
    //process raw data:
    for(ydecidig=ydecidig;ydecidig>0;ydecidig--){
      y = y/10.000;
      ydecimal = false;

    }
    for(xdecidig=xdecidig;xdecidig>0;xdecidig--){
      x=x/10.000;
      xdecimal = false;

    }
    x=x*xpositive; 
    y=y*ypositive;

    if( G91 == true){
      if (xused == true){
        x = x + xp;
      }
      if (yused == true){
        y = y + yp; 
      }
    }


    if (y<0){
      y=0;
      Serial.println ("Y can't be negative");
    }

    //for test sake yet----/start

    Serial.println ("I got:");
    Serial.print ("x");
    Serial.print(x);
    Serial.print("  y");
    Serial.println(y);
    //for test sake----/end


 //   while (distance(xp,yp)>1.00) {

  //    float xt = xp+(x-xp)/distance(xp,yp);
  //    float yt = yp+(y-yp)/distance(xp,yp);

  //    toCoordinate(xt,yt);


//      }
 //   if (distance(xp,yp)<=1.00){
        toCoordinate(x,y);
    



    //universal ending code:
    G1 = false; 

  }


  if (ok == true){
    Serial.println("ok");
    ok = false;
  }


}//end of loop


//read gcode








//-----------------------background-----------------------------

void readSerial(){
  readd = Serial.read();
  delay(5);
  switch(readd) {
  case 103:
    readd = 71;
    break; 

  case 120:
    readd = 88;
    break;

  case 121:
    readd = 89;
    break;

    delay(8);

  }
}


void deci(int axis){
  if (axis == 1 && xdecimal == true){

    xdecidig ++;
  }
  if(axis==2 && ydecimal == true) {
    ydecidig ++;

  }

} 
//for toCoordinate:
float pi=3.14159265358;

void toCoordinate(float X, float Y){

  double c = sqrt(pow(X,2)+pow(Y,2));

  if (c<20.00){
    c= 20.00;
  }
  else if (c>160.00){
    c= 160.00;
  }

//
  double B = acos(c/160.0000);
  double A = atan2(X,Y);

  int stepsDesti = int((A+B)/2/pi*2048);
  Sp.step(stepsDesti-stepsCount);
  Serial.print("stepper:");
  Serial.println(stepsDesti-stepsCount);
  
  stepsCount=stepsDesti;
  
  int C = int((pi-2*B)/pi*180);
  Serial.print("servo:");
  Serial.println(C);

  Sv.write(C);
  xp = X;
  yp = Y; 


}

float distance(float X, float Y){ //from input to x,y
  return (float(sqrt( pow((x-X),2)+pow((y-Y),2))));
}


















