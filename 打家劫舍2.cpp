#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        //前两间房能偷取的最大金额 = second；
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        //S0 = H0;
        //S1 = max（S0,H1）;
        //S2 = max（S1,S0 + H2）;
        //Sn = max（Sn-1,Sn-2 + Hn）;
        //1. 前n-2 间房能偷的最大金额 + 最后一间的金额
        //2. 前n-1 间房最大金额
        //二者取最大
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        //只有一间屋子直接返回
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            //两间屋子返回大的
            return max(nums[0], nums[1]);
        }
        //大于两间房子的情况
        //保证第一间和最后一间不同时偷
        //把环拆成两个队列，一个是从0到n-1，另一个是从1到n，返回大的
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }


};


int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {200,3,140,20,10};
    cout << solution.rob(nums);
    return 0;
}

