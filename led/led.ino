int ledPin=13;
void setup() {
 pinMode(ledPin,OUTPUT);
 Serial.begin(9600);

}

//void loop() {
  digitalWrite(ledPin,HIGH);
  delay(100);
  digitalWrite(ledPin,LOW);
  delay(100);
  Serial.println("everest");
}
