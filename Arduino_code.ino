#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define ldr 8

int val;
int val2;
String duration;

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("LiFi Project");
  delay(3000);
  lcd.clear();
  lcd.print("Send any message");
  lcd.setCursor(0, 1);
  lcd.print("from LiFi App..");
  delay(3000);
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    message.trim();
    Serial.print("Displaying message: ");
    Serial.println(message);
    lcd.clear();
    lcd.print(message.substring(0, 16));
    if (message.length() > 16) {
      lcd.setCursor(0, 1);
      lcd.print(message.substring(16, 32));
    }
  }

  val = digitalRead(ldr);
  while (val == 0) {
    val2 = digitalRead(ldr);
    duration += val2;

    if (duration == "001") {
      Serial.println("Received message: hi");
      lcd.clear();
      lcd.print("hi");
    } else if (duration == "0001") {
      Serial.println("Received message: hello");
      lcd.clear();
      lcd.print("hello");
    } else if (duration == "00001") {
      Serial.println("Received message: how are you?");
      lcd.clear();
      lcd.print("how are you?");
    } else if (duration == "000001") {
      Serial.println("Received message: I am fine");
      lcd.clear();
      lcd.print("I am fine");
    } else if (duration == "0000001") {
      Serial.println("Received message: ok");
      lcd.clear();
      lcd.print("ok");
    } else if (duration == "00000001") {
      Serial.println("Received message: good morning");
      lcd.clear();
      lcd.print("good morning");
    } else if (duration == "000000001") {
      Serial.println("Received message: good afternoon");
      lcd.clear();
      lcd.print("good afternoon");
    } else if (duration == "0000000001") {
      Serial.println("Received message: good evening");
      lcd.clear();
      lcd.print("good evening");
    } else if (duration == "00000000001") {
      Serial.println("Received message: thank you");
      lcd.clear();
      lcd.print("thank you");
    } else if (duration == "000000000001") {
      Serial.println("Received message: sorry");
      lcd.clear();
      lcd.print("sorry");
    }

    if (val2 == 1) {
      duration = "";
      break;
    }
    delay(200);
  }
}
