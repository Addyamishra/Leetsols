class Solution {
public:
int rev(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        map<int,int> cont;
        for(int i=0;i<nums.size();i++){
            int r=rev(nums[i]);
            // if(i==1) return nums[i];
            if(cont.count(nums[i ])) ans=min(ans,i-cont[nums[i]]);
            cont[r]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};