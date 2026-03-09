class Solution {
public:
    const int MOD = 1e9+7;
    int dp[201][201][2];

    int dfs(int z,int o,int last,int limit){
        if(z==0 && o==0) return 1;

        if(last!=-1 && dp[z][o][last]!=-1)
            return dp[z][o][last];

        long long ans=0;

        if(last!=0){
            for(int k=1;k<=limit && k<=z;k++){
                ans=(ans+dfs(z-k,o,0,limit))%MOD;
            }
        }

        if(last!=1){
            for(int k=1;k<=limit && k<=o;k++){
                ans=(ans+dfs(z,o-k,1,limit))%MOD;
            }
        }

        if(last==-1) return ans%MOD;
        return dp[z][o][last]=ans%MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        return dfs(zero,one,-1,limit);
    }
};