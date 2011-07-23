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

float FuzzyComposition::discretize(int quant){
	float firstPoint = points[0][0];
	float lastPoint = getLastPoint();

	float maxPointT1 = 0.0, maxPointT2 = 0.0;
	float maxIndex = 0.0;
	for (int i = 0; i < index; i++){
		if (points[i][1] > maxIndex){
                        maxIndex = points[i][1];
			maxPointT1 = points[i][0];
			maxPointT2 = points[i+1][0];
		}
	}

	float razao = (lastPoint - firstPoint) / (quant - 1);
        float pos_ini = ((maxPointT1 - firstPoint) / razao) + 1;
        float vi = firstPoint + razao * (pos_ini - 1);
        
        float pos_fim = ((lastPoint - maxPointT2) / razao) + 1;
        float vf = firstPoint + razao * (pos_fim - 1);

	//float vi = firstPoint + razao * (maxPointT1 - 1);
	//float vf = firstPoint + razao * (maxPointT2 - 1);
	//float result = (quant(vf + vi)) / 2 * quant ;
        //float result = (vf + vi) / 2;
        float result = (maxPointT1 + maxPointT2) / 2;

	return result;
}

