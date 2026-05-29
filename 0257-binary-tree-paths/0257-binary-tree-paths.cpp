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

    vector<string> res;
    void traverse(TreeNode* root,string ans){
        if(!root) return;

        ans+=to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(ans);
            return;
        }
        ans+="->";

        traverse(root->left,ans);
        traverse(root->right,ans);
    }
    

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        traverse(root,"");
        return res;
        
    }
};