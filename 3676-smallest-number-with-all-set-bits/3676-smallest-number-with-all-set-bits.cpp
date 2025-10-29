class Solution {
public:
    int smallestNumber(int n) {
        int x=0,i=0;
        while(x<n){
          x|=(1<<i++);
        }
        return x;
    }
};