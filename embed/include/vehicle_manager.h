#ifndef VMANAGER_H_SENTRY
#define VMANAGER_H_SENTRY

#include "device/interface/sensor_interface.h"
#include "device/interface/battery.h"

#include "sender.h"

class VehicleManager {
private:
    vehicle_state state;

    GpsSensor *gps_sensor;
    Battery *battery;
    
    Sender *sender;
public:
    VehicleManager(Sender *sender);
    void loop();

    ~VehicleManager();
};

#endif