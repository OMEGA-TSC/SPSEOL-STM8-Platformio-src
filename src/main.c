#include "stm8s.h"
#include "delay.h"
#include "millis.h"
#include "stdio.h"

#define LED_P GPIO_PIN_5
#define LED_PO GPIOC   

int main()
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
    SerialInit(9600);
    millis_init();
    GPIO_Init(LED_PO, LED_P, GPIO_MODE_OUT_PP_HIGH_FAST);
    while (1)
    {
        GPIO_WriteHigh(LED_PO, LED_P);
        delay_ms(1000);
        GPIO_WriteLow(LED_PO, LED_P);
        delay_ms(1000);
    }
}

/* Zde vkládejte Interrupt Vektory*/
/*
níže je znázorněna vzorová interrupt funkce,
kde N je číslo Interruptu který chcete použít
a NAZEV může být cokoliv doporučuji však zachovat originální stm8 názvy Interruptu pro lepší orientaci

INTERRUPT_HANDLER(NAZEV, N)
{
kod který má být vykonán v interruptu, 
(nastavení vlastních flagů, resetování flagu interruptu, atd...)
}

*/
/* Níže Interrupt Vektor potřebný pro funkci millis*/
extern uint32_t current_millis;
INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
{
    current_millis++;
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
}