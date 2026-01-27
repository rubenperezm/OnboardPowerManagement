#include <iostream>

#include "LogBackend.hpp"

void log_backend_debug(const std::string msg){
    std::cerr << "[DEBUG] " << msg << std::endl;
}

void log_backend_info(const std::string msg){
    std::cerr << "[INFO] " << msg << std::endl;
}

void log_backend_warn(const std::string msg){
    std::cerr << "[WARN] " << msg << std::endl;
}

void log_backend_error(const std::string msg){
    std::cerr << "[ERROR] " << msg << std::endl;
}
