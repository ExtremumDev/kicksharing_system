#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "vehicle_manager.h"
#include "sender.h"

int main(int argc, char **argv)
{
    short socket_port, server_port;
    if(argc < 5)
    {
        perror("Not ehough arguments");
        return 1;
    }

    socket_port = atoi(argv[2]);
    server_port = atoi(argv[4]);

    Sender sender(argv[1], socket_port, argv[3], server_port);
    VehicleManager device(&sender);
    bool run_fl = true;

    while(run_fl){
        device.loop();
        sleep(1);

    }

    return 0;

}

