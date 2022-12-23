class Solution {
public:
    int find(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(idx>=prices.size()) return 0;                       // we are using idx+2 that's why >=
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        if(buy==1)
        {
            return dp[idx][buy] = max(-prices[idx]+find(idx+1,0,prices,dp),0+find(idx+1,1,prices,dp));
        }
        else
        {
                // idx+2 because we can not buy just after selling
            return dp[idx][buy] = max(prices[idx]+find(idx+2,1,prices,dp),0+find(idx+1,0,prices,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int n  = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return find(0,1,prices,dp);
    }
};