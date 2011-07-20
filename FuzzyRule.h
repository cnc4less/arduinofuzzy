#include "FuzzySet.h"

class FuzzyRule {
	public:
		FuzzyRule();
		FuzzyRule(FuzzySet f1, FuzzySet f2, FuzzySet out);
		void evaluate();
		int getFired();
		FuzzySet getFuzzySet1();
		FuzzySet getFuzzySet2();
		FuzzySet getOutput();
		void setPointT1(float t1);
		void setPointT2(float t2);
		float getPointT1();
		float getPointT2();

	private:
		void init();
		FuzzySet fuzzySet1;
		FuzzySet fuzzySet2;
		FuzzySet output;

		int op; // Operator;
		int fired; //Was the rule fired???
		float _pointT1;
		float _pointT2;
};

