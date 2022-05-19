#include <iostream>

using namespace std;

inline void prime_table(const unsigned int& k, bool a[]) {
    for (auto t = 4; t <= k; t += 2) {
        a[t] = true;
    }

    for (auto t = 3; t * t <= k; t += 2) {
        if (a[t] == 0) {
            for (auto r = t; t * r <= k; r += 2) {
                a[t * r] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int a = 0, c = 0, d = 0;
    long long b = 0;

    cin >> a >> b;

    auto table = new bool[b + 1]{};
    table[1] = true;

    prime_table(b, table);

    for (auto t = a; t < b + 1; t++) {
        if (!table[t]) cout << t << "\n";
    }
}