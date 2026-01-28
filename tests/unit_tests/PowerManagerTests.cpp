#include <gtest/gtest.h>
#include <optional>
#include <thread>
#include <chrono>

#include "PowerManagerTestAdapter.hpp"
#include "BatteryMeasurementsBuilder.hpp"
#include "SensorHealthStatusBuilder.hpp"



/**
 * Fixtures 
 */
class PowerManagerTest : public ::testing::Test {
  protected:
    PowerManagerTest() : config(TEST_CONFIG_FILE), pm(config) {}

    Config config;
    PowerManager pm;  
};

/**
 * Auxiliary functions
 */

void step(PowerManager& pm, const std::optional<BatteryMeasurements>& measurements,
          const std::optional<SensorHealthStatus>& healthStatus) {

  if (measurements.has_value()){
    pm.processBatteryMeasurements(measurements.value());
  }

  if (healthStatus.has_value()){
    pm.processSensorHealthStatus(healthStatus.value());
  }
  
  pm.evaluate();
}

/**
 * UT-PWR-001-A
 */
TEST_F(PowerManagerTest, UTPWR001A) {
  // UT-PWR-001-A.1 (fixture)

  // UT-PWR-001-A.2
  PowerMode currentMode = pm.getCurrentMode();
  EXPECT_EQ(currentMode, PowerMode::NORMAL) <<
   "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-001-A.3
  PowerManagerTestAdapter::forceMode(pm, PowerMode::SAFE);
  currentMode = pm.getCurrentMode();
  EXPECT_EQ(currentMode, PowerMode::SAFE) << "PowerManager did not transition to SAFE mode";

  // UT-PWR-001-A.4
  PowerManagerTestAdapter::forceMode(pm, PowerMode::OFF);
  currentMode = pm.getCurrentMode();
  EXPECT_EQ(currentMode, PowerMode::OFF) << "PowerManager did not transition to OFF mode";

  // UT-PWR-001-A.5
  PowerManagerTestAdapter::forceMode(pm, PowerMode::NORMAL);
  currentMode = pm.getCurrentMode();
  EXPECT_EQ(currentMode, PowerMode::NORMAL) << "PowerManager did not return to NORMAL mode";

}

/**
 * UT-PWR-001-B
 */
TEST_F(PowerManagerTest, UTPWR001B) {
  SUCCEED() << "Verified by analysis (see AN-PWR-001).";
}

/**
 * UT-PWR-002-A
 */
TEST_F(PowerManagerTest, UTPWR002A) {
  // UT-PWR-002-A.1 (fixture)

  // UT-PWR-002-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-002-A.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMinVoltage() - 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-002-A.4
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode on undervoltage condition";
}

/**
 * UT-PWR-002-B
 */
TEST_F(PowerManagerTest, UTPWR002B) {
  // UT-PWR-002-B.1 (fixture)

  // UT-PWR-002-B.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-002-B.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMaxVoltage() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-002-B.4
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode on overvoltage condition";
}

/**
 * UT-PWR-003-A
 */
TEST_F(PowerManagerTest, UTPWR003A) {
  // UT-PWR-003-A.1 (fixture)

  // UT-PWR-003-A.2
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMinVoltage() - 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-A.3
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode on undervoltage condition";

  // UT-PWR-003-A.4
  measurements = BatteryMeasurementsBuilder(config).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-A.5
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL)
    << "PowerManager did not return to NORMAL mode after recovering from undervoltage condition";
}

/**
 * UT-PWR-003-B
 */
TEST_F(PowerManagerTest, UTPWR003B) {
  // UT-PWR-003-B.1 (fixture)

  // UT-PWR-003-B.2
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMaxVoltage() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-B.3
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode on overvoltage condition";

  // UT-PWR-003-B.4
  measurements = BatteryMeasurementsBuilder(config).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-B.5
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL)
    << "PowerManager did not return to NORMAL mode after recovering from overvoltage condition";
}

