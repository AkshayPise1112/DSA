#include<bits/stdc++.h>
using namespace std;

class solution{

    // Sorted Array Search
    // https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1
    
    
    int binarySearch(int arr[], int n, int s, int e, int k){
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
    
            if (arr[mid] == k){
                ans = 1;
            }
    
            if (arr[mid] < k)
                s = mid + 1;
    
            else
                e = mid - 1;
        }
    
        return ans;
    }
    
    int searchInSorted(int arr[], int N, int K) 
    { 
        return binarySearch(arr, N, 0, N-1, K);
       
       
    }


    // 2149. Rearrange Array Elements by Sign
    // https://leetcode.com/problems/rearrange-array-elements-by-sign/

    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a, b, ans;
        for(auto i: nums){
            if(i < 0){
                a.push_back(i);
            }
            else{
                b.push_back(i);
            }
        }

        for(int i=0, j=0; i<nums.size()/2, j<nums.size()/2;){
            ans.push_back(b[i]);
            i++;
            ans.push_back(a[j]);
            j++;
        }

        return ans;
    }


    // 88. Merge Sorted Array
    // https://leetcode.com/problems/merge-sorted-array/description/

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        int k = nums1.size()-1;
        int i=m-1, j=n-1; 
        while(j >= 0){
            if( i >= 0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
    }
};