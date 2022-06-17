#include <bits/stdc++.h>
using namespace std;

string processString(string &s) {
    string res = "";
    for (char ch : s) {
        if (isalnum(ch)) {
            res += tolower(ch);
        }
    }
    return res;
}

bool isPalindrome(string &s) {
    s = processString(s);
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}