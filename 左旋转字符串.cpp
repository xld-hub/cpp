#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string temp;
        if (n>s.size())
            return s;
        
        for (size_t i = 0; i < n; i++)
        {
            temp += s[i];
        }
        s.erase(0,n);
        s += temp;
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "hello";
    Solution solution;
    cout<<solution.reverseLeftWords(s,2);
    return 0;
}
