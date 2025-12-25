class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;
        for(auto&it : nums) mp[it]++;
        int n=nums.size();
        for(int i=1;i<=n;i++) {
            if(mp[i]==0) ans.push_back(i);
        }
        return ans;
    }
};