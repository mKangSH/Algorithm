#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Matrix
{
public:
	Matrix(int rows, int cols);
	void PrintAllElement();

	vector<T>& operator[] (int idx)
	{
		if (idx < 0 || idx >= this->rows)
		{
			cout << "Array index of bound exception" << endl;
			exit(1);
		}

		return mat[idx];
	}

	Matrix<T> operator+(Matrix<T> m)
	{
		Matrix<T> ret(rows, cols);

		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < cols; x++)
			{
				ret[y][x] = mat[y][x] + m[y][x];
			}
		}

		return ret;
	}

private:
	vector<vector<T>> mat;
	int rows;
	int cols;
};

template<typename T>
Matrix<T>::Matrix(int rows, int cols)
{
	this->mat.reserve(rows * cols);

	for (int y = 0; y < rows; y++)
	{
		vector<T> column; 
		for (int x = 0; x < cols; x++)
		{
			T defaultValue;
			column.push_back(defaultValue);
		}

		this->mat.push_back(column);
	}

	this->rows = rows;
	this->cols = cols;
}

template<typename T>
void Matrix<T>::PrintAllElement()
{
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			cout << this->mat[y][x] << " ";
		}

		cout << '\n';
	}
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	Matrix<int> mat1(rows, cols);
	Matrix<int> mat2(rows, cols);

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			int xElement;
			cin >> xElement;

			mat1[y][x] = xElement;
		}
	}

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			int xElement;
			cin >> xElement;

			mat2[y][x] = xElement;
		}
	}

	Matrix<int> ret = mat1 + mat2;
	ret.PrintAllElement();

	return 0;
}