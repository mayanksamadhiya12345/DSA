class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> arr(n+1,0);            // people labeled 1 to n
        
        for(int i=0;i<trust.size();i++)
        {
            arr[trust[i][0]]--;
            arr[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            // if Everybody (except for the town judge) trusts the town judge it means value should be equal to n-1
            if(arr[i]==n-1) return i;
        }
        return -1;
    }
};