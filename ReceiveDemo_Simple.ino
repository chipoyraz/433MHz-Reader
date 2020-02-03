#include <LiquidCrystal.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
LiquidCrystal lcd(12, 11, 5, 4, 3, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  mySwitch.enableReceive(0);
  lcd.setCursor(2,2);
  lcd.print("RECEIVED HEX");
}

void loop() {
  if (mySwitch.available()) {
    lcd.home();
    lcd.print(mySwitch.getReceivedValue());
    mySwitch.resetAvailable();
  }
}
