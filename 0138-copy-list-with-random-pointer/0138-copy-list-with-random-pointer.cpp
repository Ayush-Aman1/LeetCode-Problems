/*
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
*/

// Definition for a Node.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        for (Node* cur = head; cur != nullptr; ) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        for (Node* cur = head; cur != nullptr; cur = cur->next->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
        }

        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        Node* cur = head;

        while (cur) {
            Node* copy = cur->next;
            Node* nextOriginal = copy->next;
            copyTail->next = copy;
            copyTail = copy;
            cur->next = nextOriginal;
            cur = nextOriginal;
        }

        Node* copyHead = dummy->next;
        delete dummy;
        return copyHead;
    }
};