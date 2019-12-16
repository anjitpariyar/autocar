int ldrValue;
int ledPin=5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}
int ldr(){
  ldrValue=analogRead(A0);
  Serial.print("ldrValue ");
  Serial.println(ldrValue);
  if(ldrValue<=400){
   Serial.println("led on");
   digitalWrite(ledPin,HIGH);
   delay(1000);
   }
   else{
   Serial.println("led off");
   digitalWrite(ledPin,LOW);
   delay(1000);
   }
   return ldrValue;
}
void loop() {
  // put your main code here, to run repeatedly:
  ldrValue=ldr();
}
