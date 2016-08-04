#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	ListNode* reverse(ListNode* head){
		if(head==NULL || head->next==NULL) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next=head;
		ListNode* prev=dummy->next;
		ListNode* pcur=prev->next;
		while(pcur){
			prev->next=pcur->next;
			pcur=dummy->next;
			dummy->next=pcur;
			pcur=prev->next;
		}
		return dummy->next;
	}

	ListNode* add2Num(ListNode* l1, ListNode* l2){
		ListNode* dummy=new ListNode(-1);
		ListNode* p=dummy;
		l1=reverse(l1);
		l2=reverse(l2);
		ListNode* cur1=l1;
		ListNode* cur2=l2;
		int carry=0;
		while(cur1!=NULL && cur2!=NULL){
			carry=cur1->val+cur2->val+carry;
			p->next=new ListNode(carry%10);
			carry=carry/10;
			p=p->next;
			cur1=cur1->next;
			cur2=cur2->next;
		}
		while(cur1){
			carry=cur1->val+carry;
			p->next=new ListNode(carry%10);
			carry=carry/10;
			p=p->next;
			cur1->next;
		}
		while(cur2){
			carry=cur2->val+carry;
			p->next=new ListNode(carry%10);
			carry=carry/10;
			p=p->next;
			cur2->next;
		}
		if(carry){
			p->next=new ListNode(carry);
		}
		p=p->next;
		return reverse(dummy->next);
	}
};