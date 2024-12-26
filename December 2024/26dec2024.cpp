#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 383. Ransom Note
    // https://leetcode.com/problems/ransom-note/

    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        for(auto it: magazine){
            if(mp.find(it) == mp.end()){
                mp[it] = 1;
            }
            else{
                mp[it]++;
            }
        }

        for(auto it: ransomNote){
            if(mp.find(it) == mp.end() || mp[it] <= 0) return false;

            mp[it]--;
        }

        return true;
    }
}