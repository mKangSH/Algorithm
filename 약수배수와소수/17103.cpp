#include <iostream>
#include <vector>
using namespace std;

void CreatePrimeTable(vector<bool>& primeNumberTable)
{
	primeNumberTable[0] = false;
	primeNumberTable[1] = false;

	for (int i = 4; i < primeNumberTable.size(); i += 2)
	{
		primeNumberTable[i] = false;
	}

	for (int i = 3; i * i < primeNumberTable.size(); i += 2)
	{
		int coefficient = 2;
		if (primeNumberTable[i] == false)
		{
			continue;
		}

		while (i * coefficient < primeNumberTable.size() - 1)
		{
			primeNumberTable[i * coefficient] = false;
			coefficient++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tryCount;
	cin >> tryCount;

	vector<bool> primeNumberTable(1000001, true);
	CreatePrimeTable(primeNumberTable);

	for (int i = 0; i < tryCount; i++)
	{
		int evenNumber;
		cin >> evenNumber;

		int a, b;
		a = evenNumber / 2;
		b = evenNumber / 2;

		int partitionCount = 0;
		while (a > 1 && b < evenNumber)
		{
			if (primeNumberTable[a] && primeNumberTable[b])
			{
				if (evenNumber == a + b)
				{
					partitionCount++;
					a--;
				}
				else if (evenNumber < a + b)
				{
					a--;
				}
				else
				{
					b++;
				}
			}
			else if(primeNumberTable[a] == false)
			{
				a--;
			}
			else
			{
				b++;
			}
		}

		cout << partitionCount << '\n';
	}
}