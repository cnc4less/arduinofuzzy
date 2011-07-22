#include <inttypes.h>

class FuzzySet {

	public:
		FuzzySet();
		FuzzySet(float a, float b, float c, float d);
		void setIndex(int index);
		float getPointA();
		float getPointB();
		float getPointC();
		float getPointD();
		void setPertinance(float pertinance);
		float getPertinance();
		bool isValid();


	private:
		float _a;
		float _b;
		float _c;
		float _d;
		int _index; // The variable index that contains this FuzzySet
		float _pertinance;
		void init();
};

