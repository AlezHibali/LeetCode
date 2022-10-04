/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // use queue to traverse by level
    // NULL in queue are used to change line (level++, res.pushback)
    // NULL are added whenever one line has completed and its not till the end
    // at the end, pop the last unused 'line' in res
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(NULL);
        q.push(root);
        
        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL){
                level++;
                res.push_back({});
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            res[level-1].push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        res.pop_back();
        return res;
    }
};
