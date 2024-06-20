#include<bits/stdc++.h>
using namespace std;
class solution{
    // Union of Two Sorted Arrays
    // https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

     vector<int> optimized(int arr1[], int arr2[], int n, int m){
        vector<int>result;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
        }
        for(int i=0;i<m;i++){
            s.insert(arr2[i]);
        }
    
        for(auto it=s.begin();it!=s.end();it++){
             result.push_back(it);
        }
        return result;
    }
   
   
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        
        int prev = min(arr1[0], arr2[0]);
        
        ans.push_back(prev);
        int i=0, j=0;
        
        for(; i<n && j<m; ){
            if(arr1[i] <= arr2[j] && prev != arr1[i]){
                ans.push_back(arr1[i]);
                prev = arr1[i];
                i++;
            }
            else if(arr1[i] > arr2[j] && prev != arr2[j]){
                ans.push_back(arr2[j]);
                prev = arr2[j];
                j++;
            }
            
            if(prev == arr1[i]){
                
                i++;
            }
            if(prev == arr2[j]){
                j++;
            }
        }
        
        while(i < n){
            if(prev == arr1[i]){
                i++;
                continue;
            }   
            ans.push_back(arr1[i]);
            prev = arr1[i];
            i++;
        }
        
        while(j < m){
            if(prev == arr2[j]){
                j++;
                continue;
            }
            ans.push_back(arr2[j]);
            prev = arr2[j];
            j++;
        }
        
        return ans;
    }


    // 31. Next Permutation
    // https://leetcode.com/problems/next-permutation/
    
    void nextPermutation(vector<int>& nums) {
        int low  = -1;
        int n = nums.size();

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                low = i;
                break;
            }
        }

        if(low == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>low; i--){
            if(nums[i] > nums[low]){
                swap(nums[i], nums[low]);
                break;
            }
        }

        reverse(nums.begin() + (low+1) , nums.end());
    }

    // Missing And Repeating
    // https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

    vector<int> findTwoElement(vector<int> arr, int n) {
        
        vector<bool> temp(n+1, false);
        int missing, repeat;
        
        for(int i=0; i<n; i++){
            
            if(temp[arr[i]] == true){
                repeat = arr[i];
            }
            else{
                temp[arr[i]] = true;
            }
        }
        
        for(int i=1; i<=n; i++){
            if(temp[i] == false){
                missing = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(repeat);
        ans.push_back(missing);
        
        return ans;
    }
};