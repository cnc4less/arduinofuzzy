#include <iostream>
#include "Fuzzy.h"

using namespace std;

int main(){
	Fuzzy fuzzy(1);
	//Fuzzy Sets -  Input 1 - Velocidade
  	FuzzySet velocidadeBaixa(0.0, 0.0, 30, 60);
  	FuzzySet velocidadeMedia(30, 60, 60, 90);
  	FuzzySet velocidadeAlta(60, 90, 100, 100);

  	//Index 0 - Input - Velocidade
  	fuzzy.setFuzzySetsInput(0, 0, velocidadeBaixa);   //Set 0
  	fuzzy.setFuzzySetsInput(0, 1, velocidadeMedia);   //Set 1
  	fuzzy.setFuzzySetsInput(0, 2, velocidadeAlta);   //Set 2


  	//Fuzzy Sets - Output - Consumo
  	FuzzySet consumoAlto(0.0, 0.0, 3, 6);
  	FuzzySet consumoMedio(3, 6, 6, 9);
  	FuzzySet consumoBaixo(6, 9, 10, 10);


  	//Index 2 - Output
  	fuzzy.setFuzzySetsInput(1, 0,consumoAlto);
  	fuzzy.setFuzzySetsInput(1, 1, consumoMedio);
  	fuzzy.setFuzzySetsInput(1, 2, consumoBaixo);

  	//Rules Base
  	FuzzyRule rule1(velocidadeBaixa, consumoMedio);
  	FuzzyRule rule2(velocidadeMedia, consumoBaixo);
  	FuzzyRule rule3(velocidadeAlta, consumoAlto);


  	fuzzy.addRule(rule1);
 	fuzzy.addRule(rule2);
  	fuzzy.addRule(rule3);


  	//Definindo o valor crisp da Velocidade
  	fuzzy.setInputs(0,40);

	//Fuzzificando
	fuzzy.fuzzify(0);

	float pertinenciaVelocidadeBaixa = fuzzy.getFuzzification(0,0);
	float pertinenciaVelocidadeMedia = fuzzy.getFuzzification(0,1);
	float pertinenciaVelocidadeAlta = fuzzy.getFuzzification(0,2);

	cout << "Pertinências...: \n\n";
	cout << "Velocidade Baixa: ";
	cout << pertinenciaVelocidadeBaixa;
	cout << "\n";

	cout << "Velocidade Media: ";
	cout << pertinenciaVelocidadeMedia;
	cout << "\n";

	cout << "Velocidade Alta: ";
	cout << pertinenciaVelocidadeAlta;
	cout << "\n";
	return 0;
}

