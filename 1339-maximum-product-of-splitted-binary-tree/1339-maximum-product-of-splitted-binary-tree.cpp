class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;
    long long sum = 0;
    long long best = 0;

    void getSum(TreeNode* node){
        if(!node) return;
        sum += node->val;
        getSum(node->left);
        getSum(node->right);
    }

    long long dfs(TreeNode* node){
        if(!node) return 0;

        long long left = dfs(node->left);
        long long right = dfs(node->right);

        long long curr = node->val + left + right;
        long long other = sum - curr;

        best = max(best, curr * other); 
        return curr;
    }

    int maxProduct(TreeNode* root) {
        sum = 0;
        best = 0;

        getSum(root);
        dfs(root);

        return best % MOD;
    }
};
