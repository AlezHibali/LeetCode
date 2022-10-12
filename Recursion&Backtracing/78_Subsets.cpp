class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int>& nums, 
                vector<int> s, int curr, int size){
        res.push_back(s);
        for (int i = curr; i < size; i++){
            s.push_back(nums[i]);
            helper(res,nums,s,i+1,size);
            s.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> s;
        helper(res,nums,s,0,nums.size());
        return res;
    }
};
