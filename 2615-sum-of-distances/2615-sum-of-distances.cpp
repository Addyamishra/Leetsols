class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,vector<long long>> cont,cont2;
        for(int i=0;i<nums.size();i++){
            cont[nums[i]].push_back(i);
            cont2[nums[i]].push_back(i);
            int n=cont2[nums[i]].size();
            if(n>1) {cont2[nums[i]][n-1]+=cont2[nums[i]][n-2];}
        }
        vector<long long>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(cont[nums[i]].size()==1) continue;
            long long l=cont[nums[i]].size();
            long long ind=lower_bound(cont[nums[i]].begin(),cont[nums[i]].end(),i)-cont[nums[i]].begin();
            long long frst=cont2[nums[i]][l-1]-cont2[nums[i]][ind];
            long long left=(ind*cont[nums[i]][ind])-((ind-1>=0)?cont2[nums[i]][ind-1]:0);
            long long right=frst-(l-ind-1)*cont[nums[i]][ind];
            ans[i]=left+right;

            // int th=(ind-1>=0)?cont2[nums[i]][ind-1]:0;
            // if(i==3) return {cont2[nums[i]][ind]}; 
            // long long curr=cont2[nums[i]][l-1]-(2*(th))-((l-ind-1)*cont[nums[i]][ind]);
            // 
            
        }
        return ans;
    }
};