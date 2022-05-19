#include <iostream>
using namespace std;

int main(void)
{
	int N, result = 0;

	cin >> N;

	while (N >= 0)
	{
		if (N % 5 != 0)
		{
			N -= 3;
			result++;
		}

		else
		{
			result += (N / 5);
			cout << result << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}