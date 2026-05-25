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
    int d=0;
    int maxLen(TreeNode* root){
        if(!root)return 0;

        int left=maxLen(root->right);
        int right=maxLen(root->left);

        d=max(d,left+right);

        return 1+max(left,right);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        maxLen(root);
        return d;
    }
};