class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int n=nums.size();
        int s=0;
        int e=n;
        while(s<e){
          int m=(s+e)/2;
          int frst=m-1>=0?nums[m-1]:-1;
          int scnd=m+1<n?nums[m+1]:-1;
          if(frst!=nums[m] && scnd!=nums[m]) return nums[m];
          if(frst==nums[m]) m--;
          if((n-m)%2) s=m+2;
          else e=m-1;
       }
       return nums[e];
    }
};