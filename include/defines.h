#ifndef _DF_DEFINES_H_
#define _DF_DEFINES_H_

/**
 * @file
 * Common macro defines
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Avoid compiler warning on unused variables.
 */
#define UNUSED(_x) (void)(_x)

/*
 * Get absolute value.
 */
#define DF_ABS(_x) ((_x >= 0) ? _x : -_x)

/*
 * signum(x).
 */
#define DF_SGN(_x) ((_x > 0) ? 1 : (_x == 0) ? 0 : -1)

#ifdef __cplusplus
}
#endif

#endif /* DF_DEFINES_H_ */
