
int redled = 5;
int delayTime=3000;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);

}

void loop() {
  Serial.print("hello world");
  digitalWrite(redled, HIGH);
  Serial.println("0N");
  delay(delayTime);

  digitalWrite(redled, LOW);
  Serial.println("0FF");
  delay(delayTime);
}
