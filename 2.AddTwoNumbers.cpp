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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummyNode = new ListNode(0);
		ListNode *l1Current = l1;
		ListNode *l2Current = l2;
		ListNode *currentNode = dummyNode;
		int carry = 0;
		while (l1Current != nullptr || l2Current != nullptr)
		{
			// nullptrの時0それ以外は数値を抽出
			int x = l1Current != nullptr ? l1Current->val : 0;
			int y = l2Current != nullptr ? l2Current->val : 0;
			// 加算
			int sum = carry + x + y;
			// 繰り上がり保存
			carry = sum / 10;
			// 1の位を新規Listに格納
			currentNode->next = new ListNode(sum % 10);
			currentNode = currentNode->next;
			if (l1Current != nullptr)
				l1Current = l1Current->next;
			if (l2Current != nullptr)
				l2Current = l2Current->next;
		}
		// 繰り上がりがある時桁追加
		if (carry > 0)
			currentNode->next = new ListNode(carry);
		return
			dummyNode->next;
	}
};