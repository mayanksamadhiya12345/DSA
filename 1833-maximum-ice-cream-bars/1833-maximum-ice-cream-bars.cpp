class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(),costs.end());
        if(costs[0] > coins) return 0;
        
        int count=0;
        int i=0;
        while(coins && i<costs.size())
        {
            if(costs[i] <= coins)
            {
                count++;
                coins -= costs[i++];
            }
            else
            {
                break;
            }
        }
        return count;
    }
};