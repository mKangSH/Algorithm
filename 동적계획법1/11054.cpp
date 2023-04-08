#include <iostream>
#include <vector>
using namespace std;

int main()
{
	bool higher = true;
	int testCount, length = -1;
	vector<int> memory(1001), v(1001), bMemory(1001);

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < testCount; ++i)
	{
		memory[i] = 1;

		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j])
				memory[i] = max(memory[i], memory[j] + 1);
		}
	}

	for (int i = testCount - 1; i >= 0; --i)
	{
		bMemory[i] = 1;

		for (int j = testCount - 1; j >= i; --j)
		{
			if (v[i] > v[j])
				bMemory[i] = max(bMemory[i], bMemory[j] + 1);
		}
	}

	for (int i = 0; i < testCount; ++i)
		length = max(length, memory[i] + bMemory[i] - 1);

	cout << length << endl;
}