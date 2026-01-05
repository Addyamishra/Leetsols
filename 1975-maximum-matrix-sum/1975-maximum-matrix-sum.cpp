class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long neg=0;
        long long sum=0;
        long long mi=INT_MAX;
        for(auto ind:mat){
           for(long long i:ind){
            if(i<0) neg++;
            sum+=abs(i);
            mi=min(mi,abs(i));
           }
        }
        if(neg&1){
           sum-=mi;
            sum-=mi;
        }
        return sum;
    }
};