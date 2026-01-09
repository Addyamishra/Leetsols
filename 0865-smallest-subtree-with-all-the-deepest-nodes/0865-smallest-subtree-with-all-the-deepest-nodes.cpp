class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {NULL, 0};

        auto L = dfs(root->left);
        auto R = dfs(root->right);

        if (L.second == R.second) 
            return {root, L.second + 1};

        if (L.second > R.second)
            return {L.first, L.second + 1};

        return {R.first, R.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
