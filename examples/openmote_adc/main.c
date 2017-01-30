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
        int16_t sample = adc_sample(AD4_DIO4_PIN, RES);
        //gpio_set(LED0_PIN);

        //unsigned old_state = irq_disable();

        //adc_start_sampling(AD4_DIO4_PIN, RES);
        
        //gpio_clear(GPIO_PIN(PORT_D,2));
        //xtimer_spin(delay);
        //xtimer_usleep(1000000U);
        //gpio_set(GPIO_PIN(PORT_D,2));
        
        //if (adc_is_sample_ready(AD4_DIO4_PIN, RES) == 1) {
            //uint16_t sample = adc_read_sample(AD4_DIO4_PIN, RES);
            printf("ADC = %d\n", sample);
            //printf("%d\n", adc_sample(AD4_DIO4_PIN, RES));
        //}
        //else {
            //printf("xxxxxxxx\n");
        //}

        //irq_restore(old_state);

        xtimer_usleep(1000000U);
        //gpio_clear(LED0_PIN);
    }

    return 0;
}
