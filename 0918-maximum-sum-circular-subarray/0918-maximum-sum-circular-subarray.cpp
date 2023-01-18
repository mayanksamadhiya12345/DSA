class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int total=0;
        int curr1=0,curr2=0;
        int mx=INT_MIN,mn=INT_MAX;
           
        for(auto it : nums)
        {
            total+=it;
            
            curr1+=it;
            mx=max(mx,curr1);
            if(curr1<0) curr1=0;
            
            curr2+=it;
            mn=min(curr2,mn);
            if(curr2>0) curr2=0;
        }
        cout<<"Total : "<<total<<endl;
        cout<<"Max : "<<mx<<endl;
        cout<<"Min : "<<mn<<endl;
        
        if(total==mn) return mx;       // if all values are negative in that case total will be equals to mn and then return mx value out of them
        return max(mx,total-mn);       // we are using total-min here because here subarray can be circular so we'll just remove the min sub array part from it
    }
};

// total-min
// [5,-3,5]
// total=12 , min=-3 , mx=5
// just remove min sub array part , we'll left with [5,5]=10