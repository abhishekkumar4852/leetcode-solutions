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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>>nodes;

        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode*curr = p.first;

            int row = p.second.first;
            int col = p.second.second;

            nodes[col][row].insert(curr->val);

            if(curr->left){
                q.push({curr->left , {row+1 , col-1}});

            }
            if(curr->right){
                q.push({curr->right , {row +1 , col +1}});
            }
        }
        vector<vector<int>> ans;

        for(auto it = nodes.begin() ; it!=nodes.end() ; it++){
            vector<int>col;

            for(auto it2 = it->second.begin() ; it2!=it->second.end() ; it2++){
                for(auto it3 = it2->second.begin() ; it3!=it2->second.end() ; it3++){
                    col.push_back(*it3);
                }
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};