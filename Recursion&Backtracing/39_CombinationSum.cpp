class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int>& nums, 
                vector<int> &s, int curr, int size, int diff){
        if (diff == 0)
            res.push_back(s);
        
        for (int i = curr; i < size; i++){
            s.push_back(nums[i]);
            if (nums[i] <= diff)
                helper(res,nums,s,i,size,diff-nums[i]);
            s.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> s;
        helper(res,candidates,s,0,candidates.size(),target);
        return res;
    }
};
