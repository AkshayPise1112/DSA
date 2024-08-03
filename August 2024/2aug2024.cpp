#include<bits/stdc++.h>
using namespace std;

class solution{

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

    // 13. Roman to Integer
    // https://leetcode.com/problems/roman-to-integer/description/

    int romanToInt(string s) {
        int prev = 0;
        int ans = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'I'){
                ans += 1;
                cout << ans << "  ";
                prev = 1;
            }
            if(s[i] == 'V'){
                if(prev == 1){
                    ans -= 1;
                    ans += 4;
                    continue;
                }
                ans += 5;
                prev = 5;
            }
            if(s[i] == 'X'){
                if(prev == 1){
                    ans -= 1;
                    ans += 9;
                    continue; 
                }
                ans += 10;
                prev = 10;
            }
            if(s[i] == 'L'){
                if(prev == 10){
                    ans -= 10;
                    ans += 40;
                    continue;
                }
                ans += 50;
                prev = 50;
            }
            if(s[i] == 'C'){
                if(prev == 10){
                    ans -= 10;
                    ans += 90;
                    continue;
                }
                ans += 100;
                prev = 100;
            }
            if(s[i] == 'D'){
                if(prev == 100){
                    ans -= 100;
                    ans += 400;
                    continue; 
                }
                ans += 500;
                prev = 500;
            }
            if(s[i] == 'M'){
                if(prev == 100){
                    ans -= 100;
                    ans += 900;
                    continue;
                }
                ans += 1000;
                prev = 1000;
            }
        }

        return ans;
    }


    // 8. String to Integer (atoi)
    // https://leetcode.com/problems/string-to-integer-atoi/

    int myAtoi(string s) {
        __int128 ans = 0;
        int ispositive = 1;

        int i=0;
        while(i < s.length()){
            if(s[i] != ' '){
                break;
            }
            i++;
        }

        if(s[i] == '-'){
            ispositive = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        while(i < s.length()){
            if(s[i] >= '0' && s[i] <= '9'){
                ans *= 10;
                int temp = int(s[i]) - 48;
                ans += temp;
            }
            else{
                break;
            }
            i++;

            if(ans * ispositive > pow(2, 31) - 1 || ans * ispositive < -pow(2, 31)){
                ans = ans * ispositive;
                if(ans > pow(2, 31) - 1){
                    return pow(2, 31) - 1;
                }
                else if(ans < -(pow(2, 31))){
                    return -pow(2, 31);
                }
            }
        }

        ans = ans * ispositive;

        return ans;
    }
};