#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res(n+1, 0);
    res[0] = 0;
    // If X/2 = Y
    // If X is even, then no of bits in X = no of bits in Y
    // If X is odd, then (bits X) = 1 + (bits Y)
    for (int i = 1; i <= n; i++) {
        res[i] = res[i/2] + i%2;
    }
    return res;
}