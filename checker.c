#include <stdio.h>
#include <assert.h>


int temperatureIsOk(float temperature) {
	return (!(temperature < 0 || temperature > 45)) ;
}


int socIsOk( float soc ) {
	return (!(soc < 20 || soc > 80));
}


int chargeRateIsOk( float chargeRate) {
	return (!(chargeRate > 0.8)); 
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
  int t_ok = temperatureIsOk(temperature);
  int s_ok = socIsOk(soc);
  int c_ok = chargeRateIsOk(chargeRate);	

	if( (t_ok + s_ok + c_ok) == 3)
		return 1;
        else 
		return 0;
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}


