#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> conversionNumber;
	int decimalNumber, numberSystem;

	cin >> decimalNumber >> numberSystem;

	while ((decimalNumber / numberSystem) != 0)
	{
		conversionNumber.push(decimalNumber % numberSystem);
		decimalNumber = (decimalNumber / numberSystem);
	}
	conversionNumber.push(decimalNumber);
	
	string answer;
	while (conversionNumber.empty() == false)
	{
		int number = conversionNumber.top();

		if (number >= 10)
		{
			answer += (number - 10 + 'A');
		}
		else
		{
			answer += (number + '0');
		}
		
		conversionNumber.pop();
	}

	cout << answer;
}