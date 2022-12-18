class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        // problem is similar with Next Greater Element
        int n = temperatures.size();
        vector<int> answer(n,0);
        stack<int> s;                                         // stack for storing index
        
        // array is not circular so need to check for last element from the front
        for(int i=n-1;i>=0;i--)
        {
            // if current temperatures[s.top()] is smaller then the current temperatures it means, it can never be next great 
            // for any previous element so remove it
            while(!s.empty() && temperatures[s.top()]<=temperatures[i])
            {
                s.pop();
            }
            
            if(!s.empty())
            {
                cout<<s.top()-i<<" ";
                answer[i] = s.top()-i;                    // diff between the indexes
            }
            
            s.push(i);
        }
        return answer;
    }
};