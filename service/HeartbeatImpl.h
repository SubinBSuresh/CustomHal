
#pragma once
#include <aidl/com/dutch/heartbeat/BnHeartbeat.h>
#include <aidl/com/dutch/heartbeat/IHeartbeatListener.h>
#include <android/binder_auto_utils.h>

namespace aidl::com::dutch::heartbeat
{
    class HeartbeatImpl : public BnHeartbeat
    {
    public:
        ndk::ScopedAStatus pulse(std::string *_aidl_return) override;
        ndk::ScopedAStatus setListener(const std::shared_ptr<IHeartbeatListener> &listener) override;

    private:
        std::shared_ptr<IHeartbeatListener> mListener;
    };
} // namespace aidl::com::dutch::heartbeat