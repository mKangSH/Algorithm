#include <iostream>
#include <vector>
using namespace std;

enum TriType
{
	Error,
	Scalene,
	Isosceles,
	Equilateral,
};

void ChangeTriType(TriType& tType)
{
	switch (tType)
	{
		case TriType::Scalene:
		{
			tType = TriType::Isosceles;
			break;
		}
		case TriType::Isosceles:
		{
			tType = TriType::Equilateral;
			break;
		}
	}
}

void PrintTriType(TriType& tType)
{
	switch (tType)
	{
		case TriType::Scalene:
		{
			cout << "Scalene";
			break;
		}
		case TriType::Isosceles:
		{
			cout << "Isosceles";
			break;
		}
		case TriType::Equilateral:
		{
			cout << "Equilateral";
			break;
		}
		case TriType::Error:
		{
			cout << "Error";
			break;
		}
	}
}

int main()
{
	vector<int> angles;
	TriType triType = TriType::Scalene;
	int totalAngle = 0;
	for (int i = 0; i < 3; i++)
	{
		int angle;
		cin >> angle;

		totalAngle += angle;
		for (int storedAngle : angles)
		{
			if (storedAngle == angle)
			{
				ChangeTriType(triType);
			}
		}
		angles.push_back(angle);
	}

	if (totalAngle != 180)
	{
		triType = TriType::Error;
	}

	PrintTriType(triType);
}