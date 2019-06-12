#include <power_sw.h>
#include <host_pin_def.h>
#include <sys_common.h>
#include <stm8s_gpio.h>

typedef struct
{
	uint8_t power		:1;
	uint8_t				:7;
} POWER_SW_STATUS_S;

typedef struct power_sw_s
{
	POWER_SW_STATUS_S	status;
} POWER_SW_S;

POWER_SW_S power_sw;

/*====================================================================================================
heat functions
=====================================================================================================*/

void power_sw_switch(void)
{
	power_sw.status.power = power_sw.status.power ? STM_FALSE : STM_TRUE;
	POWER_SW_OUT = power_sw.status.power ? STM_TRUE : STM_FALSE;
}

void power_sw_init(void)
{
	GPIO_Init(POWER_SW_GPIO, POWER_SW_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
	power_sw.status.power = STM_FALSE;
	POWER_SW_OUT = power_sw.status.power ? STM_TRUE : STM_FALSE;
}

