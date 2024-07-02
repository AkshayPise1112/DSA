#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 35. Search Insert Position
    // https://leetcode.com/problems/search-insert-position/

    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        if(nums[0] > target){
            return 0;
        }
        if(nums[nums.size() - 1] < target){
            return nums.size();
        }

        while(s <= e){
            int mid = s + (e - s) / 2;


            if(nums[mid] == target || (nums[mid] > target && nums[mid - 1] < target)){
                ans = mid;
                break;
            }

            if(nums[mid] < target){
                s = mid+1;
            }

            if(nums[mid] > target){
                e = mid - 1;
            }
        }

        return ans;
    }


    // 1283. Find the Smallest Divisor Given a Threshold
    // https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

    bool validDivisor(vector<int> &nums, int threshold, int mid){
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += ceil(nums[i] / (double) mid);
        }

        return ans <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MAX;
        int mini = 1;
        int ans;

        while(mini <= maxi){
            int mid = mini + (maxi - mini) / 2;

            if(validDivisor(nums, threshold, mid)){
                ans = mid;
                maxi = mid-1;
            }
            else{
                mini = mid+1;
            }
        }

        return ans;
    }

    

    // 1482. Minimum Number of Days to Make m Bouquets
    // https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

    bool isPossible(vector<int> &nums, int n, int m, int k, int mid){
        int ans = 0, cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] <= mid){
                cnt++;
            }
            else{
                ans += (cnt / k);
                cnt = 0;
            }
        }
        
        ans += (cnt / k);

        if(ans >= m){
            return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), ans = -1;

        long long val = m * 1LL * k * 1LL;

        if(val > n){
            return ans;
        }

        int e = INT_MIN, s = INT_MAX;

        for(int i=0; i<n; i++){
            e = max(e, bloomDay[i]);
            s = min(s, bloomDay[i]);
        }

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(isPossible(bloomDay, n, m, k, mid)){
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
