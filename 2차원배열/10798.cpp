#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	vector<vector<char>> table(16, vector<char>(16, ' '));

	for (int y = 0; y < 5; y++)
	{
		char word[16] = { ' ' };
		cin.getline(word, 16);

		memcpy(&table[y][0], word, sizeof(word));
	}

	string answer;
	
	for (size_t x = 0; x < table.size(); x++)
	{
		for (size_t y = 0; y < table.size(); y++)
		{
			if ((table[y][x] >= 'A' && table[y][x] <= 'Z') ||
				(table[y][x] >= 'a' && table[y][x] <= 'z') ||
				(table[y][x] >= '0' && table[y][x] <= '9'))
			{
				answer += table[y][x];
			}
		}
	}
	
	cout << answer;
}