#include<bits/stdc++.h>
using namespace std;

class solution{
    public: 
    // 485. Max Consecutive Ones
    // https://leetcode.com/problems/max-consecutive-ones/description/

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                curr++;
                maxi = max(maxi, curr);
            }

            if(nums[i] == 0){
                curr = 0;
            }
        }

        return maxi;
    }

    // Longest consecutive subsequence
    // https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/0?problemType=functional&page=1&query=problemTypefunctionalpage1
    

    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr, arr+N);
        int maxi = 1;
        int curr = 0;
        int prev = INT_MIN;
        
        for(int i=0; i<N; i++){
            if(prev == arr[i]){
                continue;
            }
            if(prev == (arr[i] - 1)){
                curr += 1;
                prev = arr[i];
            }
            if(prev != arr[i]){
                curr = 1;
                prev = arr[i];
            }
                maxi = max(curr, maxi);
        }
        
        return maxi;
    }


    // 493. Reverse Pairs
    // https://leetcode.com/problems/reverse-pairs/

    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }

    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }

};