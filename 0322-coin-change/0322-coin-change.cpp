class Solution {
public:
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(i==0) {
            if(amount%coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int take = 1e9;
        if(amount >= coins[i]) {
            take = 1 + solve(i, coins, amount-coins[i], dp);
        }

        int not_take = solve(i-1, coins, amount, dp);
        return dp[i][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        vector<int> curr(amount+1, 0), prev(amount+1, 0);
        for(int am=0;am<=amount;am++) {
            if(am%coins[0] == 0) prev[am] = am/coins[0];
            else prev[am] = 1e9;
        }

        for(int i=1;i<n;i++) {
            for(int am=0;am<=amount;am++) {
                int take = 1e9;
                if(am >= coins[i]) {
                    take = 1 + curr[am-coins[i]];
                }

                int not_take = 1e9; 
                if(i>0) not_take = prev[am];
                curr[am] = min(take, not_take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return ans>=1e9 ? -1 : ans;
    }
};