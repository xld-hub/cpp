#include <iostream>


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
    bool isPalindrome(ListNode* head) {//O(n)、O(1)
        ListNode* slow = head, *fast = head,  *prev = nullptr;
        while (fast){//find mid node
            slow = slow->next;
            fast = fast->next ? fast->next->next: fast->next;
        }

        while (slow){//reverse
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        while (head && prev){//check
            if (head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};

int main()
{
    int num[]={};
    ListNode *head;
    head = CreateList(num,sizeof(num)/sizeof(int));
    Solution solution;
    
    cout<<solution.isPalindrome(head);
}