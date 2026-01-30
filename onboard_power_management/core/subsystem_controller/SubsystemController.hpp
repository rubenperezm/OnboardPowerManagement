#pragma once

#include "types/LoadStatus.hpp"
#include "types/PowerCommand.hpp"

using namespace core;
/**
 * @brief SubsystemController
 *
 * @details
 * Provides the operational context and load status to the PowerManager.
 * In a real system, this module would interface with hardware controllers
 * or other subsystems. In simulation, it can be fed with predefined scenarios.
 */
class SubsystemController {
    public:
        /**
        * @brief Constructor
        */
        SubsystemController();

        /**
        * @brief Destructor
        */
        ~SubsystemController() = default;

        /**
        * @brief Update the current load status of the subsystem
        *
        * @param command The command issued by the Power Manager
        */
        void updateLoadStatus(const PowerCommand& command);

        /**
        * @brief Retrieve the latest load status for the PowerManager
        *
        * @return Current LoadStatus
        */
        LoadStatus getLoadStatus() const;

    private:
        // Last known load status
        LoadStatus m_loadStatus;

        // Setters for each power mode
        void setNormal();
        void setSafe();
        void setOff(const bool emergencyShutdown);

        // Simulation of safe shutdown
        void wait_shutdown() const;
};

