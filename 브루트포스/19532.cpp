#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	// ax + by = c
	// dx + ey = f

	// |a b| |x| = |c|
	// |d e| |y| = |f|

	// a * d + b * d = c * d
	// d * a + e * a = f * a
	// ----------------------
	// y = (c * d - f * a) / (b * d - e * a)
	// x = (c - b * (c * d - f * a) / (b * d - e * a)) / a

	int y = 0;
	int x = 0;

	if (a != 0)
	{
		y = (c * d - f * a) / (b * d - e * a);
		x = (c - b * y) / a;

		cout << x << " " << y;
	}
	else
	{
		y = c / b;
		x = (f - e * y) / d;

		cout << x << " " << y;
	}
}