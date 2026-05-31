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
    int maxSum=INT_MIN;

    int solve(TreeNode* root){
        if(!root) return 0;

        int leftSum=max(0,solve(root->left));
        int rightSum=max(0,solve(root->right));

        int currSum=root->val+leftSum+rightSum;

        maxSum=max(maxSum,currSum);

        return max(root->val+leftSum,root->val+rightSum);
    }


    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};