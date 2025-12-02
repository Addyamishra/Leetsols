class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long mod = 1000000007;
        map<int,int> mp;
        for(auto x:points) mp[x[1]]++;
        vector<long long> vec;
        for(auto it:mp)
        {
            if(it.second>=2)
            {
                long long val = it.second;
                vec.push_back((val*(val-1))/2);
            }
        }
        int n = vec.size(); if(n==0) return 0;
        vector<long long> suff(n,0);
        suff[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]+vec[i+1];
        }
        long long ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans+=(vec[i]*suff[i]);
            ans%=mod;
        }
        return ans;
        
    }
};