#include <iostream>
#include <vector>
#include <map>

using namespace std;
// 被几页数组教做人
// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         vector<int>a (arr);
//         sort(a.begin(),a.end());
//         a.erase(unique(a.begin(),a.end()),a.end());
//         vector<int>::iterator ia;
//         vector<int>temp;
//             //a的下标换成 arr的值
//         ia = arr.begin();
//         while (ia != arr.end())
//         {
//             size_t i=0;
//             for ( i = 0; i < a.size(); i++)
//             {
//                 if (*ia == a[i])
//                 {
//                     temp.push_back(i+1);
//                     continue;
//                 }
//             }
//             ia++;    
//         }
//         for (size_t i = 0; i < temp.size(); i++)
//         {
//             cout<<temp[i]<<"  ";      
//         }
//         return temp;
//     }
// };
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        multimap<int,int> mp;
        //统计元素 并且按照arr[i]降序排好
        for(int i=0;i<arr.size();++i){
            mp.insert({arr[i],i});
        }
        //res对应arr
        vector<int> res(arr.size());
        int pos=1;
        auto it=mp.begin();

        
        
        //遍历统计排序 后的multimap
        while(it!=mp.end()){
            int cur=it->first;
            //处理重复的情形
            //找到与第i（it）个数 相等的所有数（map first）
            //将这个数 对应下标pos 填到res中合适的位置（对应map记录的second原来arr位置） 
            while(it!=mp.end()&&it->first==cur){
                res[it->second]=pos;
                ++it;
            }
            ++pos;//下标++
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int>arr ={27,46,-3,-36,31,-14,-7,-36,27,-14,41,-40,23};
    solution.arrayRankTransform(arr);
}