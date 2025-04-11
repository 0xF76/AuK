#include "delay.h"

static volatile uint64_t ticks;

void msDelay(uint64_t ms) {
	uint64_t tickstart = ticks;

	while((ticks - tickstart) < ms) {

	}
}

uint64_t msGetTicks(void) {
	return ticks;
}

/** SysTick Interrupt Handler */
void SysTick_Handler(void) {
    ticks++;
}

