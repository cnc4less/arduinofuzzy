#include <inttypes.h>
#include "FuzzyRule.h"
#include "FuzzyComposition.h"

#define MAX_NUMBER_OF_INPUTS 2
#define MAX_NUMBER_OF_FUZZY_SETS 4
#define MAX_NUMBER_OF_RULES 16

class Fuzzy {

	public:
		Fuzzy(int number_input_var);

		void setFuzzySetsInput(int index, int indexSet, FuzzySet* f);
		void setInputs(int index, float value);
		void addRule(FuzzyRule rule);
		void fuzzify(int indexInput);
		float getFuzzification(int indexInput, int indexSet);
		void evaluate();
		void truncate();
		float desfuzzify();
		FuzzyRule getFuzzyRule(int index);

	private:
		int number_input_var;

		FuzzySet* fuzzySetsInput[MAX_NUMBER_OF_INPUTS+1][MAX_NUMBER_OF_FUZZY_SETS];

		//Crisp Inputs
		float inputs[MAX_NUMBER_OF_INPUTS];

		//In this array, we must keep the pertinence for each fuzzy set
		float resultFuzzyfication[MAX_NUMBER_OF_INPUTS+1][MAX_NUMBER_OF_FUZZY_SETS];

		FuzzyRule baseRules[MAX_NUMBER_OF_RULES];
                void reOrderBaseRules();
		int indexRule;
		FuzzyComposition composition;
		float discretize(int quant);
};

