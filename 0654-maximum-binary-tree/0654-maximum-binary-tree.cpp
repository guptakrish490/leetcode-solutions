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
    
    TreeNode* helper(vector<int>&nums,auto it1,auto it2){

        if(it1==it2) return nullptr;

        auto it=max_element(it1,it2);
        TreeNode* root=new TreeNode(*it);

        root->left=helper(nums,it1,it);
        root->right=helper(nums,it+1,it2);

        return root;

    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return helper(nums,nums.begin(),nums.end());

    }
};