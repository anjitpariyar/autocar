#include <Servo.h> 
#define trigPin 6  //for ultra sonic sensor
#define echoPin 13 //for ultra sonic sensor

#define LS 2     
#define RS 3 

int motorAIn1=10;
int motorAIn2=9;
int motorBIn1=11;
int motorBIn2=12;
int ledPin=5;
int ldrValue;
int ultraValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(motorAIn1,OUTPUT);
  pinMode(motorAIn2,OUTPUT);
  pinMode(motorBIn1,OUTPUT);
  pinMode(motorBIn2,OUTPUT);
//ldr
  pinMode(ledPin,OUTPUT);
//for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
 void forward(){
  
   Serial.println("Foward");
  digitalWrite(motorAIn1,HIGH);
  //analogWrite(motorAIn1,);
  digitalWrite(motorAIn2,LOW);
  digitalWrite(motorBIn1,HIGH);
  digitalWrite(motorBIn2,LOW);


  
 }



// void back(){
//  
//  Serial.println("back");
//  //digitalWrite(motorAEnable,HIGH);
//  digitalWrite(motorAIn1,LOW);
//  //analogWrite(motorAIn2,100);
//  digitalWrite(motorAIn2,HIGH);
//  //digitalWrite(motorBEnable,HIGH);
//  digitalWrite(motorBIn1,LOW);
//  //analogWrite(motorBIn2,100);
//  digitalWrite(motorBIn2,HIGH);
//
// }

 void stop(){
  
  //digitalWrite(motorAEnable,LOW);
//  Serial.println("stop");
  analogWrite(motorAIn1,0);
  digitalWrite(motorAIn2,LOW);
  //digitalWrite(motorBEnable,HIGH);
  analogWrite(motorBIn1,0);
  digitalWrite(motorBIn2,LOW);

 }
// ldr function
int ldr(){
 
  ldrValue=analogRead(A0);
//   Serial.print("ldrValue ");
//  Serial.println(ldrValue);
    if(ldrValue<=400){
    Serial.println("led on");
    digitalWrite(ledPin,HIGH);
    }
    else
    digitalWrite(ledPin,LOW);
  return 0;
}
// void blink(){
//  for(int i=0;i<2;i++){
//    digitalWrite(ledPin,LOW);
//    delay(500);
//    digitalWrite(ledPin,HIGH);
//    delay(500);
//    digitalWrite(ledPin,LOW);
//    delay(500);
//  }
// }

//ultrasonic function
int ultrasonic(){
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

//  if (distance >= 2000 ) {
//    Serial.println("Out of range");
//  }
//  else {
//    Serial.print("ultra sonic distance");
//    Serial.print(distance);
//    Serial.println(" cm");
//  }
  if (distance > 60 ) {
    Serial.println("path clear");
    return 0;
  }
  else {
     Serial.println("something is ahead of us");
    return 1;
  }
  
 
} 


//main loop
void loop() {
  // put your main code here, to run repeatedly:
   ultraValue= ultrasonic();
    if(ultraValue){
      stop();}
  if(digitalRead(LS) && digitalRead(RS))     // Stop
  {
    stop();
    ldrValue=ldr();
    Serial.println("both detect");
    ldrValue=ldr();
  }
  ultraValue= ultrasonic();
    if(ultraValue){
      stop();}

   if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    ldrValue=ldr();
    Serial.println("left detect");
     stop();
     ldrValue=ldr();
  }
if(!(digitalRead(LS)) && !(digitalRead(RS)))     // move foward
  {
    
//    Serial.println("first case not  detect");
//    now time to put ultra sonic 
    ultraValue= ultrasonic();
    if(ultraValue){
      stop();
      ldrValue=ldr();
//      Serial.println("turning left case 2");
    if(digitalRead(LS) && digitalRead(RS))     // Stop
  {
    
//    Serial.println("both detect");
    stop();
    ldrValue=ldr();
  }
      stop();
     }
     else{
//      Serial.println("moving foward hurrey");
      ldrValue=ldr();
          forward();
            if(digitalRead(LS) && digitalRead(RS))     // Stop
  {
     stop();
    ldrValue=ldr();
    Serial.println("both detect");
    ldrValue=ldr();
  }

         }
}

  if(digitalRead(LS) && !(digitalRead(RS)))     // Turn left
  {
    
    Serial.println("Right side detect");
    stop(); 


                 
    
  }
// ldr work
ldrValue=ldr();
//ultra sonic test
ultraValue= ultrasonic();
Serial.println(ultraValue);

}
