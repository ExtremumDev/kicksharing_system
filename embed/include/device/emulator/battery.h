
#ifndef BATTERY_EM_H_SENTRY
#define BATTERY_EM_H_SENTRY

#include "device/interface/battery.h"

class BatteryEmulator : public Battery {

public:
    BatteryEmulator(vehicle_state &state);

    bool ReadChargeLevel(vehicle_state &state);
private:
    void Init(vehicle_state &state) { state.charge_level = 1000; };
};

#endif