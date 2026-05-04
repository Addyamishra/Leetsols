// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=0,e=n,ans=n;
        while(s<=e){
            int m=s+(e-s)/2;
            if(isBadVersion(m)) ans=m,e=m-1;
            else s=m+1;
        }
        return ans;
    }
};