#include "Fuzzy.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "WProgram.h"



Fuzzy::Fuzzy(int number){
	number_input_var = number;
}
/*************************************************************************************************************************************************************************************/

void Fuzzy::setFuzzySetsInput(int index, int indexRule, FuzzySet f){
	fuzzySetsInput[index][indexRule] = f;
}

