#include "FuzzyComposition.h"

void FuzzyComposition::init(){
	index = 0;
}

FuzzyComposition::FuzzyComposition(){
	init();
}

void FuzzyComposition::addPoint(float point){
	points[index] = point;
	index = index + 1;
}

float FuzzyComposition::getPoint(int i){
	float retorno = 0.0;
	if (i <= index ){
		retorno = points[i];
	}

	return retorno;
}

