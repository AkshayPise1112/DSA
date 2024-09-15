#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    
    // 90. Subsets II
    // https://leetcode.com/problems/subsets-ii/

    void solve(vector<vector<int>>& ans, vector<int> &nums, int index, vector<int> &prev){
        if(index >= nums.size()){
            ans.push_back(prev);
            return;
        }

        // include
        prev.push_back(nums[index]);
        solve(ans, nums, index+1, prev);
        prev.pop_back();

        // exclude
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }

        solve(ans, nums, index+1, prev);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> prev;
        solve(ans, nums, 0, prev);
        return ans;
    }

    
    // 17. Letter Combinations of a Phone Number
    // https://leetcode.com/problems/letter-combinations-of-a-phone-number/

    void solve(string& digits, vector<string>& mp, vector<string> &ans, string &output, int index){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }

        int currDigit = digits[index] - '0';

        for(int i=0; i<mp[currDigit].size(); i++){
            output.push_back(mp[currDigit][i]);
            solve(digits, mp, ans, output, index+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;

        if(digits == ""){
            return ans;
        }

        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, mp, ans, output, 0);

        return ans;
    }

    // 79. Word Search
    // https://leetcode.com/problems/word-search/

    bool solve(vector<vector<char>>& board, string& word, int row, int col, int i){
        if(i >= word.size()){
            return true;
        }

        if((row < 0 || col < 0) || (row >= board.size() || col >= board[0].size() || board[row][col] != word[i])){
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '#';

        bool ans1 = solve(board, word, row+1, col, i+1);
        bool ans2 = solve(board, word, row-1, col, i+1);
        bool ans3 = solve(board, word, row, col+1, i+1);
        bool ans4 = solve(board, word, row, col-1, i+1);

        board[row][col] = ch;


        return ans1 || ans2 || ans3 || ans4;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){

                if(solve(board, word, i, j, 0)){
                    return true;
                }
                
            }
        }

        return false;
    }
};