#include "Fuzzy.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>



Fuzzy::Fuzzy(int number){
	number_input_var = number;

	//Initialize all arrays with NULL
	for (int i = 0; i < MAX_NUMBER_OF_INPUTS+1; i++){
		inputs[i] = NULL;
		for (int k = 0; k < MAX_NUMBER_OF_FUZZY_SETS; k++){
			resultFuzzyfication[i][k] = NULL;
			//fuzzySetsInput[i][k] = NULL;
		}
	}
}
/*************************************************************************************************************************************************************************************/

void Fuzzy::setFuzzySetsInput(int index, int indexSet, FuzzySet f){
	fuzzySetsInput[index][indexSet] = f;
	f.setIndex(index);
}

void Fuzzy::setInputs(int index, float value){
	inputs[index] = value;
}

float Fuzzy::evaluate(){
	return 0.0;
}

void Fuzzy::fuzzify(int indexInput){
	FuzzySet fuzzySet;
	float a,b,c,d,slope,pertinance;
	float crispInput = inputs[indexInput];

	for (int i = 0; i < MAX_NUMBER_OF_FUZZY_SETS; i++){
		fuzzySet = fuzzySetsInput[indexInput][i];

		a = fuzzySet.getPointA();
		b = fuzzySet.getPointB();
		c = fuzzySet.getPointC();
		d = fuzzySet.getPointD();

		if (crispInput >= a and crispInput < b){
			slope = 1 / (b - a);
			pertinance = slope * (crispInput - b) + 1;
		}else if (crispInput >= b and crispInput <= c){
			pertinance = 1;
		}else{
			slope = 1 / (c - d);
			pertinance = slope * (crispInput - c) + 1;
		}

		resultFuzzyfication[indexInput][i] = pertinance;
	}
}

float Fuzzy::getFuzzification(int indexInput, int indexSet){
	return resultFuzzyfication[indexInput][indexSet];
}

