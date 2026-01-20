class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i:nums){
            int a=-1;
            for(int j=0;j<i;j++) if((j|(j+1))==i){ a=j; break;}
            ans.push_back(a);
        }
        return ans;
    }
};