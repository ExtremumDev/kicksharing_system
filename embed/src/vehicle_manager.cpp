#include <stdio.h>

#include "vehicle_manager.h"
#include "emulator/gps.h"

void VehicleManager::loop()
{
    int ok;
    this->state.speed = 8;
    this->gps_sensor->ReadPosition(this->state);

    printf("Current position: %d %d\n", this->state.latitude, this->state.longitude);

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

}

VehicleManager::~VehicleManager()
{
    delete this->gps_sensor;

}
