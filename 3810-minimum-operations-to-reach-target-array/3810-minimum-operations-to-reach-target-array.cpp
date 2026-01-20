class Solution {
public:
    int minOperations(vector<int>& nums,vector<int>target) {
        int ans=0,n=nums.size();
        bool ch=false;
        for(int i=0;i<n;i++){
          if(nums[i]==target[i]) {nums[i]=-1; ch=true;}
        }
        set<int> cont;
        for(int i:nums) cont.insert(i);
        if(ch) return cont.size()-1;
        return cont.size();
    }
};