#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len<2)
        {
            return false;
        }
        if (s[0]==')'||s[0]=='}'||s[0]==']')
        {
            return false;
        }
        //左括号如栈，右括号出栈比较
        string temp;
        for (size_t i = 0; i < len; i++)
        {

            
            if (s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                temp.push_back(s[i]);
                continue;
            }
            if (s[i]==')')
            {
                if (temp.empty())
                    return false;
                if (temp[temp.length()-1]=='(')
                {
                    temp.pop_back();
                    continue;
                }
                else
                    return false;
            }
            if (s[i]=='}')
            {
                if (temp.empty())
                    return false;
                if (temp[temp.length()-1]=='{')
                {
                    temp.pop_back();
                    continue;
                }
                else
                    return false;
            }
            if (s[i]==']')
            {
                if (temp.empty())
                    return false;
                if (temp[temp.length()-1]=='[')
                {
                    temp.pop_back();
                    continue;
                }
                else
                    return false;
            }
        }
        
        if (temp.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "(){}}{";
    Solution solution;
    cout<<solution.isValid(s)<<endl;
}