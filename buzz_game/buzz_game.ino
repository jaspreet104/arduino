int LED = 13;
int BUZZER = 9;
int GAMEUP = 0;
int BUZZERSTATUS = 12;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,INPUT);
  Serial.begin(9600);
}

void loop() {
  if (GAMEUP == 1) {
    digitalWrite(LED,HIGH);
    return;
  }
  test_buzzer();
  if (digitalRead(BUZZERSTATUS) == HIGH) {
    GAMEUP = 1;
  }
}

void test_buzzer() {
  tone(BUZZER,500);
}

void test_led(){
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000) ;
}
