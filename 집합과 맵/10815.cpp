#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, bool> a;

	int cardCount, key, testCount;

	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cardCount;

	for (int i = 0; i < cardCount; ++i)
	{
		cin >> key;

		a.emplace(key, true);
	}

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> key;

		auto item = a.find(key);

		if (item != a.end())
			cout << 1 << ' ';

		else
			cout << 0 << ' ';
	}
}