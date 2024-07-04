#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 34. Find First and Last Position of Element in Sorted Array
    // https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        vector<int> ans = {-1, -1};

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(target == nums[mid]){
                int temp1 = mid, temp2 = mid;

                while(temp1 >= 0){
                    if(nums[temp1] != nums[mid]){
                        break;
                    }
                    ans[0] = temp1;
                    temp1--;
                }
                while(temp2 < nums.size()){
                    if(nums[temp2] != nums[mid]){
                        break;
                    }
                    ans[1] = temp2;
                    temp2++;
                }

                return ans;
            }

            if(target < nums[mid]){
                e = mid - 1;
            }

            if(target > nums[mid]){
                s = mid + 1;
            }

        }

        return ans;
    }


    // Allocate minimum number of pages
    // https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

    bool isPossible(int arr[], int n, int m, int mid){
        int cnt = 0;
        int temp = 0;
        
        for(int i=0; i<n; i++){
            temp += arr[i];
            if(temp > mid){
                cnt ++;
                temp = arr[i];
            }
        }
        
        if(temp > 0) cnt++;
        
        if(cnt <= m){
            return true;
        }
        
        return false;
    }
    
    long long findPages(int n, int arr[], int m) {
        int s = -1, e = 0;
        int ans = -1;
        
        if(n < m){
            return ans;
        }
        
        for(int i=0; i<n; i++){
            e += arr[i];
            s = max(s, arr[i]);
        }
            
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(isPossible(arr, n, m, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }


    // 410. Split Array Largest Sum
    // https://leetcode.com/problems/split-array-largest-sum/description/

    bool isPossible(vector<int>& nums, int n, int k, int mid){
        int cnt = 0, temp = 0;

        for(int i=0; i<n; i++){
            temp += nums[i];

            if(temp > mid){
                temp = nums[i];
                cnt++;
            }
        }

        if(temp > 0) cnt++;

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int s = -1, e = 0, ans = -1;
        int n = nums.size();

        if(n < k){
            return ans;
        }

        for(int i=0; i<nums.size(); i++){
            s = max(s, nums[i]);
            e += nums[i];
        }

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(isPossible(nums, n, k, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};