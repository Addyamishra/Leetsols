class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0,u=0;
        for(char ch:moves){
            if(ch=='U') u++;
            else if(ch=='L') l++;
            else if(ch=='D') u--;
            else l--;
        }
        return l==0 && u==0;
    }
};