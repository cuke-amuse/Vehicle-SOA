#include <vector>
#include <memory>

#include "./Someip/SomeipIF.h"
#include "./Someip/define.h"

class VehicleSomeIpAgent {
public:
    //static VehicleSomeIpAgent& GetInstance()
    //{
      //  static VehicleSomeIpAgent sa;
       // return sa;
    //}
    explicit VehicleSomeIpAgent(std::shared_ptr<Someip::SomeipIF>& app)
      : app_(app) 
    { }
    // for server part
    void Advertise(std::vector<Service>& service)
    {
        app_->OfferService();
    }
    
    void PublishEvent(Someip::ServiceID serviceId, Someip::InstanceID instanceId, Someip::MethodID methodId,
        Someip::EventID)
    {
        app_->OfferEvent();
    }
    // for client part
    void SendReqMethod(Someip::ServiceID serviceId, Someip::InstanceID instanceId, Someip::MethodID methodId)   // method close window or sth else
    {
        app_->OfferEvent();
    }

    bool GetField()
    {

    }
    void Subscribe(const std::vector<Service>& services)
    {
        app_->book_service();
        app_->RegisterAvailable();
    }

private:
    VehicleSomeIpAgent(const VehicleSomeIpAgent&) = delete;
    VehicleSomeIpAgent& operator=(const VehicleSomeIpAgent&) = delete;
    void OnState();
    void OnNotification();
    void UnBookService();
    void StopOfferService();
    //VehicleSomeIpAgent();
    std::shared_ptr<Someip::SomeipIF> app_;
};