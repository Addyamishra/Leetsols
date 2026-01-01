class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        int rem=1;
        while(i>=0){
            if(digits[i]==9){
                digits[i]=0;
                i--;
            }
            else{
                digits[i]++;
                rem=0;
                break;
            }
        }
     if(rem==1){digits.push_back(0); digits[0]=1;}
     return digits;
    }
};