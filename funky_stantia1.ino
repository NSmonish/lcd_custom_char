#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

byte smile[8] = {0b00000,0b01010,0b00000,0b00000,0b10001,0b01110,0b00000,0b00000};

byte heart[8] = {0b00000,0b01010,0b11111,0b11111,0b11111,0b01110,0b00100,0b00000};

byte sad[8] = {0b00000,0b10001,0b00000,0b00000,0b01110,0b10001,0b00000,0b00000};


void setup()
{
  Serial.begin(9600);
  Serial.println("1) Smile");
  Serial.println("2) Sad");
  Serial.println("3) Heart");
  Serial.println("4) Exit");
  lcd.begin(16, 2); 
}
void loop()
{
  Serial.println("Enter Choice: ");
  while (Serial.available()==0) {}
  int option=0;
  while (option!=4) {
    option = Serial.parseInt();
    if (option==1) {
      lcd.createChar(5, smile); 
      lcd.setCursor(5,0);
      lcd.write(5);
    }

    else if (option==2) {
      lcd.createChar(5, sad);
      lcd.setCursor(5,0);
      lcd.write(5);
    }

    else if (option==3) {
      lcd.createChar(5, heart);
      lcd.setCursor(5,0);
      lcd.write(5);
    }
    else
      break;
  }
}