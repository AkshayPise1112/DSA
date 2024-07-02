#include<iostream>
#include<vector>
using namespace std;

class solutions{

    //Searching an element in a sorted array
    //https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1
    
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


    //2149. Rearrange Array Elements by Sign
    //https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

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

    //Subsets with XOR value
    //https://www.geeksforgeeks.org/problems/subsets-with-xor-value2023/1

    int solve(int i, int x, int n, int k, vector<int> &arr){
        if(i >= n){
            if(x == k){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int a1 = solve(i+1, x^arr[i], n, k, arr);
        int a2 = solve(i+1, x, n, k, arr);
        
        return a1 + a2;
    }
   
    
    
    int subsetXOR(vector<int> arr, int N, int K) {
        
        return solve(0, 0, N, K, arr);
    }
};

