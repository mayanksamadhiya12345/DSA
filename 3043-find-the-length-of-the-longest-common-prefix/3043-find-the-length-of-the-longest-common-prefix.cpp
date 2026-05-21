class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        set<string> st;
        for(auto&it : arr1) {
            string str = to_string(it);
            int k = str.length();
            string curr = "";
            for(int j=0;j<k;j++) {
                curr += str[j];
                st.insert(curr);
            }
        }
        
        int ans = 0;
        for(auto&it : arr2) {
            string str = to_string(it);
            int k = str.length();
            string curr = "";
            for(int j=0;j<k;j++) {
                curr += str[j];
                if(st.count(curr) > 0) {
                    ans = max(ans, j+1);
                }
            }
        }
        return ans;
    }
};

// 1000
// 1 10 100