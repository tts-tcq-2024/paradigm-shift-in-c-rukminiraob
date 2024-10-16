#include <assert.h>
#include "battery.h"

int main() {
    assert(batteryIsOk(25, 70, 0.7));   // All parameters within range
    assert(!batteryIsOk(50, 85, 0));    // Temperature and SoC out of range
    assert(batteryIsOk(20, 21, 0.6));   // Edge case: lower limits for SoC
    return 0;
}
