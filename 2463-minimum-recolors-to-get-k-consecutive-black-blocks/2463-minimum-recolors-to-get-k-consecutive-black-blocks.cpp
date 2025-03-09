class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int ans = INT_MAX;
        int n = blocks.length();
        
        for(int i=0;i<=n-k;i++)
        {
            int cnt=0;
            for(int j=i;j<i+k;j++)
            {
                if(blocks[j]=='W') 
                    cnt++;
            }
            ans  = min(ans,cnt);
        }
        return ans;
    }
};