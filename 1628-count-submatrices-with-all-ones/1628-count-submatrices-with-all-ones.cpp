class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),ans=0;
        vector<int> hash(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hash[j]=mat[i][j]?hash[j]+1:0;
            }
            vector<int> sum(m);
            stack<int> st;

            for(int j=0;j<m;j++){
                while(!st.empty() && hash[st.top()]>=hash[j]) st.pop();
                if(!st.empty()){
                    int p=st.top();
                    sum[j]=sum[p]+hash[j]*(j-p);

                }else{
                    sum[j]=hash[j]*(j+1);
                }
                st.push(j);
                ans+=sum[j];
            }
        }
        return ans;

    }
};