class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int round=0;
        unordered_map<int,int> mp;
        for(auto it : tasks) mp[it]++;
        
        for(auto &it : mp)
        {
            int curr = it.second;
            if(curr == 1) return -1;
            
            while(curr >= 2)
            {
                round++;
                if(curr%3==0) curr -= 3;
                else curr -= 2;
            }
            
            if(curr != 0) return -1;
        }
        return round;
    }
};