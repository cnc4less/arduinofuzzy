#define MAX_NUMBER_OF_POINTS 10
class FuzzyComposition{

	public:
		FuzzyComposition();
		void addPoint(float point, float pertinance);
		void addPointByIndex(int i, float point, float pertinance);
		float getPoint(int index);
		float getLastPoint();
		float getPertinance(int index);
		int getLength();
		float discretize(int quant);

	private:
		void init();

		//We have to keep the point and the pertinance of that point
		float points[MAX_NUMBER_OF_POINTS][2];
		int index;
};

