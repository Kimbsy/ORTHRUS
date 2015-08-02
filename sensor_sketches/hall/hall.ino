/**
 * Sketch to measure rotation of hamster wheel with magnets attached.
 *
 * Using hall sensor (U18).
 *
 * Pins when looking at model number on sensor:
 *   left   : Vin
 *   middle : ground
 *   right  : output
 */

#define HALL_PIN 12
#define LED_PIN 13

int hallState = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(HALL_PIN, INPUT);

  Serial.begin(9600);
}

void flash()
{
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
}

void sense() {
  int raw = digitalRead(HALL_PIN);

  // Serial.println(raw);

  if (raw != hallState)
  {
    hallState = raw;
    flash();
  }
}

void loop(){
  sense();
}
