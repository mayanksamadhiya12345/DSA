class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem=0, curr=0;
        int ans = numBottles;
        curr = numBottles/numExchange;
        rem = numBottles%numExchange;
        cout<<curr<<" "<<rem<<" "<<ans<<endl;

        while(curr) {
            ans += curr;
            curr += rem;
            rem = curr%numExchange;
            curr = curr/numExchange;

            cout<<curr<<" "<<rem<<" "<<ans<<endl;
        }
        return ans;
    }
};