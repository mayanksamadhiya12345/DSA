class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int cnt = 1;
        set<int> st;
        
        if(arr.size()==2)
        {
            return (arr[0]==arr[1]);
        }
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1] != arr[i])
            {
                if(st.count(cnt) != 0)
                {
                    return false;
                }
                else
                {
                    st.insert(cnt);
                    cnt = 1;
                }
                
            }
            else
            {
                cnt++;
            }
        }
        return true;
    }
};