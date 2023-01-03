class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int n = strs.size();
        int m = strs[0].size();
        
        int ans=0;
        
        // just check for each column, and if we got wrong lexicographically order just remove that and incraese count by 1
        for(int j=0;j<m;j++)        // each column
        {
            for(int i=1;i<n;i++)    // each row
            {
                if(strs[i-1][j] > strs[i][j])
                {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};