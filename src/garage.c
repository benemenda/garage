/* Created by MBaron 11/01/16 */

#include <stdio.h>
#include "optionGrabber.h"

int car[GARAGE_SIZE];

void getOption(int* selection);
void getCar(int* selection);

void initGarage(){
	int i;
	for(i = 0; i < GARAGE_SIZE; i++){
		car[i] = 0;
	}

}

int isInUse(int selectedCar){
	if(car[selectedCar] == 0){
		return 0;
	}
	else{
		return 1;
	}
}

void setInUse(int selectedCar){
	car[selectedCar] = 1;
}

void setNotInUse(int selectedCar){
	car[selectedCar] = 0;
}

int selectedCarInRange(int selectedCar){
	if (selectedCar > GARAGE_SIZE || selectedCar < 0){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	initGarage();
	while(1){
		printf("\nSelect an action: \n\t1:\tShow status of the garage\n\t2:\tCheck out a car\n\t3:\tCheck in a car\n\t4:\tExit\n");
		int selection; // used to hold user selection
		int selectedCar; // used to hold user selection of car
		getOption(&selection);
		switch(selection) {
			case 1:
				printf("Getting garage status:\n");
				int i;
				for(i = 0; i < GARAGE_SIZE; i++){
					int inUse = isInUse(i);
					if(inUse){
						printf("\tCar %d:\tOUT\n", i);
					}
					else{
						printf("\tCar %d:\tIN\n", i);
					}
				}
				break;
			case 2:
				printf("Select a car to check out (0-%d): ", GARAGE_SIZE-1);
				getCar(&selectedCar);
				if (selectedCarInRange(selectedCar)){
					if(isInUse(selectedCar)){
						printf("\tCar %d already in use", selectedCar);
					}
					else{
						setInUse(selectedCar);
						printf("\tCar %d checked out", selectedCar);
					}
				}
				else{
					printf("\tInvalid car selection: %d", selectedCar);
				}
				break;
			case 3:
				printf("Select a car to check in (0-%d): ", GARAGE_SIZE-1);
				getCar(&selectedCar);
				if (selectedCarInRange(selectedCar)){
					if(isInUse(selectedCar)){
						setNotInUse(selectedCar);
						printf("\tCar %d checked back in", selectedCar);
					}
					else{
						printf("\tCar %d is not in use", selectedCar);
					}
				}
				else{
					printf("\tInvalid car selection: %d", selectedCar);
				}
				break;
			case 4:
				printf("Exiting");
				return 1;
			default:
				printf("Invalid selection: %d", selection);
				break;
		}
		printf("\n");
	}
}
