/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //marking parents
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track,TreeNode* target){
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* cur=Q.front();
            Q.pop();

            if(cur->left){
                parent_track[cur->left]=cur;
                Q.push(cur->left);
            }
            if(cur->right){
                parent_track[cur->right]=cur;
                Q.push(cur->right);
            }
        }
    }



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //getting the parents marked or ready
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track,target);

        //going down or traversing
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;

        int cur_lvl=0;

        while(!q.empty()){
            int size=q.size();
            if(cur_lvl++==k) break;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                }

            }

            
            }
            //forming ans
            vector<int> ans;
            while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                ans.push_back(curr->val);

            }
            return ans;
    }
};