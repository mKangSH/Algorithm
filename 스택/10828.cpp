#include <iostream>
#include <string_view>
#include <vector>
using namespace std;

void command(vector<int>& v, string_view cmd, int operand)
{
	if (cmd == "push")
		v.push_back(operand);

	else if (cmd == "pop")
	{
		if (v.empty() == true)
			cout << -1 << endl;

		else
		{
			cout << v.back() << endl;
			v.pop_back();
		}
	}

	else if (cmd == "size")
	{
		cout << v.size() << endl;
	}

	else if (cmd == "empty")
	{
		if (v.empty() == true)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	else if (cmd == "top")
	{
		if (v.empty() == true)
			cout << -1 << endl;

		else
		{
			cout << v.back() << endl;
		}
	}
}

int main()
{
	vector<int> v;
	int testCount = 0, operand = 0;
	string cmd;

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> cmd;

		if (cmd == "push")
			cin >> operand;

		command(v, cmd, operand);
	}
}