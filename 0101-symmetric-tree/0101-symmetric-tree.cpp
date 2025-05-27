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
    bool akap(TreeNode* left,TreeNode* right){
        if(left==nullptr || right==nullptr) return left==right;
        if(left->val != right->val) return false;

        return akap(left->left,right->right) && akap(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* l=root->left;
        TreeNode* r=root->right;

        return root==nullptr || akap(l,r);
    }
};