int LED = 8;
int PUSHBUTTON = 7; 


void setup() {
  pinMode(LED,OUTPUT);
  pinMode(PUSHBUTTON,INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(PUSHBUTTON);
  if (value==HIGH)
  {
    digitalWrite (LED,HIGH);
  }
  else
  {
    digitalWrite (LED,LOW);
  }
}

void test_switch() {
  int pushbutton_value = digitalRead (PUSHBUTTON);
  Serial.println(pushbutton_value); 
}

void test_led(){
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000) ;
}
