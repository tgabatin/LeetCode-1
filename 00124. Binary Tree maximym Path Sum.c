
//Accepted	18 ms	c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int ans;
int maxPathSum(struct TreeNode* root) {
    ans = INT_MIN;
    dfs(root);
    return ans;
}

int dfs(struct TreeNode* root){
    if(!root) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    left = left>0?left:0;
    right = right>0?right:0;
    ans = ans>(left+right+root->val)?ans:(left+right+root->val);
    
    return root->val + (left>right?left:right);
}
