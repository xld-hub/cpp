#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }
    
    void func(vector<string> &res, string str, int l, int r, int n){
        //1.左右括号数量最大为n
        //2.左括号数量大于或等于右边括号数量
        if(l > n || r > n || r > l) 
            return ;
        //左右括号等于n，退出循环，保存结果
        if(l == n && r == n) 
        {
            res.push_back(str); 
            return;
        }
        
        func(res, str + '(', l+1, r, n);
        func(res, str + ')', l, r+1, n);
        return;
    }
    
    // void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
    //     if (cur.size() == n * 2) {
    //         ans.push_back(cur);
    //         return;
    //     }
    //     if (open < n) {
    //         cur.push_back('(');
    //         backtrack(ans, cur, open + 1, close, n);
    //         cur.pop_back();
    //     }
    //     if (close < open) {
    //         cur.push_back(')');
    //         backtrack(ans, cur, open, close + 1, n);
    //         cur.pop_back();
    //     }
    // }


};
int main()
{
    int n = 4;
    Solution solution;
    vector<string> s;
    s = solution.generateParenthesis(n);
    for (size_t i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<endl;
    }
    
   
    return 0;
}