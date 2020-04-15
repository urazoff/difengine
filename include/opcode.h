#ifndef _DF_OPCODE_H_
#define _DF_OPCODE_H_

/**
 * @file
 * Operation's codes
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    RETURN_VALUE,
    UNARY_NEG,
    BIN_ADD,
    BIN_SUBTRACT,
    BIN_MULTIPLY,
    BIN_DIVIDE,
    HAS_ARG,
    LOAD_CONST
} Op_Codes;

#define HAS_ARG(_opcode) (_opcode >= HAS_ARG)

#ifdef __cplusplus
}
#endif

#endif /* DF_OPCODE_H_ */
