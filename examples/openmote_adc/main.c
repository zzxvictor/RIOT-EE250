#include <stdio.h>
#include "xtimer.h"
#include "periph/adc.h"
#include "periph/gpio.h"

#define RES             ADC_RES_12BIT
#define DELAY           1000000U

int main(void)
{

    adc_init(AD4_DIO4_PIN);
    gpio_init(GPIO_PIN(PORT_D,2), GPIO_OUT);

    adc_init(AD4_PIN);

    while(1)
    {
        int16_t sample = adc_sample(AD4_DIO4_PIN, RES);
        printf("ADC = @%d@\n", sample);

        xtimer_usleep(DELAY);
        gpio_toggle(LED0_PIN);
    }

    return 0;
}
