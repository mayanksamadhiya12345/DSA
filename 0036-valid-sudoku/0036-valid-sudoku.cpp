class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> rows, cols;
        map<pair<int, int>, set<int>> subBox;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') continue;

                if(rows[i].find(board[i][j]-'0') != rows[i].end()) return false;
                if(cols[j].find(board[i][j]-'0') != cols[j].end()) return false;
                if(subBox[{i/3,j/3}].find(board[i][j]-'0') != subBox[{i/3,j/3}].end()) return false;

                rows[i].insert(board[i][j]-'0');
                cols[j].insert(board[i][j]-'0');
                subBox[{i/3,j/3}].insert(board[i][j]-'0');
            }
        }
        return true;
    }
};