/**
  Christmas Ornamant 2024 firmware for ATtiny13.

  Three banks of LEDs, Yellow, White, and Blue.
  The Yellow bank is always on, while the white and blue are
  twinkling with seperate randomness.

  Written by Danni Randeris, 2024
 */


/* ----------------- Hardware-specific config ---------------------- */
#define LED_BANK_1 3  // I/O-pin connected to white LED bank
#define LED_BANK_2 0  // I/O-pin connected to purple LED bank
#define LED_BANK_3 1  // I/O-pin connected to yellow LED bank


/* ----------------- Program --------------------------------------- */
void setup() {
  // Set PIN modes
  pinMode(LED_BANK_1, OUTPUT);
  pinMode(LED_BANK_2, OUTPUT);
  pinMode(LED_BANK_3, OUTPUT);
  pinMode(4, INPUT_PULLUP);  // NC, pulled HIGH

  // Power Yellow LED bank on
  digitalWrite(LED_BANK_1, HIGH);
}

void loop() {
  // Use PWM to light the the LED banks with a fenced random
  // intensity and then hold that for a fenced random amount of time.
  analogWrite(LED_BANK_2, random(75, 250));
  analogWrite(LED_BANK_3, random(75, 250));
  delay(random(400));
}
