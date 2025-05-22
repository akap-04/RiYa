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

    int findmax(TreeNode* root, int& dia){
        if(root==nullptr) return 0;
        
        int lh=findmax(root->left,dia);
        int rh=findmax(root->right,dia);

        dia=max(dia,rh+lh);
        
        return 1+max(rh,lh);

    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        findmax(root,dia);

        return dia;
    }
};