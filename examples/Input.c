// This file is automatically generated.

#include <avr/io.h>
#include <stdbool.h>

struct list {
    uint8_t size;
    void* values;
};

static void input_pin12();

static void input_timer();

static void stream_1(uint8_t arg, void* value);

static void stream_2(uint8_t arg, void* value);

static void stream_3(uint8_t arg, void* value);

static void stream_4(uint8_t arg, void* value);

static void stream_5(uint8_t arg, void* value);

static void stream_6(uint8_t arg, void* value);

static void input_pin12() {
  bool temp0;
  temp0 = (PINB & (1 << PB4)) == 0U;
  stream_1(0, (void*)(&temp0));
}

static void input_timer() {
  uint16_t temp1;
  temp1 = TCNT1;
  TCNT1 = 0;
  stream_2(0, (void*)(&temp1));
}

static void stream_1(uint8_t arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB5);
  } else {
    PORTB &= ~(1 << PB5);
  }
}

static void stream_2(uint8_t arg, void* value) {
  bool temp2;
  uint16_t temp3;
  uint16_t temp4;
  uint16_t temp5;
  uint16_t temp6;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  static uint16_t fold_state = 0;
  temp2 = fold_state > 10000;
  temp3 = fold_state - 10000;
  temp4 = temp3 + input_0;
  temp5 = fold_state + input_0;
  if (temp2) {
    temp6 = temp4;
  } else {
    temp6 = temp5;
  }
  fold_state = temp6;
  stream_3(0, (void*)(&fold_state));
}

static void stream_3(uint8_t arg, void* value) {
  bool temp7;
  bool temp8;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  temp7 = input_0 > 10000;
  temp8 = false;
  if (temp7) {
    temp8 = true;
  }
  if (temp8) {
    stream_4(0, (void*)(&input_0));
  }
}

static void stream_4(uint8_t arg, void* value) {
  uint16_t temp9;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  static uint16_t fold_state = 0;
  temp9 = fold_state + 1;
  fold_state = temp9;
  stream_5(0, (void*)(&fold_state));
}

static void stream_5(uint8_t arg, void* value) {
  bool temp10;
  static uint16_t input_0;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
  }
  temp10 = (input_0) % 2 == 0;
  stream_6(0, (void*)(&temp10));
}

static void stream_6(uint8_t arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB3);
  } else {
    PORTB &= ~(1 << PB3);
  }
}

int main(void) {
  DDRB &= ~(1 << PB4);
  PORTB |= (1 << PB4);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  DDRB |= (1 << PB5);
  DDRB |= (1 << PB3);
  while (1) {
    input_pin12();
    input_timer();
  }
  return 0;
}
