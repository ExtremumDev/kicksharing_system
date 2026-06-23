#include <unistd.h>
#include <netinet/in.h>

#include "vehicle_state.h"

#ifndef SENDER_H_SENTRY
#define SENDER_H_SENTRY

class Sender {
private:
    struct sockaddr_in socket_address;
    struct sockaddr_in server_address;
    int socket_fd;

    int OpenSocket();

public:
    Sender();
    Sender(char *local_address, short local_port, char *server_address, short server_port);

    int SendVehicleData(vehicle_state *state);

    ~Sender() {close(this->socket_fd);}
};

#endif