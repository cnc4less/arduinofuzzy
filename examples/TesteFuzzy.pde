#include <Fuzzy.h>

int teste = 0;
int ledPin = 13;
int tamanho = 100;
int v = 10;

Fuzzy fuzzy(1);

//Fuzzy Sets -  Input 1 - Velocidade
FuzzySet velocidadeBaixa(0.0, 0.0, 30, 60); 
FuzzySet velocidadeMedia(30, 60, 60, 90);
FuzzySet velocidadeAlta(60, 90, 100, 100);

//Fuzzy Sets - Output - Consumo
FuzzySet consumoAlto(0.0, 0.0, 3, 6); 
FuzzySet consumoMedio(3, 6, 6, 9); 
FuzzySet consumoBaixo(6, 9, 10, 10);

void setup(){
  Serial.begin(9600);
  Serial.println("Ola mundo");  
  pinMode(ledPin, OUTPUT);
  
  
  //Index 0 - Input - Velocidade
  fuzzy.setFuzzySetsInput(0, 0, &velocidadeBaixa);   //Set 1
  fuzzy.setFuzzySetsInput(0, 1, &velocidadeMedia);   //Set 2
  fuzzy.setFuzzySetsInput(0, 2, &velocidadeAlta);   //Set 3
  
  
  //Index 2 - Output
  fuzzy.setFuzzySetsInput(1, 0, &consumoAlto);
  fuzzy.setFuzzySetsInput(1, 1, &consumoMedio);
  fuzzy.setFuzzySetsInput(1, 2, &consumoBaixo);
  
  //Rules Base
  FuzzyRule rule1(&velocidadeBaixa, &consumoMedio);
  FuzzyRule rule2(&velocidadeMedia, &consumoBaixo);
  FuzzyRule rule3(&velocidadeAlta, &consumoAlto);
  
  fuzzy.addRule(rule1);
  fuzzy.addRule(rule2);
  fuzzy.addRule(rule3);
}

void loop(){ 

 if (v > 100){
   v = 10;
 }
 fuzzy.setInputs(0,v);
 
 fuzzy.fuzzify(0);
 
 fuzzy.evaluate();
 
 float saida = fuzzy.desfuzzify();
 
 Serial.print("Entrada: ");
 Serial.println(v);
 Serial.println(fuzzy.getFuzzification(0,0)); 
 Serial.println(fuzzy.getFuzzification(0,1));
 Serial.println(fuzzy.getFuzzification(0,2));
 Serial.println("-");
 Serial.print("Resultado: ");
 Serial.println(saida);
 Serial.println("---");
 Serial.println();
 
 v = v + 1;  
 delay(3000);
}
