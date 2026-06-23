class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        static int up[2005], down[2005];
        static int nup[2005], ndown[2005];

        for (int i = 1; i <= m; ++i) {
            up[i] = m - i;
            down[i] = i - 1;
        }

        for (int len = 3; len <= n; ++len) {
            int pref = 0;

            for (int i = 1; i <= m; ++i) {
                ndown[i] = pref;
                pref += up[i];
                if (pref >= MOD) pref -= MOD;
            }

            int suff = 0;

            for (int i = m; i >= 1; --i) {
                nup[i] = suff;
                suff += down[i];
                if (suff >= MOD) suff -= MOD;
            }

            memcpy(up, nup, (m + 1) * sizeof(int));
            memcpy(down, ndown, (m + 1) * sizeof(int));
        }

        int ans = 0;

        for (int i = 1; i <= m; ++i) {
            ans += up[i];
            if (ans >= MOD) ans -= MOD;

            ans += down[i];
            if (ans >= MOD) ans -= MOD;
        }

        return ans;
    }
};