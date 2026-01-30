#pragma once

#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <functional>

#include "DDSCoreAdapter.hpp"

template<typename MsgT, typename ObjT>
class GenericListener : public eprosima::fastdds::dds::DataReaderListener {
    public:
        using Callback = void (ObjT::*)(const MsgT&);

        GenericListener(ObjT* object, Callback callback) : object_(object), callback_(callback) {}

        void on_data_available(eprosima::fastdds::dds::DataReader* reader) override {
            MsgT data;
            eprosima::fastdds::dds::SampleInfo info;

            while (reader->take_next_sample(&data, &info) ==
                ReturnCode_t::RETCODE_OK)
            {
                
                if (info.valid_data) {
                    (object_->*callback_)(data);
                }
            }
        }

    private:
        ObjT* object_;
        Callback callback_;
};
