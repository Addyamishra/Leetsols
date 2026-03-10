class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int s=0;
        int e=num.size()-1;
        while(s<e){
          if(num[s]+num[e]>target) e--;
          else if(num[s]+num[e]==target) return {s+1,e+1};
          else s++;
        }
        return {-1,-1};
    }
};