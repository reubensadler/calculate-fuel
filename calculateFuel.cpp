#include <iostream>
#include <fstream>

std::ifstream openFile()
{
	std::ifstream inFile;
	inFile.open("Module_Masses.txt");

	if (!inFile) {
		std::cerr << "Unable to open file module masses.txt";
		exit(1);			// call system to stop
	}
	return inFile;
}

int calculateFuel(std::ifstream &inFile)
{
	int moduleMass{};											// mass of current module
	int totalFuel{};											// total fuel requirements
	
	while (inFile >> moduleMass)
	{
		//Declare variables used in the calculation
		//Question says to round down, so integers are sufficient
		int fuelForModule{ moduleMass / 3 - 2 };				// fuel required to launch the module without the mass of fuel
		int fuelForFuel{ fuelForModule };						// fuel required for previous increment of fuel
		int totalFuelForFuel{ 0 };								// fuel required for all previous fuel calculated for a module

		//calculate total fuel required to move fuel and modules
		while ((fuelForFuel / 3 - 2) > 0)						//if fuel required to move last increment of fuel is <0, stop
		{
			fuelForFuel = fuelForFuel / 3 - 2;
			totalFuelForFuel = totalFuelForFuel + fuelForFuel;
		}

		totalFuel = totalFuel + totalFuelForFuel + fuelForModule;	//add the fuel required for this module to the total fuel so far
	}
	return totalFuel;
}

int main()
{
	std::ifstream inFile{ openFile() };

	int totalFuel{ calculateFuel(inFile) };

	inFile.close();
	
	std::cout << "Fuel required = " <<  totalFuel << '\n';

	return 0;
}