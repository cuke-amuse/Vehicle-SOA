#include <memory>

namespace VehicleBodyPartition {
class VehicleBodyServer {
public:
    VehicleBodyServer();
    ~VehicleBodyServer() = default;
private:
    struct Impl;
    std::unique_ptr<Impl> pimpl_;
};

}