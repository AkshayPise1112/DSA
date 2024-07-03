#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // Check if array is sorted
    // https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

    bool arraySortedOrNot(int arr[], int n) {
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    

    // 1011. Capacity To Ship Packages Within D Days
    // https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

    bool isPossible(vector<int>& nums, int days, int mid){
        int cnt = 0, ans = 0;

        for(int i=0; i<nums.size(); i++){

            if((cnt + nums[i]) <= mid){
                cnt += nums[i];
            }
            else{
                cnt = nums[i];
                ans++;
            }
        }

        if(cnt > 0) ans++;

        return ans <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(),weights.end());
        int e = accumulate(weights.begin(),weights.end(),0);
        int ans;

        while(s <= e){
            int mid = (s + e) / 2;
            if(isPossible(weights, days, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }


    // 4. Median of Two Sorted Arrays
    // https://leetcode.com/problems/median-of-two-sorted-arrays/description/

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int len1 = nums1.size();
        int len2 = nums2.size();

        vector<int> ans;
        int i=0, j=0;

        while(i<len1 && j<len2){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<len1){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < len2){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = merge(nums1, nums2);
        int n = ans.size();

        if(n%2 == 0){
            int median1 = n / 2;
            double ans1 = (double (ans[median1]) + double (ans[median1 - 1])) / 2;
            return ans1;
        }

        return ans[n/2];
    }
};