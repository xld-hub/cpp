#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int change = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if( i == 0 && nums[i] > nums[i + 1]){//第一个位置单独讨论
                //前面没有数字，直接改为后面
                nums[i] = nums[i + 1];
                change ++;
            }
            else if(nums[i] > nums[i + 1]){
                
                change ++;
                //前面有数字，判断前面数字是否大于后面数字
                if(nums[i + 1] >= nums[i - 1]){
                    //前面数字小于后面数字
                    nums[i] = nums[i + 1];
                }
                else{
                    //前面数字大于后面数字，
                    nums[i + 1] = nums[i];
                }
            }
        }
        //两个以上变化就不可能在最多改变一个元素的情况下变成一个非递减数列
        return change <= 1;
    }
};


int main()
{
    vector<int> nums = {4,2,1};
    Solution solution;
    cout<<solution.checkPossibility(nums);
    return 0;
}