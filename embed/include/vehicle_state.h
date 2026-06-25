
#ifndef VEHICLE_STATE_H_SENTRY
#define VEHICLE_STATE_H_SENTRY

#include <stdint.h>

typedef struct {
    uint32_t latitude;
    uint32_t longitude;
    uint16_t speed;
    uint16_t charge_level; // Keeps charge level in the range 0-1000 (with the tenth part)

} vehicle_state;

#endif
