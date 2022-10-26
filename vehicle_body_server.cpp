#include "vehicle_body_server.h"

#include <map>
#include <thread>
#include <atomic>
#include <deque>
#include <functional>
#include <chrono>
#include "vehicle_body_operation.h"

namespace VehicleBodyPartition {
using excute = std::function<bool()>;
struct VehicleBodyServer:: Impl {
    std::thread thread_;
    std::atomic<bool> exit_{false};
    std::map<uint8_t, VehicleRequest> runningMap_;
    std::deque<VehicleRequest> cachedCmd_;
    constexpr static std::map<VehicleBodyControl, excute> funMap = {
            {VehicleBodyControl::WINDOW_CLOSE, &Impl::CloseWindow},
            {VehicleBodyControl::LIGHT_WELCOM, &Impl::LightWelcom},
            {VehicleBodyControl::INVALID_CMD, nullptr}
        };
    Impl() : runningMap_() {

    }
    ~Impl()
    {
        exit_ = true;
        if (thread_.joinable()) {
            thread_.join();
        }
    }
    void Init()
    {
        //Process();
        thread_ = std::move(std::thread(&Impl::Process, this));
    }
    void Process()
    {
        while (!exit_) {
            ProcessReq();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    bool LightWelcom()
    {

    }

    bool CloseWindow()
    { }

    void ProcessReq()
    { 
        while (!cachedCmd_.empty()) {
            VehicleRequest req = cachedCmd_.front();
            cachedCmd_.pop_front();
            if (funcMap.find(req.cmd) != funMap.end()) {
                funMap[req.cmd]();
            }
        }
    }
};

VehicleBodyServer::VehicleBodyServer()
    : pimpl_(std::make_unique<Impl>()) 
{ }
VehicleBodyServer::~VehicleBodyServer() 
{ }
}