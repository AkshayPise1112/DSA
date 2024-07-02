#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // Floor in a Sorted Array
    // https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154

    int findFloor(vector<long long> v, long long n, long long x){
      
        
        int s = 0, e = n - 1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(v[mid] == x || (v[mid] < x && v[mid + 1] > x) || (mid == n-1 && v[mid] < x)){
                return mid;
            }
            
            if(v[mid] > x){
                e = mid - 1;
            }
            
            if(v[mid] < x){
                s = mid + 1;
            }
        }
        
        return -1;
    }

    // 1901. Find a Peak Element II
    // https://leetcode.com/problems/find-a-peak-element-ii/

    void solve(vector<vector<int> > &mat, int i, int j, int m, int n, vector<int>& ans){
        if(i < 0 || j < 0 || i >= m || j >= n || ans.size() != 0){
            return;
        }

        int curr = mat[i][j];

        int top = (i-1 >= 0) ? mat[i-1][j] : INT_MIN;
        int left = (j-1 >= 0) ? mat[i][j-1] : INT_MIN;
        int right = (j+1 < n) ? mat[i][j+1] : INT_MIN;
        int down = (i+1 < m) ? mat[i+1][j] : INT_MIN;

        if(curr > top && curr > left && curr > right && curr > down){
            ans.push_back(i);
            ans.push_back(j);

            return;
        }
        
        solve(mat, i+1, j, m, n, ans);
        solve(mat, i, j+1, m, n, ans);
        

        return;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        solve(mat, 0, 0, mat.size(), mat[0].size(), ans);
        return ans;
    }


    // Find Nth root of M
    // https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

    int NthRoot(int n, int m)
	{
        int low = 1;
        int high = m;
        int mid = (low + high )/2;
     
        while(low<=high){
            mid = (low + high )/2;
            
            if(pow(mid,n) == m ){
                return mid;
                break;
            }
            if(pow(mid,n) >m ){
                high=mid-1;
            }
            if(pow(mid,n) < m ){
                low=mid+1;
            }   
        }
    }
};