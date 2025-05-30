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
   int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    
    int ans = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        int sz = q.size();
        unsigned long long mmin = q.front().second;
        unsigned long long first = 0, last = 0;
        
        for (int i = 0; i < sz; i++) {
            unsigned long long cur_index = q.front().second - mmin;
            TreeNode* node = q.front().first;
            q.pop();

            if (i == 0) first = cur_index;
            if (i == sz - 1) last = cur_index;

            if (node->left) q.push({node->left, cur_index * 2 + 1});
            if (node->right) q.push({node->right, cur_index * 2 + 2});
        }
        
        ans = max(ans, static_cast<int>(last - first + 1));
    }
    
    return ans;
}

};