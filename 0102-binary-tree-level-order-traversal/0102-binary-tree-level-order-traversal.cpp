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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            vector<int> level;

            for(int i=0;i<sz;i++){
                TreeNode* root=q.front();
                q.pop();

                if(root->left!=nullptr) q.push(root->left);
                if(root->right!=nullptr) q.push(root->right);

                level.push_back(root->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};