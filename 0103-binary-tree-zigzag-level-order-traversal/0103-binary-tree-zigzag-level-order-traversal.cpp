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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans; // Handle empty tree

        queue<TreeNode*> nodeQ;
        nodeQ.push(root); // Start BFS
        bool L2R = true;  // Direction flag

        while (!nodeQ.empty()) {
            int len = nodeQ.size();         // Number of nodes in current level
            vector<int> row(len);           // Temporary array for this level

            for (int i = 0; i < len; ++i) {
                TreeNode* node = nodeQ.front(); // Get current node
                nodeQ.pop();

                // Choose index based on direction
                int index = L2R ? i : (len - 1 - i);
                row[index] = node->val;

                // Add child nodes to queue
                if (node->left) nodeQ.push(node->left);
                if (node->right) nodeQ.push(node->right);
            }

            ans.push_back(row);  // Add current level to result
            L2R = !L2R;          // Toggle direction
        }

        return ans;
    }
};
