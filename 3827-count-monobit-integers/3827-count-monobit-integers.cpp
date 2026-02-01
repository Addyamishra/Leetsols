class Solution {
public:
    int countMonobit(int n) {
        vector<int>cont={0,1, 3, 7, 15, 31, 63, 127, 255, 511};
        for(int i=0;i<cont.size();i++) if(cont[i]>n) return i;
        return cont.size();
    }
};