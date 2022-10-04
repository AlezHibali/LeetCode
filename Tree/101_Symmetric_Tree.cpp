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
    // stop when it reaches NULL
    // for each recursion, check the left and right are the same
    // if not directly return false; else check the next ones
    bool check(TreeNode* l, TreeNode* r){
        if ((l == NULL) != (r == NULL)) return false;
        if (l == NULL) return true;
        
        if (l->val != r->val) 
            return false;
        else return check(l->left, r->right) && check(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
