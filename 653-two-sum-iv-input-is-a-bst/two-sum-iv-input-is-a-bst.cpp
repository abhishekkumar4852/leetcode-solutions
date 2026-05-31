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


    void pushLeft(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    void pushRight(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->right;
        }
    }

    int next(stack<TreeNode*>& st) {
        TreeNode* node = st.top();
        st.pop();

        pushLeft(node->right, st);
        return node->val;
    }

    int prev(stack<TreeNode*>& st) {
        TreeNode* node = st.top();
        st.pop();

        pushRight(node->left, st);
        return node->val;
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        stack<TreeNode*> leftSt, rightSt;
        pushLeft(root, leftSt);
        pushRight(root, rightSt);

        int left = next(leftSt);
        int right = prev(rightSt);

        while (left < right) {
            int sum = left + right;

            if (sum == k)
                return true;
            else if (sum < k)
                left = next(leftSt);
            else
                right = prev(rightSt);
        }

        return false;
    }
};
    

        
    
