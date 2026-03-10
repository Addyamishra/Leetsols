class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    if(it == nums.end() || *it != target)
    return {-1,-1};    int frst=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int scnd=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
    return {frst,scnd};
    }
};