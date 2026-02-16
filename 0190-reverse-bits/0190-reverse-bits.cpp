class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t ans=0;
       for(int i=0;i<32;i++)
       {
         long long last_bit=(n>>i)&1;
         ans=ans | last_bit<<(31-i);
       } 
       return ans;
    }
};