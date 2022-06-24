#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> table;
    
    // Initialize frequency table
    for (char ch : t) {
        table[ch]++;
    }
    
    // Initialize sliding window
    int begin = 0, end = 0;
    int counter = table.size();
    int len = INT_MAX;
    
    string ans = "";
    
    while (end < s.length()) {
        char endChar = s[end];
        
        // Expand window
        if (table.find(endChar) != table.end()) {
            table[endChar]--;
            if (table[endChar] == 0) counter--;
        }
        end++;
        
        // Contract window
        while (counter == 0) {
            // Take a snapshot of the window when it meets the
            // necessary conditions i.e counter==0
            if (end-begin < len) {
                ans = s.substr(begin, end-begin);
                len = end-begin;
                cout << len << endl;
            }
            
            char beginChar = s[begin];
            begin++;
            if (table.count(beginChar) == 1) {
                table[beginChar]++;
                if (table[beginChar] > 0) counter++;
            }
        }
    }
    return ans;
}