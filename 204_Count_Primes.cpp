// 204. Count Primes

// Much Faster Solution Updated
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
        int res = n - 2; // no 0 and 1
        dp[0] = false;
        dp[1] = false;
        
        // use prime times (number_greater_than_that_prime) to get all non-prime
        for (int i = 2; i < sqrt(n); i++){
            if (!dp[i])
                continue;
            // use + is much faster than * !!!!!!!
            for (int j = i*i; j < n; j+=i){
                // no count duplicate
                if (dp[j])
                    res--;
                dp[j] = false;
            }       
        }
        
        return res;
    }
};
