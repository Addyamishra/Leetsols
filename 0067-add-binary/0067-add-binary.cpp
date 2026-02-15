class Solution {
public:
    string addBinary(string a, string b) {
        string &res = (a.size() >= b.size()) ? a : b; 
        int i = a.size() - 1, j = b.size() - 1;
        int k = res.size() - 1;
        int C = 0;
        while (k >= 0) {
            int A = i < 0 ? 0 : a[i] & 1; 
            int B = j < 0 ? 0 : b[j] & 1; 
            int S = (A ^ B) ^ C; 
            int C_out = ((A ^ B) & C) | (A & B);
            res[k] = S + '0'; 
            C = C_out;
            i--; j--; k--; 
        }
        return C ? (res.insert(res.begin(), '1'), res) : res;
    }
};
