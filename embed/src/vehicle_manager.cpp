#include <stdio.h>

#include "vehicle_manager.h"
#include "device/emulator/gps.h"
#include "device/emulator/battery.h"

void VehicleManager::loop()
{
    int ok;
    this->state.speed = 8;
    gps_sensor->ReadPosition(this->state);
    battery->ReadChargeLevel(this->state);

    printf("Current position: %d %d\n", this->state.latitude, this->state.longitude);
    printf("Current charge level: %.1f\n", this->state.charge_level / 10.);

    ok = this->sender->SendVehicleData(&this->state);

    if(ok == -1)
    {
        perror("Failed to send data to the server\n");
    }
}


VehicleManager::VehicleManager(Sender *sender)
{
    this->sender = sender;
    this->gps_sensor = new GpsEmulator;
    this->battery = new BatteryEmulator(this->state);
}

VehicleManager::~VehicleManager()
{
    delete this->gps_sensor;
    delete this->battery;
}
