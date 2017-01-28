#include <stdio.h>
#include "xtimer.h"
#include "periph/adc.h"
#include "periph/gpio.h"

int main(void)
{
    uint32_t last = xtimer_now();
    int16_t sample = 0;

    adc_init(AD4_PIN);

    while(1)
    {
        sample = adc_sample(AD4_PIN, RES);

        if (sample < 0) 
        {
            printf("ADC error\n");
        } 
        else 
        {
            printf("ADC output %d\n", sample);
        }

        xtimer_usleep_until(&last, DELAY);
        gpio_clear(LED0_PIN);
    }

    return 0;
}