#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y; //不同位置
        //计算不同位置中1的数量
        int count = 0;
        while (temp > 0)
        {
            if ((temp & 1) == 1)
            {
                count++;
            }
            temp >>= 1;
            
        }
        return count;
    }
};

int main()
{
    int x = 1;
    int y = 2;
    Solution solution ;
    std::cout<<solution.hammingDistance(x,y)<<std::endl;

}