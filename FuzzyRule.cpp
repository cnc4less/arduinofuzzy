#include "FuzzyRule.h"

FuzzyRule::FuzzyRule(){
	op = 0;
}

FuzzyRule::FuzzyRule(FuzzySet f1, FuzzySet f2, FuzzySet out){
	fuzzySet1 = f1;
	fuzzySet2 = f2;
	output = out;
	op = 0;
}

