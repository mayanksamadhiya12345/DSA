class Solution {
public:
#define md 1000000007
    int numTilings(int n) 
    {
        vector<long long> v(1001, 0);

        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        
        for(int i = 4; i <= n; i++)
            v[i] = (2 * v[i-1] + v[i-3]) % md;
        
    return v[n];
    }
};




// tested on few testcases

// n = 1 : ans = 1
// n = 2 : ans = 2
// n = 3 : ans = 5
// n = 4 : ans = 11
// n = 5 : ans = 24

// Considering a pattern formed with current "n" and previously calculated "n" :
// ans[n] = 2 * ans[n-1] + ans[n-3]