#pragma once

#include <fastdds/dds/publisher/DataWriter.hpp>

template<typename MsgT>
class GenericPublisher {
public:
    explicit GenericPublisher(eprosima::fastdds::dds::DataWriter* writer)
        : writer_(writer)
    {}

    bool publish(const MsgT& data)
    {
        if (!writer_) {
            return false;
        }

        return writer_->write(
            const_cast<MsgT*>(&data)
        ) == ReturnCode_t::RETCODE_OK;
    }

private:
    eprosima::fastdds::dds::DataWriter* writer_{nullptr};
};