/**
 * @file logf.h
 * @author andersonarc (e.andersonarc@gmail.com)
 * @brief csafe formatted logging
 * @version 0.2
 * @date 2021-02-07
 */
    /* header guard */
#ifndef CSAFE_LOGF_H
#define CSAFE_LOGF_H

    /* defines */
/**
 * @brief formatted message with custom suffix and prefix
 */
#define log_sp_f(message, function, suffix, prefix, ...) _csafe_logf_message(prefix "[" suffix "] " function ": " message, __VA_ARGS__)
/**
 * @brief formatted message with custom suffix
 */
#define log_s_f(message, function, suffix, ...) log_sp(message, function, suffix, prefix, __VA_ARGS__)


/**
 * @brief formatted error with custom suffix and prefix
 */
#define loge_sp_f(message, function, suffix, prefix, ...) _csafe_logf_error(prefix "[" suffix "] " function ": " message, __VA_ARGS__)
/**
 * @brief formatted error message with custom suffix
 */
#define loge_s_f(message, function, suffix, ...) loge_sp(message, function, suffix, prefix, __VA_ARGS__)


/**
 * @brief formatted debug message
 */
#ifdef DEBUG
    #define logd(message, function, ...) log_s(message, function, "D", __VA_ARGS__)
#else
    #define logd(message, function, ...)
#endif /* DEBUG */


/**
 * @brief formatted info
 */
#define logi_f(message, function, ...) log_s(message, function, "I", __VA_ARGS__)


/**
 * @brief formatted warning
 */
#define logw_f(message, function, ...) loge_sp(message, function, "W", "!", __VA_ARGS__)


/**
 * @brief formatted error
 */
#define loge_f(message, function, ...) loge_sp(message, function, "E", "!!!", __VA_ARGS__)


/**
 * @brief formatted fatal error
 */
#define logfe_f(message, function, ...) _csafe_logf_fatal("!!!!! [FATAL] " function ": " message, __VA_ARGS__)




    /* functions */
/**
 * @brief print a message, for internal use only
 * 
 * @param message format string
 */
void _csafe_logf_message(char* message, ...);

/**
 * @brief print an error, for internal use only
 * 
 * @param message format string
 */
void _csafe_logf_error(char* message, ...);

/**
 * @brief print a message and exit, for internal use only
 * 
 * @param message format string
 */
void _csafe_logf_fatal(char* message, ...);

#endif /* CSAFE_LOG_F_H */