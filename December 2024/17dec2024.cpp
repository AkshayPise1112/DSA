#include<bits/stdc++.h>
using namespace std;

class solution{
    
    // 56. Merge Intervals
    // https://leetcode.com/problems/merge-intervals/
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int prev = -1;

        for(int i=0; i<intervals.size(); i++){
            if(!ans.empty() && ans[prev][1] >= intervals[i][0]){
                ans[prev][1] = max(ans[prev][1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
                prev++;
            }
        }

        return ans;
    }
};