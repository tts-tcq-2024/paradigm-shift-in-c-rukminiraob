#include <stdio.h>
#include "temperature.h"

#define TEMPERATURE_UPPER_LIMIT 45
#define TEMPERATURE_LOWER_LIMIT 0
#define TEMPERATURE_WARNING_TOLERANCE 2.25 // 5% of 45

int temperatureIsOk(float temperature) {
    if (temperature < TEMPERATURE_LOWER_LIMIT || temperature > TEMPERATURE_UPPER_LIMIT) {
        printf("Temperature out of range!\n");
        return 0;
    } else if (temperature <= TEMPERATURE_LOWER_LIMIT + TEMPERATURE_WARNING_TOLERANCE) {
        printf("Warning: Approaching lower temperature limit!\n");
    } else if (temperature >= TEMPERATURE_UPPER_LIMIT - TEMPERATURE_WARNING_TOLERANCE) {
        printf("Warning: Approaching upper temperature limit!\n");
    }
    return 1;
}
