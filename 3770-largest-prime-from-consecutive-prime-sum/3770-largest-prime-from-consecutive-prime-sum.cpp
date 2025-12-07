class Solution {
public:
bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

    int largestPrime(int n) {
        vector<int> cont=sieve(n);
        int ans=0;
        int sum=0;
        for(int i:cont){
            if(sum+i>n) break;
            sum+=i;
            if(isprime(sum)) ans=sum;
        }
        return ans;
    }
};