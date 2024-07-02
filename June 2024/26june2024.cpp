#include<bits/stdc++.h>
using namespace std;

class solutions{
    // 74. Search a 2D Matrix
    // https://leetcode.com/problems/search-a-2d-matrix/

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int row=0, col=m-1;

        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++;
            else col--;
        }
        return false;
    }

    // Row with max 1s
    // https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = INT_MIN;
	    int maxi = 0;
	    for(int i=0; i<n; i++){
	        int cnt = 0;
	        for(int j=0; j<m; j++){
	            if(arr[i][j] == 1){
	                cnt++;
	            }   
	        }
	        if(maxi < cnt){
	            maxi = cnt;
	            ans = i;  
	       }
	    }
	    
	    if(ans == INT_MIN){
	        return -1;
	    }
	    
	    return ans;
	}
};