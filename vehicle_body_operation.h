#include <cstdint>

namespace VehicleBodyPartition {

//class VehicleBodyOperation {
//public:
    enum class VehicleBodyControl : uint8_t {
        WINDOW_CLOSE,
        LIGHT_WELCOM,
        STEERING_WHEEL_SHARKHAND,
        INVALID_CMD
    };
  //  VehicleBodyOperation();
    //~VehicleBodyOperation();
   // bool CloseWindow();
   // bool LightWelcom();
   // bool SteeringWheelShakehand();
//};
struct VehicleRequest {
    long srcPid;
    VehicleBodyControl cmd;
} ;

}