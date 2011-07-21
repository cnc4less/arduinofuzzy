all:
	gcc -c *.cpp
	g++ TesteFuzzy.cpp Fuzzy.o FuzzyComposition.o FuzzySet.o FuzzyRule.o -o TesteFuzzy

clean:
	rm *.o TesteFuzzy
