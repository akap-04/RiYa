class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums):k(k) {
        for(int n:nums){
            if(pq.size()<k){
                pq.push(n);
            }else if(n>pq.top()){
                pq.push(n);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<k){
            pq.push(val);
        }else if(val>pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */