#define BUZZER1 3
#define BUZZER2 2
#define TRIG_PIN 9
#define ECHO_PIN 10

int controlar_tempo(int distancia){
  if(distancia <= 12 && distancia > 10){
    return 1000;
  }
  if(distancia <= 10 && distancia > 8){
    return 800;
  }
  if(distancia <= 8 && distancia > 6){
    return 500;
  }
  else{
    return 200;
  }
}


void setup() {
    Serial.begin(9600);
    pinMode(BUZZER1, OUTPUT);
    pinMode(BUZZER2, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    bool isDelay = true;
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = duration * 0.034 / 2; // Conversão para cm
    if (distance <= 12.00 && distance >= 2.00){
      Serial.println("Entrei");
      int t = controlar_tempo(distance);
      tone(BUZZER1, 300);
      digitalWrite(BUZZER2, 1);
      delay(t);
      digitalWrite(BUZZER2, LOW);
      noTone(BUZZER1);
      isDelay = false;
    }
   
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");
    if(isDelay){
      delay(350);
    }
    isDelay = true;
}