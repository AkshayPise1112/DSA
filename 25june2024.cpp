#include<bits/stdc++.h>
using namespace std;

class solution{
    public: 
    // 136. Single Number
    // https://leetcode.com/problems/single-number/description/

    int optimized(vector<int>& nums){
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }

    int singleNumber(vector<int>& nums) {

        return optimized(nums);
        // unordered_map <int, bool> mp;

        // for(int i=0; i<nums.size(); i++){
        //     if(mp.find(nums[i]) == mp.end()){
        //         mp[nums[i]] = true;
        //     }
        //     else{
        //         mp.erase(nums[i]);
        //     }
        // }

        // return mp.begin()->first;
    }


    // 54. Spiral Matrix
    // https://leetcode.com/problems/spiral-matrix/description/

    void solve(vector<vector<int>> &matrix, vector<int> &ans, int i, int j, int n, int m, int ch){
        if(i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == -101){
            return;
        }

        ans.push_back(matrix[i][j]);
        matrix[i][j] = -101;

        if(ch == 1){
            solve(matrix, ans, i, j+1, n, m, 1);
        }

        if(ch == 2){
            solve(matrix, ans, i+1, j, n, m, 2);
        }

        if(ch == 3){
            solve(matrix, ans, i, j-1, n, m, 3);
        }

        if(ch == 4){
            solve(matrix, ans, i-1, j, n, m, 4);
        }

        solve(matrix, ans, i, j+1, n, m, 1);
        solve(matrix, ans, i+1, j, n, m, 2);
        solve(matrix, ans, i, j-1, n, m, 3);
        solve(matrix, ans, i-1, j, n, m, 4);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        solve(matrix, ans, 0, 0, n, m, 1);

        return ans;
    }
};
