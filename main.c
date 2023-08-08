#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int motorPin[] = {18,19,20,21};

int rolePerMinute = 4;
int stepsPerRevolution = 2048;
int stepSpeed = 0;

int main() {
	
	stdio_init_all();
	
	for(uint i = 0; i < 4; i++) {
		gpio_init(motorPin[i]);
		gpio_set_dir(motorPin[i], GPIO_OUT);
	}
	
	stepSpeed = (60000000 / rolePerMinute) / stepsPerRevolution;
	
	while(1) {
		
		for(int j = 0; j < 4; j++) {
			for(int i = 0; i < 4; i++) {
				//anti-clockwise
				//gpio_put(motorPin[i],0x99 >> j & (0x08>>i));
				//clockwise
				gpio_put(motorPin[i],0x99 << j & (0x08>>i));
				printf("Step Speed : %d\n", stepSpeed);
			}
			sleep_us(stepSpeed);
		}
		
	}
	
}

