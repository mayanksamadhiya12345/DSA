class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        map<int, int> mp;
        int dup=0;
        
        for(int i=0;i<n;i++) {
            mp[A[i]]++;

            if(mp[A[i]] == 2) {
                dup++;
            }

            mp[B[i]]++;
            if(mp[B[i]] == 2) {
                dup++;
            }

            res[i] = dup;
        }
        return res;
    }
};