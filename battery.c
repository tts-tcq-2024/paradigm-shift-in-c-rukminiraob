#include "battery.h"
#include "soc.h"
#include "charge_rate.h"
#include "temperature.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int tempOk = temperatureIsOk(temperature);
    int socOk = socIsOk(soc);
    int chargeRateOk = chargeRateIsOk(chargeRate);

    return tempOk && socOk && chargeRateOk;
}
