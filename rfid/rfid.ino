#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
#define LED             4
#define BUZZER          5

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

//gunnu uid =  04 71 DF 2B
//jappu uid =  79 29 0A E3


String GunnuCard = "04 71 DF 2B";
String JappuCard = "79 29 0A E3";

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  //mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Ready to Scan..."));
  noTone(BUZZER);
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  //Serial.print("uid = ");
  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    uid.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  uid.toUpperCase();
  //Serial.println(uid);

  if (uid.substring(1) == GunnuCard) {
    Serial.println("Detected my rfid Card");
    gunnu_led();
  }
  else if (uid.substring(1) == JappuCard) {
    Serial.println("Detected my rfid Tag");
    jappu_led();
  }
  else {
    Serial.println("Unauthorized rfid");
    sound_alarm();
  }

  
  // Dump debug info about the card; PICC_HaltA() is automatically called
  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  mfrc522.PICC_HaltA();
}


void sound_alarm()
{
  for (int i1 = 0; i1 < 5; i1++) {
    delay(200);
    for (int i = 1000; i < 2000; i++) {
      tone(BUZZER,i);   
      delay(1);
    }
    noTone(BUZZER);
  }
}

void gunnu_led() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED,HIGH);
    delay(500);
    digitalWrite(LED,LOW);
    delay(500) ;
  }
}

void jappu_led() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    delay(100) ;
  }
}
