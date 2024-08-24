class Solution {
public:
    long long generate(long long leftHalf, bool isEven)
    {
        long long palin = leftHalf;
        if(!isEven) leftHalf /= 10;

        while(leftHalf > 0)
        {
            palin = palin*10 + leftHalf%10;
            leftHalf /= 10;
        }

        return palin;
    }
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        if(num <= 10) return to_string(num-1);
        if(num == 11) return to_string(9);

        if(n == "999999999999999999") return "100000000000000001";

        int len = n.length();
        long long leftHalf = stoll(n.substr(0, (len+1)/2));
        vector<long long> nums(5);

        nums[0] = generate(leftHalf-1, len%2 == 0);
        nums[1] = generate(leftHalf, len%2 == 0);

        if(leftHalf < 999999999)
        {
            nums[2] = generate(leftHalf+1, len%2 == 0);
        }
        else
        {
            nums[2] = stoll("1" + string(len-1, '0') + "1");
        }

        nums[3] = pow(10, len-1) - 1;
        nums[4] = pow(10, len) + 1;

        long long mn_palin = 0;
        long long mn_num = LLONG_MAX;

        for(auto &it : nums)
        {
            if(it == num) continue;

            long long diff = abs(it - num);
            if(diff < mn_num || (diff == mn_num && it < mn_palin))
            {
                mn_palin = it;
                mn_num = diff;
            }
        }

        return to_string(mn_palin);
    }
};