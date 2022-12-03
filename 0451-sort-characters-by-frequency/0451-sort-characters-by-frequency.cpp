class Solution {
public:
    string frequencySort(string s) 
    {
        // declare map for storing the frequency of each char in string
        map<char,int> mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        
        // declare a max heap for sorting the map values based on frequency
        priority_queue<pair<int,char>> pq;
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        
        string ans = "";
        while(!pq.empty())
        {
            int s = pq.top().first;
            char ch = pq.top().second;  
            pq.pop();
            
            for(int i=0;i<s;i++)
            {
                ans += ch;
            }
        }
        
        return ans;
    }
};