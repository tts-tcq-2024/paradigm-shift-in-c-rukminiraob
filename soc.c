#include <stdio.h>
#include "soc.h"

#define SOC_UPPER_LIMIT 80
#define SOC_LOWER_LIMIT 20
#define SOC_WARNING_TOLERANCE 4 // 5% of 80

// Function to check if the SoC is out of range
int isSocOutOfRange(float soc) {
    if (soc < SOC_LOWER_LIMIT) {
        printf("State of Charge out of range!\n");
        return 1;
    }
    return 0;
}

// Function to check if SoC is approaching discharge
void checkSocLowerWarning(float soc) {
    if (soc <= SOC_LOWER_LIMIT + SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching discharge limit!\n");
    }
}

// Function to check if SoC is approaching charge-peak
void checkSocUpperWarning(float soc) {
    if (soc >= SOC_UPPER_LIMIT - SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching charge-peak!\n");
    }
}

// Main function that integrates all checks
int socIsOk(float soc) {
    if (isSocOutOfRange(soc)) {
        return 0;
    }
    checkSocLowerWarning(soc);
    checkSocUpperWarning(soc);
    return soc <= SOC_UPPER_LIMIT;
}
