class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        // 3 -> 0, 2->1, 4->2

        // 
        int n = numbers.size();
        vector<pair<int,int>> aashi;
        for(int i=0;i<n;i++)
        {
            aashi.push_back({numbers[i], i});
        }

        sort(aashi.begin(),aashi.end());
        // 2->1, 3->0, 4->2

        int st = 0;
        int en = n-1;

        while(st < en)
        {
            cout<<aashi[st].first<<" "<<aashi[en].first<<endl;
            if(aashi[st].first + aashi[en].first == target) return {aashi[st].second, aashi[en].second};
            else if(aashi[st].first + aashi[en].first > target) en--;
            else st++;
        }
        return {-1,-1};

    }
};