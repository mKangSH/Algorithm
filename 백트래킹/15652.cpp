#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<pair<int, bool>>& v, int n, int m, int count)
{
	if (count == m)
	{
		for (int i = 0; i < m; ++i)
			cout << v[i].first << ' ';

		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		v[count].first = i + 1;

		if (count == 0)
		{
			dfs(v, n, m, count + 1);
		}

		else if (v[count - 1].first <= i + 1)
		{
			dfs(v, n, m, count + 1);
		}
	}
}

int main()
{
	int n, m;
	vector<pair<int, bool>> v(9, make_pair(0, false));
	cin >> n >> m;

	dfs(v, n, m, 0);
}