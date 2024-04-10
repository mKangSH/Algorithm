#include <iostream>
using namespace std;

int main()
{
	int a1, a0;
	int c, n0;

	cin >> a1 >> a0 >> c >> n0;

	if (c == 0 && a1 == 0 && a0 == 0)
	{
		cout << "1";
		return 0;
	}
	if (a1 == c)
	{
		if (a0 <= 0)
		{
			cout << "1";
			return 0;
		}
	}

	int meetN = 0;
	// ±³Á¡
	meetN = -(a0 / (a1 - c));
	if (n0 >= meetN)
	{
		if (c >= a1)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	else
	{
		cout << "0";
	}

	return 0;
}