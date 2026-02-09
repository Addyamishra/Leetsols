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
void fill(TreeNode* root, vector<TreeNode*>& arr)
{
  if(root==NULL) return;
   fill(root->left,arr);
   arr.push_back(root);
   fill(root->right,arr);
}
TreeNode* cons(vector<TreeNode*>& arr,int s,int e)
{
  if(s>e) return NULL;
  int m=s+(e-s)/2;
  TreeNode* ans=arr[m];
  ans->left=cons(arr,s,m-1);
  ans->right=cons(arr,m+1,e);
  return ans;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        fill(root,arr);
        return cons(arr,0,arr.size()-1);
    }
};