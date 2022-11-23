class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        map<int,set<int>> rows;
        map<int,set<int>> cols;
        map<pair<int,int>,set<int>> subBox;
        
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                // if it is . skip it
                if(board[r][c]=='.') continue;
                
                // if we found current value previously then return false
                
                // Check row
                if(rows[r].find(board[r][c]-'0') != rows[r].end())
                    return false;
                
                // check col
                if(cols[c].find(board[r][c]-'0') != cols[c].end())
                    return false;
                
                // check sub boxes
                if(subBox[{r/3,c/3}].find(board[r][c]-'0') != subBox[{r/3,c/3}].end())
                    return false;
                
                
                // if none of then return false then add curr board value to the declared set for next check
                rows[r].insert(board[r][c]-'0');
                cols[c].insert(board[r][c]-'0');
                subBox[{r/3,c/3}].insert(board[r][c]-'0');
            }
        }
        
        return true;
    }
};