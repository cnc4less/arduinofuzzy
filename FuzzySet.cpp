#include "FuzzySet.h"


FuzzySet::FuzzySet(){
	_a = 0;
	_b = 0;
	_c = 0;
	_d = 0;
}

FuzzySet::FuzzySet(int a, int b, int c, int d){
	_a = a;
	_b = b;
	_c = c;
	_d = d;
}

void FuzzySet::setIndex(int index){
	_index = index;
}

