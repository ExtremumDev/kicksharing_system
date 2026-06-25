#include "device/emulator/gps.h"

bool GpsEmulator::ReadPosition(vehicle_state &state)
{
    state.latitude += 1;
    state.longitude -= 1;
    return true;
}