#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define long long i64
#define unsigned long long ui64
#define unsigned int ui32

using namespace std;

int N;
int map[20][20];
int result = 20000000;

vector<int> team1;
vector<int> team2;

void dfs(int idx, int diff) {
	if (idx > N - 1) {
		result = min(result, abs(diff));
		return;
	}

	int tmp = 0;

	if (team1.size() < N / 2) {
		team1.push_back(idx);

		for (int i = 0; i < team1.size(); i++) {
			tmp = tmp + map[idx][team1[i]] + map[team1[i]][idx];
		}
		dfs(idx + 1, diff + tmp);
		team1.pop_back();
	}

	if (team2.size() < N / 2) {
		team2.push_back(idx);
		tmp = 0;
		for (int i = 0; i < team2.size(); i++) {
			tmp = tmp + map[idx][team2[i]] + map[team2[i]][idx];
		}
		dfs(idx + 1, diff - tmp);
		team2.pop_back();
	}

	cout << idx << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	team1.reserve(N);
	team2.reserve(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 0);

	cout << result << '\n';

	return 0;
}


/*
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int idx = 0;
int mn = 1234567890;

void dfs(vector<vector<pair<int, bool>>>& v, int testCount, int count, int idx)
{
	int score1 = 0, score2 = 0;
	vector<int> start;
	vector<int> link;

	if (count == (testCount / 2))
	{
		for (int i = 0; i < testCount; ++i)
		{
			if (v[0][i].second == true)
				start.push_back(i);
			else
				link.push_back(i);
		}

		for (int i = 0; i < testCount / 2; ++i)
		{
			for (int j = 0; j < testCount / 2; ++j)
			{
				score1 += v[start[i]][start[j]].first;
				score2 += v[link[i]][link[j]].first;
			}
		}

		if (abs(score1 - score2) < mn)
			mn = abs(score1 - score2);
		return;
	}

	for (int i = idx; i < testCount; ++i)
	{
		if (!(v[0][i].second))
		{
			v[0][i].second = true;

			dfs(v, testCount, count + 1, i);

			v[0][i].second = false;
		}
	}
}

int main()
{
	vector<vector<pair<int, bool>>> v(21, vector<pair<int, bool>>(21, make_pair(0, false)));
	int testCount, result = 0;

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		for (int j = 0; j < testCount; ++j)
		{
			cin >> v[i][j].first;
		}
	}

	dfs(v, testCount, 0, 0);

	cout << mn;
	return 0;
}

*/