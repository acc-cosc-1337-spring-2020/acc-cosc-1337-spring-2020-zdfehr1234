#include "temperature_data.h"
#include <iostream>

using std::cout;

int main() 
{
	vector<Temperature> out_temps{ Temperature(1, 98.9), Temperature(2, 99.5), Temperature(3, 99) };

	TemperatureData data;

	data.save_temps(out_temps);

	vector<Temperature> in_temps = data.get_temps();

	for (auto temp : in_temps)
	{
		cout << temp.get_hour() << " - " << temp.get_reading() << "\n";
	}
	return 0;
}

//** SAVE LOCATION **
// E:\GitHub\out\build\x64-Debug\test\classwork_test\01_assign_test