/**
 * UT-PWR-003-C
 */
TEST_F(PowerManagerTest, UTPWR003C) {
  // UT-PWR-003-C.1 (fixture)

  // UT-PWR-003-C.2
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMinVoltage() - 0.8).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-C.3
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode on overvoltage condition";

  // UT-PWR-003-C.4
  measurements = BatteryMeasurementsBuilder(config).withVoltage(config.getMinVoltage() + 0.2).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-C.5
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not remain in SAFE mode after detecting voltage outside recovery margins";
}


/**
 * UT-PWR-003-D
 */
TEST_F(PowerManagerTest, UTPWR003D) {
  // UT-PWR-003-D.1 (fixture)

  // UT-PWR-003-D.2
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMaxVoltage() + 1.2).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-D.3
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode on overvoltage condition";

  // UT-PWR-003-D.4
  measurements = BatteryMeasurementsBuilder(config).withVoltage(config.getMaxVoltage() - 0.2).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-003-D.5
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not remain in SAFE mode after detecting voltage outside recovery margins";
}

/**
 * UT-PWR-005-A
 */
TEST_F(PowerManagerTest, UTPWR005A){
  // UT-PWR-005-A.1 (fixture)
  
  // UT-PWR-005-A.2
  BatteryMeasurements normalMeasurements = BatteryMeasurementsBuilder(config).build();

  step(pm, normalMeasurements, std::nullopt);

  // UT-PWR-005-A.3
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL)
    << "PowerManager did not transition from NORMAL to NORMAL";

  // UT-PWR-005-A.4
  pm.setShutdown(true);

  // UT-PWR-005-A.5
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::OFF)
    << "PowerManager did not transition from NORMAL to OFF (via setShutdown)";

  // UT-PWR-005-A.6
  pm.setShutdown(false);

  // UT-PWR-005-A.7
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL)
    << "PowerManager did not transition from OFF to NORMAL";

  // UT-PWR-005-A.8
  BatteryMeasurements safeMeasurements = BatteryMeasurementsBuilder(config)
                                          .withVoltage(config.getMaxVoltage() + 0.5).build();

  step(pm, safeMeasurements, std::nullopt);

  // UT-PWR-005-A.9
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition from NORMAL to SAFE";

  // UT-PWR-005-A.10
  step(pm, normalMeasurements, std::nullopt);

  // UT-PWR-005-A.11
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL)
    << "PowerManager did not transition from SAFE to NORMAL";

  // UT-PWR-005-A.12
  step(pm, safeMeasurements, std::nullopt);

  // UT-PWR-005-A.13
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition from NORMAL to SAFE";

  // UT-PWR-005-A.14
  step(pm, safeMeasurements, std::nullopt);

  // UT-PWR-005-A.15
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition from SAFE to SAFE";

  // UT-PWR-005-A.16
  SensorHealthStatus failedSensors = SensorHealthStatusBuilder()
                                      .withAnyFailed(true).build();

  step(pm, safeMeasurements, failedSensors);

  // UT-PWR-005-A.17
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::OFF)
    << "PowerManager did not transition from SAFE to OFF";

  // UT-PWR-005-A.18
  pm.setShutdown(true);

  // UT-PWR-005-A.19
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::OFF)
    << "PowerManager did not transition from OFF to OFF";

}

/**
 * UT-PWR-005-B
 */
TEST_F(PowerManagerTest, UTPWR005B) {
  SUCCEED() << "Verified by analysis (see AN-PWR-005).";
}

/**
 * UT-PWR-007-A
 */
TEST_F(PowerManagerTest, UTPWR007A) {
  // UT-PWR-007-A.1 (fixture)

  // UT-PWR-007-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-007-A.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMinVoltage() - 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-007-A.4
  EXPECT_TRUE(PowerManagerTestAdapter::getVoltageUnderloadFlag(pm)) << 
    "Undervoltage flag has not been set after processing undervoltage measurements";
}

