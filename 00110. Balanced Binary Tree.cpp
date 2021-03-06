
//	Accepted	496 ms	cpp
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        int lDeep = getDeep(root->left);
        int rDeep = getDeep(root->right);

        return l && r && abs(lDeep-rDeep) < 2;
    }

    int getDeep(TreeNode* root)
    {
        if(!root) return 0;

        int l = getDeep(root->left);
        int r = getDeep(root->right);

        return l > r ? l+1 : r+1;
    }
};
