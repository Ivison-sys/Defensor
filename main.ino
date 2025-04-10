#include <Servo.h>
#define BUZZER 10
#define TRIG_PIN 2
#define ECHO_PIN 3
#define Rele 6

Servo ServoRota;
Servo Pistao;
int x = 5;

// Variáveis do servo
int angulo = 0; 
bool frente = true;

void angle(){
  delay(20);
  if(angulo == 0){
    frente = true;
  }
  else if(angulo == 180){
    frente = false;
  }

  if(frente){
    angulo = angulo+5;
  }
  else{
    angulo = angulo-5;
  }
} 


void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    ServoRota.attach(4);
    pinMode(Rele, OUTPUT);
    Pistao.attach(5);
    Pistao.write(70);
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // Conversão para cm
  if (distance <= 6.00 && distance > 1.00 ){
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("Entrei");
    digitalWrite(Rele, 1);
    delay(500);
    Pistao.write(0);
    delay(200);
    Pistao.write(70);
    delay(500);
  }
  else{
    angle();
    ServoRota.write(angulo);
    digitalWrite(Rele, 0);
    delay(100);
  }
}