#include "Fuzzy.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>



Fuzzy::Fuzzy(int number){
	number_input_var = number;
	indexRule = 0;

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

void Fuzzy::evaluate(){

	for (int i=0; i < MAX_NUMBER_OF_RULES; i++){
		FuzzyRule f = baseRules[i];
		f.evaluate();
	}
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
		fuzzySet.setPertinance(pertinance);
	}
}

float Fuzzy::getFuzzification(int indexInput, int indexSet){
	return resultFuzzyfication[indexInput][indexSet];
}

void Fuzzy::addRule(FuzzyRule rule){
	if (indexRule < MAX_NUMBER_OF_RULES){
		baseRules[indexRule] = rule;
		indexRule = indexRule + 1;
	}
}

void Fuzzy::truncate(){
	float a,b,c,d, slope = 0.0;
	float pertinanceMax = 0.0;

	for (int i=0; i < MAX_NUMBER_OF_RULES; i++){
		FuzzyRule f = baseRules[i];
		if (f.getFired() == 1){ //The rule was fired


			FuzzySet set1 = f.getFuzzySet1();
			FuzzySet set2 = f.getFuzzySet2();
			FuzzySet output = f.getOutput();

			a = output.getPointA();
			b = output.getPointB();
			c = output.getPointC();
			d = output.getPointD();

			if (set1.getPertinance() > set2.getPertinance()){
				pertinanceMax = set1.getPertinance();
			}else{
				pertinanceMax = set2.getPertinance();
			}

			float pointT1 = 0.0, pointT2 = 0.0;

			//Now, we have to discover the points basead on the pertinanceMax
			slope = 1 / (b - a);
			pointT1 = (pertinanceMax - 1 + slope * b) / slope;
			f.setPointT1(pointT1);

			slope = 1 / (b - a);
			pointT2 = (pertinanceMax - 1 + slope * c) / slope;
			f.setPointT2(pointT2);
		}
	}
}

FuzzyRule Fuzzy::getFuzzyRule(int index){
	return baseRules[index];
}

