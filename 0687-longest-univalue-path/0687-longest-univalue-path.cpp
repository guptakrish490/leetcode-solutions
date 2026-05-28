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
    int maxi=0;

    int solve(TreeNode* root){

        if(!root) return 0;

        int left=solve(root->left);
        int right=solve(root->right);

        int leftsum=0,rightsum=0;

        if(root->left && root->left->val==root->val) leftsum=left+1;
        if(root->right && root->right->val==root->val) rightsum=right+1;

        maxi=max(maxi,leftsum+rightsum);

        return max(leftsum,rightsum);

    }


    int longestUnivaluePath(TreeNode* root) {

        solve(root);
        
        return maxi;
        
    }
};