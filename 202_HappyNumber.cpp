class Solution {
public:
    int helper(int n){
        int res = 0;
        while (n != 0){
            res += (n%10)*(n%10);
            n = n / 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        unordered_set<int> dp;
        while (1){
            int res = helper(n);
            if (res == 1)
                return true;
            if (dp.find(res) != dp.end())
                return false;
            else
                dp.insert(res);
            n = res;
        }
    }
};
