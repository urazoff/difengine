#ifndef _DF_EVALUATE_H_
#define _DF_EVALUATE_H_

#include "object.h"
#include "frame.h"
#include "difengine.h"

/**
 * @file
 * Runtime architecture of Difengine
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Run frame's code
 *
 * @return
 *   Some DfObject location
 */
extern DfObject *df_eval_frame(DfFrameObj *frame);

#ifdef __cplusplus
}
#endif

#endif /* DF_EVALUATE_H_ */
