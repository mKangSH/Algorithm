#include <iostream>
using namespace std;

int main()
{
	int tryCount;
	cin >> tryCount;

	int totalCount = 2;
	for (int i = 0; i < tryCount; i++)
	{
		totalCount += (totalCount - 1);
	}

	cout << totalCount * totalCount;
}