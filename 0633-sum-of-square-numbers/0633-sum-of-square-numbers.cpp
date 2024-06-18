class Solution {
public:
    bool judgeSquareSum(int c) {
        long st=0;
        long en=sqrt(c);

        while(st<=en)
        {
            if((st*st + en*en) == c) return true;
            else if((st*st + en*en) < c) st++;
            else en--;
        }
        return false;
    }
};