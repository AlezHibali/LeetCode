// 0ms inspired by Discussion
class Solution {
public:
    // two options: include or exclude
    // if include, add prev ex to current
    // if exclude, max(prev ex, prev in)
    int rob(vector<int>& nums) {
        int i = 0;
        int e = 0;
        
        for (auto n : nums){
            int temp = i;
            i = e + n;
            e = max(e,temp);         
        }
        
        return max(i,e);
    }
};

// first attempt 40%
class Solution {
public:
    // jump two or three steps backward to see which 
    // gives more profit -> store possible max profit
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp (nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        int res = max(dp[2], dp[1]);
        
        for (int i = 3; i < nums.size(); i++){
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
            res = max(dp[i],res);
        }
        return res;
    }
};
