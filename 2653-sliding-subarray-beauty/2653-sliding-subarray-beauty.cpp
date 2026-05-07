class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int>cont;
        vector<int> answer;
        int s=0;
        int e=k;
        int neg=0;
        for(int i=0;i<k;i++){
           if(nums[i]<0) {cont[nums[i]]++; neg++;}
        }
        while(e<=nums.size()){
            int ans=0;
            if(neg>=x){
                int temp=x;
                for(auto ind:cont){
                    if(temp-ind.second<=0){
                        ans=ind.first;
                        break;
                    }else temp-=ind.second;
                }
            }
            answer.push_back(ans);
            if(e==nums.size()) break;
            if(nums[e]<0){ cont[nums[e]]++; neg++;}
            if(nums[s]<0){ cont[nums[s]]--; neg--;}
            e++,s++;
        }
        return answer;
    }
};