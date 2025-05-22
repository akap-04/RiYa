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
    void inOr(TreeNode* root, vector<int>& arr){
        if(root==nullptr) return;

        
        inOr(root->left,arr);
        arr.push_back(root->val);
        inOr(root->right,arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;

        inOr(root,arr);

        return arr;
    }
};