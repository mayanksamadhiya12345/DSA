class Solution {
public:
    bool isPossible(int row,int col, char k, vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == k) return false;
            if(board[row][i] == k) return false;
            if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == k) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == '.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isPossible(i,j,k,board))
                        {
                            board[i][j] = k;
                            if(solve(board)) return true;

                            board[i][j] = '.';
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
};