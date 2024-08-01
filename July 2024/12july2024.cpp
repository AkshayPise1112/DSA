#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    //1021. Remove Outermost Parentheses
    //https://leetcode.com/problems/remove-outermost-parentheses/submissions/1338078128/

    string removeOuterParentheses(string s) {
        int outer = 0, inner = 0;
        string ans;

        for(int i=0; i<s.length(); i++){
            if(outer == 0){
                outer++;
                continue;
            }
            if(outer != 0 && s[i] == '('){
                ans += s[i];
                inner++;
                continue;
            }
            if(inner != 0 && s[i] == ')'){
                ans += s[i];
                inner--;
                continue;
            }
            if(inner == 0 && s[i] == ')'){
                outer--;
                continue;
            }
        }

        return ans;
    }


    // 451. Sort Characters By Frequency
    // https://leetcode.com/problems/sort-characters-by-frequency/description/

    string frequencySort(string s) {
        vector<pair<int, char>> hash('z'+1, {0, 0});
        string ans = "";

        for(auto it: s){
            hash[it] = {hash[it].first+1, it};
        }

        auto lambda = [&](pair<int, char> &p1, pair<int, char> &p2){
            return p1.first > p2.first;
        };

        sort(hash.begin(), hash.end(), lambda);

        for(auto it: hash){
            while(it.first > 0){
                ans += it.second;
                it.first--;
            }
        }

        return ans;
    }


    // 1614. Maximum Nesting Depth of the Parentheses
    // https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0;

        for(auto it: s){
            if(it == '('){
                st.push(it);
                if(maxi < st.size()){
                    maxi = st.size();
                }
            }
            if(it == ')'){
                st.pop();
            }
        }

        return maxi;
    }
};