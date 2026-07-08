class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = s.size();

        vector<int> idx(n + 1, 0);
        vector<long long> val(n + 1, 0);
        vector<long long> total(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = pow10[i - 1] * 10 % MOD;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            if (digit != 0) {
                count++;
                val[count] = (val[count - 1] * 10 + digit) % MOD;
                total[count] = total[count - 1] + digit;
            }

            idx[i + 1] = count;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];

            int a = idx[left];
            int b = idx[right + 1];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            int length = b - a;

            long long num = (val[b] - val[a] * pow10[length]) % MOD;
            if (num < 0) num += MOD;

            long long digitSum = total[b] - total[a];

            ans.push_back(num * digitSum % MOD);
        }

        return ans;
    }
};