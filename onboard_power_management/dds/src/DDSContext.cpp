#include "DDSContext.hpp"

using namespace eprosima::fastdds::dds;

DDSContext::DDSContext() {
    DomainParticipantQos pqos;
    participant_ =
        DomainParticipantFactory::get_instance()->create_participant(0, pqos);

    publisher_  = participant_->create_publisher(PUBLISHER_QOS_DEFAULT);
    subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT);
}

DDSContext::~DDSContext() {
    participant_->delete_contained_entities();
    DomainParticipantFactory::get_instance()->delete_participant(participant_);
}
