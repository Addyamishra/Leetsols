class Solution {
public:
vector<vector<int>> dp;
int get(int i,int j,vector<int> frst,vector<int> scnd){
    if(i>=frst.size() || j>=scnd.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int take=frst[i]*scnd[j]+get(i+1,j+1,frst,scnd);
    int not_t=max(get(i+1,j,frst,scnd),get(i,j+1,frst,scnd));
    return dp[i][j]=max(take,not_t);
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int ans=INT_MIN;
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int a=INT_MIN;
        for(int i:nums1){
            for(int j:nums2){
                a=max(a,i*j);
            }
        }
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                dp[i][j]=dp[i-1][j-1]+nums1[i-1]*nums2[j-1];
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
                ans=max(ans,dp[i][j]);
         }
        }
     
        // int a=get(0,0,nums1,nums2);
        return dp[nums1.size()][nums2.size()]==0?a:ans;
    }
};