#include "main.h"

int main ()
{
    // Enable GPIOB peripheral
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // Setup pin B3 for output and push-pull
    GPIOA->MODER &= ~GPIO_MODER_MODER15;
    GPIOA->MODER |= GPIO_MODER_MODER15_0;
    GPIOA->OTYPER &= ~GPIO_OTYPER_OT_15;

    int counter = 0;
    while (1)
    {
        // Turn on the LED
        GPIOA->BSRR = (1 << 15);
        delay(counter);

        // Turn off the LED
        GPIOA->BRR = (1 << 15);
        delay(counter);

        counter += 10000;
    }
}

void delay(int count) {
    for (int i = 0; i < count; i++) {
        // sleep
    }
}
