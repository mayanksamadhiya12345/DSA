class Solution {
public:
    long long sumAndMultiply(int n) {
        long long number = 0;
        string num = to_string(n);

        int m = num.length();
        long long sum = 0;
        for(int i=0;i<m;i++) {
            if(num[i] != '0') {
                long long val = (long long) (num[i]-'0');
                number = (number * 10) + val;
                sum += val;
            }
        }
        number *= sum;
        return number;
    }
};