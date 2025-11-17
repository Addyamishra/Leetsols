class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
     bool o=false;
     int c=0;
     for(int i:nums){
        if(o && i==1){
            if(c<k) return false;
            c=0;
        }else if(o) c++;
        if(i==1) o=true;
     }   
     return true;
    }
};