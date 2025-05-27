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
    vector<int> akap(TreeNode* root, vector<int>& arr, int lvl){
        if(root==nullptr) return arr;
        if(lvl==arr.size()) arr.push_back(root->val);

        akap(root->right,arr,lvl+1);
        akap(root->left,arr,lvl+1);

        return arr;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int lvl=0;
        
        return akap(root,res,lvl);
    }
};