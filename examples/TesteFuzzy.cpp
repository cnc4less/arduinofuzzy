#include <iostream>
#include "../Fuzzy.h"

using namespace std;

int main(){
	Fuzzy fuzzy(1);
	//Fuzzy Sets -  Input 1 - Velocidade
  	FuzzySet* velocidadeBaixa = new FuzzySet(0.0, 0.0, 30, 60);
  	FuzzySet* velocidadeMedia = new FuzzySet(30, 60, 60, 90);
  	FuzzySet* velocidadeAlta = new FuzzySet(60, 90, 100, 100);

  	//Index 0 - Input - Velocidade
  	fuzzy.setFuzzySetsInput(0, 0, velocidadeBaixa);   //Set 0
  	fuzzy.setFuzzySetsInput(0, 1, velocidadeMedia);   //Set 1
  	fuzzy.setFuzzySetsInput(0, 2, velocidadeAlta);   //Set 2


  	//Fuzzy Sets - Output - Consumo
  	FuzzySet* consumoAlto = new FuzzySet(0.0, 0.0, 3, 6);
  	FuzzySet* consumoMedio = new FuzzySet(3, 6, 6, 9);
  	FuzzySet* consumoBaixo = new FuzzySet(6, 9, 10, 10);


  	//Index 2 - Output
  	fuzzy.setFuzzySetsInput(1, 0,consumoAlto);
  	fuzzy.setFuzzySetsInput(1, 1, consumoMedio);
  	fuzzy.setFuzzySetsInput(1, 2, consumoBaixo);

  	//Rules Base
        FuzzyRule rule1(velocidadeMedia, consumoBaixo);
  	FuzzyRule rule2(velocidadeBaixa, consumoMedio);
  	FuzzyRule rule3(velocidadeAlta, consumoAlto);


  	fuzzy.addRule(rule1);
 	fuzzy.addRule(rule2);
  	fuzzy.addRule(rule3);

        //Definindo o valor crisp da Velocidade
        fuzzy.setInputs(0, 40);

        //Fuzzificando
        fuzzy.fuzzify(0);

        fuzzy.evaluate();

        float pertinenciaVelocidadeBaixa = fuzzy.getFuzzification(0, 0);
        float pertinenciaVelocidadeMedia = fuzzy.getFuzzification(0, 1);
        float pertinenciaVelocidadeAlta = fuzzy.getFuzzification(0, 2);

        cout << "Pertinências...: \n\n";
        cout << "Velocidade Baixa: ";
        cout << pertinenciaVelocidadeBaixa;
        cout << "\n";

        cout << "Velocidade Media: ";
        cout << pertinenciaVelocidadeMedia;
        cout << "\n";

        cout << "Velocidade Alta.........: ";
        cout << pertinenciaVelocidadeAlta;
        cout << "\n";

        float resultado = fuzzy.desfuzzify();
        cout << "\nResultado..........: ";
        cout << resultado;
        cout << "\n";
	return 0;
}

