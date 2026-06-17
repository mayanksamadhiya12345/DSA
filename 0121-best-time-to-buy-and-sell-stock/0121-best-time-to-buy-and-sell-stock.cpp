class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = INT_MIN, mn_price = INT_MAX;
        for(int i=0;i<n;i++) {
            mn_price = min(mn_price, prices[i]);
            ans = max(ans, prices[i]-mn_price);
        }
        cout<<mn_price<<" "<<ans;
        return ans;
    }
};