#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GetGreaterCommonDivisor(int a,int b)
{
	int remain;

	while (b != 0)
	{
		remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count, interval = 0;
	cin >> count;
	if (count == 0)
	{
		return -1;
	}

	vector<int> treePositions;
	treePositions.reserve(100001);

	for (int i = 0; i < count; i++)
	{
		int treePos;
		cin >> treePos;
		treePositions.push_back(treePos);

		if (i == 0)
		{
			continue;
		}
		else if (i == 1)
		{
			interval = treePos - treePositions[i - 1];
		}
		else
		{
			interval = GetGreaterCommonDivisor(interval, treePos - treePositions[i - 1]);
		}
	}

	cout << (treePositions.back() - treePositions.front()) / interval + 1 - treePositions.size();

	return 0;
}