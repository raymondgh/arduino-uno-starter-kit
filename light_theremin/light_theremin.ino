int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }

    Serial.print("sensorLow: ");
    Serial.print(sensorLow);
    Serial.print(" sensorHigh: ");
    Serial.println(sensorHigh);
  }

  digitalWrite(ledPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorValue = analogRead(A0);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 2000);

  tone(8, pitch, 20);

  delay(10);

}
