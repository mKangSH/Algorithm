#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int marbleCount;
	cin >> marbleCount;

	int minX = 10001, minY = 10001, maxX = -10001, maxY = -10001;
	for (int i = 0; i < marbleCount; i++)
	{
		int x, y;
		cin >> x >> y;

		minX = min(x, minX);
		minY = min(y, minY);

		maxX = max(x, maxX);
		maxY = max(y, maxY);
	}

	cout << (maxX - minX) * (maxY - minY);
}