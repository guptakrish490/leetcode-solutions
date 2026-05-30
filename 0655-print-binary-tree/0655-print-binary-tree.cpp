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
    int height(TreeNode* root){
        if(!root)return 0;

        return 1+max(height(root->left),height(root->right));
    }


    void traverse(TreeNode*& root,int i,int mid,vector<vector<string>>& ans,int h){
        if(!root) return;

        ans[i][mid]=to_string(root->val);

        traverse(root->left,i+1,mid-pow(2,h-i-2),ans,h);
        traverse(root->right,i+1,mid+pow(2,h-i-2),ans,h);

    }


    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return {};
        
        int h=height(root);

        int rows=h;
        int cols=pow(2,h)-1;

        vector<vector<string>> ans(rows,vector<string>(cols));

        int mid=cols/2;
        traverse(root,0,mid,ans,h);
        
        return ans;

        
    }
};