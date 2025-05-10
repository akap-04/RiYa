class Solution {
public:


    int hrs(vector<int>& piles, int t) {
        int sumhr = 0;
        for (int i = 0; i < piles.size(); i++) {
            sumhr += ceil((double)piles[i] / (double)t);
        }
        return sumhr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while (l < hi) {
            int mid = l + (hi - l) / 2;
            int totalH = hrs(piles, mid);

            if (totalH > h) {
                l = mid + 1;
            } else {
                hi = mid; // keep mid in search space to find min possible
            }
        }

        return l;
    }
};