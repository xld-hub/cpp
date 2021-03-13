#include <iostream>
#include <vector>
#include<algorithm>

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
	ListNode *Head = new ListNode();
	ListNode *tail = new ListNode();
	ListNode *temp;
	Head = tail;

	for (size_t i = 0; i < len; i++)
	{
		temp = new ListNode();
		temp->val = *con_val;
		// temp->next = NULL;
		tail->next = temp;
		tail = temp;
		con_val++;
	}

	return Head;
}
void ShowList(ListNode *List)
{
	List = List->next;
	do
	{
		cout<<List->val<<"-";
		List = List->next;
	} while(List != NULL);
	
	cout<<endl;
}

int AddList(ListNode* List) 
{
	List = List->next;
	int ret = 0;
	do
	{
		ret =ret*10+List->val;
		List = List->next;
	} while(List != NULL);
	return ret;
}
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// 		// l1 = l1->next;
// 		// l2 = l2->next;
// 		ListNode* List;
// 		int x;
// 		vector<int> num;
// 		x = AddList(l1)+AddList(l2);
// 		// ;
// 		while(x!=0)
// 		{
// 			num.push_back(x % 10);
// 			x = x/10;
// 		}
// 		reverse(num.begin(),num.end());
// 		int*p = NULL;
// 		p = new int[num.size()];
// 		for (int i = 0; i < num.size(); i++)
// 		{
// 			p[i] = num[i];
// 		}		
// 		List = CreateList(p,num.size());
// 		ShowList(List);
// 		delete []p;
// 		return List;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;//记录l1的长度
        int len2=1;//记录l2的长度
        ListNode* p=l1;
        ListNode* q=l2;
        while(p->next!=NULL)//获取l1的长度
        {
            len1++;
            p=p->next;
        }
        while(q->next!=NULL)//获取l2的长度
        {
            len2++;
            q=q->next;
        }
        if(len1>len2)//l1较长，在l2末尾补零
        {
            for(int i=1;i<=len1-len2;i++)
            {
                q->next=new ListNode(0);
                q=q->next;
            }
        }
        else//l2较长，在l1末尾补零
        {
            for(int i=1;i<=len2-len1;i++)
            {
                p->next=new ListNode(0);
                p=p->next;
            }
        }
        p=l1;
        q=l2;
        bool count=false;//记录进位
        ListNode* l3=new ListNode(-1);//存放结果的链表
        ListNode* w=l3;//l3的移动指针
        int i=0;//记录相加结果
        while(p!=NULL&&q!=NULL)
        {
            i=count+p->val+q->val;
            w->next=new ListNode(i%10);
            count=i>=10?true:false;
            w=w->next;
            p=p->next;
            q=q->next;
        }
        if(count)//若最后还有进位
        {
            w->next=new ListNode(1);
            w=w->next;
        }
        return l3->next; 
    }
};

int main()
{
	ListNode *List1,*List2;
	//321
	int num1[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	//123
	int num2[] = {5,2,2};
	List1 = CreateList(num1,sizeof(num1)/sizeof(int));
	List2 = CreateList(num2,sizeof(num2)/sizeof(int));
	Solution solution;
	ShowList(solution.addTwoNumbers(List1,List2));

	cin.get();
	return 0;
}
