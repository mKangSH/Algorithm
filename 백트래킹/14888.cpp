#include <iostream>
#include <vector>
using namespace std;

int mx = -1234567890, mn = 1234567890;

void dfs(vector<int>& v, vector<int>& op, int testCount, int count, int result)
{
	if (count == testCount)
	{
		if (result > mx)
			mx = result;
		if (result < mn)
			mn = result;

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (op[i] > 0)
		{
			op[i]--;
			switch (i)
			{
				case 0:
					dfs(v, op, testCount, count + 1, result + v[count]);
					break;

				case 1:
					dfs(v, op, testCount, count + 1, result - v[count]);
					break;

				case 2:
					dfs(v, op, testCount, count + 1, result * v[count]);
					break;

				default:
					dfs(v, op, testCount, count + 1, result = result / v[count]);
					break;
			}

			op[i]++;
		}
	}
	return;
}

int main()
{
	int testCount;

	cin >> testCount;

	vector<int> v(11, 0);
	vector<int> op(4);

	for (int i = 0; i < testCount; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> op[i];
	}

	dfs(v, op, testCount, 1, v[0]);

	cout << mx << endl;
	cout << mn << endl;
}