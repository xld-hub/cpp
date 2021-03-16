#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
	//构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//初始化函数
ListNode *CreateList(int con_val[],int len)
{
	ListNode *Head ;
    ListNode *Temp = new ListNode(con_val[0]);
    Head = Temp;
	for (size_t i = 1; i < len; i++)
	{
        Temp->next = new ListNode(con_val[i]);
        Temp = Temp->next;
	}
	return Head;
}

void ShowList(ListNode *List)
{
	do
	{
		cout<<List->val<<"-";
		List = List->next;
	} while(List != NULL);
	
	cout<<endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //头节点
        ListNode newHead(0);

        //移动节点
        ListNode *pi = &newHead;

        //都不为空
        while(l1 && l2) {
            //定义l1指向最小 保证最小节点加入到头节点后面 
            if(l1->val > l2->val) swap(l1, l2);

            //头节点加上l1
            pi->next = l1;

            //l1 pi向后移动
            l1 = l1->next;
            pi = pi->next;
        }

        //不满足都不为空的条件，退出while循环
        //如果l1指向空，pi->next还要加上l2，不管l2是否为空
        pi->next = l1 ? l1 : l2;
        //返回去掉开头的零
        return newHead.next;

    
    }
};

int main()
{
    ListNode *L1,*L2;
    int a1[]={5};
    int a2[]={1,2,4};
    L1 = CreateList(a1,sizeof(a1)/sizeof(int));
    L2 = CreateList(a2,sizeof(a2)/sizeof(int));
    Solution solution;

    ShowList(solution.mergeTwoLists(L1,L2));

    return 0;

}