const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 1;
int prevSwitchState = 1;

int led = 2;
long interval = 1000;


void setup() {
  // put your setup code here, to run once:

  for(int x = 2; x<8; x++){
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  if(currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

  }
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState) {
    for (int x = 2; x<8; x++) {
      digitalWrite(x, LOW);
    }

    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
