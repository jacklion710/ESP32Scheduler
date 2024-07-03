# ESP32 Scheduler

1 MHz clock for executing tasks in a scheduled order. 1 ms, 10 ms, 100 ms, and 1000 ms routines are defined in which an LED is made to blink on and off at a rate according to the routine it is called under.

# Why?

To have a basic template as a starting point for more advanced systems projects in the future.

# Usage

The functions below expose control over the timing of programmatic events to occur in a specific user defined order. Tasks placed in the 1 ms block will be called every millisecond and tasks in the 10 ms block will be called every 10th millisecond and so on. 

```cpp
void task1ms() {
  // Code for 1 ms task
}

void task10ms() {
  // Code for 10 ms task
}

void task100ms() {
  // Code for 100 ms task
}

void task1000ms() {
  // Code for 1000 ms task
}
```


