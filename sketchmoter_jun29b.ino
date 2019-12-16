
#include <Servo.h> 
int motorAIn1=10;
int motorAIn2=9;
int motorBIn1=11;
int motorBIn2=12;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//pinMode(motorBEnable,OUTPUT);
pinMode(motorAIn1,OUTPUT);
pinMode(motorAIn2,OUTPUT);
pinMode(motorBIn1,OUTPUT);
pinMode(motorBIn2,OUTPUT);

}
 void forward(){
  delay(1000);
  Serial.println("Foward");
  digitalWrite(motorAIn1,HIGH);
  digitalWrite(motorAIn2,LOW);
  digitalWrite(motorBIn1,HIGH);
  digitalWrite(motorBIn2,LOW);
  delay(1000);
 }


// void back(){
//  delay(10);
//  Serial.println("back");
//  //digitalWrite(motorAEnable,HIGH);
//  digitalWrite(motorAIn1,LOW);
//  //analogWrite(motorAIn2,100);
//  digitalWrite(motorAIn2,HIGH);
////digitalWrite(motorBEnable,HIGH);
//digitalWrite(motorBIn1,LOW);
////analogWrite(motorBIn2,100);
//digitalWrite(motorBIn2,HIGH);
//delay(10);
// }

 void stop(){
  delay(1000);
  Serial.println("stop");
  analogWrite(motorAIn1,0);
  digitalWrite(motorAIn2,LOW);
  analogWrite(motorBIn1,0);
  digitalWrite(motorBIn2,LOW);
  delay(1000);
 }
 


void loop() {
  Serial.println("hello world");
  delay(100);
  forward();
  delay(1000);
  stop();
  delay(1000);
}
