class Solution {
public:
    int countCollisions(string directions) {
        int ans=0;
        stack<char> st;
        for(char ch:directions){
            if(st.size() && ch=='L' && (st.top()=='R'  || st.top()=='S')){
              if(st.top()=='R')  ans+=2,st.pop();
              else ans++,st.pop();
              while(st.size() && st.top()=='R')  ans+=1,st.pop();
                st.push('S');
            }else if(st.size() && ch=='S' && st.top()=='R'){
              while(st.size() && st.top()=='R')  ans+=1,st.pop();
              st.push('S');
            }else st.push(ch);
        }
        return ans;
    }
};