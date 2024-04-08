#include <iostream>
using namespace std;

int main()
{
	// 맨 위 둘레 1
	// n - 1 이음새 둘레
	// 아래 둘레 n
	// 옆 둘레 2n
	unsigned long long layer;

	cin >> layer;
	cout << layer * 4;

	return 0;
}