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
    bool helper(TreeNode*root,int curr){
        if(!root) return true;

        return (root->val==curr) && helper(root->left,curr) && helper(root->right,curr);
    }


    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return helper(root,root->val);
    }
};