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

void Fuzzy::setFuzzySetsInput(int index, int indexSet, FuzzySet* f){
	fuzzySetsInput[index][indexSet] = f;
	f->setIndex(index);
}

void Fuzzy::setInputs(int index, float value){
	inputs[index] = value;
}

void Fuzzy::evaluate(){

	//Evaluate the Rules; Mark the fired rules
	for (int i=0; i < indexRule; i++){
		FuzzyRule* f = &baseRules[i];
		f->evaluate();
	}

	//Truncate the outputs of the fired rules
	truncate();
}

void Fuzzy::fuzzify(int indexInput){
	FuzzySet* fuzzySet;
	float a,b,c,d,slope,pertinance;
	float crispInput = inputs[indexInput];

	for (int i = 0; i < MAX_NUMBER_OF_FUZZY_SETS; i++){
		pertinance = 0.0;
		slope = 0.0;
		fuzzySet = fuzzySetsInput[indexInput][i];

		a = fuzzySet->getPointA();
		b = fuzzySet->getPointB();
		c = fuzzySet->getPointC();
		d = fuzzySet->getPointD();

		if (crispInput >= a && crispInput < b){
			slope = 1 / (b - a);
			pertinance = slope * (crispInput - b) + 1;
		}else if (crispInput >= b && crispInput <= c){
			pertinance = 1;
		}else if (crispInput >c && crispInput <= d){
			slope = 1 / (c - d);
			pertinance = slope * (crispInput - c) + 1;
		}

		resultFuzzyfication[indexInput][i] = pertinance;
		fuzzySet->setPertinance(pertinance);
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
	FuzzyComposition previousFuzzyComposition;

	for (int i=0; i < indexRule; i++){
                FuzzyRule* f = &baseRules[i];
		if (f->getFired() == 1){ //The rule was fired

                        FuzzySet* set1 = f->getFuzzySet1();
			FuzzySet* set2 = f->getFuzzySet2();
			FuzzySet* output = f->getOutput();

			a = output->getPointA();
			b = output->getPointB();
			c = output->getPointC();
			d = output->getPointD();

                        pertinanceMax = set1->getPertinance(); //ok

                        if (set2 != 0){
                                if (set1->getPertinance() < set2->getPertinance()){
                                        pertinanceMax = set1->getPertinance();
                                }else{
                                        pertinanceMax = set2->getPertinance();
                                }
                        }
                        float pointT1 = 0.0, pointT2 = 0.0;

                        //Now, we have to discover the points based on the pertinanceMax
                        if ( b - a == 0){
                                pointT1 = b;
                        }else{
                                slope = 1 / (b - a);
                                pointT1 = (pertinanceMax + slope * a) / slope;
                        }
                        f->setPointT1(pointT1);

                        if (c - d == 0){
                                pointT2 = c;
                        }else{
                                slope = 1 / (c - d);
                                pointT2 = (pertinanceMax + slope * d) / slope;
                        }
                        
                        
            f->setPointT2(pointT2);

            if (previousFuzzyComposition.getLength() == 0) {
                previousFuzzyComposition.addPoint(a, 0);
                previousFuzzyComposition.addPoint(pointT1, pertinanceMax);
                previousFuzzyComposition.addPoint(pointT2, pertinanceMax);
                previousFuzzyComposition.addPoint(d, 0);
            } else {
                //Here, we have to compare the current FuzzyRule with the previous one;
                int quantPontos = previousFuzzyComposition.getLength();

                float pontoX = previousFuzzyComposition.getPoint(0);
                float pontoY = 0.0;
                for (int k = 1; k < quantPontos; k++) {
                        pontoY = previousFuzzyComposition.getPoint(k);
                        if (a >= pontoX and a <= pontoY) {
                                float previousPertinance = previousFuzzyComposition.getPertinance(1);
                                //Now, we have to calculate the function of a-b

                                slope = 1 / (b - a);
                                intersection = (previousPertinance - 1 + slope * b) / slope;


                                FuzzyComposition tempComposition;

                                for (int z = 0; z <= k - 1; z++) {
                                        tempComposition.addPoint(previousFuzzyComposition.getPoint(z), previousFuzzyComposition.getPertinance(z));
                                }
                                tempComposition.addPoint(intersection, previousPertinance);
                                tempComposition.addPoint(b, pertinanceMax);
                                tempComposition.addPoint(c, pertinanceMax);
                                tempComposition.addPoint(d, 0);

                                previousFuzzyComposition = tempComposition;
                                break;
                        }
                    pontoX = pontoY;
                }
            }
        }
     }
     composition = previousFuzzyComposition;       
}

FuzzyRule Fuzzy::getFuzzyRule(int index){
	return baseRules[index];
}

float Fuzzy::discretize(int quant){
	return composition.discretize(quant);
}

float Fuzzy::desfuzzify(){
	return discretize(10);
}

