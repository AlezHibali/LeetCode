// 204. Count Primes

class Solution {
public:
    // 2 3 5 7 11 13 ...
    // 00 10 20 31 42 52 63 73 84
    // dp: when n <= 2, prime is none; else n will increment if n-1 is prime
    
    int countPrimes(int n) {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        // true -> prime
        vector<bool> dp(n,true);
        dp[0] = false;
        dp[1] = false;
        
        // use prime times 2+ to get all non-prime
        for (int i = 0; i < sqrt(n); i++){
            if (dp[i])
                for (int j = 2; j*i < n; j++)
                    dp[i*j] = false;
        }
        
        return count(dp.begin(),dp.end(),true);
    }
};
