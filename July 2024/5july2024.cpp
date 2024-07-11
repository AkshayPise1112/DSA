#include<bits/stdc++.h>
using namespace std;

class solution{


    // 162. Find Peak Element
    // https://leetcode.com/problems/find-peak-element/submissions/1317190626/

     int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // for(int i=0; i<n; i++){
        //     if((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i+1] < nums[i])){
        //         return i;
        //     }
        // }
        // return 0;

        if(n == 1 || nums[0] > nums[1]){
            return 0;
        }

        if(nums[n-1] > nums[n-2]){
            return n-1;
        }

        int s = 1;
        int e = n-2;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]){
                return mid;
            }

            else if(nums[mid - 1] < nums[mid]){
                s = mid + 1;
            }

            else if(nums[mid + 1] < nums[mid]){
                e = mid - 1;
            }

            else{
                s = mid + 1;
            }
        }

        return -1;
    }

    // 81. Search in Rotated Sorted Array II
    // https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

    bool search(vector<int>& nums, int target) {
        // for(auto i: nums){
        //     if(i == target){
        //         return true;
        //     }
        // }
        // return false;

        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                ++l;
                --r;
                continue;
            }
  
            else if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
  
            else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }

    // 153. Find Minimum in Rotated Sorted Array
    // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

    int findMin(vector<int>& nums) {
        int res = nums[0];
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            if (nums[l] < nums[r]) { 
                res = min(res, nums[l]);
                break;
            }
            
            int mid = l + (r - l) / 2;
            
            res = min(res, nums[mid]);
            
            if (nums[mid] >= nums[l]) { 
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        
        return res;
    }
};