class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        // Add current node to path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        // If it's a leaf node
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        // Recurse left and right
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};