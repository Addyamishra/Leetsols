class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int num = 0,temp=n;
        while(n){
            num|=1;
            num<<=1;
            n = n >>1;
        }
        return (num/2)^temp;
    }
};