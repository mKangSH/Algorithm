#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(void)
{
	string A, B, as, bs;
	int max, ai, bi, carry = 0, result;

	cin >> A >> B;

	vector<int> a, b, v;

	for (int i = A.length(); i > 0; i -= 1)
	{
		as = A.substr(A.length() - i, 1);
		ai = stoi(as);
		a.push_back(ai);
	}

	for (int i = B.length(); i > 0; i -= 1)
	{
		bs = B.substr(B.length() - i, 1);
		bi = stoi(bs);
		b.push_back(bi);
	}

	if (a.size() < b.size())
	{
		vector<int>::iterator it = a.begin();
		max = b.size();
		a.insert(it, (b.size() - a.size()), 0);
	}

	else
	{
		vector<int>::iterator it = b.begin();
		max = a.size();

		b.insert(it, (a.size() - b.size()), 0);
	}

	vector<int>::iterator iter = v.begin();

	for (int i = max - 1; i >= 0; i--)
	{
		iter = v.begin();
		result = a[i] + b[i] + carry;
		if (result >= 10)
		{
			carry = 1;
			result %= 10;
		}

		else
			carry = 0;

		v.insert(iter, 1, result);
	}

	if (carry == 1)
	{
		cout << carry;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}

}