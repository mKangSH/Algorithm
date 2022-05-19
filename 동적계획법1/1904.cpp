#include <iostream>
using namespace std;

int memory[1000001] = { 0 };

int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (memory[n] != 0) return memory[n];
	return memory[n] = (dp(n - 2) + dp(n - 1)) % 15746;
}

int main()
{
	int N;

	cin >> N;

	cout << dp(N) % 15746;
}

// 1
// 00 11
// 001 100 111
// 0011 0000 1001 1100 1111
// 10011 00111 10000 00001 00100 11001 11100 11111