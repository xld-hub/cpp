#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int>::iterator left;
        // vector<int>::iterator right;
        // if(nums.size()<3)
        // {
        //     return nums.size();
        // }
        // left = nums.begin();

        // while ((left + 2) != nums.end())
        // {
        //     right = left + 2;
        //     if(*left == *right)
        //         nums.erase(left);
        //     else
        //         left++;
            
        // }
        // return nums.size();
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (len < 2 || nums[i] != nums[len-2])
                nums[len++] = nums[i];
        }
        return len;

    }
};

int main()
{
    vector<int> nums ={1,1,1,2,2,3,3,4,4};
    Solution solution;
    cout<<solution.removeDuplicates(nums);
}