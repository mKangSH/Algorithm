#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& v, const int m, const int n, int cnt)
{
	if (m == cnt)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << v[i] << ' ';
		}

		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		v[cnt] = i + 1;
		dfs(v, m, n, cnt + 1);
	}
}

int main()
{
	vector<int> v(8, 0);
	int m, n;

	ios::sync_with_stdio(false);

	cin >> n >> m;

	dfs(v, m, n, 0);
}