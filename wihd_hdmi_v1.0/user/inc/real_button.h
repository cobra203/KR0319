#ifndef _REAL_BUTTON_H_
#define _REAL_BUTTON_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stm8s_led.h>

void real_button_init(void);
void real_button_loosen(void);
void real_button_press(void);

#ifdef __cplusplus
}
#endif

#endif /* _REAL_BUTTON_H_ */

