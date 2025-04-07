const int pulsePin = A0;
int threshold = 520; // Adjust as needed
int bpm = 0;
int beats = 0;
unsigned long startTime;

void setup() {
  Serial.begin(9600);
  pinMode(pulsePin, INPUT);
  startTime = millis();
}

void loop() {
  int sensorValue = analogRead(pulsePin);

  if (sensorValue > threshold) {
    beats++;
    delay(200); // Debounce
  }

  if (millis() - startTime >= 10000) {
    bpm = beats * 6;
    Serial.print("BPM: ");
    Serial.println(bpm);
    beats = 0;
    startTime = millis();
  }
}
