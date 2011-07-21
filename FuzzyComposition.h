#define MAX_NUMBER_OF_POINTS 10
class FuzzyComposition{

	public:
		FuzzyComposition();
		void addPoint(float point, float pertinance);
		void addPointByIndex(int i, float point, float pertinance);
		float getPoint(int index);
		float getPertinance(int index);
		int getLength();

	private:
		void init();

		//We have to keep the point and the pertinance of that point
		float points[MAX_NUMBER_OF_POINTS][2];
		int index;
};

