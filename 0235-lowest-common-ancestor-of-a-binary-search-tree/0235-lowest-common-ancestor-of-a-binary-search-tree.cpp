/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // TreeNode* search(TreeNode* root,int key){
    //     if(!root)return root;

    //     if(root->val==key) return root;

    //     if(root->val > key) return search(root->left,key);
    //     else return search(root->right,key);
    // }
    


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;

        if(p->val < root->val && q->val > root->val) return root;

        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left,p,q);
        else if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};