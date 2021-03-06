#include "FuzzySet.h"


FuzzySet::FuzzySet(){
	_a = 0.0;
	_b = 0.0;
	_c = 0.0;
	_d = 0.0;
	init();
}

FuzzySet::FuzzySet(float a, float b, float c, float d){
	_a = a;
	_b = b;
	_c = c;
	_d = d;
	init();
}

void FuzzySet::init(){
	_pertinance = 0.0;
}

void FuzzySet::setIndex(int index){
	_index = index;
}


float FuzzySet::getPointA(){
	return _a;
}

float FuzzySet::getPointB(){
	return _b;
}

float FuzzySet::getPointC(){
	return _c;
}

float FuzzySet::getPointD(){
	return _d;
}

void FuzzySet::setPertinance(float pertinance){
	_pertinance = pertinance;
}

float FuzzySet::getPertinance(){
	return _pertinance;
}

bool FuzzySet::isValid(){
	bool retorno = false;

	if (_a > 0 || _b > 0 || _c > 0 || _d > 0){
		retorno = true;
	}

	return retorno;
}

