class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int> mp;
        for(auto&it:arr1) mp[it]++;

        int n = arr2.size();
        for(int i=0;i<n;i++)
        {
            while(mp.find(arr2[i]) != mp.end())
            {
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
                if(mp[arr2[i]] == 0) break;
            }
        }

        for(auto&it:mp)
        {
            while(it.second != 0)
            {
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};