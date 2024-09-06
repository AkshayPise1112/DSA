#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 50. Pow(x, n)
    // https://leetcode.com/problems/powx-n/

    double solve(double x, long long n){
        if(n <= 1){
            return x;
        }

        double ans;

        if(n % 2 == 0){
            double temp = solve(x, n / 2);
            ans = temp * temp;
        }
        else{
            double temp = solve(x, (n-1) / 2);
            ans = x * temp * temp;
        }

        return ans;
    }

    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(x == 0){
            return 0;
        }
        if(n < 0){
            return 1 / solve(x, abs(n));
        }

        return solve(x, n);
    }


    // 78. Subsets
    // https://leetcode.com/problems/subsets/

    void solve(vector<int> &nums, vector<vector<int>>& ans, int index, vector<int> prev){
        if(index >= nums.size()) {
            ans.push_back(prev);
            return;
        }

        //exclude
        solve(nums, ans, index+1, prev);

        // include
        prev.push_back(nums[index]);
        solve(nums, ans, index+1, prev);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> prev;
        solve(nums, ans, 0, prev);
        return ans;
    }

    // 39. Combination Sum
    // https://leetcode.com/problems/combination-sum/

    void combination(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum>target) return; 
        if(currSum==target){
            ans.push_back(currComb); 
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){ 
            currComb.push_back(candidates[i]); 
            currSum+=candidates[i];
            combination(candidates, target, currComb, currSum, i, ans); 
            currComb.pop_back();
            currSum-=candidates[i];
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, 0, ans);
        return ans;
    }
};