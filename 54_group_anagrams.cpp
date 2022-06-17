#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    map<string, vector<string>> mp;
    
    for (string &str : strs) {
        string temp = str;
        sort(str.begin(), str.end());
        mp[str].push_back(temp);
    }
    
    for (auto anagram : mp) {
        res.push_back(anagram.second);
    }
    
    return res;
}