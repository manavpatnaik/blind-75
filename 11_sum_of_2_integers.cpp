#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b) {
    unsigned carry = 0;
    while (b != 0) {
        carry = (a&b);
        // Merging the different bits into a
        a = (a^b);
        // Storing carry bits in b
        b = carry << 1;
    }
    return a;
}

int main() {
    cout << getSum(-1, 2) << endl;
    cout << getSum(-1, 1) << endl;
    cout << getSum(3, 7) << endl;

    return 0;
}