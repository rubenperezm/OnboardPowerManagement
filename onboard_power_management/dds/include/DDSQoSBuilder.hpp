#pragma once

#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastdds/dds/core/policy/QosPolicies.hpp>

class DataReaderQosBuilder {
public:
    DataReaderQosBuilder();

    DataReaderQosBuilder& withBestEffort();
    DataReaderQosBuilder& withReliable();
    DataReaderQosBuilder& withKeepLast(int depth);
    DataReaderQosBuilder& withVolatileDurability();
    DataReaderQosBuilder& withTransientLocalDurability();
    DataReaderQosBuilder& withDeadline(uint32_t sec, uint32_t nanosec);

    eprosima::fastdds::dds::DataReaderQos build() const;

private:
    eprosima::fastdds::dds::DataReaderQos qos_;
};

class DataWriterQosBuilder {
public:
    DataWriterQosBuilder();

    DataWriterQosBuilder& withBestEffort();
    DataWriterQosBuilder& withReliable();
    DataWriterQosBuilder& withKeepLast(int depth);
    DataWriterQosBuilder& withVolatileDurability();
    DataWriterQosBuilder& withTransientLocalDurability();
    DataWriterQosBuilder& withLatencyBudget(uint32_t sec, uint32_t nanosec);

    eprosima::fastdds::dds::DataWriterQos build() const;

private:
    eprosima::fastdds::dds::DataWriterQos qos_;
};
