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

    int PathSum=0;
    int currSum=0;
    int maxSum=INT_MIN;

    int solver(TreeNode* root){
        if(!root) return 0;

        int left=max(0,solver(root->left));
        int right=max(0,solver(root->right));

        currSum=root->val+left+right;

        maxSum=max(maxSum,currSum);

        return root->val+max(left,right);
    }

    int maxPathSum(TreeNode* root) {

        solver(root);

        return maxSum;
        

        

        return PathSum; 
        
    }
};