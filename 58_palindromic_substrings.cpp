#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    int l, r, count = 0;
    for (int i = 0; i < s.length(); i++) {
        l = r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }
        l = i;
        r = l+1;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }
    return count;
}