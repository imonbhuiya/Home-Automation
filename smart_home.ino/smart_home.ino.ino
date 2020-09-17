#include<Servo.h>
int sensor = A0;
double value=0;
int lightvalue=0;
Servo serv;
int val =0;
void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
  pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
  pinMode(A1,INPUT);
  serv.attach(9);
}
 
void loop()
{
  
  //led on off
  lightvalue = analogRead(sensor);
  Serial.println(lightvalue);
   if(lightvalue<130)
{
   digitalWrite(13,HIGH);
  
 }
  else{
   
    digitalWrite(13,LOW);
  
  } 
  
   {
   
     //sonar sensor on/off
  digitalWrite(2,LOW);
  delay(10);
  digitalWrite(2,HIGH);
  delay(10);
  digitalWrite(2,LOW);
  
    
  int d = pulseIn(4,HIGH);
  //distance calculation
  d = d/29/2;
  delay(500);
  if(d>10)
  {
  serv.write(180); //servo motor will turn in 180 degree
  delay(1);   
   }else{
  serv.write(0);  //servo motor will turn in 0 degree
  delay(5000);
  
}
 //Dc motor on/off
  value = analogRead(A1)*0.004882814;
    value = (value - 0.5) * 100.0;
    serial.println(12,value);
  if(value>35){
    digitalWrite(12,1);
    
  }else{
    digitalWrite(12,0);
  }
 
}

 
}
