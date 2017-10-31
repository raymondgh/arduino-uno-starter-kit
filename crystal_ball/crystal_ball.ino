#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask me a");
  lcd.setCursor(0, 1);
  lcd.print("yes/no question");
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState) {
    if(switchState == LOW) {
      reply = random(8);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("I say...");
      lcd.setCursor(0, 1);
      switch(reply) {
        case 0:
          lcd.print("Heck yes!");
          break;
        case 1:
          lcd.print("Bet on it.");
          break;
        case 2:
          lcd.print("Absolutely.");
          break;
        case 3:
          lcd.print("       ...what?");
          break;
        case 4:
          lcd.print("Don't ask that.");
          break;
        case 5:
          lcd.print("Ask again");
          break;
        case 6:
          lcd.print("Fat chance");
          break;
        case 7:
          lcd.print("NOOOOOO!!!!");
          break;
      }
      delay(1500);
        lcd.clear();
        lcd.print("Ask me a");
        lcd.setCursor(0, 1);
        lcd.print("yes/no question");
      
    }
  }
  prevSwitchState = switchState;
}
