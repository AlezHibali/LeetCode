class Solution {
public:
    vector<int> mem;
    int recursion(int n) {
        if (n == 0 || n == 1)
            return 1;
        else if (mem[n] > 0)
            return mem[n];
        else{
            mem[n] = recursion(n-1) + recursion(n-2);
            return mem[n];
        }
    }
    int climbStairs(int n) {
        mem.resize(n+1,-1);
        return recursion(n);
    }
};
