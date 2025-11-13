class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : nums) pq.push(x);

        int prev = pq.top();
        pq.pop();

        int cnt = 1, maxx = 1;

        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (curr == prev) continue; // skip duplicates

            if (curr == prev + 1) {
                cnt++;
            } else {
                cnt = 1; // reset count
            }

            maxx = max(maxx, cnt);
            prev = curr;
        }

        return maxx;
    }
};