/**
 * UT-PWR-007-B
 */
TEST_F(PowerManagerTest, UTPWR007B) {
  // UT-PWR-007-B.1 (fixture)

  // UT-PWR-007-B.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-007-B.3
  EXPECT_FALSE(PowerManagerTestAdapter::getVoltageUnderloadFlag(pm)) << 
    "Precondition failed: undervoltage flag is set to true initially";

  // UT-PWR-007-B.4
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMinVoltage() - 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-007-B.5
  EXPECT_TRUE(PowerManagerTestAdapter::getVoltageUnderloadFlag(pm)) << 
    "Undervoltage flag has not been set after processing undervoltage measurements";

  // UT-PWR-007-B.6
  measurements = BatteryMeasurementsBuilder(config).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-007-B.7
  EXPECT_FALSE(PowerManagerTestAdapter::getVoltageUnderloadFlag(pm)) << 
    "Undervoltage flag has not been unset after processing normal measurements";

}

/**
 * UT-PWR-008-A
 */
TEST_F(PowerManagerTest, UTPWR008A) {
  // UT-PWR-008-A.1 (fixture)

  // UT-PWR-008-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-008-A.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMaxVoltage() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-008-A.4
  EXPECT_TRUE(PowerManagerTestAdapter::getVoltageOverloadFlag(pm)) << 
    "Overvoltage flag has not been set after processing overvoltage measurements";
}

/**
 * UT-PWR-008-B
 */
