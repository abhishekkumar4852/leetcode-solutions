class BSTIterator {
public:
    stack<TreeNode*> st;

    // Push all left nodes into stack
    void pushAll(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        // Process right subtree
        pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};