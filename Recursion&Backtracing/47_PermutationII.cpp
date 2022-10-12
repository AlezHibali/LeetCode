class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &res, int curr, int size){
        if (curr == size)
            res.push_back(nums);
        unordered_set<int> st;
        for (int i = curr; i < size; i++){
            if (st.count(nums[i])) continue; // if already swap, then do nothing
            st.insert(nums[i]);
            swap(nums[i],nums[curr]);
            helper(nums,res,curr+1,size);
            swap(nums[i],nums[curr]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,res,0,nums.size());
        return res;
    }
};
