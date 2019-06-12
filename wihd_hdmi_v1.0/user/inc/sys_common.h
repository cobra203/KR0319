#ifndef _SYS_COMMON_H_
#define _SYS_COMMON_H_

#ifdef __cplusplus
 extern "C" {
#endif

#define     BIT_ISSET(a, s) (((a) >> (s)) & 0x1)
#define     BIT_SET(a, s)   ((a) = (a) | 0x1 << (s))
#define     BIT_CLR(a, s)   ((a) = (a) & ~(0x1 << (s)))

#define     STM_SUCCESS     0
#define     STM_FAILURE     -1

#define     STM_TRUE        1
#define     STM_FALSE       0

#define     STM_ENABLE      STM_TRUE
#define     STM_DISABLE     STM_FALSE

#define		STM_NULL		((void *)0)
#define		STM_BOOL		uint8_t

#ifdef __cplusplus
}
#endif

#endif /* _SYS_COMMON_H_ */

