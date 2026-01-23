class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=INT_MAX;
        int dif=INT_MAX;
        for(int i:nums){
            if(dif>=abs(i)){
                if(dif==abs(i)) ans=max(ans,i); 
                else ans=i;
                dif=abs(i);
            }
        }
        return ans;
    }
};