#include <inttypes.h>
#include "FuzzyRule.h"

#define MAX_NUMBER_OF_INPUTS 2
#define MAX_NUMBER_OF_FUZZY_SETS 4

class Fuzzy {

	public:
		Fuzzy(int number_input_var);

		void setFuzzySetsInput(int index, int indexSet, FuzzySet f);

	private:
		int number_input_var;

		FuzzySet fuzzySetsInput[MAX_NUMBER_OF_INPUTS+1][MAX_NUMBER_OF_FUZZY_SETS];
};

