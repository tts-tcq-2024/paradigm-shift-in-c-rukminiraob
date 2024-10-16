#include <stdio.h>
#include "temperature.h"

#define TEMPERATURE_UPPER_LIMIT 45
#define TEMPERATURE_LOWER_LIMIT 0
#define TEMPERATURE_WARNING_TOLERANCE 2.25 // 5% of 45

// Function to check if the temperature is out of range
int isTemperatureOutOfRange(float temperature) {
    if (temperature < TEMPERATURE_LOWER_LIMIT || temperature > TEMPERATURE_UPPER_LIMIT) {
        printf("Temperature out of range!\n");
        return 1;
    }
    return 0;
}

// Function to check if the temperature is approaching lower limit
void checkTemperatureLowerWarning(float temperature) {
    if (temperature <= TEMPERATURE_LOWER_LIMIT + TEMPERATURE_WARNING_TOLERANCE) {
        printf("Warning: Approaching lower temperature limit!\n");
    }
}

// Function to check if the temperature is approaching upper limit
void checkTemperatureUpperWarning(float temperature) {
    if (temperature >= TEMPERATURE_UPPER_LIMIT - TEMPERATURE_WARNING_TOLERANCE) {
        printf("Warning: Approaching upper temperature limit!\n");
    }
}

// Main function that integrates all checks
int temperatureIsOk(float temperature) {
    if (isTemperatureOutOfRange(temperature)) {
        return 0;
    }
    checkTemperatureLowerWarning(temperature);
    checkTemperatureUpperWarning(temperature);
    return 1;
}
