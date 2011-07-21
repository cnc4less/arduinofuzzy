#include "FuzzyRule.h"

void FuzzyRule::init(){
	op = 0;
	fired = 0;
	_pointT1 = 0.0;
	_pointT2 = 0.0;
}

FuzzyRule::FuzzyRule(){
	init();
}

FuzzyRule::FuzzyRule(FuzzySet f1, FuzzySet f2, FuzzySet out){
	fuzzySet1 = f1;
	fuzzySet2 = f2;
	output = out;
	init();
}

FuzzyRule::FuzzyRule(FuzzySet f1, FuzzySet out){
	fuzzySet1 = f1;
	output = out;
	init();
}

void FuzzyRule::evaluate(){
	if (op == 0){ // 'E'
		if (fuzzySet1.getPertinance()>0 and (fuzzySet2.getPertinance()>0 or fuzzySet2.isValid() == 0)){
			fired = 1;
		}
	}
}

int FuzzyRule::getFired(){
	return fired;
}

FuzzySet FuzzyRule::getFuzzySet1(){
	return fuzzySet1;
}

FuzzySet FuzzyRule::getFuzzySet2(){
	return fuzzySet2;
}

FuzzySet FuzzyRule::getOutput(){
	return output;
}

void FuzzyRule::setPointT1(float t1){
	_pointT1 = t1;
}

void FuzzyRule::setPointT2(float t2){
	_pointT2 = t2;
}

float FuzzyRule::getPointT1(){
	return _pointT1;
}
float FuzzyRule::getPointT2(){
	return _pointT2;
}

float FuzzyRule::getPertinance(){
	float pertinance = 0.0;

	if (op == 0){
		if (fuzzySet1.getPertinance() > fuzzySet2.getPertinance()){
			pertinance = fuzzySet1.getPertinance();
		}else{
			pertinance = fuzzySet2.getPertinance();
		}
	}

	return pertinance;
}

