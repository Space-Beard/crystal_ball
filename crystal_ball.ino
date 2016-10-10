// import liquid crystal library
#include <LiquidCrystal.h>
// create lcd object and tell it which pins it will be using
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//create the variables
const int switchPin = 6;
int switchState = 0;
int previousSwitchState = 0;
int reply;

void setup() {
  // tell the library how big the LCD is and set the switchPin mode
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);

  //set the LCD up with a question for the user
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
  
}

void loop() {
  // read the switch pin
  switchState = digitalRead(switchPin);
  
  if(switchState != previousSwitchState) {
    if(switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);

      switch(reply) {
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;        
      }
    }
  }

  // set previous switch state variable
  previousSwitchState = switchState;
  delay(250);
  
}
