class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, -1); // Initialize result array with -1
        std::stack<int> st;

        // Traverse the array twice to handle circular nature
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i % n]) {
                result[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }
        return result;
    }
};