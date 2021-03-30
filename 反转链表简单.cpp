#include <iostream>
#include<stack>

using namespace std;

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
    ListNode* reverseList(ListNode* head) {

        ListNode *flag = new ListNode();
        ListNode *rightNode;
        ListNode *leftNode = nullptr;
        flag = head;
        
        while (flag != NULL)
        {
            rightNode = flag->next;
            flag->next = leftNode;
            leftNode = flag;
            flag = rightNode;
            
        }
        
        ShowList(leftNode);
        return leftNode;
    }
};

int main()
{
    int num[]={1,2};
    ListNode *head;
    head = CreateList(num,sizeof(num)/sizeof(int));
    Solution solution;
    
    ShowList(solution.reverseList(head));
}