int LED = 13;
int BUTTON = 4;

int counter = 1;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {  
  int buttonvalue = digitalRead(BUTTON);

  if (buttonvalue == HIGH) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}

void test_led() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay (1000);
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay (1000);
}

void test_pushbutton() {
  delay (1000);
  int buttonvalue = digitalRead(BUTTON);
  Serial.println(buttonvalue);
}


void debug_method() {
  Serial.println("start with delay 3s");
  delay (10000);
  int buttonvalue = digitalRead(BUTTON);
  Serial.println("value of button = ");
  Serial.println(buttonvalue);
  
  if (buttonvalue != 0);
  {
    Serial.println("going into high loop and switching led on");
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.println("wait for 3s");
    delay (1000);
  }
  Serial.println("value of button = ");
  Serial.println(buttonvalue);
  if (buttonvalue == 0);
  {
    Serial.println("going into low loop and switching led off");
    digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
    Serial.println("wait for 3s");
    delay (1000);
  }
}

void led_heartbeat()
{
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
  
    digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
    delay(50);                       // wait for a second
  
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
  
    digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
    delay(1000); 
}
