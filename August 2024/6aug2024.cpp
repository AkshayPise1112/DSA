#include<bits/stdc++.h>
using namespace std;

class solution{
    public: 

    // 151. Reverse Words in a String
    // https://leetcode.com/problems/reverse-words-in-a-string/

    string reverseWords(string s) {
        vector<string> st;
        string temp = "", ans = "";

        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                if(temp == ""){
                    continue;
                }
                st.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }

        if(temp != ""){
            st.push_back(temp);
        }

        int n = st.size();

        ans += st[n-1];

        for(int i=n-2; i>=0; i--){
            ans += ' ';
            ans += st[i];
        }

        return ans;
    }

    // 796. Rotate String
    // https://leetcode.com/problems/rotate-string/

    bool rotateString(string s, string goal) {
        int j=0, i=0;

        if(s.size() < goal.size() || s.size() > goal.size()){
            return false;
        }

        for(i=0; i<s.size(); i++){
            if(s[i] == goal[j]){
                j++;
            }
            else if(j != 0 && s[i] != goal[j] && s[i] == goal[0]){
                j = 1;
            }
            else{
                j = 0;
            }
            
        }

        i = 0;

        while(j < goal.size()){
            if(s[i] == goal[j]){
                i++;
                j++;
            }
            else{
                return false;
            }
        }

        return true;
    }

    // 242. Valid Anagram
    // https://leetcode.com/problems/valid-anagram/

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> mp(26, 0);

        for(int i=0; i<s.size(); i++){
            mp[s[i] - 'a'] ++; 
        }

        for(int i=0; i<t.size(); i++){
            if(mp[t[i] - 'a'] == 0){
                return false;
            }
            mp[t[i] - 'a']--;
        }

        return true;
    }
};