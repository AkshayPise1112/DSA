#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 48. Rotate Image
    // https://leetcode.com/problems/rotate-image/submissions/1298376898/

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > temp(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[i][j] = matrix[i][j];
            }
        }

        int row = 0;
        int col = n-1;
        for(int i=0, col=n-1; i<n; i++, col--){
            for(int j=0, row=0; j<n; j++, row++){
                matrix[row][col] = temp[i][j];
            }
        }
    }

    
    // 152. Maximum Product Subarray
    // https://leetcode.com/problems/maximum-product-subarray/description/

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        __int128_t low = 1;
        __int128_t high = 1;
        __int128_t ans = INT_MIN;

        for(int i=0; i<n; i++){
            if(low == 0) low = 1;
            if(high == 0) high = 1;

            low = low * nums[i];
            high = high * nums[n-i-1];

            ans = max(low, max(ans, high));
        }

        return ans;

    }
};