class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        map<int, int> mp;
        
        for(int i=0;i<n;i++) {
            mp[B[i]]++; // Array B

            // Check the occurance for A
            for(int j=0;j<=i;j++) {
                if(mp.find(A[j]) != mp.end()) {
                    cout<<A[j]<<" "<<mp[A[j]]<<endl;
                    res[i] += mp[A[j]];
                }
            }
        }
        return res;
    }
};