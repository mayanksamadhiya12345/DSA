class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n  = prices.size();
        vector<int> ahead2(2,0);
        vector<int> ahead1(2,0);
        vector<int> curr(2,0);
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1) curr[buy] = max(-prices[idx]+ahead1[0],ahead1[1]);
                else curr[buy] = max(prices[idx]+ahead2[1],ahead1[0]);
            }
            ahead2=ahead1;
            ahead1=curr;
        }
        return ahead1[1];
    }
};