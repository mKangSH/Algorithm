#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int x, y, count = 1, n = 1, d = 1 ,T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;

		d = sqrt(y - x);

		if (pow(d, 2) == y - x)
			count = 2 * d - 1;
		else
			count = 2 * d;

		if (y - x > d * (d + 1))
			count++;

		cout << count << endl;
	}
}