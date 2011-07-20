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
	float pertinanceMax = 0.0, intersection = 0.0;

	//Previous Fuzzy Rule
	FuzzyRule* previousFuzzyRule = NULL;

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

			if (previousFuzzyRule == NULL){
				previousFuzzyRule = &f;
			}else{
				//Here, we have to compare the current FuzzyRule with the previous one;
				FuzzySet previousOutput = previousFuzzyRule->getOutput();
				float previousPertinance = f.getPertinance();

				//float bP = previousOutput.getPointB();
				//float cP = previousOutput.getPointC();

				float aP = previousOutput.getPointA();
				float bP = f.getPointT1();
				float cP = f.getPointT2();
				float dP = previousOutput.getPointD();

				//Now, we have to discover if there are intersects points
				if (a >= aP and a < bP){

				}else if (a >=bP and a < cP){
					if (output.getPertinance() > previousPertinance){
						//Now, we have to calculate the function of a-b

						slope = 1 / (b - a);
						intersection = (previousPertinance -1 + slope * b) / slope;
					}
				}else{

				}
			}
		}
	}
}

FuzzyRule Fuzzy::getFuzzyRule(int index){
	return baseRules[index];
}

