class Solution {
public:
    int minBitFlips(int start, int goal) {

    int n = start ^ goal;
    int cnt = 0;
    
    
    while (n) {
        cnt += n & 1;  // Add the least significant bit to cnt
        n >>= 1;       // Right shift n to process the next bit
    }

    return cnt;
    }
};