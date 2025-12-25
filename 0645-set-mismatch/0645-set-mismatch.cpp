class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for(auto& it : nums) mp[it]++;

        int dup=0, mis=0;
        for(int i=1;i<=n;i++) {
            if(mp[i] > 1) dup=i;
            else if(mp[i] == 0) mis=i;
        }

        return {dup, mis};
    }
};