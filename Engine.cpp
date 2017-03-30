#include "Engine.h"


CEngine::CEngine(void)
{
}


CEngine::~CEngine(void)
{
}

double CEngine::getThrustMax(void){
	return (thrustMax*(double)quantity);
}

void CEngine::setupEngine(void){
	int engineID = 0;
	printf("%s",std::string(25,'\n').c_str());
	printf("Choose an engine:\n");
	printf("1  - Flea\n");
	printf("2  - Hammer\n");
	printf("3  - Thumper\n");
	printf("4  - Kickback\n");
	printf("5  - Swivel\n");
	printf("6  - Reliant\n");
	printf("7  - Terrier\n");
	printf("8  - Skipper\n");
	printf("9  - Mainsail\n");
	printf("10 - Poodle\n");
	printf("11 - Thud\n");

	printf("\nEngine: ");

	bool goodChoice = false;
	int temp = 0;
	while (!goodChoice){
		std::cin >> temp;
		if ((temp < 1)||(temp > 11)){
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		} else {
			goodChoice = true;
		}
	}
	engineID = temp;

	printf("%s",std::string(25,'\n').c_str());
	printf("Quantity of engines: ");
	goodChoice = false;
	temp = 0;
	while (!goodChoice){
		std::cin >> temp;
		if (temp <= 0){
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		} else {
			goodChoice = true;
		}
	}

	quantity = temp;

	switch(engineID){
	case 1:
		name = "Flea";
		thrustMax = 162.909;
		specificImpulse = 140;
		fuelMass = 1.05;
		break;
	case 2:
		name = "Hammer";
		thrustMax = 197.897;
		specificImpulse = 170;
		fuelMass = 2.81;
		break;
	case 3:
		name = "Thumper";
		thrustMax = 250.0;
		specificImpulse = 175;
		fuelMass = 6.15;
		break;
	case 4:
		name = "Kickback";
		thrustMax = 593.864;
		specificImpulse = 195;
		fuelMass = 19.5;
		break;
	case 5:
		name = "Swivel";
		thrustMax = 167.969;
		specificImpulse = 250;
		fuelMass = 0.0;
		break;
	case 6:
		name = "Reliant";
		thrustMax = 205.161;
		specificImpulse = 265;
		fuelMass = 0.0;
		break;
	case 7:
		name = "Terrier";
		thrustMax = 14.783;
		specificImpulse = 85;
		fuelMass = 0.0;
		break;
	case 8:
		name = "Skipper";
		thrustMax = 586.75;
		specificImpulse = 280;
		fuelMass = 0.0;
		break;
	case 9:
		name = "Mainsail";
		thrustMax = 1379.032;
		specificImpulse = 285;
		fuelMass = 0.0;
		break;
	case 10:
		name = "Poodle";
		thrustMax = 64.286;
		specificImpulse = 90;
		fuelMass = 0.0;
		break;
	case 11:
		name = "Thud";
		thrustMax = 108.197;
		specificImpulse = 275;
		fuelMass = 0.0;
		break;
	default:
		break;
	}
}