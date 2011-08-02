#include "../Fuzzy.h"
#include "gtest/gtest.h"

TEST(FuzzySet, fuzzyset) {
  	FuzzySet* velocidadeBaixa = new FuzzySet(0.0, 0.0, 30, 60);

  	float pertinance = velocidadeBaixa->getPertinance();

  	EXPECT_EQ(0, pertinance);
}

TEST(FuzzySet, fuzzyset_isvalid) {
  	FuzzySet* velocidadeBaixa = new FuzzySet(0.0, 0.0, 30, 60);

  	bool isValid = velocidadeBaixa->isValid();

  	EXPECT_TRUE(isValid);
}


class FuzzyTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
 		fuzzy = new Fuzzy(1);
    	//Fuzzy Sets -  Input 0 - Velocidade
	  	FuzzySet* velocidadeBaixa = new FuzzySet(0.0, 0.0, 30, 60);
	  	FuzzySet* velocidadeMedia = new FuzzySet(30, 60, 60, 90);
	  	FuzzySet* velocidadeAlta = new FuzzySet(60, 90, 100, 100);

	  	//Index 0 - Input - Velocidade
	  	fuzzy->addFuzzySet(0, 0, velocidadeBaixa);   //Set 0
	  	fuzzy->addFuzzySet(0, 1, velocidadeMedia);   //Set 1
	  	fuzzy->addFuzzySet(0, 2, velocidadeAlta);   //Set 2

	  	//Fuzzy Sets - Output - Consumo
	  	FuzzySet* consumoAlto = new FuzzySet(0.0, 0.0, 3, 6);
	  	FuzzySet* consumoMedio = new FuzzySet(3, 6, 6, 9);
	  	FuzzySet* consumoBaixo = new FuzzySet(6, 9, 10, 10);


	  	//Index 2 - Output
	  	fuzzy->addFuzzySet(2, 0,consumoAlto);
	  	fuzzy->addFuzzySet(2, 1, consumoMedio);
	  	fuzzy->addFuzzySet(2, 2, consumoBaixo);

	  	//Rules Base
		FuzzyRule rule1(velocidadeMedia, consumoBaixo);
	  	FuzzyRule rule2(velocidadeBaixa, consumoMedio);
	  	FuzzyRule rule3(velocidadeAlta, consumoAlto);


	  	fuzzy->addRule(rule1);
	 	fuzzy->addRule(rule2);
	  	fuzzy->addRule(rule3);
  }

  // virtual void TearDown() {}

  Fuzzy* fuzzy;
};

TEST_F(FuzzyTest, fuzzificar){
    //Definindo o valor crisp da Velocidade
    fuzzy->setInputs(0, 40);

    //Fuzzificando
    fuzzy->fuzzify(0);

    float pertinenciaVelocidadeBaixa = fuzzy->getFuzzification(0, 0);
    float pertinenciaVelocidadeMedia = fuzzy->getFuzzification(0, 1);
    float pertinenciaVelocidadeAlta = fuzzy->getFuzzification(0, 2);

    EXPECT_FLOAT_EQ(0.66666663, pertinenciaVelocidadeBaixa);
    EXPECT_FLOAT_EQ(0.33333331, pertinenciaVelocidadeMedia);
    EXPECT_FLOAT_EQ(0, pertinenciaVelocidadeAlta);

}

TEST_F(FuzzyTest, fuzzificarMedio){
    //Definindo o valor crisp da Velocidade
    fuzzy->setInputs(0, 60);

    //Fuzzificando
    fuzzy->fuzzify(0);

    EXPECT_FLOAT_EQ(0, fuzzy->getFuzzification(0, 0));
    EXPECT_FLOAT_EQ(1, fuzzy->getFuzzification(0, 1));
    EXPECT_FLOAT_EQ(0, fuzzy->getFuzzification(0, 2));

}

TEST_F(FuzzyTest, testarValorAcimaDoLimiteUltimoConjunto){
    //Definindo o valor crisp da Velocidade
    fuzzy->setInputs(0, 101);

    //Fuzzificando
    fuzzy->fuzzify(0);

    EXPECT_FLOAT_EQ(0, fuzzy->getFuzzification(0, 0));
    EXPECT_FLOAT_EQ(0, fuzzy->getFuzzification(0, 1));
    EXPECT_FLOAT_EQ(1, fuzzy->getFuzzification(0, 2));
}

