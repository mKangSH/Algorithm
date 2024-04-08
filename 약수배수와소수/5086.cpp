#include <iostream>
using namespace std;

enum NumberState
{
	factor,
	multiple,
	neither,
};

void PrintNumberState(const NumberState& ns)
{
	switch (ns)
	{
		case NumberState::multiple:
		{
			cout << "multiple" << '\n';
			break;
		}
		case NumberState::factor:
		{
			cout << "factor" << '\n';
			break;
		}
		case NumberState::neither:
		{
			cout << "neither" << '\n';
			break;
		}
		// default:
	}
}

int main()
{
	NumberState ns;
	int lhs, rhs;

	while (true)
	{
		cin >> lhs >> rhs;

		if (lhs == 0 && rhs == 0)
		{
			break;
		}

		if (lhs > rhs)
		{
			if (lhs % rhs == 0)
			{
				ns = NumberState::multiple;
			}
			else
			{
				ns = NumberState::neither;
			}
		}
		else
		{
			if (rhs % lhs == 0)
			{
				ns = NumberState::factor;
			}
			else
			{
				ns = NumberState::neither;
			}
		}

		PrintNumberState(ns);
	}
}