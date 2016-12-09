int a =750;int a =750;photoresistorphotoresistor

//    5v---Photoresistor------10k-resis--GND
//                        |
//                        A0

//    12------(+led-)-----220-resis---GND

int a =750;

void setup ()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
}
void loop()
{
  int n = analogRead(A0);            //读取模拟口A0数值
  Serial.println(n);
  if (n <= a )                   //对光线强度进行判断，如果比我们的预设值大 就点亮LED否则就关闭
  {
    digitalWrite(12,HIGH);
  }
  else
  {
    digitalWrite(12,LOW);
  }
}
