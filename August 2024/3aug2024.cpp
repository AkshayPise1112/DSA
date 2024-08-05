#include<bits/stdc++.h>

using namespace std;

class solutions{
    // 1903. Largest Odd Number in String
    // https://leetcode.com/problems/largest-odd-number-in-string/

    string largestOddNumber(string num) {
        string ans = "";

        for(int i=num.length()-1; i>=0; i--){
            if((int(num[i]) - 48) % 2 == 1){
                return num.substr(0, i+1);
            }
        }

        return ans;
    }


    // 5. Longest Palindromic Substring
    //https://leetcode.com/problems/longest-palindromic-substring/

    string longestPalindrome(string s) {
        int n = s.length();

        int startIndex = 0;
        int endIndex = 0;


        for(int i=0; i<n; i++){
            for(int j=n-1; j>=i; j--){
                if(s[i] == s[j]){
                    int tempStart = i;
                    int tempEnd = j;
                    int a=i, b=j;
                    bool flag = true;
                    while(a <= b){
                        if(s[a] == s[b]){
                            a++;
                            b--;
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        tempStart = 0;
                        tempEnd = 0;
                    }
                    if((tempEnd - tempStart) > (endIndex - startIndex)){
                        endIndex = tempEnd;
                        startIndex = tempStart;
                    }
                }
            }
        }

        string ans = "";

        for(int i=startIndex; i<=endIndex; i++){
            ans += s[i];
        }

        return ans;
    }


    // Count number of substrings
    // https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

    long long int atleast(string s, int k) 
    {
    
        long long int n = s.length();
        vector<int> mp(26,0);
        int count = 0;
        long long int ans = 0;
    
        long long int i = 0, j = 0;
    
        while (j < n) 
        {
            if (mp[s[j]-'a'] == 0) count++;
            
            mp[s[j]-'a']++;
            
            if (count >= k) 
            {
                ans += (n - j);  
    
                while (count >= k) 
                {
                    if (--mp[s[i++]-'a'] == 0) count--;
                    else ans += (n - j);
                }
            }
    
            j++;
        }
    
        return ans;
    }

    long long int substrCount(string s, int k) 
    {
        return atleast(s, k) - atleast(s, k+1);
    }

};