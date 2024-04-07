#include <iostream>
#include <string>
using namespace std;

int CalculateCoinCount(int& change, const int coin)
{
	int ret = change / coin;
	change = change % coin;

	return ret;
}

int main()
{
	const int Quarter = 25;
	const int Dime = 10;
	const int Nickel = 5;
	const int Penny = 1;

	int caseCount;
	cin >> caseCount;

	for (int i = 0; i < caseCount; i++)
	{
		int change;
		cin >> change;

		string coins;
		
		coins += to_string(CalculateCoinCount(change, Quarter)) + " ";
		coins += to_string(CalculateCoinCount(change, Dime)) + " ";
		coins += to_string(CalculateCoinCount(change, Nickel)) + " ";
		coins += to_string(CalculateCoinCount(change, Penny));

		cout << coins << '\n';
	}
}