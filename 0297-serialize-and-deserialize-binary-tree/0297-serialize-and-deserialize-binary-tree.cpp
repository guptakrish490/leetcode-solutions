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
    string res;

    void solve(TreeNode* root) {}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null,";

        return to_string(root->val) + "," + serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* build(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        if (val == "null")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = build(nodes);
        node->right = build(nodes);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            nodes.push(token);
        }
        return build(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));