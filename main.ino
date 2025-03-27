#include <Stepper.h>
#define BUZZER 10
#define TRIG_PIN 12
#define ECHO_PIN 13
#define STEPS 2048  // Passos por revolução do 28BYJ-48

Stepper motor(STEPS, 2, 3, 4, 5);  // Pinos do driver no Arduino

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    motor.setSpeed(10);  // Velocidade em RPM
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
      Serial.println("Entrei");
      tone(BUZZER, 7000);
    }
    else{
      noTone(BUZZER);
      motor.step(10);  
    }

    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");
}