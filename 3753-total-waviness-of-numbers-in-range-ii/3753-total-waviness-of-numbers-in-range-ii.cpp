class Solution {
public:
    using ll = long long;
    ll ll_pow(ll base, ll power) {
        ll result = 1;
        for(int i = 0; i < power; i++) {
            result *= base;
        }
        return result;
    }

    ll wav(ll num){
        if(num <= 100) return 0;
        string s = to_string(num);
        int n = s.size();

        ll a, b, c, res = 0;

        for(int i=0; i<n-2; i++){
            a = 1, b = 0, c = 1;
            ll exp = 1; 

            for(int j=n-1; j>=0; j--){
                if(j>=i && j<=i+2) continue;
                if(j<i) a += exp * (s[j]-'0');
                else a *= 10;
                exp *= 10;
            }
            
            if(i>0) b = a - ll_pow(10, n-i-3);

            exp = 1; 
            for(int j=n-1; j>=0; j--){
                if(j>=i && j<=i+2) continue;
                c += exp * (s[j]-'0');
                exp *= 10;
            }

            int tar = (s[i]-'0')*100 + (s[i+1]-'0')*10 + s[i+2]-'0';
            ll sub = ll_pow(10, n - i - 3); 
            for(int j=0; j<=9; j++){
                if(i==0 && j==0) continue;
                for(int k=0; k<=9; k++){
                    for(int l=0; l<=9; l++){
                        if((k>j && k>l) || (k<j && k<l)){
                            int curr = j*100 + k*10 + l;
                            if(curr < tar){
                                res += a;
                                if(curr < 100) res -= sub; 
                            }
                            else if(curr == tar){
                                res += c;
                                if(curr < 100) res -= sub;
                            }
                            else{
                                res += b;
                                if(curr < 100) res -= sub; 
                            }
                        }
                    }
                }
            }
        }

        return res;
    }

    long long totalWaviness(long long num1, long long num2) {
        return wav(num2) - wav(num1-1);
    }
};