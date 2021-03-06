/**
 * @file safecall.h
 * @author andersonarc (e.andersonarc@gmail.com)
 * @brief safe function calls with null/errno assertion
 * @version 0.2
 * @date 2020-09-30
 */
    /* header guard */
#ifndef CSAFE_SAFECALL_H
#define CSAFE_SAFECALL_H

    /* includes */
#include "csafe/assertd.h" /* debug assertions */
#include "csafe/assertr.h" /* runtime assertions */

    /* defines */
/**
 * @brief perform a safe call to function and set variable to the returned value (with debug assertions)
 * 
 * @param function calling function name
 * @param variable variable name
 * @param function_call function call expression
 */
#define scd(function, variable, function_call) \
    assertd_not_null_function_set(function, variable, function_call) \
    assertd_errno(function)

/**
 * @brief perform a safe call to a function (with debug assertions)
 * 
 * @param function calling function name
 * @param function_call function call expression
 */
#define scd_call(function, function_call) \
    assertd_not_null_function(function, function_call) \
    assertd_errno(function)

/**
 * @brief perform a safe call to function and set variable to the returned value (with runtime assertions)
 * 
 * @param function calling function name
 * @param variable variable name
 * @param function_call function call expression
 * @param status status to return on safe call failure
 */
#define scr(function, variable, function_call, status) \
    assertr_not_null_function_set(function, variable, function_call, status) \
    assertr_errno(function, status)

/**
 * @brief perform a safe call to a function (with runtime assertions)
 * 
 * @param function calling function name
 * @param function_call function call expression
 * @param status status to return on safe call failure
 */
#define scr_call(function, function_call, status) \
    assertr_not_null_function(function, function_call, status) \
    assertr_errno(function, status)

#endif /* CSAFE_SAFECALL_H */