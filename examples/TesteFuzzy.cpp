#include <iostream>
#include "../Fuzzy.h"

using namespace std;

int main() {
	Fuzzy fuzzy(1);
	//Fuzzy Sets -  Input 1 - Distancia
	FuzzySet* veryShortD = new FuzzySet(0, 0, 2, 4);
	FuzzySet* shortD = new FuzzySet(2, 4, 4, 6);
	FuzzySet* mediumD = new FuzzySet(4, 6, 6, 8);
	FuzzySet* bigD = new FuzzySet(6, 8, 8, 10);
	FuzzySet* veryBigD = new FuzzySet(8, 10, 12, 12);

	//Index 0 - Input - Distancia
	fuzzy.addFuzzySet(0, 0, veryShortD); //Set 0
	fuzzy.addFuzzySet(0, 1, shortD); //Set 1
	fuzzy.addFuzzySet(0, 2, mediumD); //Set 2
	fuzzy.addFuzzySet(0, 3, bigD); //Set 2
	fuzzy.addFuzzySet(0, 4, veryBigD); //Set 2

	//Fuzzy Sets - Output - Consumo
	FuzzySet* veryShortW = new FuzzySet(0, 0, 0, 0.2);
	FuzzySet* shortW = new FuzzySet(0, 0.2, 0.2, 0.3);
	FuzzySet* mediumW = new FuzzySet(0.2, 0.3, 0.3, 0.6);
	FuzzySet* bigW = new FuzzySet(0.4, 0.6, 0.6, 1);
	FuzzySet* veryBigW = new FuzzySet(0.6, 1, 1, 1);

	//Index 2 - Output
	fuzzy.addFuzzySet(1, 0, veryShortW);
	fuzzy.addFuzzySet(1, 1, shortW);
	fuzzy.addFuzzySet(1, 2, mediumW);
	fuzzy.addFuzzySet(1, 3, bigW);
	fuzzy.addFuzzySet(1, 4, veryBigW);

	//Rules Base
	FuzzyRule rule0(veryShortD, veryShortW);
	FuzzyRule rule1(shortD, shortW);
	FuzzyRule rule2(mediumD, mediumW);
	FuzzyRule rule3(bigD, bigW);
	FuzzyRule rule4(veryBigD, veryBigW);

	fuzzy.addRule(rule0);
	fuzzy.addRule(rule1);
	fuzzy.addRule(rule2);
	fuzzy.addRule(rule3);
	fuzzy.addRule(rule4);

	//Definindo o valor crisp da Velocidade
	//for (float x = 11.0; x < 12; x = x + 1) {
        float x = 9;
		fuzzy.setInputs(0, x);

		//Fuzzificando
		fuzzy.fuzzify(0);

		fuzzy.evaluate();

		float pertinenciaLeituraMuitoPerto = fuzzy.getFuzzification(0, 0);
		float pertinenciaLeituraPerto = fuzzy.getFuzzification(0, 1);
		float pertinenciaLeituraMediaD = fuzzy.getFuzzification(0, 2);
		float pertinenciaLeituraLonge = fuzzy.getFuzzification(0, 3);
		float pertinenciaLeituraMuitoLonge = fuzzy.getFuzzification(0, 4);

		float saida0 = fuzzy.desfuzzify();

/*
		fuzzy.setInputs(1, saida0);

		//Fuzzificando
		fuzzy.fuzzify(1);

		fuzzy.evaluate();

		float pertinenciaLeituraMuitoBaixa = fuzzy.getFuzzification(1, 0);
		float pertinenciaLeituraBaixa = fuzzy.getFuzzification(1, 1);
		float pertinenciaLeituraMediaW = fuzzy.getFuzzification(1, 2);
		float pertinenciaLeituraAlta = fuzzy.getFuzzification(1, 3);
		float pertinenciaLeituraMuitoAlta = fuzzy.getFuzzification(1, 4);

		float saida1 = fuzzy.desfuzzify();

		/*
		cout << x;
		cout << ", ";
		cout << saida;
		*/

		cout << x;
		cout << " => ";
		cout << " {";
		cout << pertinenciaLeituraMuitoPerto;
		cout << ", ";
		cout << pertinenciaLeituraPerto;
		cout << ", ";
		cout << pertinenciaLeituraMediaD;
		cout << ", ";
		cout << pertinenciaLeituraLonge;
		cout << ", ";
		cout << pertinenciaLeituraMuitoLonge;
		cout << "}, ";
		/*
		cout << "{";
		cout << pertinenciaLeituraMuitoBaixa;
		cout << ", ";
		cout << pertinenciaLeituraBaixa;
		cout << ", ";
		cout << pertinenciaLeituraMediaW;
		cout << ", ";
		cout << pertinenciaLeituraAlta;
		cout << ", ";
		cout << pertinenciaLeituraMuitoAlta;
		cout << "}, ";
		*/
		cout << saida0;
		//cout << ", ";
		//cout << saida1;

		cout << "\n";
	//}
	return 0;
}

