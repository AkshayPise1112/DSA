#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    
    // 51. N-Queens
    // https://leetcode.com/problems/n-queens/

    bool isSafe(vector<string>& output, int row, int col, int n){
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(output[i][j] == 'Q') return false;
        }

        for(int i=row+1, j=col-1; i<n && j>=0; i++, j--){
            if(output[i][j] == 'Q') return false;
        }

        for(int i=0; i<col; i++){
            if(output[row][i] == 'Q') return false;
        }

        return true;
    }

    void solve(int n, vector<string>& output, vector<vector<string>> &ans, int col){
        if(col >= n){
            ans.push_back(output);
            return;
        }

        for(int i=0; i<n; i++){
            if(isSafe(output, i, col, n)){
                output[i][col] = 'Q';
                solve(n, output, ans, col+1);
                output[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string a(n, '.');
        vector<string> output(n, a);
        solve(n, output, ans, 0);
        return ans;
    }

    // 37. Sudoku Solver
    // https://leetcode.com/problems/sudoku-solver/

    bool isAns(vector<vector<char>> &board, int row, int col, char k){
        for(int i=0; i<9; i++){
            if(board[row][i] == k){
                return false;
            }

            if(board[i][col] == k){
                return false;
            }

            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == k){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '.'){
                    for(char k='1'; k<='9'; k++){
                        if(isAns(board, i, j, k)){
                            board[i][j] = k;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }


    // 139. Word Break
    // https://leetcode.com/problems/word-break/

    bool solve(string s, unordered_set<string>& dict, int index, vector<int>& dp){
        if(index >= s.size()){
            return true;
        }

        if(dp[index] != -1) return dp[index];

        string temp = "";
        bool ans = false;

        for(int i=index; i<s.size(); i++){
            temp += s[i];
            if(dict.find(temp) != dict.end()){
                if(solve(s, dict, i+1, dp)) return dp[index] = 1;
            }
        }

        return dp[index] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size()+1, -1);

        for(auto it: wordDict){
            st.insert(it);
        }

        return solve(s, st, 0, dp);
    }
};