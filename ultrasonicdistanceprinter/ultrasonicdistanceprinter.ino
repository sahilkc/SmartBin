#define NOTIFYDISTANCE 5
int tme=0;
int ledPin1=8;
int ledPin2=9;
int ledPin3=10;
const int echopin=3;
const int trigerpin=2;
int distance=0;
bool sentno=1;
unsigned long lastfulltime=0;
bool firsttime=1;
void setup() {
  pinMode(3,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(10,OUTPUT);
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
if(distance<10)
{
  digitalWrite(ledPin1,HIGH);
  delay(100);
  digitalWrite(ledPin1,LOW);
  delay(100);
  }
 else
 { digitalWrite(ledPin2,HIGH);
  delay(100);
  digitalWrite(ledPin2,LOW);
  delay(100);
  }
  
if(distance <= NOTIFYDISTANCE){
  if(firsttime){
   lastfulltime=millis(); 
    firsttime=0;
    Serial.println(11);
    digitalWrite(ledPin3,HIGH);
    delay(100);
    digitalWrite(ledPin3,LOW);
    delay(100);
    
  }else{
      if( (millis()-lastfulltime)>= 60000){
        Serial.println(11);
        lastfulltime=millis();
        }
  }
 firsttime=1;
 
}

delay(2);
}
