#include "../Fuzzy.h"
#include "gtest/gtest.h"

TEST(FuzzyTest, fuzzyset) {

	Fuzzy fuzzy(1);
	//Fuzzy Sets -  Input 1 - Velocidade
  	FuzzySet* velocidadeBaixa = new FuzzySet(0.0, 0.0, 30, 60);

  	float pertinance = velocidadeBaixa->getPertinance();

  	EXPECT_EQ(0, pertinance);
}

TEST(FuzzyTest, fuzzyset_isvalid) {

	Fuzzy fuzzy(1);
	//Fuzzy Sets -  Input 1 - Velocidade
  	FuzzySet* velocidadeBaixa = new FuzzySet(0.0, 0.0, 30, 60);

  	bool isValid = velocidadeBaixa->isValid();

  	EXPECT_TRUE(isValid);
}

TEST(Fuzzy, fuzzificar){
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

    float pertinenciaVelocidadeBaixa = fuzzy.getFuzzification(0, 0);
    float pertinenciaVelocidadeMedia = fuzzy.getFuzzification(0, 1);
    float pertinenciaVelocidadeAlta = fuzzy.getFuzzification(0, 2);

    EXPECT_FLOAT_EQ(0.66666663, pertinenciaVelocidadeBaixa);
    EXPECT_FLOAT_EQ(0.33333331, pertinenciaVelocidadeMedia);
    EXPECT_FLOAT_EQ(0, pertinenciaVelocidadeAlta);

}

