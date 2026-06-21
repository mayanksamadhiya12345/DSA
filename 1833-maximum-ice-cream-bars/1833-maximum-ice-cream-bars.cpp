class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int> mp;

        for(auto&it : costs) {
            mp[it]++;
        }

        int ans = 0;
        for(auto&it : mp) {
            int curr_price = it.first;
            int no_of_times = it.second;
            while(coins >= curr_price && no_of_times) {
                ans++;
                coins -= curr_price;
                no_of_times--;
            }
            cout<<it.first<<" "<<it.second<<endl;
        }

        return ans;
    }
};