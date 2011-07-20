#define MAX_NUMBER_OF_POINTS 10
class FuzzyComposition{

	public:
		FuzzyComposition();
		void addPoint(float point);
		float getPoint(int index);

	private:
		void init();
		float points[MAX_NUMBER_OF_POINTS];
		int index;
};

