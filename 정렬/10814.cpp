#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct People
{
	int count;
	int age;
	string name;
}People;

bool compare(People a, People b)
{
	if (a.age == b.age)
		return a.count < b.count;

	return a.age < b.age;
}

int main(void)
{
	int testCount, a;
	string s;
	vector<People> v;

	cin.sync_with_stdio(false);

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> a >> s;

		v.push_back({ i, a, s });
	}

	sort(v.begin(), v.end(), compare);

	string outStr;

	for (auto iter : v)
	{
		outStr += to_string(iter.age) + ' ' + iter.name + '\n';
	}

	cout << outStr << endl;
}