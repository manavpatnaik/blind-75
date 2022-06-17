#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    map<char, int> table;
    
    for (char ch : s) table[ch]++;
    
    for (char ch : t) {
        table[ch]--;
        if (table[ch] < 0) return false;
        if (table[ch] == 0) table.erase(ch);
    }
    
    return true;
}