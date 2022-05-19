#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int testCount, temp;

	vector<int> v;

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> ma;

	ma.push_back(v[0]);
	ma.push_back(v[0] + v[1]);
	ma.push_back(max(v[0] + v[2], v[1] + v[2]));

	for (int i = 3; i < testCount; ++i)
	{
		ma.push_back(max(ma[i - 2] + v[i], ma[i - 3] + v[i - 1] + v[i]));
	}

	cout << ma[testCount - 1] << endl;
}