
#ifndef GPS_EMULATOR_H_SENTRY
#define GPS_EMULATOR_H_SENTRY

#include "device/interface/sensor_interface.h"


class GpsEmulator : public GpsSensor{
public:
    bool ReadPosition(vehicle_state &state);
};

#endif