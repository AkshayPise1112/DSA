#include<bits/stdc++.h>
using namespace std;

class solutions{

    //283. Move Zeroes
    //https://leetcode.com/problems/move-zeroes/description/

    void moveZeroes(vector<int>& nums) {
        vector<int> temp;

        for(auto i: nums){
            if(i != 0){
                temp.push_back(i);
            }
        }

        if(temp.size() != 0){
            int j = 0;
            for(int i=0; i<nums.size(); i++){
                if(j < temp.size()){
                    nums[i] = temp[j];
                    j++;
                }
                else{
                    nums[i] = 0;
                }
            }
        }
    }


    // 56. Merge Intervals
    // https://leetcode.com/problems/merge-intervals/

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;

        sort(intervals.begin(), intervals.end());

        for(int i=0; i<intervals.size(); i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }

        return ans;
    }


    // 121. Best Time to Buy and Sell Stock
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            int diff = prices[i] - mini;
            ans = max(ans, diff);
            mini = min(mini, prices[i]);
        }
        return ans;
    }


};


int main(){
    return 0;
}