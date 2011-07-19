#include "FuzzySet.h"

class FuzzyRule {
	public:
		FuzzyRule();
		FuzzyRule(FuzzySet f1, FuzzySet f2, FuzzySet out);

	private:
		FuzzySet fuzzySet1;
		FuzzySet fuzzySet2;
		FuzzySet output;

		int op; // Operator;
};

