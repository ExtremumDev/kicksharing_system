#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

#include "sender.h"

int transform_address_ton(struct sockaddr_in *dst, char *address, short port)
{
    int ok;
    ok = inet_aton(address, &dst->sin_addr);

    if (ok == -1)
        return -1;

    dst->sin_port = htons(port);
    dst->sin_family = AF_INET;
    return 0;
}

Sender::Sender(char *local_address, short local_port, char *server_address, short server_port)
{
    int ok;

    ok = transform_address_ton(&this->socket_address, local_address, local_port);
    if(ok == -1)
    {
        perror("Invalid format of local address or port\n");
    }

    ok = transform_address_ton(&this->server_address, server_address, server_port);
    if(ok == -1)
    {
        perror("Invalid format of server address or port\n");
    }
    this->socket_fd = -1;
}

int Sender::OpenSocket()
{
    int fd, call_status;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    if(fd == -1)
    {
        return -1;
    }

    this->socket_fd = fd;

    call_status = bind(
        this->socket_fd, (struct sockaddr*)&this->socket_address, sizeof(sockaddr_in)
    );

    if(call_status == -1)
    {
        return -1;
    }

    return 0;
}

int Sender::SendVehicleData(vehicle_state *state)
{
    int res;

    if(this->socket_fd == -1) {
        res = this->OpenSocket();

        if(res == -1){
            return -1;
        }
    }
    res = sendto(
        this->socket_fd, state, sizeof(*state), 0, (struct sockaddr*)&this->server_address, sizeof(sockaddr_in)
    );

    return 0;
}