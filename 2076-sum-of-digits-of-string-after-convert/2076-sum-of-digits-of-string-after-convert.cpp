class Solution {
public:
    int getLucky(string s, int k) {
        string number = "";
        for(auto&it : s) number += to_string(it-96);
        
        int ans = 0;
        string temp = number;
        while(k--)
        {
            int curr = 0;
            for(auto& it : temp)
            {
                curr += (it - '0');
            }

            ans = curr;
            temp = to_string(ans);
        }
        return ans;
    }
};