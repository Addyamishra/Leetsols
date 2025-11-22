#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    pair<long long, long long> dp[20][11][11][2][2];
    string S;

public:
    pair<long long, long long> solve(int idx, int prev, int prev2, bool tight, bool leading) {
        if (idx == S.size()) {
            return {1, 0}; 
        }

        if (dp[idx][prev][prev2][tight][leading].first != -1) {
            return dp[idx][prev][prev2][tight][leading];
        }

        long long limit = tight ? (S[idx] - '0') : 9;
        long long totalCount = 0;
        long long totalWaviness = 0;

        for (int digit = 0; digit <= limit; digit++) {
            bool nextTight = tight && (digit == limit);
            bool nextLeading = leading && (digit == 0);
            int nextPrev = nextLeading ? 10 : digit;
            int nextPrev2 = nextLeading ? 10 : prev;
            long long isPeakOrValley = 0;
            if (!nextLeading && prev != 10 && prev2 != 10) {
                if (prev > prev2 && prev > digit) isPeakOrValley = 1;
                else if (prev < prev2 && prev < digit) isPeakOrValley = 1; 
            }

            pair<long long, long long> res = solve(idx + 1, nextPrev, nextPrev2, nextTight, nextLeading);
            
            long long countFromChild = res.first;
            long long wavinessFromChild = res.second;
            totalWaviness += wavinessFromChild + (isPeakOrValley * countFromChild);
            totalCount += countFromChild;
        }

        return dp[idx][prev][prev2][tight][leading] = {totalCount, totalWaviness};
    }

    long long calc(long long n) {
        if (n < 0) return 0;
        if (n == 0) return 0;
        
        S = to_string(n);
        for(int i=0; i<20; i++)
            for(int j=0; j<11; j++)
                for(int k=0; k<11; k++)
                    for(int l=0; l<2; l++)
                        for(int m=0; m<2; m++)
                            dp[i][j][k][l][m] = {-1, -1};

        return solve(0, 10, 10, true, true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};