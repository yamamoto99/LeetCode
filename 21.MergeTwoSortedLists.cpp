// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode *newList = new ListNode();
		ListNode *head = newList;
		while (list1 && list2)
		{
			if (list1->val > list2->val)
			{
				newList->next = new ListNode(list2->val);
				list2 = list2->next;
			}
			else
			{
				newList->next = new ListNode(list1->val);
				list1 = list1->next;
			}
		}
		newList->next = list1 ? list1 : list2;
		return head;
	}
};