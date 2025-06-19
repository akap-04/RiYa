class Solution {
public:

        bool check(int start, vector<vector<int>>& graph, vector<int>& mark) {
        queue<int> q;
        q.push(start);
        mark[start] = 0;  // Start with color 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (mark[neighbor] == -1) {
                    mark[neighbor] = !mark[node];  // Assign opposite color
                    q.push(neighbor);
                }
                else if (mark[neighbor] == mark[node]) {
                    return false;  // Conflict
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size(),m=graph[0].size();
        
        vector<int> mark(n,-1);
        
 for (int i = 0; i < n; i++) {
            if (mark[i] == -1) {
                if (!check(i, graph, mark)) {
                    return false;
                }
            }
        }

        return true;
    }
};