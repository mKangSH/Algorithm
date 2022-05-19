#include <iostream>
using namespace std;
//2869

int main(void)
{
	int A, B, V, result = 0, count = 0;

	cin >> A >> B >> V;

	if((V - A) % (A - B) == 0)
		count = (V - A) / (A - B) + 1;
	else
		count = (V - A) / (A - B) + 2;

	cout << count << endl;
}