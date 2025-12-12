#ifndef MILLIS_H_
#define MILLIS_H_

#include "stm8s.h"

#define TIM4_PERIOD 24
//volatile uint32_t current_millis

void millis_init(void);

uint32_t millis(void);

#endif
