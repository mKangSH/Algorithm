#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, bool>> v(10);

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << v[i].first << ' ';
		}

		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!(v[i].second))
		{
			v[i].second = true;
			v[cnt].first = i;
			dfs(cnt + 1);
			v[i].second = false;
		}
	}
}

int main()
{
	cin >> n >> m;

	dfs(0);

	return 0;
}