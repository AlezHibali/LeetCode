class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &s, int diff, int curr, int len){
        if (diff == 0 && len == 0)
            res.push_back(s);
        for(int i = curr; i <= 9 - len + 1; i++){
            s.push_back(i);
            if (i <= diff)
                helper(res,s,diff-i,i+1,len-1);
            s.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> s;
        helper(res,s,n,1,k);
        return res;
    }
};
