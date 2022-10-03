class Solution {
public:
    // dp: for each entry, if dp[i-1] is negative, keep itself
    // else add dp[i-1] to itself
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        vector<int> dp(len,-1);
        dp[0] = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); i++){
            if (dp[i-1] < 0)
                dp[i] = nums[i];
            else
                dp[i] = nums[i]+dp[i-1];
            if (dp[i] > res)
                res = dp[i];
        }
        
        return res;
    }
};
