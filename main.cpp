#include "Stage.h"

void printMenu(void);
int runMenu(void);

int main (void) {
	
	CStage firstStage;
	int menuChoice = 0;

	bool launchStage = true;
	while(launchStage){
		printMenu();
		menuChoice = runMenu();
		if (menuChoice == 1){
			firstStage.caclulateThrustCoefficient();
			firstStage.printCoefficients();
			system("PAUSE");
		} else {
			launchStage = false;
		}
	}

	return 0;
}

void printMenu(void){
	printf("%s",std::string(25,'\n').c_str());
	printf("Launch Stage Examination\n");
	printf("************************\n");
	printf(" 1 - New Stage\n");
	printf(" 2 - Exit\n");
	printf("\nChoice: ");
}

int runMenu(void){
	bool goodChoice = false;
	int choice = 0;

	while(!goodChoice){
		std::cin >> choice;
		if ((choice < 1)||(choice > 2)){
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		} else {
			goodChoice = true;
		}
	}

	return choice;
}