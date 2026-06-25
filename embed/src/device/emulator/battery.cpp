
#include "device/emulator/battery.h"


bool BatteryEmulator::ReadChargeLevel(vehicle_state &state)
{
    state.charge_level -= 1;

    return true;
}

BatteryEmulator::BatteryEmulator(vehicle_state &state)
{
    Init(state);
}