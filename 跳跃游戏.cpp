#include <iostream>
#include <vector>
using namespace std;

/**
 * 贪心
 * f(n) = n - 1 要到达n下标最小跳数
 * d(n) 到达n下标可能的最大跳数
 * d(0) = nums[0];
 * d(1) = nums[0]-1+nums[1]
 * d(3) = 
 * d(n) = max(d(n-1),d(n-2),...,d(1))+1
 */


class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int len = nums.size();
        if (len <= 1) return true;

        int maxDis = nums[0];

        for (int i = 1; i < len - 1; i++) {
            if (i <= maxDis) {
                maxDis = max(maxDis, nums[i]+i);
            }
        }
        cout << (maxDis >= len - 1);
        return maxDis >= len - 1;
    }
};



int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    solution.canJump(nums);

    return 0;
}