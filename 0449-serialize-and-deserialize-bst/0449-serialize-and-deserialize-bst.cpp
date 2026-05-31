/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null,";

        return to_string(root->val) + "," +
                serialize(root->left)+
                serialize(root->right);
    }

    int idx = 0;

    TreeNode* build(vector<int>& preorder, int minVal, int maxVal) {
        if (idx >= preorder.size())
            return nullptr;

        int val = preorder[idx];
        if (val < minVal || val > maxVal)
            return nullptr;

        TreeNode* root = new TreeNode(val);
        idx++;
        root->left = build(preorder, minVal, val);
        root->right = build(preorder, val, maxVal);
        return root;
    }

    TreeNode* deserialize(string data) {
        vector<int> vec;
        string num;
        for (char c : data) {
            if (c == ',') {
                if (!num.empty() && num != "null") {
                    vec.push_back(stoi(num));
                }
                num.clear();
            } else {
                num.push_back(c);
            }
        }
        if (!num.empty() && num!="null")
            vec.push_back(stoi(num));

        idx = 0;
        return build(vec, INT_MIN, INT_MAX);
    }
};


// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;