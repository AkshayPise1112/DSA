#include<bits/stdc++.h>
using namespace std;
class solution{
    public:

    // Number of occurrence
    // https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

    int firstOccurrence(int arr[], int n, int x) {
        int low = 0, high = n - 1, first = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                first = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }
     
     int lastOccurrence(int arr[], int n, int x) {
        int low = 0, high = n - 1, last = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                last = mid;
                low = mid + 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

    
    int count(int arr[], int n, int x) {
        int first = firstOccurrence(arr, n, x);
        if (first == -1) {
            return 0; 
        }
        int last = lastOccurrence(arr, n, x);
        return last - first + 1;
    }

    // 1539. Kth Missing Positive Number
    // https://leetcode.com/problems/kth-missing-positive-number/

    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] - mid > k) {
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low + k;
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
};