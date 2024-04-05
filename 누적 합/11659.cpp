#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int countOfNumber, countOfSum;

	cin >> countOfNumber >> countOfSum;

	vector<int> samples(countOfNumber + 1, 0);

	for (int i = 1; i < countOfNumber + 1; i++)
	{
		cin >> samples[i];
		samples[i] += samples[i - 1];
	}

	for (int i = 0; i < countOfSum; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << samples[end] - samples[start - 1] << '\n';
	}

	return 0;
}