/* Mining-safety prototype (super-sensitive for testing with incense smoke)
   - DHT11 on D2
   - MQ-2 A0, MQ-7 A1, MQ-135 A2
   - LEDs: green D8, yellow D9, red D10
   - Buzzer: D11
*/

#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// sensor pins
const int MQ2_PIN   = A0;
const int MQ7_PIN   = A1;
const int MQ135_PIN = A2;

// LEDs & buzzer
const int LED_GREEN  = 8;
const int LED_YELLOW = 9;
const int LED_RED    = 10;
const int BUZZER_PIN = 11;

// --- Super-Low Thresholds (very sensitive) ---
const int MQ2_WARN   = 60;
const int MQ2_DANGER = 120;

const int MQ7_WARN   = 60;
const int MQ7_DANGER = 120;

const int MQ135_WARN   = 50;
const int MQ135_DANGER = 110;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Mining-safety prototype (super-sensitive) starting...");
  delay(2000);
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  if (!isnan(hum) && !isnan(temp)) {
    Serial.print("Temp(C): "); Serial.print(temp,1);
    Serial.print("  Humidity(%): "); Serial.print(hum,1);
    Serial.println();
  }

  int mq2   = analogRead(MQ2_PIN);
  int mq7   = analogRead(MQ7_PIN);
  int mq135 = analogRead(MQ135_PIN);

  Serial.print("MQ-2: "); Serial.print(mq2);
  Serial.print("  MQ-7: "); Serial.print(mq7);
  Serial.print("  MQ-135: "); Serial.println(mq135);

  bool danger = (mq2 >= MQ2_DANGER) || (mq7 >= MQ7_DANGER) || (mq135 >= MQ135_DANGER);
  bool warning = !danger && ((mq2 >= MQ2_WARN) || (mq7 >= MQ7_WARN) || (mq135 >= MQ135_WARN));

  if (danger) {
    // Continuous blinking and buzzer
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    for (int i = 0; i < 6; i++) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(150);
      digitalWrite(LED_RED, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      delay(150);
    }
  }
  else if (warning) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
  else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  }

  Serial.println("---------------------------");
}
