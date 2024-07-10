class Solution {
public:
    void solve(int col,int n,vector<string>& board,vector<vector<string>>& ans,vector<int>&left,vector<int>&upper,vector<int>&lower)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(left[row]==0 && upper[col+row]==0 && lower[col-row+n-1]==0)
            {
                board[row][col]='Q';                 // store to Q afetr all three condition
                
                // make the hashmap from 0 to 1
                left[row]=1; 
                upper[row+col]=1;
                lower[n-1+col-row]=1;
                
                // recursion
                solve(col+1,n,board,ans,left,upper,lower);
                
                // BackTracking
                board[row][col]='.';
                left[row]=0;
                upper[row+col]=0;
                lower[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }

        vector<int> left(n,0);
        vector<int> upper(2*n-1,0);
        vector<int> lower(2*n-1,0);
        solve(0,n,board,ans,left,upper,lower);
        return ans;
    }
};