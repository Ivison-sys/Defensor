#define BUZZER 3
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = duration * 0.034 / 2; // Conversão para cm
    if (distance <= 6.00 && distance > 1.00){
      Serial.println("Entrei");
      tone(BUZZER, 7000);
    }
    else{
      noTone(BUZZER);
    }

    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(800);
}