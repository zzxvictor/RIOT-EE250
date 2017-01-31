#include <stdio.h>
#include "xtimer.h"
#include "periph/adc.h"
#include "periph/gpio.h"

#define RES             ADC_RES_7BIT
#define DELAY           1000000U

int main(void)
{
  // Initialize the ADC for DA4
  adc_init(AD4_DIO4_PIN);
  
  // Initialize PIN PD2 to measure the duration of conversion
  gpio_init(GPIO_PIN(PORT_D,2), GPIO_OUT);
  gpio_clear(GPIO_PIN(PORT_D,2));

  while(1)
  {
    int16_t sample = adc_sample(AD4_DIO4_PIN, RES);
    printf("ADC = @%d@\n", sample);

    xtimer_usleep(DELAY);
    gpio_toggle(LED0_PIN);
  }

  return 0;
}
