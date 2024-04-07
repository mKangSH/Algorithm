#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
	Matrix(int rows, int cols);
	vector<int>& operator[](int idx)
	{
		if (idx < 0 || idx >= rows)
		{
			cout << "Array index of bound exception" << endl;
			exit(1);
		}

		return elements[idx];
	}



private:
	vector<vector<int>> elements;
	int rows;
	int cols;
};

Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;

	elements.reserve(rows * cols);
	elements.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		vector<int> xElements(cols);
		this->elements[i] = xElements;
	}
	int stop = 1;
}

typedef struct PosInfo
{
	int y;
	int x;
	int value;
}PosInfo;

int main()
{
	const int rows = 9;
	const int cols = 9;

	Matrix mat(rows, cols);
	PosInfo maxValue = { -1, -1, -1 };

	for(int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			int element;
			cin >> element;
			mat[y][x] = element;

			if (maxValue.value < element)
			{
				maxValue.value = element;
				maxValue.y = y + 1;
				maxValue.x = x + 1;
			}
		}
	}

	cout << maxValue.value << endl;
	cout << maxValue.y << " " << maxValue.x;

	return 0;
}