#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    int count = 0;
    auto currEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= currEnd)
            currEnd = intervals[i][1];
        else {
            // Removing the interval that ends after that current end
            // i.e the larger interval
            count++;
            currEnd = min(intervals[i][1], currEnd);
        }
    }
    
    return count;
}