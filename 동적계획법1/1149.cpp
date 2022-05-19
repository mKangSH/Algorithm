#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> v(1001);

	int houses, R, G ,B;

	cin >> houses;

	for (int i = 0; i < houses; ++i)
	{
		cin >> R >> G >> B;

		v[i].push_back(R);
		v[i].push_back(G);
		v[i].push_back(B);

		if (i != 0)
		{
			v[i][0] = min(v[i - 1][1], v[i - 1][2]) + v[i][0];
			v[i][1] = min(v[i - 1][0], v[i - 1][2]) + v[i][1];
			v[i][2] = min(v[i - 1][1], v[i - 1][0]) + v[i][2];
		}
	}

	cout << min(min(v[houses - 1][0], v[houses - 1][1]), v[houses - 1][2]) << endl;

	return 0;
}