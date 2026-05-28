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
    int idx=0;

    TreeNode* solve(vector<int>& arr,int mini,int maxi){

        if(idx>=arr.size()) return nullptr;
        
        if(arr[idx]<mini || arr[idx]>maxi) return nullptr;

        TreeNode* root=new TreeNode(arr[idx]);
        idx++;

        root->left=solve(arr,mini,arr[idx-1]);
        root->right=solve(arr,arr[idx-1],maxi);

        return root;

    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return solve(preorder,INT_MIN, INT_MAX);
    }
};