#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int num, max = 0;

    cin >> num;

    vector<int> even;
    int index;

    for (int i = 0; i < num; i++) {
        cin >> index;

        even.push_back(index);

        if (index > max)
            max = index;
    }

    vector<bool> prime(max + 1, true);
  
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(max); i++)
    {
        if (prime[i] == true)
            for (int j = i * 2; j <= (max); j += i)
                prime[j] = false;
    }

    int result = 0;

    for (int i = 0; i < num; ++i) // n/2 - j + n/2 + j = n
    {
        result = even[i] / 2;

        for (int j = 0; j < even[i] / 2; ++j)
        {
            result - j;

            if (prime[result - j] && prime[result + j])
            {
                cout << result - j << ' ' << result + j << '\n';
                break;
            }
        }
    }

    return 0;
}