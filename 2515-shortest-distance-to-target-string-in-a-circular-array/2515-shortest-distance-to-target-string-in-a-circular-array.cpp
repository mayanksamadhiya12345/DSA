class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) 
    {
        int n = words.size();
        int cnt = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            // if it is my target
            if(words[i]==target)
            {
                cnt = min(cnt, min(abs(startIndex - i), abs(n - abs(startIndex - i)))); 
            }
        }
        
        return cnt == INT_MAX ? -1 : cnt;
    }
};