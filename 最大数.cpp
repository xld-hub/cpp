#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:

    string largestNumber(vector<int>& nums) {

        // 将 nums 中的元素按照如下示例规则排序：
        // 因 "2" + "10" > "10" + "2" , 故 2 排在 10 的前面 
        sort(
            nums.begin(), 
            nums.end(), 
            [&](int x, int y){
                string a = to_string(x);
                string b = to_string(y);
                return a + b > b + a;
            }
        );

        // 将排序后的数组转为字符串
        string ans = "";
        for(int n:nums) 
            ans += to_string(n);
        // 输入为 [0,0] 时，输出应该为 "0"
        return ans[0]=='0'? "0" : ans; 
    }
};

int main()
{
    vector<int> nums = {0,0};
    Solution solution;
    cout<<solution.largestNumber(nums);
    
}