#include<LiquidCrystal.h>
#include<EEPROM.h>
 int t = 12; // tank capacity 
 float a = 4.24 ;// votage at fuel indicator 0 level
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  // maximum voltage
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hare krishna");
 
}

void loop() {
  
  int s = analogRead(A0);// read the analog resistance value or value of fuel guage resistANCE
 
  float voltage = s * (5.0 / 1023.0); // convet resistance into voltage

  // put your main code here, to run repeatedly:
 
 float r = a - voltage; // calculting the change when tank is at initial to the petrol added in terms of voltage
 float petrol = (r/0.34);// for 12 litre  tank 1 litre= 0.34 and d is the value of petrol now in tank 

 
 lcd.setCursor(0,1);
 lcd.print(voltage);

 lcd.setCursor(5,1);
 lcd.print( petrol);
  
 //lcd.setCursor(11,1);
 //lcd.print(r);
}
