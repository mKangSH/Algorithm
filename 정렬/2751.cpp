#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int N = 0, t, temp;
	vector<int> D;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		D.push_back(t);
	}

	sort(D.begin(), D.end());

	for (int i = 0; i < N; i++)
		cout << D[i] << '\n';
}