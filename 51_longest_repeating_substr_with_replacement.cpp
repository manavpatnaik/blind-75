#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> arr(26,0);
    int maxFreq = 0, start = 0, end = 0, len = 0;
    
    while (end < s.length()) {
        arr[s[end]-'A']++;
        maxFreq = max(maxFreq, arr[s[end]-'A']);
        end++;
        if (end-start - maxFreq <= k) 
            len = max(len, end-start);
        else {
            arr[s[start]-'A']--;    
            start++;
        }
    }
    
    return len;
}