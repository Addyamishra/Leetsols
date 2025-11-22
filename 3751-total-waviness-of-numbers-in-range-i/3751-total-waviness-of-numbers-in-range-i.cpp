class Solution {
public:
int check(int a){
    int last1=a%10;
    a/=10;
    int last2=a%10;
    a/=10;
    int ans=0;
    while(a){
        int curr=a%10;
        if(last2>curr && last2>last1) ans++;
        if(last2<curr && last2<last1) ans++;
        last1=last2;
        last2=curr;
        a/=10;
    }
   return ans;
}
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
           ans+=check(i);
        }
        return ans;
    }
};