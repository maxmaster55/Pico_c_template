#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

// led
#define VCC_PIN 15
#define DATA_PIN 26

// init pins data is analog input 
void init_pins(){
    gpio_init(VCC_PIN);
    gpio_init(DATA_PIN);
    gpio_set_dir(VCC_PIN, GPIO_OUT);
    gpio_set_dir(DATA_PIN, GPIO_IN);
    gpio_put(VCC_PIN, 1);

    adc_init();
    adc_gpio_init(DATA_PIN);
    adc_select_input(0);
}


int main(){
    stdio_init_all();
    init_pins();

    while(1){
        printf("data: %d\n", gpio_get(DATA_PIN));
        
        uint16_t result = adc_read();
        printf("adc: %d\n", result);

        sleep_ms(250);
    }
    return 0;
}
