#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 392. Is Subsequence
    // https://leetcode.com/problems/is-subsequence/

    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        int i = 0;
        int flag = false;
        for(auto it: t){
            if(s[i] == it) i++;
            if(i >= s.size()){
                flag = true;
                break;
            }
        }

        return flag;
    }
}