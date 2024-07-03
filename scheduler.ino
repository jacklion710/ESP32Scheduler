#include <Arduino.h>

const byte YELLOW_LED = 14;
const byte YELLOW2_LED = 13;
const byte RED_LED = 12;
hw_timer_t *timer = NULL;
volatile bool toggleYellowLED = false;
volatile bool toggleYellow2LED = false;
volatile bool toggleRedLED = false;

// Counters for each scheduling interval
volatile unsigned long counter_1ms = 0;
volatile unsigned long counter_10ms = 0;
volatile unsigned long counter_100ms = 0;
volatile unsigned long counter_1000ms = 0;

void ARDUINO_ISR_ATTR onTimer() {
  counter_1ms++;

  // 1 ms task
  if (counter_1ms >= 1) {
    counter_1ms = 0;
    task1ms();
  }

  // 10 ms task
  counter_10ms++;
  if (counter_10ms >= 10) {
    counter_10ms = 0;
    task10ms();
  }

  // 100 ms task
  counter_100ms++;
  if (counter_100ms >= 100) {
    counter_100ms = 0;
    task100ms();
  }

  // 1000 ms (1 second) task
  counter_1000ms++;
  if (counter_1000ms >= 1000) {
    counter_1000ms = 0;
    task1000ms();
  }
}

void task1ms() {
  // Code for 1 ms task
}

void task10ms() {
  // Code for 10 ms task
  toggleYellowLED = !toggleYellowLED;
  digitalWrite(YELLOW_LED, toggleYellowLED);
}

void task100ms() {
  // Code for 100 ms task
  toggleYellow2LED = !toggleYellow2LED;
  digitalWrite(YELLOW2_LED, toggleYellow2LED);
}

void task1000ms() {
  // Code for 1000 ms task
  // Toggle LED as an example task for 1 second interval
  toggleRedLED = !toggleRedLED;
  digitalWrite(RED_LED, toggleRedLED);
}

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);

  pinMode(YELLOW_LED, OUTPUT);
  digitalWrite(YELLOW_LED, LOW);

  pinMode(YELLOW2_LED, OUTPUT);
  digitalWrite(YELLOW2_LED, LOW);

  // Set timer frequency to 1 MHz (1 us per tick)
  timer = timerBegin(1000000); // Timer 0, prescaler 80 -> 1 MHz

  // Attach onTimer function to our timer
  timerAttachInterrupt(timer, &onTimer);

  // Set alarm to call onTimer function every 1 ms (1000 us)
  timerAlarm(timer, 1000, true, 0);
}

void loop() {
  // Main loop can remain empty or perform other tasks
}