TEST_F(FuzzyTest, testarFuzzificationComDuasEntradas){

	Fuzzy* fuzzy2 = new Fuzzy(2);
	
    //Fuzzy Sets -  Input 0 - Velocidade
	FuzzySet* velocidadeBaixa = new FuzzySet(0.0, 0.0, 30, 60);
	FuzzySet* velocidadeMedia = new FuzzySet(30, 60, 60, 90);
	FuzzySet* velocidadeAlta = new FuzzySet(60, 90, 100, 100);

	//Index 0 - Input - Velocidade
	fuzzy2->addFuzzySet(0, 0, velocidadeBaixa);   //Set 0
	fuzzy2->addFuzzySet(0, 1, velocidadeMedia);   //Set 1
	fuzzy2->addFuzzySet(0, 2, velocidadeAlta);   //Set 2
	
	//Fuzzy Sets -  Input 1 - Distância
	FuzzySet* distanciaPequena = new FuzzySet(0.0, 0.0, 15, 30);
	FuzzySet* distanciaMedia = new FuzzySet(15, 30, 30, 45);
	FuzzySet* distanciaGrande = new FuzzySet(30, 45, 100, 100);

	//Index 1 - Input - Distância
	fuzzy2->addFuzzySet(1, 0, distanciaPequena);   //Set 0
	fuzzy2->addFuzzySet(1, 1, distanciaMedia);   //Set 1
	fuzzy2->addFuzzySet(1, 2, distanciaGrande);   //Set 2

	//Fuzzy Sets - Output - Consumo
	FuzzySet* frearPouco = new FuzzySet(0.0, 0.0, 3, 6);
	FuzzySet* frearMedio = new FuzzySet(3, 6, 6, 9);
	FuzzySet* frearMuito = new FuzzySet(6, 9, 10, 10);


	//Index 2 - Output
	fuzzy2->addFuzzySet(2, 0,frearPouco);
	fuzzy2->addFuzzySet(2, 1, frearMedio);
	fuzzy2->addFuzzySet(2, 2, frearMuito);
 	//Rules Base
	FuzzyRule rule1(velocidadeBaixa, distanciaPequena, frearMuito);
  	FuzzyRule rule2(velocidadeBaixa, distanciaMedia, frearMedio);
  	FuzzyRule rule3(velocidadeAlta, distanciaGrande, frearPouco);


  	fuzzy2->addRule(rule1);
 	fuzzy2->addRule(rule2);
  	fuzzy2->addRule(rule3);
  	
  	
  	/****************************/
  		
  	//Definindo o valor crisp da Velocidade
    fuzzy2->setInputs(0, 60);
    
    //Definindo o valor crisp da Distancia
    fuzzy2->setInputs(1, 30);

    //Fuzzificando
    fuzzy2->fuzzify(0);
    fuzzy2->fuzzify(1);

    EXPECT_FLOAT_EQ(0, fuzzy2->getFuzzification(1, 0));
    EXPECT_FLOAT_EQ(1, fuzzy2->getFuzzification(1, 1));
    EXPECT_FLOAT_EQ(0, fuzzy2->getFuzzification(1, 2));
	/********/
	    
 

	/****************************/
	
    fuzzy2->setInputs(1, 37);	
    fuzzy2->fuzzify(1);
    
    EXPECT_FLOAT_EQ(0, fuzzy2->getFuzzification(1, 0));
    EXPECT_FLOAT_EQ(0.5333333, fuzzy2->getFuzzification(1, 1));
    EXPECT_FLOAT_EQ(0.46666664, fuzzy2->getFuzzification(1, 2)); 
    /***************************/
    
    
    fuzzy2->setInputs(0, 50);
    fuzzy2->setInputs(1, 29);
	
	fuzzy2->fuzzify(0);
    fuzzy2->fuzzify(1);	    
    fuzzy2->evaluate();
    
    float freio = fuzzy2->desfuzzify();
    
    EXPECT_FLOAT_EQ(6.1111112, freio); 	
	
}
