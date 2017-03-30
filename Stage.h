#pragma once
#include "Engine.h"
#include <vector>
#include <iostream>
#include <string>

const double gravConstant = 9.81;

class CStage
{
public:
	CStage(void);
	~CStage(void);

	void caclulateThrustCoefficient(void);
	void printCoefficients(void);
	void resetStage(void);

private:
	void getMassInitial(void);
	void getEngineConfiguration(void);

	double thrustMax;
	double massInitial;

	std::vector<CEngine> engines;
	std::vector<double> goalTWR;
	std::vector<double> actualTWR;
	std::vector<double> thrustCoefficients;
};

