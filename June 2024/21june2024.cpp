#include<bits/stdc++.h>
using namespace std;

class solution{
    // 268. Missing Number
    // https://leetcode.com/problems/missing-number/

    int xorApproach(vector<int>& nums){
        int x = 0;
        int n = nums.size();

        for(int i=0; i<n+1; i++){
            x = x ^ i;
        }

        for(int i=0; i<n; i++){
            x = x ^ nums[i];
        }

        return x;
    }

    int mathApproach(vector<int> &nums){
        int n = nums.size();
        int total = (n * (n + 1)) / 2;

        for(int i=0; i<n; i++){
            total = total - nums[i];
        }

        return total;
    }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n+1, false);
        int ans;

        for(int i=0; i<n; i++){
            vis[nums[i]] = true;
        }

        for(int i=0; i<=n; i++){
            if(vis[i] == false){
                ans = i;
            }
        }

        return ans;
    }


    // Array Leaders
    // https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

    vector<int> leaders(int n, int arr[]) {
        int max = 0;
        vector<int> ans;
        
        for(int i=n-1; i>=0; i--){
            if(max <= arr[i]){
                max = arr[i];
                ans.push_back(arr[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // Count Inversions
    // https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

    void mergeSortedArray(long long arr[], long long start,long long end, long long mid,long long int &count){
          vector<long long> tempArray;
          
          long long index1 = start;
          long long index2 = mid+1;
    
          while(index1 <= mid && index2 <= end){
              if(arr[index1] <= arr[index2]){
                  tempArray.push_back(arr[index1++]);
              }
              else{
                  tempArray.push_back(arr[index2++]);
                  count += mid + 1 - index1;
              }
          }
          
          while(index1 <= mid){
              tempArray.push_back(arr[index1++]);
          }
          
          while(index2 <= end){
              tempArray.push_back(arr[index2++]);
          }
          
          for(int i = 0; i < tempArray.size() && start <= end; i++){
              arr[start++] = tempArray[i];
          }
          
         return;
      }
      
      void mergeSort(long long arr[], long long start, long long end, long long int &count){
          if(start == end){
              return ;
          }
          long long mid = start + (end - start) / 2;
          mergeSort(arr, start, mid, count);
          
          mergeSort(arr, mid+1, end, count);
          
          mergeSortedArray(arr, start, end, mid, count);
      }
    long long int inversionCount(long long arr[], long long N)
    {
       long long  start = 0;
       long long end = N - 1;
       long long int count = 0;
       mergeSort(arr, start, end, count);
       
       return count;
    }
};