#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;
//10250

int main()
{
	int T, H, W, N;

	cin >> T;
	
	queue<int> q;
	queue<int> q1;
	queue<int> q2;

	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;
		
		q.push(H);
		q1.push(W);
		q2.push(N);
	}

	for (int j = 0; j < T; j++)
	{
		if (q2.front() % q.front() == 0)
			cout << q.front() << setw(2) << setfill('0') << (q2.front() / q.front()) << endl;
		else
			cout << (q2.front() % q.front()) << setw(2) << setfill('0') << (q2.front() / q.front()) + 1 << endl;

		q2.pop();
		q.pop();
	}

	return 0;
}