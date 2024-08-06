#include<bits/stdc++.h>
using namespace std;

class solution{
    public: 

    // 14. Longest Common Prefix
    // https://leetcode.com/problems/longest-common-prefix/

    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }

        return ans;
    }

    // 1781. Sum of Beauty of All Substrings
    // https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

    int beauty(vector<int> &mp){
        int maxi = -1;
        int mini = INT_MAX;

        for(int i=0; i<26; i++){
            maxi = max(maxi, mp[i]);
            if(mp[i] >= 1){
                mini = min(mini, mp[i]);
            }
        }

        return maxi - mini;
    }

    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            vector<int> mp(26, 0);
            for(int j=i; j<n; j++){
                mp[s[j] - 'a'] ++;
                ans += beauty(mp);
            }
        }

        return ans;
    }



    // 205. Isomorphic Strings
    // https://leetcode.com/problems/isomorphic-strings/

    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> mp;
        unordered_map<char, char> tmp;
       
        for(int i=0; i<n; i++){
            if(mp.find(s[i]) == mp.end()){
                if(tmp.find(t[i]) == tmp.end() || tmp[t[i]] == s[i]){
                    mp[s[i]] = t[i];
                    tmp[t[i]] = s[i];
                }
                else{
                    return false;
                }
            }
            else if(mp[s[i]] != t[i]){
                return false;
            }
        }

        return true;
    }
};
