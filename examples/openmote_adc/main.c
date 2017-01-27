#include <stdio.h>
#include "xtimer.h"
#include "periph/adc.h"
#include "periph/gpio.h"

#define RES             ADC_RES_12BIT
#define DELAY           1000000UL

int main(void)
{
    //xtimer_ticks32_t delay;
    //delay.ticks32 = DELAY;

    adc_init(AD4_DIO4_PIN);
    
    //gpio_hardware_control(GPIO_PXX_TO_NUM(PORT_D, 2));
    //IOC_PXX_OVER[GPIO_PXX_TO_NUM(PORT_D, 2)] = IOC_OVERRIDE_OE;

    //gpio_init(GPIO_PD2, GPIO_OUT);
    gpio_init(GPIO_PD0, GPIO_OUT);
    gpio_init(GPIO_PD1, GPIO_OUT);
    gpio_init(GPIO_PD2, GPIO_OUT);
    gpio_init(GPIO_PD3, GPIO_OUT);

    gpio_set(GPIO_PD0);
    gpio_set(GPIO_PD1);
    gpio_set(GPIO_PD2);
    gpio_set(GPIO_PD3);

    while(1)
    {
        //int16_t sample = adc_sample(AD4_DIO4_PIN, RES);
                
        adc_start_sampling(AD4_DIO4_PIN, RES);
        
        //unsigned old_state = irq_disable();
        

        //gpio_set(GPIO_PD2);
        //xtimer_spin(delay);
        xtimer_usleep(1000000U);
        //gpio_clear(GPIO_PD2);

        if (adc_is_sample_ready(AD4_DIO4_PIN, RES) == 1) {
            uint16_t sample = adc_read_sample(AD4_DIO4_PIN, RES);
            printf("%d\n", sample);
        }
        else {
            printf("xxxxxxxx\n");
        }

        //irq_restore(old_state);
        //xtimer_usleep(1000000U);
    }

    return 0;
}