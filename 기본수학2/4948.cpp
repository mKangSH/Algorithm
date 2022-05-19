#include <iostream>

using namespace std;

inline void prime_table(const unsigned int& k, bool a[]) {
    for (auto t = 4; t <= k; t += 2) {
        a[t] = true;
    }

    for (auto t = 3; t * t <= k; t += 2) 
    {
        if (a[t] == 0) 
        {
            for (auto r = t; t * r <= k; r += 2) 
            {
                a[t * r] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int a = 0, c = 0;
    long long b = 0;

    while (1) 
    {
        cin >> a;

        if (a == 0)
            break;

        auto table = new bool[2*a + 1]{};
        table[1] = true;

        prime_table(2*a, table);

        for (auto t = a + 1; t <= 2*a; t++) 
        {
            if (!table[t]) c++;
        }

        cout << c << endl;

        c = 0;
    }
}

/*
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define SIZE 246913

using namespace std;

int main() {
    vector<bool> sieve(SIZE);
    int n = 1, i = 1, count;
    vector<int> prime_Fact;

    while (++i < SIZE)
        if (!sieve[i]) {
            prime_Fact.push_back(i);
            if (i <= sqrt(SIZE))
                for (int j = i * i; j < SIZE; j += i)
                    sieve[j] = true;
        }
    while (n) {
        count = 0;
        scanf("%d", &n);

        if (n)
            printf("%d\n", lower_bound(prime_Fact.begin(), prime_Fact.end(), 2 * n + 1) - \
                upper_bound(prime_Fact.begin(), prime_Fact.end(), n));
    }
}
*/