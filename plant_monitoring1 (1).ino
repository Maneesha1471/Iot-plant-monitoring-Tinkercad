#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int temp=A1;
int moist=A0;
int humiditysensorOutput = 0;
int Relaypin=16;
int output;
int voltage;
float tempC;
float tempF;
void setup(){

  lcd.begin(16,2);
//Serial.begin(9600);
pinMode(A2, INPUT);
pinMode(16,OUTPUT);
}
void loop()
{
float moisture_percentage;

output=analogRead(A5);
voltage=output*(5/1024);
tempC=(voltage-0.5)*100;
tempF=(tempC*9/5)+32;
//Serial.print("Temperature in celsius");
//Serial.println(tempC);
//Serial.print("Temperature in Farenheat");
//Serial.println(tempF);
lcd.setCursor(0,0);
lcd.print("Temp in C:");
lcd.print(tempC);
lcd.setCursor(0,1);
lcd.print("Temp in F:");
lcd.print(tempF);
delay(3000);
  
humiditysensorOutput = analogRead(A1);
//Serial.print("Humidity: "); 
//Serial.print(map(humiditysensorOutput, 0, 1023, 10, 70));
//Serial.println("%");
lcd.setCursor(0,0);
lcd.print("Humidity:");
lcd.print(map(humiditysensorOutput, 0, 1023, 10, 70));
lcd.print("%");
  
moisture_percentage = ( 100.00 - ( (analogRead(moist)/1023.00) * 100.00 ) );
//Serial.print("Soil Moisture:");
//Serial.print(moisture_percentage);
//Serial.println("%");
lcd.setCursor(0,1);
lcd.print("Soil Moist:");
lcd.print(moisture_percentage);
lcd.print("%");
delay(3000);
  
if(moisture_percentage<=50)
{
lcd.setCursor(0,1);
digitalWrite(Relaypin,LOW);
lcd.print("Motor on");
}
else
{
lcd.setCursor(0,1);
digitalWrite(Relaypin,HIGH);
lcd.print("Motor off");
}
  
}