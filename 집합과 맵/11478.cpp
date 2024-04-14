#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	string word;
	cin >> word;

	unordered_set<string> subWord;
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 0; j < word.size(); j++)
		{
			subWord.insert(word.substr(i, j));
		}
	}

	cout << subWord.size();
}