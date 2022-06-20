#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> table;
    
    int start = 0, end = 0;
    int len = 0, counter = 0;
    
    while (end < s.length()) {
        table[s[end]]++;
        
        if (table[s[end]] > 1) counter++;
        end++;
        
        if (counter == 0) len = max(len, end-start);
        
        while (counter > 0) {
            table[s[start]]--;
            if (table[s[start]] == 1) counter--;
            start++;
        }
    }
    return len;
}