#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // Ceil The Floor
    // https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

    pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
        int mini = -1;
        int maxi = INT_MAX;

        for(int i=0; i<n; i++){
            if(arr[i] == x){
                return make_pair(x, x);
            }
            if(arr[i] > mini && arr[i] < x){
                mini = arr[i];
            }
            if(arr[i] < maxi && arr[i] > x){
                maxi = arr[i];
            }
        }
        
        if(maxi == INT_MAX){
            return make_pair(mini, -1);
        }
        
        return make_pair(mini, maxi);
    }

    // 875. Koko Eating Bananas
    // https://leetcode.com/problems/koko-eating-bananas/description/

    bool possible(vector<int> piles, int mid, int h){
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += piles[i]/mid;
            piles[i] %= mid;
            if(piles[i] > 0) hours++;
            if(hours > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(min <= max){
            int mid = (min + max)/2;
            if(possible(piles,mid,h)){
                ans = mid;
                max = mid - 1;
            }
            else{
                min = mid + 1;
            }
        }
        return ans;
    }

    // Median in a row-wise sorted Matrix
    // https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

    int bruteForce(vector<vector<int>> &matrix, int R, int C){
        // vector<int> sorted_array;
        
        // for(int i=0; i<R; i++){
        //     for(int j=0, k=0; j<C; j++){
        //         sorted_array.push_back(matrix[i][j]);
        //     }
        // }
        
        // sort(sorted_array.begin(), sorted_array.end());
        
        // int mid = (R * C) / 2;
        
        // return sorted_array[mid];
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int low = INT_MAX, high = -1;
        
        for(int i=0; i<R; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C-1]);
        }
        
        int ans;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            int cnt = 0;
            
            for(int i=0; i<R; i++){
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(cnt >= (R * C + 1) / 2){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};


