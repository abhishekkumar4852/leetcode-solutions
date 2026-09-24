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

    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        // Store inorder positions
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder,
                    int left, int right) {

        if (left > right)
            return NULL;

        // First element of preorder is root
        int rootValue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int mid = mp[rootValue];

        // Build left subtree first
        root->left = build(preorder, left, mid - 1);

        // Then right subtree
        root->right = build(preorder, mid + 1, right);

        return root;
    }
};