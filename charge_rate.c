#include <stdio.h>
#include "charge_rate.h"

#define CHARGE_RATE_UPPER_LIMIT 0.8
#define CHARGE_WARNING_TOLERANCE 0.04 // 5% of 0.8

int chargeRateIsOk(float chargeRate) {
    if (chargeRate > CHARGE_RATE_UPPER_LIMIT) {
        printf("Charge Rate out of range!\n");
        return 0;
    } else if (chargeRate >= CHARGE_RATE_UPPER_LIMIT - CHARGE_WARNING_TOLERANCE) {
        printf("Warning: Approaching upper charge rate limit!\n");
    }
    return 1;
}
