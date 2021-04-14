#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int change = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if( i == 0 && nums[i] > nums[i + 1]){//第一个位置单独讨论
                nums[i] = nums[i + 1];
                change ++;
            }
            else if(nums[i] > nums[i + 1]){
                change ++;
                if(nums[i + 1] >= nums[i - 1]){
                    nums[i] = nums[i + 1];
                }
                else{
                    nums[i + 1] = nums[i];
                }
            }
        }
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