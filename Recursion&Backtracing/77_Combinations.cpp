class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &s, int n, int k, int curr){
        if (k == 0)
            res.push_back(s);
        else
        for (int i = curr; i <= n - k + 1; i++){
            s.push_back(i);
            helper(res,s,n,k-1,i+1);
            s.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> s;
        helper(res,s,n,k,1);
        return res;
    }
};
