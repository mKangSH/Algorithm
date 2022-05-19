#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main(void)
{
	int testCount, x, y;

	cin.sync_with_stdio(false);

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> x >> y;

		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), compare);
	
	string outStr;
	for (auto iter : v)
		outStr += to_string(iter.first) + ' ' + to_string(iter.second) + '\n';
		//cout << iter.first << ' ' << iter.second << '\n';

	cout << outStr;

	return 0;
}