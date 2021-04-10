#include <iostream>

class Solution
{

public:
    bool isUgly(int num)
    {
        if(num <= 0) return 0;
        while(num%3==0)num/=3;
        while(num%5==0)num/=5;
        return (num&num-1) == 0;
    }
};



int main(int argc, char const *argv[])
{
    int num = 10;
    Solution solution;
    solution.isUgly(num);
    return 0;
}
