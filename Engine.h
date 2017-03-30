#pragma once
#include <string>
#include <iostream>

class CEngine
{
public:
	CEngine(void);
	~CEngine(void);

	double getThrustMax(void);
	void setupEngine(void);

	int getQuantity(void){return quantity;}
	std::string getName(void){return name;}


private:
	int quantity;
	std::string name;
	double thrustMax;
	double specificImpulse;
	double fuelMass;
};

