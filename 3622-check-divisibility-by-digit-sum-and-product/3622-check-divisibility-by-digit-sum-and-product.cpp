class Solution {
public:
    bool checkDivisibility(int n) {
        int pro=1;
        int sum=0;
        int val=n;
        while(n) {
            int rem = n%10;
            pro *= rem;
            sum += rem;
            n /= 10;
        }

        bool ans = val%(sum+pro) == 0 ? true : false;
        return ans;
    }
};