TEST_F(PowerManagerTest, UTPWR008B) {
  // UT-PWR-008-B.1 (fixture)

  // UT-PWR-008-B.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-008-B.3
  EXPECT_FALSE(PowerManagerTestAdapter::getVoltageOverloadFlag(pm)) << 
    "Precondition failed: overvoltage flag is set to true initially";

  // UT-PWR-008-B.4
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withVoltage(config.getMaxVoltage() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-008-B.5
  EXPECT_TRUE(PowerManagerTestAdapter::getVoltageOverloadFlag(pm)) << 
    "Overvoltage flag has not been set after processing overvoltage measurements";

  // UT-PWR-008-B.6
  measurements = BatteryMeasurementsBuilder(config).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-008-B.7
  EXPECT_FALSE(PowerManagerTestAdapter::getVoltageOverloadFlag(pm)) << 
    "Overvoltage flag has not been unset after processing normal measurements";

}

/**
 * UT-PWR-010-A
 */
TEST_F(PowerManagerTest, UTPWR010A) {
  // UT-PWR-010-A.1 (fixture)

  // UT-PWR-010-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-010-A.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withCurrent(config.getMaxCurrent() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-010-A.4
  EXPECT_TRUE(PowerManagerTestAdapter::getCurrentOverloadFlag(pm)) << 
    "Overcurrent flag has not been set after processing overcurrent measurements";
}

/**
 * UT-PWR-010-B
 */
TEST_F(PowerManagerTest, UTPWR010B) {
  // UT-PWR-010-B.1 (fixture)

  // UT-PWR-010-B.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-010-B.3
  EXPECT_FALSE(PowerManagerTestAdapter::getCurrentOverloadFlag(pm)) << 
    "Precondition failed: overcurrent flag is set to true initially";

  // UT-PWR-010-B.4
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withCurrent(config.getMaxCurrent() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-010-B.5
  EXPECT_TRUE(PowerManagerTestAdapter::getCurrentOverloadFlag(pm)) << 
    "Overcurrent flag has not been set after processing overcurrent measurements";

  // UT-PWR-010-B.6
  measurements = BatteryMeasurementsBuilder(config).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-010-B.7
  EXPECT_FALSE(PowerManagerTestAdapter::getCurrentOverloadFlag(pm)) << 
    "Overcurrent flag has not been unset after processing normal measurements";

}

/**
 * UT-PWR-011-A
 */
TEST_F(PowerManagerTest, UTPWR011A) {
  // UT-PWR-011-A.1 (fixture)

  // UT-PWR-011-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-011-A.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withCurrent(config.getMaxCurrent() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-011-A.4
  measurements.timestamp_us(measurements.timestamp_us() + config.getOvercurrentDurationThreshold() * 1000000);

  step(pm, measurements, std::nullopt);

  // UT-PWR-011-A.5
  EXPECT_TRUE(PowerManagerTestAdapter::getSustainedOvercurrentFlag(pm)) << 
    "Sustained overcurrent flag has not been set";

  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode on sustained overcurrent condition";
}

/**
 * UT-PWR-011-B
 */
TEST_F(PowerManagerTest, UTPWR011B) {
  // UT-PWR-011-B.1 (fixture)

  // UT-PWR-011-B.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-011-B.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withCurrent(config.getMaxCurrent() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-011-B.4
  step(pm, measurements, std::nullopt);

  // UT-PWR-011-B.5
  EXPECT_FALSE(PowerManagerTestAdapter::getSustainedOvercurrentFlag(pm)) << 
    "Sustained overcurrent flag has been set, but duration was not enough";

  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL)
    << "PowerManager did not stayed in SAFE mode after transient overcurrent";
}

/**
 * UT-PWR-013-A
 */
TEST_F(PowerManagerTest, UTPWR013A) {
  // UT-PWR-013-A.1 (fixture)

  // UT-PWR-013-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-013-A.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withTemperature(config.getMaxTemperature() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-013-A.4
  EXPECT_FALSE(PowerManagerTestAdapter::getUndertemperatureFlag(pm)) << 
    "Undertemperature flag has been set after processing overtemperature measurements";

  EXPECT_TRUE(PowerManagerTestAdapter::getOvertemperatureFlag(pm)) << 
    "Overtemperature flag has not been set after processing overtemperature measurements";

  // UT-PWR-013-A.5
  measurements = BatteryMeasurementsBuilder(config)
                                      .withTemperature(config.getMinTemperature() - 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-013-A.6
  EXPECT_FALSE(PowerManagerTestAdapter::getOvertemperatureFlag(pm)) << 
    "Overtemperature flag has been set after processing undertemperature measurements";

  EXPECT_TRUE(PowerManagerTestAdapter::getUndertemperatureFlag(pm)) << 
    "Undertemperature flag has not been set after processing undertemperature measurements";
}

/**
 * UT-PWR-013-B
 */
TEST_F(PowerManagerTest, UTPWR013B) {
  // UT-PWR-013-B.1 (fixture)

  // UT-PWR-013-B.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-013-B.3
  BatteryMeasurements overTempMeasurements = BatteryMeasurementsBuilder(config)
                                      .withTemperature(config.getMaxTemperature() + 0.5).build();

  step(pm, overTempMeasurements, std::nullopt);

  // UT-PWR-01B-B.4
  EXPECT_FALSE(PowerManagerTestAdapter::getUndertemperatureFlag(pm)) << 
    "Undertemperature flag has been set after processing overtemperature measurements";

  EXPECT_TRUE(PowerManagerTestAdapter::getOvertemperatureFlag(pm)) << 
    "Overtemperature flag has not been set after processing overtemperature measurements";

  // UT-PWR-01B-B.5
  BatteryMeasurements normalMeasurements = BatteryMeasurementsBuilder(config).build();

  step(pm, normalMeasurements, std::nullopt);

  // UT-PWR-013-B.6
  EXPECT_FALSE(PowerManagerTestAdapter::getOvertemperatureFlag(pm)) << 
    "Overtemperature flag has been set after processing normal measurements";

  EXPECT_FALSE(PowerManagerTestAdapter::getUndertemperatureFlag(pm)) << 
    "Undertemperature flag has been set after processing normal measurements";
  
  // UT-PWR-01B-B.7
  BatteryMeasurements underTempMeasurements = BatteryMeasurementsBuilder(config)
                                      .withTemperature(config.getMinTemperature() - 0.5).build();

  step(pm, underTempMeasurements, std::nullopt);

  // UT-PWR-013-B.8
  EXPECT_FALSE(PowerManagerTestAdapter::getOvertemperatureFlag(pm)) << 
    "Overtemperature flag has been set after processing undertemperature measurements";

  EXPECT_TRUE(PowerManagerTestAdapter::getUndertemperatureFlag(pm)) << 
    "Undertemperature flag has not been set after processing undertemperature measurements";

  // UT-PWR-013-B.9
  step(pm, normalMeasurements, std::nullopt);

  // UT-PWR-013-A.10
  EXPECT_FALSE(PowerManagerTestAdapter::getOvertemperatureFlag(pm)) << 
    "Overtemperature flag has been set after processing normal measurements";

  EXPECT_FALSE(PowerManagerTestAdapter::getUndertemperatureFlag(pm)) << 
    "Undertemperature flag has been set after processing normal measurements";
}

/**
 * UT-PWR-014-A
 */
TEST_F(PowerManagerTest, UTPWR014A) {
  // UT-PWR-014-A.1 (fixture)

  // UT-PWR-014-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-014-A.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withTemperature(config.getMaxTemperature() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-014-A.4
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode after overtemperature conditions";
}

/**
 * UT-PWR-014-B
 */
TEST_F(PowerManagerTest, UTPWR014B) {
  // UT-PWR-014-B.1 (fixture)

  // UT-PWR-014-B.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-014-B.3
  BatteryMeasurements measurements = BatteryMeasurementsBuilder(config)
                                      .withTemperature(config.getMinTemperature() - 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-014-B.4
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE mode after overtemperature conditions";

  // UT-PWR-014-B.5
  measurements = BatteryMeasurementsBuilder(config)
                                      .withTemperature(config.getMaxTemperature() + 0.5).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-014-B.6
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager transitioned to NORMAL mode after changing from undertemperature to overtemperature conditions";

  EXPECT_FALSE(PowerManagerTestAdapter::getUndertemperatureFlag(pm)) << 
    "Undertemperature flag has been set after processing overtemperature measurements";

  EXPECT_TRUE(PowerManagerTestAdapter::getOvertemperatureFlag(pm)) << 
    "Overtemperature flag has not been set after processing overtemperature measurements";

  // UT-PWR-014-A.7
  measurements = BatteryMeasurementsBuilder(config).build();

  step(pm, measurements, std::nullopt);

  // UT-PWR-014-A.8
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after returning to allowable temperature limits";
}

/**
 * UT-PWR-016-A
 */
TEST_F(PowerManagerTest, UTPWR016A) {
  SUCCEED() << "Verified by functional tests (see FT-PWR-016).";
}

/**
 * UT-PWR-022-A
 */
TEST_F(PowerManagerTest, UTPWR022A){
  // UT-PWR-022-A.1 (fixture)

  // UT-PWR-022-A.2
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::NORMAL) << 
    "Precondition failed: PowerManager is not in NORMAL mode after initialization";

  // UT-PWR-022-A.3
  SensorHealthStatus status = SensorHealthStatusBuilder().withAnyDegraded(true).build();

  step(pm, std::nullopt, status);

  // UT-PWR-022-A.4
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::SAFE)
    << "PowerManager did not transition to SAFE after degraded sensors present";

  // UT-PWR-022-A.5
  status = SensorHealthStatusBuilder().withAnyFailed(true).build();

  step(pm, std::nullopt, status);

  // UT-PWR-022-A.6
  EXPECT_EQ(pm.getCurrentMode(), PowerMode::OFF)
    << "PowerManager did not transition to OFF after failing sensors present";
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}