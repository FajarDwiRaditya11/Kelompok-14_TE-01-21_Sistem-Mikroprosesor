#include <LiquidCrystal_I2C.h>
#include <UltraDistSensor.h>
#include <Wire.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

const int trigPin = 8;
const int echoPin = 9;

const int serPin = 10;
const int sensorOut = 3;
int sensorvalue = HIGH;
long duration, distance;
int distanceCm;
float Liquid;

void setup() {
lcd.begin(16, 2);
Serial.begin (9600);//put your setup code here, to run once:
pinMode (trigPin, OUTPUT);
pinMode (echoPin, INPUT);
pinMode (serPin, OUTPUT);
pinMode (sensorOut, INPUT_PULLUP);
lcd.setCursor (0, 1);

lcd.clear();
}
void loop() {
long duration, distanceCm;
digitalWrite (trigPin, LOW); //put your main code here, to run repeatedly:
delayMicroseconds (2);
digitalWrite (trigPin, HIGH);
delayMicroseconds (10);
digitalWrite (trigPin, LOW);
duration = pulseIn (echoPin, HIGH);
distanceCm = duration * 0.034 / 2;
lcd.setCursor (1, 0);
lcd.print("SELAMAT DATANG");

delay (100);

if (distanceCm<5)
{
delay(450);
lcd.setCursor (4, 0);
lcd.print("SILAKAN");
lcd.setCursor (1, 1);
lcd.print("MASUKKAN SAMPAH");
delay(5000);
lcd.clear ();
delay(500);
lcd.clear ();
delay (450);
lcd.setCursor (2, 1);
lcd.print("TERIMA KASIH");
delay (3000);

int sensorvalue = digitalRead(sensorOut); //start program sensor proximity
if (sensorvalue == LOW)
{
Serial.println("Object detected");
servo.write(180);//posisi servo pada 90 derajat

{
lcd.setCursor (0, 1);
lcd.print("SAMPAH LOGAM");
delay(5000); //Delay
lcd.clear ();}
servo.write(90);
delay(450);
}

else{

Serial.println("No object");
servo.write(0); //Posisi servo pada 0 derajat
lcd.setCursor (0, 1);
lcd.print("SAMPAH NON LOGAM");
delay(5000);
lcd.clear ();
servo.write(90);
delay(450);

}
lcd.clear();
}
}
