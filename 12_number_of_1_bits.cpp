#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    // Brian Kernighan Algorithm
    while (n > 0) {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main() {
    cout << hammingWeight(3) << endl;
    cout << hammingWeight(7) << endl;
}