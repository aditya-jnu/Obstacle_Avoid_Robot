#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

long cm, duration;
const int echoPin = 7;
const int trigPin = 6;

const int lm1 = 2;
const int lm2 = 3;
const int rm1 = 4;
const int rm2 = 5;

void setup(){
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.begin(16, 2);
  lcd.print("Hello, World!");
}
void loop(){
  
  //the distance ahead using an ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  // motion controls...
  cm = duration*0.034/2;
  if(cm<20){
    stop_bot();
    delay(2000);
    
    go_back();
    delay(2000);
    
    stop_again();
    delay(1000);
    
    go_left();
    delay(1000);
  }
  else{
    go_straight();
    delay(1000);
  }
  
  // PRINITNG ON LCD....
  Serial.print("Distance in CM: ");
  Serial.print(cm);
}
  
  // different motion functions used
  void go_straight(){
    lcd.setCursor(0,0);
    lcd.print("Nothing Ahead");
    lcd.setCursor(0,1);
    lcd.print("Moving Forward");
    // forward
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
  }
  
  void go_back(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Taking Reverse");
    lcd.setCursor(0,1);
    lcd.print(cm);
    // backward
    digitalWrite(lm2, HIGH);
    digitalWrite(lm1, LOW);
    digitalWrite(rm2, HIGH);
    digitalWrite(rm1, LOW);
  }
  
  void stop_bot(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Something Ahead");
    lcd.setCursor(0,1);
    lcd.print("Stop!!");
    //stop
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm2, LOW);
    digitalWrite(rm1, LOW);
  }
  
  void stop_again(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Break for turn");
    //stop
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm2, LOW);
    digitalWrite(rm1, LOW);
  }
  
  void go_left(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Turning Left");
    lcd.setCursor(0,1);
    lcd.print(cm);
    // left turn
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
  }
  
  void go_right(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Turning Right");
    lcd.setCursor(0,1);
    lcd.print(cm);
    // right turn
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
  }
 

