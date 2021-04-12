#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool Compare(const int num1, const int num2)
    {
        auto strNum1 = to_string(num1);
        auto strNum2 = to_string(num2);
        return strNum1+strNum2 > strNum2 + strNum1;
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), [&](const int num1, const int num2){return Compare(num1, num2);});
        string res;
        for(auto iter:nums)
            res = res + to_string(iter);
        auto index = 0;
        while(index < res.length() && res[index] == '0')
            ++index;
        if(index>=res.length())
            return "0";

        return res.substr(index);
    }
};

int main()
{
    vector<int> nums = {0,0};
    Solution solution;
    cout<<solution.largestNumber(nums);
    
}