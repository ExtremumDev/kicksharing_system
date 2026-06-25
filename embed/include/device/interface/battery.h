
#ifndef BATTERY_H_SENTRY
#define BATTERY_H_SENTRY

#include "vehicle_state.h"


class Battery {

public:
    virtual bool ReadChargeLevel(vehicle_state &state) = 0;
    virtual ~Battery(){};
};

#endif