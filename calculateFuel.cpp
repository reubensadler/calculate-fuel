#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inFile;
	inFile.open("");			//add path to Module masses.txt

	if (!inFile) {
		std::cerr << "Unable to open file module masses.txt";
		exit(1);			// call system to stop
	}

	int massX{};			// mass of module given in line X
	int fuelX{};			// fuel required for module X
	
	int totalFuel{};		// total fuel requirements
	int fuelFuel{};			// fuel required for last increment of fuel
	int totalFuelFuel{};	// fuel required for all previous fuel calculated for a module
			

	while (inFile >> massX)
	{	
		fuelX = massX / 3 - 2 ;		
		fuelFuel = fuelX;			
		totalFuelFuel = 0;		// set totalFuelFuel to 0 for this module
		
		//calculate total fuel required to move fuel and modules
		while ((fuelFuel / 3 - 2) > 0)						//if fuel required to move last increment of fuel is <0, stop
		{
			fuelFuel = fuelFuel / 3 - 2;
			totalFuelFuel = totalFuelFuel + fuelFuel;
		}
		
		totalFuel = totalFuel + totalFuelFuel + fuelX;
	}

	inFile.close();
	std::cout << "Fuel required = " << totalFuel << '\n';

	return 0;
}