class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=-1;
        int freq=0;
        for(int i:nums){
          if(freq==0){
            cand=i;
          }
          if(cand==i){
            freq++;
          }else{
            freq--;
          }
        }
        return cand;
    }
};