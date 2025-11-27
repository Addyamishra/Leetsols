class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=count(s.begin(),s.end(),'a');
        int b=count(s.begin(),s.end(),'b');
        return abs(a-b);

    }
};