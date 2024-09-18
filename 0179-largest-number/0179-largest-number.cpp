class Solution {
public:
    bool static comp(string a, string b)
    {
        if(a+b > b+a) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(auto&it : nums) vec.push_back(to_string(it));

        sort(vec.begin(), vec.end(), comp);
        if(vec[0] == "0") return "0";
        string res = "";
        for(auto&it:vec) res += it;
        return res;
    }
};