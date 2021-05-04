#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator left;
        vector<int>::iterator right;
        if(nums.size()<1)
        {
            return nums.size();
        }
        left = nums.begin();

        while ((left + 1) != nums.end())
        {
            right = left + 1;
            if(*left == *right)
                nums.erase(left);
            else
                left++;
            
        }
        return nums.size();

    }
};

int main()
{
    vector<int> nums ={1,1,1,2,2,3,3,4,4};
    Solution solution;
    cout<<solution.removeDuplicates(nums);
}