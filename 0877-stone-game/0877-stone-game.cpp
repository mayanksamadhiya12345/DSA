class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int suma = 0;
        int sumb = 0;
        for(int i=0; i<n/2; i++){
            suma += piles[i];
            sumb += piles[n-i-1];
        }

        int alice =0;
        int bob = 0;
        bool flag = true;
        int i = 0;
        int j = n-1;
        while(i<j){
            if(flag){
                if(piles[i] == piles[j]){
                    alice += piles[i];
                    if(suma >= sumb){
                        j--;
                    }
                    else{
                        i++;
                    }
                }
                else if(piles[i] > piles[j]){
                    alice += piles[i];
                    i++;
                }
                else{
                    alice += piles[j];
                    j--;
                }
                
            }
            // else{
            //     if(piles[i] == piles[j]){
            //         bob += piles[i];
            //         if(suma >= sumb){
            //             j--;
            //         }
            //         else{
            //             i++;
            //         }
            //     }
            //     else if(piles[i] > piles[j]){
            //         bob += piles[i];
            //         i++;
            //     }
            //     else{
            //         bob += piles[j];
            //         j--;
            //     }
            // }
        }

        return alice >= bob;
    }
};