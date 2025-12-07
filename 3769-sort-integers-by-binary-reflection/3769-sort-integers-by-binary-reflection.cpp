class Solution {
public:
int get(int n) {
    int rev = 0;
    while (n > 0) {
        rev = (rev << 1) | (n & 1); 
        n >>= 1;                   
    }
    return rev;
}
    vector<int> sortByReflection(vector<int>& nums) {
        vector<vector<int>> cont;
        for(int i:nums){
            int a=get(i);
            cont.push_back({a,i});
        }
        vector<int> ans;
        sort(cont.begin(),cont.end());
        for(int i=0;i<nums.size();i++) ans.push_back(cont[i][1]);
        return ans;
    }
};