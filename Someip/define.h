#include <cstdint>

namespace Someip {
using ServiceID = uint16_t;
using MethodID = uint16_t;
using InstanceID = uint16_t;
using EventID = uint16_t;
using Eventgroup_t = uint16_t;

enum class AppState : uint8_t {
    APPSTATE_REGISTER,
    APPSTATE_UNREGISTER,
};

enum class MsgType : uint8_t {
    MSG_REQ,
    MSG_REQ_NO_RETURN,
    RESPONSE,
    NOTIFICATION,
    ERROR,
    UNKNOW
};

enum class 
}