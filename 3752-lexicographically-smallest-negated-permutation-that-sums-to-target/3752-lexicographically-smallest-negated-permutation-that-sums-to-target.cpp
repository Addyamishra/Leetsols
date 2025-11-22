class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> arr(n);
        for(int i=0;i<n;i++)arr[i]+=i+1;
        long long sum=n*1LL*(n*1LL+1)/2;
        long long req=sum-target;
        if(req&1) return {};
        req/=2;
        for(int i=n;i>=1;i--){
         if(req>=i){
            arr[i-1]=-i; 
            req-=i;
         }
        }
        sort(arr.begin(),arr.end());
        vector<int> arr2;
        return req==0?arr:arr2;
    }
};