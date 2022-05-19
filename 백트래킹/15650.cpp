#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<pair<int, bool>>& v, int cnt, int m, int n)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
			cout << v[i].first << ' ';

		cout << endl;
		return;
	}

	for (int i = 0; i < n; ++i)
	{

		if (!(v[i].second))
		{
			v[i].second = true;

			v[cnt].first = i + 1;

			if (cnt == 0)
			{
				dfs(v, cnt + 1, m, n);
			}

			else if(v[cnt - 1].first < i + 1)
			{
				dfs(v, cnt + 1, m, n);
			}

			v[i].second = false;
		}
	}
}

int main()
{
	vector<pair<int, bool>> v(9, make_pair(0, false));
	int n, m;

	cin >> n >> m;

	dfs(v, 0, m, n);
	return 0;

}