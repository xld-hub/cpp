/**
 * 动态规划：
 * f(n) = min(f(n - coin1), f(n - coin2), ... f(n - coinn)) + 1
 * f(n):n面额所需最少硬币数 
 * 前提是coin[i] <= 面额n
 *   
 * 暴力：
 *      11
 *  10   9   8
 * 9 8 7....
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution{
public:
    int coinChange(vector<int>& coins,int amount)
    {
        int Max = amount + 1;
        vector<int> dp( amount+1, Max);
        dp[0] = 0;
        for (size_t i = 1; i <= amount; i++)
        {
            for (size_t j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i],dp[i - coins[j]] + 1);
                }
            }
            
        }
        return dp[amount] > amount ? -1 : dp[amount];



        // //sort(coins.begin(),coins.end(),greater<int>());
        // sort(
        //     coins.begin(),
        //     coins.end(),
        //     [&](int x, int y){
        //         return x > y;
        //     }
        // );
        // vector<int>::iterator it;
        
        // for (it = coins.begin(); it != coins.end(); it++) 
        // {
        //     while ((amount - (*it))>=0)
        //     {
        //         count++;
        //         amount = amount - (*it);
        //     }
        // }
        
        // if (amount==0)
        // {
        //     cout<<"true";

        // }
        // else
        // {
        //     cout<<"false";
        //     count = -1;
        // }
        // // for_each(
        // //     coins.begin(),
        // //     coins.end(), 
        // //     [](int i){
        // //         cout<<i;
        // //     }
        // // );

        // return count;
    }
};

int main()
{
    Solution solution ;
    vector<int> coins = {1,3,5};
    int amount = 11;
    solution.coinChange(coins, amount);
    return 0;
}
