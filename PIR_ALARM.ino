#include "pitches.h"

const uint8_t PIR_PIN = 2;
const uint8_t SAFE_PIN = 3;
const uint8_t ALARM_PIN = 4;
const uint8_t PIEZO_PIN = 5;

void setup() {
	pinMode(PIR_PIN, INPUT);
	pinMode(SAFE_PIN, OUTPUT);
	pinMode(ALARM_PIN, OUTPUT);
	pinMode(PIEZO_PIN, OUTPUT);

	delay(3000);

	digitalWrite(SAFE_PIN, HIGH);
}

void loop() {
	if (digitalRead(PIR_PIN)) {
		digitalWrite(SAFE_PIN, LOW);
		digitalWrite(ALARM_PIN, HIGH);

		while (true) {
			tone(PIEZO_PIN, NOTE_C5, 1000);
			delay(1000);
			noTone(PIEZO_PIN);
			delay(500);
		}
	}
}