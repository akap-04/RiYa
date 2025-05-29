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
    // BFS to map parents and find the target node
    TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start) {
                target = node;
            }

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }

        return target;
    }

    // BFS to find maximum distance (time to spread)
    int findMaxDistance(unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* target) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int time = -1; // start from -1 because the first node is infected at time 0

        while (!q.empty()) {
            int size = q.size();
            time++; // one level = one minute

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                // Left child
                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                // Right child
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                // Parent node
                if (parentMap.count(node) && !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                }
            }
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* target = bfsToMapParents(root, parentMap, start);
        return findMaxDistance(parentMap, target);
    }
};