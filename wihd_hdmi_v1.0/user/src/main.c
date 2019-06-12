/**
  ******************************************************************************
  * @file    Project/main.c 
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   Main program body
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include <stm8s_timer.h>
#include <stm8s_led.h>
#include <stm8s_debug.h>
#include <real_button.h>
#include <wihd_button.h>
#include <power_sw.h>


/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

static void clk_init(void)
{
	CLK_DeInit();
    CLK_HSICmd(ENABLE);
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);
	CLK_ClockSecuritySystemEnable();//启用系统时钟安全，启用就无法关闭，直到复位   
}

void main(void)
{
    //while(1);
	disableInterrupts();
    /* init */
    clk_init();
    timer_init();
    real_button_init();
    button_init();
	power_sw_init();

	enableInterrupts();

    /* Infinite loop */
    while (1)
    {
        button_detect_input();
        button_updata_status();
        button_precess();
        delay_ms(10);
    }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number  */
    DEBUG("Wrong parameters value: file %s on line %d\n", file, (int)line);

  /* Infinite loop */
    while (1)
    {
    }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
