

#ifndef SENSOR_H_SENTRY
#define SENSOR_H_SENTRY

#include "vehicle_state.h"

class GpsSensor {
public:
    virtual ~GpsSensor(){};
    virtual bool ReadPosition(vehicle_state& state) = 0;

};

#endif