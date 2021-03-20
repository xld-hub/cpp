#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string>::iterator str;
        str = tokens.begin();

        stack<int> stk;
        int num1,num2;
        
        while (str!=tokens.end())
        {

            if (*str == "+"||*str == "-"||*str == "*"||*str == "/")
            {
                num1 = stk.top();
                stk.pop();
                num2 = stk.top();
                stk.pop();
                if (*str == "+")
                {
                    stk.push(num2+num1);
                }
                else if (*str == "-")
                {
                    stk.push(num2-num1);
                }
                else if (*str == "*")
                {
                    stk.push(num2*num1);
                }
                else if (*str == "/")
                {
                    stk.push(num2/num1);
                }
            }
            else
            {

                stk.push(stoi(*str));
            }

            str++;
        }

        cout<<stk.top()<<endl;
        return stk.top();
    }
};


int main()
{
    Solution solution;
    vector<string> tokens = {"4","3","-"};
    solution.evalRPN(tokens);

}