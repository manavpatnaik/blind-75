#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int l, r, len = 0;
    int start, strLen;
    
    for (int i = 0; i < s.length(); i++) {
        l = r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            if (r-l+1 > len) {
                len = max(len, r-l+1);
                start = l;
                strLen = r-l+1;
            }
            l--;
            r++;
        }
        l = i;
        r = l+1;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            if (r-l+1 > len) {
                len = max(len, r-l+1);
                start = l;
                strLen = r-l+1;
            }
            l--;
            r++;
        }
    }
    return s.substr(start, strLen);
}