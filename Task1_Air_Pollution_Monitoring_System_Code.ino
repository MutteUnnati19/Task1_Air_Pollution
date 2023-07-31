#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pin8 = 8;
int analogPin = A0;    
int sensorValue = 0;     

void setup() {
  pinMode(analogPin, INPUT);
  pinMode(pin8, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Air Quality");
  Serial.begin(9600);
  lcd.display();
 
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  
  delay(1000);
  sensorValue = analogRead(analogPin);     
  Serial.print("Air Quality in PPM = ");
  Serial.println(sensorValue);          
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("Air Quality: ");
  lcd.print (sensorValue);
  
  if (sensorValue<=375)
   {
   Serial.print("Good Air ");
   Serial.print ("\r\n");
   lcd.setCursor(0,1);
   lcd.print("Good Air");
   digitalWrite(7, LOW); 
   digitalWrite(6, LOW); 
   digitalWrite(9, HIGH); 
   }
  else if( sensorValue>=375 && sensorValue<=500 )
   {
   Serial.print("Moderate Air");
   Serial.print ("\r\n");
   lcd.setCursor(0,1);
   lcd.print("Moderate Air");
   digitalWrite(9, LOW);
   digitalWrite(7, HIGH); 
   digitalWrite(6, LOW); 
   }
  else if (sensorValue>=500 )
   {
   Serial.print("Polluted");
   Serial.print ("\r\n");
   lcd.setCursor(0,1);
   lcd.print("Polluted");
    digitalWrite(7, LOW); 
    digitalWrite(6, HIGH); 
    digitalWrite(9, LOW); 
   }
  
  if (sensorValue >650) {
    digitalWrite(pin8, HIGH);
  }
  else {
    digitalWrite(pin8, LOW);
  }
}
 