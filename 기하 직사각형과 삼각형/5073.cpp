#include <iostream>
#include <algorithm>
using namespace std;

void PrintTriType(int side1, int side2, int side3)
{
	if (side1 == side2 && side2 == side3)
	{
		cout << "Equilateral" << '\n';
	}
	else if (side1 != side2 && side2 != side3 && side1 != side3)
	{
		cout << "Scalene" << '\n';
	}
	else
	{
		cout << "Isosceles" << '\n';
	}
}

int main()
{
	int side1, side2, side3;

	int maxSide = 0;
	while (true)
	{
		cin >> side1 >> side2 >> side3;
		if (side1 == 0 && side2 == 0 && side3 == 0)
		{
			break;
		}

		maxSide = max(side1, max(side2, side3));
		if (side1 + side2 + side3 - maxSide <= maxSide)
		{
			cout << "Invalid" << '\n';
			continue;
		}

		PrintTriType(side1, side2, side3);
	}

	return 0;
}