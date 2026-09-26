class Solution {
public:

    TreeNode* build(vector<int>& preorder, int& i, int bound) {

        // No more elements
        // OR current value cannot belong to this subtree
        if (i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        // Create current node
        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        // Build left subtree
        root->left = build(preorder, i, root->val);

        // Build right subtree
        root->right = build(preorder, i, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int i = 0;

        return build(preorder, i, INT_MAX);
    }
};
