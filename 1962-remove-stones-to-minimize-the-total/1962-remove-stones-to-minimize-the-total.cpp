class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int n = piles.size();
        
        // it will give max stone value each time
        priority_queue<int> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push(piles[i]);
        }
        
        while(!pq.empty() && k)
        {
            int top = pq.top();
            pq.pop();
            
            pq.push(((top+1)/2));
            k--;
        }
        
        int cnt=0;
        while(!pq.empty())
        {
            cout<<pq.top()<<" ";
            cnt += pq.top();
            pq.pop();
        }
        return cnt;
    }
};