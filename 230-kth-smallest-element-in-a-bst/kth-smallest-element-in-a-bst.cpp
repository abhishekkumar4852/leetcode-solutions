class Solution {
public:
    int count = 0;
    int ans;

    void inorder(TreeNode* root, int k) {

        if (root == NULL)
            return;

        // Go left
        inorder(root->left, k);

        // Visit root
        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        // Go right
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        inorder(root, k);

        return ans;
    }
};