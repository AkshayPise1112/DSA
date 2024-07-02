#include<bits/stdc++.h>
using namespace std;

class solution{
    // 560. Subarray Sum Equals K
    // https://leetcode.com/problems/subarray-sum-equals-k/description/

    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            int prev = nums[i];
            if(nums[i] == k){
                ans++;
            }
            for(int j=i+1; j<nums.size(); j++){
                if(prev + nums[j] == k){
                    ans++;
                }

                
                prev = prev + nums[j];
                

            }
        }
        return ans;
    }


    // 73. Set Matrix Zeroes
    // https://leetcode.com/problems/set-matrix-zeroes/


    void solve(vector<vector<int>>& matrix, int i, int j){
        int tempi = i-1;
        int tempj = j-1;
        while(tempi >= 0){
            matrix[tempi][j] = 0;
            tempi--;
        }
        while(tempj >= 0){
            matrix[i][tempj] = 0;
            tempj--;
        }
        tempi = i+1;
        tempj = j+1;
        while(tempi < matrix.size()){
            matrix[tempi][j] = 0;
            tempi++;
        }
        while(tempj < matrix[0].size()){
            matrix[i][tempj] = 0;
            tempj++;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size(), vector<int>(matrix[0].size()));
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                temp[i][j] = matrix[i][j];
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(temp[i][j] == 0){
                    solve(matrix, i, j);
                }
            }
        }
    }

    // Maximum Product Subarray
    // https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/0?qa-rewrite=3336%2Fprint-all-valid-combinations-of-ip-address&show=3350

    long long maxProduct(vector<int> arr, int n) {
	    long long int ans = INT_MIN;
	    long long int prev;
        
        for(int i=0; i<n; i++){
            prev = arr[i];
            ans = max(prev, ans);
            for(int j=i+1; j<n; j++){
                
                prev = prev * arr[j];
                
                ans = max(prev, ans);
            }
            
        }
        return ans;
	}

};