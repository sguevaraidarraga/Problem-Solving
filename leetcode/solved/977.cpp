/*
    Santiago Guevara Idarraga
    Problem: 977 - Squares of a Sorted Array
*/

#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int> &nums) {
            int n = nums.size(), L = 0, R = n-1, v1, v2;
            vector<int> ans(n);
            for(int i = n-1; i >= 0; i--) {
                v1 = nums[L] * nums[L];
                v2 = nums[R] * nums[R];
                if(v1 > v2) {
                    ans[i] = v1;
                    L++;
                }
                else {
                    ans[i] = v2;
                    R--;
                }
            }
            return ans;
        }
};