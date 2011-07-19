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

