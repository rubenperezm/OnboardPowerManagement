#include "DDSQoSBuilder.hpp"

// ---------------- DataReaderQosBuilder ----------------

DataReaderQosBuilder::DataReaderQosBuilder()
{
    qos_.history().kind = eprosima::fastdds::dds::KEEP_LAST_HISTORY_QOS;
    qos_.history().depth = 1;
    qos_.reliability().kind = eprosima::fastdds::dds::BEST_EFFORT_RELIABILITY_QOS;
    qos_.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS;
    qos_.resource_limits().max_samples = 10;
    qos_.resource_limits().max_instances = 1;
    qos_.resource_limits().max_samples_per_instance = 10;
    qos_.deadline().period = eprosima::fastrtps::Duration_t(0, 10000000);
}

DataReaderQosBuilder& DataReaderQosBuilder::withBestEffort()
{
    qos_.reliability().kind = eprosima::fastdds::dds::BEST_EFFORT_RELIABILITY_QOS;
    return *this;
}

DataReaderQosBuilder& DataReaderQosBuilder::withReliable()
{
    qos_.reliability().kind = eprosima::fastdds::dds::RELIABLE_RELIABILITY_QOS;
    return *this;
}

DataReaderQosBuilder& DataReaderQosBuilder::withKeepLast(int depth)
{
    qos_.history().kind = eprosima::fastdds::dds::KEEP_LAST_HISTORY_QOS;
    qos_.history().depth = depth;
    return *this;
}

DataReaderQosBuilder& DataReaderQosBuilder::withVolatileDurability()
{
    qos_.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS;
    return *this;
}

DataReaderQosBuilder& DataReaderQosBuilder::withTransientLocalDurability()
{
    qos_.durability().kind = eprosima::fastdds::dds::TRANSIENT_LOCAL_DURABILITY_QOS;
    return *this;
}

DataReaderQosBuilder& DataReaderQosBuilder::withDeadline(uint32_t sec, uint32_t nanosec)
{
    qos_.deadline().period = eprosima::fastrtps::Duration_t(sec, nanosec);
    return *this;
}

eprosima::fastdds::dds::DataReaderQos DataReaderQosBuilder::build() const
{
    return qos_;
}

// ---------------- DataWriterQosBuilder ----------------

DataWriterQosBuilder::DataWriterQosBuilder()
{
    qos_.history().kind = eprosima::fastdds::dds::KEEP_LAST_HISTORY_QOS;
    qos_.history().depth = 1;
    qos_.reliability().kind = eprosima::fastdds::dds::BEST_EFFORT_RELIABILITY_QOS;
    qos_.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS;
    qos_.resource_limits().max_samples = 10;
    qos_.latency_budget().duration = eprosima::fastrtps::Duration_t(0, 10000000);
}

DataWriterQosBuilder& DataWriterQosBuilder::withBestEffort()
{
    qos_.reliability().kind = eprosima::fastdds::dds::BEST_EFFORT_RELIABILITY_QOS;
    return *this;
}

DataWriterQosBuilder& DataWriterQosBuilder::withReliable()
{
    qos_.reliability().kind = eprosima::fastdds::dds::RELIABLE_RELIABILITY_QOS;
    return *this;
}

DataWriterQosBuilder& DataWriterQosBuilder::withKeepLast(int depth)
{
    qos_.history().kind = eprosima::fastdds::dds::KEEP_LAST_HISTORY_QOS;
    qos_.history().depth = depth;
    return *this;
}

DataWriterQosBuilder& DataWriterQosBuilder::withVolatileDurability()
{
    qos_.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS;
    return *this;
}

DataWriterQosBuilder& DataWriterQosBuilder::withTransientLocalDurability()
{
    qos_.durability().kind = eprosima::fastdds::dds::TRANSIENT_LOCAL_DURABILITY_QOS;
    return *this;
}

DataWriterQosBuilder& DataWriterQosBuilder::withLatencyBudget(uint32_t sec, uint32_t nanosec)
{
    qos_.latency_budget().duration = eprosima::fastrtps::Duration_t(sec, nanosec);
    return *this;
}

eprosima::fastdds::dds::DataWriterQos DataWriterQosBuilder::build() const
{
    return qos_;
}