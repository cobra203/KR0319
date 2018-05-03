#include <string.h>
#include <stm8s.h>
#include <stm8s_gpio.h>
#include <stm8s_debug.h>
#include <stm8s_common.h>
#include <stm8s_timer.h>
#include <button.h>
#include <real_button.h>
#include <wihd_button.h>

typedef enum button_id_e
{
    BTN_ID_PC3_PAIRING = 0,
    BTN_ID_BUTT,
} BUTTON_ID_E;

#define BUTTON_NUM  BTN_ID_BUTT

static BUTTON_S button[BUTTON_NUM];

int _button_process(struct button_s *button)
{
    static int              focused_times = 0;

    if(button->state.avtice) {
        button->state.avtice = 0;
        
        switch(button->type) {
        case BTN_ID_PC3_PAIRING:
            if(ECT_FOCUSED == button->state.effective) {
                focused_times++;
                if(290 == focused_times) {
                    focused_times = 0;
                    real_button_press();
                    delay_ms(10000);
                    real_button_loosen();
                }
            }
            else {
                focused_times = 0;
                real_button_loosen();
            }
            break;
        }
    }

    return 0;
}

void button_init(void)
{
    int i = 0;

    GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_IN_PU_NO_IT);
    
    for(i = 0; i < BTN_ID_BUTT; i++) {
        button[i].check_active      = button_check_active;
        button[i].process           = _button_process;
        button[i].type              = i;
        button[i].interval.shack    = 3;
        button[i].interval.pressed  = 10;
        button[i].interval.focused  = 100;
    }
}

void button_detect_input(void)
{
    uint8_t portc_value = 0;
    int     i = 0;
    
    portc_value = GPIO_ReadInputData(GPIOC);
    
    for(i = 0; i < BTN_ID_BUTT; i++) {
        button[i].state.press = (~portc_value >> 3) & 0x1;
    }
}

void button_updata_status(void)
{
    int i = 0;

    for(i = 0; i < BTN_ID_BUTT; i++) {
        button[i].check_active(&button[i]);
    }
}

void button_precess(void)
{
    int i = 0;

    for(i = 0; i < BTN_ID_BUTT; i++) {
        button[i].process(&button[i]);
    }
}
