#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}

	return (a.length() < b.length());
}

int main(void)
{
	int count;
	string s;
	vector<string> v;
	
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	s = "\0";

	string outStr;

	for (auto iter : v)
	{
		if (s != iter)
			outStr += iter + '\n';

		s = iter;
	}

	cout << outStr << endl;

	return 0;
}