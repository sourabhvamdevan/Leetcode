// Last updated: 08/03/2026, 13:23:22
class Solution {
public:
    int smallestNumber(unsigned n) {
        return bit_ceil(n+1)-1;
    }
};