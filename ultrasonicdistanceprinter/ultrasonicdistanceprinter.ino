unsigned long lastfulltime=0;
bool firsttime=1;
void setup() {
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
}

void loop(){
digitalWrite(trigerpin,LOW);
delay(2);
digitalWrite(trigerpin,HIGH);
delay(10);
digitalWrite(trigerpin,LOW);

tme=pulseIn(echopin,HIGH);
//time in microseconds

distance=tme*0.017;
Serial.println(distance);
}
