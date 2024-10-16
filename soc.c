#include <stdio.h>
#include "soc.h"

#define SOC_UPPER_LIMIT 80
#define SOC_LOWER_LIMIT 20
#define SOC_WARNING_TOLERANCE 4 // 5% of 80

int socIsOk(float soc) {
    if (soc < SOC_LOWER_LIMIT) {
        printf("State of Charge out of range!\n");
        return 0;
    } else if (soc <= SOC_LOWER_LIMIT + SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching discharge limit!\n");
    } else if (soc >= SOC_UPPER_LIMIT - SOC_WARNING_TOLERANCE) {
        printf("Warning: Approaching charge-peak!\n");
    }
    return (soc <= SOC_UPPER_LIMIT);
}
