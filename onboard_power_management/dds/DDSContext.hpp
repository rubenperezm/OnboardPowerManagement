#pragma once

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>

class DDSContext {
public:
    DDSContext();
    ~DDSContext();

    eprosima::fastdds::dds::DomainParticipant* participant() const;
    eprosima::fastdds::dds::Publisher* publisher() const;
    eprosima::fastdds::dds::Subscriber* subscriber() const;

private:
    eprosima::fastdds::dds::DomainParticipant* participant_;
    eprosima::fastdds::dds::Publisher* publisher_;
    eprosima::fastdds::dds::Subscriber* subscriber_;
};
