#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> a;

int cnt = 0;

void recursive(int n, int start, int bypass, int to)
{
	++cnt;

	if (n == 1)
		cout << start << ' ' << to << '\n';

	else
	{
		recursive(n - 1, start, to, bypass);
		cout << start << ' ' << to << '\n';
		recursive(n - 1, bypass, start, to);
	}
}

int main()
{
	int N;

	cin >> N;

	cout << (1 << N) - 1 << '\n';

	recursive(N, 1, 2, 3);
}