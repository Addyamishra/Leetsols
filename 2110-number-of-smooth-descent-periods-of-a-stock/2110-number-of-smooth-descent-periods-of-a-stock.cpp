class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long s=0;
        long long e=1;
        long long ans=0;
        while(e<prices.size()){
         if(prices[e-1]-prices[e]!=1){
           ans+=(e-s)*(e-s+1)/2;
           s=e;
         }
         e++;
        }
        ans+=(e-s)*(e-s+1)/2;
        return ans;
    }
};