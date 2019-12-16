#define LS 2     
#define RS 3 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hello world");
  if(digitalRead(LS) && digitalRead(RS))     // Stop
  {
    Serial.println("both detect");
    delay(1000);
  }
  else if(!digitalRead(LS) && digitalRead(RS))     // Stop
  {
    Serial.println("right detect");
    delay(1000);
  }
  else if(digitalRead(LS) && !digitalRead(RS))     // Stop
  {
    Serial.println("left detect");
    delay(1000);
  }
  else{
    Serial.println("you can move");
    delay(1000);
  }
}
