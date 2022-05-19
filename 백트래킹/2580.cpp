#include <iostream>
#include <vector>
using namespace std;

bool found = false;

bool check(vector<vector<int>>& v, vector<pair<int, int>>& points, int count, int a)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (a == v[points[count].first][j] || a == v[j][points[count].second])
				return false;
		}

		for (int j = 0; j < 9; ++j)
		{
			if (a == v[(((points[count].first)/3) * 3) + (j / 3)][(((points[count].second) / 3) * 3) + (j % 3)])
				return false;
		}
	}

	return true;
}

void sudoku(vector<vector<int>>& v, vector<pair<int, int>>& points, int count)
{
	if (count == points.size())
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cout << v[i][j] << ' ';
			}

			cout << '\n';
		}
		found = true;
		return;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (check(v, points, count, i + 1))
		{
			v[points[count].first][points[count].second] = i + 1;
			sudoku(v, points, count + 1);
		}

		if (found)
			return;
	}

	v[points[count].first][points[count].second] = 0;
	return;
}

int main()
{
	vector<vector<int>> v(9, vector<int>(9));
	pair<int, int> zeroPoint;
	vector<pair<int, int>> points;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] == 0)
			{
				zeroPoint.first = i;
				zeroPoint.second = j;

				points.push_back(zeroPoint);
			}
		}
	}

	sudoku(v, points, 0);

}