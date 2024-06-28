#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 704. Binary Search
    // https://leetcode.com/problems/binary-search/submissions/1301615173/

     int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return -1;
    }


    // 74. Search a 2D Matrix
    // https://leetcode.com/problems/search-a-2d-matrix/description/

    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int rows=0, rowe = n-1, cole=m-1, cols = 0;

        while(rows <= rowe){
            int rowmid = rows + (rowe - rows) / 2;

            if(matrix[rowmid][0] <= target && matrix[rowmid][cole] >= target){
                while(cols <= cole){
                    int colmid = cols + (cole - cols) / 2;

                    if(matrix[rowmid][colmid] == target){
                        return true;
                    }

                    if(matrix[rowmid][colmid] < target){
                        cols = colmid + 1;
                    }

                    if(matrix[rowmid][colmid] > target){
                        cole = colmid - 1;
                    }
                }
            }

            if(matrix[rowmid][cole] < target){
                rows = rowmid+1;
            }
            
            if(matrix[rowmid][0] > target){
                rowe = rowmid-1;
            }
        }

        return false;
    }

    // Square root of a number
    // https://www.geeksforgeeks.org/problems/square-root/0

    long long int floorSqrt(long long int x) 
    {
        long long int s = 0;
        long long int e = x;
        long long int ans;
        while(s <= e){
            long long int mid = s + (e - s) / 2;
            
            long long int s1 = mid * mid;
            long long int s2 = (mid+1) * (mid+1);
            
            if(s1 == x || (x > s1 && x < s2)){
                ans = mid;
                break;
            }
            
            if(x < s1){
                e = mid-1;
            }
            
            if(x > s1){
                s = mid+1;
            }
        }
        
        return ans;
    }

};