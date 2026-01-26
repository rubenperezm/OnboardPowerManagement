#pragma once

#include "LogConfig.hpp"
#include "LogBackend.hpp"

#if LOG_LEVEL == LOG_LEVEL_DEBUG
    #define LOG_DEBUG(msg) log_backend_debug(msg)
#else
    #define LOG_DEBUG(msg) do {} while(0)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
    #define LOG_INFO(msg) log_backend_info(msg)
#else
    #define LOG_INFO(msg) do {} while(0)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
    #define LOG_WARN(msg) log_backend_warn(msg)
#else
    #define LOG_WARN(msg) do {} while(0)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
    #define LOG_ERROR(msg) log_backend_error(msg)
#else
    #define LOG_ERROR(msg) do {} while(0)
#endif
