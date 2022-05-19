#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int blackjack(vector<int> v, int max)
{
    int result = 0, count = v.size();

    for (int i = 0; i < (count - 2); ++i)
    {
        for (int j = i + 1; j < (count - 1); ++j)
        {
            for (int k = j + 1; k < count; ++k)
            {
                int temp = v[i] + v[j] + v[k];
                if (temp <= max && result < temp)
                    result = temp;
            }
        }
    }

    return result;
}

int main()
{
    int count, answer, result;
    vector<int> a;

    cin >> count >> answer;

    for (int i = 0; i < count; ++i)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    result = blackjack(a, answer);

    cout << result << endl;

    return 0;
}