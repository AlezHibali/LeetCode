class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recursion(res, nums, nums.size(), 0);
        return res;
    }
    
    void recursion(vector<vector<int>> &res, vector<int>& nums, int size, int curr){
        if (curr == size)
            res.push_back(nums);
        for (int i = curr; i < size; i++){
            swap(nums[i], nums[curr]);
            recursion(res, nums, size, curr+1);
            swap(nums[i], nums[curr]);
        }
    }
};
