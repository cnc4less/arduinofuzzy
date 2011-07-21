#include "FuzzyComposition.h"

void FuzzyComposition::init(){
	index = 0;
}

FuzzyComposition::FuzzyComposition(){
	init();
}

void FuzzyComposition::addPoint(float point, float pertinance){
	points[index][0] = point;
	points[index][1] = pertinance;
	index = index + 1;
}

void FuzzyComposition::addPointByIndex(int i, float point, float pertinance){
	points[i][0] = point;
	points[i][1] = pertinance;
}

float FuzzyComposition::getPoint(int i){
	float retorno = 0.0;
	if (i <= index ){
		retorno = points[i][0];
	}

	return retorno;
}

float FuzzyComposition::getPertinance(int i){
	float retorno = 0.0;
	if (i <= index ){
		retorno = points[i][1];
	}

	return retorno;
}

int FuzzyComposition::getLength(){
	return index;
}

