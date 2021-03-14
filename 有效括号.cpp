#include <iostream>
#include <stack>
using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        //遇见左括号相应右括号入栈
        //遇见右括号判断栈是否为空，不为空直接出栈比较
        for (auto c:s) {
            if (c == '(') {
                st.push(')');
            }else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            } else if ((!st.empty()) && (st.top() == c)) {
                st.pop();
            } else {
                return false;
            }
        }

        return (st.empty()) ? true : false;
        // int len = s.length();
        // if (len<2)
        // {
        //     return false;
        // }
        // if (s[0]==')'||s[0]=='}'||s[0]==']')
        // {
        //     return false;
        // }
        // //左括号入栈，右括号出栈比较
        // string temp;
        // for (size_t i = 0; i < len; i++)
        // {
        //     if (s[i]=='('||s[i]=='{'||s[i]=='[')
        //     {
        //         temp.push_back(s[i]);
        //         continue;
        //     }
        //     if (s[i]==')')
        //     {
        //         if (temp.empty())
        //             return false;
        //         if (temp[temp.length()-1]=='(')
        //         {
        //             temp.pop_back();
        //             continue;
        //         }
        //         else
        //             return false;
        //     }
        //     if (s[i]=='}')
        //     {
        //         if (temp.empty())
        //             return false;
        //         if (temp[temp.length()-1]=='{')
        //         {
        //             temp.pop_back();
        //             continue;
        //         }
        //         else
        //             return false;
        //     }
        //     if (s[i]==']')
        //     {
        //         if (temp.empty())
        //             return false;
        //         if (temp[temp.length()-1]=='[')
        //         {
        //             temp.pop_back();
        //             continue;
        //         }
        //         else
        //             return false;
        //     }
        // }
        // if (temp.empty())
        //     return true;
        // else
        //     return false;
    }
};

int main()
{
    string s = "(){}}{";
    Solution solution;
    cout<<solution.isValid(s)<<endl;
}