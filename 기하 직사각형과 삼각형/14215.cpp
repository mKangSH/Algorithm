#include <iostream>
using namespace std;

int main()
{
	int side1, side2, side3;

	int maxSide = 0;

	cin >> side1 >> side2 >> side3;

	maxSide = max(side1, max(side2, side3));
	if (side1 + side2 + side3 - maxSide <= maxSide)
	{
		cout << (2 * (side1 + side2 + side3 - maxSide)) - 1;
	}
	else
	{
		cout << side1 + side2 + side3;
	}

	return 0;
}