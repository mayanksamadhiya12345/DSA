class Solution {
public:
    vector<int> closestPrimes(int left, int right) 
    {
        // make a vector of size right+1 boundary it will store all the prime(true) and non prime numbers(false)
        vector<bool> temp(right+1,true);
        
        // sieve algorithm for storing prime numbers
        for(int i=2;i*i<=right;i++)
        {
            if(temp[i])
            {
                // if current number is prime then mark all it's multiples false
                for(int j=i*i;j<=right;j+=i)
                {
                    temp[j]=false;                // non prime
                }
            }
        }
        
        vector<int> prime;                        // it will collect all the prime numbers between the range
        if(left==1) left=2;
        for(int i=left;i<=right;i++)
        {
            if(temp[i]) prime.push_back(i);
        }
        
        // finding the min diff pair
        int diff,mn=INT_MAX;
        int a=-1,b=-1;
        
        for(int i=1;i<prime.size();i++)
        {
            diff = prime[i]-prime[i-1];
            if(diff<mn)
            {
                mn = diff;
                a = prime[i-1];
                b = prime[i];
            }
        }
        return {a,b};
    }
};