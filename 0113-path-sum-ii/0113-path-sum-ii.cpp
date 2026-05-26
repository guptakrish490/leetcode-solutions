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

    vector<int> vec;
    vector<vector<int>> ans;


    void sum(TreeNode* root,int targetSum){
        if(!root) return;

        vec.push_back(root->val);

        if(!root->left && !root->right){
            if(targetSum==root->val) ans.push_back(vec);
        }
        else{
            sum(root->left,targetSum-root->val);
            sum(root->right,targetSum-root->val);
        }

        vec.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if(!root)return {};

        sum(root,targetSum);


        return ans;
    }
};