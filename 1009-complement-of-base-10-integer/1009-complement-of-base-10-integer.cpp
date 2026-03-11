class Solution {
public:
    int bitwiseComplement(int n) {
        int num = 0,temp=n;
        while(n>=0){
            n = n >>1;
            num|=1;
            num<<=1;
            if(n==0) break;
        }
        return (num/2)^temp;
    }
};