class Solution {
public:
    int numSteps(string s) {
       
        int n=s.length();
        int ans=n-1;
        int rem=0;
        for(int i=n-1;i>0;i--)
        {
          if(s[i]-'0'+rem==1)
          {
            ans++;
            rem=1;
          }
        }
        return ans+rem;
    }
};