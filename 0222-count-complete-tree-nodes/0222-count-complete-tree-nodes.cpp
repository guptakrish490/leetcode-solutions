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
    int countNodes(TreeNode* root) {

        if(!root) return 0;
        int res=0;
        int h=0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int> ans;
            h++;
            
            for(int i=0;i<size;i++){

                TreeNode* node=q.front(); q.pop();

                ans.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            res=ans.size();
            
        }

        return res+pow(2,h-1)-1;
    }
};