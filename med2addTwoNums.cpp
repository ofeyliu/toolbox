#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *head = NULL;
	ListNode *prev = NULL;

	int carry = 0;
	while (l1 || l2) {
		int v1 = l1 ? l1->val : 0;
		int v2 = l2 ? l2->val : 0;
		int tmp = v1 + v2 + carry;
		carry = tmp / 10;
		int val = tmp % 10;
		ListNode* cur = new ListNode(val);
		if (head == NULL){
			head = cur;
			prev = head;
		}
		else{
			prev->next = cur;
			prev = cur;
		}
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	if (carry > 0) {
		ListNode* c = new ListNode(carry);
		prev->next = c;
	}
	return head;
}

int main()
{
	ListNode *a=new ListNode(2);
	ListNode *b = new ListNode(4);
	ListNode *c = new ListNode(3);
	a->next = b;
	b->next = c;
	ListNode *a2 = new ListNode(5);
	ListNode *b2= new ListNode(6);
	ListNode *c2 = new ListNode(4);
	a2->next = b2;
	b2->next = c2;
	ListNode *ans = NULL;
	ans = addTwoNumbers(a, a2);
	system("pause");
}