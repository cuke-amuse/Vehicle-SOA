#include <memory>

namespace Someip {
class SomeipIF {
public:
    static std::shared_ptr<SomeipIF>& Create();
    void OfferService();
    void OfferEvent();
    void SendMsg();
    virtual void Notify() = 0;

    // client part
    void BookService();
    void SendRegMsg();

        virtual void offer_event(service_t _service, instance_t _instance,
            event_t _notifier, const std::set<eventgroup_t> &_eventgroups,
            event_type_e _type = event_type_e::ET_EVENT,
            std::chrono::milliseconds _cycle =std::chrono::milliseconds::zero(),
            bool _change_resets_cycle = false,
            bool _update_on_change = true,
            const epsilon_change_func_t &_epsilon_change_func = nullptr,
            reliability_type_e _reliability = reliability_type_e::RT_UNKNOWN) = 0;
};
}