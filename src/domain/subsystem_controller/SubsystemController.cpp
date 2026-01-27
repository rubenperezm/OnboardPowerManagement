#include <thread>
#include <iostream>
#include <chrono>

#include "SubsystemController.hpp"

SubsystemController::SubsystemController() : m_loadStatus{true, true, true, 0} {}

void SubsystemController::updateLoadStatus(const PowerCommand& command){
    if (command.mode == PowerMode::NORMAL){
        setNormal();
    } else if (command.mode == PowerMode::SAFE){
        setSafe();
    } else {
        setOff(command.emergencyShutdown);
    }

    m_loadStatus.timestamp_us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()
    ).count();
}

LoadStatus SubsystemController::getLoadStatus() const{
    return m_loadStatus;
}

void SubsystemController::setNormal(){
    m_loadStatus.payloadActive = true;
    m_loadStatus.commsActive = true;
    m_loadStatus.thermalActive = true;
}

void SubsystemController::setSafe(){
    m_loadStatus.payloadActive = false;
    m_loadStatus.commsActive = true;
    m_loadStatus.thermalActive = true;
}

void SubsystemController::setOff(const bool emergencyShutdown){
    if (!emergencyShutdown){
        wait_shutdown();
    }

    m_loadStatus.payloadActive = false;
    m_loadStatus.commsActive = false;
    m_loadStatus.thermalActive = false;
}

void SubsystemController::wait_shutdown() const{
    try {
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    } catch (const std::exception& e) {
        std::cerr << "Error during sleep: " << e.what() << std::endl;
    }
}