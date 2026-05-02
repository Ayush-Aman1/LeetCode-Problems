/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return NULL;
        }
        Node* cur = head;
        Node* tail;
        Node* next;
        while(cur){
            next = cur->next;
            if(cur->child){
                tail = cur;
                tail->next = cur->child;
                cur->child->prev = tail;
                cur->child = NULL;
                while(tail->next){
                    tail = tail->next;
                }
                tail->next = next;
                if(next) next->prev = tail;
            }
            cur = cur->next;
        }
        return head;
    }
};