#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int count;
	cin >> count;

	int openDoorCount = 0;
	for (double i = 1; i * i <= count; i++)
	{
		if (i == sqrt(i * i))
		{
			openDoorCount++;
		}
	}

	cout << openDoorCount;
}