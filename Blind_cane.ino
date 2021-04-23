#define TrigPin 9
#define echoPin 8
#define Buzzer1 7
#define Buzzer2 6
#define Led 5
int sound = 340;


void setup() {
 Serial.begin (9600);
 pinMode(TrigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(Buzzer1, OUTPUT);
 pinMode(Buzzer2, OUTPUT);
 pinMode(Led, OUTPUT);
}

void loop() {
  Serial.begin(9600);

  long duration, distance;
  digitalWrite(TrigPin, LOW);
  delay(2);
  digitalWrite(TrigPin, HIGH);
  delay(10);
  digitalWrite(TrigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((sound * duration)/2)/58; //Distance in cm
  digitalWrite(Buzzer1, LOW);
  digitalWrite(Buzzer2, LOW);
  digitalWrite(Led, LOW);
  
  if (distance<40) {
    digitalWrite(Led, HIGH);
    delay(2000);
  }
  if (distance<20) {
    digitalWrite(Led, HIGH);
    delay(2000);
    digitalWrite(Buzzer1, HIGH);
    delay(2000);
  }
  if (distance<10) {
    digitalWrite(Led, HIGH);
    delay(2000);
    digitalWrite(Buzzer1, HIGH);
    delay(2000);
    digitalWrite(Buzzer2, HIGH);
    delay(2000);
  }
  }
