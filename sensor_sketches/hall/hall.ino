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

// declare pin constants
#define HALL_PIN 12
#define LED_PIN 13

int hallState = 0;
int lastTime = 0;   // last time magnetic field was sensed
int totalTime = 0;  // total time during this run
int timeChecks = 0; // how many times magnetic field has been detected this run
int timeDiff = 0;   // time (in miliseconds) since last detection
int rpm = 0;

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

void calcTime()
{
  timeDiff = millis() - lastTime;
  lastTime = millis();

  // Serial.println(timeDiff);

  if (timeDiff < 2000)
  {
    totalTime += timeDiff;
    timeChecks++;
  }
  else
  {
    totalTime = 0;
    timeChecks = 0;
  }
}

void checkRunning() {
  int raw = digitalRead(HALL_PIN);

  // Serial.println(raw);

  if (raw != hallState)
  {
    hallState = raw;

    calcTime();

    flash();
  }
}

void loop(){
  // try to detect change in magnetic field
  checkRunning();

}
