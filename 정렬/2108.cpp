#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int testCount = 0, num, sum = 0, center = 0, min = 4001, max = -4001, count = 0, fre = 0, mode;
	bool cenStop = false;
	vector<int> v(8002, 0);

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	cin >> testCount;
	
	for (int i = 0; i < testCount; ++i)
	{
		cin >> num;
		sum += num;
		++(v[num + 4000]);
	}

	if(sum >= 0)
		cout << int(((float)sum / (float)testCount) + 0.5f) << '\n';
	else
		cout << int(((float)sum / (float)testCount) - 0.5f) << '\n';

	for (int i = 0; i < 8001; ++i)
	{
		center += v[i];

		if (!(cenStop) && (center >= ((testCount) / 2 + 1)))
		{
			cenStop = true;
			cout << i - 4000 << '\n';
		}


		if (v[i] != 0 && min > i - 4000)
			min = i - 4000;

		if (v[i] != 0 && max < i - 4000)
			max = i - 4000;

		if (v[i] == fre && count == 0)
		{
			mode = i;
			++count;
		}

		if (v[i] > fre)
		{
			mode = i;
			fre = v[i];
			count = 0;
		}
	}

	cout << (mode - 4000) << '\n' << max - min << endl;
}