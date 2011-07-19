#include "Fuzzy.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>



Fuzzy::Fuzzy(int number){
	number_input_var = number;
}
/*************************************************************************************************************************************************************************************/

void Fuzzy::setFuzzySetsInput(int index, int indexSet, FuzzySet f){
	fuzzySetsInput[index][indexSet] = f;
	f.setIndex(index);
}

void Fuzzy::setInputs(int index, float value){
	inputs[index] = value;
}

float Fuzzy::evaluate(int indexInput){
	FuzzySet fuzzySet;
	float a,b,c,d;
	// slope of the function
	for (int i = 0; i < MAX_NUMBER_OF_FUZZY_SETS; i++){
		fuzzySet = fuzzySetsInput[indexInput][i];




	}
	return 0.0;
}

