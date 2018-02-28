using namespace std;

class Calc
{
	private:

	public:
		Calc();
		~Calc();

		int* checkRows(int**& board);
		int* checkColumns(int**& board);
		int* checkGrids(int**& board);
};