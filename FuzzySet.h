#include <inttypes.h>

class FuzzySet {

	public:
		FuzzySet();
		FuzzySet(int a, int b, int c, int d);
		void setIndex(int index);

	private:
		int _a;
		int _b;
		int _c;
		int _d;
		int _index; // The variable index that contains this FuzzySet
};

