#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    string left = "({[", right=")}]";
    for (char &ch : s) {
        if (left.find(ch) != string::npos) {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char c = st.top();
            st.pop();
            int leftIndex = left.find(c);
            int rightIndex = right.find(ch);
            if (leftIndex != rightIndex) return false;
        }
    }
    return st.empty();
}