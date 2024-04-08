#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> x, y;
	for (int i = 0; i < 3; i++)
	{
		int pointX, pointY;
		cin >> pointX >> pointY;

		x.push_back(pointX);
		y.push_back(pointY);

		int size = x.size();
		for (int j = 0; j < size - 1; j++)
		{
			if (pointX == x[j])
			{
				x.erase(x.end() - 1);
				x.erase(x.begin() + j);
				size -= 2;
			}
		}

		size = y.size();
		for (int j = 0; j < size - 1; j++)
		{
			if (pointY == y[j])
			{
				y.erase(y.end() - 1);
				y.erase(y.begin() + j);
				size -= 2;
			}
		}
	}

	cout << x[0] << " " << y[0];
}