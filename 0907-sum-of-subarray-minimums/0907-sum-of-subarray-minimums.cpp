class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        long long sum = 0;
        int n = arr.size();
        int mod = 1000000007;
        
        vector<int> left_bound(n);
        vector<int> right_bound(n);
        stack<int> left;
        stack<int> right;
        
        for(int i = 0; i < n; i++)
        {
            while(!left.empty() && arr[left.top()] > arr[i]) 
                left.pop();
            
            if(left.empty()) 
                left_bound[i] = 0;
            else 
                left_bound[i] = left.top() + 1;
            
            left.push(i);
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(!right.empty() && arr[right.top()] >= arr[i]) 
                right.pop();
            
            if(right.empty()) 
                right_bound[i] = n - 1;
            else 
                right_bound[i] = right.top() - 1;
            
            right.push(i);
        }
        
        for(int i = 0; i < n; i++)
        {
            long long int count = (i - left_bound[i] + 1) * (right_bound[i] - i + 1);
            sum = (sum + (arr[i] * count % mod) % mod) % mod;
        }
         
        return sum % mod;
    }
};