#include "HeartbeatImpl.h"
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <android-base/logging.h>

using aidl::com::dutch::heartbeat::HeartbeatImpl;

int main()
{
    android::base::InitLogging(nullptr, android::base::LogdLogger(android::base::SYSTEM));
    ABinderProcess_setThreadPoolMaxThreadCount(0);
    ABinderProcess_startThreadPool();

    std::shared_ptr<HeartbeatImpl> service = ndk::SharedRefBase::make<HeartbeatImpl>();

    // Naming convention: <interface_name>/default
    const std::string instance = std::string(HeartbeatImpl::descriptor) + "/default";

    binder_status_t status = AServiceManager_addService(service->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK) << "Failed to register service " << instance << " " << status;

    LOG(INFO) << "Heartbeat HAL service started: " << instance;

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE; // Should not reach here
}