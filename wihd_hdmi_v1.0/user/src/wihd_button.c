#include <string.h>
#include <stm8s.h>
#include <stm8s_gpio.h>
#include <stm8s_debug.h>
#include <stm8s_common.h>
#include <stm8s_timer.h>
#include <button.h>
#include <real_button.h>
#include <wihd_button.h>
#include <power_sw.h>
#include <host_pin_def.h>
#include <sys_common.h>

typedef enum button_id_e
{
    BTN_ID_PC3_PAIRING = 0,
    BTN_ID_BUTT,
} BUTTON_ID_E;

#define BUTTON_NUM  BTN_ID_BUTT

static BUTTON_S button[BUTTON_NUM];

int _button_process(struct button_s *button)
{
    static int focused_times = 0;
	static int last_status;

    if(button->state.avtice) {
        button->state.avtice = 0;
        
        switch(button->type) {
        case BTN_ID_PC3_PAIRING:
			switch(button->state.effective) {
			case ECT_LOOSE:
				if(last_status == ECT_PRESSED) {
					power_sw_switch();
				}
			case ECT_PRESSED:
				focused_times = 0;
                real_button_loosen();
				break;
			case ECT_FOCUSED:
				focused_times++;
				if(140 == focused_times) {
					focused_times = 0;
					real_button_press();
                    delay_ms(10000);
                    real_button_loosen();
				}
				break;
			}
			last_status = button->state.effective;
			break;
        }
    }

    return 0;
}

void button_init(void)
{
    int i = 0;

    GPIO_Init(WIHD_BUTTON_GPIO, WIHD_BUTTON_PIN, GPIO_MODE_IN_PU_NO_IT);
    
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
    int     i = 0;
    uint8_t key = 0;

	key = WIHD_BUTTON_IN;
    
    for(i = 0; i < BTN_ID_BUTT; i++) {
        button[i].state.press = key ? STM_FALSE : STM_TRUE;
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
