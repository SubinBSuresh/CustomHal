#include "HeartbeatImpl.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <android-base/logging.h>

namespace aidl::com::dutch::heartbeat
{

    ndk::ScopedAStatus HeartbeatImpl::pulse(std::string *_aidl_return)
    {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");

        *_aidl_return = "Dutch Heartbeat: " + ss.str();
        LOG(INFO) << "HeartbeatImpl: Returning pulse - " << *_aidl_return;

        if (mListener)
        {
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                          std::chrono::system_clock::now().time_since_epoch())
                          .count();
            mListener->onHeartbeat(ms);
        }

        return ndk::ScopedAStatus::ok();
    }

    ndk::ScopedAStatus HeartbeatImpl::setListener(const std::shared_ptr<IHeartbeatListener> &listener)
    {
        mListener = listener;
        LOG(INFO) << "HeartbeatImpl: Listener registered";
        return ndk::ScopedAStatus::ok();
    }

} // namespace aidl::com::dutch::heartbeat