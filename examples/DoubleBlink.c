// This file is automatically generated.

#include <avr/io.h>
#include <util/delay_basic.h>
#include <stdbool.h>

struct list {
    uint8_t size;
    void* values;
};

struct tuple2 {
    void* value0;
    void* value1;
};

struct tuple6 {
    void* value0;
    void* value1;
    void* value2;
    void* value3;
    void* value4;
    void* value5;
};

static void input_timer();

static void stream_1(uint8_t arg, void* value);

static void stream_2(uint8_t arg, void* value);

static void stream_3(uint8_t arg, void* value);

static void stream_4(uint8_t arg, void* value);

static void stream_5(uint8_t arg, void* value);

static void stream_7(uint8_t arg, void* value);

static void stream_6(uint8_t arg, void* value);

static void stream_8(uint8_t arg, void* value);

static void input_timer() {
  uint16_t temp0;
  temp0 = TCNT1;
  TCNT1 = 0;
  stream_1(0, (void*)(&temp0));
}

static void stream_1(uint8_t arg, void* value) {
  uint16_t input_0 = *((uint16_t*)value);
  static uint16_t input_1 = 0;
  uint16_t temp1;
  if ((input_1 > 5000)) {
    temp1 = ((input_1 - 5000) + input_0);
  } else {
    temp1 = (input_1 + input_0);
  }
  input_1 = temp1;
  stream_2(0, (void*)(&input_1));
}

static void stream_2(uint8_t arg, void* value) {
  uint16_t input_0 = *((uint16_t*)value);
  if ((input_0 > 5000)) {
    stream_3(0, (void*)(&input_0));
  }
}

static void stream_3(uint8_t arg, void* value) {
  uint16_t input_0 = *((uint16_t*)value);
  static uint16_t input_1 = 0;
  input_1 = (input_1 + 1);
  stream_4(0, (void*)(&input_1));
}

static void stream_4(uint8_t arg, void* value) {
  uint16_t input_0 = *((uint16_t*)value);
  static bool temp2 = false;
  static bool temp3 = true;
  static struct tuple2 input_1 = { .value0 = (void*)&temp2, .value1 = (void*)&temp3 };
  bool temp4;
  bool temp5;
  struct tuple2 temp6;
  temp4 = *((bool*)input_1.value1);
  temp5 = *((bool*)input_1.value0);
  temp6.value0 = (void*)&temp4;
  temp6.value1 = (void*)&temp5;
  *((bool*)input_1.value0) = *((bool*)temp6.value0);
  *((bool*)input_1.value1) = *((bool*)temp6.value1);
  stream_5(0, (void*)(&input_1));
  stream_7(0, (void*)(&input_1));
}

static void stream_5(uint8_t arg, void* value) {
  struct tuple2 input_0 = *((struct tuple2*)value);
  stream_6(0, (void*)(&*((bool*)input_0.value0)));
}

static void stream_7(uint8_t arg, void* value) {
  struct tuple2 input_0 = *((struct tuple2*)value);
  stream_8(0, (void*)(&*((bool*)input_0.value1)));
}

static void stream_6(uint8_t arg, void* value) {
  bool input_0 = *((bool*)value);
  if (input_0) {
    PORTB |= (1 << PB4);
  } else {
    PORTB &= ~(1 << PB4);
  }
}

static void stream_8(uint8_t arg, void* value) {
  bool input_0 = *((bool*)value);
  if (input_0) {
    PORTB |= (1 << PB5);
  } else {
    PORTB &= ~(1 << PB5);
  }
}

int main(void) {
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  DDRB |= (1 << PB4);
  DDRB |= (1 << PB5);
  while (1) {
    input_timer();
  }
  return 0;
}
