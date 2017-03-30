#include "Stage.h"


CStage::CStage(void)
{
	goalTWR.push_back(1.00);
	goalTWR.push_back(1.25);
	goalTWR.push_back(1.50);
	goalTWR.push_back(2.00);

	thrustMax = 0.0;
	massInitial = 0.0;
}


CStage::~CStage(void)
{
}

void CStage::caclulateThrustCoefficient(void){
	double temp = 0.0;
	int tempTwo = 0;

	getMassInitial();
	getEngineConfiguration();

	for (int i = 0; i < engines.size(); i++){
		thrustMax = thrustMax + engines[i].getThrustMax();
	}

	for (int i = 0; i < goalTWR.size(); i++){
		temp = (goalTWR[i]*massInitial*gravConstant)/(thrustMax);
		tempTwo = (int)(1000*temp);
		if ((tempTwo%5)>0){
			tempTwo = (tempTwo/5)+1;
		} else {
			tempTwo = (tempTwo/5);
		}
		temp = (double)tempTwo * 0.5;
		thrustCoefficients.push_back(temp);
		actualTWR.push_back(((temp/100)*thrustMax)/(massInitial*gravConstant));
	}
}

void CStage::printCoefficients(void){
	//Print Stage Composition
	printf("%s",std::string(25,'\n').c_str());
	printf("Stage Composition:\n");
	for (int i = 0; i < engines.size(); i++){
		printf("%i - %s(s)\n",engines[i].getQuantity(),engines[i].getName().c_str());
	}
	printf("**********************\n\n");
	//Print Coefficients with corresponding TWR
	for (int i = 0; i < goalTWR.size(); i++){
		printf("TWR Goal: %.2f\tCoeff: %.1f\tTWR Real: %.2f\n",
			goalTWR[i],thrustCoefficients[i],actualTWR[i]);
	}
}

void CStage::resetStage(void){
	thrustMax = 0.0;
	massInitial = 0.0;

	for (int i = 0; i < engines.size(); i++){
		engines.pop_back();
	}

	for (int i = 0; i < actualTWR.size(); i++){
		actualTWR.pop_back();
		thrustCoefficients.pop_back();
	}
}

void CStage::getMassInitial(void){
	double temp = 0.0;
	bool goodChoice = false;

	printf("%s",std::string(25,'\n').c_str());
	printf("Enter initial mass of stage [t]: ");

	while(!goodChoice){
		std::cin >> temp;
		if (temp <= 0.0){
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		} else {
			goodChoice = true;
		}
	}

	massInitial = temp;
}

void CStage::getEngineConfiguration(void){
	bool configurationDone = false;
	bool goodChoice = false;
	int choice = 0;

	while (!configurationDone){
		printf("%s",std::string(25,'\n').c_str());
		printf("Stage Engine Configuration\n");
		printf("**************************\n");
		printf(" 1 - Add Engine\n");
		printf(" 2 - Finished\n");
		printf("**************************\n");
		printf("Command: ");
		
		while (!goodChoice){
			std::cin >> choice;
			if ((choice > 2)||(choice < 1)){
				std::cin.clear();
				std::cin.ignore(INT_MAX,'\n');
			} else {
				goodChoice = true;
			}
		}

		switch(choice){
		case 1:
			{
			//Create Engine
			engines.push_back(CEngine());
			int last = engines.size() - 1;
			engines[last].setupEngine();
			choice = 0;
			goodChoice = false;
			break;
			}
		case 2:
			//End Engine Configuration
			configurationDone = true;
			break;
		}

	}
}