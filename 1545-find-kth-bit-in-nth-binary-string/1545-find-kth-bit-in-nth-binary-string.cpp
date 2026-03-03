class Solution {
public:
void invert(string& str){
  for(int i=0;i<str.length();i++){
    if(str[i]=='1') str[i]='0';
    else str[i]='1';
  }
}
    char findKthBit(int n, int k) {
        string str="0";
        int len=(1<<n);
        for(int i=2;str.length()<k;i++){
          string temp=str;
          temp+='1';
          string temp2=str;
          invert(temp2);
          reverse(temp2.begin(),temp2.end());
          str=temp;
          str+=temp2;
        }
        return str[k-1];
    }
};