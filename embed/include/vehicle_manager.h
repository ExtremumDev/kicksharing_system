#ifndef VMANAGER_H_SENTRY
#define VMANAGER_H_SENTRY

#include "sensor_interface.h"
#include "sender.h"

class VehicleManager {
private:
    vehicle_state state;
    GpsSensor *gps_sensor;
    Sender *sender;
public:
    VehicleManager(Sender *sender);
    void loop();

    ~VehicleManager();
};

#endif