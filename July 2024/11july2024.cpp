#include<bits/stdc++.h>
using namespace std;

class solution {

    // 540. Single Element in a Sorted Array
    // https://leetcode.com/problems/single-element-in-a-sorted-array/

    int singleNonDuplicate(vector<int>& nums) {
        // int i=0, j=1;
        // if(nums.size() == 1){
        //     return nums[0];
        // }
        
        // while(i < nums.size()-1 && j < nums.size()){
        //     if(nums[i] == nums[j]){
        //         i += 2;
        //         j += 2;
        //         continue;
        //     }
        //     else{
        //         return nums[i];
        //     }
        // }

        // return nums[nums.size()-1];

        int n = nums.size();

        if(n == 1 || nums[0] != nums[1]){
            return nums[0];
        }

        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }

        int s = 1;
        int e = n-2;

        int ans;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]){
                return nums[mid];
            }
            else if((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return -1;
    }

    // K-th element of two Arrays
    // https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0, j=0, count=1;
        
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                if(count==k) return arr1[i];
                count++;
                i++;
            } else {
                if(count==k) return arr2[j];
                count++;
                j++;
            }
        }
        
        while(i<n){
           if(count==k) return arr1[i];
           i++;
           count++;
        }
        
        while(j<m){
           if(count==k) return arr2[j];
           j++;
           count++;
        }
    }

    // Find Kth Rotation
    // https://www.geeksforgeeks.org/problems/rotation4723/1

    int findKRotation(vector<int> &arr) {
        
        // int n = arr.size();
        
        // if(n == 1){
        //     return 0;
        // }
        
        // int prev = arr[0];
        
        // for(int i=1; i<n; i++){
        //     if(prev > arr[i]){
        //         return i;
        //     }
        // }
        
        // return 0;
        
        
        int n = arr.size();
        
        if(n == 1){
            return 0;
        }
        
        if(arr[0] > arr[1]){
            return 1;
        }
        
        if(arr[n-1] < arr[n - 2]){
            return n-1;
        }
        
        int s = 1; 
        int e = n-2;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(arr[mid] < arr[mid-1] && arr[mid] <= arr[mid+1]){
                return mid;
            }
            
            if(arr[mid] < arr[e]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        
        return 0;
    }

};