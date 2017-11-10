#include <real_button.h>

static STM8S_LED_S real_btn;

void real_button_init(void)
{
    stm8s_led_init(&real_btn);
    real_button_loosen();
}

void real_button_loosen(void)
{
    real_btn.set(&real_btn, 1, 0);
    real_btn.doing(&real_btn);
}

void real_button_press(void)
{
    real_btn.set(&real_btn, 0, 1);
    real_btn.doing(&real_btn);
}

