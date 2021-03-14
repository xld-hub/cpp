#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;

using std::vector;
using std::endl;
using std::sort;


int FindX(int k,vector<int>::iterator nums1,vector<int>::iterator nums2)
{
    if (k == 1)
    {
        if (*nums1 == 0)
            return *nums2;
        else if (*nums2 == 0)
            return *nums1;
        else
            return *nums1<*nums2?*nums1:*nums2;

        
    }
    
    *(nums1+k/2)<*(nums2+k/2)?nums1=nums1+k/2+1:nums2=nums2+k/2+1;
    FindX(k=k-k/2,nums1,nums2);
}


int main()
{
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {6,7,8,9};
    int n = nums1.size();
    int m = nums2.size();
    //两个有序数组第k小数
    //寻找中位数
    
    int k;
    int flag;
    if ((n + m)&1)
    {
        k = (n + m)/2;
        cout<< FindX(k,nums1.begin(),nums2.begin())<<endl;
    }
    else
        cout<< FindX((n + m)/2,nums1.begin(),nums2.begin())+FindX((n + m)/2+1,nums1.begin(),nums2.begin())<<endl;
    

    




/*
    //时间复杂度不够
    int m;
    m = nums2.size();
    for (size_t i = 0; i < m; i++)
    {
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(),nums1.end());
    vector<int>::iterator it;
    for (it = nums1.begin(); it != nums1.end(); it++)
    {
        cout<< *it<< " ";
    }
    if ((1&nums1.size()) == 0)
    {
        cout<< "偶数";

        cout<< (double)(nums1[(nums1.size()/2)-1] + nums1[(nums1.size()/2)])/2<< endl;
    }
    else
    {
        cout<< "奇数";
        cout<< nums1[(nums1.size()/2)]<< endl;
    }
*/

    return 0;
}