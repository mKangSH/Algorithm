#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(1001), memory(1001);
	int testCount, mx = 0, index = 0, cnt = 0;

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < testCount; ++i)
	{
		memory[i] = 1;

		for (int j = i; j >= 0; --j)
		{
			if (v[i] > v[j])
			{
				memory[i] = max(memory[i], memory[j] + 1);
			}
		}
		
		mx = max(memory[i], mx);
		cout << '\n' << "mx: " << mx << endl;
	}

	cout << mx << endl;

	return 0;
}