class Solution {
public:
int get(int num){
    int sum=0;
    int div=0;
    for(int i=1;(i*i)<=num;i++){
        if(num%i==0){
            sum+=i;
            div++;
            if((num/i)!=i) sum+=(num/i),div++;
        }
        if(div>4) return 0;
    }
    return div==4?sum:0;
}
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=get(i);
        }
        return sum;
    }
};