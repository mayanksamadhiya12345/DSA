class Solution {
public:
    int solve(int i, int n, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int mx_Profit = INT_MIN;
        if(buy) {
            int buy = -prices[i] + solve(i+1, n, 0, prices, dp);
            int not_buy = 0 + solve(i+1, n, 1, prices, dp);
            mx_Profit = max(buy, not_buy);
        }
        else {
            int sell = prices[i] + solve(i+1, n, 1, prices, dp);
            int not_sell = 0 + solve(i+1, n, 0, prices, dp);
            mx_Profit = max(sell, not_sell);
        }

        return dp[i][buy] = mx_Profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (3, 0));

        for(int i=n-1;i>=0;i--) {
            for(int buy=0;buy<2;buy++) {
                int mx_Profit = INT_MIN;
                if(buy) {
                    int buy = -prices[i] + dp[i+1][0];
                    int not_buy = 0 + dp[i+1][1];
                    mx_Profit = max(buy, not_buy);
                }
                else {
                    int sell = prices[i] + dp[i+1][1];
                    int not_sell = 0 + dp[i+1][0];
                    mx_Profit = max(sell, not_sell);
                }
                dp[i][buy] = mx_Profit;
            }
        }
        return dp[0][1];
    }
};