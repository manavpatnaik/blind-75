#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        uint32_t lsb = (n&1);
        uint32_t revLsb = lsb<<(31-i);
        res = res|revLsb;
        n >>= 1;
    }
    return res;
}