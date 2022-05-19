#include <iostream>
using namespace std;

int main(void)
{
	int N, data[10001] = { 0 }, tmp;

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		++(data[tmp]);
	}

	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < data[i]; j++)
		{
			cout << i << '\n';
		}
	}

	return 0;
}