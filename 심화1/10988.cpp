#include <iostream>
#include <queue>
using namespace std;

int main()
{
	string word;
	cin >> word;

	queue<char> checkPalindrome;
	for (int i = 0; i < word.length() / 2; i++)
	{
		checkPalindrome.push(word[i]);
	}

	int isPalindrome = 1;
	for (int i = 0; i < word.length() / 2; i++)
	{
		if (checkPalindrome.front() == word[(word.length() - 1) - i])
		{
			checkPalindrome.pop();
		}
		else
		{
			isPalindrome = 0;
			break;
		}
	}

	cout << isPalindrome;

	return 0;
}