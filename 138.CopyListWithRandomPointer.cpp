#include <cstdlib>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;
	
	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head)
			return nullptr;
		std::unordered_map<Node*, Node*> map;
		Node *currentNode = head;
		// MapにNodeを格納
		while (currentNode)
		{
			map[currentNode] = new Node(currentNode->val);
			currentNode = currentNode->next;
		}
		currentNode = head;
		// Mapに格納したデータのnextとrandomを設定
		while (currentNode)
		{
			map[currentNode]->next = map[currentNode->next];
			map[currentNode]->random = map[currentNode->random];
			currentNode = currentNode->next;
		}
		return map[head];
	}
};