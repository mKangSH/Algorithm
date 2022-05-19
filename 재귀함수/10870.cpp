#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
	int N;

	cin >> N;

	cout << fibonacci(N) << endl;

	return 0;
}