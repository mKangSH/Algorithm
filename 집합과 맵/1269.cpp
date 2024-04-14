#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int countA, countB;
	cin >> countA >> countB;

	unordered_set<int> setA, setB;
	setA.reserve(countA);
	setB.reserve(countB);

	for (int i = 0; i < countA; i++)
	{
		int number;
		cin >> number;

		setA.insert(number);
	}

	for (int i = 0; i < countB; i++)
	{
		int number;
		cin >> number;

		if (setA.find(number) == setA.end())
		{
			setB.insert(number);
		}
		else
		{
			setA.erase(number);
		}
	}

	cout << setA.size() + setB.size();
}