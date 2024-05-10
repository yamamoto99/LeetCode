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
	// return ListSize
	int listSize(ListNode *head) {
		int res = 0;
		while (head != nullptr)
		{
			head = head->next;
			res++;
		}
		return res;
	}

public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = listSize(head);
		if (len == 1)
			return head = nullptr;
		if (len == n)
			return head->next;
		ListNode * currentNode = head;
		// 削除対象の手前のnodeまで移動
		for (int i = 1; i < len - n; i++)
			currentNode = currentNode->next;
		// 削除対象の次のノードがnullptrの場合currentNodeをtailにする
		// それ以外はnextをnext->nextに付け替え
		if (currentNode->next->next == nullptr)
			currentNode->next = nullptr;
		else
			currentNode->next = currentNode->next->next;
		return head;
	}
};