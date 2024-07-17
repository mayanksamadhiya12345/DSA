class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        int n = h.size();
        vector<int> left(n), right(n);

        stack<int> s;

        // left limit
        for(int i=0;i<n;i++)
        {
            if(s.empty()) left[i]=0;
            else
            {
                while(!s.empty() && h[s.top()]>=h[i]) s.pop();
                left[i] = s.empty() ? 0 : s.top()+1;
            }

            s.push(i);
        }

        while(!s.empty()) s.pop();

        // right limit
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty()) right[i]=n-1;
            else
            {
                while(!s.empty() && h[s.top()]>=h[i]) s.pop();
                right[i] = s.empty() ? n-1 : s.top()-1;
            }

            s.push(i);
        }

        int Area = INT_MIN;
        for(int i=0;i<n;i++) Area = max(Area, h[i] * (right[i] - left[i] + 1));
        return Area;
    }
};