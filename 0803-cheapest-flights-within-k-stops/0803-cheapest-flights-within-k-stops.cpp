class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>> >adj(n); //nextnode,edgewt
      for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
      }

      queue<pair<int,pair<int,int>>> q;//stps,node,cost
      q.push({0,{src,0}});
      vector<int> dis(n,1e9);
      dis[src]=0;

      while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stp=it.first,node=it.second.first,cost=it.second.second;
        if(stp>k) continue;

        for(auto pt:adj[node]){
            int nextstp=pt.first,ewt=pt.second;
            if(cost+ewt<dis[nextstp] && stp<=k){
                dis[nextstp]=cost+ewt;
                q.push({stp+1,{nextstp,cost+ewt}});
            }
        }
      }
      return (dis[dst] == 1e9) ? -1 : dis[dst];

    }
};