int switchState = 0;
int intensity = 0;
int timeNow = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

if(intensity == 0) {
    
    digitalWrite(3, HIGH); // green led
    digitalWrite(4, LOW); // red led
    digitalWrite(5, LOW); // red led
    
} else if (intensity == 1) {

  timeNow = millis();

if (timeNow + 500 < millis()) {
  
    digitalWrite(3, LOW); // green led
    digitalWrite(4, LOW); // red led
    digitalWrite(5, HIGH); // red led
} else {
  timeNow = millis();
  
  if (timeNow + 500 < millis()) {
  
    digitalWrite(4, HIGH); // red led
    digitalWrite(5, LOW); // red led
}
}


    delay(500);
    // toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(500);
} else if (intensity == 2) {
    
    digitalWrite(3, LOW); // green led
    digitalWrite(4, LOW); // red led
    digitalWrite(5, HIGH); // red led

    delay(250);
    // toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
} else if (intensity == 3) {
    
    digitalWrite(3, LOW); // green led
    digitalWrite(4, LOW); // red led
    digitalWrite(5, HIGH); // red led

    delay(100);
    // toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(100);
}

if(switchState == HIGH) {
  // button pressed
  if (intensity == 3) {
    intensity = 0;
  } else {
    intensity += 1;
    delay(150);
  }
}
}
