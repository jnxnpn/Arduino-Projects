void setup() {
  Serial.begin(9600);
  Serial.println("ready");
  Serial.println("ok");
}



const int cacheSize = 64;
int cache[cacheSize];



void loop() {
  //Serial.println("ok");
  int G=0 ;
  int M=0 ;
  float X =0;
  float Y=0 ;
  int F=0 ;
  float E=0;
  boolean cmdRead=false; 
  boolean Gcg=false;
  boolean Mcg=false;
  boolean Xcg=false;
  boolean Ycg=false;
  boolean Ecg=false;


  for(int i=0; Serial.available()>0; i++){
    cache[i] = Serial.read();
    cmdRead = true;
    delay(6);
  }


  if(cmdRead == true){
    
    for(int i=0; i<cacheSize && cache[i]!=-1; i++){
      if(cache[i]=='G'){
        G = int(readNum(i));
        Gcg = true;
      } 
      else if(cache[i]=='M'){
        M = readNum(i);
        Mcg = true;
      } 
      else if(cache[i]=='X'){
        X = readNum(i);
        Xcg = true;
      } 
      else if(cache[i]=='Y'){
        Y = readNum(i);
        Ycg = true;
      } 
      else if(cache[i]=='F'){
        F = readNum(i);
      } 
      else if(cache[i]=='E'){
        E = readNum(i);
        Ecg = true;
      }
    } 
    Serial.println("ok");
  }


  if(Gcg == true){
    Serial.print("I got G");

    Serial.print(G);
    Serial.print(" X");
    Serial.print(X);
    Serial.print(" Y");
    Serial.print(Y);
    Serial.print(" F");
    Serial.print(F);
    Serial.print(" E");
    Serial.println(E);



  }


  for(int i=0; i<cacheSize; i++){
    cache[i]=0;
  }


}


float readNum ( int pos ) {


pos++;
char temp[cacheSize];
int poss;

  for( pos, poss; pos<cacheSize && num(cache[pos]) >0 ; pos++, poss++){
   
    temp[poss]=cache[pos];
  }
  return atof(temp);
}



byte num ( int input ) {
  if ( input > 47 &&  input < 58) {
    return 1; 
  }
  else if(input == 45 ){
    return 2;
  }
  else if(input == 46){
    return 3;
  }
  else{
    return 0; 
  }
}

