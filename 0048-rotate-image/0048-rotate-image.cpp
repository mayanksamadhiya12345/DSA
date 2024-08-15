class Solution {
public:
    void rotate(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            int st_col = 0;
            int en_col = m-1;
            while(st_col < en_col)
            {
                swap(mat[i][st_col++], mat[i][en_col--]);
            }
        }
    }
};