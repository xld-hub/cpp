#include <iostream>
#include <vector>
using namespace std;


class Solution
{

public:
    int removeElement(vector<int> nums, int val)
    {

        for (vector<int>::iterator i = nums.begin(); i < nums.end(); ++i)
        {
            if (*i == val) 
            {
                nums.erase(i);
                --i;
            }
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    int val = 1;
    solution.removeElement(nums,val);

    return 0;
}