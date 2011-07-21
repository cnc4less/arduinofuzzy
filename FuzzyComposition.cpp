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

float FuzzyComposition::getLastPoint(){
	float retorno = points[index-1][0];

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

void FuzzyComposition::discretize(int quant){
	float firstPoint = points[0][0];
	float lastPoint = getLastPoint();

	float maxPointT1 = 0.0, maxPointT2 = 0.0;
	int maxIndex = 0.0;
	for (int i = 0; i < index; i++){
		if (points[i][1] > maxIndex){
			maxPointT1 = points[i][0];
			maxPointT2 = points[i+1][0];
		}
	}

	float razao = (firstPoint - lastPoint) / (quant - 1);

	float vi = firstPoint + razao * (maxPointT1 - 1);
	float vf = firstPoint + razao * (maxPointT2 - 1);
	float result = (quant * (vi + vf)) / 2 * quant;
}

