#include <LiquidCrystal_I2C.h>
#include <UltraDistSensor.h>
#include <Wire.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo myservo;

const int trigPin = A0;
const int echoPin = A1;
const int sensorOut = 3;

int sensorvalue = HIGH;
long duration, distance;
int distanceCm;
float Liquid;
int logam = 72;
int nonlogam = 0;
int awal = 36;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight ();
  Serial.begin (9600);//put your setup code here, to run once:
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (sensorOut, INPUT_PULLUP);
  lcd.setCursor (0, 1);
  myservo.attach (10);
  myservo.write(awal);
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
  lcd.clear();

if (distanceCm<5){
  lcd.setCursor (4, 0);
  lcd.print("SILAKAN");
  lcd.setCursor (1, 1);
  lcd.print("MASUKKAN SAMPAH");
  delay(3500);
  lcd.clear ();
  delay (450);

sensorvalue = digitalRead(sensorOut); //start program sensor proximity

if (sensorvalue == LOW) {
  Serial.println("Object detected");
  myservo.write(logam);//posisi servo pada 90 derajat
  lcd.setCursor (2, 1);
  lcd.print("SAMPAH LOGAM");
  delay(3000); //Delay
  lcd.clear ();
  myservo.write(awal);
  delay(250);
  lcd.setCursor (2, 1);
  lcd.print("TERIMA KASIH");
  delay (2000);
  lcd.clear();
}else{
  Serial.println("No object");
  myservo.write(nonlogam); //Posisi servo pada 0 derajat
  lcd.setCursor (0, 1);
  lcd.print("SAMPAH NON LOGAM");
  delay(3000);
  lcd.clear ();
  myservo.write(awal);
  delay(250);
  lcd.setCursor (2, 1);
  lcd.print("TERIMA KASIH");
  delay (2000);
}
lcd.clear();
}
}