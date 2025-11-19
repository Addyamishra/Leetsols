class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> freq(1009,0);
        for(int i:nums) freq[i]++;
        while( original<1002 && freq[original]) original*=2;
        return original;
    }
};